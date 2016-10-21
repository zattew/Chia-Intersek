#include "prototipi.h"

void mappa_ordinata ( map<string, vector<int> > &mappa, map<string, vector<int> > &mappa1)
{
	map<string, vector<int> >::const_iterator it;
	
	for ( it = mappa.begin(); it != mappa.end(); it++)
	{		
		string gene = it->first;
		
		int i = 0;
		
		vector <int> temp;
		vector <int> temp1;

		for ( i = 0; i < it->second.size(); i++)
			temp.push_back(it->second[i]);
		
		unico(temp, temp1);
	
		for ( i = 0; i < temp1.size(); i++)
			 mappa1[gene].push_back(temp1[i]);
	}	

	return;
}
