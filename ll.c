#include <raylib.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>

typedef struct bullet {
  Vector2 pos;
  struct bullet *next;
} bullet;

bullet *create_bullet(Vector2 pos) {
  bullet *l = (bullet *)malloc(sizeof(bullet));
  l->pos = pos;
  l->next = NULL;
  return l;
}

void at_begining(bullet **head, Vector2 pos) {
  bullet *l = create_bullet(pos);
  l->next = *head;
  *head = l;
}
void del_head(bullet **head) {
  bullet *tmp = *head;

  *head = tmp->next;
  free(tmp);
}

void at_end(bullet **head, Vector2 pos) {
  bullet *l = create_bullet(pos);
  bullet *tmp = *head;
  while (tmp->next) {
    tmp = tmp->next;
  }
  tmp->next = l;
}
void del_end(bullet **head) {
  bullet *tmp = *head;
  while (tmp->next->next) {
    tmp = tmp->next;
  }
  free(tmp->next->next);
  tmp->next = NULL;
}

void print_bullet(bullet *head) {
  bullet *tmp = head;
  while (tmp) {
    printf("x = %lf ,y = %lf > ", tmp->pos.x, tmp->pos.y);
    tmp = tmp->next;
  }
  printf("NULL \n");
}
void free_bullet(bullet *head) {
  bullet *tmp = head;
  while (tmp) {
    tmp = tmp->next;
    free(tmp);
    puts("free");
  }
}
Vector2 get_pos(bullet *head, int reset) {
  static bullet *tmp = NULL;
  if (reset || tmp == NULL) {
    tmp = head;
  } else {
    tmp = tmp->next;
  }
  /*if (tmp == NULL){
          return;
  }*/
  return tmp->pos;
}
