// Move all the negative elements to one side of the array

#include<bits/stdc++.h>
using namespace std;

// Method 1

void moveNeg1(vector<int>& vec){
    sort(vec.begin(), vec.end());
}

// Method 2

void moveNeg2(int arr[], int size){
    int j=0;
    for(int i=0;i<size;i++){
        if(arr[i]<0){
            if(i!=j){
                swap(arr[i], arr[j]);
            }
            j++;
        }
    }
}

// Method 3

void moveNeg3(int arr[], int left, int right){

    while(left<=right){
        if(arr[left]<0 && arr[right]<0){
            left++;
        }
        else if(arr[left]>0 && arr[right]<0){
            swap(arr[left++], arr[right++]);
        }
        else if(arr[left]>0 && arr[right]>0){
            right--;;
        }
        else if(arr[left]<0 && arr[right]>0){
            left++;
            right--;
        }
    }
}

// Method 4

void moveNeg4(int arr[], int size){

    int low=0;
    int high=size-1;
    while(low<high){
        if(arr[low]<0){
            low++;
        }
        else if(arr[high]>0){
            high--;
        }
        else{
            swap(arr[low++], arr[high--]);
        }
    }
}

void moveNeg5(int arr[], int size){
    int negcnt=0;
    for(int i=0;i<size;i++){
        if(arr[i]<0){
            negcnt++;
        }
    }

    int i=0;
    int j=negcnt;
    while(i<negcnt && j<size){
        if(arr[i]<0){
            i++;
        }
        else if(arr[j]>0){
            j++;
        }
        else{
            swap(arr[i++], arr[j--]);
        }
    }
}

void printArr(int arr[], int size){
    for(int i=0;i<size;i++){
        cout<<arr[i]<<" ";
    }
}

int main(){

    int arr[]={-1, 2, -3, 4, 5, 6, -7, 8, 9};
    int size=sizeof(arr)/sizeof(arr[0]);

    vector<int> vec={-1, 2, -3, 4, 5, 6, -7, 8, 9};

    // moveNeg1(vec);

    // for(int i:vec){
    //     cout<<i<<" ";
    // }

    // moveNeg2(arr, size);

    // moveNeg3(arr, 0, size-1);

    // moveNeg4(arr, size);

    moveNeg5(arr, size);

    printArr(arr, size);
    
    return 0;
}