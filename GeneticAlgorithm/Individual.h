#pragma once
#include <string>
#include <utility>
#include "GeneticAlgorithm.h"
#include <random>
class Individual
{
public:
	Individual();
	Individual(std::string Gen);
	int calFitness(int, int weights[], int values[]);
	int mutate();
	std::string GetGenotype();
	~Individual();
	std::pair<Individual, Individual> cross(Individual parent2);
private:
	std::string genotype;
};
