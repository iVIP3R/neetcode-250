class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int idx = nums.size() - 1;
        int res = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (i > idx) break;
            if (nums[i] == val) {
                while (i < idx && nums[idx] == val) idx--, res++;
                swap(nums[i], nums[idx--]);
                res++;
            }
        }

        return nums.size() - res;
    }
};