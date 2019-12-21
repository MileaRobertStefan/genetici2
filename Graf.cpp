#include "Graf.h"

void Graf::Print()
{
	print_block
		for (int i = 1; i < graf.size(); ++i)
		{
			std::cout << i << " -> ";
			for (int j = 0; j < graf[i].size(); ++j)
			{
				std::cout << graf[i][j] << " ";
			}
			std::cout << std::endl;
		}
}

void Graf::Sortate_dupa_grad_Si_eliminare_noduri_izolate()
{
	print_block
		printf("\n\tIncepe sortarea...");
	bool sw = 0;
	std::vector<std::vector<int>>& lista_muchii = graf;
	do {
		sw = 0;
		for (int i = 1; i < varfuri - 1; ++i)
			if (lista_muchii[i].size() < lista_muchii[i + 1].size())
			{
				std::swap(lista_muchii[i], lista_muchii[i + 1]); sw = 1;
				std::swap(lista_muchii[0][i], lista_muchii[0][i + 1]);
			}

	} while (sw);
	printf(" Sortare finalizata.\n\tElimin nodurile izolate...");
	int j = lista_muchii.size() - 1;
	while (lista_muchii[j].size() == 1)
	{
		lista_muchii.pop_back();
		j--;
	}

	printf("Noduile izolate au fost eliminate.\n");
	printf("\n\tRedenumire noduri...");

	std::vector<int>masca; masca.resize(varfuri);
	for (int i = 1; i < graf.size(); ++i)
		masca[graf[i][0]] = i;


	for (int i = 1; i < graf.size(); ++i)
	{
		for (auto& j : graf[i])
		{
			j = masca[j];
		}
	}

	for (int i = 1; i < graf.size(); ++i)
		graf[i].erase(graf[i].begin());
	

	printf("Redenumire cu succes.\n");
};

Graf::Graf(std::string numefis)
{
	print_block
		printf("\n\tCitire graf...");
	std::ifstream fisier(numefis);
	std::string cuvant;
	int st = 0, dr = 0;
	do
	{
		fisier >> cuvant;
	} while (cuvant != "p");

	fisier >> cuvant; fisier >> varfuri >> muchii;
	varfuri++;
	graf.resize(varfuri);
	for (int i = 1; i < varfuri; ++i)
		graf[i].push_back(i);
	while (fisier >> cuvant)
	{
		fisier >> st >> dr;
		graf[st].push_back(dr);
		graf[dr].push_back(st);
	}
	int grad_nod = 0;
	//graf[0][x] contine Gradul nodului x
	graf[0].resize(varfuri);
	for (int i = 1; i < varfuri; ++i)
	{
		graf[0][i] = graf[i].size() - 1;
	}
	printf("Graf citit cu succes!\n");
	fisier.close();
}
