import typer
import os
from rich import print
import subprocess
from subprocess import TimeoutExpired
import json

script_dir = os.path.dirname(os.path.abspath(__file__))
root_dir = os.path.abspath(os.path.join(script_dir, ".."))
statement_dir = os.path.join(root_dir, "statement")
app = typer.Typer()

def throw_info(msg):
    print('[bold green]Info: [/bold green]' + msg)

def throw_status(msg):
    print('[blue]Status: [/blue]' + msg)

def throw_warning(msg):
    print('[bold dark_orange]Warning: [/bold dark_orange]' + msg)

def throw_error(msg, exit_code=1):
    print('[bold red]Error: [/bold red]' + msg)
    exit(exit_code)

def read_json(path):
    with open(path) as f:
        data = json.load(f)
    return data

contest_config = read_json(os.path.join(root_dir, "contest_config.json"))

def get_problem_info(problem, index) -> dict:
    data = read_json(os.path.join(root_dir, problem, "problem.json"))
    return {
        "Title": data["title"],
        "TL": str(data["time_limit"]),
        "ML": str(data["memory_limit"]),
        "Index": chr(ord('A') + index)
    }

def get_statement_dir_path(problem):
    return os.path.join(root_dir, problem, 'statement')

def get_statement_tex_path(problem):
    return os.path.join(get_statement_dir_path(problem), 'statement.tex')

def run_command(args, timeout=None):
    command = " ".join(args)
    throw_info(f"Run command: {command}")
    try:
        result = subprocess.run(args, 
                                timeout=timeout)
    except TimeoutExpired:
        throw_error(f"Command {command} timeout")
        return 1
    if result.returncode != 0:
        throw_error(f"Command {command} failed")
        return result.returncode
    throw_info(f"Command {command} OK")
    return 0

def call_pandoc(dir, source, output):
    # pandoc source --mathjax --listings --output output
    source = os.path.join(dir, source)
    output = os.path.join(dir, output)
    run_command(["pandoc", source, "--mathjax", "--listings", "--output", output])

def gen_tex_file_from_md(dir, filename):
    call_pandoc(dir, f"{filename}.md", f"stategen.{filename}.tex")

def gen_description(problem):
    gen_tex_file_from_md(get_statement_dir_path(problem), "description")

def gen_input(problem):
    gen_tex_file_from_md(get_statement_dir_path(problem), "input")

def gen_output(problem):
    gen_tex_file_from_md(get_statement_dir_path(problem), "output")

def gen_hints(problem):
    if os.path.exists(os.path.join(get_statement_dir_path(problem), "hints.md")):
        gen_tex_file_from_md(get_statement_dir_path(problem), "hints")

def gen_samples(problem):
    samples = []
    with open(os.path.join(root_dir, problem, "tests", "mapping"), "r") as f:
        for line in f:
            subtask, name = line.strip().split(" ")
            if subtask == "samples":
                samples.append(name)
    with open(os.path.join(get_statement_dir_path(problem), "stategen.samples.tex"), "w") as f:
        for sample in samples:
            f.write("\\ProblemSample{../tests/" + sample + ".in}{../tests/" + sample + ".out}\n")


def gen_problem_info(problem, problem_info: dict):
    with open(os.path.join(get_statement_dir_path(problem), "stategen.info.tex"), "w") as f:
        for key, value in problem_info.items():
            f.write("\\providecommand{\\InfoProblem" + key + "}{}\n")
            f.write("\\renewcommand{\\InfoProblem" + key + "}{" + value + "}\n")

def gen_problem_list(problems, problem_info_list):
    with open(os.path.join(statement_dir, "stategen.problem_list.tex"), "w") as f:
        f.write("\\begin{ProblemList}\n")
        for problem, problem_info in zip(problems, problem_info_list):
            f.write("\ProblemListEntry{" + problem_info["Index"] + "}{" + 
                    problem_info["Title"] + "}{" + problem_info["TL"] + "}{" + problem_info["ML"] + "}\n")
        f.write("\\end{ProblemList}\n")

def gen_problem_import_list(problems):
    with open(os.path.join(statement_dir, "stategen.problems.tex"), "w") as f:
        for problem in problems:
            f.write("\\Problem{" + problem + "}\n")

def gen_contest_info(contest):
    with open(os.path.join(statement_dir, "stategen.contest_info.tex"), "w") as f:
        f.write("\\newcommand{\\ContestTitle}{" + contest_config["contests"][contest]["title"] + "}")

def remove_file(dir, file):
    try:
        os.remove(os.path.join(dir, file))
    except FileNotFoundError:
        pass


def clean_problem_files(problem):
    problem_statement_dir = get_statement_dir_path(problem)
    remove_file(problem_statement_dir, "stategen.info.tex")
    remove_file(problem_statement_dir, "stategen.description.tex")
    remove_file(problem_statement_dir, "stategen.input.tex")
    remove_file(problem_statement_dir, "stategen.output.tex")
    remove_file(problem_statement_dir, "stategen.hints.tex")
    remove_file(problem_statement_dir, "stategen.samples.tex")

def clean_files(problems):
    remove_file(statement_dir, "stategen.problems.tex")
    remove_file(statement_dir, "stategen.contest_info.tex")
    remove_file(statement_dir, "stategen.problem_list.tex")
    for problem in problems:
        clean_problem_files(problem)

def generate_stategen_files(problems):
    # filter(lambda problem: os.path.exists(get_statement_tex_path(problem)), problems)
    throw_info("Problems: " + " ".join(problems))
    problem_info_list = list(map(lambda args: get_problem_info(args[0], args[1]),
                            zip(problems, range(len(problems)))))
    if len(problems) == 0:
        return
    contest = contest_config["tasks"][problems[0]]["type"]
    throw_info("Contest: " + contest)
    gen_problem_import_list(problems)
    gen_problem_list(problems, problem_info_list)
    gen_contest_info(contest)
    for problem, problem_info in zip(problems, problem_info_list):
        gen_description(problem)
        gen_input(problem)
        gen_output(problem)
        gen_hints(problem)
        gen_samples(problem)
        gen_problem_info(problem, problem_info)
        if not os.path.exists(get_statement_tex_path(problem)):
            source_tex = os.path.join(statement_dir, "default_problem_statement.tex")
            target_tex = os.path.join(get_statement_dir_path(problem), "statement.tex")
            run_command(["cp", source_tex, target_tex])

def compile_statement_pdf():
    os.chdir(statement_dir)
    run_command(["xelatex", "-shell-escape", os.path.join(statement_dir, "statement.tex")])


@app.command()
def single(problem: str):
    generate_stategen_files([problem])
    compile_statement_pdf()


@app.command()
def all(contest: str):
    problems = []
    for task in contest_config["tasks"]:
        if contest_config["tasks"][task]["type"] == contest:
            problems.append(task)
    generate_stategen_files(problems)
    compile_statement_pdf()

@app.command()
def clean_single(problem: str):
    clean_files([problem])

@app.command()
def clean_all(contest: str):
    problems = []
    for task in contest_config["tasks"]:
        if contest_config["tasks"][task]["type"] == contest:
            problems.append(task)
    clean_files(problems)

if __name__ == '__main__':
    app()