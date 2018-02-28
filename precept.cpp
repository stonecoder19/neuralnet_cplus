#include "precept.h"
#include "stdio.h"
#include <stdlib.h>


ineuron::ineuron(float j)
{
	weight = j;
}


float ineuron::act(float x)
{
	float a;

	a = x*weight;

	return a;
}

void oneuron::activate(float *inputv, ineuron *nrn)
{
	int i;
	activation = 0;

	for(int i=0;i<NEURON_COUNT;i++)
	{
		cout <<"\nweight for neuron " <<i+1<<" is      " <<nrn[i].weight;
		nrn[i].activation = nrn[i].act(inputv[i]);
		cout<<"           activation is                "<<nrn[i].activation;
		activation+=nrn[i].activation;
	}

	cout <<"\nactivation is "<<activation<<"\n";

}

int oneuron::outvalue(float j)
{
	if(activation>=j)
	{
		cout <<"\noutput neuron activation exceeds the threshold value of" <<j<<"\n";
		output = 1;
	}else{
		cout <<"\nthe output neuron activation is smaller than the threshold value of"<<j<<endl;
		output = 0;
	}

	cout <<" output value is" << output << endl;
	return output;
}

network::network(float a, float b, float c, float d)
{
	nrn[0] = ineuron(a);
	nrn[1] = ineuron(b);
	nrn[2] = ineuron(c);
	nrn[3] = ineuron(d);

	onrn = oneuron();
	onrn.activation = 0;
	onrn.output = 0;
}

int main(int argc, char* argv[])
{
	float inputv[] = {1.95,0.27,0.69,1.25};
	float wtv1[] = {2,3,3,2}, wtv2[] = {3,0,6,2};
	FILE * wfile, * infile;
	int num=0, vecnum=0, i;
	float threshold = 7.0;

	if(argc < 2)
	{
		cerr << "Usage: percept Weightfile and InputFile";
		return -1;

	}

	wfile = fopen(argv[1], "r");
	infile = fopen(argv[2], "r");


	if((wfile == NULL) || (infile==NULL))
	{
		cout << "Can't open file" << endl;
		return -1;
	}

	cout <<"Enter number of weights \n" <<endl;
	cin >> vecnum;

	for(i=0;i<=vecnum; i++)
	{
		fscanf(wfile, "%f %f %f %f\n", &wtv1[0],&wtv1[1],&wtv1[2],&wtv1[3]);
		network h1(wtv1[0], wtv1[1], wtv1[2], wtv1[3]);
		fscanf(infile, "%f %f %f %f\n",&inputv[0],&inputv[1],&inputv[2],&inputv[3]);
		cout <<"this is vector # " << i << "\n";
		cout <<"please enter a threshold value, eg 7.0\n";
		cin >> threshold;
		h1.onrn.activate(inputv,h1.nrn);
		h1.onrn.outvalue(threshold);
		cout << "\n\n";
	}

	fclose(wfile);
	fclose(infile);

}