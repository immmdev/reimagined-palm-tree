#include<bits/stdc++.h>
using namespace std;

// element may or may not in the sorted part                                          
int minivertedsearch(vector<int> &nums,int n){
    int ans=INT_MAX;
    int low=0;
    int high=n-1;

    while(low<=high){
        int mid=(low+high)/2;
        // check which half is sorted
        
        // if the whole array is sorted then low will be the min
        if(nums[low]<=nums[high]){
            ans=min(ans,nums[low]);
            break;
        }

        if(nums[low]<=nums[mid]){
            // if left is sorted then store min in ans of left
            ans=min(ans,nums[low]);
            // then eliminate the left part
            low=mid+1;
        }

        else{
            ans=min(ans,nums[mid]);
            high=mid-1;
        }
    }

    return ans;
}

int main(){
    int n;
    cin >> n;

    vector<int> nums(n);

    for(int i=0; i<n; i++){
        cin >> nums[i];
    }

    cout << minivertedsearch(nums,n);
}

// tc=o(logn)