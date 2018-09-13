class QUICKSORT:
    def Partition(self,A,p,r):
        i=p-1
        for j in range(p,r):#p,p+1,...,r-1
            if(A[j]<=A[r]):
                i+=1
                if(i!=j):
                    tmp=A[j]
                    A[j]=A[i]
                    A[i]=tmp
        if(i+1!=r):
            tmp=A[r]
            A[r]=A[i+1]
            A[i+1]=tmp
        return i+1

    def randomizedPation(self,A,p,r):
        import random
        i=random.randint(p,r)
        if(i!=r):
            tmp=A[i]
            A[i]=A[r]
            A[r]=tmp
        return self.Partition(A,p,r)

    def quickSort(self,A,p,r):
        if(p<r):
            q=self.Partition(A,p,r)
            self.quickSort(A,p,q-1)
            self.quickSort(A,q+1,r)
    
    def tailRecursiveQuickSort(self,A,p,r):
        while(p<r):
            #Partition and sort left subarray
            q=self.Partition(A,p,r)
            self.tailRecursiveQuickSort(A,p,q-1)
            p=q+1    

    def randomTailRecursiveQuickSort(self,A,p,r):
        while(p<r):
            #Partition and sort left subarray
            q=self.randomizedPation(A,p,r)
            self.randomTailRecursiveQuickSort(A,p,q-1)
            p=q+1    

    def Solution(self,A):
        if(type(A)!=list):
            return -1
        n=len(A)
        if(n==0):
            return -1
        #self.quickSort(A,0,n-1)
        #self.tailRecursiveQuickSort(A,0,n-1)
        self.randomTailRecursiveQuickSort(A,0,n-1)
        return 0

if __name__=='__main__':
    A=[8,3,9,12,11,3,10,1,7,13,6,4,2,5,11]
    quick_sort=QUICKSORT()
    quick_sort.Solution(A)
    print A


