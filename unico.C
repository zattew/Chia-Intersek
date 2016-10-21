#include "prototipi.h"

void unico ( vector<int> &temp, vector<int> &temp1 )
{
	sort (temp.begin(), temp.end());
	int i = 0, j = 0;
	
	for ( i = 0; i < temp.size(); i++)
	{
		int cont = 0;

		if ( i > 0 )
		{
			for ( j = 0; j < temp1.size(); j++)
			{
				if ( temp1[j] == temp[i])
				{
					cont = 1;
					break;
					}
				}
			}

		if ( cont == 0 )
			temp1.push_back(temp[i]);
	}
	
		
	return;
		
}	




