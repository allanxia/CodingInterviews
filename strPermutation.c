#include  "util.h"

bool is_swap(char * begin,char * end);
/*输入一个字符串，打印改字符串中字符的所有排列，很多其他的问题
 * 可以转换成这个问题，如如何使正方体的对应面上数字的和相同，八皇后问题等
 */
void strPermutation(char * origin,char *pBegin);

void  strPermutation(char * origin){
	if(origin==NULL) return ;
	strPermutation(origin,origin);
}

//origin指向字符串起始的指针，pBegin指向每次需要修改的指针
void strPermutation(char * origin,char *pBegin)
{
	if(*pBegin=='\0')
	{
		std::cout<<origin<<std::endl;
	}else
	{
		for(char *pCh=pBegin;*pCh!='\0';pCh++)
		{
				char temp=*pCh;
				*pCh=*pBegin;
				*pBegin=temp;
				
				strPermutation(origin,pBegin+1);

				temp=*pCh;
				*pCh=*pBegin;
				*pBegin=temp;

		}
	}

}

bool is_swap(char * begin,char * end)
{
	bool flag=true;
	for(char *p=begin;p<end;p++)
	{
		if(*p==*end) flag=false;
	}
	return flag;
}

int main()
{
	std::cout<<"字符串排列问题"<<std::endl;
	char  s[]="abbc";
	strPermutation(s);
	return 0;
}
