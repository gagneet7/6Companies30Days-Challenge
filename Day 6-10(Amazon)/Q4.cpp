string putbrackets(int i,int j,vector<vector<int>> &b){

        if(i==j){
            string s = "";
            return s + char('A'+i-1);
        }

        int k = b[i][j];

        return '(' + putbrackets(i,k,b) + putbrackets(k+1,j,b) + ')';

    }

    string matrixChainOrder(int p[], int n){
        // code here
    int m[n][n];
    vector<vector<int>> b(n,vector<int>(n,0));

    for (int i = 1; i < n; i++)
        m[i][i] = 0;

    for (int L = 2; L < n; L++)
    {
        for (int i = 1; i < n - L + 1; i++)
        {
            int j = i + L - 1;
            m[i][j] = INT_MAX;
            for (int k = i; k <= j - 1; k++)
            {

                int q = m[i][k] + m[k + 1][j]
                        + p[i - 1] * p[k] * p[j];
                if (q < m[i][j])
                {
                    m[i][j] = q;
                    b[i][j] = k;
                }
            }
        }
    }

    return putbrackets(1,n-1,b);
    }
