string binary(int n)
{
    string s="";

    while(n)
    {
        int r=n%2;
        char c=48+r;
        s=c+s;
        n=n/2;
    }
    return s;
}
vector<string> generate(int N)
{
	// Your code here
	vector<string> ans;
	for(int i=1;i<=N;i++)
	{
	    ans.push_back(binary(i));
	}
	return ans;

}
