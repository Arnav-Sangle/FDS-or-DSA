#include <bits/stdc++.h>
#include <iostream>

using namespace std;

void buildMaxHeap(int a[], int n);
void heapify(int a[], int n, int i);
void heapSort(int a[], int n);


int main() {
    int a[5]={5,4,3,2,1};
    int n = sizeof(a)/sizeof(a[0]);      //n=size
    heapSort(a,n);
    
    cout<<"Sorted array is\n";
    for(int i=0; i<n; i++) {
        cout<<a[i]<<" ";
    }
    cout<<endl;
    return 0;
}




void buildMaxHeap(int a[], int n) {
    for(int i=n/2-1; i>=0; i--) {    
        //to find parent node of child i=n/2-1, we only heapify Intermediate nodes, not leaf nodes
        heapify(a, n, i);
    }
}

void heapify(int a[], int n, int i) {     //making max heap
    int max = i;            //root indx
    int l = 2*max+1;        //left child index
    int r = 2*max+2;        //right child index
    
    if(l<n && a[l]>a[max]) {
        max=l;
    }
    if(r<n && a[r]>a[max]) {
        max=r;
    }
    
    if(max!=i) {
        swap(a[i], a[max]);     //swap is inbuilt in c++
        heapify(a,n,max);
    }
}

void heapSort(int a[], int n) {
    buildMaxHeap(a, n);
    
    //heap sort
    for(int i=n-1; i>=0; i--) {
        swap(a[0], a[i]);       //swap is inbuilt in c++
        
        // Heapify root element to get highest element at root again
        heapify(a, i, 0);       //we are decreasing size of array as it gets sorted
    }
}
