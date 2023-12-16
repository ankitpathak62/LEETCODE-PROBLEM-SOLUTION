/**
 * @param {Object | Array} obj
 * @return {boolean}
 */
var isEmpty = function(obj) {
    if(Array.isArray(obj))
        return (!obj.length);
    // console.log(Object.values(obj))
    return (!Object.values(obj).length);
};