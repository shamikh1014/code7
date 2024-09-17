// Given an array which consists of 0, 1 and 2. Sort the array without using a sorting algo

#include<bits/stdc++.h>
using namespace std;

// Method 1

void sort012_1(int arr[], int size){

    int low=0;
    int mid=0;
    int high=size-1;

    while(mid<=high){
        switch(arr[mid]){
            case 0:
            swap(arr[low++], arr[mid++]);
            break;

            case 1:
            mid++;
            break;

            case 2:
            swap(arr[mid], arr[high--]);
            break;
        }
    }
}

// Method 2

void sort012_2(int arr[], int size){

    int left=0;
    int right=size-1;

    int i=0;
    while(i<size && i<=right){
        if(arr[i]==0){
            swap(arr[left++], arr[i++]);
            // left++;
            // i++;
        }
        else if(arr[i]==1){
            i++;
        }
        else{
            swap(arr[i], arr[right--]);
            // right--;
        }
    }
}

// Method 3

void sort012_3(int arr[], int size){

    int cnt0=0, cnt1=0, cnt2=0;
    int i=0;
    while(i<size){
        switch(arr[i]){
            case 0:
            cnt0++;
            break;

            case 1:
            cnt1++;
            break;

            case 2:
            cnt2++;
            break;
        }
        i++;
    }

    i=0;
    while(cnt0>0){
        arr[i++]=0;
        cnt0--;
    }

    while(cnt1>0){
        arr[i++]=1;
        cnt1--;
    }

    while(cnt2>0){
        arr[i++]=2;
        cnt2--;
    }
}

void printArr(int arr[], int size){
    for(int i=0;i<size;i++){
        cout<<arr[i]<<" ";
    }
}

int main(){

    int arr[]={0, 1, 1, 0, 1, 2, 1, 2, 0, 0, 0, 1};
    int size=sizeof(arr)/sizeof(arr[0]);

    // sort012_1(arr, size);

    // sort012_2(arr, size);
    
    sort012_3(arr, size);

    printArr(arr, size);
    
    return 0;
}