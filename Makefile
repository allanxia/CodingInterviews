

all:printMatrixClockWise binaryTreeMirror
.PHONY:all

#¶þ²æÊ÷µÄ¾µÏñ
binaryTreeMirror:binaryTreeMirror.o binaryTree.o 
	g++ -o binaryTreeMirror binaryTreeMirror.o binaryTree.o
binaryTreeMirror.o:binaryTreeMirror.c 
	g++ -c binaryTreeMirror.c 
binaryTree.o:binaryTree.c binaryTree.h
	g++ -c binaryTree.c 

#Ë³Ê±Õë´òÓ¡¾ØÕó
printMatrixClockWise:printMatrixClockWise.o util.o
	g++ -o printMatrixClockWise printMatrixClockWise.o util.o 
printMatrixClockWise.o:printMatrixClockWise.c util.h  
	g++ -c printMatrixClockWise.c
util.o:util.c util.h
	g++ -c util.c


.PHONY:clean
clean:
	del *.o *~
cleanAll:
	del *.o *~ *.exe
