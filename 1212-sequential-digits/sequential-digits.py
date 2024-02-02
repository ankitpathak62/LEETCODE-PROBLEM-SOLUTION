class Solution:
    def sequentialDigits(self, low: int, high: int) -> List[int]:
        result = []
        for num in range(1, 10):
            current = next_digit = num
            while current <= high and next_digit < 10:
                if current >= low:
                    result.append(current)
                next_digit += 1
                current = current * 10 + next_digit
        return sorted(result)