/*  Kyle Leibowitz
    5/31/20
    CS140
    Alexandar Covington
*/

#include <iostream>
#include <fstream>
#include <stdexcept> 

using namespace std;

//Helper function to get a file. Asks for path from user. Exits if bad path. Else returns open file if valid.
ifstream getFile();

//Function to get the phrase to search for.
string getPhrase();

//Function that goes through the file and prints the phrase that was given and the line it was discovered on.
void processFile(ifstream &myFile, string phrase);

int main() {
    ifstream file = getFile();
    ifstream &myFile = file;

    string phrase = getPhrase();

    processFile(myFile, phrase);

    file.close();
}

ifstream getFile(){
    string file;
    cout<<"File Path: ";
    getline(cin, file);

    ifstream myFile;
    myFile.open(file, ios::in);
    if(myFile.fail()){
        cout<<"Could not open file "<<file<<endl;
        exit(1);
    }
    return myFile;
}

string getPhrase(){
    string phrase;
    cout<<"Phrase: ";
    getline(cin, phrase);
    return phrase;
}

void processFile(ifstream &myFile, string phrase){
    string line;
    int i = 1;
    while(getline(myFile, line)){
        if(line.find(phrase)!=string::npos){
            cout<<i<<") ";
            cout<<line<<endl;
        }
        i++;
    }
}