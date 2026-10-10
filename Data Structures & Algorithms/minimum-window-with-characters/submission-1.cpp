class Solution {
public:
    string minWindow(string s, string t) {
        if (t.size() > s.size()) return "";

        pair<int, int> res = {-1, -1};
        int minWindow = INT_MAX;
        unordered_map<char, int> mpS, mpT;
        for (const char& c: t) mpT[c]++;

        int have = 0, need = mpT.size(), l = 0;
        for (int r = 0; r < s.size(); r++) {
            mpS[s[r]]++;

            if (mpS[s[r]] == mpT[s[r]]) have++;
            while (have == need) {
                if ((r - l + 1) < minWindow) {
                    minWindow = r - l + 1;
                    res = {l, r};
                }
                mpS[s[l]]--;
                if (mpT.count(s[l]) && mpS[s[l]] < mpT[s[l]]) {
                    have--;
                }
                l++;
            }
        }

        return minWindow == INT_MAX ? "" : s.substr(res.first, minWindow); 
    }
};
