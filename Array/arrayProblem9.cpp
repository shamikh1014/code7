// Minimize the maximum difference between heights [V.IMP]

#include<bits/stdc++.h>
using namespace std;

// Method 1

int minDiff1(int arr[], int size, int k){
    sort(arr, arr+size);
    int ans=arr[size-1]-arr[0];

    int tempmin=arr[0];
    int tempmax=arr[size-1];

    for(int i=1;i<size;i++){

        if(arr[i]-k<0){
            continue;
        }

        tempmin=min(arr[0]+k, arr[i]-k);
        tempmax=max(arr[i-1]+k, arr[size-1]-k);
        ans=min(ans, tempmax-tempmin);
    }

    return ans;
}

int main(){

    int arr[]={7, 4, 8, 8, 8, 9};
    int size=sizeof(arr)/sizeof(arr[0]);

    cout<<minDiff1(arr, size, 6);
    
    return 0;
}