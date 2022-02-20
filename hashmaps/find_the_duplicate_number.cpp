/* link: https://leetcode.com/problems/find-the-duplicate-number/ */
// time complexity: As we are traversing a vector and a map ,so O(2N)~o(N)
// space complexity: As we are making a vector of length n and lets say all
// the elements in vector are different, so O(2N)~O(N)

#include <iostream>
#include <vector>
#include <map>
using namespace std;
// class is a user defined datatype
class Solution
{
public:
    int findDuplicate(vector<int> &nums)
    {
        map<int, int> mp;
        for (int i = 0; i < nums.size(); i++)
        {
            mp[nums[i]]++;
        }
        map<int, int>::iterator itr;
        for (itr = mp.begin(); itr != mp.end(); itr++)
        {
            if (itr->second > 1)
                return itr->first;
        }
        return -1;
    }
};

int main()
{
    int n;
    cin >> n;
    vector<int> nums;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        nums.push_back(x);
    }
    // creating object of class solution
    Solution obj;
    cout << obj.findDuplicate(nums) << endl;
    return 0;
}