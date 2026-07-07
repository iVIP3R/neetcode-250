class Solution {
public:
    void quickSort(vector<int>& nums, int left, int right) {
        if (left >= right) return;

        int pivotIndex = rand() % (right - left + 1) + left;
        int pivot = nums[pivotIndex];

        int lt = left;
        int mid = left;
        int gt = right;

        while (mid <= gt) {
            if (nums[mid] < pivot) {
                swap(nums[lt++], nums[mid++]);
            }
            else if (nums[mid] == pivot) {
                mid++;
            }
            else {
                swap(nums[gt--], nums[mid]);
            }
        }

        quickSort(nums, left, lt - 1);
        quickSort(nums, gt + 1, right);
    }

    vector<int> sortArray(vector<int>& nums) {
        quickSort(nums, 0, nums.size() - 1);
        return nums;
    }
};