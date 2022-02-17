/*link: https://leetcode.com/problems/robot-return-to-origin/submissions/  */

// time complexity: we are travesing the string moves so,O(N)
// space complexity: We are making 4 integers. So, space complexity is O(1)

#include <iostream>
using namespace std;
// class is a user defined data type
class solve
{
    // access modifier
public:
    string moves;
    // member functions()
    bool judgeCircle()
    {

        int left, right, up, down;
        left = right = up = down = 0;
        // int left=0;
        // int right=0;
        // int up=0;
        // int down=0;

        for (int i = 0; i < moves.size(); i++)
        {

            if (moves[i] == 'U')
                up++;

            else if (moves[i] == 'D')
                down++;

            else if (moves[i] == 'L')
                left++;

            else if (moves[i] == 'R')
                right++;
        }
        if ((up == down) && (left == right))
            return true;

        return false;
    }
};

class solution
{
    // access modifier
public:
    string moves;
    // member function()
    bool judgeCircle()
    {

        int up = 0, left = 0;

        for (int i = 0; i < moves.size(); i++)
        {
            switch (moves[i])
            {
            case 'U':
                up++;
                break;
            case 'D':
                up--;
                break;
            case 'L':
                left++;
                break;
            case 'R':
                left--;
                break;
            }
        }
        return (up == 0 && left == 0);
    }
};

int main()
{
    // creating object of class solve
    solve obj;
    cin >> obj.moves;
    cout << obj.judgeCircle() << endl;

    // creating object of class solution
    solution obj2;
    cin >> obj2.moves;
    cout << obj2.judgeCircle() << endl;
    return 0;
}