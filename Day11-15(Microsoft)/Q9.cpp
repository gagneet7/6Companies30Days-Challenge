int inorder(Node *root,int x,int &ans)
{
    if(root==NULL)return 0;

    int l=inorder(root->left,x,ans);
    int r=inorder(root->right,x,ans);
    int sum=l+r+root->data;
    if(sum==x)ans++;
    return sum;
}
int countSubtreesWithSumX(Node* root, int X)
{
	// Code here
	int ans=0;
	inorder(root,X,ans);
	return ans;
}
