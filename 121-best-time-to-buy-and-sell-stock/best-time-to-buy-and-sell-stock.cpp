class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int answer = 0;
        int minNum = INT_MAX;
        for (int price: prices){
            minNum = min(minNum,price);
            answer = max(answer,price-minNum);
        }
        return answer;
    }
};