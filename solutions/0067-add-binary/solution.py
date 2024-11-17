class Solution:
    def addBinary(self, a: str, b: str) -> str:
        deca = 0
        decb = 0
        for i in range(len(a)):
            deca += int(a[-1 - i]) * (2 ** i)
        for j in range(len(b)):
            decb += int(b[-1 - j]) * (2 ** j)
        dec_sum = deca + decb
        return bin(dec_sum)[2:]
