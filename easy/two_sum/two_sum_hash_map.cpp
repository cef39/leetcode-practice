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
#include <unordered_map>

using std::vector;  using std::cout;    using std::endl;
using std::exception;   using std::unordered_map;

vector<int> twoSum(vector<int>& nums, int target) {
    bool sumFound = false;
    vector<int> res;
    unordered_map<int, int> hash_map;

    for (int i = 0, size = nums.size(); i < size; i++) {
        // uses the index in the vector as the Key, number is value
        hash_map.emplace(nums[i], i);
    }

    for (int i = 0, size = nums.size(); i < size; i++) {
        // we obtain the number we need to find by calculating the difference of the current number and the target value
        int difference = target - nums[i];

        // now we check the hash map for the desired number
        unordered_map<int, int>::const_iterator got = hash_map.find(difference);

        // if desired number was found and the index does not equal the current index
        if (got != hash_map.end() && (got->second != i)) {
            res.push_back(i);
            res.push_back(got->second);
            return res;
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
    cout << endl;

    vector<int> nums2 = {2, 7, 11, 15};
    vector<int> result2 = twoSum(nums2, 9);

    cout << result2[0] << ": " << nums2[result2[0]] << endl;
    cout << result2[1] << ": " << nums2[result2[1]] << endl;
    cout << endl;

    vector<int> nums3 = {3, 3};
    vector<int> result3 = twoSum(nums3, 6);

    cout << result3[0] << ": " << nums3[result3[0]] << endl;
    cout << result3[1] << ": " << nums3[result3[1]] << endl;
    cout << endl;

    return 0;
}