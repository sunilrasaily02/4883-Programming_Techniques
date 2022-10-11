#include <iostream>

using namespace std;
int countCycle(int num)
{
    int counter=1;
    while (num!=1)
    {
        counter++;
        if(num%2) // if Odd
        {
            num = num*3 +1;
        }
        else
        {
            num=num/2; // if Even 
        }
    }
    return counter;
    
}



int main()
{
int input1,input2;
int max=0;
int temp;
while (cin>>input1 && cin>>input2)
{
    max=0;
    for(int i=input1;i<=input2;i++)
    {
        temp=countCycle(i);
        if(temp>max)
        max=temp;

    }
cout<<input1<<" "<<input2<<" "<<max<<endl;
}


    return 0;
}