#include<stdio.h>
#include<stdlib.h>
typedef struct TreeNode{
	char data;
	struct TreeNode* lchild;
	struct TreeNode* rchild;
}TreeNode;

void createTree(TreeNode** T,char* data,int* index)
{
	char ch;
	ch=data[*index];
	*index+=1;
	if(ch=='#')
	{
		//此时为空结点
		*T=NULL;
	}
	else{
		//此时不为空
		*T=(TreeNode*)malloc(sizeof(TreeNode));
		(*T)->data=ch;
		createTree(&((*T)->lchild),data,index);
		createTree(&((*T)->rchild),data,index);
	}
	return;
}
void preOrder(TreeNode* T)
{
	if(T==NULL)
		return;
	else{
		printf("%c",T->data);
		preOrder(T->lchild);
		preOrder(T->rchild);
	}
}
void inOrder(TreeNode* T)
{
		if(T==NULL)
		return;
	else{
		preOrder(T->lchild);
		printf("%c",T->data);		
		preOrder(T->rchild);
	}

}
void postOrder(TreeNode* T)
{
		if(T==NULL)
		return;
	else{
		preOrder(T->lchild);	
		preOrder(T->rchild);
		printf("%c",T->data);	
	}

}

int main(int argc,char* argv[])
{
	TreeNode* T;
	int index=0;
	createTree(&T,argv[1],&index);
	preOrder(T);
	printf("\n");
	inOrder(T);
	printf("\n");
	postOrder(T);
	printf("\n");
	return 0;
}
