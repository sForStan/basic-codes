#include<stdio.h>
#include<stdlib.h>
typedef struct TreeNode{
	char data;
	struct TreeNode* lchild,*rchild;
}TreeNode;
typedef struct StackNode{
	TreeNode* data;
	struct StackNode* next;
}StackNode;
void createTree(TreeNode** T,char* data,int* index){
	char ch;
	ch=data[*index];
	*index+=1;
	if(ch=='#')return;
	else{
		*T=(TreeNode*)malloc(sizeof(TreeNode));
		(*T)->data=ch;
		createTree(&((*T)->lchild),data,index);
		createTree(&((*T)->rchild),data,index);
	}
}
StackNode* initStack(){
	StackNode* S=(StackNode*)malloc(sizeof(StackNode));
	S->data=NULL;
	S->next=NULL;
	return S;
}
void push(TreeNode* data,StackNode* S)
{
	StackNode* node=(StackNode*)malloc(sizeof(StackNode));
	node->data=data;
	node->next=S->next;
	S->next=node;
}
int isEmpty(StackNode* S)
{
	return (S->next==NULL)?1:0;
}
StackNode* pop(StackNode* S){
	if(isEmpty(S))return NULL;
	else{
		StackNode* node=S->next;
		S->next=node->next;
		return node;
	}
}
void preOrder(TreeNode* T)
{
	TreeNode* node=T;
	StackNode* S=initStack();
	while(node||!isEmpty(S)){
		if(node){
			printf("%c",node->data);
			push(node,S);
			node=node->lchild;
		}
		else{
			node=pop(S)->data;
			node=node->rchild;
		}
	}
}
int main()
{
	TreeNode* T;
	int index=0;
	char s[100];
	gets(s);
	createTree(&T,s,&index);
	preOrder(T);
	printf("\n");
}
