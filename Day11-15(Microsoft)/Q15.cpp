//using concept of topological sort
class graph{
    list<int> *l;
    public:

    graph(int v)
    {
        l=new list<int> [v];
    }


    void add_edge(int x,int y)//edge from x to y (directed)
    {
       l[x].push_back(y);
    }

    void dfs_helper(int i,bool *visited,stack<int> &s)
    {
        visited[i]=true;
        for(auto a:l[i])
        {
            if(visited[a]==false)
            dfs_helper(a,visited,s);
        }
        s.push(i);//pushing elements after recursive call
    }
    void dfs(string &str,int k)//topological sort using dfs
    {
        stack<int> s;//s will have elements topologically sorted

        bool visited[k];
        for(int i=0;i<k;i++)
        visited[i]=false;

        for(int i=0;i<k;i++)
        {
            if(visited[i]==false)
            dfs_helper(i,visited,s);
        }

        while(!s.empty())
        {
            int c=s.top();
            s.pop();
            str+='a'+c;
        }
    }

};
    string findOrder(string dict[], int N, int K) {
        //code here
        graph g(K);

        for(int i=0;i<N-1;i++)
        {         string word1=dict[i];
                  string word2=dict[i+1];
                  int l1=word1.length();
                  int l2=word2.length();
                  int c=0;
                  while(c<l1&&c<l2)
                  {
                      if(word1[c]!=word2[c])//making edges bw characters that do not match
                       {
                           int x=word1[c]-'a';
                           int y=word2[c]-'a';
                           g.add_edge(x,y);//sice word1 comes before word2 so we make an edge from x to y
                           break;
                       }
                       c++;
                  }
              }

       string str="";
        g.dfs(str,K);
       return str;

    }
