class MAXSUBARRAY:
    def findMaxCrossingSubarray(self,A,low,mid,high):
        left_sum=-1e10 # as negative infinity
        sum_i=0
        for i in range(mid,low-1,-1):# [mid,mid-1,...,low+1,low]
            sum_i+=A[i]
            if(sum_i>left_sum):
                left_sum=sum_i
                max_left=i
        right_sum=-1e10 # as negative infinity
        sum_i=0
        for j in range(mid+1,high+1):# [mid,mid+1,...,high-1,high]
            sum_i+=A[j]
            if(sum_i>right_sum):
                right_sum=sum_i
                max_right=j
        return (max_left,max_right,left_sum+right_sum)
    
    def findMaxSubarray(self,A,low,high):
        if(high==low):
            return (low,high,A[low])
        else:
            mid=int((low+high)/2)
            left_low,left_high,left_sum=self.findMaxSubarray(A,low,mid)
            right_low,right_high,right_sum=self.findMaxSubarray(A,mid+1,high)
            cross_low,cross_high,cross_sum=self.findMaxCrossingSubarray(A,low,mid,high)
            if(left_sum>=right_sum and left_sum>=cross_sum):
                return (left_low,left_high,left_sum)
            elif(cross_sum>=left_sum and cross_sum>=right_sum):
                return (cross_low,cross_high,cross_sum)
            else:
                return (right_low,right_high,right_sum)

    def Solution(self,A):
        if(type(A)!=list):
            return (-1,-1,-1e10)
        n=len(A)
        if(n==0):
            return (-1,-1,-1e10)
        from_i,to_i,sum_i=self.findMaxSubarray(A,0,n-1)
        return (from_i,to_i,sum_i)



if __name__=='__main__':
    max_subarray=MAXSUBARRAY()
    A=[13,-3,-25,20,-3,-16,-23,18,20,-7,12,-5,22,15,-4,7]
    #A=[1,-2,3]
    from_i,to_i,sum_i=max_subarray.Solution(A)
    print from_i,to_i,sum_i