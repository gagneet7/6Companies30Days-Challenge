void preorder(Node *root,vector<int> &v)
    {
        if(root==NULL)
        {
            v.push_back(-1);
            return;
        }
        v.push_back(root->data);

        preorder(root->left,v);
        preorder(root->right,v);
    }
    vector<int> serialize(Node *root)
    {
        //Your code here
        vector<int> v;
        preorder(root,v);
        return v;

    }

    //Function to deserialize a list and construct the tree.
    Node * maketree(vector<int> &A,int &i)
    {
        Node *root=new Node(A[i]);

        i++;
        if(A[i]!=-1)root->left=maketree(A,i);
        i++;
        if(A[i]!=-1)root->right=maketree(A,i);
        return root;
    }

    Node * deSerialize(vector<int> &A)
    {
       //Your code here
       int i=0;
       return maketree(A,i);
    }
