#include "util.h"
/*�����first��last������first��last֮��Ĳ������*/
int getGreatest(int *datas,int first,int last);


int getGreatestSubOfArray(int * datas,int length)
{
	if(datas==NULL||length<=0) return -1;
	int curSum=0;
	int maxSum=0;
	//�ָ��������һ����׼��ָ�������֣��ֱ����������ֵ����ͣ�Ȼ�������ܵ�����
	for(int i=1;i<length-2;i++)
	{
		//����������������������������
		curSum=getGreatest(datas,0,i)+getGreatest(datas,i+1,length-1);
		if(curSum>maxSum)
		{
				maxSum=curSum;
		}
	}
	return maxSum;

}

/*�����first��last������first��last֮��Ĳ������*/
int getGreatest(int *datas,int first,int last)
{
	if(datas==NULL||first<0||last<0||first>=last) return -1;
	int curSum=0;
	int maxSum=0;
	for(int i=first;i<last;i++)//��first��last���α�����������������֮��Ĳ�ֵ��ת�����������������������
	{
			if(curSum<=0)//�����ǰ��С��0��������
			{
				curSum=datas[i+1]-datas[i];
			}else//������ϵ�ǰ��
			{
				curSum+=datas[i+1]-datas[i];
			}

			if(curSum>maxSum)//�������ֵ
			{
				maxSum=curSum;
			}
	}
	return maxSum;

}

int main(){
	int datas[]={1,4,5,2,3,1};
	std::cout<<"��������������͵�Ӧ�ã���Ʊ��������"<<std::endl;
	int max=getGreatestSubOfArray(datas,sizeof(datas)/sizeof(datas[0]));
	std::cout<<max<<std::endl;
	return 0;
}
