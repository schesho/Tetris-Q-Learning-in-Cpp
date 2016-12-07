/*
 * Piece.h
 *
 *  Created on: Nov 11, 2016
 *      Author: sel
 */
#include <vector>
using namespace std;
#ifndef PIECE_H_
#define PIECE_H_

class Piece {
private:
	int _type;
	vector<int> _shape;
	int _rotation;
public:
	Piece();
	virtual ~Piece();
	void SetAll(int,int);//first one is the piece type, second one how the piece is rotated
	int GetType(void);
	vector<int> GetShape(void);
	int GetRotation(void);

	//using the type of the piece give number of shapes that we obtain turning the piece around
};

#endif /* PIECE_H_ */
