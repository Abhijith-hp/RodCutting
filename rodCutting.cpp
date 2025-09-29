// User function Template for C++

class Solution {
  public:
  
    int cutRod(vector<int> &price) {
        int size = price.size();
        vector<vector<int>>dp(size,vector<int>(size+1,-1));
        vector<int>prev(size+1,0);
        vector<int>curr(size+1,0);
        for(int i=0;i<=size;i++)
            prev[i] = i*price[0];
        for(int i=1;i<size;i++){
            for(int j=0;j<=size;j++){
        int nonTake = 0+prev[j];
        int take = INT_MIN;
        int rodLength = i+1;
        if(rodLength<=j)
            take = price[i]+curr[j-rodLength];
        curr[j] = max(take,nonTake); 
            }
            prev=curr;
        }
        return prev[size];
        
    }
};