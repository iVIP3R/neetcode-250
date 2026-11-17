class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.size() > s2.size()) return false;

        vector<int> mp1(26, 0), mp2(26, 0);
        for (char c : s1) {
            mp1[c - 'a']++;
        }

        int l = 0;
        for (int r = 0; r < s2.size(); r++) {
            mp2[s2[r] - 'a']++;
            
            if (r - l + 1 == s1.size()) {
                if (mp1 == mp2) return true;
                mp2[s2[l++] - 'a']--;
            }
        }
        return false;
    }
};
