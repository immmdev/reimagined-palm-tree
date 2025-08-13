#include<bits/stdc++.h>
using namespace std;

// lower bound is smallest index such that arr[i]>=x or ciel of array

int lb(int nums[], int n, int x){
    int low=0;
    int high=n-1;

    // initializing lb as largest index of array
    int lb=n;

    while(low<=high){

        // preventing int overflow
        int mid=low+(high-low)/2;

        // moving high left
        if(nums[mid]>=x){

            // updating with min value
            lb=mid;

            // look for small index at left
            high=mid-1;
        }

        // else only moving low no update if x is greater
        else{
            low=mid+1;
        }

    }

    return lb;
}



// upper bound smallest inx such that arr[i]>x
int ub(int nums[], int n, int x){
    int low=0;
    int high=n-1;

    // initializing lb as largest index of array
    int ub=n;

    while(low<=high){

        // preventing int overflow
        int mid=low+(high-low)/2;

        // moving high left
        if(nums[mid]>x){

            // updating with min value
            ub=mid;

            // look for small index at left
            high=mid-1;
        }

        // else only moving low no update if x is greater
        else{
            low=mid+1;
        }

    }

    return ub;
}

int floor(int nums[], int n, int x){
    int low=0;
    int high=n-1;

    // initializing floor as largest index of array
    int floor=n;

    while(low<=high){

        // preventing int overflow
        int mid=low+(high-low)/2;

        if(nums[mid]<=x){

            floor=mid;

            low=mid+1;
        }

        else{
            high=mid-1;
        }

    }

    return floor;
}


int main(){
    int n,x;
    cin >> n;

    int arr[n];

    for(int i=0; i<n; i++){
        cin >> arr[i];
    }

    cin >> x;

    cout << lb(arr,n,x) << endl;
    cout << ub(arr,n,x) << endl;
}

// floor and ciel in sorted array
// floor is the largest no. in array <= x
// ciel is the smallest number >=x
