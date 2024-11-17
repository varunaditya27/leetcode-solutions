class Solution:
    def moveZeroes(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        indices = []
        tracker = 0
        for i in range(len(nums)):
            if nums[i] == 0:
                indices.append(i)
        zero_count = len(indices)
        for j in range(zero_count):
            nums.pop(indices[j] - tracker)
            tracker += 1
        nums.extend([0 for k in range(zero_count)])
