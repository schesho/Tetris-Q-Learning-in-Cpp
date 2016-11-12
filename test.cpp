//============================================================================
// Name        : test.cpp
// Author      : Sholom
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "Field.h"
#include "Piece.h"
#include <vector>
using namespace std;

int main() {
	Field f1;
	cout<<" height: "<<f1.GetHeight()<<endl;

	vector<int> ttl=f1.GetTtl();


	f1.SetPiece(2,2);
	ttl=f1.GetTtl();
	for (int i=0;i<6;i++){
		cout<<ttl[i+6]<<" ";
	}
	cout<<endl;

	for (int i=0;i<6;i++){
		cout<<ttl[i]<<" ";
	}
	cout<<endl;
	f1.MakeMove(0);
	cout<<" height: "<<f1.GetHeight()<<endl;
	ttl=f1.GetTtl();
	for (int i=0;i<6;i++){
		cout<<ttl[i+6]<<" ";
	}
	cout<<endl;

	for (int i=0;i<6;i++){
		cout<<ttl[i]<<" ";
	}
	cout<<endl;
	f1.MakeMove(0);
	cout<<" height: "<<f1.GetHeight()<<endl;
	ttl=f1.GetTtl();
	for (int i=0;i<6;i++){
		cout<<ttl[i+6]<<" ";
	}
	cout<<endl;

	for (int i=0;i<6;i++){
		cout<<ttl[i]<<" ";
	}
	cout<<"cool.."<<endl;
	return 0;
}
