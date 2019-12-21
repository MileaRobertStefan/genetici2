#pragma once
#include "Librarii.h"
class Graf
{
public:
	std::vector<std::vector<int>> graf;
	//graf[i][0] -- ce nod reprezinta
	//graf[0][i] -- gradul noului i
	int varfuri, muchii;

	void Print();
	void Sortate_dupa_grad_Si_eliminare_noduri_izolate();
	


	Graf(std::string numefis);
	
};

