class Solution {
public:
    int countHomogenous(string s) {
        int i=0,j=0,ln= s.size(), ans=0, M= 1e9+7;
        while(j<ln){
            while(j<ln && s[j]==s[i]){ 
                ans= (ans+(j-i+1))%M ;
                j++;
            }
            i=j;
        }
        return ans;
    }
};