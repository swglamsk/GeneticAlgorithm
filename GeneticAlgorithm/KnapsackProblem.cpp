#include "stdafx.h"
#include "KnapsackProblem.h"


KnapsackProblem::KnapsackProblem()
{
}

KnapsackProblem::KnapsackProblem(std::string wFile, std::string vFile, int weight, int number)	
{
	max_weight = weight;
	std::fstream fileW(wFile, std::ios_base::in);
	std::fstream fileV(vFile, std::ios_base::in);
	length = number;

	weights = new int[number-1];
	values = new int[number-1];

	for (int i = 0; i < number; i++)
	{
		fileW >> weights[i];
		fileV >> values[i];
		std::cout << i+1 << ". Waga: " << weights[i] << " Wartosc: " << values[i] << std::endl;
	}


}


KnapsackProblem::~KnapsackProblem()
{
	delete[] values;
	delete[] weights;
}

void KnapsackProblem::convertAnswer(Individual& individual)
{
	std::string genotype = individual.getGenotype();
	int length = genotype.length();
	std::cout << "Najlepszy wybor: " << std::endl;
	for (int i = 0; i < length; i++) {
		if (genotype[i] == '1') {
			std::cout << weights[i] << " " << values[i] << std::endl;
		}
	}
}

int KnapsackProblem::getLength()
{
	return length;
}

int KnapsackProblem::getMaxWeight()
{
	return max_weight;
}

int * KnapsackProblem::getWeights()
{
	return weights;
}

int * KnapsackProblem::getValues()
{
	return values;
}
