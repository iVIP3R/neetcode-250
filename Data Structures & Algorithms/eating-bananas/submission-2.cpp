class Solution {
public:
    bool canFinish(vector<int>& piles, int k, int h) {
        long long sum = 0;

        for (int i = 0; i < piles.size(); i++) {
            sum += ceil(piles[i] / (double)k);
        }

        return sum <= h;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        long long min = 1;
        long long max = *max_element(piles.begin(), piles.end());


        int l = min;
        int r = max;
        while (l <= r) {
            int m = l + (r - l) / 2;

            if (canFinish(piles, m, h)) {
                r = m - 1;
            }
            else l = m + 1;
        }

        return l;
    }
};
