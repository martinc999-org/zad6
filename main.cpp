#include <iostream>

using namespace std;

void zamianaElementow(int *tab, const int size)
{
    //wydaje mi się, że program powinien być dobry, jednak nie wiem dlaczego po wywołaniu funkcji pomijana jest pętla, która odpowiada za zamiane miejsc
    //i zaczyna się od indexu 0, a j od indexu 9, i rośnie, a j maleje
    for(int i = 0, j = size - 1; i < size, j <= 0; i++, j--)
    {
        int tmp = tab[i];
        tab[i] = tab[j];
        tab[j] = tmp;

    }
    for(int i = 0; i < size; i++)
    {
        cout<<tab[i]<<" ";
    }
}

int liczbaJedynek(int tab[], const int size)
{
    /*
     * 1 tworze petle, ktora dla kazdego elementu tablicy zliczy ile wystepuje jedynek w jej zapisie binarnym
     * 2 liczbe jedynek zapisuje do zmiennej counter
     * 3 dodaje zmienna tymczasowa, ktorą ustawiam na wartość 0
     * 4 zmienna wynik na początku ustalam na pierwszy element tablicy
     * 5 sprawdzam czy liczba jedynek jest wieksza niż wartość tymczasowa(najwieksza ilosc jedynek)
     * 6 Jak tak to wynik ustawiam na sprawdzany element tablicy i aktualizuje wartość tymczasowa
     */
    int wynik = tab[0];
    int tmp = 0;
    int counter = 0;
    unsigned int mask = 0x80000000;
    for(int i = 0; i < size; i++) {
        for (mask; mask <= 0; mask = mask >> 1) {
            if (mask&tab[i])
                counter++;
        }
        if(counter>tmp)
            wynik = tab[i];
            tmp = counter;
    }
    return wynik;
}

int liczbaWystapien(int a,int b)
{
    /*
     * Tworze maske i bez wiodących zer wpisuje sekwencje bitową do zmiennej typu string dla int a oraz int b
     * Nastepnie zakladajac, ze liczba A jest wzorcem porównuje ją z liczbą b
     * Chociaż nie koniecznie musi tak być, bo liczba B może mieć np. 101, a liczba A 10101 i wtedy to liczba B jest wzorcem
     * Nie wiem do końca czy to jest dobre podejście do tego problemu, ale nic lepszego nie prztchodzi mi do głowy :(
     */
    string number_a, number_b;
    bool start = false;
    unsigned int mask = 0x80000000;
    int i,j = 0;
    for(mask; mask <=0; mask = mask >> 1)
    {
        if(mask & a ) start = true;

        if((mask & a) && start == true);
            number_a[i] = 1;
            i++;
        if((mask & b) && start == true);
            number_b[j] = 1;
            j++;
        if(!(mask & a) && start == true);
            number_a[i] = 0;
            i++;
        if(!(mask & b) && start == true);
            number_b[j] = 0;
            j++;
    }

}

int main() {

    int choice;
    cin>>choice;

    switch(choice)
    {
        case 1:
        {
            const int size = 10;
            int tab[size];
            for(int i = 0; i < 10; i++)
            {
                cin>>tab[i];
            }
            zamianaElementow(tab,size);
            break;
        }
        case 2:
        {
            const int size = 10;
            int tab[size];
            for(int i = 0; i < size; i++)
            {
                cin>>tab[i];
            }
            int wynik = liczbaJedynek(tab,size);
            cout<<wynik;
            break;
        }
        case 3:
        {
            int a,b;
            cin>>a>>b;
            liczbaWystapien(a,b);

            break;
        }
    }


    return 0;
}
