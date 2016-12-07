/*
 * Piece.cpp
 *
 *  Created on: Nov 11, 2016
 *      Author: sel
 */

#include "Piece_old.h"

Piece::Piece() {
	_type=-1;
	_rotation=-1;
	vector<int> shape(4,0);
	_shape=shape;
	// TODO Auto-generated constructor stub

}


Piece::~Piece() {
	// TODO Auto-generated destructor stub
}

void Piece::SetAll(int n, int rotation_number){
	/*sets the type, the rotation number, and the shape resulting from the previous*/
	if( n<6 and n>0){
		_type=n;
		_rotation=rotation_number;
		if (n==1 and rotation_number==1){
			_shape[0]=1;
			_shape[1]=1;
			_shape[2]=1;
			_shape[3]=1;
		}
		else if (n==2){
			if(rotation_number==1){
				_shape[0]=0;
				_shape[1]=1;
				_shape[2]=1;
				_shape[3]=0;}
			else if (rotation_number==2){
				_shape[0]=1;
				_shape[1]=0;
				_shape[2]=0;
				_shape[3]=1;

			};
		}
		else if (n==3){
			if(rotation_number==1){
				_shape[0]=1;
				_shape[1]=1;
				_shape[2]=0;
				_shape[3]=1;

			}
			else if (rotation_number==2){
				_shape[0]=1;
				_shape[1]=1;
				_shape[2]=1;
				_shape[3]=0;

		}
			else if (rotation_number==3){
				_shape[0]=1;
				_shape[1]=0;
				_shape[2]=1;
				_shape[3]=1;

		}

			else if (rotation_number==4){
				_shape[0]=0;
				_shape[1]=1;
				_shape[2]=1;
				_shape[3]=1;
		}

		}

		else if (n==4){
			if (rotation_number==1){
				_shape[0]=1;
				_shape[1]=1;
				_shape[2]=0;
				_shape[3]=0;
			}
			else if (rotation_number==2){
				_shape[0]=1;
				_shape[1]=0;
				_shape[2]=1;
				_shape[3]=0;

			}
			else if (rotation_number==3){
				_shape[0]=0;
				_shape[1]=1;
				_shape[2]=0;
				_shape[3]=1;
			}


		}
		else if (n==5){
			if (rotation_number==1){
				_shape[0]=1;
				_shape[1]=0;
				_shape[2]=0;
				_shape[3]=0;

			}
			else if (rotation_number==2){
				_shape[0]=0;
				_shape[1]=1;
				_shape[2]=0;
				_shape[3]=0;

			}
		}
	}
}

int Piece::GetType(){
	return _type;}

vector<int> Piece::GetShape(){
	return _shape;
}

int Piece::GetRotation(){
	return _rotation;
}



int Piece::GetNumberOfPossibleRotation(){
	if (_type==1){
		return 1;
	}
	else if(_type==2 or _type==5){
		return 2;
	}
	else if (_type==3){
		return 4;
	}
	else{
		return 3;
	}
}
