class Solution(object):
    mod = 10**9 + 7
    MOVES = [
        [4, 6],
        [6, 8],
        [7, 9],
        [4, 8],
        [0, 3, 9],
        [],
        [0, 1, 7],
        [2, 6],
        [1, 3],
        [2, 4]
    ]

    def __init__(self):
        self.cache = [[0] * 10 for _ in range(5001)]

    def knightDialer(self, n):
        next_numbers = [0, 1, 2, 3, 4, 5, 6, 7, 8, 9]
        return self.knightDialerRecursive(n, next_numbers)

    def knightDialerRecursive(self, remaining, next_numbers):
        if remaining == 1:
            return len(next_numbers)

        count = 0
        for next_number in next_numbers:
            cur = self.cache[remaining][next_number]
            if cur == 0:
                cur = self.knightDialerRecursive(remaining - 1, self.MOVES[next_number])
                self.cache[remaining][next_number] = cur
            count += cur
            count %= self.mod

        return count
        