/**
 * @param {number[]} arr
 * @param {Function} fn
 * @return {number[]}
 */
var filter = function(arr, fn) {
    
    let newArr = [];
    
    for(let i=0; i<arr.length; i++){
        
        let checkVal = fn(arr[i],i);
        
        if(checkVal){
            newArr.push(arr[i]);
        }
    }

    return newArr;
};