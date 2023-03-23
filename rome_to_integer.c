#include <stdio.h>

enum suit {
	I = 1,
	V = 5,
	X = 10,
	L = 50,
	C = 100,
	D = 500,
	M = 1000,
};

int roman_to_integer(char* str){
	int result = 0;
	
	int pointer_one;
	int pointer_two;
	
	for(int i = 0; str[i] != '\0'; i++) {
		if(str[i] == 'I') {
			pointer_one = I;
        } else if(str[i] == 'V') {
			pointer_one = V;
        } else if(str[i] == 'X') {
			pointer_one = X;
        } else if(str[i] == 'L') {
			pointer_one = L;
        } else if(str[i] == 'C') {
			pointer_one = C;
        } else if(str[i] == 'D') {
			pointer_one = D;
		} else if(str[i] == 'M') {
			pointer_one = M;
		} else {
			pointer_two = 0;
		}
		
		if( str[i + 1] == 'I') {
			pointer_two = I;
        } else if(str[i + 1] == 'V') {
			pointer_two = V;
        } else if(str[i + 1] == 'X') {
			pointer_two = X;
        } else if(str[i + 1] == 'L') {
			pointer_two = L;
        } else if(str[i + 1] == 'C') {
			pointer_two = C;
        } else if(str[i + 1] == 'D') {
			pointer_two = D;
		} else if(str[i + 1] == 'M') {
			pointer_two = M;
		} else {
			pointer_two = 0;
		}
		
		if(pointer_one < pointer_two){
			result -= pointer_one;
		} else if(pointer_one >= pointer_two){
			result += pointer_one;
		} 
	}
	return result;
}

void test_equals_int(int result, int actual, int line){
	if(result == actual){
		printf("Test pass in Line %d.\n", line);
	} else {
		printf("expected value [%d] differs from [%d] in Line %d.\n", actual, result, line);
	}
}

void main(){
	int result = roman_to_integer("MCMXCIV");
	int actual = 1994;
	test_equals_int(result, actual, __LINE__);
	
	result = roman_to_integer("III");
	actual = 3;
	test_equals_int(result, actual, __LINE__);
	
	result = roman_to_integer("LVIII");
	actual = 58;
	test_equals_int(result, actual, __LINE__);
}