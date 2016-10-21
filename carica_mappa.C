#include "prototipi.h"

void carica_mappa ( ifstream &file, map<string, vector<int> > &mappa )
{
	string linea = "";

	while ( getline (file, linea) )
	{
		istringstream word(linea);
		
		string keys = "";
		int value = 0;		

		word >> keys;
		
		while(word >> value )
		{
			mappa[keys].push_back(value);				
		}
	}

	return;
}
