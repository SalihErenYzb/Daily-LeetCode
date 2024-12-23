class Solution {
public:
    int addDigits(int num) {
        int tmp = num%9;
        if (!tmp && num) return 9;
        return tmp;
    }
};