// Find largest sum contigous subarray [V.IMP]

#include<bits/stdc++.h>
using namespace std;

int maxSubArrSum1(int arr[], int size){
    int maxsofar=INT_MIN, maxending=0;
    for(int i=0;i<size;i++){
        maxending=maxending+arr[i];

        if(maxsofar<maxending){
            maxsofar=maxending;
        }
        if(maxending<0){
            maxending=0;
        }
        // maxsofar=max(maxsofar, maxending);
    }
    return maxsofar;
}

void maxSubArrSum2(int arr[], int size){
    int maxsofar=INT_MIN, maxending=0;
    int start=0, end=0, s=0;
    for(int i=0;i<size;i++){
        maxending=maxending+arr[i];

        if(maxsofar<maxending){
            maxsofar=maxending;
            start=s;
            end=i;
        }
        if(maxending<0){
            maxending=0;
            s=i+1;
        }
        // maxsofar=max(maxsofar, maxending);
    }
    cout<<maxsofar<<endl;
    cout<<start<<" "<<end<<endl;
}

void maxSubArrSum3(int arr[], int size){
    vector<int> dp(size, 0);

    dp[0]=arr[0];
    int ans=arr[0];

    for(int i=1;i<size;i++){
        dp[i]=max(arr[i], arr[i]+dp[i-1]);
        ans=max(ans, dp[i]);
    }
    cout<<ans<<endl;
}

int main(){
    
    int arr[]={-2, -3, 4, -1, -2, 1, 5, -3};
    int size=sizeof(arr)/sizeof(arr[0]);

    // cout<<maxSubArrSum1(arr, size)<<endl;
    // maxSubArrSum2(arr, size);
    maxSubArrSum3(arr, size);

    return 0;
}
