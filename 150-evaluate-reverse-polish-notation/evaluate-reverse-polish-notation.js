/**
 * @param {string[]} tokens
 * @return {number}
 */
class Solution {
    resolves(a, b, Operator) {
        if (Operator === '+') return a + b;
        else if (Operator === '-') return a - b;
        else if (Operator === '*') return a * b;
        return Math.trunc(a / b);
    }

    evalRPN(tokens) {
        const stack = [];
        for (const token of tokens) {
            if (token.length === 1 && token.charCodeAt(0) < 48) {
                const integer2 = stack.pop();
                const integer1 = stack.pop();
                const operator = token;
                const resolvedAns = this.resolves(integer1, integer2, operator);
                stack.push(resolvedAns);
            } else {
                stack.push(parseInt(token, 10));
            }
        }
        return stack.pop();
    }
}

var evalRPN = function(tokens) {
    const stack = [];
    const resolves = (a, b, Operator) => {
        if (Operator === '+') return a + b;
        else if (Operator === '-') return a - b;
        else if (Operator === '*') return a * b;
        return Math.trunc(a / b);
    };

    for (const token of tokens) {
        if (token.length === 1 && token.charCodeAt(0) < 48) {
            const integer2 = stack.pop();
            const integer1 = stack.pop();
            const operator = token;
            const resolvedAns = resolves(integer1, integer2, operator);
            stack.push(resolvedAns);
        } else {
            stack.push(parseInt(token, 10));
        }
    }
    return stack.pop();
};