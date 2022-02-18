/* link: https://leetcode.com/problems/reverse-vowels-of-a-string/ */

// time complexity: we are traversing the half of the string length, so O(N/2)~O(N)
// space complexity: we are making integer and char variables, so its space complexity is O(1)

#include <iostream>
using namespace std;

// class is user defined data type
class solve
{
    // access modifier
public:
    string reverseVowels(string s)
    {

        for (int i = 0, j = s.size() - 1; i < j;)
        {
            if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u' || s[i] == 'A' || s[i] == 'E' || s[i] == 'I' ||
                s[i] == 'O' || s[i] == 'U')
            {

                if (s[j] == 'a' || s[j] == 'e' || s[j] == 'i' || s[j] == 'o' || s[j] == 'u' || s[j] == 'A' || s[j] == 'E' || s[j] == 'I' ||
                    s[j] == 'O' || s[j] == 'U')
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
    string s;
    cin >> s;
    // creating object of class solve
    solve obj;
    cout << obj.reverseVowels(s) << endl;

    return 0;
}