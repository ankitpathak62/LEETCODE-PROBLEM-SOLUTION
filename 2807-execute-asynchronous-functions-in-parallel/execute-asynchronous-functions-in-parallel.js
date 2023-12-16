/**
 * @param {Array<Function>} functions
 * @return {Promise<any>}
 */
var promiseAll = function(functions) {
  return new Promise((resolve, reject) => {
    const results = [];
    let resolvedCount = 0;

    for (let i = 0; i < functions.length; i++) {
      functions[i]()
        .then(result => {
            results[i] = result;
            resolvedCount++;

            if (resolvedCount === functions.length) {
              resolve(results);
          }
        })
        .catch(error => {
            reject(error);
        });
    }
  });
};

/**
 * const promise = promiseAll([() => new Promise(res => res(42))])
 * promise.then(console.log); // [42]
 */