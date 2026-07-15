class Solution {
public:
    int maxProfit(vector<int>& arr) {
          vector<long>ahead(2,0),cur(2,0);
          int n=arr.size();
   ahead[0]=ahead[1]=0;
   for(int ind=n-1;ind>=0;ind--){
    for(int buy=0;buy<=1;buy++){
        long profit=0;
        if(buy){
            profit=max(-arr[ind]+ahead[0],0+ahead[1]);
        }
        else{
            profit=max(arr[ind]+ahead[1],0+ahead[0]);
        }
        cur[buy]=profit;
    }
    ahead=cur;
   }
   return ahead[1];
    }
};