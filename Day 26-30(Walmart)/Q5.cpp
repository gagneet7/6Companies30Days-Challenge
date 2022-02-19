int convert(Node *node)
    {
        if(node==NULL)return 0;

        int left=convert(node->left);
        int right=convert(node->right);

        int d=node->data;
        node->data=left+right;
        return left+right+d;
    }
    void toSumTree(Node *node)
    {
        // Your code here
        convert(node);
    }
