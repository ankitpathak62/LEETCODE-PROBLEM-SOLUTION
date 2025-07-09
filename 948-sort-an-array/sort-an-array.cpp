class Solution {
public:
    void merge(vector<int>&arr, int start, int mid, int end) {
        vector<int> temp(end - start + 1);
        int left = start;
        int right = mid + 1;
        int index = 0;

        // Merging the two subarrays
        while (left <= mid && right <= end) {
            if (arr[left] <= arr[right]) {
                temp[index++] = arr[left++];
            } else {
                temp[index++] = arr[right++];
            }
        }

        // Copy remaining elements from left subarray
        while (left <= mid) {
            temp[index++] = arr[left++];
        }

        // Copy remaining elements from right subarray
        while (right <= end) {
            temp[index++] = arr[right++];
        }

        // Copy temp array back to original array
        for (int i = 0; i < temp.size(); i++) {
            arr[start + i] = temp[i];
        }
    }

    void mergesort(vector<int>& arr, int start, int end) {
        if (start >= end)
            return; // base case

        int mid = (start + end) / 2;
        mergesort(arr, start, mid);   // Sort left half
        mergesort(arr, mid + 1, end); // Sort right half
        merge(arr, start, mid, end);  // Merge sorted halves
    }

    vector<int> sortArray(vector<int>& nums) {
        mergesort(nums, 0, nums.size() - 1);
        return nums;
    }
};