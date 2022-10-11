 
#include <iostream>
#include <cmath>
#include <string>
using namespace std;

int main()
{
    string num;
    long long count=0;
    int k=0;
    while(cin>>num)
    {
        
        k=0;
        count=0;
        
        for(int i=num.length()-1;i>=0;i--)
        {
            int temp=num[i]-'0';
            count+=temp*( pow(2,k+1)-1);
            k++;
        }
        if(count==0)
        {
            break;
        }
        cout<<count<<endl;
        
        
    }
    return 0;
}