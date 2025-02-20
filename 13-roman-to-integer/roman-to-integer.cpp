class Solution {
public:
    int num(char ch) {
        if (ch == 'I') {
            return 1;
        }
        if (ch == 'V') {
            return 5;
        }
        if (ch == 'X') {
            return 10;
        }
        if (ch == 'L') {
            return 50;
        }
        if (ch == 'C') {
            return 100;
        }
        if (ch == 'D') {
            return 500;
        } else {
            return 1000;
        }
    }
    int romanToInt(string s) {
        int sum = 0, index = 0;

        while (index < s.size() - 1) {
            if (num(s[index]) < num(s[index + 1])) {
                sum -= num(s[index]);
            } else {
                sum += num(s[index]);
            }
            index++;
        }
        sum += num(s[index]);
        return sum;
    }
};