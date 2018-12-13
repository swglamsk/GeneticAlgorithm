#pragma once
#include <string>
#include <fstream>
#include <iostream>
#include "Individual.h"


class KnapsackProblem
{
public:
	KnapsackProblem();
	KnapsackProblem(std::string wFile, std::string vFile, int weight, int number);
	void convertAnswer(Individual &individual);
	int getLength();
	int getMaxWeight();
	int* getWeights();
	int* getValues();
	~KnapsackProblem();
private:
	int max_weight;
	int* weights;
	int* values;
	int length;


};

