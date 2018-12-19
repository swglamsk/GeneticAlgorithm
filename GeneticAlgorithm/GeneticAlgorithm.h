#pragma once
#include "KnapsackProblem.h"
#include "Individual.h"
class GeneticAlgorithm
{
public:
	GeneticAlgorithm();
	GeneticAlgorithm(int PopSize, double CrossProb, double MutProb);
	std::string run(int iteration);
	~GeneticAlgorithm();
private:
	int PopSize;
	double CrossProb;
	double MutProb;
	Individual* population;
	KnapsackProblem* knapsack = new KnapsackProblem("weight_data.txt", "value_data.txt", 15, 7);
};

