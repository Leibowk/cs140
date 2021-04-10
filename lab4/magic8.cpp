#include <iostream>
#include <random>

using namespace std;

int randInt(int low, int high){
    random_device rd;
    default_random_engine generator{rd()};
    uniform_int_distribution<int> distribution(low, high);
    return distribution(generator);
}
int main(){
  string deck[8] = {"It is certain.", "As I see it, yes.", "Reply hazy. Try again.", "Don't count on it.", "It is decidedly so.", "Most likely.", "Ask again later.", "My reply is no."};
  string sValue;
  cout<<"What is your question?"<<endl;
  getline(cin, sValue);
  int ran = randInt(0,7);
  cout<<deck[ran]<<endl;

}