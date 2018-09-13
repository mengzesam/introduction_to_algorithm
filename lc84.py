class Solution:
    def largestRectangleArea(self,heights):
        if (not(type(heights)==list)):
            return 0
        if (len(heights)==0):
            return 0
        if (type(heights[0])==list):
            return 0
        stack=[(-1,0)]
        ret=0
        for i,h in enumerate(heights+[0]):
            while (stack[-1][1]>h):
                right,height=stack.pop(-1)
                left=stack[-1][0]
                ret0=height*(i-1-left)
                ret=max(ret,ret0)
            stack.append((i,h))
        return ret


if __name__=="__main__":
    solution=Solution()
    heights=[2,1,5,6,2,3,2,3]
    maxArea=solution.largestRectangleArea(heights)
    print maxArea