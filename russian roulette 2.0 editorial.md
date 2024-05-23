<h2 style="text-align: center;">Russian Roulette 2.0 Editorial</h2>

Let us try to compute the opposite instead, i.e. how many standing configurations exist such that nobody dies.

If any of the friends are standing on position $1$, both $\frac{N}{2}$ and $\frac{N}{2} + 2$ must be empty. Similarly, if any friend stands on $X$, then $X + \frac{N}{2} - 1$ and $X + \frac{N}{2} + 1$ must be empty Note that throughout this editorial, we take indices mod $N$ always. (Here, to maintain $1$ indexing, consider $N$ mod $N = 0$)

**Case 1** : $N$ mod $4 = 0$

Why is this case useful? Well $\frac{N}{2}$ is even in this case, so the positions that you can "kill" will be of different parity than yourself. For example, when $N = 4$, $1$ can kill $2$ and $4$, which have different parities than $1$ itself.

Dividing the indices to even and odd sets, each position that we occupy in the odd set "bans" $2$ positions in the even set.

The idea here is to reorder the indices of the even set so as to make the problem simpler. Let us rotate the even set by $180$ degrees (i.e. replace $X$ by $X + \frac{N}{2}$). For example for $N = 8$, reorder the circle $[1, 2, 3, 4, 5, 6, 7, 8]$ as $[1, 6, 3, 8, 5, 2, 7, 4]$. The problem obviously is still equivalent in our new numbering, however $1$ can now "kill" $2$ and $8$, $2$ can now kill $1$ and $3$ and so on. You can see that everyone kills their adjacent positions only, position $X$ kills $X - 1$ and $X + 1$ (instead of the original adjacent to diametrically opposite).

Thus, the problem is reduced to find $K$ positions among $N$ positions such that no $2$ chosen positions are adjacent. This is an easy combinatorics task. Suppose $1$ was chosen in the $K$ positions. Then, its equivalent to the number of solutions of :

$$x_1 + x_2 + x_3 + ... + x_K = N, x_i \ge 2$$ which is solvable using Stars and Bars. Further, multiply the answer by $\frac{N}{K}$ because there is a $\frac{K}{N}$ probability that $1$ will be one of the $K$ indices.

This solves it in $O(1)$ after we have factorials upto $N$ precomputed, which can be done in $O(N)$.

**Case 2**: $N$ mod $4 = 2$

Here, even indices only kill even indices and odd indices only kill odd indices. Thus, the set of even indices and odd indices are completely independent and can be solved separately. Further, both the even indices and odd indices are exactly equivalent to solve.

Let us restate the new problem, where we are only solving either Even indices or Odd indices: 

$M$ spots on circle, $M$ is now odd ($M = \frac{N}{2}$). Need to find ways to place $K$ people such that if $X$ has a person, neither $X + \frac{M - 1}{2}$ nor $X + \frac{M + 1}{2}$ has a person. Let the answer be $f(M, K)$.

<details>
<summary>How to compute f(M, K)</summary>
The idea is to reorder the indices to reduce the problem to adjacent indices. Again, it is possible!

Consider the permutation built as $p_1 = 1$, $p_i = p_{i - 1} - 2$ (taken mod $M$). For example, for $M = 5$, the permutation is $[1, 4, 2, 5, 3]$. For $M = 7$, the permutation is $[1, 6, 4, 2, 7, 5, 3]$. Reordering the circle with this permutation, one can check that now every position $X$ is able to kill $X - 1$ and $X + 1$.

Thus, this problem is reduced to again the same "no 2-adjacent" problem, which we can solve in $O(1)$. 

</details>



However, this solution only holds for the $2$ separate sets of even and odd indices. We still need to combine them, as the original problem contains both at once.

We can simply bruteforce this part : iterate on $Y$ from $0$ to $K$, and then add to the answer $f(\frac{N}{2}, Y) \cdot f(\frac{N}{2}, K - Y)$. We are basically bruteforcing the number of people that will be present in the odd set (say $Y$), then $K - Y$ people must be present in the even set.

Thus, the entire problem is solved in $O(K)$, which is bounded by $O(N)$.

