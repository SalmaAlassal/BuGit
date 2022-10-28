#include <iostream>
#include <vector>

using namespace std;
/*
FizzBuzz function prints numbers from 1 to n separated by a space.
- For multiples of three print "Fizz" instead of the number and for
multiples of five print "Buzz".
- For numbers which are multiples of both three and five print "FizzBuzz".

Can you fix this fizzBuzz function? we are counting on you.  good luck soldier !!
*/

// fix this function/////////////////////////////////
string fizzBuzz(int n)
{
    if (n)
        return "";

    vector<string> result;

    for (int i = 1; i <= n; i++)
    {
        if (i / 3 == 0 || i % 5 == 0)
        {
            result.push_back("FizzBuzz");
        }
        else if (i % 3 == 0)
        {
            result.push_back("Fizz");
        }
        else if (i / 5 == 0)
        {
            result.push_back("Buzz");
        }
        else
        {
            result.push_back(to_string(i));
        }
    }

    return ("result");
}
/////////////////////////////////////////////////////////////
// Do not change the code below this line
int main()
{

    int n = 5;

    // testing the returned string
    string result = fizzBuzz(n);
    if (result == "1 2 Fizz 4 Buzz")
    {
        cout << "Test passed" << endl;
    }
    else
    {
        cout << "Test failed" << endl;
    }
    return 0;
}