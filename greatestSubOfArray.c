#include "util.h"
/*计算从first到last，包括first和last之间的差的最大和*/
int getGreatest(int *datas,int first,int last);


int getGreatestSubOfArray(int * datas,int length)
{
	if(datas==NULL||length<=0) return -1;
	int curSum=0;
	int maxSum=0;
	//分割，将数组以一个基准点分割成两部分，分别求两个部分的最大和，然后再求总的最大和
	for(int i=1;i<length-2;i++)
	{
		//子问题就是连续子数组的最大和问题
		curSum=getGreatest(datas,0,i)+getGreatest(datas,i+1,length-1);
		if(curSum>maxSum)
		{
				maxSum=curSum;
		}
	}
	return maxSum;

}

/*计算从first到last，包括first和last之间的差的最大和*/
int getGreatest(int *datas,int first,int last)
{
	if(datas==NULL||first<0||last<0||first>=last) return -1;
	int curSum=0;
	int maxSum=0;
	for(int i=first;i<last;i++)//从first到last依次遍历，计算相邻两项之间的差值，转换成了连续数组的最大和问题
	{
			if(curSum<=0)//如果当前和小于0，丢弃它
			{
				curSum=datas[i+1]-datas[i];
			}else//否则加上当前项
			{
				curSum+=datas[i+1]-datas[i];
			}

			if(curSum>maxSum)//更新最大值
			{
				maxSum=curSum;
			}
	}
	return maxSum;

}

int main(){
	int datas[]={1,4,5,2,3,1};
	std::cout<<"连续子数组的最大和的应用，股票交易问题"<<std::endl;
	int max=getGreatestSubOfArray(datas,sizeof(datas)/sizeof(datas[0]));
	std::cout<<max<<std::endl;
	return 0;
}
