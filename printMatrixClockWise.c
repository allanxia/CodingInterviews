#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include "util.h"

void printMatrixClock(int **numbers,int columns,int rows,int base);

void printMatrixClockWise(int **numbers,int columns,int rows){
	if(numbers==NULL||columns<=1||rows<=1) return;
	int base=0;
	while(base*2<columns||base*2<rows)//可以用归纳法，试验几个值发现循环退出的条件
	{
		printMatrixClock(numbers,columns,rows,base);
		base+=1;
	}
}

void printMatrixClock(int **numbers,int columns,int rows,int base){
	if(numbers==NULL||columns<=1||rows<=1||base<0) return;
	for(int i=base;i<columns-base;i++)//打印最上面那行
	{
			std::cout<<numbers[base][i]<<" ";
	}
	for(int i=base+1;i<rows-base;i++)//打印右边那列
	{
			std::cout<<numbers[i][columns-base-1]<<" ";
	}
	for(int i=columns-base-2;i>=base;i--)//打印最下面那行
	{
			std::cout<<numbers[rows-base-1][i]<<" ";
	}
	for(int i=rows-base-2;i>base;i--)//打印最左边那行
	{
			std::cout<<numbers[i][base]<<" ";
	}
}

int main()
{
	//生成矩阵的方法
	int **p=new int*[4];
	for(int i=0;i<4;i++){
		p[i]=new int[4];
		for(int j=0;j<4;j++)
				p[i][j]=4*i+j+1;
	}
	printMatrix(p,4,4);
	printMatrixClockWise(p,4,4);
	for(int i=0;i<4;i++)
			delete []p[i];
	delete []p;
	return 0;
}
