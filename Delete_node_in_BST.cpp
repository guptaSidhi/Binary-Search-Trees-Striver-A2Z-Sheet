class Solution {
public:
    TreeNode* solve(TreeNode* root)
    {
        if(root -> left == NULL) return root->right;
        else if(root -> right == NULL) return root->left;
        TreeNode* temp = root -> left;
        while(temp -> right != NULL) temp = temp -> right;
        temp -> right = root -> right;
        return root -> left;
    }

    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root == NULL) return NULL;
        if(root -> val == key) return solve(root);
        TreeNode* temp = root;

        while(temp != NULL)
        {
            if(temp->val > key)
            {
                if(temp->left != NULL && temp->left->val == key)
                {
                    temp -> left = solve(temp -> left);
                    break;
                }
                else temp = temp -> left;
            }
            else
            {
                if(temp->right != NULL && temp->right->val == key)
                {
                    temp -> right = solve(temp -> right);
                    break;
                }
                else temp = temp -> right;
            }
        }

        return root;
    }
};