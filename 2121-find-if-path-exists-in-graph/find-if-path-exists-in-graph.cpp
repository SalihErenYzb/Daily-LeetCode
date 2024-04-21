class Solution {
public:
    vector<int> parents;
    vector<int> heights;
    void init1(int n){
        for (int i = 0; i < n; i++)
            parents.push_back(i);
        heights.resize(n,1);
    }
    int parent(int x){
        if (x == parents[x]) 
            return x;
        return  parents[x] = parent(parents[x]);
    }
    bool areSame(int x, int y){
        return parent(x) == parent(y);
    }
    void connect(int x, int y){
        int px = parent(x);
        int py = parent(y);
        if (px == py)
            return;
        if (heights[px] < heights[py]){
            parents[px] = py;
            heights[px] += heights[py];
        }else{
            parents[py] = px;
            heights[py] += heights[px];
        }

    }
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        init1(n);
        for (auto edge: edges){
            connect(edge[0],edge[1]);

        }
        return(areSame(source,destination));
    }
};