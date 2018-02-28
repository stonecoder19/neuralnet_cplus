#include "hop.h"	




neuron::neuron(int *j)
{
	int i;
	for (i=0;i<NEURON_COUNT;i++)
	{
		weightv[i] = *(j+i); //store weights
	}

}

int neuron::act(int count, int *pattern)
{

	int result=0;
	int i;

	for(i=0;i<count;i++)
	{
		
		result+=pattern[i] * weightv[i]; //product of weights to corresponding pattern value
	}



	return result;
}


int network::threshold(int output)
{
	output = output>0? 1:0; //keeps value at 1 or 0
}

network::network(int n1[NEURON_COUNT],int n2[NEURON_COUNT],int n3[NEURON_COUNT], int n4[NEURON_COUNT])
{

	nrn[0] = neuron(n1);
	nrn[1] = neuron(n2);
	nrn[2] = neuron(n3);
	nrn[3] = neuron(n4);
}

void network::activate(int *pattern)
{
	int i,j;

	for(i=0;i<NEURON_COUNT;i++)
	{
		for(j=0;j<NEURON_COUNT;j++)
		{

			cout << "Neruon " << i << " weight " << j << " is " << nrn[i].weightv[j] << endl;
 
		}
		nrn[i].activation = nrn[i].act(NEURON_COUNT,pattern);
		cout << "Activation is " << nrn[i].activation << endl;
		output[i] = threshold(nrn[i].activation);
		cout << "Output: " << output[i] << endl;
		cout<<endl<<endl;
	}

}

int main(int argc, char** argv)
{

	int pattern1[] = {0,1,0,0}, i;
	int wt1[] = {0,-3,3,-3};
	int wt2[] = {-3,0,-3,3};
	int wt3[] = {3,-3,0,-3};
	int wt4[] = {-3,3,-3,0};


	network n1(wt1,wt2,wt3,wt4);

	n1.activate(pattern1);



	for(i=0;i<NEURON_COUNT;i++)
	{
		cout << "Pattern[" << i << "]" << "is " << pattern1[i] << " Ouput[" <<i << "]" << "is " << n1.output[i];
		if(pattern1[i] == n1.output[i])
		{
			cout << "Matched" << endl;
		}else{
			cout << "Discrepancy occured" << endl;
		}
	}

	cout <<endl<<endl;


	int pattern2[] = {0,1,0,1};
	n1.activate(pattern2);

	for(i=0;i<NEURON_COUNT;i++)
	{
		cout << "Pattern[" << i << "]" << "is " << pattern2[i] << " Ouput[" <<i << "]" << "is " << n1.output[i];
		if(pattern2[i] == n1.output[i])
		{
			cout << " Matched" << endl;
		}else{
			cout << " Discrepancy occured" << endl;
		}
	}



}



