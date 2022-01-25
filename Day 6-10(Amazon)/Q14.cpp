pair<int,int> solution(Node *root,int target,int &ans)
    {
        if(!root)
        return {0,0};

        pair<int,int> t1=solution(root->left,target,ans);
        pair<int,int> t2=solution(root->right,target,ans);


        if(root->data==target)
        {
            int h=1+max(t1.first,t2.first);
            ans=max(ans,h-1);

            return {h,1};
        }
        if(t1.second)
        {
            ans=max(ans,t1.second+t2.first);
            return {1+max(t1.first,t2.first),t1.second+1};
        }
        if(t2.second)
        {
            ans=max(ans,t2.second+t1.first);
            return {1+max(t2.first,t1.first),t2.second+1};
        }

        return {1+max(t1.first,t2.first),0};

    }
    int minTime(Node* root, int target)
    {
        // Your code goes here
        int ans=INT_MIN;

        solution(root,target,ans);

        return ans;
    }
