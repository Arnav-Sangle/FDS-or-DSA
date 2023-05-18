#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main()
{
    int arr[10] = {100,10,50,50,25,25,20,10,10,5};
    int select[10];
    int capacity=175;
    int visited[10];
    
    int a=0; 
    int b=0;
    int k=0;
    for(int i=0;i<10;i++) {
        if(capacity>=a+arr[i]) {
            a=a+arr[i];
            capacity=capacity-arr[i];
            select[i]=arr[i];
            k++;
        }
        else {
            a = a-arr[i];
        }
    }
    
    
    
    cout<<"Selected"<<endl;
    for(int i=0; i<k; i++) {
        if(select[i]>0) {
            cout<<select[i]<<endl;
        }
    }
    
    return 0;
}
