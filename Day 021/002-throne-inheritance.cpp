// https://leetcode.com/problems/throne-inheritance/



#include <bits/stdc++.h>
using namespace std;

// --------------------------------- Approach-1 (USING MAP & DFS) ----------------------------------------------------------------

// TC : O(N)
// SC : O(N)
class ThroneInheritance {
public:
    unordered_map<string, vector<string>> mpp;
    unordered_set<string> st;
    string root;

    // TC : O(1)
    ThroneInheritance(string kingName) {
        mpp[kingName];
        root = kingName;
    }

    // TC : O(1)
    void birth(string parentName, string childName) {
        mpp[parentName].push_back(childName);
    }
    
    // TC : O(1)
    void death(string name) {
        st.insert(name);
    }

    // TC : O(N)
    void dfs(string root, vector<string>& result) {
        if (st.find(root) == st.end())
            result.push_back(root);

        for (string child : mpp[root]) {
            dfs(child, result);
        }
    }

    // TC : O(N)
    vector<string> getInheritanceOrder() {
        vector<string> result;
        dfs(root, result);
        return result;
    }
};


// ------------------------------- Approach-2 (USING TREE DS) ----------------------------------------------------------------

class Node {
public:
    string name; // name of the person
    bool alive;  // status of the person
    vector<Node*> childrens; // children of the person

    // Default constructor
    Node() {}

    // Parameterized constructor
    Node(string name) {
        this -> alive = true; // set the status to alive
        this -> name = name;  // set the name
    }
};

// TC : O(N)
// SC : O(N)
class ThroneInheritance {
public:
    Node* root; // root of the inheritance tree
    unordered_map<string, Node*> mpp; // map to store the name-node pairs
    
    // TC : O(1)
    // Constructor
    ThroneInheritance(string kingName) {
        // create a new node for the king
        root = new Node(kingName); 
        // add the king to the map
        mpp[kingName] = root;      
    }

    // TC : O(1)
    // Function to add a child to a parent
    void birth(string parentName, string childName) {
        // create a new node for the child
        Node* newNode = new Node(childName); 
        // add the child to the parent's list of children
        mpp[parentName] -> childrens.push_back(newNode);
        // add the child to the map 
        mpp[childName] = newNode; 
    }
    
    // TC : O(1)
    // Function to mark a person as dead
    void death(string name) {
        mpp[name] -> alive = 0; // set the person's status to dead
    }

    // TC : O(N)
    // Depth-first search function
    void preorder(Node* root, vector<string>& result) {
        if (root != NULL) { // if the node is not null
            if (root -> alive) { // if the person is alive
                result.push_back(root -> name); // add them to the inheritance order
            }
            for (int i = 0; i < root -> childrens.size(); i++) { // for each child of the current person
                preorder(root -> childrens[i], result); // perform a depth-first search on the child
            }
        }
    }

    // TC : O(N)
    // Function to get the inheritance order
    vector<string> getInheritanceOrder() {
        vector<string> result; // vector to store the inheritance order
        preorder(root, result); // perform a depth-first search on the root

        return result; // return the inheritance order
    }
};

/**
 * Your ThroneInheritance object will be instantiated and called as such:
 * ThroneInheritance* obj = new ThroneInheritance(kingName);
 * obj->birth(parentName,childName);
 * obj->death(name);
 * vector<string> param_3 = obj->getInheritanceOrder();
 */