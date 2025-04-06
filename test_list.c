#include "list.h"

int main(){
	Node* head = create_node(1);
	for (int i = 1; i < 11; i++){
		insert_at_end(&head, i);
	}
	display_list(head);
	return 0;
}

