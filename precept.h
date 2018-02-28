#include <stdio.h>
#include <iostream>
#include <math.h>

#define NEURON_COUNT 4

using namespace std;



class ineuron
{
protected:
	float weight;
	float activation;
	friend class oneuron;
public:
	ineuron() {};
	ineuron(float j);
	float act(float x);
};

class oneuron
{
protected:
	int output;
	float activation;
	friend class network;
public:
	oneuron() { };
	void activate(float  x[4], ineuron *nrn);
	int outvalue(float j);
};

class network
{
public:
	ineuron nrn[4];
	oneuron onrn;
	network(float,float,float,float);

};