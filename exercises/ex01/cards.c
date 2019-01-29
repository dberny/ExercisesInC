/* This program takes user input as card inputs and counts cards as
one would do to place bets on a game of blackjack */

#include <stdio.h>
#include <stdlib.h>

int get_card_val(char* input);
void update_count(int val, int *count);

int main() {
	char card_name[3];
	int count = 0;
	do {
		int val;
		puts("Enter the card_name: ");
		scanf("%2s", card_name);
		val = get_card_val(card_name);
		update_count(val, &count);
		printf("Current count: %i\n", count);
	} while (card_name[0] != 'X');
	return 0;
}

/* Takes in the value for the card user put
in and updates the card count
*/
void update_count(int val, int *count) {
	if ((val>2) && (val<7)) {
		*count += 1;
	}
	else if (val == 10) {
		*count -= 1;
	}
}

/* Takes in card user input and returns the card value
*/
int get_card_val(char* input) {
	int val = 0;
	switch (input[0]) {
		case 'K':
		case 'Q':
		case 'J':
			val = 10;
			break;
		case 'A':
			val = 11;
			break;
		case 'X':
			break;
		default:
			val = atoi(input);
			if ((val<1) || (val > 10)) {
				puts("I don't understand that value!");
				break;
			}
	}
	return val;
}
