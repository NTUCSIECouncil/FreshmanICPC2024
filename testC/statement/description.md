In this contest, you will encounter several CTF-like (Capture The Flag) problems. Your objective is to follow the instructions provided within each challenge to uncover the hidden flag. The flag will be a string in the format `CSIE{[0-9A-Za-z-_]+}`, meaning it will start with "CSIE{" followed by a sequence of alphanumeric characters, dashes, or underscores, and ending with "}". For example, a flag may look like `CSIE{A_Sample_Flag}`.

Let's try a simple task, check out this [picture](https://imgur.com/a/UmLBmS5) and find the flag!

Your program should take no input and simply output the flag. A sample program may look like this

```c
#include<stdio.h>

int main() {
    printf("CSIE{A_Sample_Flag}\n");
}
```
