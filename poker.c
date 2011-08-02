#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define CARDS 5
#define MAX_SUIT_LENGTH 20
#define true 1
#define false 0

struct card {
	char suit[MAX_SUIT_LENGTH];
	int  num;
};

int  hand[CARDS];
struct card deck[52];

void StartGame(){
	printf("Starting game...\n");
}

void DealHand(){	
	int i;
	srand(time(0));
	
	for(i=0;i<5;i++){
		hand[i] = rand()%52;
	}
}

void CreateDeck(){
	int i,j,k;
	char suits[4][MAX_SUIT_LENGTH] = {"Spades","Hearts","Clubs","Diamonds"};
	
	for(i=0;i<4;i++){
		for(j=0;j<13;j++){
			k = j+(i*13);
			struct card tmp_card;
			sprintf(tmp_card.suit,"%s",suits[i]);
			tmp_card.num = j+1;
			deck[k] = tmp_card;
		}
	}
}

int HasFlush(){
	int i;
	struct card first_card = deck[hand[0]];
	for (i=1;i<CARDS;i++){
		struct card tmp_card = deck[hand[i]];
		if (strcmp(tmp_card.suit,first_card.suit) != 0) {
			return false;
		}
	}	
	return true;
}



void DisplayHand(){
	int i;
	for(i=0;i<CARDS;i++){
		struct card tmp_card;
		tmp_card = deck[hand[i]];
		printf("%s %d\n",tmp_card.suit,tmp_card.num);
	}
}
int main(void){
	
	StartGame();
	CreateDeck();
	
	int flush = 0;
	int number_of_hands = 0;
	while(flush == 0){
		DealHand();
		number_of_hands++;
		printf("%d\n",number_of_hands);
		flush = HasFlush();	
	}
	
	printf ("Is Flush? %d\n",flush);
	DisplayHand();
	return 0;
}