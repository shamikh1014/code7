// Write a program to cyclically rotate an array by one

#include<bits/stdc++.h>
using namespace std;

// Method 1

void rotateArr1(int arr[], int size){
    int lastelement=arr[size-1];
    for(int i=size-1;i>0;i--){
        arr[i]=arr[i-1];
    }

    arr[0]=lastelement;
}

// Method 2

void rotateArr2(int arr[], int size){
    int i=0, j=size-1;
    while(i!=j){
        swap(arr[i], arr[j]);
        i++;
    }
}

// Method 3

void rotateArr3(int arr[], int size){
    int i=0, j=size-1;
    while(i<j){
        swap(arr[i], arr[j]);
        i++;
        j--;
    }

    i=1, j=size-1;
    while(i<j){
        swap(arr[i], arr[j]);
        i++;
        j--;
    }
}

void rotateArr3(int arr[], int size, int k){
    int i=0, j=size-k-1;
    while(i<j){
        swap(arr[i], arr[j]);
        i++;
        j--;
    }

    i=0, j=size-1;
    while(i<j){
        swap(arr[i], arr[j]);
        i++;
        j--;
    }
}

void printArr(int arr[], int size){
    for(int i=0;i<size;i++){
        cout<<arr[i]<<" ";
    }
}

int main(){

    int arr[]={1, 2, 3, 4, 5};
    int size=sizeof(arr)/sizeof(arr[0]);

    // rotateArr1(arr, size);

    // rotateArr2(arr, size);

    // rotateArr3(arr, size);
    
    rotateArr3(arr, size, 1);

    printArr(arr, size);
    
    return 0;
}