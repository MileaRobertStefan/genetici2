#include "Individ.h"
bool Individ::exista_culori_adiacente()
{
	std::vector<std::vector<int>>& lista_muchii = graf->graf;

	for (int i = 1; i < lista_muchii.size(); ++i)
	{
		const int culoare_nod = id_culori[i];
		for (auto vecin : lista_muchii[i])
		{
			if (id_culori[vecin] == culoare_nod)
				return true;
		}
	}
	return false;
}

bool Individ::exista_culori_adiacente(int i)
{
	std::vector<std::vector<int>>& lista_muchii = graf->graf;

	const int culoare_nod = id_culori[i];
	for (auto vecin : lista_muchii[i])
	{
		if (id_culori[vecin] == culoare_nod)
			return true;
	}

	return false;
}
void Individ::elimina_culori_adiacente()
{
	std::vector<std::vector<int>>& lista_muchii = graf->graf;

	for (int i = 1; i < lista_muchii.size(); ++i)
	{
		const int culoare_nod = id_culori[i];
		for (auto vecin : lista_muchii[i])
		{
			if (id_culori[vecin] == culoare_nod)
			{
				do {
					trasaturi.initiere_random(i);
					id_culori[i] = trasaturi.decodificare(i);
				} while (exista_culori_adiacente(i));
			}
		}
	}
}
int Individ::cate_culori_am()
{
	int vec[256] = { 0 };
	for (auto j : id_culori)
		vec[j]++;
	int sum = 0;
	for (int i = 0; i < 256; ++i)
		sum += vec[i] != 0;
	return sum;
}
void Individ::update_id_culori()
{
	for (int i = 1; i < graf->graf.size(); ++i)
		id_culori[i] = trasaturi.decodificare(i);
}
// FOLOSESTE ASTA std::vector<std::vector<int>>& lista_muchii = graf->graf;
void Individ::print_culori()
{
	print_block
		printf("\t Printez culorile.\n");
	for (int i = 1; i < id_culori.size(); ++i)
		printf("\n %d : %d", i, id_culori[i]);

}

Individ::Individ(Graf* GRAF) : graf(GRAF) {
	std::vector<std::vector<int>>& lista_muchii = graf->graf;

	Gena::default_size = lista_muchii.size();
	Gena noua;
	trasaturi = noua;
	trasaturi.initiere_random();
	id_culori.resize(Gena::default_size);
	for (int i = 1; i < lista_muchii.size(); ++i)
		id_culori[i] = trasaturi.decodificare(i);
}

