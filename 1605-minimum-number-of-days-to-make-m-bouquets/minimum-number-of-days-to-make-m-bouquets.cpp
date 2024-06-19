class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        int low = 0;
        int high = 1e9;
        int n = bloomDay.size();
        int ans = -1;
        while (low <= high){
            //cout << low << " " << high << "\n";
            int mid = (high+low)/2;
            int cnt = 0;
            int i = 0;
            int blCnt = 0;
            while (i < n){
                if (bloomDay[i] <= mid)
                   blCnt++;
                else
                    blCnt = 0;
                if (blCnt == k){
                    cnt++;
                    blCnt = 0;
                }
                if (cnt == m)
                    break;
                i++;
            }
            if (cnt == m){
                ans = mid;
                high = mid -1;
            }else
                low = mid+1;
        }
        return ans;
        
    }
};