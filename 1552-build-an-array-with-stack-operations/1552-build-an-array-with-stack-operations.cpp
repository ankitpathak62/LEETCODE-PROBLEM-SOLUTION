class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
     vector<string> str;
     int j =0;
     for(int i =1;i<=n;i++){
         if(target[j]==i){
             str.push_back("Push");
             j++;
         
             if(j==target.size()) break;
         }
         else {
             str.push_back("Push");
             str.push_back("Pop");
         }
         }
      
     return str; 
    }
};