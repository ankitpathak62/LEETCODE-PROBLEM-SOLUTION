var majorityElement = function(nums) {
    let map = new Map();
    let n = nums.length / 2;

    for (let num of nums) {
        map.set(num, (map.get(num) || 0) + 1);
    }

    let ans = 0;

    for (let [key, value] of map.entries()) {
        if (value > n) {
            ans = key;
            break;
        }
    }

    return ans;
};

