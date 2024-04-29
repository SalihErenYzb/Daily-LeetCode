class Solution:
    def minOperations(self, nums: List[int], k: int) -> int:
        a = 0
        for i in nums:
            a = a ^ i
        a = a ^ k
        count = 0
        while a != 0:
            count += a%2
            a = a//2
        return count
        