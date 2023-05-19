#include <bits/stdc++.h>
#include <iostream>

using namespace std;

void heapify(int a[], int n, int i);
void heapSort(int a[], int n);

int size=0;
int main() {
    int a[5]={5,4,3,2,1};
    int n = sizeof(a)/sizeof(a[0]);      //n=size
    heapSort(a, n);
    
    cout<<"Sorted array is\n";
    for(int i=0; i<n; i++) {
        cout<<a[i]<<" ";
    }
    cout<<endl;
    return 0;
}



// insert(int d, int a[]) {        //d = data
//     if(size==0) {   
//         a[size++] = d;          //for only 1 elmn we don't heapify
//     }
//     else {                     
//         a[size++] = d;
//         for(int i=size-1; i>0; i--) {       //size is starting from 1
//             heapify(a, size, i);            //must pass size even if global, or else it causes Segmentation fault
//         }
//     }
// }




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
        // int t=a[i];
        // a[i]=a[max];
        // a[max]=t;
        
        heapify(a,n,max);
    }
}

void heapSort(int a[], int n) {
    //build max heap
    for(int i=n/2-1; i>=0; i--) {    
        //to find parent node of child i=n/2-1, we only heapify Intermediate nodes, not leaf nodes
        heapify(a, n, i);
    }
    //heap sort
    for(int i=n-1; i>=0; i--) {
        swap(a[0], a[i]);       //swap is inbuilt in c++
        
        // Heapify root element to get highest element at root again
        heapify(a, i, 0);
    }
}
