
/**
* Name   : Sunil Rasaily
* Course : 4883-Programming Techniques
Program  : Railway
* Date   : 09/17/2022
**/
#include <iostream>
#include <stack>
using namespace std;

int main()
{
    int number, target[1000];

    stack<int> station;
    while (true)
    {
        cin >> number;
        if (number == 0)
            break;

        while (true)
        {
            cin >> target[0];
            if (target[0] == 0)
            {
                cout << endl;
                break;
            }
            for (int i = 1; i < number; i++)
            {
                cin >> target[i];
            }

            int currentCoach = 1;
            int counter = 0;
            int flag = 1;
            while (counter < number)
            {
                if (target[counter] == currentCoach) // if the first coach is = currentCoach
                {                                    // then no need to put on the stack and is can go directly to rail B
                    counter++;
                    currentCoach++;
                }
                else if (!station.empty() && station.top() == target[counter]) // if the target coach is on top of the stack
                {
                    station.pop();
                    counter++;
                }
                else if (currentCoach <= number) // will store the coach on the stack
                {
                    station.push(currentCoach++);
                }
                else // cannot achieve the goal  
                {
                    flag = 0;
                    while (!station.empty()) 
                    {
                        station.pop();
                    }
                
                    break;
                }
            }
            if (flag)
                cout << "Yes\n";
            else
                cout << "No\n";
        }
    }

    return 0;
}
