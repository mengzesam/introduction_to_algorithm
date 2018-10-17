#include <stdio.h>
void insertSort(int A[],int n);
void insertSort2(int A[],int n);
void selectSort(int A[],int n);
void bubbleSort(int A[],int n);
void shellSort(int A[],int n);
void shellSort2(int A[],int n);

int main(){
    int A[]={1,5,8,3,11,2,6,10,0,4,10,7,13,-1};
    int n=14;
    shellSort2(A,n);
    for(int i=0;i<n;i++)
        printf("%d\t",A[i]);
    //printf("%d\n",1%0);
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
        int no_swapped=1;
        for(int j=n-1;j>=i;j--)
            if(A[j-1]>A[j]){
                int tmp=A[j];
                A[j]=A[j-1];
                A[j-1]=tmp;
                no_swapped=0;
            }
        if(no_swapped)
            break;
    }
}
void shellSort(int A[],int n){
/*
    递增序列实时产生（另一种方法是将其存于表格）
    递增序列：1/2（3^k-1),其中k=1,2，3，....,即1,4,13,40...  
    https://algs4.cs.princeton.edu/21elementary/Shell.java.html
    作者Robert Sedgewick主页代码(上述网址)：
    while(h<n/3)
    然后把
    h/=3;
    放在第二个while的最后
    这个代码存在一点缺陷，即如果诸如n=14（或者41、122）时，h是从4->1,而不是13->4->1
    现改进为 
    while(h<n)
    把h/=3;放在第二个while循环开始
    同时代码中的插入排序部分不采用 Robert Sedgewick的写法，而是算法导论中写法，减少交换次数
*/
    int h=1;
    while(h<n)
        h=3*h+1;
    while(1<=h){
        h/=3;
        for(int i=h;i<n;i++){
            int key=A[i];
            int j=i-h;
            while(0<=j && key<A[j]){
                A[j+h]=A[j];
                j-=h;
            }
            A[j+h]=key;
        }
    }    
}
void shellSort2(int A[],int n){
/*
    递增序列采用表格方式给出，其倒序为1，4，13，40，121，364...
    递增训练的构造还有其他，可参考
    http://www.cs.princeton.edu/~rs/shell/driver.c
    和
    http://www.cs.princeton.edu/~rs/shell/paperF.pdf
*/
    if(n<=1) return;
    int incs[]={1743392200,581130733,193710244,64570081,21523360,7174453,2391484,
                797161,265720,88573,29524,9841,3280,1093,364,121,40,13,4,1};
    int k=0,r=19;
    while(k<=r){
        int mid=(k+r)/2;
        if(n>incs[mid])
            r=mid-1;
        else
            k=mid+1;
    }
    for(;k<20;k++){
        int h=incs[k];
        for(int i=h;i<n;i++){
            int key=A[i];
            int j=i-h;
            while(0<=j && key<A[j]){
                A[j+h]=A[j];
                j-=h;
            }
            A[j+h]=key;
        }
    }    
}