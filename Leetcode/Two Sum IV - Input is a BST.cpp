/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        //we can traverse the tree using recursion
        map<int, int> freq;
        //we store the frequency of node values in map
        freqCal(root, freq);

        return Traverse(root, freq, k);
    }
    void freqCal(TreeNode* ptr, map<int, int>& freq) {
        if (ptr == NULL) return;
        freq[ptr->val]++;
        //we do the same work for left subtree and right subtree
        freqCal(ptr->left, freq);
        freqCal(ptr->right, freq);

        //since this is a void method we may or may not add return at the end like this
        // return;
    }
    bool Traverse(TreeNode* ptr, map<int, int> freq, int target) {
        if (ptr == NULL) return false;
        if ((ptr->val != (target - ptr->val)) && freq[target - (ptr->val)])
            return true;
        //this is temporary change
        //if either of the left subtree or right subtree returns true then answer would be true
        if (Traverse(ptr->left, freq, target) || Traverse(ptr->right, freq, target))
            return true;
        else return false;
    }

};
