

###### Sample 1 Explanation
The original code is like this.
```
a = func()
b = func(a)
c = func(a, b)
d = func(a, b, c)
```
`d` is never used afterwards, so we do not have to store it into any register.