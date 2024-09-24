class Solution {
public:
    static bool compare(vector<int> a, vector<int> b){
        if (a[0] != b[0]) return a[0] < b[0];
        return a[1] < b[1];
    }
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(begin(intervals),end(intervals),compare);
        vector<vector<int>> answer;
        for (int i = 0; i < intervals.size()-1; i++){
            vector<int>& first = intervals[i];
            vector<int>& second = intervals[i+1];
            if (first[1] >= second[0]){
                second[0] = first[0];
                second[1] = max(first[1],second[1]);
            }else{
                answer.push_back(intervals[i]);
            }
        }
        answer.push_back(intervals[intervals.size()-1]);
        return answer;
    }
};