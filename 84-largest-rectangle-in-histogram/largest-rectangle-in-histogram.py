class Solution:
    def largestRectangleArea(self, heights: List[int]) -> int:
        heights = heights + [0]
        stack = []
        maxa = 0
        for i in range(len(heights)):
            hei = heights[i]
            start = i
            while stack and stack[-1][1] > hei:
                topi,toph = stack.pop()
                maxa = max(maxa,(i-topi)*toph)
                start = topi
            stack.append((start,hei))
        return maxa




        