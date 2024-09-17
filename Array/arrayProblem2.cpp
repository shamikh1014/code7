// Find the maximum and minimum element in an array

#include<bits/stdc++.h>
using namespace std;

// Method 1

int getMax(int arr[], int size){
    int maxNo=INT_MIN;
    for(int i=0;i<size;i++){
        if(arr[i]>maxNo){
            maxNo=arr[i];
        }
    }
    return maxNo;
}

int getMin(int arr[], int size){
    int minNo=INT_MAX;
    for(int i=0;i<size;i++){
        if(arr[i]<minNo){
            minNo=arr[i];
        }
    }
    return minNo;
}

void getMaxMin(int arr[], int size){
    sort(arr, arr+size);
    // cout<<arr[size-1]<<" "<<arr[0]<<endl;
    int maxi=arr[size-1];
    int mini=arr[0];

    cout<<maxi<<" "<<mini<<endl;
}

// Method 2

struct Pair{
    int min;
    int max;
};

Pair getMinMax2(int arr[], int size){
    Pair minmax;
    sort(arr, arr+size);

    minmax.min=arr[0];
    minmax.max=arr[size-1];

    return minmax;
}

// Method 3

Pair getMinMax3(int arr[], int size){
    struct Pair minmax;
    
    if(size==1){
        minmax.min=arr[0];
        minmax.max=arr[0];
        return minmax;
    }

    if(arr[0]>arr[1]){
        minmax.min=arr[1];
        minmax.max=arr[0];
    }
    else{
        minmax.min=arr[0];
        minmax.max=arr[1];
    }

    for(int i=2;i<size;i++){
        if(arr[i]<minmax.min){
            minmax.min=arr[i];
        }
        else if(arr[i]>minmax.max){
            minmax.max=arr[i];
        }
    }
    return minmax;
}

// Method 4

Pair getMinMax4(int arr[], int low, int high){
    struct Pair minmax, minmaxleft, minmaxright;

    if(low==high){
        minmax.min=arr[low];
        minmax.max=arr[low];
        return minmax;
    }

    if(high==low+1){
        if(arr[low]>arr[high]){
            minmax.min=arr[high];
            minmax.max=arr[low];
        }
        else{
            minmax.min=arr[low];
            minmax.max=arr[high];
        }
        return minmax;
    }

    int mid=(low+high)/2;
    minmaxleft=getMinMax4(arr, low, mid);
    minmaxright=getMinMax4(arr, mid+1, high);

    if(minmaxleft.min<minmaxright.min){
        minmax.min=minmaxleft.min;
    }
    else{
        minmax.min=minmaxright.min;
    }

    if(minmaxleft.max>minmaxright.max){
        minmax.max=minmaxleft.max;
    }
    else{
        minmax.max=minmaxright.max;
    }

    return minmax;
}

// Method 5

Pair getMinMax5(int arr[], int size){
    struct Pair minmax;
    int i;
    if(size%2==0){
        if(arr[0]>arr[1]){
            minmax.min=arr[1];
            minmax.max=arr[0];
        }
        else{
            minmax.min=arr[0];
            minmax.max=arr[1];
        }
        i=2;
    }
    else{
        minmax.min=arr[0];
        minmax.max=arr[0];
        i=2;    
    }

    while(i<size-1){
        if(arr[i]>arr[i+1]){

            if(arr[i+1]<minmax.min){
                minmax.min=arr[i+1];
            }

            if(arr[i]>minmax.max){
                minmax.max=arr[i];
            }
            
        }
        else{
            if(arr[i]<minmax.min){
                minmax.min=arr[i];
            }
            if(arr[i+1]>minmax.max){
                minmax.max=arr[i+1];
            }
        }
        i+=2;
    }

    return minmax;
}

int main(){

    int arr[]={1000, 11, 445, 1, 330, 3000};
    int size=sizeof(arr)/sizeof(arr[0]);

    // cout<<getMax(arr, size)<<endl;
    // cout<<getMin(arr, size)<<endl;

    // getMaxMin(arr, size);

    // Pair minmax=getMinMax2(arr, size);

    // struct Pair minmax=getMinMax3(arr, size);

    // struct Pair minmax=getMinMax4(arr, 0, size-1);
    
    Pair minmax=getMinMax5(arr, size);

    cout<<minmax.min<<" "<<minmax.max<<endl;

    return 0;
}