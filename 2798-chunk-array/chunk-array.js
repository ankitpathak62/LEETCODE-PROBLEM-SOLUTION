/**
 * @param {Array} arr
 * @param {number} size
 * @return {Array[]}
 */
var chunk = function(arr, size) {
    const result = []
    for(i = 0;i<arr.length;i+=size){
        result.push(arr.slice(i, Math.min(arr.length, i+size)))
    }
    return result
};