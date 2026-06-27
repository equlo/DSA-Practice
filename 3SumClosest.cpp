#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int threeSumClosest(vector<int>& nums, int target) {
    sort(nums.begin(), nums.end());

    int n = nums.size();
    int closestSum = nums[0] + nums[1] + nums[2];

    for (int i = 0; i < n - 2; i++) {
        int left = i + 1;
        int right = n - 1;

        while (left < right) {
            int currentSum = nums[i] + nums[left] + nums[right];

            // Update closest sum if current sum is nearer to target
            if (abs(target - currentSum) < abs(target - closestSum)) {
                closestSum = currentSum;
            }

            if (currentSum < target)
                left++;
            else if (currentSum > target)
                right--;
            else
                return currentSum; // Exact match found
        }
    }

    return closestSum;
}

int main() {
    int n, target;

    cout << "Enter the number of elements: ";
    cin >> n;

    vector<int> nums(n);

    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    cout << "Enter the target value: ";
    cin >> target;

    int result = threeSumClosest(nums, target);

    cout << "The sum closest to the target is: " << result << endl;

    return 0;
}