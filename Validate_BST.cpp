class Solution {
public:
    bool solve(TreeNode* root,long long lrange,long long rrange)
    {
        if(root == NULL) return true;
        if(root -> val <= lrange || root -> val >= rrange) return false;
        bool left = solve(root -> left, lrange, root->val);
        if(left == false) return false;
        bool right = solve(root -> right, root->val, rrange);
        if(right == false) return false;
        return true;
    }

    bool isValidBST(TreeNode* root) {
        return solve(root,LONG_MIN,LONG_MAX);
    }
};