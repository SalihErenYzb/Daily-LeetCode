class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(begin(people),end(people));
        int n = people.size();
        int i = 0, j = n-1;
        int possibleAns = -1;
        // do binary search 
        // write checker func
        // should find the appropriate highest index
        while (j >= i){
            int mid = (i+j)/2;
            if (checker(people,mid,limit)){
                i = mid+1;
                possibleAns = mid;
            }else{
                j = mid -1;
            }
        }
        return (possibleAns+1)/2 + (possibleAns+1)%2 + n-possibleAns-1;
        
    }
    bool checker(vector<int>& people, int& mid, int& limit){
        for (int i = 0; i < (mid+1)/2; i++){
            if (people[i] + people[mid-i] > limit){
                return false;
            }
        }
        return true;
    }
};