#include <stdio.h>

typedef struct{
  float x;
  float y;
}Vector2;

Vector2 addV(Vector2 a,Vector2 b){
  Vector2 ret = {a.x + b.x, a.y + b.y};
  return ret;
}
void add_int_to_V(Vector2 *a,int N){
  a->x = a->x + N;
  a->y = a->y + N;
}

int main(){
  Vector2 a = {5.0,6};
  //Vector2 b = {5.0,6};
  add_int_to_V(&a, 2000);
  printf("x = %f,y = %f \n", a.x ,a.y);
  return 0;
}

  
