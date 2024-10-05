class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int arr[26] = {0};
        int arr2[26] = {0};
        for (char c: s1){
            arr[c-'a']++;
        }
        int matches = 0;
        for (int i: arr){
            if (!i) matches++;
        }
        int length = 0;
        for (int r = 0; r < s2.size(); r++){
            length++;
            arr2[s2[r]-'a']++;
            if (arr2[s2[r]-'a'] == arr[s2[r]-'a']){
                matches++;
            }
            while (arr2[s2[r]-'a'] > arr[s2[r]-'a']){
                if (arr2[s2[r - length +1]-'a']-- == arr[s2[r-length+1]-'a']){
                    matches--;
                }
                length--;
            }
            if (matches == 26){
                return true;
            }
        }
        return false;
    }
};