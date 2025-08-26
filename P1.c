#include <stdio.h>

int c1=0,c2=0;

void s(int *x,int *y){int t=*x;*x=*y;*y=t;}

void p(int a[],int n){
    for(int i=0;i<n;i++)printf("%d ",a[i]);
    printf("\n");
}

int part1(int a[],int l,int h){
    int p=a[h],i=l-1;
    for(int j=l;j<h;j++){
        c1++;
        if(a[j]<=p){i++;s(&a[i],&a[j]);}
    }
    s(&a[i+1],&a[h]);
    return i+1;
}

void q1(int a[],int l,int h,int n){
    if(l<h){
        int pi=part1(a,l,h);
        printf("Pivot %d -> ",a[pi]);p(a,n);
        q1(a,l,pi-1,n);
        q1(a,pi+1,h,n);
    }
}

int med3(int a[],int l,int h){
    int m=(l+h)/2;
    if(a[l]>a[m])s(&a[l],&a[m]);
    if(a[l]>a[h])s(&a[l],&a[h]);
    if(a[m]>a[h])s(&a[m],&a[h]);
    s(&a[m],&a[h]);
    return a[h];
}

int part2(int a[],int l,int h){
    int p=med3(a,l,h),i=l-1;
    for(int j=l;j<h;j++){
        c2++;
        if(a[j]<=p){i++;s(&a[i],&a[j]);}
    }
    s(&a[i+1],&a[h]);
    return i+1;
}

void q2(int a[],int l,int h){
    if(l<h){
        int pi=part2(a,l,h);
        q2(a,l,pi-1);
        q2(a,pi+1,h);
    }
}

int main(){
    int n;printf("n: ");scanf("%d",&n);
    int a[n],b[n];
    for(int i=0;i<n;i++){scanf("%d",&a[i]);b[i]=a[i];}
    printf("\n-- Quick Sort (Last Pivot) --\n");
    q1(a,0,n-1,n);printf("Sorted: ");p(a,n);
    printf("Comparisons: %d\n",c1);

    printf("\n-- Quick Sort (Median 3) --\n");
    q2(b,0,n-1);printf("Sorted: ");p(b,n);
    printf("Comparisons: %d\n",c2);
    return 0;
}
