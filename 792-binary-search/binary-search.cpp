class Solution {
public:
    int search(vector<int>& arr, int Element) {
        int n = arr.size();
        int first_element = 0;
        int last_element = n - 1;
        int mid;

        while (first_element <= last_element) {
            mid = first_element + ((last_element - first_element) / 2);

            if (arr[mid] == Element) {
                return mid;
            } else if (arr[mid] < Element) {
                first_element = mid + 1;
            } else {
                last_element = mid - 1;
            }
        }
        return -1;
    }
};