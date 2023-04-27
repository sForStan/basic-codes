#include<stdio.h>
#include<stdlib.h>
typedef struct TreeNode{
	char data;
	int flag;
	struct TreeNode* rchild,*lchild;
}TreeNode;
typedef struct StackNode{
	TreeNode* data;
	struct StackNode* next;
}StackNode;
void creatTree(TreeNode** T,char* data,int*index)
{
	char ch;
	ch=data[*index];
	*index+=1;
	if(ch=='#')
		*T=NULL;
	else{
		*T=(TreeNode*)malloc(sizeof(TreeNode));
		(*T)->data=ch;
		 (*T)->flag=0;
		creatTree(&((*T)->lchild),data,index);
		creatTree(&((*T)->rchild),data,index);
	}
}
StackNode* initStack()
{
	StackNode* S=(StackNode*)malloc(sizeof(StackNode));
	S->data=NULL;
	S->next=NULL;
	return S;
}
void push(TreeNode* T,StackNode* S)
{
	StackNode* node=malloc(sizeof(StackNode));
	node->data=T;
	node->next=S->next;
	S->next=node;
}
int isEmpty(StackNode* S)
{
	return (S->next==NULL)?1:0;
}
StackNode* pop(StackNode* S)
{
	if(isEmpty(S)){
		return NULL;
	}
	else{
		StackNode* node=S->next;
		S->next=node->next;
		return node;
	}
}
StackNode* getTop(StackNode* S)
{
	if(isEmpty(S)){
		return NULL;
	}
	else{
		StackNode* node=S->next;
		return node;
	}
}
void postOrder(TreeNode* T)
{
	TreeNode* node=T;
	StackNode* S=initStack();
	while(node||!(isEmpty(S))){
		if(node){
			push(node,S);
			node=node->lchild;
		}
		else{
			TreeNode* top=getTop(S)->data;
			if(top->rchild&&top->rchild->flag==0){
				top=top->rchild;
				push(top,S);
				node=top->lchild;
			}
			else{
				top=pop(S)->data;
				printf("%c",top->data);
				top->flag=1;
			}
		}
	}
}int main()
{
	TreeNode* T;
	char S[100];
	gets(S);
	int index=0;
	creatTree(&T,S,&index);
	postOrder(T);

}
