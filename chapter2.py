class BUBBLESORT:
    def Solution(self,A):
        if (type(A)!=list):
            return -1
        n=len(A)
        if (n==0):
            return -1
        for i in range(n-1,0,-1):
            for j in range(0,i):
                if (A[j]>A[j+1]):
                    tmp=A[j]
                    A[j]=A[j+1]
                    A[j+1]=tmp
        return 0
    def Solution2(self,A):
        if (type(A)!=list):
            return -1
        n=len(A)
        if (n==0):
            return -1
        for i in range(n-1):
            for j in range(n-1,i,-1):
                if (A[j-1]>A[j]):
                    tmp=A[j-1]
                    A[j-1]=A[j]
                    A[j]=tmp
        return 0


if __name__=='__main__':
    bubble_sort=BUBBLESORT()
    A=[16,14,10,8,7,9,3,2,4,1]
    bubble_sort.Solution2(A)
    print A
