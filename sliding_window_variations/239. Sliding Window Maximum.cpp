/*

239. Sliding Window Maximum
Solved
Hard
Topics
premium lock icon
Companies
Hint
You are given an array of integers nums, there is a sliding window of size k which is moving from the very left of the array to the very right. You can only see the k numbers in the window. Each time the sliding window moves right by one position.

Return the max sliding window.


*/
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        // dequeue of indexes
        deque<int> dq;
        vector<int> maxInKWindow;

        for(int ind = 0; ind < nums.size(); ind++){
            // remove element out of k window
            while (dq.size() && ind-dq.front() >= k) dq.pop_front();
            while (dq.size() && nums[ind] >= nums[dq.back()]) dq.pop_back();
            dq.push_back(ind);
            if (ind >= k-1) maxInKWindow.push_back(nums[dq.front()]);

        }
        return maxInKWindow;
    }
};


/*
[1,3,-1,-3,5,3,6,7], k = 3

Yes — this “sliding window maximum” problem is a classic, so interviewers often follow up with tweaks to see if you truly understand the deque pattern and its limits.
Here are some common follow-ups and their **intuitive** solutions:

---

**1️⃣ What if we needed the *minimum* in each sliding window instead of the maximum?**

* **Change:** When maintaining the deque, pop from the back while the new element is **smaller** (instead of larger).
* **Why:** Same logic — the front holds the smallest element for that window.
* **Key tweak:**

```cpp
while (!dq.empty() && nums[ind] <= nums[dq.back()]) dq.pop_back();
```

---

**2️⃣ What if `k` is very large, possibly equal to `n`?**

* **Observation:** Same deque method works in O(n) time — no changes needed. The first output is just the max of the whole array.
* **Trickiness:** Make sure you don’t do an O(nk) scan.

---

**3️⃣ What if we need the maximum of *all* prefixes of length ≤ k (not exactly k)?**

* **Observation:** That’s like multiple window sizes at once.
* **Quick intuition:** You can adapt the deque to output at each step the max for the current window size (which grows until `k`, then stays at `k`), still O(n).

---

**4️⃣ How would you do it *offline* if all queries were given in advance (different k’s)?**

* **Idea:** Use a Sparse Table or Segment Tree for range max queries.
* **Why:** Preprocess in O(n log n) then answer any window max in O(1) (Sparse Table) or O(log n) (Segment Tree).

---

**5️⃣ Could you solve it with a heap instead of a deque?**

* **Yes:** Push `(value, index)` into a max-heap. Pop while the top index is out of the window.
* **Trade-off:** O(n log k) time instead of O(n), simpler if you already know heaps.

---

**6️⃣ What if the input is a *stream* (you can’t store the whole array)?**

* **Approach:** Keep the deque for the current window in memory; push each incoming number, evict old ones. Output max each time. Works in O(1) amortized per element.
* **Limitation:** You can’t revisit past elements, so you can only output “online.”

---

**7️⃣ What if we also need the *second largest* in the window?**

* **Approach:** Still store indices in decreasing order in the deque, but now track top 2 values from the front of deque and next index.
* **Alternative:** Keep a balanced BST (or multiset in C++) of the k elements — then you can get top 2 in O(log k) per step.

---

If you want, I can prepare a **single diagram** showing the deque’s behavior so that these variants make visual sense in one shot — that’s a favorite interviewer “whiteboard moment.”




*/
