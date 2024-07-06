int findCeil(Node* root, int target) {
    if (root == NULL) return -1;
    Node* temp = root;
    int ans = -1;
    while(temp != NULL)
    {
        if(temp -> data == target) return target;
        else if(temp -> data < target) temp = temp -> right;
        else
        {
            ans = temp -> data;
            temp = temp -> left;
        }
    }
    return ans;
}