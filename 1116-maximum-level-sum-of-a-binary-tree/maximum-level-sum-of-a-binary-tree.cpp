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
    int maxLevelSum(TreeNode* root) {
        //go through each level in order using BFS and queue
        // if that level is greater than max than we update the maxlevel by 1 
        //else we move forward
        int maxLevel = 1;
        int max = root->val;
        int currentLevel = 1;

        queue<TreeNode*> que;

        que.push(root);
        max += root->val;

        while(!que.empty()){
            int size = que.size();
            int currLevelSum = 0;

            for(int i = 0; i < size; i++){
                TreeNode* curr = que.front();
                que.pop();

                currLevelSum += curr->val;

                if(curr->right != NULL){
                    que.push(curr->right);
                }

                if(curr->left != NULL){
                    que.push(curr->left);
                }
            }

            if(currLevelSum > max) {
                max = currLevelSum;
                maxLevel = currentLevel;
            }

            currentLevel++;
        }
    return maxLevel;
    }
};