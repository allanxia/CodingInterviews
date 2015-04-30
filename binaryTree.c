#include "binaryTree.h"

//逐层打印二叉树
void printBinaryTreeHier(BinaryTreeNode *root){
	if(root==NULL)  return;
	std::queue<BinaryTreeNode *> nodes;
	int num=0;//num记录的是下一层的节点数
	nodes.push(root);
	while(nodes.size()!=0){
		while(num!=nodes.size())//当num记录的数字与nodes.size()不等时表示当前层还没有打印完，暂时不需要打印换行符
		{
	  		BinaryTreeNode * node=nodes.front();
			std::cout<<node->m_value<<" ";
			if(node->pLeft!=NULL) { num++; nodes.push(node->pLeft); } 
			if(node->pRight!=NULL) {num++;  nodes.push(node->pRight);}
			nodes.pop();
		}
		num=0;//每打印完一层，需要将num置为0
		std::cout<<std::endl;
	}
	
}

