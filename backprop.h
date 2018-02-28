#include <cstdio>
#define MAX_LAYERS 5
#define MAX_VECTORS 100
#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <time.h>


class network;
class layer
{

protected:
	int num_inputs;
	int num_outputs;
	float* outputs;
	float* inputs;

public:

	virtual void calc_out();
};

class input_layer : public layer
{
public:

	input_layer(int, int);
	~input_layer();
	virtual void calc_out();



};

class middlelayer;

class outputlayer : public layer
{

protected:
	float * weights;
	float * output_errors;
	float * back_errors;
	float * expected_values;

	friend network;

public:

	output_layer(int,int);
	~output_layer();
	virtual void calc_out();
	void calc_error(float &);
	void randomize_weights();
	void update_weights(const float);
	void list_weights();
	void write_weights(int, FILE*);
	void read_weights(int, FILE*);
	void list_errors();
	void list_outputs();
};

class middle_layer : public output_layer
{

	public:
		middle_layer(int,int);
		~middle_layer();
		void calc_error();

};


class network
{

private:
	layer *layer_ptr[MAX_LAYERS];
	int number_of_layers;
	int layer_size;
	float * buffer;
	fpos_t position;
	unsigned training;

public:
	network();
	~network();
	void set_training(const unsigned &);
	unsigned get_training_value();
	void get_layer_info();
	void set_up_network();
	void randomize_weights();
	void update_weights(const float);
	void write_weights(FILE *);
	void read_weights(FILE *);
	void list_weights();
	void write_outputs(FILE * file);
	void list_outputs();
	void list_errors();
	void forward_prop();
	void backward_prop(float &);
	int fill_IObuffer(FILE *);
	void set_up_pattern();

};


