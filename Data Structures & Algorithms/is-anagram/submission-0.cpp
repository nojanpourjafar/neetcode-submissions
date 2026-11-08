class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> countS;
        unordered_map<char, int> countT;       
        for(int i = 0; i < s.size (); i++){
            countS[s[i]]++;
        }

        for(int j = 0; j < t.size (); j++){
            countT[t[j]]++;
        }

    return(countS == countT);
    }
};
