class Solution {
public:
    int passThePillow(int n, int time) {
        int ans = time%(2*n-2);
        if (ans >= n)
            ans = n - 1 - (ans - n + 1);
        return ans+1;
    }
};