#include<stdio.h>
#include<stdlib.h>
typedef struct TreeNode{
	char data;
	struct TreeNode* lchild,*rchild;
	int ltag,rtag;
}TreeNode;
void createTree(TreeNode** T,char *data,int *index)
{
	char ch=data[*index];
	*index+=1;
	if(ch=='#')
		*T=NULL;
	else{
		*T=(TreeNode*)malloc(sizeof(TreeNode));
		(*T)->data=ch;
		(*T)->ltag=0;
		(*T)->rtag=0;
		createTree(&((*T)->lchild),data,index);
		createTree(&((*T)->rchild),data,index);
	}
}
void preTreadTree(TreeNode*T,TreeNode** pre)
{
	if(T){
		if(T->lchild==NULL){
			T->ltag=1;
			T->lchild=*pre;
		}
		if(*pre!=NULL&&(*pre)->rchild==NULL){
			(*pre)->rtag=1;
			(*pre)->rchild=T;
		}
		(*pre)=T;
		if(T->ltag==0)
			preTreadTree(T->lchild,pre);
		preTreadTree(T->rchild,pre);
	}
}
TreeNode* getNext(TreeNode* node){
	if(node->rtag==1||node->ltag==1){
		return node->rchild;
	}
	else{
		return node->lchild;
	}
}

int main()
{
	TreeNode*T,*pre=NULL;
	char s[100];
	gets(s);
	int index=0;
	createTree(&T,s,&index);
	preTreadTree(T,&pre);
	pre->rtag=1;
	pre->rchild=NULL;
	TreeNode* node;
	for(node=T;node!=NULL;node=getNext(node)){
		printf("%c",node->data);
	}
	printf("\n");
	return 0;
}
