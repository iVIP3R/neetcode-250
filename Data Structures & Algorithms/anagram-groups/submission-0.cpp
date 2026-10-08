class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;
        vector<vector<string>> res;

        for (const string& str: strs) {
            string tmp = str;
            sort(tmp.begin(), tmp.end());
            mp[tmp].push_back(str);
        }

        for (auto z: mp) {
            res.push_back(z.second);
        }

        return res;
    }
};
