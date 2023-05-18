#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main()
{
    int arr[10] = {100,100,50,50,25,25,20,10,10,5};
    int select[10];
    int capacity=175;
    int notSelect[10];
    int notVisited[10];
    
    //selected 
    //not selected
    //remaining not visited         neither select nor notSelect
    
    int sum=0; 
    int a=0;
    int b=0;
    int c=0;
    int remaining = capacity;
    for(int i=0;i<10;i++) {
        if(capacity>=sum+arr[i]) {
            sum=sum+arr[i];
            select[a]=arr[i];
            a++;
            remaining = remaining-arr[i];
        }
        else if(remaining==0) {
            notVisited[c] = arr[i];
            c++;
        }
        else {
            notSelect[b] = arr[i];
            b++;
        }
    }
    
    
    
    cout<<"Selected: ";
    for(int i=0; i<a; i++) {
        cout<<select[i]<<" ";
    }
    cout<<endl;
    
    cout<<"Not Selected: ";
    for(int i=0; i<b; i++) {
        cout<<notSelect[i]<<" ";
    }
    cout<<endl;
    
    cout<<"Not Visited: ";
    for(int i=0; i<c; i++) {
        cout<<notVisited[i]<<" ";
    }
    cout<<endl;
    
    return 0;
}
