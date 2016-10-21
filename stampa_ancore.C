#include "prototipi.h"

void stampa_ancore ( map<string, vector<int> > &mappa, ofstream &scrivi)
{
	map<string, vector<int> >::const_iterator it;
	
	for ( it = mappa.begin(); it != mappa.end(); it++)
	{		
		scrivi<<it->first<<"\t";
		
		int i = 0;
		
		vector <int> temp;

		for ( i = 0; i < it->second.size(); i++)
			temp.push_back(it->second[i]);
		
		for ( i = 0; i < ( temp.size() - 1); i++)
			scrivi<<temp[i]<<"\t";

		scrivi<<temp[(temp.size() - 1)]<<endl;
	}	

	return;
}
