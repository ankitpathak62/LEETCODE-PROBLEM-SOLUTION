class Solution {
    public boolean makeEqual(String[] words) {
        int n = words.length;
        int[] map = new int[26];
        for(String word : words){
            for(char c : word.toCharArray()){
                map[c-'a']++;
            }
        }
        for(int i=0; i<26; i++){
            if(map[i]%n != 0 ) return false; 
        }
        return true; 
    }
}