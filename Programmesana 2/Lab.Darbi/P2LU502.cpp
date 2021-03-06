/*
P2LU0502. Uzrakstīt C++ programmu, kas papildina skaitļu sarakstu sar2.
Izveidot metodi ieliktLiel(sk, sar2), kura ieliek skaitļu saraksta sar2 beigās
tos mezglus no dotā saraksta, kas satur skaitli, lielāku par sk.
Sarakstu realizēt kā dinamisku saistītu mezglu kopumu. Saraksta mezglu
un sarakstu realizēt kā klašu veidnes.

*/
#include <fstream>
#include <iostream>
#include <cstring>
using namespace std;
const int NAME_SIZE = 20;
const int FIRST_NAME_SIZE = 10;
const int GRADES_COUNT = 10;
const int G[GRADES_COUNT]= {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};

class Student
{
private:
char name[NAME_SIZE+1]; // beigâs '\0' simbols
char first_name[FIRST_NAME_SIZE+1]; // beigâs '\0' simbols
int semester;
int grades[GRADES_COUNT]; // atzîmes

public:
Student (const char *n = "", const char *v = "",
         const int sem = 0, const int *a = G );
void setName(const char *n);
void setFirstName(const char *v);
void setSemester(const int sem);
void setGrades(const int *a);
/** metode fillObject() aizpilda Student objekta laukus ar vçrtîbâm.
   Vçrtîbas ievada lietotâjs no tastatûras. **/
void fillObject();
/** metode write(fout) ieraksta Student objekta laukus failâ,
   kas piesaistîts faila objektam fout. **/
void write (ostream &fout);
/** metode read(fin) nolasa Student objekta laukus no faila,
    kas piesaistîts faila objektam fin,
    ieraksta nolasîto informâciju Student objektâ. **/
bool read (istream &fin);
/** metode print() izdrukâ Student objekta laukus **/
void print();
};
int main ()
{
ofstream fout1; // veidojamâ komponenðu faila mainîgais
ifstream fin1; // izveidotâ faila pârbaudei
Student s;

fout1.open("stud.bin", ios::binary | ios::app);
// Secîgas apstrâdes shçmas realizâcija failam cin
    s.fillObject(); // iegûst pirmâ studenta vçrtîbu no tastatûras
while (!cin.eof())
    {
    s.write(fout1); // apstrâdâ kârtçjo dabûto vçrtîbu(ziòas par studentu)
    s.fillObject();
    };

fout1.close ();

// Pârbauda izveidotâ faila atbilstîbu ievadîtajâm vçrtîbâm
fin1.open("stud.bin", ios::binary | ios::app);
while (s.read(fin1)) s.print(); // atkal secîgas apstrâdes shçmas realizâcija
fin1.close();
return 0;
};
Student::Student (const char *n, const char *v, const int sem, const int * a)
{
setName(n);
setFirstName(v);
setSemester(sem);
setGrades(a);
};
void Student::setName(const char *n){
 strncpy (name, n, NAME_SIZE);
 name[NAME_SIZE]='\0';
};
void Student::setFirstName(const char *v){
 strncpy (first_name, v, FIRST_NAME_SIZE);
 first_name[FIRST_NAME_SIZE]='\0';
};
void Student::setSemester(const int sem){
 semester = sem;
};
void Student::setGrades(const int *a){
 for (int i=0; i<GRADES_COUNT; i++)
 grades[i] = a[i];
};
/** metode fillObject() aizpilda Student objekta laukus ar vçrtîbâm.
   Vçrtîbas ievada lietotâjs no tastatûras. **/
void Student::fillObject()
{
char np[NAME_SIZE+1];
char fnp[FIRST_NAME_SIZE+1];
int sp;
int ap[10];
    cout << "Ievadiet studenta datus: "<< endl;
    cout << "uzvârds vârds semestris 10 atzîmes (CTRL+Z, lai pabeigtu ievadi)" << endl;
    cin >> np; setName(np);
    cin.ignore(1); // Lai varçtu pârtraukt ievadi pirms visu lauku ievades
    cin >> fnp; setFirstName(fnp);
    cin.ignore(1);
    cin >> sp; setSemester(sp);
    for (int i=0; i<GRADES_COUNT; i++) cin >> ap[i];
    setGrades(ap);
}
/** metode write(fout) ieraksta Student objekta laukus failâ,
   kas piesaistîts faila objektam fout. **/
void Student::write (ostream &fout)
{
fout.write ((char*)this, sizeof(Student)); // visa komponentes vçrtîba tiek ierakstîta
};
/** metode read(fin) nolasa Student objekta laukus no faila,
    kas piesaistîts faila objektam fin,
    ieraksta nolasîto informâciju Student objektâ. **/
bool Student::read (istream &fin)
{
fin.read ((char*)this, sizeof(Student)); // visa komponentes vçrtîba tiek nolasîta
return fin;
};
/** metode print() izdrukâ Student objekta laukus **/
void Student::print(){
cout << name << ' '<< first_name << ' ' << semester << ' ';
for (int i=0;i<GRADES_COUNT; i++) cout << grades[i] << ' ';
cout << endl;
};
