#include<bits/stdc++.h>

using namespace std;

vector<int>quickSort(vector<int>arr)
{
    // check if the array length is 1 or 0 then this array is already sorted
    if(arr.size() <= 1)
        return arr;
    int pivot = arr[arr.size()-1];
    vector<int>left;
    vector<int>right;
    // since we already take 1 element as a pivot. so the length arr.size()-1
    int sz=arr.size() - 1;
    for(int i=0;i<sz;i++){
        if(arr[i]<pivot)
            left.push_back(arr[i]);
        else
            right.push_back(arr[i]);
    }
    // now we need to sort the left and right array:
    vector<int>sorted_left=quickSort(left);
    vector<int>sorted_right=quickSort(right);
    // now the we need to merge the sorted left and right array:
    vector<int>sorted_arr;
    for(int i=0;i<sorted_left.size();i++)
        sorted_arr.push_back(sorted_left[i]);
    // insert the pivot
    sorted_arr.push_back(pivot);
    // insert the right array value;
    for(int i=0;i<sorted_right.size();i++)
        sorted_arr.push_back(sorted_right[i]);
    // so here sorted_arr is the sorted array of arr;
    return sorted_arr;
}
int main()
{
    vector<int>arr={5,1,4,3,7,2};
    vector<int>ans=quickSort(arr);
    for(int i=0;i<ans.size();i++)
        cout << ans[i] << " ";
    return 0;
}
