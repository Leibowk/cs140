/*  Kyle Leibowitz
    5/31/20
    CS140
    Alexandar Covington
*/

#include <iostream>
#include "iomanip"
#include <math.h>
#include <fstream>
#include <stdexcept> 

using namespace std;

//Helper function to get a file. Asks for path from user. If file exists, opens with truncations, else creates file.
ofstream getFile();

//Prints "Price and Description stuff to file"
void printInit(ofstream &myFile);

//Gets the name of the item
string getName(string message);

//Gets the price of the item
float getPrice(string message);

//Prints the price and name of item neatly to file
void printItem(ofstream &myFile, string name, float price);

//Prints total into the file
void printTotal(ofstream &myFile, float total);

//Asks user if finished with program
bool done();

int main() {
    ofstream file = getFile();
    ofstream &myFile = file;
    bool finished = false;

    printInit(myFile);
    
    float total=0;

    while(!finished){
        float price = getPrice("Price: ");

        string name = getName("Description: ");
        
        printItem(myFile, name, price);
        
        total+=price;

        finished = done();
    }

    printTotal(myFile, total);

    file.close();
}


ofstream getFile(){
    string file;
    cout<<"File Path: ";
    getline(cin, file);

    ofstream myFile;
    myFile.open(file, ios::trunc);
    
    return myFile;
}

void printInit(ofstream &myFile){
    myFile<<"Price"<<setw(20)<<"Description"<<endl;
    myFile<<"-----"<<setw(20)<<"-----------"<<endl<<endl;
}

//Prints item name and price to file. If item is exact price, includes 0 cents in file
void printItem(ofstream &myFile, string name, float price){
    if((price - floor(price))==0)
      myFile<<price<<".00"<<setw(20)<<name<<endl;
    else
    {
        myFile<<price<<setw(20)<<name<<endl;
    }
}

//Prints total to file. If total is exact price, includes 0 cents in file
void printTotal(ofstream &myFile, float total){
    myFile<<endl<<"Total"<<endl;
    myFile<<"------"<<endl;
    if((total - floor(total))==0)
      myFile<<total<<".00"<<endl;
    else
    {
        myFile << total;
    }
}

bool done(){
    string finished;
    do{
        cout<<"Finished? [y/n] ";
        getline(cin, finished);
        if((finished!="y")&&(finished!="n")){
            cout<<"Invalid difficulty!"<<endl;
        }
    }while((finished!="y")&&(finished!="n"));
    if(finished =="y"){
        return true;
    }
    return false;
}

string getName(string message){
  cout<<message;
  string food;
  getline(cin, food);
  return food;
}

float getPrice(string message){
  cout<<message;
  string sValue;
  getline(cin, sValue);
  float value = std::stof(sValue);
  return value;
}