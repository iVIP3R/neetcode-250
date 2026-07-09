class Solution {
private:
    vector<int> unique;
    unordered_map<int, int> freq;
public:
    int partition(int left, int right, int pivot_index) {
        int pivot_frequency = freq[unique[pivot_index]];
        int store_left = left;
        
        swap(unique[right], unique[pivot_index]);
        for (int i = left; i <= right; i++) {
            if (freq[unique[i]] < pivot_frequency) {
                swap(unique[i], unique[store_left]);
                store_left++;
            }
        }

        swap(unique[store_left], unique[right]);
        return store_left;
    }

    void quickselect(int left, int right, int k_smallest) {
        if (left == right) return;

        int pivot_index = rand() % (right - left + 1) + left;

        pivot_index = partition(left, right, pivot_index);

        if (pivot_index < k_smallest) {
            quickselect(pivot_index + 1, right, k_smallest);
        }
        else if (pivot_index > k_smallest) {
            quickselect(left, pivot_index - 1, k_smallest);
        }
        else {
            return;
        }
    }

    vector<int> topKFrequent(vector<int>& nums, int k) {
        if (nums.size() == 1) return nums;
        vector<int> res(k);

        for (const int& num: nums) {
            freq[num]++;
        }

        for (auto& [key, value]: freq) {
            unique.push_back(key);
        }

        quickselect(0, unique.size() - 1, unique.size() - k);
        copy(unique.begin() + unique.size() - k, unique.end(), res.begin());
        return res;
    }
};