#include"prototipi.h"


void casi_particolari ( int dim, map <string, vector<int> > &left, map <string, vector<int> > &right, map <int, vector<string> > &casi_particolari ){
	map <string, vector<int> >::const_iterator it;

	for ( int i = 1 ; i <= dim; i++)
	{
		
		cout<<"Sovrapposizioni\t";
		pacman(i,dim);	

		vector<string> vettore_geni;

		for ( it = left.begin(); it != left.end(); it++)
		{
			for ( int j = 0; j < it->second.size(); j++)
				if ( it->second[j] == i )
				{	
					vettore_geni.push_back(it->first);	
					break;
				}

		}
	
		//solo se hai trovato più di due geni che hanno la stessa ancora
		

		vector<string> vettore_geni1;

		if ( vettore_geni.size() > 1 )
		{
			for ( it = right.begin(); it != right.end(); it++)
			{
				for ( int j = 0; j < it->second.size(); j++)
				       if ( it->second[j] == i )
				       {
					       for ( int x = 0; x < vettore_geni.size(); x++)
					       {
						      if( vettore_geni[x] == it->first )
						      {
							      vettore_geni1.push_back(vettore_geni[x]);
							      break;
						      }
					       }
							      
					       break;
				       }
			}			

		
		}
	
	
		if ( vettore_geni1.size() > 1 )
			for ( int j = 0; j < vettore_geni1.size(); j++)
				casi_particolari[i].push_back(vettore_geni1[j]);
	
	}



	return;
}
	
