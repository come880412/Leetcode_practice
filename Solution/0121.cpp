class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int buy, sell, price;
        int profit = 0;
        for(int i=0;i<prices.size();++i){
            price = prices[i];
            if(i == 0){
                buy = sell = price;
            }
            else{
                if(buy > price){
                    if((sell - buy) > profit)
                        profit = sell - buy;
                    sell = price;
                    buy = price;
                }
                else
                    if(sell < price)
                        sell = price;
            }
        }
        if((sell - buy) > profit)
            profit = sell - buy;
        
        return profit;
    }
};
