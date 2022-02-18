/* link: https://leetcode.com/problems/multiply-strings/  */

// time complexity: O(num1.size() * num2.size())
// space complexity: O(num1.size()+num2.size())

#include <iostream>
#include <string>
#include <vector>
using namespace std;

// class is a user defined datatype

class solve
{
    // access modifier
public:
    string num1;
    string num2;
    // member function()
    string multiply()
    {

        if (num1 == "0" || num2 == "0")
            return "0";

        vector<int> res(num1.size() + num2.size(), 0);
        for (int i = num1.size() - 1; i >= 0; i--)
        {
            for (int j = num2.size() - 1; j >= 0; j--)
            {
                res[i + j + 1] += (num1[i] - '0') * (num2[j] - '0');
                res[i + j] += res[i + j + 1] / 10;
                res[i + j + 1] = res[i + j + 1] % 10;
            }
        }
        int i = 0;
        string ans = "";
        while (res[i] == 0)
            i++;

        while (i < res.size())
        {
            ans += to_string(res[i++]);
        }
        return ans;
    }
};

int main()
{
    // creating objects
    solve obj;
    cin >> obj.num1 >> obj.num2;
    cout << obj.multiply() << endl;

    return 0;
}