**<span style="color: red;">This is an interactive problem.</span> You can download the sample grader and implementation <a download="group.zip" href="data:zip;base64,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">here</a>.**

Abel is a famous mathematician who just got married! Now it's time to think about how to parent their children.

The best thing about toys is that they can be entertaining yet educational. While Abel does have lots of toys, they are kind of... eccentric.

Each box in Abel's toy collection contains several bouncy balls. These balls come in $n$ different colors, numbered from $0$ to $n - 1$. There are sufficiently many balls for a single color, so you won't run out of any color during the playthrough! When you pick two such bouncy balls and squeeze one against another, they will *fuse* together and generate a new color! To prevent chaos, these balls have some very special properties. Let $f(a, b)$ denote the color produced when you take color $a$ in the left hand and $b$ in the right hand, then fuse them.

1. No matter what the colors of the original balls are, the newly produced color $f(a, b)$ is always present in the box.
2. There is a "transparent color" $e \in \\{0, 1, \ldots, n - 1\\}$ such that fusing any ball with color $c$ with it will produce a ball with color $f(e, c) = f(c, e) = c$.
3. There is a way to "revert" the process: for any color $a$ in the box, there is a color $b$ also in the box such that fusing the two balls will produce the transparent color. That is, $f(a, b) = f(b, a) = e$.
4. Suppose we have three colors in order $a, b, c$. The fusing result is the same as long as we preserve their order. Formally speaking, for any $a, b, c \in \\{0, 1, \ldots, n - 1\\}$ $f(a, f(b, c)) = f(f(a, b), c)$.

This can be quite fun, but things can go wrong when you *swap hands*. As a proficient mathematician, Abel quickly noticed that these rules do not guarantee that the resulting color will be the same if you swap the balls in your two hands! That is, $f(a, b)$ is not necessarily the same as $f(b, a)$!

Abel doesn't want his kids confused. Hence, he only wants to pick those boxes where swapping hands does not matter. Formally, Abel wants to know for a given box, whether it satisfies 

 - For any $a, b \in \\{0, 1, \ldots, n - 1\\}$, we have $f(a, b) = f(b, a)$.

These boxes are called *abelian* boxes. Help Abel determine if a box is *abelian*.

</p> </div> </div> <div class="row"> <div class="col-md-6"> <div class="panel panel-default"> <div class="panel-heading"> <h1 class="panel-title">Implementation Details</h1> </div> <div class="panel-body"> In this problem, please do not read or write to the standard input and the standard output. However, you may still print debugging messages to standard error (`stderr`). </p>

Your progam has to include the header file `lib0026.h` via preprocessor directives. Please notice that you should change this filename to `group.h` when testing your program locally. You may refer to the sample implementation for further details.

You should implement the following procedure:

```cpp
bool is_abelian(int n);
```
 - This procedure is called exactly once for each test case.
 - The parameter `n` refers to the variable $n$.
 - The return value should be a boolean value. If the box is *abelian*, return true. Otherwise, you should return false.

Your program can call the following procedure:

```cpp
int fuse_ball(int a, int b);
```
 - Parameter $a$ and $b$ should satisfy $0 \leq a, b < n$.
 - The return value will be the resulting color when fusing a ball with color $a$ in the left hand and $b$ in the the right hand.
 - During a single test case, `fuse_ball` can be called at most $60$ times.

If any of the condition is not satisfied or your program tried to interfere with the judging process, you will recieve the **Wrong Answer** verdict. Otherwise, your program will be judged as correct.
</p> </div> </div> </div> <div class="col-md-6"> <div class="panel panel-default"> <div class="panel-heading"> <h1 class="panel-title">Example</h1> </div> <div class="panel-body"> Suppose that $n = 4$. The following is a correct example of the interacting process: <p>
 <table style="margin-left: auto; margin-right: auto;">  <tr>    <th>Judge</th>    <th>Participant</th>  </tr>  <tr>    <td>Calls `is_abelian(4)`.</td>    <td></td>  </tr>  <tr>    <td></td>    <td>Calls `fuse_ball(1, 2)`.</td>  </tr>  <tr>    <td>Return `3`.</td>    <td></td>  </tr>  <tr>    <td></td>    <td>Calls `fuse_ball(2, 3)`.</td>  </tr>  <tr>    <td>Returns `1`.</td>    <td></td>  </tr>  <tr>    <td></td>    <td>Return `true`.</td>  </tr></table> 

</p> </div> </div> <div class="panel panel-default"> <div class="panel-heading"> <h1 class="panel-title">Constraints</h1> </div> <div class="panel-body">  <p>

 - $1 \leq n \leq 10 ^ 6$
 - The results of fusing balls $f(a, b)$ are fixed before the interaction starts. That is, the judge is not adaptive.

</p> </div> </div> 
