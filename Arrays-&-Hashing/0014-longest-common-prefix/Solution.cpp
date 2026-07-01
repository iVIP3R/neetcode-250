class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        auto shortest = min_element(
            strs.begin(), strs.end(),
            [](const string& a, const string& b) {
                return a.size() < b.size();
            });

        int minSize = shortest->size();

        for (int i = 0; i < minSize; i++) {
            for (int j = 1; j < strs.size(); j++) {
                if (strs[j][i] != strs[0][i])
                    return strs[0].substr(0, i);
            }
        }

        return strs[0].substr(0, minSize);
    }
};