class Solution {
    int max_num=INT_MIN;
public:
    
    unordered_map<TreeNode*,int>umap;
    int helper(TreeNode*root){
        
        if(root==NULL)return 0;
        if(umap[root])return umap[root];
        int left_max=0;
        int right_max=0;
        if(root->left){
            left_max=helper(root->left->left)+helper(root->left->right);
        }
       if(root->right){
            right_max=helper(root->right->left)+helper(root->right->right);
       }
        
        return umap[root]=max(root->val+left_max+right_max,helper(root->left)+helper(root->right));
        
        
    }

    
    int rob(TreeNode* root) {
        return helper(root);
    }
};