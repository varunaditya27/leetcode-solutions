class Solution:
    def firstUniqChar(self, s: str) -> int:
        uniques = {}
        for i in range(len(s)):
            if s[i] not in uniques:
                uniques[s[i]] = str(i)
            else:
                uniques[s[i]] = 'x'
        for unique in uniques.keys():
            if uniques[unique].isdecimal():
                return int(uniques[unique])
        return -1
