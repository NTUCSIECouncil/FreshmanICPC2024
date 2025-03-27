FROM texlive/texlive:latest

RUN bash -c "$(curl -fsSL https://raw.githubusercontent.com/ioi-2017/tps/master/online-installer/install.sh)"
RUN apt update
RUN apt install -y python3-typer pandoc

CMD ["tail", "-f", "/dev/null"]
