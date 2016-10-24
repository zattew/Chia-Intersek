#include<iostream>
#include<stdlib.h>
#include<sstream>
#include<fstream>
#include<vector>
#include<string>
#include<map>
#include <algorithm> 
#include"termcolor.hpp"

using namespace std;


void leggi_tss (ifstream& , vector<string>&  , vector<string>&  , vector<int>&  , vector<string>&  , int * );
void leggi_ancore ( ifstream&, vector<string>&, vector<int>&, vector<int>&, int * );
void scambia ( int * , int * , string * , string * , string * , string * , string * , string *  );
void bubble ( vector<int>&, vector<string>&, vector<string>&, vector<string>&, int );
void unico ( vector<int>&, vector<int>& );
void mappa_ancore( map<string, vector<int> >&, vector <string>&, vector<int>&, vector<int>&, vector<string>&, vector<int>&,vector<string>& , int, string );
void stampa_ancore ( map<string, vector<int> >&, ofstream&);
void carica_mappa ( ifstream&, map<string, vector<int> >& );
void lettura_ancore (ifstream&, ifstream& ,vector<string>&, vector<int>&, vector<int>&, int, int ) ;
void pacman ( int ,int ) ;
void cerca_ancore_uguali ( int, map < string, vector < int > >&, map < string, vector < int > >& );
void mappa_ordinata ( map<string, vector<int> >&, map<string, vector<int> >&);
void casi_particolari ( int , map <string, vector<int> >&, map <string, vector<int> >&, map <int, vector<string> >& );
void leggi_ancore_sox2 ( ifstream& , vector<string>& ,vector<string>& , vector<int>& , vector<int>& , int * );
void lettura_ancore_sox (ifstream&, ifstream& ,vector<string>&, vector<int>&, int , int , vector<string>& ) ;
