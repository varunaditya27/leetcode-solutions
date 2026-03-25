class Solution:
    def pickGifts(self, gifts: List[int], k: int) -> int:
        for i in range(k):
            max_term = gifts[0]
            max_index = 0
            for j in range(len(gifts)):
                if gifts[j] > max_term:
                    max_term = gifts[j]
                    max_index = j
            gifts[max_index] = int((max_term ** 0.5)//1)
        return sum(gifts)
