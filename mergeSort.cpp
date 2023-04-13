#include<bits/stdc++.h>
// #include <iostream>
using namespace std;

void mergeSort(int a[], int b, int e);
void merge(int a[], int b, int mid, int e);

int main() {
    int n;
    
    cout<<"\n----MERGE SORT----\n"<<endl;
    cout<<"Enter size of array: ";
    cin>>n;
    
    int a[n];
    cout<<"Enter array elements: ";
    for(int i=0; i<n; i++) {
        cin>>a[i];
    }
    
    cout<<"Before Sort: ";
    for(int i=0; i<n; i++) {
        cout<<a[i]<<" ";
    }
    cout<<endl;
    
    mergeSort(a, 0, n-1);     //Merge sort
    
    cout<<"After Sort: ";
    for(int i=0; i<n; i++) {
        cout<<a[i]<<" ";
    }
    cout<<endl;
    
    
    return 0;
}


void mergeSort(int a[], int b, int e) { 
    int mid;
    if(b<e) {
        mid = (b+e)/2;
        mergeSort(a, b, mid);
        mergeSort(a, mid+1, e);
        merge(a, b, mid, e);
    }
}

void merge(int a[], int b, int mid, int e) {
    int i,j,k;
    int n1 = b+mid+1;    //beginnig to mid      
    int n2 = e-mid;    //mid+1 to end
    
    int left[n1], right[n2];
    for(int i=0; i<n1; i++) {
        left[i] = a[b+i];
    }
    
    for(int j=0; j<n2; j++) {
        right[j] = a[mid+1 + j];
    }
    
    i=0; j=0; k=b;
    
    while(i<n1 && j<n2) {
        if(left[i] > right[j]) {
            a[k] = right[j];
            k++;
            j++;
        }
        else {
            a[k] = left[i];
            k++;
            i++;
        }
    }
    
    //there might be extra elements, bcoz left[] & right[] may Not be of same size
    while(i<n1) {
        a[k] = left[i];
        i++;
        k++;
    }
    
    while(j<n2) {
        a[k] = right[j];
        j++;
        k++;
    }
}
