class Solution:
    def addDigits(self, num: int) -> int:
        digit_sum = num
        while digit_sum > 9:
            digit_sum = sum(int(digit) for digit in str(digit_sum))
        return digit_sum
