/* link:https://leetcode.com/problems/reverse-only-letters/ */

// time complexity: we are traversing the string only half so O(N/2)~O(N)
// space complexity:we have made simple integer and char variables,so O(1)

#include <iostream>
using namespace std;

// class is  auser defined data type
class solve
{
    // access modifier
public:
    string s;
    // member functions()
    string reverseOnlyLetters()
    {

        for (int i = 0, j = s.size() - 1; i < j;)
        {
            if (isalpha(s[i]))
            {
                if (isalpha(s[j]))
                {
                    char temp = s[i];
                    s[i] = s[j];
                    s[j] = temp;
                    i++;
                }
                j--;
            }
            else
                i++;
        }

        return s;
    }
};

int main()
{
    // creating objects
    solve obj;
    // input string taking
    cin >> obj.s;
    cout << obj.reverseOnlyLetters() << endl;
    return 0;
}