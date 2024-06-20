class Solution {
public:
    int maxDistance(vector<int>& position, int m) {
        // mid will be the minumum distance between adjacent balls
        // if we can fit m balls with minumum mid distance it means
        // we can elongate the distance 
        // if not deacrese the distance
        sort(begin(position),end(position));
        int n = position.size();
        int low = 1;
        int high = position[n-1];
        int ans = -1;
        while (low <= high){
            int cnt = 1;
            int mid = (low+high)/2;
            int curr = position[0];
            for (int i = 1; i < n; i++){
                if (position[i] - curr >= mid){
                    cnt++;
                    curr = position[i];
                    if (cnt == m){
                        ans = mid;
                        low = mid + 1;
                        break;
                    }
                }
            }
            if (low != mid + 1)
                high = mid - 1;
        }
        return ans;
    }
};