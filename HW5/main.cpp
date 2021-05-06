#include "main.h"

int main()
{
	string input = "+ 7 / - 9 3 * 2 5";
	cout << input << " = " << calculate_array(input) << endl;
	cout << input << " = " << calculate_list(input) << endl;

	input = "(a+b)*c-(d+e*f/((g/h+i-j)*k))/r";
	cout << input << " = " << calculate_to_prefix(input) << endl;

	input = "a+(45-a(x)*(b-c))";
	cout << calculate_brackets(input, false) << endl;
	cout << calculate_brackets(input, true) << endl;
}