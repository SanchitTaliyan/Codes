#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;

char s[52];
char ss[52];
int main()
{
	while(scanf("%s",s)!=EOF)
	{
		int flag=0;
		memset(ss,'\0',sizeof(ss));
		int len=strlen(s);
		int cnt=0;
		for(int i=0;i<len;)
		{
			if(i==0)
			{
				if(s[i]=='h'&&s[i+1]=='t'&&s[i+2]=='t'&&s[i+3]=='p')
				{
					printf("http://");
					i+=4;
					continue; //这里wa了一次，没有加这个结果和应该输出的不一样
				}
				if(s[i]=='f'&&s[i+1]=='t'&&s[i+2]=='p')
				{
					printf("ftp://");
					i+=3;
					continue;//一样
				}
			}
			else
			{
				ss[cnt++]=s[i++];
				if(s[i]=='r'&&s[i+1]=='u')
				{
					ss[cnt]='\0';
					printf("%s.ru",ss);
					if((i+1)!=(len-1)) printf("/");//！！！！！httpcsdfvdru这样的样例应该输出htt：//pcsdfvd.ru而不是htt：//pcsdfvd.ru/
					i+=2;
					while(i<len)
					printf("%c",s[i++]);//上面的执行完了以后就把原来的剩下的输出就好了
					break;//退出
				}
			}
		}
		cout<<endl;
	}
}
