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
    vector<vector<int>> levelOrder(TreeNode* root) {
        //the data structure that needs to be returned
        vector<vector<int>> res;
        //base case
        if(root == nullptr) return res;
        
        //using the Queue data structure (standard practice)
        queue<TreeNode*> Que;
        Que.push(root);

        while(!Que.empty()) {
            //since each level needs to be a vector of integers
            vector<int> currLevel;

            int size = Que.size();

            //now for each node in the same level push the left and right child into the 
            //queue and pop the current
            for(int i = 0; i < size; i++) {
                TreeNode* curr = Que.front();
                Que.pop();
                currLevel.push_back(curr->val);

                if(curr->left != NULL) {
                    Que.push(curr->left);
                }

                if(curr->right != NULL) {
                    Que.push(curr->right);
                }
            }
            //push the current level into the vector of levels
            res.push_back(currLevel);
        }
        return res;
    }
};