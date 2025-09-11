#include<bits/stdc++.h>
using namespace std;
// Q :- finding kth missing number between 1 to max of array
int bs_missing(vector<int>nums,int k){
    int n=nums.size();
    int low=0;
    int high=n-1;
    while(low<=high){
        int mid=(low+high)/2;
        // finding the no missing till index
        int missing=nums[mid]-(mid+1);
        // if missing is less then required eliminate left
        if(missing<k){
            low=mid+1;
        } else {
            high=mid-1;
        }
    }
    // low ans high will point to the opposite polarity 
    // ans will be arr[high]+more where more is more=k-missing where missing is arr[high]-(high+1)
    // ans=arr[high]+k-(arr[high]-(high+1))
    //  ans=(high+1)+k where high+1=low
    // so, ans=low+k;
    return low+k;
}

int main(){
    int n,k;
    cin>>n>>k;
    vector<int>nums(n);
    for(int i=0; i<n; i++){
        cin>>nums[i];
    }

    
    // Solution 1 :- 
    // TC O(n)
    // SC O(1)
    // for(int i=0; i<n; i++){
    //     if(nums[i]<=k) k++;
    //     else break;
    // }
    // cout<<k<<endl;

    // solution 2 :-
    // TC O(log(n))
    // SC O(1)
    cout<<bs_missing(nums,k)<<endl;
 
}