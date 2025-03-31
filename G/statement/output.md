If your progam is judged as correct, the sample grader will output a line `Accepted`.

Otherwise, the sample grader will output `Wrong Answer: MSG` where `MSG` and the corresponding reasons are listed as follows:

 - `too many queries`: the total call to the function `fuse_ball` exceeds the limit.
 - `invalid arguments`: your program called the function `fuse_ball` with invalid arguments.
 - `answer is not correct`: the return value of `is_abelian` is not correct. 

If there are multiple reasons, the program will only output any of them.

Note that the actual grader used in the judging process is not necessarily the same as the sample grader provided.
