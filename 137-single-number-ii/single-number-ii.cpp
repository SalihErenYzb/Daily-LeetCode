class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int a = 0; // defines the first bit of number of xth bit % 3
        int b = 0; // defines the second bit of number of xth bit % 3
        int tmp;
        int tmp1;
        int tmp2;
        for (int num: nums) {
            // need 3 states, that counts number of ones%3
            // ai = 0, bi = 0 first
            // ai = 1, bi = 0 second
            // ai = 1, bi = 1 third
            tmp = (~a)&(~b)&num;
            tmp1 = a & b & num;
            tmp1 = ~tmp1;
            tmp2 = a&(~b)&num;
            b |= tmp2;
            a |= tmp;
            a &= tmp1;
            b &= tmp1;
            //cout << a << " " << b << "\n";
        }
        return a;
    }
};