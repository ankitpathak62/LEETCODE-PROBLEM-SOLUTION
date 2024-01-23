/**
 * @param {string[]} arr - Array of strings
 * @return {number} - Maximum length of a string with unique characters
 */
var maxLength = function(arr) {
    // Helper function to check if a string has unique characters using bitmasks
    const hasUniqueChars = (mask, word) => {
        let newMask = mask;
        for (const char of word) {
            const charCode = char.charCodeAt(0) - 'a'.charCodeAt(0);
            if ((newMask & (1 << charCode)) !== 0) {
                // If the character is already set in the bitmask, it's not unique
                return false;
            }
            // Set the character in the bitmask
            newMask |= (1 << charCode);
        }
        return true;
    };

    // Backtracking function with bitmask and without unnecessary recursion
    const backtrack = (index, mask, length) => {
        // Update maxLength with the maximum length found so far
        maxLength = Math.max(maxLength, length);

        // Explore the array starting from the given index
        for (let i = index; i < arr.length; i++) {
            if (hasUniqueChars(mask, arr[i])) {
                // If the current string has unique characters, continue exploration
                backtrack(i + 1, mask | wordToMask(arr[i]), length + arr[i].length);
            }
        }
    };

    // Helper function to convert a word to a bitmask
    const wordToMask = (word) => {
        let mask = 0;
        for (const char of word) {
            const charCode = char.charCodeAt(0) - 'a'.charCodeAt(0);
            mask |= (1 << charCode);
        }
        return mask;
    };

    // Initialize maxLength to 0 and start exploration from the beginning
    let maxLength = 0;
    backtrack(0, 0, 0);
    
    // Return the maximum length found during the exploration
    return maxLength;
};