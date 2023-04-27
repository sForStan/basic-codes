#include<stdio.h>
#include<stdlib.h>
typedef struct TreeNode{
	char data;
	int rtag,ltag;
	struct TreeNode* rchild,*lchild;
}TreeNode;
void creatTree(TreeNode** T,char* data,int *index)
{
	char ch=data[*index];
	*index+=1;
	if(ch=='#')
		*T=NULL;
	else{
		*T=malloc(sizeof(TreeNode));
		(*T)->data=ch;
		(*T)->ltag=0;
		(*T)->rtag=0;
		creatTree(&((*T)->lchild),data,index);
		creatTree(&((*T)->rchild),data,index);
	}
}
void inTreadTree(TreeNode* T,TreeNode** pre)
{	
	if(T){
		inTreadTree(T->lchild,pre);
		if(T->lchild==NULL){
			T->ltag=1;
			T->lchild=*pre;
		}
		if(*pre!=NULL&&(*pre)->rchild==NULL){
			(*pre)->rtag=1;
			(*pre)->rchild=T;
		}
		*pre=T;
		inTreadTree(T->rchild,pre);
	}
}
int main()
{
	TreeNode* T;
	TreeNode* pre=NULL;
	int index=0;
	char s[100];
	gets(s);
	creatTree(&T,s,&index);
	inTreadTree(T,&pre);
	pre->rtag=1;
	pre->rchild=NULL;
	return 0;
}
