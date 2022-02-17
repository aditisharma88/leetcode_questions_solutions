/*link : https://leetcode.com/problems/ransom-note/   */
// time complexity: As we are traversing the string ransomNote and magazine, so
// time complexity will be = ransomNote.size()+magazine.size()=O(N+N)~O(N)

// space complexity:as we are making a map by inserting elements of magazine, so
// the worst case will be all the elements are different in magazine so ,O(magazine.size())~O(N)

#include <iostream>
#include <map>
using namespace std;

// class is a user defined data type
class solve
{
    // access modifier
public:
    // string ransomNote;
    // string magazine;
    // member functions()
    bool canConstruct(string ransomNote, string magazine)
    {
        if (magazine.size() < ransomNote.size())
            return false;

        map<char, int> magazinemap;

        for (int i = 0; i < magazine.size(); i++)
        {
            magazinemap[magazine[i]]++;
        }

        for (int i = 0; i < ransomNote.size(); i++)
        {
            if (magazinemap[ransomNote[i]] > 0)
            {
                magazinemap[ransomNote[i]]--;
            }
            else
            {
                return false;
            }
        }
        return true;
    }
};

int main()
{
    string ransomeNote;
    string magazine;
    cin >> ransomeNote >> magazine;
    // creating object of class solve
    solve obj;
    cout << obj.canConstruct(ransomeNote, magazine) << endl;
    return 0;
}