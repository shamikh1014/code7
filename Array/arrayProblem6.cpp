// Find the Union and Intersection of the two sorted arrays

#include<bits/stdc++.h>
using namespace std;

// Method 1

vector<int> union1(int arr1[], int arr2[], int size1, int size2){
    set<int> s;
    for(int i=0;i<size1;i++){
        s.insert(arr1[i]);
    }

    for(int i=0;i<size2;i++){
        s.insert(arr2[i]);
    }

    vector<int> vec(s.begin(), s.end());

    return vec;
}

// Method 2

vector<int> union2(int arr1[], int arr2[], int size1, int size2){

    map<int, int> map;
    for(int i=0;i<size1;i++){
        if(map.find(arr1[i])!= map.end()){
            map[arr1[i]]++;
        }
        else{
            map[arr1[i]]=1;
        }
    }

    for(int i=0;i<size2;i++){
        if(map.find(arr2[i])!= map.end()){
            map[arr2[i]]++;
        }
        else{
            map[arr2[i]]=1;
        }
    }

    vector<int> vec;
    for(auto i:map){
        vec.push_back(i.first);
    }
    return vec;
}

// Method 3

void union3(int arr1[], int arr2[], int size1, int size2){
    int i=0, j=0;

    while(i<size1 && j<size2){
        if(arr1[i]<arr2[j]){
            cout<<arr1[i++]<<" ";
        }
        else if(arr2[j]<arr1[i]){
            cout<<arr2[j++]<<" ";
        }
        else{
            cout<<arr2[j++]<<" ";
            i++;

            // cout<<arr2[i++]<<" ";
            // j++;
        }
    }

    while(i<size1){
        cout<<arr1[i++]<<" ";
    }
    while(j<size2){
        cout<<arr2[j++]<<" ";
    }
}

// Method 4

void nextDistinctElement(vector<int>& arr, int& x){
    do{
        ++x;
    }
        while(x<arr.size() && arr[x-1]==arr[x]);

}

void union4(vector<int> arr1, vector<int> arr2){
    int i=0, j=0;
    while(i<arr1.size() && j<arr2.size()){
        if(arr1[i]<arr2[j]){
            cout<<arr1[i]<<" ";
            nextDistinctElement(arr1, i);
        }
        else if(arr2[j]<arr1[i]){
            cout<<arr2[j]<<" ";
            nextDistinctElement(arr2, j);
        }
        else{
            cout<<arr1[i]<<" ";
            // cout<<arr2[j]<<" ";
            nextDistinctElement(arr1, i);
            nextDistinctElement(arr2, j);
        }
    }

    while(i<arr1.size()){
        cout<<arr1[i]<<" ";
        nextDistinctElement(arr1, i);
    }
    while(j<arr2.size()){
        cout<<arr2[j]<<" ";
        nextDistinctElement(arr2, j);
    }
}

// Method 1

vector<int> intersection1(int arr1[], int arr2[], int size1, int size2){
    set<int> s;
    for(int i=0;i<size1;i++){
        s.insert(arr1[i]);
    }

    vector<int> vec;
    for(int i=0;i<size2;i++){
        if(s.find(arr2[i])!=s.end()){
            vec.push_back(arr2[i]);
            s.erase(arr2[i]);
        }
    }
    return vec;
}

// Method 2

void intersection2(int arr1[], int arr2[], int size1, int size2){
    int i=0, j=0;
    while(i<size1 && j<size2){
        if(arr1[i]<arr2[j]){
            i++;
        }
        else if(arr2[j]<arr1[i]){
            j++;
        }
        else{
            // cout<<arr1[i]<<" ";
            cout<<arr2[j]<<" ";
            i++;
            j++;
        }
    }
}

// Method 3

void intersection3(int arr1[], int arr2[], int size1, int size2){
    int i=0, j=0;
    while(i<size1 && j<size2){

        if(i>0 && arr1[i]==arr1[i-1]){
            i++;
            continue;
        }
        if(arr1[i]<arr2[j]){
            i++;
        }
        else if(arr2[j]<arr1[i]){
            j++;
        }
        else{
            // cout<<arr1[i]<<" ";
            cout<<arr2[j]<<" ";
            i++;
            j++;
        }
    }
}

int main(){

    int arr1[]={1, 2, 2, 2, 3};
    int arr2[]={2, 3, 3, 4, 5, 5};

    int size1=sizeof(arr1)/sizeof(arr1[0]);
    int size2=sizeof(arr2)/sizeof(arr2[0]);

    // vector<int> uni=union1(arr1, arr2, size1, size2);
    // vector<int> uni=union2(arr1, arr2, size1, size2);

    // for(int i:uni){
    //     cout<<i<<" ";
    // }

    // union3(arr1, arr2, size1, size2);

    // vector<int> arr1={1, 2, 2, 2, 3};
    // vector<int> arr2={2, 3, 3, 4, 5, 5};

    // union4(arr1, arr2);

    // vector<int> inter=intersection1(arr1, arr2, size1, size2);
    // for(int i:inter){
    //     cout<<i<<" ";
    // }

    // intersection2(arr1, arr2, size1, size2);
    intersection3(arr1, arr2, size1, size2);
    
    return 0;
}