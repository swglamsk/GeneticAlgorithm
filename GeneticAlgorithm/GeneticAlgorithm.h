#pragma once
#include "KnapsackProblem.h"
#include "Individual.h"
class GeneticAlgorithm
{
public:
	GeneticAlgorithm();
	GeneticAlgorithm(int PopSize, double CrossProb, double MutProb);
	void run(int iteration);
	~GeneticAlgorithm();
private:
	int PopSize;
	double CrossProb;
	double MutProb;
};

