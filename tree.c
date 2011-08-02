#include <stdio.h>;
#include <stdlib.h>;

/* 
Tree Sort

    5
  4   6
2       9
      8   20
        12
*/
struct Tree {
  struct Tree *left;
  struct Tree *right;
  int val;
};

void AddNode(struct Tree ** tree,int val){
	printf("Inside AddNode\n");
	printf("%p\n",tree);
  if (*tree == NULL) {
	printf("Malloc node\n");
	*tree = malloc(sizeof(struct Tree));
	printf("%p\n",tree);
	(*tree)->val = val;	
  } else if ((*tree)->val > val) {
	printf("Looking left\n");
	AddNode(&(*tree)->left,val);
  } else {
	printf("Looking right\n");
	printf("Calling new node\n");
	AddNode(&(*tree)->right,val);	
  }
}
void TreeTest(struct Tree ** tree) {
  *tree = malloc(sizeof(struct Tree));
}
void TestAddNote(struct Tree ** tree, int val){
  (*tree)->right = malloc(sizeof(struct Tree));
  (*tree)->right->val = val;
}
void TestAddNote2(struct Tree ** tree, int val){
  *tree = malloc(sizeof(struct Tree));
  (*tree)->val = val;
}
void PrintTree(struct Tree * tree){
  if (tree != NULL) {
	PrintTree(tree->left);
	printf("%d\n",tree->val);
	PrintTree(tree->right);
  }
}
/*
Tree * t1; undefined
*t1 value at address stored in t1
t1 address(in hex) that t1's value is stored in
&t1 Address where value of address *t1 is stored
*/

int main(){
  printf("Starting...\n");
  srand(time(0));
  int nodes = rand() % 50;
/*
  struct Tree *t1;
  struct Tree **t2;
  t2 = &t1; /* t2 = &t1 == *t2 = t1;
  printf("%p\n",t1);
  printf("%p\n",t2);
  printf("%p\n",*t2);
  t1 = malloc(sizeof(struct Tree));
  printf("%p\n",t1);
  (*t1).val = 5;
  //(*t1).val == t1->val;
  printf("%d == %d\n",(*t1).val, t1->val);
  printf("%p\n",(*t2));
  printf("%d %d\n",(*(*t2)).val,(*t2)->val);
*/
  struct Tree * t11;
  printf("%p\n",t11);
  TreeTest(&t11);
  printf("%p\n",t11);
  TestAddNote(&t11,55);
  printf("%p\n",t11->right);
  printf("TEST %d\n",t11->right->val);
  TestAddNote2(&t11->left,100);
  printf("%p\n",t11->left);
  printf("TEST %d\n",t11->left->val);
  printf("\n\n");
  struct Tree *t12;
  AddNode(&t12,10);
  AddNode(&t12,20);
  AddNode(&t12,5);
  AddNode(&t12,203);
  AddNode(&t12,2);
  AddNode(&t12,1);
  AddNode(&t12,7);
  AddNode(&t12,6);
  AddNode(&t12,9);
  printf("\n\n");
  PrintTree(t12);
  //printf("t1 right %d\n",t1->right->val);
  /*
  t3->val = 3;
  t1->left = t2; 
  t2->val  = 2;
  printf("t1 val %d\n",t1->val);
  printf("t1 left val %d\n",t1->left->val);
  t1->left->val = 22;
  t1->left = t3;
  printf("t1 left val %d\n",t1->left->val);
  printf("t2 val %d\n",t2->val);

  */
  return 0;
}