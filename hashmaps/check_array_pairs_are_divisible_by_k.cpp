/* link: https://leetcode.com/problems/check-if-array-pairs-are-divisible-by-k/   */
// time complexity: we are traversing vector of size n and also traversing array of size k, so O(N+k)
// space complexity: we are making vector of size n and array of size k, so O(N+k)

#include <iostream>
#include <vector>

using namespace std;

// class is user defined data type
class solve
{
    // access modifier
public:
    bool canArrange(vector<int> &arr, int k)
    {
        int freq[k];
        for (int i = 0; i < k; i++)
        {
            freq[i] = 0;
        }
        // frquency of xero should be even

        for (int i = 0; i < arr.size(); i++)
        {
            int rem = arr[i] % k;
            if (rem < 0)
            {
                rem = rem + k;
            }
            freq[rem]++;
        }

        for (int i = 1; i < k; i++)
        {
            if (freq[i] != freq[k - i])
                return false;
        }

        if (freq[0] % 2 != 0)
            return false;

        return true;
    }
};

int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> arr;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        arr.push_back(x);
    }

    // creating object of class solve
    solve obj;
    cout << obj.canArrange(arr, k) << endl;

    return 0;
}