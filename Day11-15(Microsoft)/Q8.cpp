void connect(Node *root)
    {

       queue<Node *> q;
       q.push(root);

       while(!q.empty())
       {
           int s=q.size();
           while(s)
           {
               Node *t=q.front();
               q.pop();

               if(s==1)t->nextRight=NULL;
               else t->nextRight=q.front();

               if(t->left)q.push(t->left);
               if(t->right)q.push(t->right);

               s--;
           }
       }
    }
