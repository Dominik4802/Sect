#include <stdio.h>

#define MAX_POWER_OF_TWO 64

// struct helping to calculate the result by storing attributes of shit of the pattern by which people are getting killed,
// storing position of the person of our interest in the last round excluding empty positions (people already killed) and
// storing information about round number
typedef struct {
	long long int shifted;
	unsigned long long int positionInHisLastRound;
	short rounds;
} struct_t;

void reset_struct(struct_t *attributes) {

	attributes->positionInHisLastRound = 0;
	attributes->shifted = 0;
}

void initialize_powers_of_two_array(unsigned long long int powers_of_two[MAX_POWER_OF_TWO]) {

	unsigned long long int value = 1;

	for (int i = 0; i < MAX_POWER_OF_TWO; i++) {
		powers_of_two[i] = value;
		value *= 2;
	}
}

void simulation(unsigned long long int n, long long int k, struct_t *attributes, unsigned long long int powers_of_two[MAX_POWER_OF_TWO]) {

	int one_more = 0, shifts = 0;
	short i = 0;
	long long int killed;
	bool new_shift = 1;

	while (1) {
		if (n % 2 == 1 || n - one_more == 1) {			// in case there is an odd number of ppl in a circle or these are the last people
			one_more++;									// variable deciding if there will be n/2 ppl killed or n/2+1
			new_shift = 1;
		}
		killed = n / 2 + ((one_more == 2) ? 1 : 0);			// if the there was once an odd amount of people left in a circle and it is also right now then one more person will get killed
		if (k <= killed || k == 1) {						// if more people are gonna die than there are to kill or it is the last person, then end the loop
			attributes->positionInHisLastRound = k;			// and save the position in this round
			break;
		}
		if ((new_shift == 1) && (one_more > 0 || n - one_more == 1)) {
			attributes->shifted += powers_of_two[i + 1] * ((shifts % 2 == 1) ? 1 : -1);	// counting the shift of the pattern by which people are getting killed;
			shifts++;																	// every even shift goes to the left, or to the right
			new_shift = 0;
		}
		if (one_more == 2)	one_more = 0;

		k -= killed;		// subtracting 
		n -= killed;		// killed people
		i++;			// counting rounds
	}
	attributes->rounds = i;
	return;
}

int main() {

	unsigned long long int n, k = 0, powers_of_two[MAX_POWER_OF_TWO];
	long long int l;
	int num_of_tests;
	struct_t attributes;

	initialize_powers_of_two_array(powers_of_two);
	scanf_s("%d", &num_of_tests);

	for (int o = 0; o < num_of_tests; o++) {

		unsigned long long int position;
		bool last_man_standing = 0;
		scanf_s("%llu %lld", &n, &l); // input from the user: n - number of people in the circle, l - lth person to die we are interested in

		if (l < 0) {
			k = n + l + 1;		// converting negative k into a positive position
		}
		else {
			k = l;
		}

		if (k == n) {
			last_man_standing = 1;
		}

		reset_struct(&attributes);
		simulation(n, k, &attributes, powers_of_two);
		position = attributes.positionInHisLastRound * powers_of_two[attributes.rounds + 1] + 1 - powers_of_two[attributes.rounds] + attributes.shifted - ((last_man_standing == 1) ? powers_of_two[attributes.rounds] : 0);
		printf_s("%llu\n", position);
	}

	return 0;
}