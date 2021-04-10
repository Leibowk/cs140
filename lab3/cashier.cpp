#include "iostream"
#include "iomanip"
#include <math.h>
#include <bits/stdc++.h> 

using namespace std;

/* PROTOTYPES */
void scan(void);
void pay(void);
void print_change(float change);

/* GLOBALS */
float total = 0;

float getFloat(string message){
  cout<<message;
  string sValue;
  getline(cin, sValue);
  float value = std::stof(sValue);
  return value;
}

float roundV(float val){
  return roundf(val * 100) / 100;
}

void printfunc(string text, float amount){
    if((amount - floor(amount))==0)
      cout<<setprecision(0);
    else
    {
        cout<<setprecision(2);
    }
    
    cout << noshowpoint << left<< setw(20)<< text<< setw(7) << "--" << amount << endl;
}

void scan() {
  float price = getFloat("Price of item: ");
  float quantity = getFloat("Quantity: ");
  total = total + (price * quantity);
}

void pay() {
  float money = getFloat("Customer paid: ");
  if (money<total){
      cout<<"Not enough paid!\n";
      return;
  }

  float change = roundV(money - total);
  int dollars = (int)change;
  printfunc("Change back", change);
  printfunc("Dollars", dollars);
  float cents = change - dollars;
  print_change(cents);
  total = 0;
}

void print_change(float change) {
    int num = 0;
    if (change>.25){
    while(change>=.25){
      change = change - .25;
      num= num + 1;
      }  
    printfunc("Quarters", num);
    num = 0;
    }

    if (change>.10){
      while(change>=.10){
        change = change - .10;
        num= num + 1;
      }
      printfunc("Dimes", num);
      num = 0;
    }

    if(change>.05){
      while(change>=.05){
          change = change - .05;
          num= num + 1;
      }
      printfunc("Nickles", num);
      num = 0;
    }
    
    if(change>.01){
      while(change>=.01){
          //cout<<change<<endl;
          change = change - .01;
          num= num + 1;
      }
      printfunc("Pennies", num);
    }
}

// DO NOT MODIFY MAIN
int main() {
  while (true) {
    string input;
    cout << "Total" << setw(10) << "$" << fixed << setprecision(2) << total << endl << "> ";
    getline(cin, input);

    if (input.compare("scan") == 0) {
      scan();
    } else if (input.compare("pay") == 0) {
      pay();
    } else if (input.compare("quit") == 0) {
      exit(0);
    } else {
      cout << "Invalid input." << endl;
    }
    cout << endl;
  }
}