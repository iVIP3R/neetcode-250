class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        int maxFreq = 0;

        for (int num : nums) {
            maxFreq = max(maxFreq, ++freq[num]);
        }

        vector<vector<int>> buckets(maxFreq + 1);

        for (const auto& [num, count] : freq) {
            buckets[count].push_back(num);
        }

        vector<int> res;
        res.reserve(k);

        for (int count = maxFreq; count > 0 && k > 0; --count) {
            for (int num : buckets[count]) {
                res.push_back(num);

                if (--k == 0) {
                    return res;
                }
            }
        }

        return res;
    }
};