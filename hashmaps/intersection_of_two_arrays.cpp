/* link: https://leetcode.com/problems/unique-number-of-occurrences/ */
// time complexity: We are traversing the vector, so O(N), again with map we are traversing the vector,
// so O(N) thus time complexity is O(2N)~O(N)
// space complexity: We are making a vector to store n elements, lets take
// the case when all the elements are different then we are making a map
// to store n elements and a set to store n elemnts, so space complexity is:
// o(3N)~ o(N)

#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <iterator>

using namespace std;

// class is user defined data type
class solve
{
    // access modifier
public:
    vector<int> intersection(vector<int> &nums1, vector<int> &nums2)
    {

        map<int, int> nummap;
        set<int> res;
        vector<int> ans;

        for (int i = 0; i < nums1.size(); i++)
        {
            nummap[nums1[i]]++;
        }

        for (int j = 0; j < nums2.size(); j++)
        {
            if (nummap.count(nums2[j]))
            {
                res.insert(nums2[j]);
            }
        }

        set<int>::iterator itr;
        for (itr = res.begin(); itr != res.end(); itr++)
        {
            ans.push_back(*itr);
        }
        return ans;
    }
};

int main()
{
    int n1, n2;
    cin >> n1 >> n2;
    vector<int> arr1;
    for (int i = 0; i < n1; i++)
    {
        int x;
        cin >> x;
        arr1.push_back(x);
    }
    vector<int> arr2;
    for (int i = 0; i < n2; i++)
    {
        int x;
        cin >> x;
        arr2.push_back(x);
    }

    // creating object of class solve
    solve obj;
    vector<int> res = obj.intersection(arr1, arr2);
    for (int i = 0; i < res.size(); i++)
    {
        cout << res[i] << " ";
    }

    return 0;
}