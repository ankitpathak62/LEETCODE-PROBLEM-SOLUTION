import java.util.HashSet;

class Solution {
    public int subarrayBitwiseORs(int[] arr) {
        HashSet<Integer> uniqueResult = new HashSet<>();
        HashSet<Integer> previous = new HashSet<>();

        for (int i = 0; i < arr.length; i++) {
            HashSet<Integer> current = new HashSet<>();
            current.add(arr[i]);
            uniqueResult.add(arr[i]);

            for (Integer prev : previous) {
                int orResult = prev | arr[i];
                current.add(orResult);
                uniqueResult.add(orResult);
            }
            previous = current;
        }
        return uniqueResult.size();
    }
}
