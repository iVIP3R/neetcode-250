class Solution {
public:
    int maxArea(vector<int>& heights) {
        int mA = 0;
        int l = 0;
        int r = heights.size() - 1;

        while (l < r) {
            int area = (r - l) * (min(heights[l], heights[r]));
            mA = max(mA, area);

            if (heights[l] >= heights[r]) r--;
            else if (heights[l] < heights[r]) l++;
        }

        return mA;
    }
};
