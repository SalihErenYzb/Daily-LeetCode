class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        unordered_set<string> dead(begin(deadends), end(deadends));
        if (dead.find("0000") != dead.end()) return -1;
        dead.insert({"0000"});
        if(target == "0000") return 0; // if start string itself is the target string.
        queue<string> q({"0000"});
        int n, minTurns = 0;
        while(!q.empty()) {            
            n = size(q), minTurns++;
            for(int i = 0; i < n; i++) { // traversing all nodes on the current level of BFS traversal
                auto cur_str = q.front(); q.pop();       
                for(int j = 0; j < 4; j++) 
                    for(auto adj_str : turn(cur_str, j)) 
                        if(dead.find(adj_str) == end(dead)) // adjacent (turned) string is not visited earlier, nor a dead end
                            if(adj_str == target) return minTurns;
                            else q.push(adj_str), dead.insert(adj_str);
            }
        }
        return -1;
    }
    vector<string> turn(string s, int i) {
        vector<string> res(2, s);
        res[0][i] = '0' + (res[0][i] - '0' + 1) % 10;        // forward turn
        res[1][i] = '0' + (res[1][i] - '0' - 1 + 10) % 10;   // backward turn
        return res;
    }
};