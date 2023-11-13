class Solution {
    public String sortVowels(String s) {
        
        String vowels ="aeiouAEIOU";
        
        char[] c = s.toCharArray();
        
        PriorityQueue<Character> pq = new PriorityQueue<>((a, b) -> { return (int)a - (int)b;  });
        
        for(char ch : c){
            if(vowels.indexOf(ch)!=-1)
            pq.add(ch);
        }
       
        for(int i=0; i<c.length;i++)
        {   
            if(vowels.indexOf(c[i])!=-1){
                c[i] =pq.poll();
            }
        }
        return new String(c);
    }
}