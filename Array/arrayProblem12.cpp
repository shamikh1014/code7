// Merge 2 sorted arrays without using extra space

#include<bits/stdc++.h>
using namespace std;

// Method 1

void mergeArr1(int arr1[], int arr2[], int size1, int size2, int arr3[]){
    
}

// Method 2

void mergeArr2(int arr1[], int arr2[], int size1, int size2, int arr3[]){

}

// Method 3

void mergeArr3(int arr1[], int arr2[], int size1, int size2, int arr3[]){

}

// Method 4

void mergeArr4(int arr1[], int arr2[], int size1, int size2, int arr3[]){

}



void printArr(int arr[], int size){
    for(int i=0;i<size;i++){
        cout<<arr[i]<<" ";
    }
}

int main(){

    int arr1[]={1, 3, 5, 7};
    int size1=sizeof(arr1)/sizeof(arr1[0]);

    int arr2[]={2, 4, 6, 8};
    int size2=sizeof(arr2)/sizeof(arr2[0]);

    int arr3[size1+size2];

    // mergeArr1(arr1, arr2, size1, size2, arr3);

    // mergeArr2(arr1, arr2, size1, size2, arr3);

    mergeArr3(arr1, arr2, size1, size2, arr3);

    // mergeArr4(arr1, arr2, size1, size2, arr3);

    printArr(arr3, size1+size2);
    
    return 0;
}