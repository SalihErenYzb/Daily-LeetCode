class Solution {
public:
    long long minEnd(int n, int x) {
        vector<long long> v;
        int tmp = x;
        long long k = 1;
        while (k < LLONG_MAX/3){
            if (tmp%2 == 0) v.push_back(k);
            k = k << 1;
            tmp = tmp >> 1;
        }
        reverse(begin(v),end(v));
        long long ans = x;
        n--;
        while (n){
            if (n%2) ans |= v.back();
            v.pop_back();
            n = n /2;
        }
        return ans;
    }
};