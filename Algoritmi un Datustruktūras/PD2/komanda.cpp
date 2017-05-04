#include <iostream>
#include <fstream>

using namespace std;

class Data{

  struct Participant{
    unsigned int ID;
    unsigned int P1;
    unsigned int P2;
    int LV;
  };

  struct Segment{
    Participant data[1000];
  };

  Segment *data[10];
  int size;

public:
  Data();
  ~Data();
  void NewSegment();
  void setID(int index,unsigned int ID);
  void setP1(int index,unsigned int P1);
  void setP2(int index,unsigned int P2);
  unsigned int getID(int index);
  unsigned int getP1(int index);
  unsigned int getP2(int index);
}data;

class Chain {

  struct Node {
    unsigned int value;
    Node *next;
  };

  Node *beg;
  Node *end;

public:
    Chain();
    ~Chain();
    void Add(unsigned int value);
    void Output(ofstream & output);
} * outputLevel;

int participantCount;
int jumpsPerformed;
int maxLevel;

int getIndex(unsigned int position);
void jump(unsigned int position , int level);
void jumpSetLevels(unsigned int position , int level);

int main(){

  ifstream input;
  ofstream output;
  long long participantInitial;
  unsigned int ID;
  unsigned int P1;
  unsigned int P2;

  input.open("komanda.in", ios::in);
  participantInitial = 0;
  participantCount = 0;
  jumpsPerformed = 0;
  input>>ID>>P1>>P2;

  while(ID!=0){
    participantInitial += (long long)ID;
    data.setID(participantCount,ID);
    data.setP1(participantCount,P1);
    data.setP2(participantCount,P2);
    participantCount++;
    if(participantCount%1000==0)data.NewSegment();
    input>>ID>>P1>>P2;
  };

  input.close();

  for(int i=0;i<participantCount;i++){
    participantInitial -=(long long)data.getP1(i);
    participantInitial -=(long long)data.getP2(i);
  }

  output.open("komanda.out",ios::out);
  jump(participantInitial , 0);
  outputLevel = new Chain[maxLevel+1];
  jumpSetLevels(participantInitial , 0);

  for(int i=maxLevel;i>=0;i--){
    output<<i<<": ";
    outputLevel[i].Output(output);
    output<<endl;
  }

  output.close();

  delete[] outputLevel;
}

int getIndex(unsigned int position){
  for(int i=0;i<participantCount;i++) if(position == (long long)data.getID(i)) return i;
  return 0;
}

void jump(unsigned int position , int level){
  if(position == 0) return;
  if(level>maxLevel)maxLevel = level;
  int index = getIndex(position);
  jump(data.getP1(index),level+1);
  jump(data.getP2(index),level+1);
}

void jumpSetLevels(unsigned int position , int level){
  if(position == 0) return;
  outputLevel[level].Add(position);
  int index = getIndex(position);
  jumpSetLevels(data.getP1(index),level+1);
  jumpSetLevels(data.getP2(index),level+1);

}

Data::Data(){
  size = 0;
  NewSegment();
}

Data::~Data(){
  for(int i=0;i<size;i++) delete data[i];
}

void Data::NewSegment(){
  Segment * segment;
  segment = new Segment();
  data[size] = segment;
  size++;
}

void Data::setID(int index,unsigned int ID){
  this->data[index/1000]->data[index%1000].ID = ID;
}

void Data::setP1(int index,unsigned int P1){
  this->data[index/1000]->data[index%1000].P1 = P1;
}

void Data::setP2(int index,unsigned int P2){
  this->data[index/1000]->data[index%1000].P2 = P2;
}

unsigned int Data::getID(int index){
  return this->data[index/1000]->data[index%1000].ID;
}

unsigned int Data::getP1(int index){
  return this->data[index/1000]->data[index%1000].P1;
}

unsigned int Data::getP2(int index){
  return this->data[index/1000]->data[index%1000].P2;
}

Chain::Chain(){
  beg = end = NULL;
}

Chain::~Chain(){
  delete this->beg;
  delete this->end;
}

void Chain::Add(unsigned int value){
  Node * temp = new Node();
  temp->value = value;
  temp->next = NULL;
  if(this->beg == NULL) this->beg = temp;
  else this->end->next = temp;
  this->end = temp;
}

void Chain::Output(ofstream & output){
  Node * temp = beg;

  while ( temp != NULL ) {
    output<<temp->value<<" ";
    temp=temp->next;
  }
}
