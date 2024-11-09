class Solution {
public:
    long long minEnd(int n, int x) {
        long long tmp_num = x; n--;
        int cnt = 0;
        for(int i=0;i<64;i++){
            if((1LL << i) & x) continue;
            tmp_num += ((1LL << cnt) & n) ? (1LL << i) : 0;
            cnt++;
        }
        return tmp_num;
    }
};