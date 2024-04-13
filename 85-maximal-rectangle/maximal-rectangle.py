class Solution:
    def maximalRectangle(self, matrix: List[List[str]]) -> int:
        heights = [0]*(len(matrix[0])+1)
        maxa = 0
        for row in matrix:
            for k in range(len(row)):
                heights[k] = heights[k]+1 if row[k]=="1" else 0
            stack = []
            for i in range(len(heights)):
                hei = heights[i]
                start = i
                while stack and stack[-1][1] > hei:
                    topi,toph = stack.pop()
                    maxa = max(maxa,(i-topi)*toph)
                    start = topi
                stack.append((start,hei))     
        return maxa
