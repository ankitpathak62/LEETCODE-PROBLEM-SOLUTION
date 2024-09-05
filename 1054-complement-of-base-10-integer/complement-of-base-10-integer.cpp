class Solution {
public:
    int bitwiseComplement(int n) {
        if (n ==0){
            return 1;
        }
       int ans = 0, rem, mult =1;
       while(n){
        rem = n%2;
        rem = rem^1;
        n = n/2;
        ans = ans + rem * mult;
        mult = mult * 2;
       }
       return ans;
    }
};