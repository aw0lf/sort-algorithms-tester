#include <iostream>
#include <cstdlib>
#include <time.h>
#include<fstream>

using namespace std;
int* Sort(int [],int); //funkcje sortujace, potrzebne by uzyskac dane rodzaje zbiorów
int* ReverseSort ( int [], int);
void generateData();
void loadData();
void stoper(char *);

int main(){
    generateData();
    loadData();
return 0;
}
void stoper(){
    clock_t t;
    for(int i=0;i<5;i++){
    t = clock();
//algorytm
    t = clock() - t;
    double time_taken = ((double)t)/CLOCKS_PER_SEC; // in seconds
    cout<<"Pomiar "<<i<<" czas: "<<time_taken<<endl;
    }

    }
void loadData(){
char *file_name=new char[7];
int tab_size;
file_name[2]='.';
file_name[3]='t';
file_name[4]='x';
file_name[5]='t';
int tab_sizes[]={10,20,30,50,75,100,200,300,400,500};
for(int j=0;j<10;j++){
    int temp[]={'0','1','2','3','4','5','6','7','8','9'};
    file_name[1]=temp[j];
    tab_size=tab_sizes[j];
    int *tab=new int[tab_size];
    fstream file; //otwieram plik
    //pesymistyczne
    cout<<"Losowy zbior: "<<tab_size<<" elementowy"<<endl;
    file_name[0]='r';
    file.open(file_name);
    while(file.good()){
        for(int i=0;i<tab_size;i++)
            file>>tab[i]; //wczytuje dane do tab
    }
    file.close();
    stoper();

    //optymistyczne
    cout<<"Optymistyczny zbior: "<<tab_size<<" elementowy"<<endl;
        file_name[0]='o';
    file.open(file_name);
    while(file.good()){
        for(int i=0;i<tab_size;i++)
            file>>tab[i]; //wczytuje dane do tab
    }
    file.close();
    stoper();
    //pesymistyczne
    cout<<"Pesymistyczne zbior: "<<tab_size<<" elementowy"<<endl;
        file_name[0]='p';
    file.open(file_name);
    while(file.good()){
        for(int i=0;i<tab_size;i++)
            file>>tab[i]; //wczytuje dane do tab
    }
    file.close();
    stoper();

    delete[] tab;
    }
    delete[] file_name;
}

void generateData()
{
    srand(time(NULL));

    char *file_name=new char[7];
    int tab_size;
    file_name[2]='.';
    file_name[3]='t';
    file_name[4]='x';
    file_name[5]='t';

    for(int j=0;j<10;j++){
    cout<<"Podaj wielkosc "<<endl;
    cin>>tab_size;
    int *tab = new int[tab_size]; //generowanie tablicy dynamicznej i wypelnianie jej liczbami losowymi
        for(int i=0; i<tab_size; i++){
            tab[i] = (rand() % tab_size)+7;
        }

    int temp[]={'0','1','2','3','4','5','6','7','8','9'};
    file_name[1]=temp[j];
    ofstream file;
    //losowe, wypenianie petla tablicy charow
        file_name[0]='r';
    file.open(file_name);
            for(int i=0; i<tab_size; i++){
        file<<tab[i]<<endl;
            }
    file.close();

    //
        //zapis zbioru optymistycznego
    Sort(tab,tab_size/2);
    file_name[0]='o';
    file.open(file_name);
    for(int i=0;i<tab_size;i++){
        file<<tab[i]<<endl;
    }
    file.close();

        //zapis zbioru pesymistycznego
    ReverseSort(tab,tab_size);
    file_name[0]='p';
    file.open(file_name);
    for(int i=0;i<tab_size;i++){
        file<<tab[i]<<endl;
    }
    file.close();
    delete[] tab;
    }


    delete[] file_name;

}
int* Sort( int tab[], int size ) //sortuje liczby, potrzebna by stworzyc optymistyczny- czesciowo uporzadkowany zbior
{
    int temp, j;
    for( int i = 1; i < size; i++ )
    {
        temp = tab[ i ];
        for( j = i - 1; j >= 0 && tab[ j ] > temp; j-- )
             tab[ j + 1 ] = tab[ j ];
        tab[ j + 1 ] = temp;
    }
    return tab;
}

int* ReverseSort ( int tab[], int size ) //generuje zbior pesymistyczny, liczby posortowane odwrotnie
{
    int temp, j;
    for( int i = 1; i < size; i++ )
    {
        temp = tab[ i ];
        for( j = i - 1; j >= 0 && tab[ j ] < temp; j-- )
             tab[ j + 1 ] = tab[ j ];
        tab[ j + 1 ] = temp;
    }
    return tab;
}
