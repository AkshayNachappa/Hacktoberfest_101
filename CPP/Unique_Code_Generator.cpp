#include <iostream>
#include <string.h>
#include <ctime>
#include <bits/stdc++.h>
using namespace std;

string randomString(int maxLength = 5, string charIndex = "abcdefghijklmnaoqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890")
{
    int length = maxLength;
    int indexesOfRandomChars[15];
    for (int i = 0; i < length; ++i)
        indexesOfRandomChars[i] = rand() % charIndex.length();
    string randomString = "";
    for (int i = 0; i < length; ++i){
        randomString += charIndex[indexesOfRandomChars[i]];
    } 
    return randomString;
}

int main(){

string kode_unik;
    srand(time(NULL));
		kode_unik=randomString();
		cout<<"\n	Kode Unik Anda = "<<kode_unik<<;
	
}