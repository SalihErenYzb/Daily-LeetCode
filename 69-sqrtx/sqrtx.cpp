class Solution {
public:
    int mySqrt(int x) {
        int low = 0;
        int high = 46340;
        int ans = 0;
        while (high >= low){
            ans = (low + high)/2;
            if (ans*ans > x){
                high = ans-1;
            }else if (ans*ans < x){
                low = ans+1;
            }else{
                return ans;
            }
        }
        if (ans*ans > x) ans--;
        return ans;
    }
};