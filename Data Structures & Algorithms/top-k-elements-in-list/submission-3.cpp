class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        if (k == nums.size()) return nums;
        unordered_map<int, int> mp;

        int s = 1;
        for (const int& num: nums) mp[num]++, s = max(s, mp[num]);

        vector<vector<int>> freq(s + 1);
        for (auto& z: mp) {
            freq[z.second].push_back(z.first);
        }

        vector<int> res;
        for (int i = freq.size() - 1; i >= 0; i--) {
            for (int j = 0; j < freq[i].size() && k; j++) {
                res.push_back(freq[i][j]);
                k--;
            }
        }

        return res;
    }
};
