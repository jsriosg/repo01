#include <cmath>
#include <iostream>

using namespace std;
int main(){
  for(int i=500; i<=1400;i++){
   int j=2;
    while(i%j !=0 && j<=i){
      j=j+1;
      if(i%j==0){
	if(j==i){
	  cout<<i<<endl;
	}
	break;
      }
    }
  }
}
