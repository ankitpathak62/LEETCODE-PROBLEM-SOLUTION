class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int start = 0 ;
        int n =  nums.size();
        int end =   n-1;
        int mid;
        while(start<= end){
            mid = start + (end - start)/2;
            if(nums[mid] == target){
                return mid;
            }
            else if(nums[mid]<target){
                start = mid + 1 ;

            }
            else{
                n= mid;
                end= mid-1;
            }
        }
return n;
    }
};