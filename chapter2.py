class INSERTSORT:
    def Solution(self,A):
        if(type(A)!=list):
            return -1
        n=len(A)        
        if(n==0):
            return -1
        for i in range(1,n):
            key=A[i]
            j=i-1
            while j>=0 and A[j]>key:
                A[j+1]=A[j]
                j=j-1
            A[j+1]=key
        return 0

class MERGESORT:
    def Merge(self,A,p,q,r):
        if not (p<=q and q<r):
            print "p,q,r must be p<=q<r"
            return -1
        sentinel=1e10 #as infinity
        n1=q-p+1
        n2=r-q
        L=[0]*(n1+1)
        R=[0]*(n2+1)
        for i in range(n1):
            L[i]=A[p+i]
        for j in range(n2):
            R[j]=A[q+1+j]
        L[n1]=sentinel
        R[n2]=sentinel
        i=0
        j=0
        for k in range(p,r+1):
            if(L[i]<=R[j]):
                A[k]=L[i]
                i+=1
            else:
                A[k]=R[j]
                j+=1
        return 0

    def MergeSort(self,A,p,r):
        if(p<r):
            q=int((p+r)/2)
            self.MergeSort(A,p,q)
            self.MergeSort(A,q+1,r)
            self.Merge(A,p,q,r)
               
    def Solution(self,A):
        if(type(A)!=list):
            return -1
        n=len(A)        
        if(n==0):
            return -1
        self.MergeSort(A,0,n-1)
        return 0

class BUBBLESORT:
    def Solution(self,A):
        if(type(A)!=list):
            return -1
        n=len(A)     
        if(n==0):
            return -1
        for i in range(n-1,0,-1):
            for j in range(i):
                if(A[j]>A[j+1]):
                    tmp=A[j]
                    A[j]=A[j+1]
                    A[j+1]=tmp
        return 0




if __name__=='__main__':
    insert_sort=INSERTSORT()
    A=[5,2,4,1,6,1,7,3]
    insert_sort.Solution(A)
    print A
    merger_sort=MERGESORT()
    A=[8,3,9,12,11,3,10,1,7,13,6,4,2,5,11]
    merger_sort.Solution(A)
    print A
    A=[8,3,9,12,11,3,10,1,7,13,6,4,2,5,11]
    bubble_sort=BUBBLESORT()
    bubble_sort.Solution(A)
    print A

