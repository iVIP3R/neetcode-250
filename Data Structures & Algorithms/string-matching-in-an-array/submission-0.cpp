class Solution {
public:
    bool isSubstring(string word1, string word2) {
        return word2.find(word1) != string::npos;
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