/* link : https://leetcode.com/problems/increasing-decreasing-string/ */

// Time complexity: lets say worst case when all the letters are same
// then while loop will run N/2 times and for loops are running 26*2 timese in 1 while loop
// so, worst case time complexity will be O(N/2 *26*2)~ O(N)
//  space complexity: As we are storing 26 elements in vector, so it should be O(26)~ constant
// so, space complexity will be O(1)

#include <iostream>
using namespace std;
// class is user defined data type
class solve
{
    // Access modifier
public:
    string s;
    // Member functions()

    string sortString()
    {
        string result;
        int arr[26] = {0};

        for (int i = 0; i < s.size(); i++)
        {
            arr[s[i] - 'a']++;
        }

        while (true)
        {
            for (int i = 0; i < 26; i++)
            {
                if (arr[i] > 0)
                {
                    arr[i]--;
                    result += i + 'a';
                }
            }

            for (int j = 25; j >= 0; j--)
            {
                if (arr[j] > 0)
                {
                    arr[j]--;
                    result += j + 'a';
                }
            }
            if (result.size() == s.size())
                break;
        }
        return result;
    }
};

int main()
{
    // making object of class
    solve obj;
    // making string
    cin >> obj.s;
    cout << obj.sortString() << endl;
    return 0;
}
