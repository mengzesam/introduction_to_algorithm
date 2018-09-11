class HEAPSORT:
    def __init__(self,A):
        self.length=0
        self.status=False
        if (type(A)!=list):
            return        
        self.length=len(A)
        if (self.length==0):
            return
        self.A=[]
        for val in A:
            self.A.append(val)
        self.status=True
        self.heap_size=self.length

    def Left(self,i):
        return 2*i+1

    def Right(self,i):
        return 2*(i+1)

    def Parent(self,i):
        return int((i-1)/2)

    def maxHeapify(self,i):
        l=self.Left(i)
        r=self.Right(i)
        largest=0
        if (l<self.heap_size and self.A[l]>self.A[i]):
            largest=l
        else:
            largest=i
        if(r<self.heap_size and self.A[r]>self.A[largest]):
            largest=r
        if (largest!=i):
            tmp=self.A[i]
            self.A[i]=self.A[largest]
            self.A[largest]=tmp
            self.maxHeapify(largest)

    def buildMaxHeap(self):
        mid=int(self.heap_size/2)
        for i in range(mid-1,-1,-1):
            self.maxHeapify(i)

    def heapSort(self):
        self.buildMaxHeap()
        for i in range(self.length-1,0,-1):
            tmp=self.A[0]
            self.A[0]=self.A[i]
            self.A[i]=tmp
            self.heap_size-=1
            self.maxHeapify(0)
        self.heap_size=self.length



if __name__=='__main__':
    A=[16,14,10,8,7,9,3,2,4,1]
    heap_sort=HEAPSORT(A)
    heap_sort.heapSort()
    print heap_sort.A
    print A
