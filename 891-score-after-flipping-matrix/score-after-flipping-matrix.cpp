class Solution {
public:
    int matrixScore(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<bool> t(m,false);
        int tmp = (1<<(n-1));
        cout << tmp << "\n";
        int sum = tmp * m;
        int ans = tmp * m;
        for (int i = 0; i < m; i++)
            t[i] = ~grid[i][0] + 2; 
        // just reverse t and it will be aplicable for the other possiblity
        for (int i = 1; i < n; i++){
            int c = 0;
            for (int j = 0; j < m; j++)
                c += grid[j][i]^t[j];
            c = max(c,m-c);
            tmp = tmp >> 1;
            sum += tmp*c;
        }
        tmp = (1<<(n-1));
        for (int i = 0; i < m; i++)
            t[i] = t[i]^true;
        for (int i = 1; i < n; i++){
            int c = 0;
            for (int j = 0; j < m; j++)
                c += grid[j][i]^t[j];
            c = max(c,m-c);
            tmp = tmp >> 1;
            ans += tmp*c;
        }
        return max(ans,sum);

    }
};