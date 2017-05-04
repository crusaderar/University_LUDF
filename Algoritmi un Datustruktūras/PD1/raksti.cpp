#include <iostream>
#include <fstream>

using namespace std;

struct Container{
  int i;
  char name[200];
  char *comments;
  int size;

  ~Container(){
    delete[] comments;
  }
  void add(const char* comment){
    if(comments == NULL){
      comments = new char[30];
      size=0;
      for(int i=0;i<30&&(comment[i]<='z'&&comment[i]>='a'||comment[i]<='Z'&&comment[i]>='A');i++){
        comments[i] = comment[i];
        size++;
      }
      return;
    }else{
      int buffer_size=0;
      char * buffer = new char[size+31];
      for(int i=0;i<30&&(comment[i]<='z'&&comment[i]>='a'||comment[i]<='Z'&&comment[i]>='A');i++){
        buffer[i] = comment[i];
        buffer_size++;
      }
      buffer[buffer_size]=' ';buffer_size++;
      for(int i=0;i<size;i++){
        buffer[buffer_size+i]=comments[i];
      }
      size +=buffer_size;
      delete[] comments;
      comments = buffer;
    }
  }
};

int main (){
  ifstream read;
  int fileCount;
  Container *container;
  //READING AND SWAPPING THE ARTICLE NAMES
  read.open("raksti.in", ios::in);
  read>>fileCount;
  container = new Container[fileCount];
  for(int i=0;i<fileCount;i++){
    read>>container[i].i;
    read.get();
    read.get();
    read.getline(container[i].name,200,'"');
  }
  for(int i=0;i<fileCount;i++){
    for(int g=0;g<fileCount-1;g++){
      if(container[g].i>container[g+1].i){
        Container temp = container[g];
        container[g] = container[g+1];
        container[g+1] = temp;
      }
    }
  }
  while(!read.eof()){
    int i;
    bool exists = false;
    char comment[30];
    read>>i;
    for(int g=0;g<fileCount&&exists==false;g++){
      if(container[g].i == i){
        i=g;
        exists = true;
      }
    }
      read.get();
      read.getline(comment,30);
    if(exists){
      container[i].add(comment);
    }
  }
  read.close();
  ofstream write;
  write.open("raksti.out", ios::out);
  for(int i=0;i<fileCount;i++){
    write<<container[i].name<<endl;
    if(container[i].comments==NULL)
      write<<"-"<<endl;
    else{
      int offset=0;
      if(container[i].comments[0]==' ')offset++;
      for(int g=offset;g<container[i].size;g++){
        write<<container[i].comments[g];
      }
      write<<endl;
    }
  }
  delete[] container;
}
