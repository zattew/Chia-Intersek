#include "prototipi.h"

//Prototipi

// gene_espressione( file,  mappa<string,float>); i valori di espressione sono float.

// bubble(coordinate, cromosomi, NM, geni, dim)  

// leggi_ancora( file, crom_ancora, start, end, &dim )

// leggi_tss(file, NM, crom, start, gene, &dim )


int main(int argc, char** argv )
{

	system("clear");
	system("figlet 'Chia Intersek' ");
	cout<<endl<<endl;

	int i = 0;
	
	//setto l'intorno
	
	int intorno = 1000;

	//Variabili per la lettura del primo file

	ifstream tss ( argv[1] );
	string linea = "";

	ifstream ancora_left ( argv[2] );	
	string linea_left = "";

	ifstream ancora_right ( argv[3] );
	string linea_right = "";

	ofstream risultati("Risultati.txt");

	if ( argc != 4 )
	{	
		cout<<"Usage: ./main.x crom_coord ancora_left ancora_right"<<endl;      	
		return 1;
	}


	vector <string> NM;
       	vector <string> crom;
       	vector <string> gene;
       	vector <string> strand;
	vector <int> start;
	int dimensioni = 0;	
	
	//Leggo file Tss

	leggi_tss( tss, NM, crom, start, gene, &dimensioni );

	// Ordino il Tss

	bubble( start, crom, NM, gene, dimensioni);   

	//Variabili per la lettura del secondo file

	vector <string> crom_left;
	vector <int> start_left, end_left;
	
	vector <string> crom_right;
	vector <int> start_right, end_right;

	//lettura ancore

	int tot_ancore_left = 0;
	int tot_ancore_right = 0;

	leggi_ancore(ancora_left, crom_left, start_left, end_left, &tot_ancore_left ); 
	leggi_ancore(ancora_right, crom_right, start_right, end_right, &tot_ancore_right );

	//Incrocio delle ancore con il Tss in un intorno di mille

	// l'idea è creare una mappa di vettori di coordinate

	map <string, vector <int> > mappa_left, mappa_left1;
	map <string, vector <int> > mappa_right, mappa_right1;

	string ancora = "left";
	mappa_ancore( mappa_left, crom_left, start_left, end_left, crom, start,gene ,  intorno, ancora );
	cout<<endl;
	
	ancora = "right";
	mappa_ancore( mappa_right, crom_right, start_right, end_right, crom, start,gene ,  intorno, ancora );
	cout<<endl;

	//Stampo le due ancore in due file rimuovendo quelle che si ripetono

	ofstream scrivi;
	scrivi.open("geni_ancore_left.txt");

	ofstream scrivi1;
	scrivi1.open("geni_ancore_right.txt");

	int mappa_left_dim = mappa_left.size();
	int mappa_right_dim = mappa_right.size();


	//ordino la mappa

	mappa_ordinata ( mappa_left, mappa_left1);
	mappa_ordinata ( mappa_right, mappa_right1);


	//controllo i casi particolari in cui una ancora cade su due o più geni sia nella parte sx che dx;
	
	map <int, vector<string> > ancore_sovrapposte;
	map <int, vector<string> >::const_iterator tt;
	

	casi_particolari(start_left.size(), mappa_left1, mappa_right1, ancore_sovrapposte );
	cout<<endl;

	//stampo le ancore

 	stampa_ancore( mappa_left1, scrivi);
 	stampa_ancore( mappa_right1, scrivi1);
	
	// pulisco le variabili usate
	scrivi.close();
	scrivi.clear();

	scrivi1.close();
	scrivi1.clear();

	mappa_left.clear();
	mappa_right.clear();

	//lettura ancore dai file per determinare promotori ed enhancer
	
	vector<string> geni_ancore_left;
	vector<int> prom_ass_left, enh_ass_left;
	vector<string> geni_ancore_right;
	vector<int> prom_ass_right, enh_ass_right;

	ifstream left ("geni_ancore_left.txt");
	ifstream right ("geni_ancore_right.txt");
	
	int uno = 1;

	lettura_ancore( left, right,geni_ancore_left, prom_ass_left, enh_ass_left, mappa_left_dim, uno);
	cout<<endl;
	
	left.clear();
	left.close();
	right.clear();
	right.close();

	left.open("geni_ancore_left.txt");
	right.open("geni_ancore_right.txt");

	uno++;

	lettura_ancore( right, left,geni_ancore_right, prom_ass_right, enh_ass_right, mappa_right_dim, uno);
	cout<<endl;
	
	left.clear();
	left.close();
	right.clear();
	right.close();

	//Decommenta questo comando sotto se vuoi vedere Nome gene e numero dell'ancora caduta sul gene
	system("rm geni_ancore_left.txt geni_ancore_right.txt");

	//unisco in un ultimo vettore tutte le ancore e i rispettivi punteggi;
	
	map <string, int > geni_totali;
	map <string, int >::const_iterator it;
	vector <string> tutti_geni; 

	for ( i = 0; i < geni_ancore_left.size(); i++)
		geni_totali[geni_ancore_left[i]] = 1;

	for ( i = 0; i< geni_ancore_right.size(); i++)
		geni_totali[geni_ancore_right[i]] = 1;

	for ( it = geni_totali.begin(); it != geni_totali.end(); it++)
		tutti_geni.push_back(it->first);


	//vettori finali
	
	vector<int> prom_finali, enh_finali;

	for ( i = 0; i < tutti_geni.size(); i++)
	{
		int final_prom = 0, final_enh = 0;

		for (int j = 0; j < geni_ancore_left.size(); j++)
		{
			if ( tutti_geni[i] == geni_ancore_left[j] )
			{
				final_prom = prom_ass_left[j];
				final_enh = enh_ass_left[j];
				break;
			}
		}
		
		for (int j = 0; j < geni_ancore_right.size(); j++)
		{
			if ( tutti_geni[i] == geni_ancore_right[j] )
			{
				final_prom =final_prom + prom_ass_right[j];
				final_enh = final_enh + enh_ass_right[j];
			
				//Se ci sono casi particolari devo sottrarre dal totale
				for ( tt = ancore_sovrapposte.begin(); tt != ancore_sovrapposte.end(); tt++)
				{
					for ( int j = 0; j < tt->second.size(); j++)
						if ( tutti_geni[i] == tt->second[j] )
							final_prom = final_prom - (tt->second.size() * ( (tt->second.size() - 1)) - 1); 
							
							// sottraggo il numero dei geni diviso due, corrispondente a second.size(), dopo moltiplico per il numero di interazioni che ha ogni gene considerando che quando un gene è uguale tra dx e sx  non ci sono interazioni. Quindi in un box di 2 * 2 le interazioni per gene sono 1 e ogni gene aggiunge 1 ai promotori, quindi basta sottrarre uno alla conta totale.Così via all'aumentare dei geni.
				
				}

				break;
			}
		}


		prom_finali.push_back(final_prom);
		enh_finali.push_back(final_enh);

	}


	//stampa finale

	risultati<<"Geni"<<"\t"<<"prom"<<"\t"<<"enh"<<endl;
	
	for ( i = 0; i < tutti_geni.size(); i++)
		risultati<<tutti_geni[i]<<"\t"<<prom_finali[i]<<"\t"<<enh_finali[i]<<endl;

	cout<<endl<<endl;
	cout<<termcolor::on_blue<<"risultati salvati nella cartella corrente in Risultati.txt"<<termcolor::reset<<endl;
	
	cout<<endl;

	return 0;
}
