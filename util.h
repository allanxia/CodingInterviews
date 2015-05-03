#ifndef __UTIL
#define __UTIL
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <stack>
#include <queue>

//打印数组
template<class T>
void printArrayT(T * t,int len){
	for(int i=0;i<len;i++)
			std::cout<<t[i]<<" ";
	std::cout<<std::endl;
}


//打印矩阵
template <class T>
void printMatrix(T ** numbers,int rows,int columns){
	for(int i=0;i<rows;i++)
	{
			for(int j=0;j<columns;j++)
					std::cout<<numbers[i][j]<<" ";
		std::cout<<std::endl;
	}
}

#endif
