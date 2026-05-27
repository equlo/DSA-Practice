#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {

    vector<int> arr;

    // Merge first array
    for(int i = 0; i < nums1.size(); i++) {
        arr.push_back(nums1[i]);
    }

    // Merge second array
    for(int i = 0; i < nums2.size(); i++) {
        arr.push_back(nums2[i]);
    }

    // Sort merged array
    sort(arr.begin(), arr.end());

    int n = arr.size();

    // Odd number of elements
    if(n % 2 == 1) {
        return arr[n / 2];
    }

    // Even number of elements
    return (arr[n/2] + arr[(n/2)-1]) / 2.0;
}

int main() {

    vector<int> nums1 = {1, 2};
    vector<int> nums2 = {3, 4};

    double median = findMedianSortedArrays(nums1, nums2);

    cout << "Median = " << median << endl;

    return 0;
}