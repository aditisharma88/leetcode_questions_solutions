/*link: https://leetcode.com/problems/valid-anagram/    */

#include <iostream>
#include <map>
#include <string>

using namespace std;

// Method-1
// Time complexity: O(n+n)
// Space complexity: O(N+N)
//  class is user defined data type
class solve1
{
    // Access specifier
public:
    string s;
    string t;
    // Member functions()
    bool isAnagram()
    {

        if (t.size() > s.size())
        {
            return false;
        }
        map<char, int> smap;

        for (int i = 0; i < s.size(); i++)
        {
            smap[s[i]]++;
        }

        map<char, int> tmap;
        for (int i = 0; i < t.size(); i++)
        {
            tmap[t[i]]++;
        }

        map<char, int>::iterator itr;

        for (itr = smap.begin(); itr != smap.end(); itr++)
        {
            if (tmap.find(itr->first) == tmap.end())
            {
                return false;
            }
            else if (tmap[itr->first] != itr->second)
            {
                return false;
            }
        }
        return true;
    }
};

// Method-2
// Time complexity: O(N+N)
// Space complexity: O(N)
// class is user defined data type
class solve2
{
    // Access Modifier
public:
    string s;
    string t;
    // Member functions()

    bool isAnagram()
    {
        if (t.size() != s.size())
            return false;
        map<char, int> tmap;

        for (int i = 0; i < t.size(); i++)
        {
            tmap[t[i]]++;
        }

        for (int i = 0; i < s.size(); i++)
        {
            if (tmap[s[i]] <= 0)
                return false;

            tmap[s[i]]--;
        }
        return true;
    }
};

int main()
{
    solve1 obj1;
    cin >> obj1.s;
    cin >> obj1.t;
    cout << obj1.isAnagram() << endl;

    solve2 obj2;
    cin >> obj2.s >> obj2.t;
    cout << obj2.isAnagram() << endl;
    return 0;
}