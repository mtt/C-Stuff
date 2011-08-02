#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void){
	
	int ** ary;
	int x = 10;
	int y = 10;
	int i,j;
	ary = (int **) malloc((x+y) * sizeof(int));
	for(i=0;i<x;i++){
		ary[i] = (int *)malloc(y * sizeof(int));
		for(j=0;j<y;j++){
			ary[i][j] = i*j;
		}
	}
	for(i=0;i<x;i++){
		for(j=0;j<y;j++){
			printf("%d\t",ary[i][j]);
		}
		printf("\n");
	}
	
	return 0;
}