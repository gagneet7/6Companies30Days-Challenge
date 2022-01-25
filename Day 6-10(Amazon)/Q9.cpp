int isValid(vector<vector<int>> mat){
        // code here
      for(int i=0;i<9;i++)//each row
      {
          int f[10]={0};

          for(int j=0;j<9;j++)
          {
              if(mat[i][j]==0)continue;
              if(f[mat[i][j]]>=1)return 0;
              f[mat[i][j]]++;
          }
      }

      for(int i=0;i<9;i++)//each column
      {
          int f[10]={0};

          for(int j=0;j<9;j++)
          {
              if(mat[j][i]==0)continue;
              if(f[mat[j][i]]>=1)return 0;
              f[mat[j][i]]++;
          }
      }

      int n=9;
      for(int i=0;i<n-2;i+=3)
      {
          for(int j=0;j<n-2;j+=3)
          {
              int f[10]={0};
              for(int k=0;k<3;k++)
              {
                  for(int l=0;l<3;l++)
                  {
                      if(mat[i+k][j+l]==0)continue;
                      if(f[mat[i+k][j+l]]>=1)return 0;
                      f[mat[i+k][j+l]]++;
                  }
              }
          }
      }
      return 1;


    }
