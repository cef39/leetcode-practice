/**
 * Given an array of integers, return indices of the two numbers such that they add up to a specific target.
 *
 * You may assume that each input would have exactly one solution, and you may not use the same element twice.
 *
 * Example:
 *
 * Given nums = [2, 7, 11, 15], target = 9,
 *
 * Because nums[0] + nums[1] = 2 + 7 = 9,
 * return [0, 1]. 
 *
 */

#include <vector>
#include <iostream>
#include <exception>

using std::vector;  using std::cout;    using std::endl;
using std::exception;

vector<int> twoSum(vector<int>& nums, int target) {
    bool sumFound = false;
    vector<int> res;

    for (int i = 0; i < nums.size(); i++) {

        for (int j = i + 1; j < nums.size(); j++) {
            
            int sum = nums[i] + nums[j];
            if ((j != i) && sum == target) {
                res.push_back(i);
                res.push_back(j);
                sumFound = true;
            }
        }

        if (sumFound) {
            break;
        }
    }

    if (res.size() == 0) {
        throw "No valid sum was found.";
    }
    
    return res;
}

int main() {

    vector<int> nums;
    for (int i = 1; i <= 10; i++) {
        nums.push_back(i);
    }

    vector<int> result = twoSum(nums, 4);

    cout << result[0] << ": " << nums[result[0]] << endl;
    cout << result[1] << ": " << nums[result[1]] << endl;

    vector<int> nums2 = {2, 7, 11, 15};
    vector<int> result2 = twoSum(nums2, 9);

    cout << result2[0] << ": " << nums2[result2[0]] << endl;
    cout << result2[1] << ": " << nums2[result2[1]] << endl;

    return 0;
}