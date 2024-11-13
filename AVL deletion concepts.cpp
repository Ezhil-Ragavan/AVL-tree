BinaryNode* minimum(BinaryNode* root) 
{
    if (root->left == NULL)
    {
        return root;
    } 
    else 
    {
        return minimum(root->left);
    }
}
BinaryNode* deleteNode(BinaryNode* root, int data) 
{
    if (root == NULL) {
        cout << "Value not found in BST";
        return NULL;
    }

    if (data < root->key)
    {
        root->left = deleteNode(root->left, data);
    }
    else if (data > root->key)
    {
        root->right = deleteNode(root->right, data);
    } else
    {
        if (root->left != NULL && root->right != NULL)
        {
            BinaryNode* temp = root;
            BinaryNode* minNodeForRight = minimum(temp->right);
            root->key = minNodeForRight->key;
            root->right = deleteNode(root->right, minNodeForRight->key);
        } 
        else if (root->left != NULL) 
        {
            root = root->left;
        }
        else if (root->right != NULL)
        {
            root = root->right;
        } 
        else 
        {
            root = NULL;
        }
    }

    if (root == NULL) return root;

    root->height = 1 + max(getHeight(root->left), getHeight(root->right));
    int balance = getBalance(root);

    if (balance > 1 && getBalance(root->left) >= 0) 
    {
        return rotateRight(root);
    }

    if (balance > 1 && getBalance(root->left) < 0)
    {
        root->left = rotateLeft(root->left);
        return rotateRight(root);
    }

    if (balance < -1 && getBalance(root->right) <= 0) 
    {
        return rotateLeft(root);
    }

    if (balance < -1 && getBalance(root->right) > 0)
    {
        root->right = rotateRight(root->right);
        return rotateLeft(root);
    }

    return root;
}
