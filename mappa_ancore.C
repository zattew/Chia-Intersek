#include "prototipi.h"


void mappa_ancore( map<string, vector<int> > &mappa, vector <string> &crom_ancora, vector<int> &start_ancora, vector<int> &end_ancora, vector<string> &crom_tss, vector<int> &start_tss,vector<string> &gene_tss , int intorno, string quale)
{
	int tot_ancore = crom_ancora.size();
	int tot_tss = crom_tss.size();
	int i = 0, j = 0;

	for ( i = 0; i < tot_ancore; i++)
	{
		cout<<"Mappaggio "<<quale<<"\t";
		pacman(i,tot_ancore);

		for ( j = 0; j < tot_tss; j++)
		{
			if ( crom_ancora[i] == crom_tss[j] )
			{
				string keys = gene_tss[j];
				int value = (i+1);
				
				int inferiore = start_tss[j] - intorno;
				int superiore = start_tss[j] + intorno;

				//verifica se cade inizio ancora in intorno di 1000	
				if( start_ancora[i] >= inferiore && start_ancora[i] <= superiore )
				{
					mappa[keys].push_back(value);
				}
				
				//verifica se cade fine ancora in intorno di 1000 solo se la prima condizione è falsa	
				else if( end_ancora[i] >= inferiore && end_ancora[i] <= superiore )
				{

					mappa[keys].push_back(value);
				}

				
				//verifica che l'ancora comprenda il TSS se le altre due condizioni sono false
				else if (  start_ancora[i] <= inferiore  && end_ancora[i] >= superiore )
				{

					mappa[keys].push_back(value);
				}
			}
		}
	}

	return;
}

