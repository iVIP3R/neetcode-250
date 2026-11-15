class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> mp;

        mp[0] = 1;
        int total = 0;
        int res = 0;

        for (int i = 0; i < n; i++) {
            total += nums[i];
            
            if (mp.find(total - k) != mp.end()) res += mp[total - k];

            mp[total]++;
        }

        return res;
    }
};