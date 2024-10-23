class Solution {
public:
    int reverse(int x) {
        long long ans = 0;
        long long con = 1000000000;
        bool flag = false;
        if (x < 0) {
            flag = true;
        }
        x = abs(x);
        while (x > 0){
            ans += con*(x%10);
            x /= 10;
            con /= 10;
        }
        while (ans%10 == 0 && ans != 0){
            ans /= 10;
        }
        if (flag) ans = -ans;
        if (ans > INT_MAX || ans < INT_MIN) return 0;
        return ans;
    }
};