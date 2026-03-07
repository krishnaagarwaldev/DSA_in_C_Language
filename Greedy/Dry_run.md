For  **all 3 Greedy problems** :

* ✅ Detailed approach
* ✅ Proper pseudocode (exam-ready)
* ✅ Complete dry run step-by-step
* ✅ What to write in 10-mark answer

We’ll do:

1. Fractional Knapsack
2. Activity Selection
3. Job Sequencing with Deadline

---

# 🔶 1️⃣ Fractional Knapsack

---

## ✅ Problem Statement

Given:

* n items (profit, weight)
* Capacity W

Goal: Maximize total profit (items can be taken fractionally)

---

## ✅ Greedy Approach (WHY?)

We choose item with **maximum profit/weight ratio** first.

Because:

* Each unit weight should give maximum profit.
* Taking highest ratio first gives global maximum.

---

## ✅ Algorithm Steps

1. Compute ratio = profit / weight
2. Sort items in descending order of ratio
3. For each item:
   * If full item fits → take it
   * Else → take fractional part
4. Stop when capacity becomes 0

---

## ✅ Pseudocode

<pre class="overflow-visible! px-0!" data-start="906" data-end="1296"><div class="relative w-full my-4"><div class=""><div class="relative"><div class="h-full min-h-0 min-w-0"><div class="h-full min-h-0 min-w-0"><div class="border border-token-border-light border-radius-3xl corner-superellipse/1.1 rounded-3xl"><div class="h-full w-full border-radius-3xl bg-token-bg-elevated-secondary corner-superellipse/1.1 overflow-clip rounded-3xl lxnfua_clipPathFallback"><div class="pointer-events-none absolute inset-x-4 top-12 bottom-4"><div class="pointer-events-none sticky z-40 shrink-0 z-1!"><div class="sticky bg-token-border-light"></div></div></div><div class=""><div class="relative z-0 flex max-w-full"><div id="code-block-viewer" dir="ltr" class="q9tKkq_viewer cm-editor z-10 light:cm-light dark:cm-light flex h-full w-full flex-col items-stretch ͼk ͼy"><div class="cm-scroller"><div class="cm-content q9tKkq_readonly"><span>FractionalKnapsack(items, n, W)</span><br/><br/><span>1. For i = 1 to n</span><br/><span>       items[i].ratio = profit / weight</span><br/><br/><span>2. Sort items in descending order of ratio</span><br/><br/><span>3. totalProfit = 0</span><br/><br/><span>4. For i = 1 to n</span><br/><span>       If W >= items[i].weight</span><br/><span>            totalProfit += items[i].profit</span><br/><span>            W = W - items[i].weight</span><br/><span>       Else</span><br/><span>            totalProfit += items[i].ratio * W</span><br/><span>            Break</span><br/><br/><span>5. Return totalProfit</span></div></div></div></div></div></div></div></div></div><div class=""><div class=""></div></div></div></div></div></pre>

---

## ✅ Dry Run Example

Items:

| Profit | Weight |
| ------ | ------ |
| 60     | 10     |
| 100    | 20     |
| 120    | 30     |

Capacity = 50

---

### Step 1: Calculate Ratio

| Profit | Weight | Ratio |
| ------ | ------ | ----- |
| 60     | 10     | 6     |
| 100    | 20     | 5     |
| 120    | 30     | 4     |

---

### Step 2: Sort (Descending Ratio)

Order remains same:

6 → 5 → 4

---

### Step 3: Fill Knapsack

Capacity = 50

* Take Item1 (10kg)
  * Profit = 60
  * Capacity = 40
* Take Item2 (20kg)
  * Profit = 160
  * Capacity = 20
* Item3 weight = 30 (cannot take fully)
  * Take 20/30 fraction
  * Profit = 4 × 20 = 80

Final Profit:

60 + 100 + 80 = **240**

---

## ✅ Time Complexity

Sorting → O(n log n)

Loop → O(n)

Overall → O(n log n)

---

# 🔶 2️⃣ Activity Selection

---

## ✅ Problem Statement

Given n activities with start and finish times.

Select maximum number of non-overlapping activities.

---

## ✅ Greedy Idea

Always pick activity that finishes earliest.

WHY?

Because finishing early leaves more room for future activities.

---

## ✅ Algorithm Steps

1. Sort activities by finish time (ascending)
2. Select first activity
3. For each next activity:
   * If start ≥ last selected finish
     * Select it

---

## ✅ Pseudocode

<pre class="overflow-visible! px-0!" data-start="2523" data-end="2761"><div class="relative w-full my-4"><div class=""><div class="relative"><div class="h-full min-h-0 min-w-0"><div class="h-full min-h-0 min-w-0"><div class="border border-token-border-light border-radius-3xl corner-superellipse/1.1 rounded-3xl"><div class="h-full w-full border-radius-3xl bg-token-bg-elevated-secondary corner-superellipse/1.1 overflow-clip rounded-3xl lxnfua_clipPathFallback"><div class="pointer-events-none absolute inset-x-4 top-12 bottom-4"><div class="pointer-events-none sticky z-40 shrink-0 z-1!"><div class="sticky bg-token-border-light"></div></div></div><div class=""><div class="relative z-0 flex max-w-full"><div id="code-block-viewer" dir="ltr" class="q9tKkq_viewer cm-editor z-10 light:cm-light dark:cm-light flex h-full w-full flex-col items-stretch ͼk ͼy"><div class="cm-scroller"><div class="cm-content q9tKkq_readonly"><span>ActivitySelection(A, n)</span><br/><br/><span>1. Sort A by finish time (ascending)</span><br/><br/><span>2. Select first activity</span><br/><span>   lastFinish = A[1].finish</span><br/><br/><span>3. For i = 2 to n</span><br/><span>       If A[i].start >= lastFinish</span><br/><span>            Select A[i]</span><br/><span>            lastFinish = A[i].finish</span></div></div></div></div></div></div></div></div></div><div class=""><div class=""></div></div></div></div></div></pre>

---

## ✅ Dry Run Example

Start =  {1, 3, 0, 5, 8, 5}

Finish = {2, 4, 6, 7, 9, 9}

---

### Step 1: Sort by Finish

Sorted:

(1,2)

(3,4)

(0,6)

(5,7)

(8,9)

(5,9)

---

### Step 2: Select Activities

Pick first → (1,2)

Last finish = 2

Next:

(3,4) → 3 ≥ 2 ✔ select

Last finish = 4

(0,6) → 0 < 4 ✘ reject

(5,7) → 5 ≥ 4 ✔ select

Last finish = 7

(8,9) → 8 ≥ 7 ✔ select

Last finish = 9

(5,9) → 5 < 9 ✘ reject

---

### Final Selected

(1,2)

(3,4)

(5,7)

(8,9)

Total = 4 activities

---

## ✅ Time Complexity

Sorting → O(n log n)

Loop → O(n)

Overall → O(n log n)

---

# 🔶 3️⃣ Job Sequencing with Deadline

---

## ✅ Problem Statement

Each job has:

* Deadline
* Profit
* Takes 1 unit time

Goal: Maximize profit.

---

## ✅ Greedy Idea

Pick highest profit job first and assign it to latest available slot before deadline.

WHY latest slot?

So earlier slots remain free for other jobs.

---

## ✅ Algorithm Steps

1. Sort jobs by profit (descending)
2. Create slot array
3. For each job:
   * Check from deadline to 1
   * If slot free → assign

---

## ✅ Pseudocode

<pre class="overflow-visible! px-0!" data-start="3864" data-end="4234"><div class="relative w-full my-4"><div class=""><div class="relative"><div class="h-full min-h-0 min-w-0"><div class="h-full min-h-0 min-w-0"><div class="border border-token-border-light border-radius-3xl corner-superellipse/1.1 rounded-3xl"><div class="h-full w-full border-radius-3xl bg-token-bg-elevated-secondary corner-superellipse/1.1 overflow-clip rounded-3xl lxnfua_clipPathFallback"><div class="pointer-events-none absolute inset-x-4 top-12 bottom-4"><div class="pointer-events-none sticky z-40 shrink-0 z-1!"><div class="sticky bg-token-border-light"></div></div></div><div class=""><div class="relative z-0 flex max-w-full"><div id="code-block-viewer" dir="ltr" class="q9tKkq_viewer cm-editor z-10 light:cm-light dark:cm-light flex h-full w-full flex-col items-stretch ͼk ͼy"><div class="cm-scroller"><div class="cm-content q9tKkq_readonly"><span>JobSequencing(J, n)</span><br/><br/><span>1. Sort jobs in descending order of profit</span><br/><br/><span>2. Create array slot[1..maxDeadline] = empty</span><br/><br/><span>3. totalProfit = 0</span><br/><br/><span>4. For i = 1 to n</span><br/><span>       For j = J[i].deadline down to 1</span><br/><span>            If slot[j] is empty</span><br/><span>                slot[j] = J[i]</span><br/><span>                totalProfit += J[i].profit</span><br/><span>                Break</span><br/><br/><span>5. Print scheduled jobs</span><br/><span>6. Return totalProfit</span></div></div></div></div></div></div></div></div></div><div class=""><div class=""></div></div></div></div></div></pre>

---

## ✅ Dry Run Example

| Job | Deadline | Profit |
| --- | -------- | ------ |
| A   | 2        | 100    |
| B   | 1        | 19     |
| C   | 2        | 27     |
| D   | 1        | 25     |

---

### Step 1: Sort by Profit

A(100)

C(27)

D(25)

B(19)

---

Max Deadline = 2

Slots = [ _ , _ ]

---

### Step 2: Assign Jobs

A (deadline 2)

Check slot 2 → empty ✔

Slots = [ _, A ]

C (deadline 2)

Check slot 2 → full

Check slot 1 → empty ✔

Slots = [ C , A ]

D (deadline 1)

Check slot 1 → full ✘

B (deadline 1)

Check slot 1 → full ✘

---

Final Jobs:

C A

Profit = 27 + 100 = **127**

---

## ✅ Time Complexity

Sorting → O(n log n)

Assignment → O(n²) worst case

Overall → O(n log n)

---

# 🔥 Final Comparison

| Problem    | Greedy Choice     |
| ---------- | ----------------- |
| Fractional | Max profit/weight |
| Activity   | Min finish time   |
| Job Seq    | Max profit        |
