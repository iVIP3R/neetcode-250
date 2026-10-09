class Solution {
public:
    bool isPalindrome(string s) {
        string t = "";

        for (const char& c: s) {
            if (isalnum(static_cast<unsigned char>(c))) t.push_back(tolower(c));
        }

        int l = 0;
        int r = t.size() - 1;
        
        while (l <= r) {
            if (t[l++] != t[r--]) return false;
        }

        return true;
    }
};
