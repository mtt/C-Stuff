#include <stdio.h>;
#include <stdlib.h>;

struct Ary { 
  int *data;
  int size;
};


int *IntAryList(int num){
  return (int *)malloc(num * sizeof(int));
}

struct Ary IntAryList2(int num){
	struct Ary ary;
	ary.data = IntAryList(num);
	ary.size = num;
	return ary;
}

void RandomizeAry(int *ary,int size){
  int i;
  for(i=0;i<size;i++){
    ary[i] = rand() % 10;
  }	
}
void RandomizeAry2(struct Ary ary){
  RandomizeAry(ary.data,ary.size);
}
int *AddToAryList(int *ary, int val, int size){
  ary = (int *)realloc(ary,size * sizeof(int));
  ary[size-1] = val;
  return ary;
}

void PrintAry(int *ary,int size){
  int j;
  for(j=0;j<size;j++){
    printf("Ary %d = %d\n",j,ary[j]);
  }
}
void PrintAry2(struct Ary ary){
  PrintAry(ary.data,ary.size);
}
void FreeAry(struct Ary ary){
	free(ary.data);
}
int main() {
	int size = 10;
	int *ary;
	int i;
	srand(time(0));

	struct Ary ary2 = IntAryList2(size);
    RandomizeAry2(ary2);
    PrintAry2(ary2);  
	FreeAry(ary2);
	return 0;
}