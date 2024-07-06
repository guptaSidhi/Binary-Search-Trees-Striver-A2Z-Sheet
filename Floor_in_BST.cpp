class Solution{
public:
    int floor(Node* root, int target) {
        if (root == NULL) return -1;
        Node* temp = root;
        int ans = -1;
        while(temp != NULL)
        {
            if(temp -> data == target) return target;
            else if(temp -> data > target) temp = temp -> left;
            else
            {
                ans = temp -> data;
                temp = temp -> right;
            }
        }
        return ans;
    }
};