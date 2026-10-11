# Competitive Programming

My solutions to competitive programming problems, organized by platform. The repository reflects steady practice: Codeforces and AtCoder contests, the CSES problem set, USACO training, and Spanish online judges such as Acepta el Reto.

**Languages:** C++ (main, ~160 solutions) · Python (~100)

## Contents

| Folder | What's inside |
|---|---|
| [`codeforces/`](codeforces) | Solutions from ~34 rounds (Div. 1/2/3, Educational, Beta Rounds), from older to most recent |
| [`atcoder/`](atcoder) | AtCoder rounds (ABC) and problems from the Educational DP Contest |
| [`cses/`](cses) | CSES Problem Set, sorted by topic: DP, graphs, trees, geometry, math and range queries |
| [`usaco/`](usaco) | Problems from the USACO Guide: flood fill, trees, greedy with sorting, priority queues |
| [`leetcode/`](leetcode) | Backtracking, DP and data structures (N-Queens, subsets, histograms, etc.) |
| [`AceptaElReto/`](AceptaElReto) | Problems from [Acepta el Reto](https://aceptaelreto.com) |
| [`algomania/`](algomania) | Problems from the Algomanía contests (internal UPV judge created by Daniel Villena) |
| [`bootcamp/`](bootcamp) | Material from the CP-UPV bootcamp and team contests (Paellas 2024, 2025, 2026) |
| [`contest_informatica/`](contest_informatica), [`serafim_contest/`](serafim_contest), [`adabyron/`](adabyron) | Computer science contests and internal UPV contests |
| [`online_judge/`](online_judge), [`timus-online-judge/`](timus-online-judge) | UVa Online Judge and Timus |
| [`varios/`](varios) | Loose templates and utilities for practice (e.g. a segment tree) |

## Topics and techniques covered

- **Dynamic programming:** knapsack, LCS, edit distance, LIS, subset DP, counting combinations
- **Graphs:** BFS/DFS, Dijkstra, cycle detection, shortest paths, matching, flood fill
- **Trees:** traversals, subtrees, tree matching
- **Data structures:** segment tree, DSU (union-find), priority queues, AVL trees
- **Computational geometry:** convex hull, segment intersection, point in polygon, polygon area
- **Math:** modular exponentiation, number theory
- **General techniques:** greedy, backtracking, binary search, two pointers

## Problem structure

Each problem lives in its own folder:

```
<platform>/<problem>/
├── main.cpp      # solution (or main.py)
└── input.txt     # test cases used to try it out
```

## How to run a solution

```bash
cd cses/dp/coin-combinations-i
g++ -O3 main.cpp -o main
./main < input.txt
```

Python solutions run with `python main.py < input.txt`.

## About me

I'm Bautista Dahn, a second-year Artificial Intelligence student at the Universitat Politècnica de València. I enjoy solving problems involving math, logic and programming. I'm especially drawn to the algorithmic challenges found in competition problems, so I study and practice competitive programming techniques to keep improving my results.

- GitHub: [@BauDahn](https://github.com/BauDahn)
- Contact: bautistadahn22@gmail.com
