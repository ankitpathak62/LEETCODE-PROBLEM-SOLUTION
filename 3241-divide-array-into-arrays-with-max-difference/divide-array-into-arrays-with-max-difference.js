var divideArray = function(nums, k) {
    nums.sort((a,b) => a - b)

    let ans = []
    let len = nums.length
    let flag = true

    for(let i = 0; i < len - 2; i = i + 3){
        if(nums[i + 2] - nums[i + 1] <= k && nums[i + 2] - nums[i] <= k && nums[i + 1] - nums[i] <= k){
            ans.push([nums[i],nums[i + 1],nums[i + 2]])
        }
        else{
            flag = false
            break
        }
    }

    return flag?ans:[]
};