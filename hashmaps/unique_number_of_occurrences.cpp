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

using namespace std;

// class is user defined data type
class solve
{
    // access modifier
public:
    // member functions()
    bool uniqueOccurrences(vector<int> &arr)
    {
        map<int, int> arrmap;
        for (int i = 0; i < arr.size(); i++)
        {
            arrmap[arr[i]]++;
        }

        set<int> arrset;
        map<int, int>::iterator itr;
        for (itr = arrmap.begin(); itr != arrmap.end(); itr++)
        {
            arrset.insert(itr->second);
        }

        if (arrset.size() == arrmap.size())
            return true;

        return false;
    }
};

int main()
{
    int n;
    cin >> n;
    vector<int> arr;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        arr.push_back(x);
    }

    // creating object of class solve
    solve obj;
    cout << obj.uniqueOccurrences(arr) << endl;

    return 0;
}