#include <stdio.h>

typedef struct {
	int RA ;
	int RB ;
	int RO ;
	//int sum ;
} Reg;

typedef struct {
int j;
int c;
int D0;
int D1;
int S;
int Sreg;
int imm;


} flags;

flags decoder(int inst){
	flags f;

	if (inst && 0x80)
		f.j=1;
	else if (inst && 0x40)
		f.c=1;
	else if (inst && 0x20)
		f.D1=1;
	else if (inst && 0x01)	
		f.D0=1 ;
	else if (inst && 0x08)
		f.Sreg=1;
	else if (inst && 0x04)
		f.S=1;

			return f;
	}

/*Reg alu (Reg r, flags f){
	if (f.D0 == 1)
		r.RB = RA + RB;
	else if (f.s == 1)
 		r.RA = RA - RB;
	else if (f.s == 1 && f.D0 ==1)
		r.RB = RA -RB;
	else if (f.D == 1)
		r.RO = r.RA;	
	else if (f.Sreg==1)
		r.RA=imm;
	else if (f.D0==1 && f.Sreg==1)
		r.jc=imm;
	else if (f.j==1 && D0==1 && D1==1)
		r.j=imm;
return r; 
		
		}
*/

int mux (int s ,int sum, int imm=1) {
int mux=0;
	if (s==1)
		mux= imm;
	else
		mux= sum;

return mux;
}

int mux (int , int ,Reg Reg){
	if(D0==0 && D1==0)
		return Reg.RA;
	else if (D0==0 && D1==1)
		return Reg.RB;
	else (D0==1 && D1==0)
		return Reg.RO; 
			
}

int main() 
{
	
}
