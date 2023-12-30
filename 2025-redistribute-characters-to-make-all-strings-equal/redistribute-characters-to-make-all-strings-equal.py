class Solution:
    def makeEqual(self, words: List[str]) -> bool:
        counts = [0] * 26
        for word in words:
            for c in word:
                counts[ord(c) - ord('a')] += 1
        n = len(words)
        for c in counts:
            if c % n != 0: return False
        return True