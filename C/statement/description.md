## Task Description

*"Given $n$ classrooms and $m$ courses, determine a schedule that maximized the total amount of class time within a week."* -- Judge Girl 50308.

As a student of NTU CSIE, you are already quite familiar with this task.

However, as the spring semester is about to begin, you suddenly realize that you haven’t scheduled your own courses yet! The deadline is approaching fast—you have only a few hours left before the course selection system closes at 3 a.m. Now, you must efficiently select and arrange your courses before time runs out.

## Course Selection

You are given $n$ courses. Each course $x$ has the following attributes:

- Weekday $w_x$: The day of the week when the course takes place.
- Begin Period $s_x$: The period in which the course starts.
- End Period $t_x$: The period in which the course ends (the course will end after this period). 
- Sweetness $a_x$: A measure of how generous the grading is.
- Coolness $b_x$: A measure of how easy the course is.
- Professor Name $c_x$: The name of the professor who teaches the course.

A course $x$ is considered better course $y$ if

1. The sweetness $a_x > a_y$ (course xx has a higher sweetness score).
2. The coolness $b_x > b_y$ if the sweetness $a_x = a_y$ (if two courses have the same sweetness, the one with a higher coolness score is preferred).

Additionally, you should avoid selecting multiple courses taught by the same professor to steer clear of receiving the so-called "big gift package" from the professor.

Of course, the selected courses must not have overlapping time intervals; otherwise, the system will reject your request. 

When selecting courses, prioritize the most preferable ones first, then select as many as you can. The selection process should be done in a way that respects time conflicts and avoids selecting courses taught by the same professor. After that, you’ll have your schedule for this semester.

Finally, you can compute the credits for this semester, which are determined by the number of periods in which you have a course.
