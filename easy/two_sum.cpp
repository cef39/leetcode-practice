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

using std::vector;  using std::cout;    using std::endl;

vector<int> twoSum(vector<int>& nums, int target) {
    bool sumFound = false;
    vector<int> res;

    for (int i = 0; i < nums.size(); i++) {

        for (int j = 0; j < nums.size(); j++) {
            
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

    return 0;
}