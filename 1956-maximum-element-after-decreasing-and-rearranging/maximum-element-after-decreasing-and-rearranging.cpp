class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        int l = arr.size();
        std::vector<int> counter(l, 0);

        for (int i = 0; i < l; ++i) {
            ++counter[std::min(arr[i] - 1, l - 1)];
        }

        int ans = 1;
        for (int i = 1; i < l; ++i) {
            ans = std::min(i + 1, ans + counter[i]);
        }

        return ans;
    }
};