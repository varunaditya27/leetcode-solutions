class Solution:
    def plusOne(self, digits: List[int]) -> List[int]:
        num = int(''.join(map(str, digits)))
        num += 1
        num_str = str(num)
        result = [int(num_str[i]) for i in range(len(num_str))]
        return result
