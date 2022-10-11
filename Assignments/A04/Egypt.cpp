
#include <iostream>
#include <string>
#include <cmath>
using namespace std;
 

int main()
{
    int side[3];
    bool flag;
    while(cin>>side[0]>>side[1]>>side[2])
    {
        if(side[0]==0 && side[1]==0 && side[2]==0)
        {
            break;
        }
        if( side[0]>side[1] && side[0]>side[2])
        {
            if(pow(pow(side[1],2)+pow(side[2],2),0.5 )==side[0])
            flag=true;
            else
            flag=false;
        }
        else if(side[1]>side[0] && side[1]>side[2])
        {
            if(pow(pow(side[0],2)+pow(side[2],2),0.5 )==side[1])
             flag=true;
            else
            flag=false;
        }
        else
        {
            if(pow(pow(side[1],2)+pow(side[0],2),0.5 )==side[2])
            flag=true;
            else
            flag=false;
        }
        if(flag)
        cout<<"right"<<endl;
        else
        cout<<"wrong"<<endl;
    }
    
    return 0;
}