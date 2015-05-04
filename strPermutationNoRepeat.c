#include  "util.h"

/*����һ���ַ�������ӡ���ַ������ַ����������У��ܶ�����������
 * ����ת����������⣬�����ʹ������Ķ�Ӧ�������ֵĺ���ͬ���˻ʺ������
 */


//�ж��Ƿ񽻻��ĺ���
bool is_swap(char * begin,char *end);

//��������ָ��ָ��ı����ĺ���
void swap(char * p1,char *p2);

//�ַ������к���
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
		//pBeginָ������ַ�����Ԫ��ֻ��һ���Ĳ���,pChָ������ַ����е�ʣ�ಿ��
		for(char *pCh=pBegin;*pCh!='\0';pCh++)
		{
				if(is_swap(pBegin,pCh))	
				{
					swap(pBegin,pCh);//����pBegin��pCh

					strPermutation(origin,pBegin+1);

					swap(pBegin,pCh);//����pBegin��pCh
				}
		}
	}

}

//�ж��Ƿ񽻻������[begin,end)�����ڴ�����endָ��ָ����ͬ��ֵ������false��ʾ����Ҫ����
bool is_swap(char * begin,char * end)
{
	bool flag=true;
	for(char *p=begin;p<end;p++)
	{
		if(*p==*end) flag=false;
	}
	return flag;
}

//��������ָ��ָ���ֵ
void swap(char * p1,char *p2){
	char tmp=*p1;
	*p1=*p2;
	*p2=tmp;
}
int main()
{
	std::cout<<"�����ظ��ַ�����������"<<std::endl;
	char  s[]="abbc";
	strPermutation(s);
	return 0;
}
