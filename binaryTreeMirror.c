#include "binaryTree.h"

//二叉树的镜像，使用递归实现
void mirrorRecursive(BinaryTreeNode * root){
	if(root==NULL) return;
	if(root->pLeft!=NULL) mirrorRecursive(root->pLeft);
	if(root->pRight!=NULL) mirrorRecursive(root->pRight);
	BinaryTreeNode * left=root->pLeft;
	root->pLeft=root->pRight;
	root->pRight=left;
}

int main(){
	BinaryTreeNode* node5=new BinaryTreeNode(5);
	BinaryTreeNode* node7=new BinaryTreeNode(7);
	BinaryTreeNode* node9=new BinaryTreeNode(9);
	BinaryTreeNode* node11=new BinaryTreeNode(11);
	BinaryTreeNode* node6=new BinaryTreeNode(6,node5,node7);
	BinaryTreeNode* node10=new BinaryTreeNode(10,node9,node11);
	BinaryTreeNode* node8=new BinaryTreeNode(8,node6,node10);
	//逐层打印二叉树
	printBinaryTreeHier(node8);
	mirrorRecursive(node8);
	//逐层打印二叉树
	printBinaryTreeHier(node8);
	return 0;
}
