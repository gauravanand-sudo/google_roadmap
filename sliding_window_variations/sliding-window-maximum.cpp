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



*/
