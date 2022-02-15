 vector<vector<int>> pacificAtlantic(vector<vector<int>>& matrix) {

        vector<vector<int>> r;
        int m = matrix.size();
        int n = matrix[0].size();

        vector<vector<bool>> pacific(m, vector<bool>(n)); //if pacific[i][j]==true this means water can reach to pacific frm i,j
        vector<vector<bool>> atlantic(m, vector<bool>(n));

        //we will start dfs from boundary points and dfs is done for one ocean at a time
        for (int i = 0; i < m; i++)
        {
            dfs(matrix, pacific, i, 0);//from this pos ,water will surely reach to pacific as these are on left side
            dfs(matrix, atlantic, i, n-1);//from this pos ,water will surely reach to atlantic ,these are on right side
        }

        for (int j = 0; j < n; j++)
        {
            dfs(matrix, pacific, 0, j);//upper side
            dfs(matrix, atlantic, m-1, j);//lower side
        }

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (pacific[i][j] && atlantic[i][j])//if water can reach both oceans from this pos
                {
                    vector<int> v{i,j};
                    r.push_back(v);
                }
            }
        }
        return r;
    }

    void dfs(vector<vector<int>>& matrix, vector<vector<bool>>& visited, int i, int j) {
        int m = matrix.size();
        int n = matrix[0].size();

        visited[i][j] = true;

        //from curr pos we will try to go to that pos which have height >= height of curr pos
        //this is bcs if water can reach to ocean from this pos and next pos height is more than curr pos
        //then water can reach from next pos to curr pos and then to ocean;

        //up
        if (i-1 >= 0 && visited[i-1][j] != true && matrix[i-1][j]>=matrix[i][j])
            dfs(matrix, visited, i-1, j);
        //down
        if (i+1 < m && visited[i+1][j] != true && matrix[i+1][j]>=matrix[i][j])
            dfs(matrix, visited, i+1, j);
        //left
        if (j-1 >= 0 && visited[i][j-1] != true && matrix[i][j-1]>=matrix[i][j])
            dfs(matrix, visited, i, j-1);
        //right
        if (j+1 <n && visited[i][j+1] != true && matrix[i][j+1]>=matrix[i][j])
            dfs(matrix, visited, i, j+1);

    }
