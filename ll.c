#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <raylib.h>


typedef struct list{
	Vector2 pos;
	struct list* next;
}list;

list * create_list(Vector2 pos){
	list * l = (list *) malloc(sizeof(list));
	l-> pos  = pos;
	l-> next = NULL;
	return l;
}

void at_begining(list** head,Vector2 pos){
	list * l = create_list(pos);
	l->next = *head;
	*head = l;
}
void del_head(list** head){
	list *tmp = *head;

	*head = tmp->next;
	free(tmp);
}


void at_end(list ** head ,Vector2  pos){
	list * l = create_list(pos);
	list * tmp = *head;
	while (tmp->next){
		tmp = tmp->next;
	}
	tmp -> next = l;
}
void del_end(list** head){
	list * tmp = *head;
	while (tmp->next->next){
		tmp = tmp->next;
	}
	free(tmp->next->next);
	tmp->next = NULL;

}


void print_list(list *head){
	list * tmp = head;
	while (tmp){
		printf("x = %lf ,y = %lf > ",tmp -> pos.x,tmp->pos.y);
		tmp = tmp->next;
	}
	printf("NULL \n");
}
void free_list(list *head){
	list * tmp = head;
	while (tmp) {
		tmp = tmp->next;
		free(tmp);
		puts("free");
	}
}
Vector2 get_posue(list *head,int reset){
	static list * tmp  = NULL;
	if (reset || tmp == NULL){
		tmp = head;
	}else{
		tmp = tmp->next;
	}
	/*if (tmp == NULL){
		return;
	}*/
	return tmp->pos;
}

