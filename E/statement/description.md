Eric is an overworked wage slave with a lot on his plate.

He has $n$ tasks to complete, but it's unlikely he'll be able to finish them all on time.

Each task is defined by:
- $r_i$: the time required to complete the task.
- $s_i$: the latest possible time the task can be started.

Unlike high-level wage slaves who can multitask, Eric can only work on one task at a time. He starts working at time 0 and must complete tasks sequentially. He can choose the order in which he completes tasks and may remain idle between tasks.

Your goal is to determine the maximum number of tasks Eric can complete.

Suppose there are 3 tasks with the following values of $(r_i, s_i)$:
$$(2, 4), (5, 1), (10, 7)$$
A possible optimal strategy is:
1. Idle for 1 unit of time, then start the second task at time = 1.
2. Finish the second task at time = 6, after which the first task can no longer be started.
3. Start the third task at time = 6, finishing at time = 16.
In total, Eric successfully completes 2 tasks, which is the maximum possible.
