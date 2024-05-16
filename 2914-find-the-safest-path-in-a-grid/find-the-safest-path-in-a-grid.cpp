class Solution {
public:
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> costs(n,vector<int>(n,0));
        queue<pair<int,int>> qu;

        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                if (grid[i][j]){
                    qu.push({i,j});
                    grid[i][j] = 0;
                }
                    

        int k = 0;
        while (!qu.empty()){
            int sz = qu.size();
            for (int i = 0; i < sz; i++){
                pair coord = qu.front();
                //cout << "coord: " << coord.first << " " << coord.second << "\n";
                //cout << "ADDED TO THIS ARE: " << "\n";
                qu.pop();
                if (grid[coord.first][coord.second] == 1){
                    continue;
                }
                costs[coord.first][coord.second] = k;
                grid[coord.first][coord.second] = 1;
                coord.first++;
                if (coord.first < n && grid[coord.first][coord.second] == 0)
                    qu.push(coord);
                //cout << "coord: " << coord.first << " " << coord.second << "\n";
                coord.first -= 2;
                if (coord.first >= 0 && grid[coord.first][coord.second] == 0)
                    qu.push(coord);
                //cout << "coord: " << coord.first << " " << coord.second << "\n";
                coord.first++;
                coord.second++;
                if (coord.second < n && grid[coord.first][coord.second] == 0)
                    qu.push(coord);
                //cout << "coord: " << coord.first << " " << coord.second << "\n";
                coord.second -= 2;
                if (coord.second >= 0 && grid[coord.first][coord.second] == 0)
                    qu.push(coord);
                //cout << "coord: " << coord.first << " " << coord.second << "\n";
            }

            k++;
        }
        int minCost = 1e8;
        priority_queue<tuple<int,int,int>> pq;
        pq.push({costs[0][0],0,0});
        while (true){
            tuple<int,int,int> tp = pq.top();
            pq.pop();
            if (grid[get<1>(tp)][get<2>(tp)] == 0){
                continue;
            }
            grid[get<1>(tp)][get<2>(tp)] = 0;
            minCost = min(minCost,get<0>(tp));
            if (get<0>(tp) == 0){
                return 0;
            }
            if (get<1>(tp) == n-1 && get<2>(tp) == n-1){
                return minCost;
            }
            if (get<1>(tp)+1 < n && grid[get<1>(tp)+1][get<2>(tp)])
                pq.push({costs[get<1>(tp)+1][get<2>(tp)],get<1>(tp)+1,get<2>(tp)});

            if (get<1>(tp)-1 >= 0 && grid[get<1>(tp)-1][get<2>(tp)])
                pq.push({costs[get<1>(tp)-1][get<2>(tp)],get<1>(tp)-1,get<2>(tp)});

            if (get<2>(tp)+1 < n && grid[get<1>(tp)][get<2>(tp)+1])
                pq.push({costs[get<1>(tp)][get<2>(tp)+1],get<1>(tp),get<2>(tp)+1});

            if (get<2>(tp)-1 >= 0 && grid[get<1>(tp)][get<2>(tp)-1])
                pq.push({costs[get<1>(tp)][get<2>(tp)-1],get<1>(tp),get<2>(tp)-1});
            }



        return -1;


    }
};