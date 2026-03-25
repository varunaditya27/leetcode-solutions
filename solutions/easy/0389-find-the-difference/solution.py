class Solution:
    def findTheDifference(self, s: str, t: str) -> str:
        t_list = list(t)
        for char in s:
            t_list.pop(t_list.index(char))
        return ''.join(t_list)
