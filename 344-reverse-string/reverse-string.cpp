class Solution {
public:
    void reverseString(vector<char>& s) {
        stack<char>hst;
        for (int i=0;i<s.size();i++)
        {
            hst.push(s[i]);
        }
        int i =0;
        while(!hst.empty())
        {
            s[i] = hst.top();
            hst.pop();
            i++;
        }
    }
};