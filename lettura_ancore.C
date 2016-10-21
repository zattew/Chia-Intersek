#include"prototipi.h"


void lettura_ancore (ifstream &prima, ifstream &seconda ,vector<string> &gene, vector<int> &promotori_associati, vector<int> &enhancer_associati, int dim_mappa, int uno ) 
{

	int pac_man = 0;

	string linea = "", linea1 ="";
	
	vector<int> vettore_punteggio;
	//int vett = 0;

	string temp_gene, temp_gene1;
	
	while ( getline ( prima, linea ) )
	{
		istringstream word(linea);
		
		vector<int> temp;
		
		//conosco la lunghezza della prima linea
		
		cout<<"Interazioni  "<<termcolor::red<<uno<<termcolor::white<<"\t";
		pacman( pac_man, dim_mappa );
			
		pac_man++;

		//dichiaro prima del ciclo, ogni volta deve riazzerarsi
		int tot = 0;

		//cancello vettore punteggio

		vettore_punteggio.clear();

		string colonna = "";

		while ( word >> colonna )
		{
			if ( tot == 0 )
			{
				temp_gene = colonna;
				tot++;
			}

			else
			{
				int num = atoi( colonna.c_str() );
				temp.push_back(num);
			}
		}


		//inizializzo il vettore punteggio a zero

		for ( int i = 0; i < temp.size(); i++)
			vettore_punteggio.push_back(0);

		
		//apro il secondo file e linea per linea controllo se è presente l'ancora

		//dichiaro il tot

		while ( getline(seconda, linea1) )
		{
			istringstream word(linea1);

			string colonna1 = "";
			
			//dichiaro prima di entrare nel ciclo, ogni volta deve riazzerarsi.
			int tot1 = 0;

			//dichiaro temp1 in maniera tale che si riazzeri a ciclo completato
			vector<int> temp1;


			while ( word >> colonna1 )
			{
				if ( tot1 == 0 )
				{
					temp_gene1 = colonna1;
					tot1++;
				}

				else
				{
					int num1 = atoi( colonna1.c_str() );
					temp1.push_back(num1);
				}
			}
		

			//tengo traccia dei geni associati con un vettore perchè se si ripetono, non vanno contati

			vector<string> contatore_geni;
			int prima_volta = 0;

			for ( int i = 0; i < temp.size(); i++)
			{	
				for ( int j = 0; j < temp1.size(); j++)
				{
					//Se il gene è uguale e le ancore sono uguali
					if ( temp_gene == temp_gene1 && temp[i] == temp1[j] )
					{
						/* Se non hai ancora trovato nessuna ancora oltre a questa dello
						 stesso gene, setta il punteggio a -1 perchè se non si trova nulla
						 questo gene non va messo. Vuol dire che sx e dx cadono sulla stesso gene e basta
						 se si lascia zero, vengono segnati come enhancer che in realtà non esistono*/

						if (vettore_punteggio[i] == 0 )
							vettore_punteggio[i] = -1;
					}

					else if ( temp[i] == temp1[j]  )
					{
						
						/*Se quest'ancora era caduto sullo stesso gene ma ne hai trovati altri,
						riprendi il conteggio dei promotori*/

						if ( vettore_punteggio[i] == -1 ) vettore_punteggio[i] = 0;
						
						//va tenuta traccia del gene trovato, ma se è la prima volta che entri qua dentro
						//non va avviato il ciclo.

						
						if ( prima_volta == 0 )
						{
							vettore_punteggio[i]++;
							contatore_geni.push_back(temp_gene1); 
						}
							
						else
						{
							int controllo = 0;

							//se trovi il gene allora metti il controllo = -1;

							for ( int z = 0; z < contatore_geni.size(); z++)
								if ( contatore_geni[z] == temp_gene1 )
								{
									controllo = -1;

									//Se il punteggio è ancora a zero, devo dire al programma
									//che questo gene deve essere segnato come ripetizione, non come
									//enhancer. Se il punteggio è uguale a 1 invece basta non incrementare
									//il punteggio.

									if ( vettore_punteggio[i] == 0 ) vettore_punteggio[i] = -1;
								}

						
							//solo se non è presente allora aumenta il punteggio e metti il gene nel vettore

							if ( controllo == 0 )
							{
								//di nuovo devo verificare che il punteggio non sia uguale a -1 per qualche
								//ripetizione prima di aumentarlo di nuovo;

								if ( vettore_punteggio[i] == -1 ) vettore_punteggio[i] = 0;
								
								vettore_punteggio[i]++;
								contatore_geni.push_back(temp_gene1); 
							}
							
						
						}			

						//Appena entri, aumenta la variabile prima volta per poter effettura i cicli di controllo.
						prima_volta++;

					
					}
				}
			
			}
				
		}
			

		//conteggio di enhancer e promotori
		
		int promo = 0;
		int enh = 0;
		
		for ( int i = 0; i < vettore_punteggio.size(); i++)
		{
			if ( vettore_punteggio[i] == 0 )
				enh++;
			
			else if ( vettore_punteggio[i] > 0 ) 
			       	promo = promo + vettore_punteggio[i];
		}


		//rispedisco i valori al mittente

		if ( promo != 0 || enh != 0 )
		{
			gene.push_back(temp_gene);
			promotori_associati.push_back(promo);
			enhancer_associati.push_back(enh);
		}
		


		//riazzero la parte destra
		seconda.clear() ;
		seconda.seekg(0, ios::beg);

	}


	return;
}
