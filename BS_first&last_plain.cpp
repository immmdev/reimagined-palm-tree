#include<bits/stdc++.h>
using namespace std;

int firstOcc(int nums[],int n,int x){
    int low=0;
    int high=n-1;
    int first=-1;
    while(low<=high){
        int mid=(high+low)/2;
        if(nums[mid]==x){
            high=mid-1;
            first=mid;
        }

        else if(nums[mid]<x){
            low=mid+1;
        }

        else{
            high=mid-1;
        }
    }

    return first;
}

int lastOcc(int nums[],int n, int x){
     int low=0;
    int high=n-1;
    int last=-1;
    while(low<=high){
        int mid=(high+low)/2;
        if(nums[mid]==x){
            low=mid+1;
            last=mid;
        }

        else if(nums[mid]<x){
            low=mid+1;
        }

        else{
            high=mid-1;
        }
    }

    return last;
}




int main(){
    int n,target;
    cin >> n;

    int arr[n];

    for(int i=0; i<n; i++){
        cin >> arr[i];
    }

    int x;
    cin >> x;

    cout << firstOcc(arr,n,x) << "," << lastOcc(arr,n,x) << endl;

    cout << lastOcc(arr,n,x)-firstOcc(arr,n,x)+1;

    return 0;
}