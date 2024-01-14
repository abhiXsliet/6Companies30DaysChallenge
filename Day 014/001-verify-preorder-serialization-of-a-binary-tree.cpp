// https://leetcode.com/problems/verify-preorder-serialization-of-a-binary-tree/



#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    // TC : O(N)
    // SC : O(N)
    bool solve_approach_1(string& preorder) {
        int n = preorder.length();

        vector<string> nodes;
        string current;
        for (int i = 0; i < n; i++) {
            if (preorder[i] == ',') {
                if (!current.empty()) {
                    nodes.push_back(current);
                    current.clear();
                }
            }
            else {
                current += preorder[i];
            }
        }

        if (!current.empty()) {
            nodes.push_back(current);
        }

        int slot = 1;
        for (string node : nodes) {
            slot --;
            
            if (slot < 0) 
                return 0;

            if (node != "#")
                slot += 2;
        }
        return slot == 0;
    }

    // TC : O(N)
    // SC : O(N) at worst when all chars are 'digits' or '#' separated by commas, which would be stored in the istringstream
    bool solve_approach_2(string& preorder) {
        int n = preorder.length();
        
        istringstream stream(preorder);
        string token;
        int slots = 1; // Start with one slot for the root

        while (getline(stream, token, ',')) {
            // For each node, consume one slot
            slots--;

            // If no slots are available, it means the tree is already full
            if (slots < 0) return false;

            // If the node is not null, it adds two slots (for its children)
            if (token != "#") {
                slots += 2;
            }
        }

        // The serialization is valid if all slots are filled exactly
        return slots == 0;
    }

    // TC : O(N) where n is the length of the input string.
    // SC : O(N)
    bool solve_approach_3(string& preorder) {
        int n = preorder.length();

        // using a vector to simulate stack
        vector<string> stk;

        stringstream ss(preorder);
        string str;

        while (getline(ss, str, ',')) {
            stk.push_back(str);

            while (stk.size() >= 3 && stk[stk.size() - 1] == "#"
                    && stk[stk.size() - 2] == "#" 
                    && stk[stk.size() - 3] != "#" ) {
                
                stk.pop_back();
                stk.pop_back();
                stk.pop_back();
                stk.push_back("#");
            }
        }

        return stk.size() == 1 && stk[0] == "#";
    }
public:
    bool isValidSerialization(string preorder) {
        // return solve_approach_1(preorder);

        // return solve_approach_2(preorder);

        return solve_approach_3(preorder);
    }
};
