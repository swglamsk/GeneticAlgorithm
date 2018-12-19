#include "stdafx.h"
#include "GeneticAlgorithm.h"
#include <utility>

GeneticAlgorithm::GeneticAlgorithm()
{
}

GeneticAlgorithm::GeneticAlgorithm(int PopSize, double CrossProb, double MutProb)
{
	this->PopSize = PopSize;
	this->CrossProb = CrossProb;
	this->MutProb = MutProb;
	population = new Individual[PopSize];
}

std::string GeneticAlgorithm::run(int iteration)
{
	
	std::string bestResult = "";
	int bestFitness = 0;
	//pierwsza populacja zrobiona z losowych liczb
	for (int i = 0; i < PopSize; i++)
	{
		population[i] = Individual(knapsack->getLength());
	}

	//g³owna petla
	for (int i = 0; i < iteration; i++)
	{
		for (int j = 0; j < PopSize; j++)
		{
			int tmpFitness = population[j].calFitness(knapsack->getMaxWeight(), knapsack->getWeights(), knapsack->getValues());
			if (tmpFitness > bestFitness)
			{
				bestFitness = tmpFitness;
				bestResult = population[j].getGenotype();
			}
		}
		//crossing
		for (int j = 0; j < PopSize; j+=2)
		{
			int firstA = 0;
			int firstB = 0;
			int secondA = 0;
			int secondB = 0;
			int indexA;
			int indexB;
			while (firstA == secondA)
			{
				firstA = rand() % PopSize;
				secondA = rand() % PopSize;
			}
			while (firstB == secondB)
			{
				firstB = rand() % PopSize;
				secondB = rand() % PopSize;
			}
			int firstFitnessA = population[firstA].calFitness(knapsack->getMaxWeight(), knapsack->getWeights(), knapsack->getValues());
			int firstFitnessB = population[firstB].calFitness(knapsack->getMaxWeight(), knapsack->getWeights(), knapsack->getValues());
			int secondFitnessA = population[secondA].calFitness(knapsack->getMaxWeight(), knapsack->getWeights(), knapsack->getValues());
			int secondFitnessb = population[secondB].calFitness(knapsack->getMaxWeight(), knapsack->getWeights(), knapsack->getValues());

			if (firstFitnessA > secondFitnessA) indexA = firstA;
			else indexA = secondA;

			if (firstFitnessB > secondFitnessb) indexB = firstB;
			else indexB = secondB;
			Individual* childA = &(population[indexA]);
			Individual* childB = &(population[indexB]);

		double r = (rand() % 100) /100;
			if (r < CrossProb) 
			{
				childA->cross(*childB);
			}

			
		}

		//mutacja
		for (int j = 0; j < PopSize; j++)
		{
			population[j].mutate(MutProb);
		}
		
	}
	std::cout << bestFitness << std::endl;
	return bestResult;
}


GeneticAlgorithm::~GeneticAlgorithm()
{
	delete population;
}
