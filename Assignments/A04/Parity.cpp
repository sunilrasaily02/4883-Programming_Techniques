
#include <iostream>
#include <string>

using namespace std;


string decToBinary(int n,int &count)
{ 
    string str="";
  count=0;
    int i = 0;
    while (n > 0) {
 
       
        str+= (n%2)?'1':'0';
        if(n%2)
        count++;
        n = n / 2;
        i++;
    }
 
 string modifiedSTR="";    
    for (int j = str.length() - 1; j >= 0; j--)
       modifiedSTR+=str[j];
       
       return modifiedSTR;
}


int main()
{
   long long num;
   int parity=0;
   string str;
   while(cin>>num)
   {
       parity=0;
       if(num==0)
       break;
       
       str=decToBinary(num,parity);
       
       cout<<"The parity of "<<str<<" is "<<parity<<" (mod 2)."<<endl;
   }

    return 0;
}