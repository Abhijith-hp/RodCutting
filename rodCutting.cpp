
class Solution {
  public:
  
    int cutRod(vector<int> &price) {
        int size = price.size();
        vector<vector<int>>dp(size,vector<int>(size+1,-1));
        vector<int>prev(size+1,0);
       
        for(int i=0;i<=size;i++)
            prev[i] = i*price[0];
        for(int i=1;i<size;i++){
            for(int j=0;j<=size;j++){
        int nonTake = 0+prev[j];
        int take = INT_MIN;
        int rodLength = i+1;
        if(rodLength<=j)
            take = price[i]+prev[j-rodLength];
         prev[j] = max(take,nonTake); 
            }
       
        }
        return prev[size];
        
    }
};