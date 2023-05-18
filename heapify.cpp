#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int size=0;
int main() {
    a[5]={5,4,3,2,1};
    
    cout<<"";

    return 0;
}



insert(int d, int a[]) {        //d = data
    if(size==0) {   
        a[size++] = d;          //for only 1 elmn we don't heapify
    }
    else {                     
        a[size++] = d;
        for(int i=size-1; i>0; i--) {       //size is starting from 1
            heapify(a, size, i);            //must pass size even if global, or else it causes Segmentation fault
        }
    }
}




heapify(int a[]. int size, int i) {
    int max = i;            //max elmnt indx
    int l = 2*max+1;        //left index
    int r = 2*max+2;
    if(l<=size && a[max]<a[l]) {
        max=l;
    }
    if(r<=size && a[max]<a[r]) {
        max=r;
    }
    
    if(max!=i) {
        // swap(a[i], a[max]);
        int t=a[i];
        a[i]=a[max];
        a[max]=t;
        
        heapify(a,size,max);
    }
}
