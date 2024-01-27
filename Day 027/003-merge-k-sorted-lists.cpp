// https://leetcode.com/problems/merge-k-sorted-lists/



#include <bits/stdc++.h>
using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
private:
    // TC : O(n), where n is the total number of nodes in the two lists
    // SC : O(1), as it only uses a constant amount of space
    ListNode* mergeTwoSortedLL(ListNode* first, ListNode* second) {
        if (!first ) return second;
        if (!second) return first;

        if (first -> val <= second -> val) { 
            first -> next  = mergeTwoSortedLL(first -> next, second);
            return first;
        }
        else {
            second -> next = mergeTwoSortedLL(first, second -> next);
            return second;
        }
        return NULL;
    }

    // TC : O(n log k), where n is the total number of nodes across all lists and k is the number of linked lists
    // SC : O(log k), due to the recursive stack space used by the divide and conquer approach
    ListNode* partition(vector<ListNode*>& list, int start, int end) {
        if (start  > end) return NULL;
        if (start == end) return list[start];

        int mid = start + (end - start) / 2;

        ListNode* first  = partition(list, start  , mid);
        ListNode* second = partition(list, mid + 1, end);
        
        return mergeTwoSortedLL(first, second);
    }
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        return partition(lists, 0, lists.size() - 1);
    }
};