#include<iostream>
#include<fstream>
#include<vector>
#include<string>

using namespace std;

void leggi_ancore_sox2 ( ifstream& ancora, vector<string> &S ,vector<string> &ancora_crom , vector<int> &start , vector<int> &end , int *dim )
{
	string ss = "", temp_crom = "";
	int start_temp = 0, end_temp = 0;

	while ( ancora >> ss >> temp_crom >> start_temp >> end_temp )   
	{
		int differenza = ( end_temp - start_temp );

		if ( differenza < 500000 )
		{

		S.push_back(ss);
		ancora_crom.push_back(temp_crom);
		start.push_back(start_temp);
		end.push_back(end_temp);
	
		}
	}


	int dim1 = start.size();
	
	*dim =  dim1;

	 return;

}
