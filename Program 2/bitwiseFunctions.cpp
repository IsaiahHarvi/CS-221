#include "bitwiseFunctions.h"

int bitwiseFunctions::add(int a, int b) {
	int an;
	int bn;
	int sum = 0;
	int carry = 0;
	int n = 1;

	/*
	Addition Using only bitwise operators.

	& is AND
	| is OR
	^ is XOR
	~ is NOT
	<< is Bitshift

	int n is the current bit.
	It will begin at 00000001, then 00000010, and so on.
	*/

	an = a & n;
	bn = b & n;
	sum |= (an ^ bn) ^ carry; // 
	carry = ((an & bn) | ((an ^ bn) & carry)) << 1;
	n <<= 1;

	an = a & n;
	bn = b & n;
	sum |= (an ^ bn) ^ carry; // 
	carry = ((an & bn) | ((an ^ bn) & carry)) << 1;
	n <<= 1;

	an = a & n;
	bn = b & n;
	sum |= (an ^ bn) ^ carry; // 
	carry = ((an & bn) | ((an ^ bn) & carry)) << 1;
	n <<= 1;

	an = a & n;
	bn = b & n;
	sum |= (an ^ bn) ^ carry; // 
	carry = ((an & bn) | ((an ^ bn) & carry)) << 1;
	n <<= 1;

	an = a & n;
	bn = b & n;
	sum |= (an ^ bn) ^ carry; // 
	carry = ((an & bn) | ((an ^ bn) & carry)) << 1;
	n <<= 1;

	an = a & n;
	bn = b & n;
	sum |= (an ^ bn) ^ carry; // 
	carry = ((an & bn) | ((an ^ bn) & carry)) << 1;
	n <<= 1;

	an = a & n;
	bn = b & n;
	sum |= (an ^ bn) ^ carry; // 
	carry = ((an & bn) | ((an ^ bn) & carry)) << 1;
	n <<= 1;

	an = a & n;
	bn = b & n;
	sum |= (an ^ bn) ^ carry; // 
	carry = ((an & bn) | ((an ^ bn) & carry)) << 1;
	n <<= 1;

	an = a & n;
	bn = b & n;
	sum |= (an ^ bn) ^ carry; // 
	carry = ((an & bn) | ((an ^ bn) & carry)) << 1;
	n <<= 1;

	an = a & n;
	bn = b & n;
	sum |= (an ^ bn) ^ carry; // 
	carry = ((an & bn) | ((an ^ bn) & carry)) << 1;
	n <<= 1;

	an = a & n;
	bn = b & n;
	sum |= (an ^ bn) ^ carry; // 
	carry = ((an & bn) | ((an ^ bn) & carry)) << 1;
	n <<= 1;

	an = a & n;
	bn = b & n;
	sum |= (an ^ bn) ^ carry; // 
	carry = ((an & bn) | ((an ^ bn) & carry)) << 1;
	n <<= 1;

	an = a & n;
	bn = b & n;
	sum |= (an ^ bn) ^ carry; // 
	carry = ((an & bn) | ((an ^ bn) & carry)) << 1;
	n <<= 1;

	an = a & n;
	bn = b & n;
	sum |= (an ^ bn) ^ carry; // 
	carry = ((an & bn) | ((an ^ bn) & carry)) << 1;
	n <<= 1;

	an = a & n;
	bn = b & n;
	sum |= (an ^ bn) ^ carry; // 
	carry = ((an & bn) | ((an ^ bn) & carry)) << 1;
	n <<= 1;

	an = a & n;
	bn = b & n;
	sum |= (an ^ bn) ^ carry; // 
	carry = ((an & bn) | ((an ^ bn) & carry)) << 1;
	n <<= 1;

	an = a & n;
	bn = b & n;
	sum |= (an ^ bn) ^ carry; // 
	carry = ((an & bn) | ((an ^ bn) & carry)) << 1;
	n <<= 1;

	an = a & n;
	bn = b & n;
	sum |= (an ^ bn) ^ carry; // 
	carry = ((an & bn) | ((an ^ bn) & carry)) << 1;
	n <<= 1;

	an = a & n;
	bn = b & n;
	sum |= (an ^ bn) ^ carry; // 
	carry = ((an & bn) | ((an ^ bn) & carry)) << 1;
	n <<= 1;

	an = a & n;
	bn = b & n;
	sum |= (an ^ bn) ^ carry; // 
	carry = ((an & bn) | ((an ^ bn) & carry)) << 1;
	n <<= 1;

	an = a & n;
	bn = b & n;
	sum |= (an ^ bn) ^ carry; // 
	carry = ((an & bn) | ((an ^ bn) & carry)) << 1;
	n <<= 1;

	an = a & n;
	bn = b & n;
	sum |= (an ^ bn) ^ carry; // 
	carry = ((an & bn) | ((an ^ bn) & carry)) << 1;
	n <<= 1;

	an = a & n;
	bn = b & n;
	sum |= (an ^ bn) ^ carry; // 
	carry = ((an & bn) | ((an ^ bn) & carry)) << 1;
	n <<= 1;

	an = a & n;
	bn = b & n;
	sum |= (an ^ bn) ^ carry; // 
	carry = ((an & bn) | ((an ^ bn) & carry)) << 1;
	n <<= 1;

	an = a & n;
	bn = b & n;
	sum |= (an ^ bn) ^ carry; // 
	carry = ((an & bn) | ((an ^ bn) & carry)) << 1;
	n <<= 1;

	an = a & n;
	bn = b & n;
	sum |= (an ^ bn) ^ carry; // 
	carry = ((an & bn) | ((an ^ bn) & carry)) << 1;
	n <<= 1;

	an = a & n;
	bn = b & n;
	sum |= (an ^ bn) ^ carry; // 
	carry = ((an & bn) | ((an ^ bn) & carry)) << 1;
	n <<= 1;

	an = a & n;
	bn = b & n;
	sum |= (an ^ bn) ^ carry; // 
	carry = ((an & bn) | ((an ^ bn) & carry)) << 1;
	n <<= 1;

	an = a & n;
	bn = b & n;
	sum |= (an ^ bn) ^ carry; // 
	carry = ((an & bn) | ((an ^ bn) & carry)) << 1;
	n <<= 1;

	an = a & n;
	bn = b & n;
	sum |= (an ^ bn) ^ carry; // 
	carry = ((an & bn) | ((an ^ bn) & carry)) << 1;
	n <<= 1;

	an = a & n;
	bn = b & n;
	sum |= (an ^ bn) ^ carry; // 
	carry = ((an & bn) | ((an ^ bn) & carry)) << 1;
	n <<= 1;

	an = a & n;
	bn = b & n;
	sum |= (an ^ bn) ^ carry; //
	carry = ((an & bn) | ((an ^ bn) & carry)) << 1;
	n <<= 1;

	return sum;
}


int bitwiseFunctions::subtract(int a, int b) {
		int an;
		int bn;
		int sum = 0;
		int carry = 1;
		int n = 1;

		/*
		Subtrction Using only bitwise operators.

		& is AND
		| is OR
		^ is XOR
		~ is NOT
		<< is Bitshift

		int n is the current bit.
		It will begin at 00000001, then 00000010, and so on.
		*/

		an = a & n;
		bn = ~b & n;
		sum |= (an ^ bn) ^ carry; // 
		carry = ((an & bn) | ((an ^ bn) & carry)) << 1;
		n <<= 1;

		an = a & n;
		bn = ~b & n;
		sum |= (an ^ bn) ^ carry; // 
		carry = ((an & bn) | ((an ^ bn) & carry)) << 1;
		n <<= 1;
		an = a & n;
		bn = ~b & n;
		sum |= (an ^ bn) ^ carry; // 
		carry = ((an & bn) | ((an ^ bn) & carry)) << 1;
		n <<= 1;

		an = a & n;
		bn = ~b & n;
		sum |= (an ^ bn) ^ carry; // 
		carry = ((an & bn) | ((an ^ bn) & carry)) << 1;
		n <<= 1;
		an = a & n;
		bn = ~b & n;
		sum |= (an ^ bn) ^ carry; // 
		carry = ((an & bn) | ((an ^ bn) & carry)) << 1;
		n <<= 1;

		an = a & n;
		bn = ~b & n;
		sum |= (an ^ bn) ^ carry; // 
		carry = ((an & bn) | ((an ^ bn) & carry)) << 1;
		n <<= 1;
		an = a & n;
		bn = ~b & n;
		sum |= (an ^ bn) ^ carry; // 
		carry = ((an & bn) | ((an ^ bn) & carry)) << 1;
		n <<= 1;

		an = a & n;
		bn = ~b & n;
		sum |= (an ^ bn) ^ carry; // 
		carry = ((an & bn) | ((an ^ bn) & carry)) << 1;
		n <<= 1;
		an = a & n;
		bn = ~b & n;
		sum |= (an ^ bn) ^ carry; // 
		carry = ((an & bn) | ((an ^ bn) & carry)) << 1;
		n <<= 1;

		an = a & n;
		bn = ~b & n;
		sum |= (an ^ bn) ^ carry; // 
		carry = ((an & bn) | ((an ^ bn) & carry)) << 1;
		n <<= 1;
		an = a & n;
		bn = ~b & n;
		sum |= (an ^ bn) ^ carry; // 
		carry = ((an & bn) | ((an ^ bn) & carry)) << 1;
		n <<= 1;

		an = a & n;
		bn = ~b & n;
		sum |= (an ^ bn) ^ carry; // 
		carry = ((an & bn) | ((an ^ bn) & carry)) << 1;
		n <<= 1;
		an = a & n;
		bn = ~b & n;
		sum |= (an ^ bn) ^ carry; // 
		carry = ((an & bn) | ((an ^ bn) & carry)) << 1;
		n <<= 1;

		an = a & n;
		bn = ~b & n;
		sum |= (an ^ bn) ^ carry; // 
		carry = ((an & bn) | ((an ^ bn) & carry)) << 1;
		n <<= 1;
		an = a & n;
		bn = ~b & n;
		sum |= (an ^ bn) ^ carry; // 
		carry = ((an & bn) | ((an ^ bn) & carry)) << 1;
		n <<= 1;

		an = a & n;
		bn = ~b & n;
		sum |= (an ^ bn) ^ carry; // 
		carry = ((an & bn) | ((an ^ bn) & carry)) << 1;
		n <<= 1;
		an = a & n;
		bn = ~b & n;
		sum |= (an ^ bn) ^ carry; // 
		carry = ((an & bn) | ((an ^ bn) & carry)) << 1;
		n <<= 1;

		an = a & n;
		bn = ~b & n;
		sum |= (an ^ bn) ^ carry; // 
		carry = ((an & bn) | ((an ^ bn) & carry)) << 1;
		n <<= 1;
		an = a & n;
		bn = ~b & n;
		sum |= (an ^ bn) ^ carry; // 
		carry = ((an & bn) | ((an ^ bn) & carry)) << 1;
		n <<= 1;

		an = a & n;
		bn = ~b & n;
		sum |= (an ^ bn) ^ carry; // 
		carry = ((an & bn) | ((an ^ bn) & carry)) << 1;
		n <<= 1;
		an = a & n;
		bn = ~b & n;
		sum |= (an ^ bn) ^ carry; // 
		carry = ((an & bn) | ((an ^ bn) & carry)) << 1;
		n <<= 1;

		an = a & n;
		bn = ~b & n;
		sum |= (an ^ bn) ^ carry; // 
		carry = ((an & bn) | ((an ^ bn) & carry)) << 1;
		n <<= 1;
		an = a & n;
		bn = ~b & n;
		sum |= (an ^ bn) ^ carry; // 
		carry = ((an & bn) | ((an ^ bn) & carry)) << 1;
		n <<= 1;

		an = a & n;
		bn = ~b & n;
		sum |= (an ^ bn) ^ carry; // 
		carry = ((an & bn) | ((an ^ bn) & carry)) << 1;
		n <<= 1;
		an = a & n;
		bn = ~b & n;
		sum |= (an ^ bn) ^ carry; // 
		carry = ((an & bn) | ((an ^ bn) & carry)) << 1;
		n <<= 1;

		an = a & n;
		bn = ~b & n;
		sum |= (an ^ bn) ^ carry; // 
		carry = ((an & bn) | ((an ^ bn) & carry)) << 1;
		n <<= 1;
		an = a & n;
		bn = ~b & n;
		sum |= (an ^ bn) ^ carry; // 
		carry = ((an & bn) | ((an ^ bn) & carry)) << 1;
		n <<= 1;

		an = a & n;
		bn = ~b & n;
		sum |= (an ^ bn) ^ carry; // 
		carry = ((an & bn) | ((an ^ bn) & carry)) << 1;
		n <<= 1;
		an = a & n;
		bn = ~b & n;
		sum |= (an ^ bn) ^ carry; // 
		carry = ((an & bn) | ((an ^ bn) & carry)) << 1;
		n <<= 1;

		an = a & n;
		bn = ~b & n;
		sum |= (an ^ bn) ^ carry; // 
		carry = ((an & bn) | ((an ^ bn) & carry)) << 1;
		n <<= 1;
		an = a & n;
		bn = ~b & n;
		sum |= (an ^ bn) ^ carry; // 
		carry = ((an & bn) | ((an ^ bn) & carry)) << 1;
		n <<= 1;

		an = a & n;
		bn = ~b & n;
		sum |= (an ^ bn) ^ carry; // 
		carry = ((an & bn) | ((an ^ bn) & carry)) << 1;
		n <<= 1;

		return sum;
}