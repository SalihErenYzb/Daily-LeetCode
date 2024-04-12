class Solution:
    def trap(self, height: List[int]) -> int:
        ans = 0
        max1 = height[0]
        temp = 0
        for hei in height[1:]:

            if hei >= max1:
                max1 = hei
                ans += temp
                temp = 0
            print(hei,abs(hei-max1))
            temp += abs(hei-max1)
        height= list(reversed(height))
        max1 = height[0]
        temp = 0
        for hei in height[1:]:

            if hei > max1:
                max1 = hei
                ans += temp
                temp = 0
            print(hei,abs(hei-max1))

            temp += abs(hei-max1)
        return ans
        




