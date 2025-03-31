The first line contains a single integer $n$, representing the number of available courses.

The next $n$ lines each contain five integers and a string, where the $i$-th line ($1 \le i \le n$) is formatted as:

$w_i$ $s_i$ $t_i$ $a_i$ $b_i$ $c_i$

These values represent the attributes of each course as described above.

- $w_i$: The weekday of the course.
- $s_i$: The starting period.
- $t_i$: The ending period.
- $a_i$: The sweetness score.
- $b_i$: The coolness score.
- $c_i$: The professor’s name.

The constraints are as follows:

- $1 \le n \le 10^5$
- $\forall i: 1 \le w_i \le 7$
- $\forall i: 1 \le s_i \le t_i \le 14$
- $\forall i: -10^9 \le a_i, b_i \le 10^9$, it is ensured that the pairs ($a_i$, $b_i$) are distinct.
- $\forall i: 1 \le |c_i| \le 10$, and $c_i$ only contains uppercase and lowercase English letters.
