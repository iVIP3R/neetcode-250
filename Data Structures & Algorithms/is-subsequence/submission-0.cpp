class Solution {
public:
    bool isSubsequence(string s, string t) {

        int j = 0;
        for (int i = 0; i < s.size(); i++) {
            bool flag = 0;
            while (j < t.size() && s.size() - (i + 1) <= t.size() - (j + 1)) {
                if (t[j] == s[i]) flag = 1, i++;
                else flag = 0;
                j++;
            }
            if (!flag) return 0;
        }

        return 1;
    }
};