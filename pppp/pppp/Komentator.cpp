#include "Komentator.h"

void Komentator::powiadomOSmierci(Organizm* zabijajacy, Organizm* umierajacy)
{
	if(umierajacy->getCzyZwierze())
		cout << zabijajacy->organizmToString() << " zabil " << umierajacy->organizmToString() << endl;
	else
		cout << zabijajacy->organizmToString() << " zjadl " << umierajacy->organizmToString() << endl;
}

void Komentator::powiadomOUniku(Organizm* atakujacy, Organizm* unikajacy)
{
	cout <<unikajacy->organizmToString()<<" uniknal ataku "<< atakujacy->organizmToString() << endl;
}

void Komentator::powiadomOBloku(Organizm* atakujacy, Organizm* blokujacy)
{
	cout << blokujacy->organizmToString() << " zablokowal atak " << atakujacy->organizmToString() << endl;
}

void Komentator::powiadomOZatruciu(Organizm* roslina, Organizm* zwierze)
{
	cout << zwierze->organizmToString() << " zatrul sie " << roslina->organizmToString() << endl;
}
