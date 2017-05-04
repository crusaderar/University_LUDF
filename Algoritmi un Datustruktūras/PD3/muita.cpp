#include <iostream>
#include <fstream>

using namespace std;




// Manger Class
struct Manager{
  int time;
  long long timer;

  Manager(){
    this->timer = 0;
  }
};

int main(){
  ifstream input; // File Input
  ofstream output; // File output
  char type; // input type
  unsigned int arrival; // arrival of person
  int CMC;// Citizen Manager Count
  int NMC;// Non-Citizen Manager Count
  int CMT;// Citizen Manager Time
  int NMT;// Non-Citizen Manager Time

  input.open("muita.in", ios::in);
  output.open("muita.out", ios::out);
  input>>CMC>>NMC>>CMT>>NMT;
  Manager CManager[CMC];
  Manager NManager[NMC];

  for(int i=0;i<CMC;i++) CManager[i].time = CMT;
  for(int i=0;i<NMC;i++) NManager[i].time = NMT;

  input>>type;
  while(type != 'X'){
    switch(type){
      case 'P':
        input>>arrival;
        output<<arrival<<" ";
        for(int i = 0 ; i < CMT ; i++){
          if(CManager[i].timer == 0){
              CManager[i].timer +=CManager[i].time;
              output<<arrival+CManager[i].time<<endl;
              break;
          }
        }
      break;
      case 'N':
        input>>arrival;
      break;
      case 'T':
        int index,value;
        input>>type>>index>>value;
        if(type == 'P')CManager[index-1].time = value;
        else NManager[index-1].time = value;
      break;
    }
    input>>type;
  }
  input.close();
  output.close();
}
