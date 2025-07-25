class Solution {
public:
    void para(int n, int L, int R, vector<string>& ans,
              string& temp){
                if(L+R ==2*n){
                    ans.push_back(temp);
                    return;
                }

                //left 
                if(L<n){
                    temp.push_back('(');
                    para(n, L+1,R,ans, temp);
                    temp.pop_back();
                }

                //right
                if(R<L){
                    temp.push_back(')');
                    para(n, L,R+1,ans, temp);
                    temp.pop_back();

                }
              }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string temp;
        para(n, 0, 0,ans, temp);
        return ans;
    }
};