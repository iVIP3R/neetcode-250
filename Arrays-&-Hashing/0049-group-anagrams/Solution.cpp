class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        unordered_map<string, vector<string>> mp;

        for (const string& str: strs) {
            string tmp = str;
            sort(tmp.begin(), tmp.end());
            mp[tmp].push_back(str);
        }

        for (auto& [key, value]: mp) {
            res.push_back(value);
        }
        return res;
    }
};