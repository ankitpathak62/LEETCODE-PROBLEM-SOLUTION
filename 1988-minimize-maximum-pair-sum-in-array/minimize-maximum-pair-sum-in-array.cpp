class Solution {
public:
    int minPairSum(vector<int>& nums) {
        int n = nums.size();
        sort (nums.begin(), nums.end());
        int i = 0, j = n - 1;
        int ans = 0;
        while (i < n && j >= 0) {
            ans = max (nums[i] + nums[j], ans);
            i++;
            j--;
        }
        return ans;
    }
};