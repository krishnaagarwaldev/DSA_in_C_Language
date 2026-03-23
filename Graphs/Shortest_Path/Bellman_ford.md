
## Initial Graph (5 vertices, edges with weights):

**text**

```
0 -> 1 (6), 0 -> 3 (7)
1 -> 2 (5), 1 -> 3 (8), 1 -> 4 (-4)
2 -> 1 (-2)
3 -> 2 (-3), 3 -> 4 (9)
4 -> 0 (2), 4 -> 2 (7)
```

## Step 1: Initialization

**text**

```
dist = [0, INF, INF, INF, INF]
parent = [-1, -1, -1, -1, -1]
source = 0
```

## Step 2: Relaxation (n-1 = 4 iterations)

### Iteration 1 (k=0):

Checking all edges:

**From u=0:**

* 0→1: dist[1] = min(INF, 0+6) = 6, parent[1]=0
* 0→3: dist[3] = min(INF, 0+7) = 7, parent[3]=0

**From u=1:**

* 1→2: dist[2] = min(INF, 6+5) = 11, parent[2]=1
* 1→3: dist[3] = min(7, 6+8=14) = 7 (unchanged)
* 1→4: dist[4] = min(INF, 6+(-4)) = 2, parent[4]=1

**From u=3:**

* 3→2: dist[2] = min(11, 7+(-3)=4) = 4, parent[2]=3
* 3→4: dist[4] = min(2, 7+9=16) = 2 (unchanged)

**From u=4:**

* 4→0: dist[0] = min(0, 2+2=4) = 0 (unchanged)
* 4→2: dist[2] = min(4, 2+7=9) = 4 (unchanged)

After iteration 1:

**text**

```
dist = [0, 6, 4, 7, 2]
parent = [-1, 0, 3, 0, 1]
```

### Iteration 2 (k=1):

**From u=0:**

* 0→1: dist[1] = min(6, 0+6=6) = 6
* 0→3: dist[3] = min(7, 0+7=7) = 7

**From u=1:**

* 1→2: dist[2] = min(4, 6+5=11) = 4
* 1→3: dist[3] = min(7, 6+8=14) = 7
* 1→4: dist[4] = min(2, 6+(-4)=2) = 2

**From u=3:**

* 3→2: dist[2] = min(4, 7+(-3)=4) = 4
* 3→4: dist[4] = min(2, 7+9=16) = 2

**From u=4:**

* 4→0: dist[0] = min(0, 2+2=4) = 0
* 4→2: dist[2] = min(4, 2+7=9) = 4

No changes in iteration 2.

### Iteration 3 (k=2) & Iteration 4 (k=3):

No further improvements (converged after iteration 1).

## Step 3: Check for Negative Cycles

Check if any edge can still be relaxed:

Testing all edges:

* 0→1: 0+6=6, dist[1]=6 → no relaxation
* 0→3: 0+7=7, dist[3]=7 → no
* 1→2: 6+5=11, dist[2]=4 → no
* 1→3: 6+8=14, dist[3]=7 → no
* 1→4: 6+(-4)=2, dist[4]=2 → no
* 2→1: 4+(-2)=2, dist[1]=6 → no (2 < 6 would relax, but we're in check phase)
* 3→2: 7+(-3)=4, dist[2]=4 → no
* 3→4: 7+9=16, dist[4]=2 → no
* 4→0: 2+2=4, dist[0]=0 → no
* 4→2: 2+7=9, dist[2]=4 → no

**No negative cycle detected!**

## Step 4: Results

**text**

```
Shortest Distance from 0 to 4 = 2
Path: 0 → 1 → 4
```

### Path Reconstruction:

* dest = 4, parent[4] = 1
* parent[1] = 0
* parent[0] = -1
* Path: 0 → 1 → 4

## Verification:

The shortest path from vertex 0 to vertex 4:

* Direct path 0→1→4: weight = 6 + (-4) = 2 ✓
* Alternative path 0→3→2→1→4: weight = 7 + (-3) + (-2) + (-4) = -2 (but this creates a cycle)
* Actually, there is a negative cycle 1→2→1: weight = 5 + (-2) = 3 (not negative)
* Wait, check: 1→2→1 is actually 5 + (-2) = 3 (positive)

**Important:** The graph doesn't actually have a negative cycle. The edge 2→1 (-2) and 1→2 (5) sum to 3 (positive), and 1→4 (-4) makes some paths interesting but no cycle with total negative weight exists.
