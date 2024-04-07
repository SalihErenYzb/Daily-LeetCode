class Solution:
    def checkValidString(self, s: str) -> bool:
        stack = []
        for c in s:
            if c == ")":
                if not stack:
                    return 0
                else:
                    try:
                        k = stack[::-1].index("(") 
                        stack.pop(len(stack)-1-k)
                    except:
                        stack.pop()
            else:
                stack.append(c)
        num = 0
        for c in stack:
            if c == "(":
                num +=1
            if num and c == "*":
                num -=1
        return num==0