#include<iostream>
#include<fstream>
#include<vector>
#include<string>

using namespace std;

void leggi_tss (ifstream& tss , vector<string> &NM, vector<string>  &crom , vector<int>  &start , vector<string> &gene, int *dimensioni )
{

	string temp_NM, temp_crom, temp_gene, temp_strand;
	int start_temp, end_temp;
	
	while ( tss >> temp_NM >> temp_crom >> temp_strand >> start_temp >> end_temp >> temp_gene )
	{

		NM.push_back(temp_NM);
		crom.push_back(temp_crom);
		
		if ( temp_strand == "+" )
			start.push_back(start_temp);
		else
			start.push_back(end_temp);

		gene.push_back(temp_gene);

	}
	
	int dim = NM.size();
	
	*dimensioni = dim;

	return;
}
