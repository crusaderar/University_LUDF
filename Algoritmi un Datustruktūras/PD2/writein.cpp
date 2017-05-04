#include <iostream>
#include <fstream>

using namespace std;

int main(){
  fstream output;
  output.open("komanda.in",ios::out);
  for(int i=0;i<9998;i++){
    output<<(10000+i)<<" "<<(10001+i)<<" "<<0<<endl;
  }
  output<<19998<<" 0 0"<<endl;
  output<<"0 0 0"<<endl;
}
