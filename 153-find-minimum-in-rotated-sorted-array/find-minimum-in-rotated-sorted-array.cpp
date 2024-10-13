class Solution {
public:
    int findMin(vector<int>& nums) {
        int ans = nums[0], mid, start = 0, end = nums.size() - 1;
        while(start<= end){
            mid = start + (end - start)/2;

            if(nums[mid] < nums[0]){
                ans = nums[mid];
                end = mid-1;
                //right side sorted
            }
            else{
                start = mid + 1 ;
                //left side sorted
            }
        }
        return ans;
    }
};