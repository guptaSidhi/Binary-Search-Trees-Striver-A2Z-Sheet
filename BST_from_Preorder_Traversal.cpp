class Solution {
public:
    int find(vector <int> &in,int start,int end,int value)
    {
        for(int i=start;i<=end;i++)
        {
            if(in[i] == value) return i;
        }
        return -1;
    }

    TreeNode* solve(vector <int> &pre,vector <int> &in,int pres,int pred, int ins,int ind)
    {
        if(pres > pred ||  ins > ind) return NULL;
        TreeNode* root = new TreeNode(pre[pres]);
        int index = find(in,ins,ind,root->val);
        if(index == -1) return NULL;
        int num = index - ins;
        root -> left = solve(pre,in,pres+1,pres+num,ins,index-1);
        root -> right = solve(pre,in,pres+num+1,pred,index+1,ind);
        return root;
    }

    TreeNode* bstFromPreorder(vector<int>& preorder) {
        if(preorder.size() == 0) return NULL;
        vector <int> inorder(preorder.begin(),preorder.end());
        sort(inorder.begin(),inorder.end());
        return solve(preorder,inorder,0,preorder.size()-1,0,inorder.size()-1);
    }
};