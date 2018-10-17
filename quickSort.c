#include <stdio.h>
#include <sys/times.h>
#include <sys/types.h>
#include <unistd.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#define cmp(A, B)  (A < B)
#define maxN 128000000
#define THRESHOLD 16
typedef int itemType;

void randArray(itemType a[], int N){ 
    int i;
    srand48(time(NULL));
    for (i = 0; i < N; i++) a[i] = lrand48();//%N+1;
  }

void copyArray(itemType a[], itemType b[], int N){
      int i;    
      for (i = 0; i < N; i++) { a[i] = b[i]; } 
  }

int cmp2(const void* a,const void* b){
     return ( *(int*)a - *(int*)b );
  }

void call_qsort(itemType a[], int l, int r){
    qsort(&a[l],r-l+1,sizeof(itemType),cmp2);
  }

void quickSort(itemType a[],int l,int r);
void hybridQuickSort(itemType a[],int l,int r);
void shellsortIS(itemType a[], int l, int r);
void insertSort(itemType a[],int l,int r);
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
int main()
  { 
    itemType *a, *b;
    int N;
    int c1=0, c2=0, c3=0, c4=0, c5=0, c6=0,c7=0;

    a =(itemType*)malloc(maxN*sizeof(itemType));
    b =(itemType*)malloc(maxN*sizeof(itemType));

    printf("         N          1          2          3          4          5          6          qsort          \n");
    for (N = 6400000; N <= maxN; N *= 2)
      {
        randArray(b, N);
        copyArray(a, b, N); c3 = doit(insertSort, a, 0, N-1);
        copyArray(a, b, N); c4 = doit(shellsortIS, a, 0, N-1);
        copyArray(a, b, N); c5 = doit(hybridQuickSort, a, 0, N-1);
        copyArray(a, b, N); c6 = doit(quickSort, a, 0, N-1);
        copyArray(a, b, N); c7 = doit(call_qsort, a, 0, N-1);
        printf("%10d %10d %10d %10d %10d %10d %10d %10d\n", N, c1, c2, c3, c4, c5, c6,c7);
      }
    return 0;
  }

int partition(itemType a[],int l,int r){
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

void shellsortIS(itemType a[], int l, int r){ 
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