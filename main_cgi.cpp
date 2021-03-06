#include <iostream>
using namespace std;
#include <vector>
#include "Field.h"
#include "BestActionAndUtility.h"
#include "QBrain.h"
#include "Neuron.h"
#include "Neural_Network.h"


#include <cgicc/CgiDefs.h> 
#include <cgicc/Cgicc.h> 
#include <cgicc/CgiEnvironment.h> 
#include <cgicc/HTTPHTMLHeader.h> 
#include <cgicc/HTMLClasses.h>
using namespace std;
using namespace cgicc;


int main(){

    int number_training_games = 100;
    int number_training_pieces = 10000;
    int number_game_pieces = 10000;

    int data_success = 0;

   	float alpha = 0;
    float gamma = 0;

	Cgicc formData;

	// CGI header
	cout << "Content-type:text/html\r\n\r\n";

	// Form to get alpha and gamma

	form_iterator fi_alpha = formData.getElement("alpha");

	if( !fi_alpha->isEmpty() && fi_alpha != (*formData).end()) {  
		alpha = stof( **fi_alpha );
		data_success += 1;
	} else {
		cout << "Veuillez préciser le paramètre alpha" << endl;
	}

	form_iterator fi_gamma = formData.getElement("gamma");

	if( !fi_gamma->isEmpty() && fi_gamma != (*formData).end()) {
		gamma = stof( **fi_gamma );
		data_success += 1;
	}else{
		cout << "Veuillez préciser le paramètre alpha" << endl;
	}

	// If the user entered gamma and alpha we print the Q-table so the JS script can save it
	if ( data_success == 2){

		QBrain Q(alpha,gamma,100);

		Q.Train(number_training_games, number_training_pieces);

        float* _pQ = Q.GetQ();

		for ( int i = 0 ; i < 4096 ; i++){
			cout<<_pQ[i]<<" ";
		}
		}

}