class Solution:
    def majorityElement(self, nums: List[int]) -> int:
        num_dict = {}
        n = len(nums) / 2
        for num in nums:
            if num not in num_dict:
                num_dict[num] = 1
            else:
                num_dict[num] += 1
        for x in num_dict:
            if num_dict[x] > n:
                return x
