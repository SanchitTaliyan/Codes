#include<iostream>
#include<string>
using namespace std;
int main()
{
  string str;
  string str2("ru");
  while(cin>>str)
  {
    int len=str.size();
    int b;
    int k=str.find(str2);
    if(k==4&&str.at(0)=='h'||k==3&&str.at(0)=='f')
    {
      b=str.find(str2,k+2);
    }
    else
    {
      b=k;
    }
    if(b+2<len)
    {
      str.insert(b+2,"/");
    }
    str.insert(b,".");
    if(str.at(0)=='f')
    {
      str.insert(3,"://");
      cout<<str<<endl;
    }
    else if(str.at(0)=='h')
    {
      str.insert(4,"://");
      cout<<str<<endl;
    }

  }
  return 0;
}
