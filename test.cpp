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
#include <limits>
#include <math.h> 
#include <stdlib.h> 
#include <fstream>
using namespace std;

int GetArgUtility(vector<int> ttl){
	int arg_u=0;
	for (int i=0;i<12;i++){
		arg_u+=ttl[i]*pow(2,i);
	}
	return arg_u;

}

vector<int> TtlFromArg(int i){
	vector<int> ttl(12,0);
	for (int j=0;j<12;j++){
		if (pow(2,(11-j))<=i){
			ttl[11-j]=1;
			i-=pow(2,(11-j));
		}
	}
	return ttl;
}

vector<int> ChoosePositionRotation(Piece piece, vector<int> ttl,vector<float> Q){
		int type=piece.GetType();
		int rotation_number=piece.GetNumberOfPossibleRotation();
		Field f(ttl,0,piece);
		int pos=0;
		int rot=1;
		float arg=numeric_limits<int>::min();
		vector<int> ttl2;
		for (int i=1;i<rotation_number+1;i++){
			f.SetPiece(type,i);

			
			for(int j=0;j<5;j++){
				ttl2=f.MakeMove(j);
				ttl2=vector<int>(ttl2.begin(),ttl2.end()-1);
				if(Q[GetArgUtility(ttl2)]>arg){
					pos=j;
					rot=i;
					arg=Q[GetArgUtility(ttl2)];
				}
			}
		}
		vector<int> rep(2);
		rep[0]=pos;
		rep[1]=rot;
		return rep;
	}

int Game(vector<float>& Q1,int number_of_rounds,float alpha,float gamma){
	Field f;
	Piece piece;
	vector<int> ttl(12,0);
	vector<int> ttl_inter(12,0);
	f.SetHeight(0);
	f.SetTtl(ttl);
	int arg_ttl=0;
	int arg_ttl_2=0;
	int height=0;
	int reward=0;

	int pos_rotation_number;
	int piece_type;
	vector<int> pos_rot;
	for (int i=0;i<number_of_rounds;i++){
		piece_type=rand()%5+1;
		piece.SetAll(piece_type,1);
		pos_rot=ChoosePositionRotation(piece,ttl,Q1);
		f.SetPiece(piece_type,pos_rot[1]);
		ttl_inter=f.MakeMove(pos_rot[0]);
		/*if( i<10){
		cout<<"piece_type: "<<piece_type<<" "<<"rotation "<<pos_rot[1]<<endl;
		cout<<"position: "<<pos_rot[0]<<endl;
		cout<<"premier:"<<endl;
		for (int i=0;i<6;i++){
			cout<<ttl[6+i]<<" ";
		}
		cout<<endl;
		for (int i=0;i<6;i++){
			cout<<ttl[i]<<" ";
		}
		cout<<endl;
		cout<<"second: "<<endl;
		for (int i=0;i<6;i++){
			cout<<ttl_inter[6+i]<<" ";
		}
		cout<<endl;
		for (int i=0;i<6;i++){
			cout<<ttl_inter[i]<<" ";
		}
		cout<<endl<<endl;

		}*/
		ttl=vector<int>(ttl_inter.begin(),ttl_inter.end()-1);
		f.SetHeight(ttl_inter[12]);
		reward=-100*(ttl_inter[12]-height);
		height=ttl_inter[12];
		f.SetTtl(ttl);
		arg_ttl_2=GetArgUtility(ttl);
		Q1[arg_ttl]=(1-alpha)*Q1[arg_ttl]+alpha*(reward+gamma*Q1[arg_ttl_2]);
		arg_ttl=arg_ttl_2;

	}
	return height;
}
int main() {


	ofstream myfile;
	myfile.open ("example.txt");
	for (int i=1;i<100;i++){
		vector<float> Q(4096,0);
		myfile<<"alpha = "<<0.002*i;
		for (int j=0;j<401;j++){
		int height=Game(Q,10000,0.002*i,0.9);
			if ((j%25)==0){
				myfile<<" "<<j<<":"<<height;

			}
		}
		myfile<<endl;

	}
	myfile.close();
	/*for (int i=0;i<4096;i++){

		if (Q[i]!=0){
		cout<<i<<" : "<<Q[i]<<endl;
		vector<int> ttl=TtlFromArg(i);
		for (int i=0;i<6;i++){
			cout<<ttl[6+i]<<" ";
		}
		cout<<endl;
		for (int i=0;i<6;i++){
			cout<<ttl[i]<<" ";
		}
		cout<<endl;
		}
		}
	}
	}
	vector<int> ttl(12,0);
	Piece piece;
	piece.SetAll(4,3);
	Field f(ttl,0,piece);
	vector<int> ttl_inter=f.MakeMove(4);
	cout<<"premier:"<<endl;
		for (int i=0;i<6;i++){
			cout<<ttl[6+i]<<" ";
		}
		cout<<endl;
		for (int i=0;i<6;i++){
			cout<<ttl[i]<<" ";
		}
		cout<<endl;
		cout<<"second: "<<endl;
		for (int i=0;i<6;i++){
			cout<<ttl_inter[6+i]<<" ";
		}
		cout<<endl;
		for (int i=0;i<6;i++){
			cout<<ttl_inter[i]<<" ";
		}
		cout<<endl<<endl;*/


	return 0;
			
	}
	//TODO: prendre une pièce random rendre les états possible après (selon comment on la tourne et où on la place), en prendre le meilleur
	//bizzarre qu'en choisissant le meilleur on s'améliore tout de  même 

