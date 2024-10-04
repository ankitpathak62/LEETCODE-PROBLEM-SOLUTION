class Solution {
public:
    vector<int> searchRange(vector<int>& num, int target) {
        int first = -1, last = -1, start = 0, mid, end = num.size()- 1;

        // first
        while (start <= end) {
            mid = start + (end - start) / 2;
            if (num[mid] == target) {
                first = mid;
                end = mid - 1;

            } else if (num[mid] < target) {
                start = mid + 1; // right side
            } else {
                end = mid - 1; // left side
            }
        }

        // second
        
        
        start = 0,  end = num.size()- 1;

        while (start <= end) {
            mid = start + (end - start) / 2;
            if (num[mid] == target) {
                last = mid;
                start = mid + 1;

            } else if (num[mid] < target) {
                start = mid + 1; // right side
            } else {
                end = mid - 1; // left side
            }
        }
        vector<int> a(2);
        a[0] = first;
        a[1] = last;
        
        return a;
    }
};