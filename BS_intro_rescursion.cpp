#include<bits/stdc++.h>
using namespace std;

// function to implement bs
int bs(int arr[],int high,int low,int target){

    // iterate till element left
    while(low<=high){
        int mid=(low+high)/2;
        if(arr[mid]==target){
            // find taget return index
            return mid;
        }

        // recusing function 
        else if(arr[mid]>target){
            return bs(arr,mid-1,low,target);
        }
        else{
            return bs(arr,high,mid+1,target);
        }
    }
    return -1;
}


int main(){
    int n,target;
    cin >> n;

    int arr[n];

    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    int low=0;
    int high=n-1;
    cin >> target;

    cout << bs(arr,high,low,target);


    return 0;
}

// tc log((base2)n)
// if int low=0 int high=int_max then mid=low+(high-low)/2 so, over flow condition can be prevented without using long long.
// (int_max+int_max)/2 can not be stored in the int variable, so either you store it in long long or use the above remidy.