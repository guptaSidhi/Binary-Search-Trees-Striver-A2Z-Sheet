class Solution {
public:
    void solve(TreeNode* root,int &cnt,int k,int &ans)
    {
        if(root == NULL) return;
        solve(root->left,cnt,k,ans);
        cnt++;

        if(cnt == k) 
        {
            ans = root -> val;
            return;
        }

        solve(root -> right,cnt,k,ans);
    }

    int kthSmallest(TreeNode* root, int k) {
        int cnt = 0;
        int ans = -1;
        solve(root,cnt,k,ans);
        return ans;
    }
};