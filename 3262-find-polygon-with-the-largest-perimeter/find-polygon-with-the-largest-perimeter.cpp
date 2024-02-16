#include <algorithm>
#include <vector>

class Solution {
public:
    long long largestPerimeter(std::vector<int>& nums) {
        std::sort(nums.begin(), nums.end());  // Sort the vector in ascending order
        long long Csum = 0, Psum = 0;  // Initialize current sum and perimeter sum to 0

        for (int i = 0; i < nums.size(); ++i) {
            // Check if the current element can be part of a valid triangle
            if (nums[i] < Csum) {
                Psum = Csum + nums[i];  // Update perimeter sum with the potential triangle's perimeter
            }
            Csum += nums[i];  // Update current sum with the current element
        }

        // Return the largest perimeter if a valid triangle is found, otherwise return -1
        return (Psum == 0) ? -1 : Psum;
    }
};