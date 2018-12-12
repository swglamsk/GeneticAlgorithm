#include "stdafx.h"
#include "Individual.h"


Individual::Individual()
{
}

Individual::Individual(std::string Gen)
{
	genotype = Gen;

}



int Individual::calFitness(int maxWeight, int weights[], int values[])
{
	int weight = 0;
	int value = 0;

	for(int i = 0; i < genotype.length(); i++)
	{
		if (genotype[i] == '1')
		{
			weight += weights[i];
			value += values[i];
		}

	}
	if (weight > maxWeight)
		return 0;
	else
		return value;
}

int Individual::mutate()
{
	return 0;
}



Individual::~Individual()
{
}

std::pair<Individual, Individual> Individual::cross(Individual  parent2)
{
	int length = genotype.length();
	std::string parent1Genotype = genotype;
	std::string parent2Genotype = parent2.genotype;
	std::string child1Genotype = "";
	std::string child2Genotype = "";

	int cutPosition = (rand() % (length - 1) + 1);

	int i = 0;
	for (; i < cutPosition; i++)
	{
		child1Genotype[i] = parent1Genotype[i];
		child2Genotype[i] = parent2Genotype[i];
	}
	for (; i < length; i++)
	{
		child1Genotype[i] = parent2Genotype[i];
		child2Genotype[i] = parent1Genotype[i];
	}

	Individual child1(child1Genotype);
	Individual child2(child2Genotype);

	std::pair<Individual, Individual> Children = std::make_pair(child1, child2);

	return Children;


}