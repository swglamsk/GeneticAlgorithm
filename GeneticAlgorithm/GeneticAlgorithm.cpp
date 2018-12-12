#include "stdafx.h"
#include "GeneticAlgorithm.h"


GeneticAlgorithm::GeneticAlgorithm()
{
}

GeneticAlgorithm::GeneticAlgorithm(int PopSize, double CrossProb, double MutProb)
{
	this->PopSize = PopSize;
	this->CrossProb = CrossProb;
	this->MutProb = MutProb;
}

void GeneticAlgorithm::run(int iteration)
{
}


GeneticAlgorithm::~GeneticAlgorithm()
{
}
