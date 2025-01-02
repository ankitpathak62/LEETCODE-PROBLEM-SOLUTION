class Solution {
public:
    int longestPalindrome(string s) {

        vector<int> arraylower(26, 0);
        vector<int> arrayupper(26, 0);

        int count = 0;
        bool odd = 0;

        for (int i = 0; i < s.size(); i++) {
            if (s[i] >= 'a') {
                arraylower[s[i] - 'a']++;
            } else {
                arrayupper[s[i] - 'A']++;
            }
        }

        for (int i = 0; i < 26; i++) {
            // arraylower
            if (arraylower[i] % 2 == 0) {
                count += arraylower[i];
            } else {
                count += arraylower[i] - 1;
                odd = 1;
            }

            // arrayupper
            if (arrayupper[i] % 2 == 0) {
                count += arrayupper[i];
            } else {
                count += arrayupper[i] - 1;
                odd = 1;
            }
        }
        return count + odd;
    }
};