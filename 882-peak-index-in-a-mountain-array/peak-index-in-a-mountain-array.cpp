class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {

        int start = 0, mid, end = arr.size() - 1;
        while (start <= end) {
            // mid = start + (end - start) / 2;
            mid = end + (start - end) / 2;
            if (arr[mid] > arr[mid - 1] && arr[mid] > arr[mid + 1]) {
                return mid;
            } else if (arr[mid] > arr[mid - 1]) {
                start = mid + 1;
            } else {
                end = mid - 1;
            }
        }
        return -1;
    }
};