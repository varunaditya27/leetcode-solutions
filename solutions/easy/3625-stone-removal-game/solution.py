class Solution:
    def canAliceWin(self, n: int) -> bool:
        turn = 1
        for i in range(10, -1, -1):
            if n >= i:
                n -= i
                turn += 1
            else:
                if turn % 2 == 0:
                    return True
                else:
                    return False
