// https://leetcode.com/problems/kth-largest-element-in-a-stream/



#include <bits/stdc++.h>
using namespace std;


// --------------------------------- Approach-1 (BRUTE) ----------------------------------------------------------------

// TC : O(M * N*log(N)) Where M = No. of times fn. get called
// SC : O(N)    N = No. of elements stored in the array
class KthLargest {
public:
    int k;
    vector<int> arr;
    KthLargest(int k, vector<int>& nums) {
        arr = nums;
        this -> k = k;
    }
    
    int add(int val) {
        arr.push_back(val);
        sort(rbegin(arr), rend(arr));
        arr.erase(begin(arr), begin(arr) + 1);
        return arr[k - 1];
    }
};


// -------------------------------- Approach-2 (OPTIMAL) ----------------------------------------------------------------

// TC : O(M*log(K))
// SC : O(K) K = size of minHeap
class KthLargest {
public:
    priority_queue<int, vector<int>, greater<int>> pq;
    int k;

    // TC : O(log(K))
    KthLargest(int k, vector<int>& nums) {
        this -> k = k;

        for (int num : nums) {
            pq.push(num);
            if (pq.size() > k) 
                pq.pop();
        }
    }
    
    // TC : O(M * log(K)) where M = No. of times 'add' fn gets called
    int add(int val) {
        pq.push(val);
        if (pq.size() > k) 
            pq.pop();
        return pq.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */