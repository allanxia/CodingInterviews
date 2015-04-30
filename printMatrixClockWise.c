#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include "util.h"

void printMatrixClock(int **numbers,int columns,int rows,int base);

void printMatrixClockWise(int **numbers,int columns,int rows){
	if(numbers==NULL||columns<=1||rows<=1) return;
	int base=0;
	while(base*2<columns||base*2<rows)//�����ù��ɷ������鼸��ֵ����ѭ���˳�������
	{
		printMatrixClock(numbers,columns,rows,base);
		base+=1;
	}
}

void printMatrixClock(int **numbers,int columns,int rows,int base){
	if(numbers==NULL||columns<=1||rows<=1||base<0) return;
	for(int i=base;i<columns-base;i++)//��ӡ����������
	{
			std::cout<<numbers[base][i]<<" ";
	}
	for(int i=base+1;i<rows-base;i++)//��ӡ�ұ�����
	{
			std::cout<<numbers[i][columns-base-1]<<" ";
	}
	for(int i=columns-base-2;i>=base;i--)//��ӡ����������
	{
			std::cout<<numbers[rows-base-1][i]<<" ";
	}
	for(int i=rows-base-2;i>base;i--)//��ӡ���������
	{
			std::cout<<numbers[i][base]<<" ";
	}
}

int main()
{
	//���ɾ���ķ���
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
