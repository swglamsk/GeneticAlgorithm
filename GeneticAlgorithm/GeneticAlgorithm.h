#pragma once
class GeneticAlgorithm
{
public:
	GeneticAlgorithm();
	~GeneticAlgorithm();
private:
	int PopSize;
	int iteration;
	double CrossProb;
	double MutProb;
};

