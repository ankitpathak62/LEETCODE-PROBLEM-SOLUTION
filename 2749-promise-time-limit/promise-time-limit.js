/**
 * @param {Function} fn
 * @param {number} t
 * @return {Function}
 */
var timeLimit = function(fn, t) {
    
	return async function(...args) {
        let f1 = fn(...args);
        let f2 = new Promise((resolve, reject) => {
            setTimeout(() => {
                reject("Time Limit Exceeded");
            }, t)
        })
        return Promise.race([f1,f2]);
    }
};

/**
 * const limited = timeLimit((t) => new Promise(res => setTimeout(res, t)), 100);
 * limited(150).catch(console.log) // "Time Limit Exceeded" at t=100ms
 */