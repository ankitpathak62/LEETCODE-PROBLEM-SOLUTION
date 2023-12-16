var compactObject = function(obj) {
    if (typeof obj === 'object') {
        if (Array.isArray(obj)) {
            const tempArray = [];
            for (let index = 0; index < obj.length; index++) {
                if (Boolean(obj[index])) {
                    tempArray.push(compactObject(obj[index]));
                }
            }
            return tempArray;
        } else {
            const tempObject = {};
            for (const key in obj) {
                if (Boolean(obj[key])) {
                    tempObject[key] = compactObject(obj[key]);
                }
            }
            return tempObject;
        }
    }
    return obj;
};