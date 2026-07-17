class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit=0;
        int minprice=prices[0];
        for(int& sell:prices){
            profit=max(profit,sell-minprice);
            minprice=min(minprice,sell);
        }
        return profit;
    }
};