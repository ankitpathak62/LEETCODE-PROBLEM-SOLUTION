class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int> result;
        
        // If n is odd, include 0
        if (n % 2 != 0) {
            result.push_back(0);
        }
        
        // Add pairs of positive and negative integers
        for (int i = 1; i <= n / 2; ++i) {
            result.push_back(i);
            result.push_back(-i);
        }
        
        return result;
    }
};
