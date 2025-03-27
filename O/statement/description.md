##### Problem Description
A compiler is a crucial software tool that translates high-level programming languages (such as C, C++, and Java) into machine code that the operating system can comprehend. It is an essential component of modern software development, playing a key role in improving execution performance, cross-platform compatibility, and developer efficiency.

Key Functions of a Compiler:
1. Lexical Analysis – Converts source code into tokens, identifying keywords, variable names, and other syntax elements.
2. Syntax Analysis – Constructs a syntax tree to ensure the program follows language rules.
3. Semantic Analysis – Checks type consistency, variable scopes, and logic correctness.
4. Intermediate Code Generation – Produces an intermediate representation (such as LLVM IR or Three-Address Code) that is independent of machine architecture.
5. Optimization – Improves efficiency by removing redundant calculations, optimizing memory usage, and enhancing performance.
6. Code Generation – Translates the optimized intermediate representation into machine-specific instructions.
7. Linking and Loading – Integrates different modules and libraries to create a final executable program.

In this problem, we want to implement a important feature of code generation, Register Allocation. After the compiler transformed human-readable code into intermediate code that is easy for machines to read, we need to allocate registers for each variables.

Registers are a fundemental part of the CPU. Every variable can be stored in many possible parts in the computer. However, registers offer quick access time compared to storing the data in the memory since it is directly within the CPU. Therefore, allocating enough registers to prevent loading the variables into memory is also a quintessential part of the compiler's job.

In the language that we are implementing a compiler on, there is only one type of expression in the form of `a = func(...)`. After the execution, the return value of `func` will be stored into `a`. We have no method to obtain the inner implementation of `func`. We only know that the function is always safe and returns a value that can be saved by `a`.

A notable characteristic of `func` is that it is not deterministic i.e. it will not necessarily return the same value even when the same parameter is passed. For example:
```
a = func()
b = func()
```
`a` and `b` may result in different values.

`func` can receive an arbitrary number of parameters. It is only guaranteed that the parameters are always defined before its usage. For example, the following excerpt is valid.
```
a = func()
b = func(a)
c = func(a, b)
```

However, the following excerpt is invalid.
```
a = func(b)
```
This is because that `b` is not defined before its usage. 

Note that since we know nothing about `func`, you can not skip the execution of a function. For example, even if the `a` in the code above is never used afterwards, you still have to execute `func(b)`. Actually storing `a` in a register is however optional. Also, during the execution of the function, the register to store the parameter can already be freed and given other uses. i.e. in the `a = func(b)` case, assuming that `b` is never used afterwards, `a` can use the same register as `b`.

Now, given a code file. If we want to make all variables to be stored in a register, what is the minimum number of registers we need?

To simplify the problem for you to solve, we have already transformed the code into its intermediate representation form.

<div style="background-color: #e6f2ff; padding: 10px; border-left: 5px solid #5b9bd5; border-radius: 5px;">
In real life scenarios, transforming into intermediate representation form is usually a lot more than what is done here. The code is usually transformed to Three-Adress-Code form for example. A not-so-practical intermediate representation is given here so you don't have to implement lexical, syntax, semantic analysis!
</div>

Each line of the code is transformed into the form of `a N ...` where $N$ is the count of parameters. Each number and strings are seperated with spaces. For example,
```
a = func()
b = func(a)
c = func(a, b)
```
will be transformed into
```
a 0
b 1 a
c 2 a b
```


##### Sample Testcases

<!-- ###### Sample Input 1
```
4
a 0
b 1 a
c 2 a b
d 3 a b c
```

###### Sample Output 1
```
3
``` -->

###### Sample 1 Explanation
The original code is like this.
```
a = func()
b = func(a)
c = func(a, b)
d = func(a, b, c)
```
`d` is never used afterwards, so we do not have to store it into any register.

<!-- ### Sample Input 2
```
```


### Sample Output 2
```
```

### Sample Input 3
```
```

### Sample Output 3
```
``` -->
