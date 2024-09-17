// Reverse the array

#include<bits/stdc++.h>
using namespace std;

// Method 1

void reverseArr1(int arr[], int size){
    int reverseArr[size];
    for(int i=0;i<size;i++){
        reverseArr[i]=arr[size-i-1];
    }

    // for(int i=size-1;i>=0;i--){
    //     reverseArr[i]=arr[size-i-1];
    // }

    for(int i=0;i<size;i++){
        cout<<reverseArr[i]<<" ";
    }
    cout<<endl;
}

// Method 2

void reverseArr2(int arr[], int start, int end){

    while(start<end){
        int temp=arr[start];
        arr[start]=arr[end];
        arr[end]=temp;
        start++;
        end--;
    }
}

// Method 3

void reverseArr3(int arr[], int size){
    reverse(arr, arr+size);
}

// Method 4

void reverseArr4(int arr[], int start, int end){

    if(start>=end){
        return;
    }

    int temp=arr[start];
    arr[start]=arr[end];
    arr[end]=temp;

    reverseArr4(arr, start+1, end-1);
}

// Method 5

void reverseArr5(int arr[], int size){
    stack<int> stack;

    for(int i=0;i<size;i++){
        stack.push(arr[i]);
    }

    for(int i=0;i<size;i++){
        arr[i]=stack.top();
        stack.pop();
    }
}

void printArr(int arr[], int size){
    for(int i=0;i<size;i++){
        cout<<arr[i]<<" ";
    }
}

int main(){

    int arr[]={1, 2, 3, 4, 5, 6};
    int size=sizeof(arr)/sizeof(arr[0]);

    // reverseArr1(arr, size);

    // reverseArr2(arr, 0, size-1);
    // printArr(arr, size);

    // reverseArr3(arr, size);
    // printArr(arr, size);

    // reverseArr4(arr, 0, size-1);
    // printArr(arr, size);

    // reverseArr5(arr, size);
    // printArr(arr, size);

    return 0;

}

