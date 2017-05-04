/**
===============================================================================================================
Izveidot programmu valodā C++.  Ja programma darbojas ar failu, nedrīkst dublēt visa faila saturu operatīvajā atmiņā.
Ar faila komponenti tiek saprasts fiksēta garuma ieraksts. Sīkākās prasības sk. Laboratorijas darbu noteikumos.
H3. Uzrakstīt programmu, kas ļauj izveidot un papildināt bināru failu, kura ieraksta struktūra ir sekojoša: vārds
– atslēga (nepārsniedz 30 simbolus), vārds – vērtība  (nepārsniedz 30 simbolus), iepriekšējās atslēgas numurs (int),
nākošās atslēgas numurs (int). Programmai katrs jauns ieraksts jāieliek faila beigās, modelējot divpusēji saistītu
sarakstu, kura ieraksti sakārtoti alfabētiski pēc atslēgas – t.i., katram  ierakstam iepriekšējās atslēgas numurs
norāda uz ierakstu (ieraksta numurs pēc kārtas), kuram ir atslēga  mazāka, nākošās atslēgas numurs – uz ierakstu,
kuram atslēga ir lielāka. Paredzēt iespēju izdrukāt faila saturu alfabētiskā un apgrieztā secībā.
===============================================================================================================
**/
#include <iostream>
#include <cstdio>
#include <cstring>

struct Data{
  char a;
};

int main(){
    Data a;
    FILE * pFile;
    int i=0;
    pFile = fopen ( "data.bin" , "rb" );
    fseek ( pFile , i*sizeof(Data) , SEEK_SET );
    fread (a,1,sizeof(Data),pFile);
    fclose ( pFile );
    return 0;
}
