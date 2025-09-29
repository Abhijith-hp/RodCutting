

class Solution {
  public:
  
    int cutRod(vector<int> &price) {
        int size = price.size();
        vector<vector<int>>dp(size,vector<int>(size+1,-1));
        for(int i=0;i<=size;i++)
            dp[0][i] = i*price[0];
        for(int i=1;i<size;i++){
            for(int j=0;j<=size;j++){
        int nonTake = 0+dp[i-1][j];
        int take = INT_MIN;
        int rodLength = i+1;
        if(rodLength<=j)
            take = price[i]+dp[i][j-rodLength];
        dp[i][j] = max(take,nonTake); 
            }
        }
        return dp[size-1][size];
        
    }
};