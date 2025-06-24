#include <stdio.h>
#include <stdlib.h>
#define NUM 40

typedef struct SListNode{
	int data;
	struct SListNode* next;
}SL;

SL* createnode(int i){
	SL* newnode = (SL*)malloc(sizeof(SL));
	newnode->data = i;
	newnode->next = NULL;
	return newnode;
}

int main(){
	SL* tail = NULL;
	SL* head = NULL;
	
	for(int i=0; i<NUM; i++){
		SL* p = createnode(i+1);
		if(head==NULL){
			head = tail = p;
			continue;
		}
		tail->next = p;
		tail = p;
	}
	tail->next = head;
	
	int count = 0;
	SL* cur = head;
	SL* prev = NULL;
	while(count<NUM){
		for(int i=0; i<2; i++){
			prev = cur;
			cur = cur->next;
		}
		printf("%d\n",cur->data);
		prev->next = cur->next;
		free(cur);
		cur = prev->next;
		count++;
	}
	
    return 0;
}
