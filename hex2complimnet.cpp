#include <stdio.h>

//This program will find the twos compliment of a hex number
//It will first convert to hex then find inverse +1 then convert back to decimal

int hex (char digit) {
	//convert a string to a digit
	//return int
	if (digit >= '0' && digit <= '9') 
		return digit - '0';
	else
		return 10 + (digit - 'A');
	
}

char opposite (int difference) {
	//convert an int to char
	
	if (difference >= 0 && difference <= 9) 
		return '0' + difference;
	else
		return 'A' + (difference - 10);
	
}

void twosCompliment (char *hexNum) {
	int i = 0;
	
	while (hexNum[i]) i++;
	//i is at null terminator
	
	i--;
	//i is at last element
	
	//convert hex digit to number
	//for the first one subtract from 16 since it should force a carry on all
	//for all others loop through and subtract from 15
	
	hexNum[i] = opposite(16-hex(hexNum[i]));
	
	i--;
	
	while (i >= 0) {
		hexNum[i] = opposite(15-hex(hexNum[i]));	
		i--;
	}
	
}

int main() {
	char hexNum[] = "A67C";
	
	printf ("Your hex number is : %s\n", hexNum);
	
	twosCompliment (hexNum);
	
	printf ("Your hex number's two's complement is : %s\n", hexNum);

}
