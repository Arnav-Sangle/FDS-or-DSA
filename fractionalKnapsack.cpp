//fractional knapsack
//10 3 20 6 40
//2 3 4 4 5

#include <bits/stdc++.h>
using namespace std;

#define n 5
float capacity=12;

float basedOnProfit(float p[], float w[], float x[]) {
    float temp;
    
    cout<<"Before Sort based on profit\n";
    cout<<"Profit: ";
    for(int i=0; i<n; i++) {
        cout<<p[i]<<" ";
    }
    cout<<endl;
    cout<<"Weight: ";
    for(int i=0; i<n; i++) {
        cout<<w[i]<<" ";
    }
    cout<<endl;
    
    //bubble sort (in descending order coz Max Profit)
    for(int i=0; i<n; i++) {
        for(int j=0; j<n-i-1; j++){
            
            if(p[j]<p[j+1]) {   //swap value    3,6,1 3<6 swap 6,3,1
                temp=p[j];
                p[j]=p[j+1];
                p[j+1]=temp;
                
                temp=w[j];
                w[j]=w[j+1];
                w[j+1]=temp;
            }
        }
    }
    
    cout<<"Sorted array based on profit\n";
    cout<<"Profit: ";
    for(int i=0; i<n; i++) {
        cout<<p[i]<<" ";
    }
    cout<<endl;
    cout<<"Weight: ";
    for(int i=0; i<n; i++) {
        cout<<w[i]<<" ";
    }
    cout<<endl;
    
    float tp=0; float W=0;
    for(int i=0; i<n; i++) {
        if(W+w[i] <= capacity) {
            x[i] = 1;
            W = W+w[i];
        }
        else {
            x[i] = (capacity-W)/w[i];
            break;
        }
    }
    
    for(int i=0; i<n; i++) {
        tp=tp+p[i]*x[i];
    }
    
    return tp;
}





float basedOnWeight(float p[], float w[], float x[]) {
    float temp;
    
    cout<<"Before Sort based on Weight\n";
    cout<<"Profit: ";
    for(int i=0; i<n; i++) {
        cout<<p[i]<<" ";
    }
    cout<<endl;
    cout<<"Weight: ";
    for(int i=0; i<n; i++) {
        cout<<w[i]<<" ";
    }
    cout<<endl;
    
    //bubble sort (in ascending order coz Min Weight)
    for(int i=0; i<n; i++) {
        for(int j=0; j<n-i-1; j++){
            
            if(w[j]>w[j+1]) {   //swap value    3,6,1 6>1 swap  3,1,6  1,3,6
                temp=w[j];
                w[j]=w[j+1];
                w[j+1]=temp;
                
                temp=p[j];
                p[j]=p[j+1];
                p[j+1]=temp;
            }
        }
    }
    
    cout<<"Sorted array based on weight\n";
    cout<<"Profit: ";
    for(int i=0; i<n; i++) {
        cout<<p[i]<<" ";
    }
    cout<<endl;
    cout<<"Weight: ";
    for(int i=0; i<n; i++) {
        cout<<w[i]<<" ";
    }
    cout<<endl;
    
    float tp=0; float W=0;
    for(int i=0; i<n; i++) {
        if(W+w[i] <= capacity) {
            x[i] = 1;
            W = W+w[i];
        }
        else {
            x[i] = (capacity-W)/w[i];
            break;
        }
    }
    
    for(int i=0; i<n; i++) {
        tp=tp+p[i]*x[i];
    }
    
    return tp;
}






float basedOnRatio_PW(float p[], float w[], float x[]) {
    float temp;
    
    float r[n];
    for(int i=0; i<n; i++) {
        r[i]=p[i]/w[i];
    }
    
    cout<<"Before Sort based on Ratio (P:W)\n";
    cout<<"Ratio: ";
    for(int i=0; i<n; i++) {
        cout<<r[i]<<" ";
    }
    cout<<endl;
    cout<<"Weight: ";
    for(int i=0; i<n; i++) {
        cout<<w[i]<<" ";
    }
    cout<<endl;
    
    //bubble sort (in ascending order coz Max Ratio (P:W))
    for(int i=0; i<n; i++) {
        for(int j=0; j<n-i-1; j++){
            
            if(r[j]<r[j+1]) {   //swap value    3,6,1 3<6 swap 6,3,1
                temp=r[j];
                r[j]=r[j+1];
                r[j+1]=temp;
                
                temp=p[j];
                p[j]=p[j+1];
                p[j+1]=temp;
                
                temp=w[j];
                w[j]=w[j+1];
                w[j+1]=temp;
            }
        }
    }
    
    cout<<"Sorted array based on Ratio (P:W)\n";
    cout<<"Ratio: ";
    for(int i=0; i<n; i++) {
        cout<<r[i]<<" ";
    }
    cout<<endl;
    cout<<"Weight: ";
    for(int i=0; i<n; i++) {
        cout<<w[i]<<" ";
    }
    cout<<endl;
    
    float tp=0; float W=0;
    for(int i=0; i<n; i++) {
        if(W+w[i] <= capacity) {
            x[i] = 1;
            W = W+w[i];
        }
        else {
            x[i] = (capacity-W)/w[i];
            break;
        }
    }
    
    for(int i=0; i<n; i++) {
        tp=tp+p[i]*x[i];
    }
    
    return tp;
}




int main()
{
    float p[10], w[10], x[10];
    cout<<"Enter the profits-"<<endl;
    for(int i=0; i<n; i++) {
        cin>>p[i];
    }
    cout<<endl;
    
    cout<<("Enter the wieghts-")<<endl;
        for(int i=0; i<n; i++) {
        cin>>w[i];
    }
    cout<<endl;
    
    for(int i=0; i<n; i++) {
        x[i]=0;
    }
    
    float tp=basedOnProfit(p,w,x);
    cout<<"Total profit Based on Profit= "<<tp<<endl;
    cout<<endl;
    
    tp=basedOnWeight(p,w,x);
    cout<<"Total profit Based on Weight= "<<tp<<endl;
    cout<<endl;
    
    tp=basedOnRatio_PW(p,w,x);
    cout<<"Total profit Based on Ratio(Pi:Wi)= "<<tp<<endl;
    cout<<endl;
    
    return 0;
}
