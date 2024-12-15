class Solution {
public:


double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
    double ans = 0;

    // Custom comparator: smallest (y - x) / (y^2 + y)
    auto cmp = [](const vector<int>& a, const vector<int>& b) {
        double deltaA = (a[1] - a[0]) / (((double)a[1]) * a[1] + a[1]);
        double deltaB = (b[1] - b[0]) / (((double)b[1]) * b[1] + b[1]);
        return deltaA < deltaB; 
    };

    priority_queue<vector<int>, vector<vector<int>>, decltype(cmp)> pq(cmp);

    for (const auto& cls : classes) {
        pq.push(cls);
    }
    int tmp = extraStudents;
    while (extraStudents > 0) {
        auto cls = pq.top();
        pq.pop();

        int x = cls[0], y = cls[1];
        x++;
        y++;

        pq.push({x, y}); // Recalculate and reinsert
        --extraStudents;
    }

    // Calculate the final answer
    while (!pq.empty()) {
        auto cls = pq.top();
        pq.pop();

        ans += (double)cls[0] / cls[1];
    }
    ans /= classes.size();
    return ans;
}

};