class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> mpS;
        unordered_map<char, int> mpT;
        
        for (const char& c: s) mpS[c]++;

        for (const char& c: t) mpT[c]++;

        return mpS == mpT;
    }
};
