class COUNTINGSORT:
    '''input array A,which element must be >=0
    '''
    def countingSort(self,A,B,k):
        if(type(A)!=list or type(B)!=list):
            return -1
        n=len(A)
        m=len(B)
        if(n==0 or n!=m or k<0):
            return -1
        C=[0]*(k+1)
        for i in range(n):
            C[A[i]]+=1
        #C[i] now contains the number of elements equal to i
        for i in range(1,k+1):
            C[i]+=C[i-1]
        #C[i] now contains the number of elements less than or equal to i
        for j in range(n-1,-1,-1):
            B[C[A[j]-1]]=A[j]
            C[A[j]]-=1 #A[j] might not be distinct, Decrementing C[A[j]] for the next the element
                    #equal to A[j], if one exists, put it immediately before A[j] in the output array.

        
    def Solution(self,A,B):
        if(type(A)!=list or type(B)!=list):
            return -1
        n=len(A)
        m=len(B)
        if(n==0 or n!=m):
            return -1
        k=max(A)
        self.countingSort(A,B,k)
        return 0

if __name__=='__main__':
    A=[8,3,9,12,11,3,10,1,7,13,6,4,2,5,11]
    B=[0]*(len(A))
    couting_sort=COUNTINGSORT()
    couting_sort.Solution(A,B)
    print B


