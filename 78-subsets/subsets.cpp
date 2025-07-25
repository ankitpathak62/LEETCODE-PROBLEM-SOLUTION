class Solution {
public:
    void subsequence(vector<int>&arr, int n, int index, vector<int>& temp,
                     vector<vector<int>>& ans) {
        // base case
        if (index == n) {
            ans.push_back(temp);
            return;
        }
        // Not taking the element
        subsequence(arr, n, index + 1, temp, ans);
        // Take the element
        temp.push_back(arr[index]);
        subsequence(arr, n, index + 1, temp, ans);
        temp.pop_back();
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> temp;
        vector<vector<int>> ans;
        subsequence(nums, nums.size(), 0, temp, ans);
        return ans;
    }
};