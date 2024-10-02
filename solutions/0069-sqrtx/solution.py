class Solution:
    def mySqrt(self, x: int) -> int:
        k = 1
        while (k * k) <= x:
            k += 1
        return k - 1
