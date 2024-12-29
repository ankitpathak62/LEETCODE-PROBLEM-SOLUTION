class Solution {
public:
    bool checkIfPangram(string sentence) {
        vector<bool> array1(26, 0);

        for (int i = 0; i < sentence.size(); i++) {
            array1[sentence[i] - 'a'] = 1;
        }
        for (int i = 0; i < 26; i++) {
            if (array1[i] == 0) {
                return 0;
            }
        }
        return 1;
    }
};