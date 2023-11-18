#pragma GCC optimize("O3")
class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int n=nums.size();
        int freq=0, l=0;
        long long sum=0;
        #pragma unroll
        for(int r=0; r<n; r++){
            long long x=nums[r];
            sum+=x;
            #pragma unroll
            while((r-l+1)*x-sum>k){
               sum-=nums[l++]; 
            }
            freq=max(freq, r-l+1);
        }       
        return freq;
    }
};
auto init = []()
{ 
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();