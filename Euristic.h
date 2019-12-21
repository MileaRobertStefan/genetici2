#pragma once
#include "Individ.h"
class Euristic
{
public:
	Individ cobai;
	void (*functie_cu_valoare)(Graf, int);
	int main()
	{
		print_block
		int count = 0;
		do
		{
			printf("%d\n", ++count);
			
			cobai.elimina_culori_adiacente();


		} while (cobai.exista_culori_adiacente());
		cobai.trasaturi.print();

		return 0;
	}
	Euristic(Individ a) : cobai(a) {};


};

