

class Solution {
  public:
  
    int selections(int index,int n,vector<int>&price,vector<vector<int>>&dp){
        
        if(index==0){
            return n * price[0];
        }
        if (dp[index][n]!=-1) return dp[index][n];
        
        int nonTake = 0+selections(index-1,n,price,dp);
        int take = INT_MIN;
        int rodLength = index+1;
        if(rodLength<=n)
            take = price[index]+selections(index,n-rodLength,price,dp);
        dp[index][n] = max(take,nonTake);
        return dp[index][n];
    }
    int cutRod(vector<int> &price) {
        int size = price.size();
        vector<vector<int>>dp(size,vector<int>(size+1,-1));
        return selections(price.size()-1,price.size(),price,dp);
        
    }
};