<h2 style="text-align: center;">Russian Roulette 2.0</h2>

<h4 style="text-align: center; line-height: 0.05;">Time Limit : 1 second</h4>
<h4 style="text-align: center; line-height: 0.05;">Memory Limit : 1 second</h4>

<h3 style="text-align: center;">Problem Legend</h3>

A suicidal group of friends decided to play modified Russian Roulette after they saw their SPI of this semester.

Initially the $K$ friends are standing in a circle with $N$ equidistant marked points, numbered $1, 2, ..., N$. Each friend has chosen their own unique marked point where they are standing. 

Each player will shoot a bullet to kill the people standing on the marked point just left or just right of their **diametrically opposite** marked point (if they exist). It is guaranteed that $N$ is even so the diametrically opposite marked point is well defined.

Count the number of standing positions of the $K$ friends such that at least $1$ person gets killed. Since the answer may be large, output it modulo $10^9 + 7$.

<h3 style="text-align: center;">Input Format</h3>

The first line of input contains $1$ integer, $T$ the number of test cases.

The next $T$ lines of input each contain $2$ integers, $N$ and $K$ -- the size of the circle and the number of friends.

<h3 style="text-align: center;">Output Format</h3>

For each test case, output the number of positions where at least $1$ person gets killed modulo $10^9 + 7$.

<h3 style="text-align: center;">Constraints</h3>

- $1 \le T \le 10^4$
- $4 \le N \le 5 \cdot 10^5$
- $N$ is even
- The sum of $N$ does not exceed $5 \cdot 10^5$ over all test cases.

<h3 style="text-align: center;">Sample</h3>

<h4>Input</h4>

```
5
4 1
4 2
4 4
6 2
8 6
```

<h4>Output</h4>

```
0
8
24
12
20160
```

<h4> Explanation </h4>

**Test Case 1**: There are $4$ marked points where the first and only person can stand. Fortunately, in all those ways, there is nobody being killed.

**Test Case 2**: If the $2$ people were standing in $(1, 2)$, then both the people will be killed because both of them can shoot each other. However, the $2$ people standing in $(1, 3)$ causes nobody to be killed.

The total $8$ ways such that at least $1$ person gets killed are listed below:

- (1, 2)
- (1, 4)
- (2, 1)
- (2, 3)
- (3, 2)
- (3, 4)
- (4, 1)
- (4, 3)
