#include "combo.h"
using namespace std;

std::string guess_sequence(int N) {
  std::string p, x;
  char a, b, c = 'Y';

  if(press("AB") > 0) {
    if(press("A") > 0) c = 'A';
    else c = 'B';
  } else if(press("X") > 0) c = 'X';

  p = c;
  if(c=='A') {a = 'B'; b = 'X'; c = 'Y';}
  else if(c=='B') {a = 'A'; b = 'X'; c = 'Y';}
  else if(c=='X') {a = 'A'; b = 'B'; c = 'Y';}
  else if(c=='Y') {a = 'A'; b = 'B'; c = 'X';}

  int coins = 1, temp;
  for(int i = 1;i<N-1;i++){
    x = p; x += b;

    x += p; x += c; x += a;
    x += p; x += c; x += b;
    x += p; x += c; x += c;

    temp = press(x);

    if(temp-coins==0){
      p += a;
    } else if(temp-coins==1){
      p += b;
    } else if(temp-coins==2){
      p += c;
    }
    coins++;
  }

  if(N>1){
    x = p; x+= a;
    if(press(x) > coins) p += a;
    else {
      x = p; x+= b;
      if(press(x) > coins) p += b;
      else p += c;
    }
  }

  return p;
}
