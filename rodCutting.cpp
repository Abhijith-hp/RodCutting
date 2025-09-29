

class Solution {
  public:
  
    int selections(int index,int n,vector<int>&price){
        
        if(index==0){
            return n * price[0];
        }
        
        int nonTake = 0+selections(index-1,n,price);
        int take = INT_MIN;
        int rodLength = index+1;
        if(rodLength<=n)
            take = price[index]+selections(index,n-rodLength,price);
        return max(take,nonTake);
    }
    int cutRod(vector<int> &price) {
        return selections(price.size()-1,price.size(),price);
        
    }
};