class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        for (int i = digits.size()-1; i >= 0; i--){
            digits[i] = ++digits[i] == 10 ? 0: digits[i];
            if (digits[i])
                break;
        }
        if (!digits[0])
            digits.insert(begin(digits),1);
        return digits;
    }
};