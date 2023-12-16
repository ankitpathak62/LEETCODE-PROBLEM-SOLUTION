/**
 * @param {Array} arr
 * @param {Function} fn
 * @return {Array}
 */
const sortBy = function(arr, fn) {
    function swap(a, b) {
        return (fn(a) < fn(b)) ? -1 : 1
    }

    return arr.sort(swap)
};