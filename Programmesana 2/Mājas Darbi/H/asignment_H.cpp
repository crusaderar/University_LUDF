/**
APRAKSTS>======================================================================================================
Izveidot programmu valodā C++.  Ja programma darbojas ar failu, nedrīkst dublēt visa faila saturu operatīvajā atmiņā.
Ar faila komponenti tiek saprasts fiksēta garuma ieraksts. Sīkākās prasības sk. Laboratorijas darbu noteikumos.
H3. Uzrakstīt programmu, kas ļauj izveidot un papildināt bināru failu, kura ieraksta struktūra ir sekojoša: vārds
– atslēga (nepārsniedz 30 simbolus), vārds – vērtība  (nepārsniedz 30 simbolus), iepriekšējās atslēgas numurs (int),
nākošās atslēgas numurs (int). Programmai katrs jauns ieraksts jāieliek faila beigās, modelējot divpusēji saistītu
sarakstu, kura ieraksti sakārtoti alfabētiski pēc atslēgas – t.i., katram  ierakstam iepriekšējās atslēgas numurs
norāda uz ierakstu (ieraksta numurs pēc kārtas), kuram ir atslēga  mazāka, nākošās atslēgas numurs – uz ierakstu,
kuram atslēga ir lielāka. Paredzēt iespēju izdrukāt faila saturu alfabētiskā un apgrieztā secībā.
PROBLĒMAS======================================================================================================
124 RINDA : Ja izdzēš to random komentāru, tad 3. opcija nestrādā!!!!
Vai patiešām jādublē faili, lai rediģetu saturu???
Ja data.bin fails pirms tam nav pastāvējis, tad ar 2 ierakstu, notiek loop, jo tellg ir -1;
TESTA PLĀNS====================================================================================================
1.tests....................................................
                                        [1]Add[2]Print[3]PrintTurned[0]Exit :
0->enter                                Exits Program
2.tests....................................................
                                        [1]Add[2]Print[3]PrintTurned[0]Exit :
1->enter                                Input key:
koks->enter                             Input value:
parole->enter                           1st Record Added
                                        [1]Add[2]Print[3]PrintTurned[0]Exit :
1->enter                                Input key:
kauja->enter                            Input value:
picu->enter                             2nd Record Added
                                        [1]Add[2]Print[3]PrintTurned[0]Exit :
2->enter                                picu
                                        parole
                                        [1]Add[2]Print[3]PrintTurned[0]Exit :
3->enter                                parole
                                        picu
                                        [1]Add[2]Print[3]PrintTurned[0]Exit :
0->enter                                Exits Program
3.tests....................................................
                                        [1]Add[2]Print[3]PrintTurned[0]Exit :
2->enter                                Empty File
                                        [1]Add[2]Print[3]PrintTurned[0]Exit :
0->enter                                Exits Program, then launches it again
                                        [1]Add[2]Print[3]PrintTurned[0]Exit :
1->enter                                Input key:
1                                       Input value:
sodien                                  1st Record Added
                                        [1]Add[2]Print[3]PrintTurned[0]Exit :
1->enter                                Input key:
2                                       Input value:
ir                                      2nd Record Added
                                        [1]Add[2]Print[3]PrintTurned[0]Exit :
1->enter                                Input key:
3                                       Input value:
skaista                                 3rd Record Added
                                        [1]Add[2]Print[3]PrintTurned[0]Exit :
1->enter                                Input key:
4                                       Input value:
diena                                   4th Record Added
                                        [1]Add[2]Print[3]PrintTurned[0]Exit :
2->enter                                Sodien
                                        Ir
                                        Skaista
                                        Diena
                                        [1]Add[2]Print[3]PrintTurned[0]Exit :
0->enter                                Exits Program
4.tests....................................................
                                        [1]Add[2]Print[3]PrintTurned[0]Exit :
2->enter                                Empty File
                                        [1]Add[2]Print[3]PrintTurned[0]Exit :
0->enter                                Exits Program, then launches it again
                                        [1]Add[2]Print[3]PrintTurned[0]Exit :
1->enter                                Input key:
1                                       Input value:
sodien                                  1st Record Added
                                        [1]Add[2]Print[3]PrintTurned[0]Exit :
1->enter                                Input key:
2                                       Input value:
ir                                      2nd Record Added
                                        [1]Add[2]Print[3]PrintTurned[0]Exit :
1->enter                                Input key:
3                                       Input value:
skaista                                 3rd Record Added
                                        [1]Add[2]Print[3]PrintTurned[0]Exit :
1->enter                                Input key:
4                                       Input value:
diena                                   4th Record Added
                                        [1]Add[2]Print[3]PrintTurned[0]Exit :
3->enter                                Diena
                                        Sodien
                                        Ir
                                        Skaista
                                        [1]Add[2]Print[3]PrintTurned[0]Exit :
0->enter                                Exits Program



**/
#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

const string dataFile = "data.bin";
const string tempFile = "dataTemp.bin";

class Data{
  char key[30];
  char value[30];
  int  previous;
  int  next;

public:
  void setKey();
  void setValue();
  void setPrevious(int previous);
  void setNext(int next);
  char*getKey();
  char*getValue();
  int  getPrevious();
  int  getNext();
  void printData();
};

void  addData(ifstream & input, int & dataCount);
void  printData(ifstream & input,int dataCount);
int   findSmallest(ifstream & input);
void  printDataTurned(ifstream & input, int dataCount);
int   findBiggest(ifstream & input);
int   getFileDataCount(ifstream & input);
const char* getCharInput(int limit);
void  readData(ifstream & input, Data & data, int position);
void  writeData(ofstream & ofstream, Data data, int position);
void  findPosition(ifstream & input, Data & data);
void duplicateNewFile(ifstream & input,ofstream & output, int position, Data data);
void copyFile(ifstream & input,string target, string source);
void messageRecordAdded(int index);

int main(){
  ifstream input;
  string option;
  int dataCount;

  input.open(dataFile.c_str(), ios::in | ios::binary);
  dataCount=getFileDataCount(input);

  do{
    cout<<"[1]Add[2]Print[3]PrintTurned[0]Exit :";
    getline(cin , option);
    if(option == "1"){ addData(input , dataCount); dataCount++;}
    if(option == "2"){ printData(input,dataCount); }
    if(option == "3"){ printDataTurned(input,dataCount); }
  }while(option == "1" || option == "2" || option == "3");
  remove("dataTemp.bin");
  input.close();
}

void addData(ifstream & input , int & dataCount){
  Data data;
  ofstream output;

  data.setKey();
  data.setValue();
  if(dataCount == 0){
    data.setPrevious(-1);
    data.setNext(-1);
    output.open(dataFile.c_str(),ios::out | ios::binary);
    writeData(output,data,0);
    output.close();
  }else{
    output.open(tempFile.c_str(),ios::out | ios::binary);
    findPosition(input,data);
    duplicateNewFile(input,output,dataCount,data);
    output.close();
    copyFile(input,dataFile,tempFile);
  }
  messageRecordAdded(dataCount);
}

void printData(ifstream & input,int dataCount){
  if(dataCount<=0){
    cout<<"Empty File"<<endl;
    return;
  }

  Data tempData;
  int position;

  readData(input,tempData,findSmallest(input));
  tempData.printData();

  while(tempData.getNext()!=-1){
    readData(input,tempData,tempData.getNext());
    tempData.printData();
  }
}

int findSmallest(ifstream & input){
  Data tempData;
  int position;

  readData(input,tempData,position);
  position=0;

  while(tempData.getPrevious()!=-1){
    position=tempData.getPrevious();
    readData(input,tempData,position);
  }
  return position;
}

void printDataTurned(ifstream & input,int dataCount){
  if(dataCount<=0){
    cout<<"Empty File"<<endl;
    return;
  }
  cout<<""; //ASK THE PROFFESOR WHHHYYY???? REMOVE THIS AND 3RD OPTION DOESNT WORK
  Data tempData;
  int position;

  readData(input,tempData,findBiggest(input));
  tempData.printData();

  while(tempData.getPrevious()!=-1){
    readData(input,tempData,tempData.getPrevious());
    tempData.printData();
  }
}

int findBiggest(ifstream & input){
  Data tempData;
  int position;

  readData(input,tempData,position);
  position=0;

  while(tempData.getNext()!=-1){
    position=tempData.getNext();
    readData(input,tempData,position);
  }
  return position;
}

int  getFileDataCount(ifstream & input){
  int dataCount;

  input.seekg(0,ios::end);
  dataCount = input.tellg()/sizeof(Data);
  input.seekg(0,ios::beg);
  return (dataCount>=0)?dataCount:0;
}

void readData(ifstream & input, Data & data, int position){
  input.clear();
  input.seekg(position*sizeof(Data));
  input.read(reinterpret_cast< char * >( &data ), sizeof( Data ) );
}

void writeData(ofstream & output, Data data, int position){
  output.clear();
  output.seekp(position*sizeof(Data));
  output.write(reinterpret_cast<const char * >( &data ), sizeof( Data ) );
  output.flush();
  output.clear();
}


void  findPosition(ifstream & input, Data & data){
  Data tempData;
  int position;

  position=0;
  readData(input,tempData,position);

  if(strcmp(data.getKey(),tempData.getKey())<0){
    while(tempData.getPrevious()!=-1&&strcmp(data.getKey(),tempData.getKey())<0){
      position=tempData.getPrevious();
      readData(input,tempData,position);
    }
    if(tempData.getPrevious()==-1){
      data.setNext(position);
      data.setPrevious(-1);
    }else{
      data.setNext(tempData.getNext());
      data.setPrevious(position);
    }
  }else{
    while(tempData.getNext()!=-1&&strcmp(data.getKey(),tempData.getKey())>0){
      position=tempData.getNext();
      readData(input,tempData,position);
    }
    if(tempData.getNext()==-1){
      data.setNext(-1);
      data.setPrevious(position);
    }else{
      data.setNext(position);
      data.setPrevious(tempData.getPrevious());
    }
  }
}

void duplicateNewFile(ifstream & input,ofstream & output, int dataCount, Data data){
  Data DuplicateData;
  int i;
  input.seekg(0,ios::beg);
  output.seekp(0,ios::beg);
  input.read(reinterpret_cast< char * >( &DuplicateData ), sizeof( Data ) );
  i=0;
  while(i<dataCount){
      if(i==data.getPrevious()){
        DuplicateData.setNext(dataCount);
      }
      if(i==data.getNext()){
        DuplicateData.setPrevious(dataCount);
      }
      output.write(reinterpret_cast<const char * >( &DuplicateData ), sizeof( Data ) );
      output.flush();
      input.read(reinterpret_cast< char * >( &DuplicateData ), sizeof( Data ) );
      i++;
  }
  output.seekp(0,ios::end);
  output.write(reinterpret_cast<const char * >( &data ), sizeof( Data ) );
  output.flush();
}

void copyFile(ifstream & input,string target, string source){
  ofstream output;

  input.close();
  input.open("dataTemp.bin",ios::in | ios::binary);
  output.open("data.bin",ios::out | ios::binary);
  output << input.rdbuf();
  input.close();
  input.open("data.bin",ios::in | ios::binary);
  output.close();
}

void messageRecordAdded(int index){
  string addon;
  if((index+1)>4&&(index+1)<20){
      cout<<(index+1)<<"th Record Added"<<endl;
      return;
  }
  switch((index+1)%10){
    case 1: addon="st";break;
    case 2: addon="nd";break;
    case 3: addon="rd";break;
    default: addon="th";break;
  }
  cout<<(index+1)<<addon<<" Record Added"<<endl;
}

void Data::setKey(){
  cout<<"Input key: ";
  string input;
  getline(cin,input);
  input.resize(30);
  strcpy(this->key,input.c_str());
}

void Data::setValue(){
  cout<<"Input value: ";
  string input;
  getline(cin,input);
  input.resize(30);
  strcpy(this->value,input.c_str());
}

void Data::setPrevious(int previous){
  this->previous=previous;
}

void Data::setNext(int next){
  this->next=next;
}

char*Data::getKey(){
  return this->key;
}

char*Data::getValue(){
  return this->value;
}

int  Data::getPrevious(){
  return this->previous;
}

int  Data::getNext(){
  return this->next;
}

void Data::printData(){
  cout<<this->value<<endl;
}
