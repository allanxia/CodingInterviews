

all:printMatrixClockWise binaryTreeMirror getGreatestOfSubArray getGreatestOfStack \
		minStack strPermutation 
.PHONY:all

#�������ľ���
binaryTreeMirror:binaryTreeMirror.o binaryTree.o 
	g++ -o binaryTreeMirror binaryTreeMirror.o binaryTree.o
binaryTreeMirror.o:binaryTreeMirror.c 
	g++ -c binaryTreeMirror.c 
binaryTree.o:binaryTree.c binaryTree.h
	g++ -c binaryTree.c 

#˳ʱ���ӡ����
printMatrixClockWise:printMatrixClockWise.o util.o
	g++ -o printMatrixClockWise printMatrixClockWise.o util.o 
printMatrixClockWise.o:printMatrixClockWise.c util.h  
	g++ -c printMatrixClockWise.c
util.o:util.c util.h
	g++ -c util.c

#�������������������
getGreatestOfSubArray:getGreatestSumOfSubArray.o util.o
	g++ -o getGreatestOfSubArray getGreatestSumOfSubArray.o util.o
getGreatestSumOfSubArray.o:greatestSumOfSubArray.c util.h
	g++  -c greatestSumOfSubArray.c -o getGreatestSumOfSubArray.o 
 
#��������������͵�Ӧ�ã���Ʊ��������
getGreatestOfStack:greatestSubOfArray.o util.o
	g++ -o getGreatestOfStack greatestSubofArray.o util.o
greatestSubOfArray.o:greatestSubOfArray.c util.h
	g++ -c greatestSubOfArray.c

#����min������ջ
minStack:minStack.o
	g++ -o minStack minStack.o
minStack.o:minStack.c util.h
	g++ -c minStack.c

#�ַ�����������
strPermutation:strPermutation.o
	g++ -o strPermutation strPermutation.o
strPermutation.o:strPermutation.c util.h
	g++ -c strPermutation.c



.PHONY:clean
clean:
	del *.o *~ *.swp
cleanAll:
	del *.o *~ *.exe *.swp
