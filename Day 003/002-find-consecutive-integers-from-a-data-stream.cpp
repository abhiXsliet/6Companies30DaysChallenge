// https://leetcode.com/problems/find-consecutive-integers-from-a-data-stream/



#include <bits/stdc++.h>
using namespace std;

// ------------------------------   Brute force (TLE)-------------------------------------------------------------------
// The Operations (push, pop, front) takes O(1), 
// However performing these operations k-times in a loop, which makes the time complexity O(k)
// And since you are doing this for every call to consec, the time complexity becomes O(k2) per call

// TC : O(k^2)
// SC : O(k)

class DataStream {
public:
    queue<int> q;
    int val;
    int k;
    DataStream(int value, int k) {
        this -> val = value;
        this -> k   = k;
    }
    
    bool consec(int num) {
        q.push(num);
        while (q.size() > k) {
            q.pop();
        }
        if (q.size() < k) {
            return false;
        }
        bool isEqual = true;
        for (int i = 0; i < k; i++) {
            int front = q.front();
            q.pop();
            if (front != val) {
                isEqual = false;
            }
            q.push(front);
        }
        return isEqual;
    }
};

/**
 * Your DataStream object will be instantiated and called as such:
 * DataStream* obj = new DataStream(value, k);
 * bool param_1 = obj->consec(num);
 */



// -------------------------------------- Better Solution(Accepted) --------------------------------------------------------

// TC : O(1)
// SC : O(k) where k is the maximum size of the queue. Beacause storing the last k integers in the queue.

class DataStream {
public:
    queue<int> q;
    int val;
    int k;
    int count;
    DataStream(int value, int k) {
        this -> val = value;
        this -> k   = k;
        this -> count = 0;
    }
    
    bool consec(int num) {
        q.push(num);
        if(num == val) {
            count++;
        }
        if(q.size() > k) {
            if(q.front() == val) {
                count--;
            }
            q.pop();
        }
        return q.size() == k && count == k;
    }
};

/**
 * Your DataStream object will be instantiated and called as such:
 * DataStream* obj = new DataStream(value, k);
 * bool param_1 = obj->consec(num);
 */



// ------------------------------------------ Optimal Solution (Accepted) -----------------------------------------------------
// TC : O(1)
// SC : O(1)

class DataStream {
public:
    int val;
    int k;
    int valFreq = 0;
    DataStream(int value, int k) {
        this -> val = value;
        this -> k   = k;
    }
    
    bool consec(int num) {
        if (num == val) 
            valFreq ++;
        else 
            valFreq = 0;

        return valFreq >= k;
    }
};

/**
 * Your DataStream object will be instantiated and called as such:
 * DataStream* obj = new DataStream(value, k);
 * bool param_1 = obj->consec(num);
 */