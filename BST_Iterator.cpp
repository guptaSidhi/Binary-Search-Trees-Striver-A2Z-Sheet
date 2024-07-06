class BSTIterator {
public:
    stack<TreeNode*> s;

    BSTIterator(TreeNode* root) {
        TreeNode* temp = root;
        while (temp != nullptr) {
            s.push(temp);
            temp = temp->left;
        }
    }

    int next() {
        TreeNode* value = s.top();
        s.pop();

        if (value->right != nullptr) {
            TreeNode* temp = value->right;
            while (temp != nullptr) {
                s.push(temp);
                temp = temp->left;
            }
        }

        return value->val;
    }

    bool hasNext() {
        return !s.empty();
    }
};