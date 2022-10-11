 
#include <iostream>
#include <cmath>

#include <string>
using namespace std;

int main()
{ 
    long long num1,num2,carry;
    int counter=0;
    while(cin>>num1>>num2)
    {
        counter=0;
        carry=0;
        if(num1==0 && num2==0)
        {
            break;
        }
        carry=0;
        counter=0;
        int temp;
         while(num1!=0 || num2!=0)
         {
            temp=(num1%10) +(num2%10) +carry;
            if(temp>=10)
            {
                counter++;
                carry=1;
            }
            else
            carry=0;
            
            num1/=10;
            num2/=10;
         }
         
         if(counter==0)
         {
             cout<<"No ";
         }
         else
         cout<<counter<<" ";
         
         if(counter==1 || counter==0)
         cout<<"carry operation.\n";
         else
          cout<<"carry operations.\n";
        
    }
    
    return 0;
}