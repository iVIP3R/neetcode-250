class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        int n = nums.size();
        int resSize = nums.size() * 2;
        int idx = n;
        vector<int> res(resSize, 0);
        for (int i = 0; i < n; i++) {
            res[i] = nums[i];
            res[idx++] = nums[i];
        }

        return res;
    }
};