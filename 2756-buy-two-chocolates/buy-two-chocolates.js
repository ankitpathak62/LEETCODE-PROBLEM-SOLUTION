var buyChoco = function(arr, key) {
    let ans = Infinity;
        let fin;

        for (let i = 0; i < arr.length; ++i) {
            for (let j = 0; j < arr.length; ++j) {
                if (i !== j) {
                    const sum = arr[i] + arr[j];
                    ans = Math.min(ans, sum);
                }
            }
        }

        fin = key - ans;
        if(fin>=0){
        return fin;
        }
        else{
            return key;
        }
};