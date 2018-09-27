/*
Given a binary tree and a sum, find all root-to-leaf paths where each path's sum equals the given sum.

Note: A leaf is a node with no children.

Example:

Given the below binary tree and sum = 22,

      5
     / \
    4   8
   /   / \
  11  13  4
 /  \    / \
7    2  5   1
Return:

[
   [5,4,11,2],
   [5,8,4,5]
]
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> res;
        vector<int> out;
        pathSumDFS(root, sum, out, res);
        return res;
    }
    
    void pathSumDFS(TreeNode* root, int sum, vector<int> &out, vector<vector<int>> &res) {
        if(root != NULL){
            out.push_back(root->val);
            if (root->left == NULL && root->right == NULL){
                if (sum == root->val){
                    res.push_back(out);
                }
            }
            else {
                pathSumDFS(root->left, sum-root->val, out, res);
                pathSumDFS(root->right, sum-root->val, out, res);
            }
            out.pop_back(); // 一定要出栈
        }
    }
};
