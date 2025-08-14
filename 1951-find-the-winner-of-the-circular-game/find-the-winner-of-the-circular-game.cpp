class Solution {
public:
    int winner(vector<bool>& person, int n, int index, int per_left, int k) {
        if (per_left == 1) {
            for (int i = 0; i < n; i++) {
                if (person[i] == 0) {
                    return i;
                }
            }
        }
        // find position kill
        int kill = (k - 1) % per_left;

        while (kill--) {

            index = (index + 1) % n;
            while (person[index] == 1) {
                index = (index + 1) % n;
            }
        }
        person[index] = 1;
        // next alive
        while (person[index] == 1) {
            index = (index + 1) % n;
        }

        return winner(person, n, index, per_left - 1, k);
    }
    int findTheWinner(int n, int k) {
        vector<bool> person(n, 0);
        return winner(person, n, 0, n, k) + 1;
    }
};