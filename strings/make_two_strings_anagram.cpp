/*link: https://leetcode.com/problems/minimum-number-of-steps-to-make-two-strings-anagram/ */

// time complexity: s.size()+t.size()= O(N)
// space complexity: as we have maximum 26 apphabets, so map will maximum store 26 keys
// so ,space complexity will be O(1)

#include <iostream>
#include <map>
using namespace std;

// class is user defined datatype
class solve
{
    // access modifier
public:
    string s;
    string t;
    // member functions()
    int minSteps()
    {

        map<char, int> smap;

        for (int i = 0; i < s.size(); i++)
        {
            smap[s[i]]++;
        }
        int ans = 0;
        for (int i = 0; i < t.size(); i++)
        {
            if (smap[t[i]] > 0)
            {
                smap[t[i]]--;
            }

            else
            {
                ans += 1;
            }
        }
        return ans;
    }
};

int main()
{

    // making objects of class solve
    solve obj;
    cin >> obj.s;
    cin >> obj.t;

    cout << obj.minSteps() << endl;
    return 0;
}