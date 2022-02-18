/* link: https://leetcode.com/problems/add-binary/  */
// time complexity: for add string 1function , we are traversing both length of the string so, o(N)
// space complexity: for add string1 function, we are using a vector to store values of size O(N+1)
// where N is length of the string whose size is bigger in both of the strings
#include <iostream>
#include <string>
#include <vector>
#include <algorithm> //for reverse() function
using namespace std;

// class is user defined data type
class solve
{
    // access modifier
public:
    // member functions()
    string addBinary1(string a, string b)
    {
        if (a == "0")
            return b;
        if (b == "0")
            return a;

        int n;
        if (a.size() > b.size())
        {
            n = a.size() + 1;
        }
        else
        {
            n = b.size() + 1;
        }
        vector<int> res(n + 1, 0);

        int i = a.size() - 1;
        int j = b.size() - 1;

        while (i >= 0 && j >= 0)
        {

            res[n] += (a[i] - '0') + (b[j] - '0');
            res[n - 1] += res[n] / 2;
            res[n] %= 2;
            n--;
            i--;
            j--;
        }

        while (n && i >= 0)
        {
            res[n] += (a[i] - '0');
            res[n - 1] += res[n] / 2;
            res[n] %= 2;
            i--;
            n--;
        }

        while (n && j >= 0)
        {
            res[n] += (b[j] - '0');
            res[n - 1] += res[n] / 2;
            res[n] %= 2;
            j--;
            n--;
        }
        i = 0;
        while (res[i] == 0)
            i++;

        string ans = "";

        while (i < res.size())
        {
            ans += to_string(res[i]);
            i++;
        }

        return ans;
    }

    string addBinary2(string a, string b)
    {
        int i = a.size() - 1, j = b.size() - 1, carry = 0;
        string ans;
        while (i >= 0 || j >= 0 || carry)
        {
            if (i >= 0)
            {
                carry += a[i] - '0';
                i--;
            }
            if (j >= 0)
            {
                carry += b[j] - '0';
                j--;
            }

            ans += (carry % 2) + '0';
            carry /= 2;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

int main()
{
    string a, b;
    cin >> a >> b;
    // creating object of class solve
    solve obj;
    cout << obj.addBinary1(a, b) << endl;
    cout << obj.addBinary2(a, b) << endl;
    return 0;
}