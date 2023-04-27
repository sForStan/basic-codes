#include<stdio.h>
#include<stdlib.h>
typedef struct TreeNode{
	char data;
	int rtag,ltag;
	struct TreeNode* lchild,*rchild,*parent;
}TreeNode;
void createTree(TreeNode** T,char* data,int *index,TreeNode* parent)
{
	char ch=data[*index];
	*index+=1;
	if(ch=='#')
		*T=NULL;
	else{
		*T=(TreeNode*)malloc(sizeof(TreeNode));
		(*T)->data=ch;
		(*T)->rtag=0;
		(*T)->ltag=0;
		(*T)->parent=parent;
		createTree(&((*T)->lchild),data,index,*T);
		createTree(&((*T)->rchild),data,index,*T);
	}
}
void postOrder(TreeNode* T,TreeNode** pre)
{
	if(T){
		postOrder(T->lchild,pre);
		postOrder(T->rchild,pre);
		if(T->lchild==NULL){
			T->ltag=1;
			T->lchild=*pre;
		}
		if(*pre!=NULL&&(*pre)->rchild==NULL){
			(*pre)->rtag=1;
			(*pre)->rchild=T;
		}
		*pre=T;
	}
}
TreeNode* getFirst(TreeNode* T){
	while(T->ltag==0)
		T=T->lchild;
	if(T->rtag==0){
		return getFirst(T->rchild);
	}
		return T;
}
TreeNode* getnext(TreeNode* node)
{
	if(node->rtag==1)//如果是右孩子为空，则右孩子记录后继结点
		return node->rchild;
	else{
		if(node->parent==NULL){//如果是根结点
			return NULL;
		}
		else if(node->parent->rchild==node)//如果是右孩子
		{
			return node->parent;
		}
		else{//如果是左孩子
			if(node->parent->rtag==0){//右孩子为空
				return getFirst(node->parent->rchild);
			}
			else{
					return node->parent;
				}
			}
		}
}
int main()
{
	TreeNode* T;
	TreeNode* pre=NULL;
	char s[100];
	gets(s);
	int index=0;
	createTree(&T,s,&index,NULL);
	postOrder(T,&pre);
	TreeNode* node=NULL;
	for(node=getFirst(T);node!=NULL;node=getnext(node))
	{
		printf("%c",node->data);
	}
	printf("\n");
	return 0;
}
