
/**
* Name   : Sunil Rasaily
* Course : 4883-Programming Techniques
Program  : Traffic Lights
* Date   : 09/12/2022
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;
bool checkGreen(int time, int cycleTime)
{
    int green = cycleTime - 5;
    int fullLifeCycleTime = 2* cycleTime; // this integer to stor the full life time of a traffic light ==
    //life cycle explained ==  cycleTime(while Red) + cycleTime-5(while green) + 5 (while orange)
    if ((time % fullLifeCycleTime) < green)
        return true;
    else
        return false;
}

int main()
{
    vector<int> arr;
    int input;
    int terminate = 0;
    while (cin >> input)
    {

        if (input == 0)
        {
             if(arr.empty())
             {// if we read a zero'0' and the vector is empty that means the end of the program 
             return 0;
             }

            sort(arr.begin(), arr.end()); // sort the vector ascending

            int min = arr[0] - 5; // the time of the least traffic cycle will be green
            bool flag = true;
            for (int i = min + 1; i < 5 * 60 * 60; i++) // we will start counting after the first traffic light goes orange
            {
                flag = true;
                for (int j = 0; j < arr.size(); j++)
                {
                    if (checkGreen(i, arr[j]))
                        ;
                    else
                    {
                        flag = false;
                        break;
                    }
                }
                if (flag)
                {

                    int hour = i / (60 * 60);
                    int minute = (i / 60) % 60;
                    int sec = i % 60;
                    cout << setfill('0') << setw(2);
                    cout << hour << ":" << setfill('0') << setw(2) << minute << ":" << setfill('0') << setw(2) << sec << endl;
                    arr.clear();
                    break;
                }
            }
            if(!flag)
            cout<<"Signals fail to synchronise in 5 hours \n";
            arr.clear();
        }
        else
        {
            arr.push_back(input);
        }
    }
    return 0;
}
