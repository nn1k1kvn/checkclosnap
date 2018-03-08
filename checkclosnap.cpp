/* Check CLO-snapshot for console
 * Copyright (c) 2018 Mihails Šilovs 
 * version  0.0.1
 * Cross Compile:
 * i686-w64-mingw32-g++ -std=c++11 -c checkclosnap.cpp;
 * i686-w64-mingw32-g++ checkclosnap.o -o checkclosnap
 * Running:
 * ./checkclosnap 0x4E034B79Baf6905DCc8720af15f986f59E33f402
*/

#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>
#include <cmath>
using namespace std;

string snap = "snapshot_0001.txt";  // snapshot file
string split_char = ",";
string line,token;
int row;
const unsigned long long wei_unit = pow(10,18);

 long double etc;

 long double get_etc (string line)
{   
	size_t last = 0;
	size_t next = 0;

	while ((next = line.find(split_char, last)) != string::npos){
		token = line.substr(last, next-last);
		if (last == 0){
			
			row = stoi(token);
		}
		last = next + 1;
	}

	return  stold(line.substr(last))/wei_unit;
}

int main(int argc, char *argv[]) {


  ifstream infile(snap);
  string address;

  // Check the adress of parameters
    if (argc < 2) {
        
        std::cerr << "Usage: " << argv[0] << " [your adress ETC wallet] " << endl;

        return 1;
   }

  address = argv[1];
  transform(address.begin(), address.end(), address.begin(), ::tolower);

  while (getline(infile, line)) {
  	
  	
  	if (line.find(address) != string::npos) {
  		 etc = get_etc(line);
  		 cout << fixed;
  		 cout.precision(18);
  		 cout << "Row: " << row << endl;
  		 cout << "Address: " << address << endl;
  		 cout << "Balance: " << etc << " CLO" << endl;
           		 
    }
    
 }

  infile.close();
  return 0;
}


