#include <iostream>
#include <vector>
using namespace std;

const int RANGE = 100;
int main()
{
    // get a random number and a random list of numbers
    srand((unsigned)time(NULL));
    int who_am_i;
    int n_crowd;
    vector<int> crowd;
    n_crowd = rand() % RANGE + 1;
    printf("how many are there = %d\n", n_crowd);
    who_am_i = rand() % RANGE;
    printf("who am i = %d\n", who_am_i);
    for (int i = 0; i < n_crowd; i++)
    {
        crowd.push_back(rand() % RANGE + 1);
    }
    // bubble sort the crowd
    for (int i = 0; i < n_crowd; i++)
    {
        for (int j = 0; j < n_crowd - i - 1; j++)
        {
            if (crowd[j] > crowd[j + 1])
            {
                int temp = crowd[j];
                crowd[j] = crowd[j + 1];
                crowd[j + 1] = temp;
            }
        }
    }
    // print the crowd
    for (int i = 0; i < n_crowd; i++)
    {
        cout << crowd[i] << " ";
    }
    cout << endl;
    //////////////////////////////////////////////
    // only change the code below
    // find me
    int left = 0;
    int right = n_crowd;
    int mid;
    bool found = false;
    while (left < right)
    {
        mid = (left + right) / 2;
        if (crowd[mid] == who_am_i)
        {
            cout << "You Found ME!" << endl;
            cout << "I am at index " << mid << endl;
        }
        else if (crowd[mid] > who_am_i)
        {
            right = mid - 1;
        }
        else
        {
            left = mid + 1;
        }
    }
    if (!found)
    {
        cout << "You didn't find me :(" << endl;
    }

    return 0;
}