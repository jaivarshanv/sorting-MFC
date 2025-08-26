#include <stdio.h>

long long cmp=0;
long long inv=0;

void printArr(int a[], int n){
    int i;
    for(i=0;i<n;i++){
        printf("%d ",a[i]);
    }
    printf("\n");
}

void merge(int a[], int l, int m, int r){
    int n1 = m-l+1;
    int n2 = r-m;
    int L[n1],R[n2];
    int i,j,k;
    for(i=0;i<n1;i++) L[i]=a[l+i];
    for(j=0;j<n2;j++) R[j]=a[m+1+j];
    i=0;j=0;k=l;
    printf("Merging [");
    for(int x=0;x<n1;x++) printf("%d ",L[x]);
    printf("] and [");
    for(int y=0;y<n2;y++) printf("%d ",R[y]);
    printf("] -> ");

    while(i<n1 && j<n2){
        cmp++;
        if(L[i]<=R[j]){
            a[k]=L[i];
            i++;
        }else{
            a[k]=R[j];
            j++;
            inv += (n1 - i);
        }
        k++;
    }
    while(i<n1){
        a[k]=L[i];
        i++;k++;
    }
    while(j<n2){
        a[k]=R[j];
        j++;k++;
    }
    printArr(a,r-l+1);
}

void mergeSort(int a[], int l, int r){
    if(l<r){
        int m=(l+r)/2;
        mergeSort(a,l,m);
        mergeSort(a,m+1,r);
        merge(a,l,m,r);
    }
}

int main(){
    int n,i;
    printf("Enter n: ");
    scanf("%d",&n);
    int a[n];
    printf("Enter %d numbers:\n",n);
    for(i=0;i<n;i++) scanf("%d",&a[i]);
    mergeSort(a,0,n-1);
    printf("\nSorted array: ");
    printArr(a,n);
    printf("Total comparisons: %lld\n",cmp);
    printf("Total inversions: %lld\n",inv);
    return 0;
}
