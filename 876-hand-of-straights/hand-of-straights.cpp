class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        map<int,int> a;
        for (int i: hand)
            a[i]++;
        for (auto& [card,freq]: a){
            if (freq > 0) {
                for (int i = groupSize - 1; i >= 0; i--) {
                    a[card + i] -= freq;
                    if (a[card + i] < 0) {
                        return false;
                    }
                }
            }
        }
        return true;
        
    }
};