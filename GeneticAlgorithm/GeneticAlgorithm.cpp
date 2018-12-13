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
	knapsack = new KnapsackProblem("weight_data.txt", "value_data.txt", 104, 8);
	std::string bestResult = "";
	int bestFitness = 0;
	//pierwsza populacja zrobiona z losowych liczb
	for (int i = 0; i < PopSize; i++)
	{
		population[i] = Individual(knapsack->getLength());
	}

	//g³owna petla wykonujaca sie iles razy
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
		Individual* nextPopulation = new Individual[PopSize];
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
			Individual parent1 = population[indexA];
			Individual parent2 = population[indexB];

			double r = ((double)rand() / (RAND_MAX)) + 1;
			if (r < CrossProb) 
			{
				std::pair<Individual, Individual> newpair = parent1.cross(parent2);
				nextPopulation[j] = newpair.first;
				nextPopulation[j + 1] = newpair.second;

			}

			else
			{
				nextPopulation[j] = parent1;
				nextPopulation[j + 1] = parent2;
			}
			
		}
		population = nextPopulation;
		//mutacja
		for (int j = 0; j < PopSize; j++)
		{
			population[j].mutate(MutProb);
		}
		
	}
	return bestResult;
}


GeneticAlgorithm::~GeneticAlgorithm()
{
	delete population;
}
