class Solution {
public:
    int addDigits(int num) {
        int tmp;
        while (num > 9){
            tmp = 0;
            while (num != 0){
                tmp += num%10;
                num /= 10;
            }
            num = tmp;
        }
        return num;
    }
};