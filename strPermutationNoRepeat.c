#include  "util.h"

/*输入一个字符串，打印改字符串中字符的所有排列，很多其他的问题
 * 可以转换成这个问题，如如何使正方体的对应面上数字的和相同，八皇后问题等
 */


//判断是否交换的函数
bool is_swap(char * begin,char *end);

//交换两个指针指向的变量的函数
void swap(char * p1,char *p2);

//字符串排列函数
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
		//pBegin指向的是字符串中元素只有一个的部分,pCh指向的是字符串中的剩余部分
		for(char *pCh=pBegin;*pCh!='\0';pCh++)
		{
				if(is_swap(pBegin,pCh))	
				{
					swap(pBegin,pCh);//交换pBegin和pCh

					strPermutation(origin,pBegin+1);

					swap(pBegin,pCh);//交换pBegin和pCh
				}
		}
	}

}

//判断是否交换，如果[begin,end)区间内存在与end指针指向相同的值，返回false表示不需要交换
bool is_swap(char * begin,char * end)
{
	bool flag=true;
	for(char *p=begin;p<end;p++)
	{
		if(*p==*end) flag=false;
	}
	return flag;
}

//交换两个指针指向的值
void swap(char * p1,char *p2){
	char tmp=*p1;
	*p1=*p2;
	*p2=tmp;
}
int main()
{
	std::cout<<"消除重复字符串排列问题"<<std::endl;
	char  s[]="abbc";
	strPermutation(s);
	return 0;
}
