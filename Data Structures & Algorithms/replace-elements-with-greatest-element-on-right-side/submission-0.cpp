class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        int n = arr.size();
        vector<int> res(arr.size(), -1);

        int ma = -1;
        for (int i = n - 2; i >= 0; i--) {
            ma = max(ma, arr[i + 1]);
            res[i] = ma;
        }

        return res;
    }
};