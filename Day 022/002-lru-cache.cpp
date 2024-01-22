// https://leetcode.com/problems/lru-cache/



#include <bits/stdc++.h>   
using namespace std;

// ------------------------------------- Approach-1 -> TLE (BRUTE FORCE) ----------------------------------------------------------------

// TC : O(M*N) Where M = No. of times get() & put() functions called and N = size of vector
// SC : O(N) ~= O(3000) ~= O(1)
class LRUCache {
public:
    vector<pair<int, int>> cache;   // {key, val}
    int n;
    LRUCache(int capacity) {
        n = capacity;
    }
    
    // TC : O(N)
    int get(int key) {
        for (int i = 0; i < cache.size(); i++) {
            if (cache[i].first == key) {
                int val = cache[i].second;
                // push a new entry
                cache.push_back(cache[i]);
                // remove old entry
                cache.erase(begin(cache) + i);
                return val;
            }
        }
        return -1;
    }

    // TC : O(N)
    void put(int key, int value) {
        for (int i = 0; i < cache.size(); i++) {
            if (cache[i].first == key) {
                cache.erase(begin(cache) + i);
            }
        }

        if (cache.size() == n) {
            cache.erase(begin(cache));
        }

        cache.push_back({key, value});
    }
};

// -------------------------------------- Approach-2 (OPTIMAL) -----------------------------------------------------------------

class Node {
public:
    int key;
    int val;
    
    Node* next;
    Node* prev;
    
    Node(int key, int val) {
        this -> key = key;
        this -> val = val;
    }
};

// TC : O(M) Where M = No. of times the get() function and put() function called
// SC : O(1)
class LRUCache {
public:
    Node* head = new Node(-1, -1);
    Node* tail = new Node(-1, -1);

    int capacity;
    unordered_map<int, Node*> mpp;

    LRUCache(int capacity) {
        this -> capacity = capacity;
        head -> next = tail;
        tail -> prev = head;
    }

    void addNode(Node* newNode) {
        Node* temp = head -> next;
        newNode -> next = temp;
        newNode -> prev = head;
        head -> next = newNode;
        temp -> prev = newNode;
    }

    void deleteNode(Node* delNode) {
        Node* delNext = delNode -> next;
        Node* delPrev = delNode -> prev;
        delPrev -> next = delNext;
        delNext -> prev = delPrev;
    }
    
    // TC : O(1)
    int get(int key) {
        if (mpp.find(key) != mpp.end()) {
            Node* ansNode = mpp[key];
            int ans = ansNode -> val;
            mpp.erase(key);
            deleteNode(ansNode);
            addNode(ansNode);
            mpp[key] = head -> next;
            return ans;
        }
        return -1;
    }

    // TC : O(1)
    void put(int key, int value) {
        // if the node is already available
        if (mpp.find(key) != mpp.end()) {
            Node* existingNode = mpp[key];
            mpp.erase(key);
            deleteNode(existingNode);
        }
        
        if (mpp.size() == capacity) {
            mpp.erase(tail -> prev -> key);
            deleteNode(tail -> prev);
        }

        addNode(new Node(key, value));
        mpp[key] = head -> next;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */