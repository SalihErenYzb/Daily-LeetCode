class Solution {
public:
    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {
        if (n == 1){
            return (values[0]%k == 0);
        }
        vector<vector<int>> edg(n,vector<int>());
        vector<int> deegres(n,0);
        for (auto edge: edges){
            edg[edge[1]].push_back(edge[0]);
            edg[edge[0]].push_back(edge[1]);
            deegres[edge[0]]++;
            deegres[edge[1]]++;
        }
        queue<int> que;
        for (int i = 0; i < n; i++){
            if (deegres[i] == 1){
                que.push(i);
            }
        }
        int ans = 0;
        while (!que.empty()){
            int front = que.front();
            que.pop();
            if (deegres[front] == -1) continue;
            deegres[front] = -1;
            if (values[front]%k == 0){
                ans++;
            }
            cout << front << " " << values[front] << " " << ans << "\n";

            for (auto el: edg[front]){
                deegres[el]--;
                if (deegres[el] >= 0){
                    values[el] = (values[el] + values[front])%k;
                }
                if (deegres[el] == 1) {
                    que.push(el);
                    
                }
            }
        }
        return ans;
    }
};