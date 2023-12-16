/**
 * @return {Function}
 */
var createHelloWorld = function() {
    return function(...args) {
        // return value
        return "Hello World";
    }
};

/**
 * const f = createHelloWorld();
 * f(); // "Hello World"
 */