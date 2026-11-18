class Solution {
public:
    bool canShip(vector<int>& weights, int capacity, int days) {
        int currentLoad = 0;
        int neededDays = 1;

        for (int weight: weights) {
            if (weight + currentLoad > capacity) {
                neededDays++;
                currentLoad = 0;
            }

            currentLoad += weight;
        }

        return neededDays <= days;
    }

    int shipWithinDays(vector<int>& weights, int days) {
        int l = *max_element(weights.begin(), weights.end());
        int r = 0;
        for (int i = 0; i < weights.size(); i++) r += weights[i];

        while (l <= r) {
            int m = l + (r - l) / 2;

            if (canShip(weights, m, days)) {
                r = m - 1;
            }
            else l = m + 1;
        }

        return l;
    }
};