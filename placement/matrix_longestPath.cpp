class Solution {
public:
    bool isSafe(int i, int j, int m, int n, 
                 vector<vector<int>>& matrix, int prev) {
        return i >= 0 && j >= 0 && i < m && j < n  &&
               matrix[i][j] > prev;
    }
    int solve(int i, int j, int m, int n, vector<vector<int>>& matrix,
              int prev, vector<vector<int>>& dp) {

        int maxi = 1;
       

        if(dp[i][j] != -1){
            return dp[i][j];
        }
        // Right
        int ni = i + 0;
        int nj = j + 1;
        if (isSafe(ni, nj, m, n, matrix, prev)) {
            
            maxi = max(maxi ,1 + solve(ni, nj, m, n, matrix, matrix[ni][nj], dp));
            
        }

        // Down
        ni = i + 1;
        nj = j + 0;
        if (isSafe(ni, nj, m, n, matrix, prev)) {
            
            maxi = max(maxi ,1 +solve(ni, nj, m, n, matrix, matrix[ni][nj], dp));
            
        }

        // Left
        ni = i + 0;
        nj = j - 1;
        if (isSafe(ni, nj, m, n, matrix, prev)) {
            
            maxi = max(maxi ,1 +solve(ni, nj, m, n, matrix, matrix[ni][nj], dp));
            
        }

        // Up
        ni = i - 1;
        nj = j + 0;
        if (isSafe(ni, nj, m, n, matrix, prev)) {
            
            maxi = max(maxi ,1 +solve(ni, nj, m, n, matrix, matrix[ni][nj], dp));
            
        }

        

        
        return dp[i][j] = maxi;
        
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        int ans =0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                ans = max(ans, solve(i, j, m, n, matrix, matrix[i][j],  dp));
            }
        }
return ans;
       
    }
};