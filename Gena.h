#pragma once
#include "Librarii.h"
#define GENESIZE 8
class Gena
{
	int size;
public:
	static int default_size;
	std ::vector<bool> ADN;
	int decodificare(int poz);
	void initiere_random(int poz);
	void print(int poz);
	void initiere_random();
	void print();
	Gena(int Size);
	Gena();
	~Gena();
};

