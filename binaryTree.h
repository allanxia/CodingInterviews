#ifndef __BinaryTree
#define __BinaryTree

#include <stdio.h>
#include <stdlib.h>
#include <queue>
#include <iostream>

#ifdef PUREC
typedef struct _BinaryTreeNode{
	int m_value;
	struct _BinaryTreeNode * pLeft;
	struct _BinaryTreeNode * pRight;
}BinaryTreeNode;
#else
class BinaryTreeNode {
	public:
	BinaryTreeNode(int value,BinaryTreeNode *pleft=NULL,BinaryTreeNode *pright=NULL){
		m_value=value;
		pLeft=pleft;
		pRight=pright;
	}
	public:
		BinaryTreeNode * pLeft;
		BinaryTreeNode * pRight;
		int m_value;
};
#endif

//Öð²ã´òÓ¡¶þ²æÊ÷
void printBinaryTreeHier(BinaryTreeNode *root);



#endif
