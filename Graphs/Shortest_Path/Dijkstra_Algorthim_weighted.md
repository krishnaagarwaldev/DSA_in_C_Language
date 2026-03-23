## Initial Graph (n=5, source=0)

Adjacency matrix:

**text**

```
   0   1   2   3   4
0: 0  10   0  30 100
1:10   0  50   0   0
2: 0  50   0  20  10
3:30   0  20   0  60
4:100 0   10  60   0
```

## Initialization

**text**

```
dist = [0, INF, INF, INF, INF]
visited = [0, 0, 0, 0, 0]
```

## Iteration 1

* **Find minimum** : u = 0 (dist=0, unvisited)
* **Mark visited[0] = 1**
* **Relax edges from vertex 0** :
* v=1: adj[0][1]=10 → dist[1] = min(INF, 0+10) = **10**
* v=2: adj[0][2]=0 → skip
* v=3: adj[0][3]=30 → dist[3] = min(INF, 0+30) = **30**
* v=4: adj[0][4]=100 → dist[4] = min(INF, 0+100) = **100**

 **After iteration 1** :

**text**

```
dist = [0, 10, INF, 30, 100]
visited = [1, 0, 0, 0, 0]
```

## Iteration 2

* **Find minimum** : u = 1 (dist=10, unvisited)
* **Mark visited[1] = 1**
* **Relax edges from vertex 1** :
* v=0: visited[0]=1 → skip
* v=2: adj[1][2]=50 → dist[2] = min(INF, 10+50) = **60**
* v=3: adj[1][3]=0 → skip
* v=4: adj[1][4]=0 → skip

 **After iteration 2** :

**text**

```
dist = [0, 10, 60, 30, 100]
visited = [1, 1, 0, 0, 0]
```

## Iteration 3

* **Find minimum** : u = 3 (dist=30, unvisited)
* **Mark visited[3] = 1**
* **Relax edges from vertex 3** :
* v=0: visited[0]=1 → skip
* v=1: visited[1]=1 → skip
* v=2: adj[3][2]=20 → dist[2] = min(60, 30+20) = min(60, 50) = **50** (updated!)
* v=4: adj[3][4]=60 → dist[4] = min(100, 30+60) = min(100, 90) = **90** (updated!)

 **After iteration 3** :

**text**

```
dist = [0, 10, 50, 30, 90]
visited = [1, 1, 0, 1, 0]
```

## Iteration 4

* **Find minimum** : u = 2 (dist=50, unvisited)
* **Mark visited[2] = 1**
* **Relax edges from vertex 2** :
* v=0: visited[0]=1 → skip
* v=1: visited[1]=1 → skip
* v=3: visited[3]=1 → skip
* v=4: adj[2][4]=10 → dist[4] = min(90, 50+10) = min(90, 60) = **60** (updated!)

 **After iteration 4** :

**text**

```
dist = [0, 10, 50, 30, 60]
visited = [1, 1, 1, 1, 0]
```

## Iteration 5 (Final)

* **Find minimum** : u = 4 (dist=60, unvisited)
* **Mark visited[4] = 1**
* No unvisited neighbors to relax

## Final Result

**text**

```
Shortest distances from source 0:
To 0 = 0
To 1 = 10
To 2 = 50
To 3 = 30
To 4 = 60
```

## Path Verification

* **0→1** : Direct edge (10)
* **0→3** : Direct edge (30)
* **0→2** : 0→3→2 (30 + 20 = 50)
* **0→4** : 0→3→2→4 (30 + 20 + 10 = 60)

The algorithm correctly found the shortest paths from source vertex 0 to all other vertices.
