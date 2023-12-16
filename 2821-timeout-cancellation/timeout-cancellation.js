var cancellable = function(fn, args, t) {
    let cancel = false;
    setTimeout(() =>!cancel && fn(...args),t)
    return () => cancel = true
};