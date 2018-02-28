#include <stdio.h>
#include <iostream>
#include <math.h>

#define NEURON_COUNT 4


using namespace std;

class neuron
{
protected:
	int activation;
	friend class network;

public:
	int weightv[NEURON_COUNT];
	neuron() {};
	neuron(int *j);
	int act(int, int*);

};

class network
{

public:
	neuron nrn[NEURON_COUNT];
	int output[NEURON_COUNT];
	int threshold(int);
	void activate(int j[NEURON_COUNT]);
	network(int*,int*,int*,int*);



};