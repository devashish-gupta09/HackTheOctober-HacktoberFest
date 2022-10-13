class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        
        int r = grid.size();
        int c = grid[0].size();
        
        vector<vector<vector<int>>> dp(r,vector<vector<int>>(c,vector<int>(c,0)));
        
      for(int i = 0; i < c; i++)
      {
          for(int j = 0; j < c; j++)
          {
              if(i == j)dp[r-1][i][j] = grid[r-1][i];
              else dp[r-1][i][j] = grid[r-1][i] + grid[r-1][j];
          }
      } 
        
        
        for(int i = r-2; i >= 0; i--)
        {
            for(int j1 = 0; j1 < c; j1++)
            {
                for(int j2 = 0; j2< c; j2++)
                {
                     int maxi = -1e8;
        for(int dj1 = -1; dj1 <= 1; dj1++)
        {
            for(int dj2 = -1; dj2 <= 1; dj2++)
            {
                int value = 0;
                if(j1 == j2) value = grid[i][j1];
                else value = grid[i][j1] + grid[i][j2];
                if(j1+dj1 >= 0 && j1+dj1 < c && j2+dj2 >= 0 && j2+dj2 < c)
                value+= dp[i+1][j1+dj1][j2+dj2];
                else value+= -1e8;
                
                maxi = max(maxi,value);
                
            }
        }
                    dp[i][j1][j2] = maxi;
                }
            }
        }
        
        return dp[0][0][c-1];
    }
};

