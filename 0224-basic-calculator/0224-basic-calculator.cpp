class Solution {
public:
    int calculate(string s) {
        long result = 0;
        int sign = 1;
        stack<long> stk;

        for (int i = 0; i < (int)s.size(); i++) {
            char c = s[i];

            if (isdigit(c)) {
                long num = 0;
                while (i < (int)s.size() && isdigit(s[i])) {
                    num = num * 10 + (s[i] - '0');
                    i++;
                }
                i--;
                result += sign * num;
            } else if (c == '+') {
                sign = 1;
            } else if (c == '-') {
                sign = -1;
            } else if (c == '(') {
                stk.push(result);
                stk.push(sign);
                result = 0;
                sign = 1;
            } else if (c == ')') {
                long prevSign = stk.top(); stk.pop();
                long prevResult = stk.top(); stk.pop();
                result = prevResult + prevSign * result;
            }
        }

        return (int)result;
    }
};