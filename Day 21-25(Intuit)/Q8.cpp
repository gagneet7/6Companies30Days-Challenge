int numberOfBoomerangs(vector<vector<int>>& points) {

    int ans = 0, n = points.size();

    for(int i=0;i<n;i++)
    {
        unordered_map<int,int>mp;
        for(int j=0;j<n;j++)
        {
            if(i==j)continue;
            int dx = points[i][0] - points[j][0];
            int dy = points[i][1] - points[j][1];
            int dis = dx*dx + dy*dy;
            mp[dis]++;
        }

        for(auto a:mp)
            if(a.second>1)ans += a.second*(a.second-1); //selecting 2 points from all group of points with dist a.first
    }
    return ans;
    }
