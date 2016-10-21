#include"prototipi.h"



//se due o più geni hanno due o più ancore dx e sx che cadono tutte su quegli stessi geni allora

void cerca_ancore_uguali ( int dim_ancore, map < string, vector < int > > &left, map < string, vector < int > > &right )
{

	map < string, vector < int > >::const_iterator it;
	map < string, vector < int > >::const_iterator it1;

	vector < string > geni_left, geni_right;
	vector < int > ancore_left, ancore_right;


	for ( it = left.begin(); it != left.end(); it++)
	{
		geni_left.push_back(it->first);
		cout<<it->first<<" "<<it->second.size()<<endl;
	}



	return;

}


