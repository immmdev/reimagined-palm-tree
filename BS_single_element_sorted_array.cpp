#include<bits/stdc++.h>
using namespace std;

int singleietm(vector<int> &nums,int n){
    if(n==1) return nums[0];
    if(nums[0]!=nums[1]) return nums[0];
    if(nums[n-1]!=nums[n-2]) return nums[n-1];

    int high=n-2;
    int low=1;

    while(low<=high){
        int mid=(low+high)/2;

        // if l and r are not equal to mid then return mid
        if(nums[mid]!=nums[mid-1] && nums[mid]!=nums[mid+1]) return nums[mid];

        // checking if u are on the left part then element in right after checking the mid
        if((mid%2==1 && nums[mid]==nums[mid-1])||(mid%2==0 && nums[mid]==nums[mid+1])){
                low=mid+1;
        }
        // eleminating the right part as the elemnt will be in the left
        else{
                high=mid-1;
        }
    }
}



int main(){
    int n;
    cin >> n;

    vector<int> nums(n);

    for(int i=0; i<n; i++){
        cin >> nums[i];
    }
    cout << singleietm(nums,n);
}