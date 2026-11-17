class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int l = 0;
        int r = nums.size() - 1;

        while (l <= r) {
            int m = l + (r - l) / 2;

            if (nums[m] >= target)
                r = m - 1;
            else
                l = m + 1;
        }

        int first = l;

        if (first == nums.size() || nums[first] != target)
            return {-1, -1};

        l = 0;
        r = nums.size() - 1;

        while (l <= r) {
            int m = l + (r - l) / 2;

            if (nums[m] <= target)
                l = m + 1;
            else
                r = m - 1;
        }

        int last = r;

        return {first, last};
    }
};