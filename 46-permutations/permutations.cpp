class Solution {
public:
    void permutation(vector<int>&arr, int size, vector<int>& temp,
                     vector<vector<int>>& ans, vector<bool>& visited) {
        // base case
        if (temp.size() == size) {
            ans.push_back(temp);
            return;
        }

        for (int i = 0; i < size; i++) {
            if (visited[i] == 0) {
                visited[i] = 1;
                temp.push_back(arr[i]);
                permutation(arr, size, temp, ans, visited);
                visited[i] = 0;
                temp.pop_back();
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {

        vector<vector<int>> ans;
        int size = nums.size();
        vector<int> temp;
        vector<bool> visited(nums.size(), 0);
        permutation(nums, size, temp, ans, visited);
        return ans;
    }
};