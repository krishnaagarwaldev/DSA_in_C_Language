# 🟢 GROUP 1: Minimize the Maximum (Most Common)

### 📌 Pattern:

We are asked to:

> Minimize the maximum value

### 🔎 General Form:

* Divide something
* Distribute something
* Allocate something
* Split array
* Find minimum capacity


low = max_element
high = sum_of_elements

while(low <= high)
{
    mid = (low + high)/2;

    if(isPossible(mid))
    {
        ans = mid;
        high = mid - 1;   // try smaller
    }
    else
        low = mid + 1;
}


## 📚 Problems in This Group

1. **Book Allocation**
2. **Painter Partition**
3. **Split Array Largest Sum**
4. **Capacity to Ship Packages Within D Days**
5. **Minimum Days to Make Bouquets**
6. **Find Smallest Divisor Given Threshold**
7. **Koko Eating Bananas**

## 🎯 Core Logic

👉 If capacity/speed/pages works

→ Try smaller value

👉 If it fails

→ Increase answer


# 🟢 GROUP 2: Maximize the Minimum

### 📌 Pattern:

We are asked to:

> Maximize the minimum distance / value
>
>
> low = 1;
> high = max_possible_distance;
>
> while(low <= high)
> {
>     mid = (low + high)/2;
>
>     if(isPossible(mid))
>     {
>         ans = mid;
>         low = mid + 1;   // try bigger
>     }
>     else
>         high = mid - 1;
> }


## 📚 Problems in This Group

1. **Aggressive Cows**
2. **Magnetic Force Between Two Balls**
3. **Place k elements with maximum minimum difference**
4. **Allocate minimum distance between routers**
5. **Maximum minimum sweetness (chocolate problem)**

## 🎯 Core Logic

👉 If distance works

→ Try larger

👉 If it fails

→ Reduce distance


# 🟢 GROUP 3: Binary Search on Sorted Answer Space

These are different from answer-based ones.

---

## 📚 Problems

1. **Peak Element**
2. **Search in Rotated Sorted Array**
3. **Find Minimum in Rotated Sorted Array**
4. **First and Last Occurrence**
5. **Count Occurrences**
6. **Single Element in Sorted Array**
7. **Search Insert Position**

### Pattern:

Direct binary search on array, not on answer range.


# 🟢 GROUP 4: Binary Search on 2 Arrays (Hard)

---

## 📚 Problems

1. **Median of Two Sorted Arrays**
2. **Kth Element of Two Sorted Arrays**

---

### Pattern:

Binary search on smaller array

Use partition logic


# 🟢 GROUP 5: Numeric Root / Math Based

---

## 📚 Problems

1. **Nth Root of a Number**
2. **Square Root of X**
3. **Cube Root**
4. **Find Floor of Root**

---

### Pattern:

Search in numeric range

Check using multiplication


# 🧠 HOW TO IDENTIFY IN EXAM (Very Important)

If question says:

* Minimum capacity
* Maximum distance
* Minimum speed
* Minimum days
* Largest minimum
* Smallest divisor
* Allocate
* Split

👉 Immediately think:

<pre class="overflow-visible! px-0!" data-start="2994" data-end="3025"><div class="relative w-full my-4"><div class=""><div class="relative"><div class="h-full min-h-0 min-w-0"><div class="h-full min-h-0 min-w-0"><div class="border border-token-border-light border-radius-3xl corner-superellipse/1.1 rounded-3xl"><div class="h-full w-full border-radius-3xl bg-token-bg-elevated-secondary corner-superellipse/1.1 overflow-clip rounded-3xl lxnfua_clipPathFallback"><div class="pointer-events-none absolute inset-x-4 top-12 bottom-4"><div class="pointer-events-none sticky z-40 shrink-0 z-1!"><div class="sticky bg-token-border-light"></div></div></div><div class=""><div class="relative z-0 flex max-w-full"><div id="code-block-viewer" dir="ltr" class="q9tKkq_viewer cm-editor z-10 light:cm-light dark:cm-light flex h-full w-full flex-col items-stretch ͼk ͼy"><div class="cm-scroller"><div class="cm-content q9tKkq_readonly"><span>Binary Search on Answer</span></div></div></div></div></div></div></div></div></div><div class=""><div class=""></div></div></div></div></div></pre>

---

# 🚀 Quick Summary Table

| Type             | Move if Possible | Goal    |
| ---------------- | ---------------- | ------- |
| Minimize Maximum | high = mid - 1   | Smaller |
| Maximize Minimum | low = mid + 1    | Bigger  |
