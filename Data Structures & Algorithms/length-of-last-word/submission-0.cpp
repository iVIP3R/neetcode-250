class Solution {
public:
    int lengthOfLastWord(string s) {
        string t;
        int len = 0;

        for (int i = s.size() - 1; i >= 0; i--) {
            if (s[i] == ' ' && !t.size()) continue;
            else {
                if (s[i] == ' ') break;
                t += s[i];
            }
        }

        return t.size();
    }
};