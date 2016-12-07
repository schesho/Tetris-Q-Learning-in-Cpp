/*
 * field.h
 *
 *  Created on: Nov 10, 2016
 *      Author: sel
 */
#include "Piece_old.h"
#include <vector>
using namespace std;

#ifndef FIELD_H_
#define FIELD_H_

class Field {
private:
	vector<int> _ttl;/*top two levels :12 length array of 0 and 1 representing the 2 top levels of the game*/
	int _height; /*current height*/
	Piece _piece;/*type of piece falling from 1 to 5 (check the documentation)*/
public:
	Field();
	Field(vector<int>,int,Piece);
	virtual ~Field();
	/*below are getters and setters*/ 
	int GetHeight(void);
	void SetHeight(int);
	vector<int> GetTtl(void);
	void SetTtl(vector<int>);

	Piece GetPiece(void);
	void SetPiece(int,int);//set type and rotation


	/*using _piece.GetShape() and _ttl MakeMove an output given is changing _ttl*/
	vector<int> MakeMove(int);


};
#endif /* FIELD_H_ */

