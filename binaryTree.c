#include "binaryTree.h"

//����ӡ������
void printBinaryTreeHier(BinaryTreeNode *root){
	if(root==NULL)  return;
	std::queue<BinaryTreeNode *> nodes;
	int num=0;//num��¼������һ��Ľڵ���
	nodes.push(root);
	while(nodes.size()!=0){
		while(num!=nodes.size())//��num��¼��������nodes.size()����ʱ��ʾ��ǰ�㻹û�д�ӡ�꣬��ʱ����Ҫ��ӡ���з�
		{
	  		BinaryTreeNode * node=nodes.front();
			std::cout<<node->m_value<<" ";
			if(node->pLeft!=NULL) { num++; nodes.push(node->pLeft); } 
			if(node->pRight!=NULL) {num++;  nodes.push(node->pRight);}
			nodes.pop();
		}
		num=0;//ÿ��ӡ��һ�㣬��Ҫ��num��Ϊ0
		std::cout<<std::endl;
	}
	
}

