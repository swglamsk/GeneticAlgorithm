#pragma once
#include <string>
#include <utility>
#include <random>
class Individual
{
public:
	Individual();
	Individual(std::string Gen);
	Individual(int ran);
	int calFitness(int, int weights[], int values[]);
	std::string mutate(double mutProb);
	~Individual();
	std::string getGenotype();
	std::pair<Individual, Individual> cross(Individual& parent2);
private:
	std::string genotype;
};

