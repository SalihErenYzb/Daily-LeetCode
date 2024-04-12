class Solution:
    def trap(self, height) -> int:
        ans = 0
        max1 = [height[0],height[-1]]
        temp = [0,0]
        for i in range(1,len(height)):
            hei = [height[i],height[-i-1]]
            if hei[0] >= max1[0]:
                max1[0] = hei[0]
                ans += temp[0]
                temp[0] = 0
            if hei[1] > max1[1]:
                max1[1] = hei[1]
                ans += temp[1]
                temp[1] = 0
            temp[0] += abs(hei[0]-max1[0])
            temp[1] += abs(hei[1]-max1[1])
        return ans
        




