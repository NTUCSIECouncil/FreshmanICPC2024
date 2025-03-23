**<span style="color: red;">This is an interactive problem.</span> You can download the sample grader and implementation [here].**

Abel is a famous mathematician. Recently, he just got married! It's time to think about how to parent their children.

The best thing about toys are they can be both entertaining and educational. While Abel does have lots of toys, they are kind of... eccentric.

Each box in Abel's toy collection contains several bouncy balls. These balls come in $n$ different colors: numbered from $0$ to $n - 1$. There are sufficiently many balls for a single color. When you pick two of these bouncy balls and squeeze one against another, they will *fuse* together and generate a new color! 
To prevent chaos, these balls have some very special properties.
Let $f(a, b)$ denote the color produced when you take color $a$ in the left hand and $b$ in the right hand, then fuse them together.

1. No matter what the colors of the original balls are, the new produced color $f(a, b)$ is always present in the box already.
2. There is a "transparent color" $e \in \{0, 1, \ldots, n - 1\}$ such that fusing any ball with color $c$ with it will produce a ball with color $f(e, c) = f(c, e) = c$.
3. There is a way to "revert" the process: for any color $a$ in the box, there is a color $b$ also in the box such that fusing the two balls will produce the transparent color. That is, $f(a, b) = f(b, a) = e$.
4. Suppose we have three colors in order $a, b, c$, then the fusing result is the same as long as we preserve their order. That is, $f(a, f(b, c)) = f(f(a, b), c)$.

This can be quite fun, but things can go wrong when you *swap hands*. As a proficient mathematician, Abel quickly noticed that these rules does not guarantee that the resulting color will be the same if you swap the balls in your two hands!
That is, $f(a, b)$ is not necessarily the same as $f(b, a)$!

Abel doesn't want his kinds confused. Hence, he only wants to pick those boxes where swapping hands does not matter.
Formally, Abel wants to know for a given box, whether it satisfies 
 - For any $a, b \in \{0, 1, \ldots, n - 1\}$, we have $f(a, b) = f(b, a)$.

These boxes are called *abelian* boxes. Help Abel determine if a box is *abelian*.

</p> </div> </div> <div class="row"> <div class="col-md-6"> <div class="panel panel-default"> <div class="panel-heading"> <h1 class="panel-title">Implementation Details</h1> </div> <div class="panel-body"> In this problem, do not use the standard input and the standard output. However, you may still print debugging messages to standard error (`stderr`). </p>

Your progam has to include the header file `lib????.h` in the beginning. Please notice that you should change this filename to `group.h` when testing your program locally. You can refer to the sample implmentation about this.

You have to implement the following function:
```cpp
bool is_abelian(int n);
```
 - In a test case, `is_abelian` will only be called once.
 - The parameter `n` refers to the variable $n$.
 - The return value should be a boolean value. If the box is *abelian*, return true. Otherwise, you should return false.

You can call the following function:
```cpp
int fuse_ball(int a, int b);
```
 - Parameter $a$ and $b$ should satisfy $0 \leq a, b < n$.
 - The return value will be the resulting color when fusing a ball with color $a$ in the left hand and $b$ in the the right hand.
 - During a single test case, `fuse_ball` can be called at most $60$ times.

If any of the condition is not satisfied or your program tried to interfere with the judging process, you will recieve the **Wrong Answer** verdict.
Otherwise, your program will be judged as correct.
</p> </div> </div> </div> <div class="col-md-6"> <div class="panel panel-default"> <div class="panel-heading"> <h1 class="panel-title">Example</h1> </div> <div class="panel-body"> Suppose that $n = 4$. The following is a correct example of the interacting process: <p>
 <table style="margin-left: auto; margin-right: auto;">  <tr>    <th>Judge</th>    <th>Participant</th>  </tr>  <tr>    <td>Calls `is_abelian(4)`.</td>    <td></td>  </tr>  <tr>    <td></td>    <td>Calls `fuse_ball(1, 2)`</td>  </tr>  <tr>    <td>Return `3`.</td>    <td></td>  </tr>  <tr>    <td></td>    <td>Calls `fuse_ball(2, 3)`.</td>  </tr>  <tr>    <td>Returns `1`.</td>    <td></td>  </tr>  <tr>    <td></td>    <td>Return `true`.</td>  </tr></table> 

</p> </div> </div> </div> <div class="row"> <p> 

</p> </div> </div> <div class="row"> <div class="col-md-6"> <div class="panel panel-default"> <div class="panel-heading"> <h1 class="panel-title">Constraints</h1> </div> <div class="panel-body">  <p>

 - $1 \leq n \leq 10^6$
 - The results of fusing balls $f(a, b)$ are fixed before the interaction starts. That is, the judge is not adaptive.

</p> </div> </div> </div> 