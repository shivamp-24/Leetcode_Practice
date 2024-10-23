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
    TreeNode* replaceValueInTree(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        vector<int> tp;
        while(!q.empty()){
            int sz=q.size();
            int sum=0;
            for(int i=0;i<sz;i++){
                TreeNode* curr=q.front();
                q.pop();
                sum+=curr->val;
                if(curr->left) q.push(curr->left);
                if(curr->right) q.push(curr->right);
            }
            tp.push_back(sum);
        }
        q.push(root);
        int n=tp.size();
        root->val=0;
        int level=0;
        while(!q.empty()){
            int sz=q.size();
            for(int i=0;i<sz;i++){
                TreeNode* curr=q.front();
                q.pop();
                int childSum=0;
                if(curr->left) childSum+=curr->left->val;
                if(curr->right) childSum+=curr->right->val;
                int totSum;
                if(level+1<n) totSum=tp[level+1];
                if(curr->left){
                    curr->left->val=totSum-childSum;
                    q.push(curr->left);
                }
                if(curr->right){
                    curr->right->val=totSum-childSum;
                    q.push(curr->right);
                }
            }
            level++;
        }
        return root;
    }
};