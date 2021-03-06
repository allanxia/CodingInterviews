

all:printMatrixClockWise binaryTreeMirror getGreatestOfSubArray getGreatestOfStack \
		minStack strPermutation  judgeCube strPermutationRepeat
.PHONY:all

#二叉树的镜像
binaryTreeMirror:binaryTreeMirror.o binaryTree.o 
	g++ -o binaryTreeMirror binaryTreeMirror.o binaryTree.o
binaryTreeMirror.o:binaryTreeMirror.c 
	g++ -c binaryTreeMirror.c 
binaryTree.o:binaryTree.c binaryTree.h
	g++ -c binaryTree.c 

#顺时针打印矩阵
printMatrixClockWise:printMatrixClockWise.o util.o
	g++ -o printMatrixClockWise printMatrixClockWise.o util.o 
printMatrixClockWise.o:printMatrixClockWise.c util.h  
	g++ -c printMatrixClockWise.c
util.o:util.c util.h
	g++ -c util.c

#连续子数组的最大和问题
getGreatestOfSubArray:getGreatestSumOfSubArray.o util.o
	g++ -o getGreatestOfSubArray getGreatestSumOfSubArray.o util.o
getGreatestSumOfSubArray.o:greatestSumOfSubArray.c util.h
	g++  -c greatestSumOfSubArray.c -o getGreatestSumOfSubArray.o 
 
#连续子数组的最大和的应用，股票交易问题
getGreatestOfStack:greatestSubOfArray.o util.o
	g++ -o getGreatestOfStack greatestSubofArray.o util.o
greatestSubOfArray.o:greatestSubOfArray.c util.h
	g++ -c greatestSubOfArray.c

#包含min函数的栈
minStack:minStack.o
	g++ -o minStack minStack.o
minStack.o:minStack.c util.h
	g++ -c minStack.c

#字符串排列问题，1重复字符
strPermutation:strPermutation.o
	g++ -o strPermutation strPermutation.o
strPermutation.o:strPermutationNoRepeat.c util.h
	g++ -c strPermutationNoRepeat.c

#字符串排列问题的应用，正方体对应面顶点和相同，八皇后问题
judgeCube:judgeCube.o
	g++ -o judgeCube judgeCube.o 
judgeCube.o:judgeCube.c util.h
	g++ -c judgeCube.c

#字符串排列问题，字符串中有重复字符
strPermutationRepeat:strPermutationRepeat.o
	g++ -o strPermutationRepeat strPermutationRepeat.o
strPermutationRepeat.o:strPermutationRepeat.c util.h
	g++ -c strPermutationRepeat.c



.PHONY:clean
clean:
	del *.o *~ *.swp
cleanAll:
	del *.o *~ *.exe *.swp
