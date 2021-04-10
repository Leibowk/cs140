/*CS140
 *Project2
 *Kyle Leibowitz
 *Isabella Bowen
 *Kai Blais-Schmolke
 */

#include "iostream"
#include <fstream>
#include <string> 
#include <stdio.h>
#include <sstream>
#include <cmath>
#include <stdexcept>
#include <iomanip> 
#include <random>
#include <errno.h>
#include <exception>
#include <cerrno>
#include <string.h>

using namespace std;

struct account{
    string name;
    string id;
    double bal;
};

struct vault{
  string id;
  double bal;
};

//If given file exists, returns stream of file. Else exits with error. 
ifstream getFile(string file);

//Returns number of lines of file - 1 (due to layout of files containing labels)
int getSize(ifstream &myFile);

//Takes an array of accounts and the file, then goes through to fill up the array with the accounts from the file.
void getAccounts(ifstream &myFile, account* allAccounts);

//Takes an array of transactions and the file, then goes through to fill up the array with the transactions from the file
void getAdjustments(ifstream &foulder,vault* Taccount);

//Goes through to adjust all the accounts so that they reflect the adjustments after the transactions.
void makeAdjustments(account* allAccounts, vault* Taccount, int bLines, int numLines);

//Prints out the new accounts to the file "new_balances.csv"
void printNewFile(account* allAccounts, int numLines);

int main() {
    //Getting balances file
    ifstream balFile = getFile("balances.csv");
    ifstream &myFile = balFile;

    //Making array of current balances
    int numLines = getSize(myFile);
    account allAccounts[numLines];
    getAccounts(myFile, allAccounts);

    //Getting transaction file
    ifstream transFile = getFile("transactions.csv");
    ifstream &foulder=transFile;
    
    //Making array of transactions
    int bLines=getSize(foulder);
    vault tAccount[bLines];
    getAdjustments(foulder, tAccount);

    //Updating the accounts with the adjustments
    makeAdjustments(allAccounts, tAccount, bLines, numLines);
    
    //Printing to new file
    printNewFile(allAccounts, numLines);

}


//If given file exists, returns stream of file. Else exits with error.
ifstream getFile(string file){
    ifstream myFile;
    myFile.open(file, ios::in);
    if(myFile.fail()){
        //Upon file failing to open, prints error message and exits
        cerr << "Error \"" << strerror(errno) << "\" when opening file: " << file <<endl;
        exit(1);
    }
    return myFile;
}

//Returns number of lines of file - 1 (due to layout of files containing labels)
int getSize(ifstream &myFile){
    int i = 0;
    string line;
    while(getline(myFile, line)){
        i++;
    }
    //Also takes file back to beginning so it can be reused.
    myFile.clear();
    myFile.seekg(0, ios::beg);
    return i-1;
}

//Takes an array of accounts and the file, then goes through to fill up the array with the accounts from the file.
void getAccounts(ifstream &myFile, account* allAccounts){
    int i = 0;
    string line;
    std::string::size_type sz; 

    //Dealing with title line
    getline(myFile, line);

    while(getline(myFile, line)){
        string* substr = new string[3];
        stringstream s_stream(line);
        int k = 0;
        float test;
        while(s_stream.good()) {
            getline(s_stream, substr[k], ',');
            k++;
        }

        allAccounts[i].name = substr[0];
        allAccounts[i].id = substr[1];
        allAccounts[i].bal = stod(substr[2], &sz);

        i++;
    }
}

//Takes an array of transactions and the file, then goes through to fill up the array with the transactions from the file
void getAdjustments(ifstream &foulder,vault* Taccount){
    int i=0;
    string line;
    std::string::size_type sz;

    //Dealing with title line
    getline(foulder,line);

    while(getline(foulder, line)){
        string* substr=new string[2];
        stringstream s_stream(line);
        int d=0;
        while(s_stream.good()){
            getline(s_stream, substr[d],',');
            d++;
        }
        Taccount[i].id=substr[0];
        Taccount[i].bal=stod(substr[1], &sz);

        i++;
    }

}

//Goes through to adjust all the accounts so that they reflect the adjustments after the transactions.
void makeAdjustments(account* allAccounts, vault* Taccount, int bLines, int numLines){
    int A=0;
    while (A<=numLines){
        int j=0;
        double C=0;
        while (j<=bLines){
            if (Taccount[j].id==allAccounts[A].id){
                C=C+Taccount[j].bal;
                j++;
                }
            else{
                j++;
            }
        }

        allAccounts[A].bal=allAccounts[A].bal+C;
        A++;
    }
}

//Prints out the new accounts to the file "new_balances.csv"
void printNewFile(account* allAccounts, int numLines){
    ofstream myfile;
    myfile.open ("new_balances.csv");
    myfile << "ID,Name,Balance" << endl;
    int i=0;
    while (i < numLines){
        myfile << allAccounts[i].id << "," << allAccounts[i].name << ",";
        myfile << setprecision(2) << fixed << allAccounts[i].bal <<endl;
        i++;
    }
}