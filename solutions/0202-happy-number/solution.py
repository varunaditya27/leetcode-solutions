class Solution:
    def isHappy(self, n: int) -> bool:
        tracker = {n:0}
        while tracker[n] < 2:
            n = sum(int(x) ** 2 for x in str(n))
            if n in tracker:
                tracker[n] += 1
            else:
                tracker[n] = 1
            print(n)
            if n == 1:
                return True
        return False

