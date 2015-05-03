#include  "util.h"

bool is_swap(char * begin,char * end);
/*����һ���ַ�������ӡ���ַ������ַ����������У��ܶ�����������
 * ����ת����������⣬�����ʹ������Ķ�Ӧ�������ֵĺ���ͬ���˻ʺ������
 */
void strPermutation(char * origin,char *pBegin);

void  strPermutation(char * origin){
	if(origin==NULL) return ;
	strPermutation(origin,origin);
}

//originָ���ַ�����ʼ��ָ�룬pBeginָ��ÿ����Ҫ�޸ĵ�ָ��
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
	std::cout<<"�ַ�����������"<<std::endl;
	char  s[]="abbc";
	strPermutation(s);
	return 0;
}
