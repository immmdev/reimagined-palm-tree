#include<bits/stdc++.h>
using namespace std;

// function to implement bs
int bs(int arr[], int n, int target){
    int low=0; 
    int high=n-1;

    // iterate till element left
    while(low<=high){
        int mid=(low+high)/2;
        if(arr[mid]==target){
            // find taget return index
            return mid;
        }

        // shrinking the search space
        else if(arr[mid]>target){
            // if target is less than mid el set high behind mid
            high=mid-1;
        }
        else{
            // target greater then mid put low after mid
            low=mid+1;
        }
    }
    // not found return -1
    return -1;
}


int main(){
    int n,target;
    cin >> n;

    int arr[n];

    for(int i=0; i<n; i++){
        cin >> arr[i];
    }

    cin >> target;

    cout << bs(arr,n,target);

    return 0;
}