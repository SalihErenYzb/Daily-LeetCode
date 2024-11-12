#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        sort(items.begin(), items.end());
        for (int i = 1; i < items.size(); ++i) {
            items[i][1] = max(items[i][1], items[i - 1][1]);
        }

        vector<int> ans;
        for (int q : queries) {
            auto it = upper_bound(items.begin(), items.end(), vector<int>{q, INT_MAX});
            if (it == items.begin()) {
                ans.push_back(0);
                continue;}
            ans.push_back((it - 1)->at(1)); 
        }
        return ans;
    }
};
