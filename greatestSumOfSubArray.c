#include "util.h"
//输入是否正确的标示符
bool f_validate=true;

int getGreatestOfSubArray(int *datas,int length)
{
	if(datas==NULL|| length<=0)
	{
		f_validate=false;
		return 0;
	}		

	int curSum=0;
	int maxSum=0x80000000;//0x80000000是最小的负整数

	for(int i=0;i<length;i++)
	{
		//如果当前和小于等于0，那么舍弃掉它，从数组中的当前项开始累加
		if(curSum<=0)
		{
			curSum=datas[i];
		}else//否则当前和需要加上数组中的当前的项
		{
			curSum+=datas[i];
		}

		//每次计算一次当前的和后都需要更新最大和
		if(curSum>maxSum)
				maxSum=curSum;
	}

	return maxSum;
}

int main(){
	int datas[]={1,-2,3,10,-4,7,2,-5};
	int max=getGreatestOfSubArray(datas,sizeof(datas)/sizeof(datas[0]));
	std::cout<<"连续数组的最大和问题"<<std::endl;
	std::cout<<max<<std::endl;
	return 0;
}
