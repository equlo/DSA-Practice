#include <iostream>
#include <vector>
using namespace std;

int removeElement(vector<int>& nums, int val) {
    int k = 0;

    for(int i = 0; i < nums.size(); i++) {
        if(nums[i] != val) {
            nums[k] = nums[i];
            k++;
        }
    }

    return k;
}

int main() {
    int n;
    cout << "Enter size of array: ";
    cin >> n;

    vector<int> nums(n);

    cout << "Enter array elements: ";
    for(int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    int val;
    cout << "Enter value to remove: ";
    cin >> val;

    int k = removeElement(nums, val);

    cout << "Number of elements after removal: " << k << endl;

    cout << "Updated array: ";
    for(int i = 0; i < k; i++) {
        cout << nums[i] << " ";
    }

    return 0;
}