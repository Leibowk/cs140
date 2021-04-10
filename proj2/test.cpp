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

string encrypt(string str);

int main() {
    string test = "tesz";
    string myEncrpytion = encrypt(test);
    cout<<myEncrpytion<<endl;

}

string encrypt(string str) {
    string newString;
    for(int i=0; i<str.length(); i++){
        if(str.at(i)=='z'){
            newString= newString + "a";
        }else{
            newString= newString + (++str.at(i));
        }
    }
    return newString;
}