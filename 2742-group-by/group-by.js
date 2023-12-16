Array.prototype.groupBy = function(fn) {
    const group = {};
    for (const val of this) {
        const key = fn(val);
        group.hasOwnProperty(key) ? group[key].push(val) : group[key] = [val];
    }

    return group;
};