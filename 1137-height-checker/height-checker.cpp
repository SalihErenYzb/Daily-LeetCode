class Solution {
public:
    int heightChecker(vector<int>& heights) {
        vector<int> sorte(begin(heights),end(heights));
        sort(begin(sorte),end(sorte));
        int ans = 0;
        for (int i = 0; i < sorte.size(); i++)
            if (sorte[i] != heights[i])
                ans++;
        return ans;
    }
};