#include <stdio.h>
void insertSort(int A[],int n);
void insertSort2(int A[],int n);
void selectSort(int A[],int n);
void bubbleSort(int A[],int n);

int main(){
    int A[]={1,5,8,3,11,2,6,10,0,4,10,7};
    int n=12;
    bubbleSort(A,n);
    for(int i=0;i<n;i++)
        printf("%d\t",A[i]);
    printf("bubble\n");
    return 0;
}

void insertSort(int A[],int n){//算法导论
    for(int i=1;i<n;i++){
        int key=A[i];
        int j=i-1;
        while(j>=0 && key<A[j]){
            A[j+1]=A[j];
            j--;
        }
        A[j+1]=key;
    }
}
void insertSort2(int A[],int n){//算法（algorithms 4th），相比算法导论的，要经常交换相轮两个
    for(int i=1;i<n;i++)
        for(int j=i;j>0 && A[j]<A[j-1];j--){
            int tmp=A[j];
            A[j]=A[j-1];
            A[j-1]=tmp;
        }
}
void selectSort(int A[],int n){
    for(int i=0;i<n-1;i++){
        int k=i;
        for(int j=i+1;j<n;j++){
            if(A[j]<A[k])
                k=j;
        }
        if(k!=i){
            int tmp=A[k];
            A[k]=A[i];
            A[i]=tmp;
        }
    }
}
void bubbleSort(int A[],int n){
    for(int i=1;i<n;i++){
        int swapped=0;
        for(int j=n-1;j>=i;j--)
            if(A[j-1]>A[j]){
                int tmp=A[j];
                A[j]=A[j-1];
                A[j-1]=tmp;
                swapped=1;
            }
        if(!swapped)
            break;
    }
}