function isVowel(element) {
    if (
        element === 'a' ||
        element === 'e' ||
        element === 'i' ||
        element === 'o' ||
        element === 'u' ||
        element === 'A' ||
        element === 'E' ||
        element === 'I' ||
        element === 'O' ||
        element === 'U'
    ) {
        return true;
    }
}

var sortVowels = function(s) {
    const asciiStorage = [];
    for (let index = 0; index < s.length; index++) {
        const element = s[index];
        if (isVowel(element)) {
            const charCodeAt = s.charCodeAt(index);
            if (!asciiStorage[charCodeAt]) {
                asciiStorage[charCodeAt] = 0;
            }
            asciiStorage[charCodeAt] += 1;
        }
    }
    let outputAsciiIndexStore = [];
    for (let index = 65; index < asciiStorage.length; index++) {
        if (asciiStorage[index]) {
            let store = asciiStorage[index];
            while (store--) {
                outputAsciiIndexStore.push(index);
            }
        }
    }
    let tempIndex = 0;
    const splittedString = s.split('');
    for (let index = 0; index < splittedString.length; index++) {
        const element = splittedString[index];
        if (isVowel(element)) {
            splittedString[index] = String.fromCharCode(outputAsciiIndexStore[tempIndex++]);
        }
    }
    return splittedString.join('');
};