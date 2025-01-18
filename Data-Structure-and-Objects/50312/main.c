#include<stdio.h>
#include <stdlib.h>
#include <time.h>  
#include "sort_list.h"


int main(){
	const int N = 300000;
	struct node ptr_list[N];
	int n; scanf("%d",&n);


	// below is just to randomized addresses
	srand(time(NULL));
	for(int i=0;i<N;i++){
		ptr_list[i].next_node = ptr_list+rand()%N;
	}
	// 
	

	int cur; scanf("%d",&cur);
	int head = cur;
	for(int i=1;i<n;i++){
		int next; scanf("%d",&next);
		ptr_list[cur].next_node = ptr_list+next;
		cur = next;
	}
	ptr_list[cur].next_node = NULL;
	struct node *cur_node = ptr_list+head;
	struct node *new_head = sort_list(cur_node);
	printf("%d",(int)(new_head-ptr_list));
	for(int i=0;i<n-1;i++){
		new_head = new_head->next_node;
		printf(" %d",(int)(new_head-ptr_list));
	}
	printf("\n");

}
