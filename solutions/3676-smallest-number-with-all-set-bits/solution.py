class Solution:
    def smallestNumber(self, n: int) -> int:
        while True:
            if set(bin(n)[2:]) == {'1'}:
                return n
            else:
                n += 1
