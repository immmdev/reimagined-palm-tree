#include<bits/stdc++.h>
using namespace std;

int peak_brute(vector<int> nums,int n){
    for(int i=0; i<n; i++){
        if( i==0  && nums[i]>nums[i+1]){
            cout << nums[i] << " ";
        }

        else if(nums[i]>nums[i-1] && i==n-1){
            cout << nums[i] << " ";
        }

        else if(i>0 && i<n-1  && nums[i]>nums[i+1] && nums[i]>nums[i-1] ){
            cout << nums[i] << " ";
        }
       
    }
}

// when there is peak in the array
int peak_bs(vector<int>nums,int n){
    if(n==1) return nums[0];
    if(nums[0]>nums[1]) return nums[0];
    if(nums[n-1]>nums[n-2]) return nums[n-1];
    int low=1;
    int high=n-2;
    while(low<=high){
        int mid=(low+high)/2;
        
        if(nums[mid]>nums[mid+1]&&nums[mid]>nums[mid-1]) return nums[mid];

        // decreasing slope el will be in left
        else if(nums[mid]<nums[mid-1] && nums[mid]>nums[mid+1]){
            high=mid-1;
        }

        // increasing slope el will be in right
        else if(nums[mid]>nums[mid-1] && nums[mid]<nums[mid+1]){
            low=mid+1;
        }

        // for duplicates in array
        // we want any of the eak

        else{
            low=mid+1;
        }
    }
    return -1;
}

int main(){
    int n;
    cin >> n;

    vector<int> nums(n);

    for(int i=0; i<n; i++){
        cin >> nums[i];
    }

    // peak_brute(nums,n);
    cout << peak_bs(nums,n);

    

}

// TC O(log2n);
// SC  O(1)