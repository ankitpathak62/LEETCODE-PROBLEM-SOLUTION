class Solution {
public:
    int smallestRepunitDivByK(int k) {
        int reminder = 1;
        for (int i = 1; i <= k; i++) {

            if (reminder % k == 0) {
                return i;
            }
            reminder = (reminder % k) * 10 + 1;
        }
        return -1;
    }
};