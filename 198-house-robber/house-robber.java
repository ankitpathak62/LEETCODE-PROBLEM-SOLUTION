


class Solution {
    public int rob(int[] nums) {
        int n = nums.length;
        if (n == 0) {
            return 0;
        }

        int[] s0 = new int[2];
        int[] s1 = new int[2];
        s1[0] = nums[0];

        for (int i = 1; i < n; i++) {
            s0[i % 2] = Math.max(s0[(i - 1) % 2], s1[(i - 1) % 2]);
            s1[i % 2] = s0[(i - 1) % 2] + nums[i];
        }

        return Math.max(s0[(n - 1) % 2], s1[(n - 1) % 2]);
    }
}
