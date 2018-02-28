#include <iostream>
#include <math.h>
#include <stdlib.h>
#define MXSTZ 10


class bmneuron
{
	protected:
		int nnbr;
		int inn,outn;
		int output;
		int activation;
		int outwt[MXSTZ] ;
		char * name;
		friend class network;

	public:
		bmneuron();
		void getnrn(int,int,int,char*);

};

class exemplar
{

protected:
	int xdim,ydim;
	int v1[MXSTZ],v2[MXSTZ];
	int u1[MXSTZ],u2[MXSTZ];
	friend class network;
	friend class mtrx;

public:
	exemplar();
	void getexmplr(int,int,int,int *, int *);
	void prexmplr();
	void trnsfrm();
	void prtrnsfrm();
};

class asscpair
{
protected:
	int xdim,ydim,idn;
	int v1[MXSTZ],v2[MXSTZ];
	friend class network;

public:
	asscpair();
	void getasscpair(int,int,int);
	void prasscpair();
};

class potlpair
{
protected:
	int xdim,ydim;
	int v1[MXSTZ],v2[MXSTZ];
	friend class network;

public:
	potlpair() {};
	void getpotlpair(int,int);
	void prpotlpair();
};


class network
{
public:
	int anmbr,bnmbr,flag,nexmplr,nasspr,ninpt;
	bmneuron (anrn) [MXSTZ], (bnrn) [MXSTZ];
	exemplar (e) [MXSTZ];
	asscpair (as) [MXSTZ];
	potlpair (pp) [MXSTZ];
	int outs[MXSTZ], outs2[MXSTZ];
	int mtrx1[MXSTZ][MXSTZ], mtrx2[MXSTZ][MXSTZ];

	network() {};
	void getnwk(int,int,int,int [][6], int[][5]);
	void compr1(int,int);
	void compr2(int,int);
	void prwts();
	void iterate();
	void findassc(int *);
	void assgninpt(int *);
	void assgnvect(int, int *, int *);
	void comput1();
	void comput2();
	void prstatus();

};

