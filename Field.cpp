/*
 * field.cpp
 *
 *  Created on: Nov 10, 2016
 *      Author: sel
 */

#include "Field.h"
#include <iostream>
using namespace std;
#include "Piece.h"
#include <algorithm>

vector<int> zeros_vector(12,0);

Field::Field(){
	vector<int> a(12,0);
	_ttl=a;

	for (int i=0;i<12;i++){
		_ttl[i]=0;
	}
	_height=0;
	_piece=Piece();
	// TODO Auto-generated constructor stub

}

Field::~Field() {
	// TODO Auto-generated destructor stub
}

int Field::GetHeight(){
	return _height;
}

void Field::SetHeight(int h){
	_height=h;
}

vector<int> Field::GetTtl(){
	return _ttl;
}

void Field::SetTtl(vector<int> ttl){
	for (int i=0;i<12;i++){
		_ttl[i]=ttl[i];
	}
}

Piece Field::GetPiece(){
	return _piece;
}

void Field::SetPiece(int type,int rotation){
	_piece.SetAll(type,rotation);
}



bool Field::MakeMove(int position){
	int type=_piece.GetType();
	vector<int> shape=_piece.GetShape();

	vector <int> tfl(24,0); /*an intermediate top four levels, which are the original top two levels + 2 levels of zeros*/

	for(int i=0;i<12;i++){
		tfl[i]=_ttl[i];
	}

	if((tfl[position+6]==1 and shape[0]==1) or (tfl[position+7]==1 and shape[1]==1)){//means that the piece cannot fall
			tfl[position+12]=shape[0];
			tfl[position+13]=shape[1];
			tfl[position+18]=shape[2];
			tfl[position+19]=shape[3];
	}

	else if ((tfl[position+6]==1 and shape[2]==1) or (tfl[position+7]==1 and shape[3]==1)){
		//means that the piece is falling only one step down

			tfl[position+6]=std::max(tfl[position+6],shape[0]);
			tfl[position+7]=std::max(tfl[position+7],shape[1]);
			tfl[position+12]=shape[2];
			tfl[position+13]=shape[3];
	}

	else{//there is no obstruction, the piece is falling down 
		tfl[position]=std::max(tfl[position],shape[0]);
		tfl[position+1]=std::max(tfl[position+1],shape[1]);
		tfl[position+6]=std::max(tfl[position+6],shape[2]);
		tfl[position+7]=std::max(tfl[position+7],shape[3]);
	}
	int first_row=-1;//1 if the row is full and thus need to be removed//
	int second_row=-1;//same as first 

	int third_row=0; //0 if the row is full of zeros and therefore unused
	int fourth_row=0;//same as third
	for (int j=0;j<6;j++){
		if (tfl[j]==0){
			first_row=0;
		}
		if(tfl[j+6]==0){
			second_row=0;
		}

		if (tfl[j+12]==1){
			third_row=1;
		}
		if (tfl[j+18]==1){
			fourth_row=1;
		}
	}
	_height=_height+std::max(0,first_row+second_row+third_row+fourth_row);//how height is changing
	if (fourth_row==1){
		cout<<1<<endl;
		for (int i=0;i<12;i++){
			_ttl[i]=tfl[i+12];
		}
	}

	else if (third_row==1){
		cout<<2<<endl;
		if (second_row==0){
			for (int i=0;i<12;i++){
				_ttl[i]=tfl[i+6];
			}
		}

		else if (first_row==0){
			for (int i=0;i<6;i++){
				_ttl[i]=tfl[i];
				_ttl[i+6]=tfl[i+12];
			}
		}
		else{
			for (int i=0;i<6;i++){
				_ttl[i]=tfl[i+12];
				_ttl[i+6]=0;

			}
		}

	}

	else{
		cout<<3<<endl;
		for (int i=0;i<12;i++){
			_ttl[i]=tfl[i];
		}
	}


	return true;

}