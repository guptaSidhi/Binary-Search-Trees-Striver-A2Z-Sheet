class Solution{
  public:
    Node * inOrderSuccessor(Node *root, Node *x)
    {
        Node* temp = root;
        Node* successor = NULL;
        while(temp != NULL)
        {
            if(temp -> data <= x -> data) temp = temp -> right;
            else
            {
                if(successor == NULL || temp -> data < successor -> data)
                    successor = temp;
                temp = temp -> left;
            }
        }
        return successor;
    }
};