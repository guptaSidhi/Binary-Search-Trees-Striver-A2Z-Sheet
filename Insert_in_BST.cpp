class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int x) {
        if(root == NULL)
        {
            TreeNode* newnode = new TreeNode(x);
            return newnode;
        }
        
        TreeNode* temp = root;
        TreeNode* prev = NULL;
        while(temp != NULL)
        {
            prev = temp;
            if(temp->val > x) temp = temp -> left;
            else temp = temp -> right;
        }

        TreeNode* newnode = new TreeNode(x);
        if(prev -> val > x) prev -> left = newnode;
        else prev -> right = newnode;

        return root;
    }
};