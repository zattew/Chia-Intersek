#include"prototipi.h"


void pacman ( int x ,int dimensioni ) 
{

	float progress = 0.0; 
	int barWidth = 70;
	
	x = x + 1;

	progress = ((x * 1.0) / dimensioni) ; // for demonstration only

	int pos = barWidth * progress;
	
	cout << "[";
		 
	for (int j = 0; j < barWidth; ++j) 
	{			        
		if (j < pos) cout << "-";			        
			
		else if (j == pos && (j % 2) == 0) cout << termcolor::yellow<< "C" << termcolor::white;
		else if (j == pos && (j % 2) != 0) cout << termcolor::yellow << "c" << termcolor::white;
		
		else
		{ 	
			
			if ( j % 18 == 0 ) cout <<termcolor::red<< "ᗣ" <<termcolor::white;
			else if ( j % 2 == 0) cout << "•";
			else  cout << " ";			    
		}
	}
			
				
	cout << "] " << int(progress * 100.0) << " %\r";
	cout.flush();


	return ;
}
