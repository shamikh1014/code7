// Find the "Kth" max and min element of an array

#include<bits/stdc++.h>
using namespace std;

// Method 1

int kthSmallest1(int arr[], int size, int k){
    sort(arr, arr+size);
    return arr[k-1];
}

// Method 2

int count(vector<int>& vec, int& mid){
    int cnt=0;
    for(int i=0;i<vec.size();i++){
        if(vec[i]<=mid){
            cnt++;
        }
    }
    return cnt;
}

int kthSmallest2(vector<int> vec, int& k){
    int low=INT_MAX;
    int high=INT_MIN;

    for(int i=0;i<vec.size();i++){
        low=min(low, vec[i]);
        high=max(high, vec[i]);
    }

    while(low<high){
        int mid=low+(high-low)/2;
        if(count(vec, mid)<k){
            low=mid+1;
        }
        else{
            high=mid;
        }
    }
    return low;
}

//Method 3

int kthSmallest3(int arr[], int size, int k){
    priority_queue<int> pq;
    for(int i=0;i<size;i++){
        pq.push(arr[i]);

        if(pq.size()>k){
            pq.pop();
        }
    }
    return pq.top();
}

// Method 4

int kthSmallest4(int arr[], int size, int k){

    return 0;
}

// Method 5

int kthSmallest5(int arr[], int size, int k){
    int maxelement=arr[0];
    for(int i=0;i<size;i++){
        if(arr[i]>maxelement){
            maxelement=arr[i];
        }
    }

    int freq[maxelement+1]={0};
    for(int i=0;i<size;i++){
        freq[arr[i]]++;
    }

    int count=0;
    for(int i=0;i<maxelement;i++){
        if(freq[i]!=0){
            count+=freq[i];
        }
        if(count>=k){
            return i;
        }
    }
    return -1;
}

int main(){
    
    int arr[]={10, 5, 4, 3, 48, 6, 2, 33, 53, 10};
    int size=sizeof(arr)/sizeof(arr[0]);

    vector<int> vec={10, 5, 4, 3, 48, 6, 2, 33, 53, 10};

    // cout<<kthSmallest1(arr, size, 3)<<endl;

    // cout<<kthSmallest2(vec, 3)<<endl;

    // cout<<kthSmallest3(arr, size, 3)<<endl;

    cout<<kthSmallest5(arr, size, 3)<<endl;

    return 0;
}