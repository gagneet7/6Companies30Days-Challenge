 vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {

        int n=numCourses;
        list<int> *l;
        l=new list<int>[n];

        for(int i=0;i<prerequisites.size();i++)
        {
           l[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }

        vector<int>result;
        map<int,int> indegree;

        for(int i=0;i<n;i++)
        {
         for(int nbr:l[i])
           indegree[nbr]++;
        }

        queue<int> q;
        for(int i=0;i<n;i++)
         {
           if(indegree[i]==0)q.push(i);
         }

        while(!q.empty())
         {
           int node=q.front();
           q.pop();
           result.push_back(node);

           for(int nbr:l[node])
           {
             indegree[nbr]--;
             if(indegree[nbr]==0)q.push(nbr);
           }
         }

        if(result.size()!=numCourses)return vector<int>();
         return result;
    }
