#pragma GCC optimize("Ofast","inline","fast-math","unroll-loops","no-stack-protector","-ffast-math")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native","f16c")
static const bool Booster = [](){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return true;
}();

inline bool is_digit_or_negative(char c) {
    return (c >= '0' && c <= '9') || (c == '-');
}

std::vector<int> parse_input_data_string(const std::string& s) {
    std::vector<int> input_data_1D;
    const int N = s.size();
    int left = 0;
    while (left < N) {
        if (!is_digit_or_negative(s[left])) {
            ++left;
            continue;
        }
        int right = left;
        long long value = 0;
        int is_negative = 1;
        while (right < N && is_digit_or_negative(s[right])) {
            if (s[right] == '-') {
                is_negative = -1;
            } else {
                value = value * 10 + (s[right] - '0');
            }
            ++right;
        }
        value *= is_negative;
        input_data_1D.push_back(value);
        left = right;
    }
    return input_data_1D;
}

int numSubarrayProductLessThanK(std::vector<int>& nums, int k) {
    const int N = nums.size();
    if (k <= 1) {
        return 0;
    }
    int counter = 0;
    int product = 1;
    int l = 0;
    int r = 0;
    while (r < N) {
        product *= nums[r];
        while (l <= r && product >= k) {
            product /= nums[l];
            ++l;
        }
        counter += r - l + 1;
        ++r;
    }
    return counter;
}

bool Solve = [](){
    std::ofstream out("user.out");
    for (std::string s; std::getline(std::cin, s);) {
        std::vector<int> input_data = parse_input_data_string(s);
        std::getline(std::cin, s);
        const int k = std::stoi(s);
        out << numSubarrayProductLessThanK(input_data, k) << "\n";
    }
    out.flush();
    exit(0);
    return true;
}();

class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int product = 1;
        int ans = 0;
        int i = 0;
        for (int j = 0; j < nums.size(); j++){
            product *= nums[j];
            while (product >= k && j+1 > i){
                product = product / nums[i++];
            }
            ans += j-i+1;
        }
        return ans;
    }
};