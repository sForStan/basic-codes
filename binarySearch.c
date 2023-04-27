#include<stdio.h>
#include<stdlib.h>
typedef struct TreeNode{
	int data;
	struct TreeNode* lchild;
	struct TreeNode* rchild;
}TreeNode;
TreeNode* bstSearch(TreeNode* T,int data){
	if(T){
		if(T->data==data){
			return T;
		}
		else if(data<T->data){
			return bstSearch(T->lchild,data);
		}
		else{
			return bstSearch(T->rchild,data);
		}
	}
	else
		return NULL;
}
TreeNode* bstInsert(TreeNode** T,int data)
{
	if(*T==NULL){
		*T=(TreeNode*)malloc(sizeof(TreeNode));
		(*T)->data=data;
		(*T)->lchild=NULL;
		(*T)->rchild=NULL;
	}
	else if(data<(*T)->data){
		bstInsert(&((*T)->lchild),data);
	}
	else if(data==(*T)->data){
		return;
	}
	else{
		bstInsert(&((*T)->rchild),data);
	}
}
void preOrder(TreeNode* T)
{
	if(T){
	printf("%d",T->data);
	preOrder(T->lchild);
	preOrder(T->rchild);
	}
}
int main()
{
	TreeNode* T=NULL;
	int nums[6]={4,5,19,23,2,8};
	int i;
	for(i=0;i<6;i++)
	{
		bstInsert(&T,nums[i]);
	}
	preOrder(T);
	printf("\n");
}
