class Solution {
public:
    bool isSubstring(string word1, string word2) {
        int i = 0, j = 0;
        while (i < word1.size() && j < word2.size()) {
            if (word1[i] == word2[j]) {
                i++;
                j++;
            } else {
                j = j - i + 1;
                i = 0;
            }
        }
        return i == word1.size();
    }



    vector<string> stringMatching(vector<string>& words) {
        vector<string> res;

        for (int i = 0; i < words.size(); i++) {
            for (int j = 0; j < words.size(); j++) {
                if (j == i) continue;
                if (isSubstring(words[i], words[j])) {
                    res.push_back(words[i]);
                    break;
                }
            }
        }

        return res;
    }
};