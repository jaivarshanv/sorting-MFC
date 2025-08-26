#include <stdio.h>

int cmp1 = 0; 
int cmp2 = 0;

void printArr(int a[], int n) {
    int i;
    for(i=0;i<n;i++){
        printf("%d ", a[i]);
    }
    printf("\n");
}

void swap(int *x, int *y){
    int t = *x;
    *x = *y;
    *y = t;
}

int partLast(int a[], int l, int h){
    int piv = a[h];
    int i = l-1;
    int j;
    for(j=l;j<h;j++){
        cmp1++;
        if(a[j]<=piv){
            i++;
            swap(&a[i], &a[j]);
        }
    }
    swap(&a[i+1], &a[h]);
    return i+1;
}

void qSortLast(int a[], int l, int h, int n){
    if(l<h){
        int pi = partLast(a,l,h);
        printf("Partition using pivot %d -> ", a[pi]);
        printArr(a,n);
        printf("Subarray calls: [%d..%d], [%d..%d]\n", l, pi-1, pi+1, h);
        qSortLast(a,l,pi-1,n);
        qSortLast(a,pi+1,h,n);
    }
}

int medianOfThree(int a[], int l, int h){
    int m = (l+h)/2;
    if(a[l]>a[m]) swap(&a[l], &a[m]);
    if(a[l]>a[h]) swap(&a[l], &a[h]);
    if(a[m]>a[h]) swap(&a[m], &a[h]);
    swap(&a[m], &a[h]);
    return a[h];
}

int partMedian(int a[], int l, int h){
    int piv = medianOfThree(a,l,h);
    int i=l-1;
    int j;
    for(j=l;j<h;j++){
        cmp2++;
        if(a[j]<=piv){
            i++;
            swap(&a[i],&a[j]);
        }
    }
    swap(&a[i+1],&a[h]);
    return i+1;
}

void qSortMedian(int a[], int l, int h, int n){
    if(l<h){
        int pi=partMedian(a,l,h);
        qSortMedian(a,l,pi-1,n);
        qSortMedian(a,pi+1,h,n);
    }
}

int main(){
    int n,i;
    printf("Enter n: ");
    scanf("%d",&n);
    int a[n],b[n];
    printf("Enter %d numbers:\n",n);
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
        b[i]=a[i];
    }
    printf("\n--- Quick Sort (Last Pivot) ---\n");
    qSortLast(a,0,n-1,n);
    printf("Sorted array: ");
    printArr(a,n);
    printf("Total comparisons: %d\n", cmp1);

    printf("\n--- Quick Sort (Median of Three) ---\n");
    qSortMedian(b,0,n-1,n);
    printf("Sorted array: ");
    printArr(b,n);
    printf("Total comparisons: %d\n", cmp2);
    return 0;
}
