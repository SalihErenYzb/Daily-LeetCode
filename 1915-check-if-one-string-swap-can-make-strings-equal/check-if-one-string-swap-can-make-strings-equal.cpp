class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        int count = 2;
        int mistake;
        for (int i = 0; i < s1.size(); i++){
            if (s1[i] != s2[i]){
                if (count == 1){
                    if (s1[mistake] != s2[i] || s1[i] != s2[mistake]){
                        return false;
                    }
                }
                mistake = i;
                count--;
            }
        }
        if (!count) return true;
        return count == 2;
    }
};