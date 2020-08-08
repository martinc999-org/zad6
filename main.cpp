#include <iostream>
#include <time.h>

using namespace std;

void print_binary(int number) {

    unsigned int mask_tmp = 0x80000000;
    bool start = false;

    int count = 0;
    for(unsigned int mask = 0x80000000; mask >= 1; mask = mask >> 1) //Tworzę maskę w postaci 1000 ... 0000, którą co każdą iterację przesuwam o 1 miejsce w prawo, żeby przejrzeć wszystkie bity w liczbie
    {
        if(mask & number) start = true; //W momencie, gdy maska spotka pierwszą jedynkę zmeinną bool ustawiam na true w ten sposób mogę pominąć wiodące zera
        if((mask & number) && start == true) {cout << 1; count++;}//Sprawdzam warunek koniunkcji maski i liczby, ktorą chce zapisac w formie binarnej równocześnie sprawdzając czy zmienna bool ustawiona jest na wartosc true, jeżeli tak zapisuje pierwszą jedynkę bez wiodących zer
        if(!(mask & number) && start == true) {cout << 0; count++;} //
    }
    //printf("\nbinary: %d\n",count);
    cout << "\n";
}

void print_binary(int tab[], int size) {

    for(int i = size-1; i >= 0; i--)
    {
        cout<<tab[i]<<" ";
    }
    cout<<"\n";

}


void wczytaj_tablice(const int size, int tab[]) {

    int tmp[] = {0,1,2,3,4,5,6,7,8,14};
    for(int i = 0; i < size; i++)
    {
        //cin>>tab[i];
        tab[i] = tmp[i];
    }
}



// Function to extract k bits from p position
// and returns the extracted value as integer
//int number = 171, k = 5, p = 2;
//print_binary(171);
//printf("The extracted number is %d\n", bitExtracted(number, k, p));
//print_binary(21);

int bitExtracted(int number, int k, int p)
{
    return (((1 << k) - 1) & (number >> (p - 1)));
}

// Driver code


void zamianaElementow(int *tab, const int size)
{
    //wydaje mi się, że program powinien być dobry, jednak nie wiem dlaczego po wywołaniu funkcji pomijana jest pętla, która odpowiada za zamiane miejsc
    //i zaczyna się od indexu 0, a j od indexu 9, i rośnie, a j maleje

    for(int i = 0, j = size - 1; i < size / 2 ; i++, j--)
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
    int max_value = -1;
    int max_index;

    for(int i = 0; i < size; i++) {
        int counter = 0;
        for (unsigned int mask = 0x80000000; mask > 0; mask = mask >> 1) {
            if (mask&tab[i])
                counter++;
        }
        if(counter>max_value) {
            max_value = counter;
            max_index = i;
        }
    }
    return tab[max_index];
}

int liczbaWystapien(int a,int wzorzec)
{
    /*
     * Tworze maske i bez wiodących zer wpisuje sekwencje bitową do zmiennej typu string dla int a oraz int wzorzec
     * Nastepnie zakladajac, ze liczba A jest wzorcem porównuje ją z liczbą wzorzec
     * Chociaż nie koniecznie musi tak być, bo liczba B może mieć np. 101, a liczba A 10101 i wtedy to liczba B jest wzorcem
     * Nie wiem do końca czy to jest dobre podejście do tego problemu, ale nic lepszego nie prztchodzi mi do głowy :(
     */
    clock_t begin = clock();
    int a_bin[32], wzorzec_bin[32];
    bool start = false;
    unsigned int mask = 1;
    int i = 0;
    for(mask; mask > 0; mask = mask << 1)
    {
        if(mask & a)
            a_bin[i] = 1;
        else
            a_bin[i] = 0;

        if(mask & wzorzec)
            wzorzec_bin[i] = 1;
        else
            wzorzec_bin[i] = 0;
        i++;
    }
    int j = 32;
    for (j=31; wzorzec_bin[j]==0 && j>=0; j--);
    int wzorzec_length = j + 1;

    print_binary(a_bin, 32);
    print_binary(wzorzec_bin, 32);

    int count = 0;
    for (int k=0; k < 32 - wzorzec_length + 1; k++) {
        int l = 0;
        for (l=0; l < wzorzec_length; l++) {
            if (a_bin[k+l] != wzorzec_bin[l])
                break;
        }

        if (l == wzorzec_length)
            count++;

    }
    clock_t end = clock();
    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;

    cout<< "liczbaWystapien: " << count <<"\n";
    printf("time: %.6f\n",time_spent);
}

int liczbaWystapien2(int a,int wzorzec) {

    clock_t begin = clock();
    /* here, do your time-consuming job */

    int wzorzec_length = 32;
    cout << "wzorzec: ";
    print_binary(wzorzec);
    unsigned int mask1 = 0x80000000;
    while ((mask1 >= 1) && !(mask1 & wzorzec))
    {
        wzorzec_length--;
        mask1 = mask1 >> 1;
    }

    int count2 = 0;
    int mask = 0;
    for (int t = 32 - wzorzec_length; t >= 0; t--) {
        if (wzorzec_length==32)
            mask = wzorzec;
        else
            mask = (((1 << wzorzec_length) - 1) & (a)); //bitExtracted(a, wzorzec_length, 1);
        //print_binary(tmp);
        if (mask == wzorzec) {
            count2++;
        }

        a = a >> 1;
    }
    clock_t end = clock();
    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;

    cout << "liczbaWystapien2: " << count2 << "\n";
    printf("time: %.6f\n",time_spent);
}


int main() {

    int choice=1;
    cin>>choice;

    switch(choice)
    {
        case 1:
        {
            const int size = 10;
            int tab[size];
            wczytaj_tablice(size, tab);
            zamianaElementow(tab,size);
            break;
        }
        case 2:
        {
            const int size = 10;
            int tab[size];
            wczytaj_tablice(size, tab);
            int wynik = liczbaJedynek(tab,size);
            cout<<wynik;
            break;
        }
        case 3:
        {
            int a,b;
            //cin>>a>>b;
            liczbaWystapien(0xA8E8D2AC,5);
            liczbaWystapien2(0xA8E8D2AC,5);

            break;
        }
    }


    return 0;
}

