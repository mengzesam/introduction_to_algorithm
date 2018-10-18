#include <stdio.h>
#include <sys/times.h>
#include <sys/types.h>
#include <unistd.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#define cmp(A, B)  (A < B)
#define maxN 200000000
#define THRESHOLD 16
typedef long itemType;

int cmp_proc(const void* a,const void* b);
void randArray(itemType a[], int N);
void copyArray(itemType a[], itemType b[], int N);
void call_qsort(itemType a[], int l, int r);
int partition(itemType a[],int l,int r);
void quickSort(itemType a[],int l,int r);
void hybridQuickSort(itemType a[],int l,int r);
void shellSort(itemType A[],int l,int r);
void shellSortIS(itemType a[], int l, int r);
void insertSort(itemType a[],int l,int r);
void maxHeapify(itemType A[],int l,int r,int i);
void buildMaxHeap(itemType A[],int l,int r);
void heapSort(itemType A[],int l,int r);
/**************/
long doit(void (*sortprog)(), itemType a[], int l, int r){
    int i; long t;
    struct tms t_start,t_end;
    clock_t start=times(&t_start);
    (*sortprog)(a, l, r);
    clock_t end=times(&t_end);
    long tps=sysconf(_SC_CLK_TCK);
    for (i = l; i < r; i++)  //checking if it is sorted
      if (cmp(a[i+1], a[i])) return -1;
    return (end-start)*1000/tps;
    //return (t_end.tms_utime-t_start.tms_utime+t_end.tms_stime-t_start.tms_stime)*1000/tps;
}
/**************/
int main(){ 
    itemType *a, *b;
    // itemType A[]={1,5,8,3,11,2,6,10,0,4,10,7,13,-1};
    // heapSort(A,0,13);
    // for(int i=0;i<14;i++)
    // printf("%ld\t",A[i]);
    int N;
    int c1=0, c2=0, c3=0, c4=0, c5=0, c6=0,c7=0;

    a =(itemType*)malloc(maxN*sizeof(itemType));
    b =(itemType*)malloc(maxN*sizeof(itemType));
    printf("         N        insert     heap        shell       shellIS  hybridquick  quick        qsort          \n");
    //printf("         N          1          2          3          4         5          6            7            \n");
    for (N = 10000; N <= maxN; N *= 2)
      {
        randArray(b, N);
        if(N<=80000)
            {copyArray(a, b, N); c1 = doit(insertSort, a, 0, N-1);}
        else
            c1=0;
        copyArray(a, b, N); c2 = doit(heapSort, a, 0, N-1);
        copyArray(a, b, N); c3 = doit(shellSort, a, 0, N-1);
        copyArray(a, b, N); c4 = doit(shellSortIS, a, 0, N-1);
        copyArray(a, b, N); c5 = doit(hybridQuickSort, a, 0, N-1);
        copyArray(a, b, N); c6 = doit(quickSort, a, 0, N-1);
        copyArray(a, b, N); c7 = doit(call_qsort, a, 0, N-1);
        printf("%10d %10d %10d %10d %10d %10d %10d %10d\n", N, c1, c2, c3, c4, c5, c6,c7);
      }
    return 0;
}
void randArray(itemType a[], int N){ 
    int i;
    srand48(time(NULL));
    for (i = 0; i < N; i++) a[i] = lrand48();//%N+1;
}
void copyArray(itemType a[], itemType b[], int N){
      int i;    
      for (i = 0; i < N; i++) { a[i] = b[i]; } 
}
int cmp_proc(const void* a,const void* b){
     return ( *(int*)a - *(int*)b );
}
void call_qsort(itemType a[], int l, int r){
    qsort(&a[l],r-l+1,sizeof(itemType),cmp_proc);
}
void insertSort(itemType a[],int l,int r){
    for(int i=l+1;i<=r;i++){
        itemType key=a[i];
        int j=i-1;
        while(j>=0 && cmp(key,a[j])){
            a[j+1]=a[j];
            j--;
        }
        a[j+1]=key;
    }
}
void shellSortIS(itemType a[], int l, int r){ 
    int incs[16] = { 1391376, 463792, 198768, 86961, 33936, 13776, 
                     4592, 1968, 861, 336, 112, 48, 21, 7, 3, 1 };
    int i, j, k, h, t; itemType v;

    for ( k = 0; k < 16; k++)
      for (h = incs[k], i = l+h; i <= r; i++)
        { 
          v = a[i]; j = i;
          while (j >= h && cmp(v, a[j-h]))
            { a[j] = a[j-h]; j -= h; }
          a[j] = v; 
        } 
}
int partition(itemType a[],int l,int r){
    ////TODO:相等元素的处理，避免O(n2);pivot选择随机数进行比较；
    //dualpivotquicksort（java jdk1.7库的sort研究）
    itemType pivot;
    if(r-l+1>=27){
        //三取中:
        int mid=l+(r-l)/2;
        if(a[mid]<a[l]){
            pivot=a[mid];
            a[mid]=a[l];
            a[l]=pivot;
        }
        if(a[r]<a[l]){
            pivot=a[r];
            a[r]=a[l];
            a[l]=pivot;
        }    
        if(a[mid]<a[r]){
            pivot=a[mid];
            a[mid]=a[r];
            a[r]=pivot;
        }
    }//三取中    
    pivot=a[r];
    int i=l-1;
    int j=l;
    while(j<r){
        if(cmp(a[j],pivot)){
            i++;
            //if(i!=j){
                itemType tmp=a[i];
                a[i]=a[j];
                a[j]=tmp;
            //}
        }
        j++;
    }
    //if(i+1!=r){
        itemType tmp=a[i+1];
        a[i+1]=a[r];
        a[r]=tmp;
    //}
    return i+1;
}
void quickSort(itemType a[],int l,int r){
    while(l<r){
        int q=partition(a,l,r);
        quickSort(a,l,q-1);
        l=q+1;
    }
}
void hybridQuickSort(itemType a[],int l,int r){
    if(r-l+1<=THRESHOLD){
        insertSort(a,l,r);
        return;
    }
    while(l<r){
        int q=partition(a,l,r);
        hybridQuickSort(a,l,q-1);
        l=q+1;
    }
}
void shellSort(itemType A[],int l,int r){
  /*
    递增序列采用表格方式给出，其倒序为1，4，13，40，121，364...
    递增训练的构造还有其他，可参考
    http://www.cs.princeton.edu/~rs/shell/driver.c
    和
    http://www.cs.princeton.edu/~rs/shell/paperF.pdf
    */
    if(r-l+1<=1) return;
    int incs[]={1743392200,581130733,193710244,64570081,21523360,7174453,2391484,
                797161,265720,88573,29524,9841,3280,1093,364,121,40,13,4,1};
    int k=0;
    int u=19;
    while(k<=u){
        int mid=k+(u-k)/2;
        if((r-l+1)>incs[mid])
            u=mid-1;
        else
            k=mid+1;
    }
    for(;k<20;k++){
        int h=incs[k];
        for(int i=l+h;i<=r;i++){
            itemType key=A[i];
            int j=i-h;
            while(0<=j && cmp(key,A[j])){
                A[j+h]=A[j];
                j-=h;
            }
            A[j+h]=key;
        }
    }    
}
void maxHeapify(itemType A[],int l,int r,int i){
    /*
        shiftDown
    */
    if(i<l || i>r) return;
    int root=i;
    int largest=root;
    int left=root-l+root+1;
    int right=root-l+root+2;
    if(right<=r && cmp(A[root],A[right]))
        largest=right;
    if(left<=r && cmp(A[largest],A[left]))
        largest=left;
    while(largest!=root){
        itemType tmp=A[root];
        A[root]=A[largest];
        A[largest]=tmp;
        root=largest;
        left=root-l+root+1;
        right=root-l+root+2;
        if(right<=r && cmp(A[root],A[right]))
            largest=right;
        if(left<=r && cmp(A[largest],A[left]))
            largest=left;
    }
}
void buildMaxHeap(itemType A[],int l,int r){
    for(int i=l-1+(r-l+1)/2;i>=l;i--)
        maxHeapify(A,l,r,i);
}
void heapSort(itemType A[],int l,int r){
    if(l==r) return;
    buildMaxHeap(A,l,r);
    int end=r;
    while(end>l){
        itemType tmp=A[end];
        A[end]=A[l];
        A[l]=tmp;
        end--;
        maxHeapify(A,l,end,l);
    }
}