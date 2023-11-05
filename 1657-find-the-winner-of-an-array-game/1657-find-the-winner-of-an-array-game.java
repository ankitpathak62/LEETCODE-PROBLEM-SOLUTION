class Solution {

/*

   using HashMap

    

    static int helper(int ar[], int k){
        ArrayList<Integer> arr = new ArrayList<>();
        int n = ar.length;
        for(int i=0; i<n; i++){
            arr.add(ar[i]);
        }

        HashMap<Integer,Integer> hp = new HashMap<>();

        while(true){
            int a = arr.get(0);
            int b = arr.get(1);

            if(a>b){
                hp.put(a,hp.getOrDefault(a,0)+1);
                if(hp.get(a)==k) return a;
                arr.add(b);
                arr.remove(1);
            }else{
                hp.put(b,hp.getOrDefault(b,0)+1);
                if(hp.get(b)==k) return b;
                arr.add(a);
                arr.remove(0);
            }
        }
        return -1;
    }
    */

    static int max(int arr[]){
        int ans = arr[0];
        int n = arr.length;
        for(int i=1; i<n; i++){
            if(arr[i]>ans) ans = arr[i];
        }
        return ans;
    }

    public int getWinner(int[] arr, int k) {
        int n = arr.length;
        if(k>=n) return max(arr);

        int ans = arr[0];
        int count = 0;

        for(int i=1; i<n; i++){
            if(ans>arr[i]) count++;
            else{
                ans = arr[i];
                count = 1;
            }

            if(count==k) return ans;
        }
        return ans;
    }
}