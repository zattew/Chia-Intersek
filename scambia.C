#include<iostream>
#include<string>

using namespace std;



void scambia ( int * a, int * b, string * cromoa, string * cromob, string * NMa, string * NMb, string * genea, string * geneb )
{
	int c = *a;
	*a = *b;
	*b = c;

	string cromoc = *cromoa;
	*cromoa = *cromob;
	*cromob = cromoc;

	string NMc = *NMa;
	*NMa = *NMb;
	*NMb = NMc;

	string genec = *genea;
	*genea = *geneb;
	*geneb = genec;
	
	return;

}
