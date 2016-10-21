#include<iostream>
#include<sstream>
#include<fstream>
#include<vector>
#include<string>

using namespace std;

//ordina per coordinata spostando 4 parametri: NM, cromosoma, coordinata di start, gene.

void scambia ( int * , int * , string * , string * , string * , string * , string * , string *  );

void bubble ( vector<int> &start, vector<string> &crom, vector<string> &NM, vector<string> &gene , int dim)
{
	int i = 0, j = 0;

	for ( i = 1; i < dim; i++)
	{
		if ( crom[i] == crom[i-1] && start[i] < start[i-1] )
		{
			scambia(&start[i],&start[i-1],&crom[i],&crom[i-1],&NM[i],&NM[i-1],&gene[i],&gene[i-1]);

			for ( j = i-1; j > 0 && start[j-1] > start[j] && crom[j] == crom[i]; j-- )
			{
				scambia(&start[j],&start[j-1],&crom[j],&crom[j-1],&NM[j],&NM[j-1],&gene[j],&gene[j-1]);
			}
		}
	}

}
