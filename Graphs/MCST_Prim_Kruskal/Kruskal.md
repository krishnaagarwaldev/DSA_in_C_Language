## Code Explanation

### Key Components:

1. **Edge Structure** : Stores source vertex (u), destination vertex (v), and weight (w)
2. **parent[MAX]** : Union-Find array to track which set each vertex belongs to
3. **find()** : Finds the root parent of a vertex (without path compression in this version)
4. **unionSet()** : Merges two sets by making one root point to another
5. **sortEdges()** : Bubble sort implementation to sort edges by weight
6. **kruskal()** : Main algorithm implementation

## Dry Run with Example Graph

### Input Graph:

**text**

```
Vertices: 0, 1, 2, 3
Edges:
0-1: 10
0-2: 6
0-3: 5
1-3: 15
2-3: 4
```

Visual representation:

**text**

```
    0
   /|\
 10/ | \6
  /  |  \
 1  5|   2
  \  |  /
  15\ | /4
     \|/
      3
```

### Step 1: Initial State

**text**

```
parent[] = [0, 1, 2, 3]  // Each vertex is its own parent
edgeCount = 0
mstWeight = 0
```

### Step 2: Sort Edges by Weight

Original edges array:

**text**

```
Index: [0] 0-1(10)
       [1] 0-2(6)
       [2] 0-3(5)
       [3] 1-3(15)
       [4] 2-3(4)
```

After bubble sort (ascending order by weight):

**text**

```
Sorted edges:
[0] 2-3(4)    // Smallest weight
[1] 0-3(5)
[2] 0-2(6)
[3] 0-1(10)
[4] 1-3(15)   // Largest weight
```

### Step 3: Process Each Edge

**Iteration 1 (i=0): Edge 2-3 (weight 4)**

**text**

```
u=2, v=3, w=4
find(2): parent[2]=2 → setU=2
find(3): parent[3]=3 → setV=3
setU != setV → Different sets, include edge

Output: "2 - 3  weight: 4"
mstWeight = 0 + 4 = 4
edgeCount = 1

unionSet(2,3):
  find(2)=2, find(3)=3
  parent[2] = 3  // Make 2's parent point to 3

parent[] = [0, 1, 3, 3]
```

**Iteration 2 (i=1): Edge 0-3 (weight 5)**

**text**

```
u=0, v=3, w=5
find(0): parent[0]=0 → setU=0
find(3): parent[3]=3 → setV=3 (3's parent is 3)
setU != setV → Different sets, include edge

Output: "0 - 3  weight: 5"
mstWeight = 4 + 5 = 9
edgeCount = 2

unionSet(0,3):
  find(0)=0, find(3)=3
  parent[0] = 3  // Make 0's parent point to 3

parent[] = [3, 1, 3, 3]
```

**Iteration 3 (i=2): Edge 0-2 (weight 6)**

**text**

```
u=0, v=2, w=6
find(0): parent[0]=3, parent[3]=3 → setU=3
find(2): parent[2]=3 → setV=3
setU == setV → Same set! This would create a cycle, so SKIP

parent[] unchanged: [3, 1, 3, 3]
edgeCount still = 2
```

**Iteration 4 (i=3): Edge 0-1 (weight 10)**

**text**

```
u=0, v=1, w=10
find(0): parent[0]=3 → setU=3
find(1): parent[1]=1 → setV=1
setU != setV → Different sets, include edge

Output: "0 - 1  weight: 10"
mstWeight = 9 + 10 = 19
edgeCount = 3

unionSet(0,1):
  find(0)=3, find(1)=1
  parent[1] = 3  // Make 1's parent point to 3

parent[] = [3, 3, 3, 3]
```

**Iteration 5 (i=4): Edge 1-3 (weight 15)**

**text**

```
u=1, v=3, w=15
find(1): parent[1]=3 → setU=3
find(3): parent[3]=3 → setV=3
setU == setV → Same set! This would create a cycle, so SKIP

edgeCount = 3 (already reached V-1=3, loop condition will stop)
```

### Final MST:

**text**

```
Edges in MST:
2 - 3  weight: 4
0 - 3  weight: 5
0 - 1  weight: 10
Total weight of MST = 19
```

### Visual Representation of MST:

**text**

```
    0
   / \
 10/   \5
  /     \
 1       3
         |
         |4
         |
         2
```

## Step-by-Step Union-Find Evolution:

| Step | Edge    | Sets Before         | Decision | Sets After      |
| ---- | ------- | ------------------- | -------- | --------------- |
| 0    | -       | {0},{1},{2},{3}     | -        | {0},{1},{2},{3} |
| 1    | 2-3(4)  | {2}≠{3}            | Include  | {0},{1},{2,3}   |
| 2    | 0-3(5)  | {0}≠{2,3}          | Include  | {0,2,3},{1}     |
| 3    | 0-2(6)  | {0,2,3}={0,2,3}     | Skip     | {0,2,3},{1}     |
| 4    | 0-1(10) | {0,2,3}≠{1}        | Include  | {0,1,2,3}       |
| 5    | 1-3(15) | {0,1,2,3}={0,1,2,3} | Skip     | {0,1,2,3}       |

## Why Some Edges Were Skipped:

1. **Edge 0-2 (weight 6)** : After including 2-3 and 0-3, vertices 0,2,3 were already connected. Adding 0-2 would create a cycle (0-3-2-0).
2. **Edge 1-3 (weight 15)** : By the time we reach this edge, all vertices are already connected through other edges. Adding it would create multiple cycles.

## Key Observations:

1. **MST Property** : The algorithm successfully found 3 edges (V-1 = 3) that connect all 4 vertices
2. **Cycle Prevention** : Union-Find effectively prevented cycles by only adding edges connecting different sets
3. **Greedy Choice** : Always picked the smallest available edge that didn't create a cycle
4. **Total Weight** : 4 + 5 + 10 = 19 is the minimum possible total weight

The algorithm correctly found the Minimum Spanning Tree where all vertices are connected with minimum total weight!
