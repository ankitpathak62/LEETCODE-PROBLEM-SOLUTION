var halvesAreAlike = function(s) {
    const countVowels = (str) => {
        const vowels = new Set(['a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U']);
        return Array.from(str).filter(char => vowels.has(char)).length;
    };

    const length = s.length;
    const midPoint = length / 2;

    const firstHalf = s.substring(0, midPoint);
    const secondHalf = s.substring(midPoint);

    return countVowels(firstHalf) === countVowels(secondHalf);
};