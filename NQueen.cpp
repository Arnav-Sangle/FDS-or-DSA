#include<bits/stdc++.h>

using namespace std;

int a[20];

void queen(int n);
int place(int pos);
void print_sol(int n);

int main() {
    int n;
    cout<<"Enter no. of queens: ";
    cin>>n;
    queen(n);
}


void queen(int n) { 
    int k=1;    //k=row
    a[k]=0;     //a[k]=col
    
    while(k!=0) {
        a[k]=a[k]+1;
        while(a[k]<=n && !place(k)) {
            a[k]++;
        }
        
        if(a[k]<=n) {
            if(k==n){
                print_sol(n);
            }
            else {
                k++;
                a[k]=0;
            }
        }
        else {
            k--;
        }
    }
}

int place(int pos) {
    for(int i=1; i<pos; i++) {
        if(a[i]==a[pos] || abs(a[i]-a[pos])==abs(i-pos)) {
            return 0;
        }
    }
    return 1;
}

void print_sol(int n){
    cout<<"\n*****Solution*****\n";
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) {
            if(a[i]==j) {
                cout<<i<<" ";
            }
            else {
                cout<<"- ";
            }
        }
        cout<<endl;
    }
}

