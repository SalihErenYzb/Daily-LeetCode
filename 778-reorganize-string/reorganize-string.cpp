class Solution {
public:
    string reorganizeString(string s) {
        // for s with length 2n 
        // if a char has n+1 chars ""
        // if 2n+1 a char has n+2 char ""
        int arr[27] = {0};
        int maxF = 0;
        int k = 0;

        for (char c: s){
            int ind = c - 'a';
            arr[ind]++;
            if (arr[ind] > maxF){
                maxF = arr[ind];
                k = ind;
            }
        }
        if (s.size()%2 == 1 && maxF >= s.length()/2 + 2){
            return "";
        }else if (s.size()%2 == 0 && maxF >= s.length()/2 + 1 ){
            return "";
        }
        
        string s2(s.size(),' ');
        for (int i = 0; i < s.size(); i += 2){
            while (!arr[k]){
                k = (k+1)%27;
            }
            s2[i] = 'a'+k;
            arr[k]--;
        }
        for (int i = 1; i < s.size(); i += 2){
            while (!arr[k]){
                k = (k+1)%27;
            }
            s2[i] = 'a'+k;
            arr[k]--;
        }
        return s2;
    }
};