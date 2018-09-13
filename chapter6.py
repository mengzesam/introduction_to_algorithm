class MAXHEAP:
    sentinel_minus=-1e10
    def __init__(self,A):
        self.length=0
        self.isBuild=False
        if(type(A)!=list):
            return        
        self.length=len(A)
        if(self.length==0):
            return
        self.A=A
        # for val in A:
        #     self.A.append(val)
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
        if(l<self.heap_size and self.A[l]>self.A[i]):
            largest=l
        else:
            largest=i
        if(r<self.heap_size and self.A[r]>self.A[largest]):
            largest=r
        if(largest!=i):
            tmp=self.A[i]
            self.A[i]=self.A[largest]
            self.A[largest]=tmp
            self.maxHeapify(largest)

    def buildMaxHeap(self):
        mid=int(self.heap_size/2)
        for i in range(mid-1,-1,-1):
            self.maxHeapify(i)
        self.isBuild=True

    def heapSort(self):
        self.buildMaxHeap()
        for i in range(self.length-1,0,-1):
            tmp=self.A[0]
            self.A[0]=self.A[i]
            self.A[i]=tmp
            self.heap_size-=1
            self.maxHeapify(0)
        self.heap_size=self.length
    
    def heapMaximum(self):
        """         max-priority queue maximum """
        if(not self.isBuild):
            self.buildMaxHeap()
        return self.A[0]
    
    def heapExtractMax(self):
        """         max-priority queue"""
        if(self.heap_size<1):
            print "error:heap underflow"
            return self.sentinel_minus
        if(not self.isBuild):
            print "max heap is not built"
            return self.sentinel_minus
        heap_max=self.A[0]
        self.A[0]=self.A[self.heap_size-1]
        self.A[self.heap_size-1]=heap_max
        self.heap_size-=1
        self.maxHeapify(0)
        return heap_max

    def heapIncreaseKey(self,i,key):
        if(not self.isBuild):
            print "max heap is not built"
            return -1
        if(key<=self.A[i]):
            print "new key is not larger than current key"
            return -1
        self.A[i]=key
        while(i>0 and self.A[self.Parent(i)]<self.A[i]):
            tmp=self.A[i]
            self.A[i]=self.A[self.Parent(i)]
            self.A[self.Parent(i)]=tmp
            i=self.Parent(i)
        return 0
        
    def maxHeapInsert(self,key):
        if(not self.isBuild):
            self.buildMaxHeap()
        self.heap_size+=1
        if(self.heap_size<=len(self.A)):
            self.A[self.heap_size-1]=self.sentinel_minus
        else:
            self.A.append(self.sentinel_minus)
            self.length=len(self.A)
        self.heapIncreaseKey(self.heap_size-1,key)

        









if __name__=='__main__':
    A=[16,14,10,8,7,9,3,2,100,4,1]
    max_heap=MAXHEAP(A)
    #heap_sort.heapSort()
    max_heap.buildMaxHeap()
    print max_heap.heapExtractMax()
    

