class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int res = INT_MIN;
        unordered_set<int> st;
        for (const int& num: nums) st.insert(num);

        for (const int& x: st) {
            if (st.count(x + 1)) continue;
            int tmp = x - 1;
            int len = 1;
            while (st.count(tmp--)) len++;
            res = max(res, len);
        }

        return res == INT_MIN ? 0 : res;
    }
};
