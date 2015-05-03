#include "util.h"

void numPermutation(int *num,int *pBegin,int len);

//正方体中三组对象相等的判断函数
bool judge(int *num,int len);

//符合8皇后位置的组合
bool eightQueen(int *num,int len);

void numPermutation(int * num,int len)
{
	if(num==NULL) return ;
	numPermutation(num,num,len);
}
void numPermutation(int *num,int *pBegin,int len)
{
	if((pBegin-num)==len)
	{
		if(judge(num,len))
		{
			printArrayT(num,len);
		}
				
	}
	else
	{
		for(int* i=pBegin;i<pBegin+len-(pBegin-num);i++)
		{
			int tmp=*pBegin;
			*pBegin=*i;
			*i=tmp;

			numPermutation(num,pBegin+1,len);
			
			tmp=*i;
			*i=*pBegin;
			*pBegin=tmp;

		}

	}

}

bool judge(int *num,int len)
{
	if(num==NULL||len!=8) return false;
	if((num[0]+num[1]+num[2]+num[3])==(num[4]+num[5]+num[6]+num[7])&&
					(num[0]+num[2]+num[4]+num[6])==(num[1]+num[3]+num[5]+num[7])&&
					(num[0]+num[1]+num[4]+num[5])==(num[2]+num[3]+num[6]+num[7]))
			return true;
	return false;
}

bool eightQueen(int *num,int len)
{
	if(num==NULL||len!=8) return false;
		for(int i=0;i<len;i++)
		{
			for(int j=0;j<len;j++)
			{
				if(i!=j)
				{
					if((i-j)==(num[i]-num[j])||(i-j)==(num[j]-num[i]))
							return false;
				}
			}
		}
		return true;
}
int main()
{
	int arr[]={1,2,3,4,5,6,7,8};
	numPermutation(arr,sizeof(arr)/sizeof(arr[0]));
	return 0;
}
