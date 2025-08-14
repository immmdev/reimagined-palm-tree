#include<bits/stdc++.h>
using namespace std;

// with unique elemets
int invertedsearch(vector<int> &nums,int n, int target){

    int low=0;
    int high=n-1;

    while(low<=high){

        int mid=(low+high)/2;
        
        // retun when mid reaches to the 
        if(nums[mid]==target) return mid;


        // checking if left is sorted
        if(nums[low]<=nums[mid]) {

            // checking if target lies in the left half
            if(nums[low]<=target && target <=nums[mid]){
                high=mid-1;
            
            } else {
                low=mid+1;
            }

        // checking if right
        } else {

            // checking if traget lies in the right half
            if(nums[mid]<=target && target<=nums[high]){

                low=mid+1;

            } else {
                high=mid-1;
            }
        }
    }
}

// without unique elemets
int invertedsearch_1(vector<int> &nums,int n,int target){
    
    int low=0;
    int high=n-1;

    while(low<=high){

        int mid=(low+high)/2;
        
        // retun when mid reaches to the 
        if(nums[mid]==target) return 1;

        // shriking the search space whwn low mid and high are equal
        if(nums[mid]==nums[low] && nums[mid]==nums[high]) {
            high=high-1;
            low=low+1;
            continue;
        }

        // checking if left is sorted
        if(nums[low]<=nums[mid]) {

            // checking if target lies in the left half
            if(nums[low]<=target && target <=nums[mid]){
                high=mid-1;
            
            } else {
                low=mid+1;
            }

        // checking if right
        } else {

            // checking if traget lies in the right half
            if(nums[mid]<=target && target<=nums[high]){

                low=mid+1;

            } else {
                high=mid-1;
            }
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

    int target;
    cin >> target;

    cout << invertedsearch_1(nums,n,target);
}

// tc:- avg:- o(logn) worst:-o(n/2)

