var rob = function(nums) {
    const n = nums.length;
    if (n === 0) {
        return 0;
    }

    const s0 = [0, 0];
    const s1 = [0, 0];
    s1[0] = nums[0];

    for (let i = 1; i < n; i++) {
        s0[i % 2] = Math.max(s0[(i - 1) % 2], s1[(i - 1) % 2]);
        s1[i % 2] = s0[(i - 1) % 2] + nums[i];
    }

    return Math.max(s0[(n - 1) % 2], s1[(n - 1) % 2]);
};

