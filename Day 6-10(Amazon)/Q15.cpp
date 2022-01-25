void linkdelete(struct Node  *head, int M, int N)
    {
        //Add code here
        Node *t=head;
        while(t)
        {
            int i=1;
            Node *prev;
            while(i<=M&&t)
            {
                prev=t;
                t=t->next;
                i++;
            }

            i=1;
            while(i<=N&&t)
             {
                 Node *n=t->next;
                 prev->next=n;
                 t=n;
                 i++;
             }
        }
    }
