#include "util.h"
//�����Ƿ���ȷ�ı�ʾ��
bool f_validate=true;

int getGreatestOfSubArray(int *datas,int length)
{
	if(datas==NULL|| length<=0)
	{
		f_validate=false;
		return 0;
	}		

	int curSum=0;
	int maxSum=0x80000000;//0x80000000����С�ĸ�����

	for(int i=0;i<length;i++)
	{
		//�����ǰ��С�ڵ���0����ô�����������������еĵ�ǰ�ʼ�ۼ�
		if(curSum<=0)
		{
			curSum=datas[i];
		}else//����ǰ����Ҫ���������еĵ�ǰ����
		{
			curSum+=datas[i];
		}

		//ÿ�μ���һ�ε�ǰ�ĺͺ���Ҫ��������
		if(curSum>maxSum)
				maxSum=curSum;
	}

	return maxSum;
}

int main(){
	int datas[]={1,-2,3,10,-4,7,2,-5};
	int max=getGreatestOfSubArray(datas,sizeof(datas)/sizeof(datas[0]));
	std::cout<<"�����������������"<<std::endl;
	std::cout<<max<<std::endl;
	return 0;
}
