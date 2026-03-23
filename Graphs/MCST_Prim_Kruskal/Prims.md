## Code Explanation

The code implements Prim's algorithm to find the Minimum Spanning Tree (MST) of a weighted undirected graph. Let me break down each component:

### Key Data Structures:

* `adj[MAX][MAX]`: Adjacency matrix storing edge weights
* `key[MAX]`: Minimum weight to connect each vertex to MST
* `parent[MAX]`: Stores the parent of each vertex in MST
* `visited[MAX]`: Tracks which vertices are already in MST

### Main Functions:

1. `minKey()`: Finds unvisited vertex with minimum key value
2. `primMST()`: Implements Prim's algorithm
3. `main()`: Sets up the graph and calls primMST()

## Dry Run with Example Graph

Let's trace through the algorithm step by step with this graph:

**text**

```
Vertices: 0, 1, 2, 3, 4
Edges:
0-1: 2    0-3: 6
1-2: 3    1-3: 8    1-4: 5
2-4: 7
3-4: 9
```

### Initial State:

**text**

```
key[] = [INF, INF, INF, INF, INF]
parent[] = [-1, -1, -1, -1, -1]
visited[] = [0, 0, 0, 0, 0]
```

### Step 1: Start with vertex 0

**text**

```
key[0] = 0
visited[] = [1, 0, 0, 0, 0]
key[] = [0, INF, INF, INF, INF]

Check neighbors of vertex 0:
- v=1: adj[0][1]=2 < key[1]=INF → key[1]=2, parent[1]=0
- v=3: adj[0][3]=6 < key[3]=INF → key[3]=6, parent[3]=0
Result: key[] = [0, 2, INF, 6, INF]
```

### Step 2: Pick minimum key from unvisited vertices

Unvisited: {1,2,3,4}, minimum key is vertex 1 (key=2)

**text**

```
Add vertex 1 to MST:
visited[] = [1, 1, 0, 0, 0]

Check neighbors of vertex 1:
- v=0: visited, skip
- v=2: adj[1][2]=3 < key[2]=INF → key[2]=3, parent[2]=1
- v=3: adj[1][3]=8 < key[3]=6? No, 8>6 so no change
- v=4: adj[1][4]=5 < key[4]=INF → key[4]=5, parent[4]=1
Result: key[] = [0, 2, 3, 6, 5]
```

### Step 3: Pick minimum key from unvisited vertices

Unvisited: {2,3,4}, minimum key is vertex 2 (key=3)

**text**

```
Add vertex 2 to MST:
visited[] = [1, 1, 1, 0, 0]

Check neighbors of vertex 2:
- v=1: visited, skip
- v=4: adj[2][4]=7 < key[4]=5? No, 7>5 so no change
Result: key[] = [0, 2, 3, 6, 5]
```

### Step 4: Pick minimum key from unvisited vertices

Unvisited: {3,4}, minimum key is vertex 4 (key=5)

**text**

```
Add vertex 4 to MST:
visited[] = [1, 1, 1, 0, 1]

Check neighbors of vertex 4:
- v=1: visited, skip
- v=2: visited, skip
- v=3: adj[4][3]=9 < key[3]=6? No, 9>6 so no change
Result: key[] = [0, 2, 3, 6, 5]
```

### Step 5: Pick minimum key from unvisited vertices

Unvisited: {3}, minimum key is vertex 3 (key=6)

**text**

```
Add vertex 3 to MST:
visited[] = [1, 1, 1, 1, 1]

Check neighbors of vertex 3:
- v=0: visited, skip
- v=1: visited, skip
- v=4: visited, skip
```

### Final MST:

**text**

```
parent[] = [-1, 0, 1, 0, 1]
This means:
- Vertex 1's parent is 0 (edge 0-1, weight 2)
- Vertex 2's parent is 1 (edge 1-2, weight 3)
- Vertex 3's parent is 0 (edge 0-3, weight 6)
- Vertex 4's parent is 1 (edge 1-4, weight 5)

Total weight = 2 + 3 + 6 + 5 = 16
```

### Output:

**text**

```
Edges in MST:
0 - 1 : 2
1 - 2 : 3
0 - 3 : 6
1 - 4 : 5
Total weight of MST = 16
```

## Visual Representation of MST:

**text**

```
    0
   / \
 2/   \6
 /     \
1---3---3
| \     |
|  \    |
5|   \  |9
|    \ |
4-----2
   7
```

The MST edges are: 0-1(2), 1-2(3), 0-3(6), 1-4(5)

The algorithm successfully finds the minimum spanning tree that connects all vertices with total weight 16, which is the minimum possible for this graph.
