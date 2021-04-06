/*
  Aubakirov Talgat, Omar Adilkhan
  BDA1902

  Assignment 2, (Part 1 of the project)
  Work done in C++ language (C++11) in replit.com website
*/

/*
  Importing necessary libraries
  iostream - input/output in console
  fstream - input/output in file
*/
#include <iostream>
#include <fstream>

/*
  User std as default scope, to ont write std:: before each cin, cout and other methods and variable types
*/
using namespace std;

/*
  Prototypes of function that will be implemented during the code
*/

int* uniqueSorter(int*);
int* counter(string);
string file_read(string);

/*
  Implementing special function to sort array the programm get from counter function
*/

int* uniqueSorter(int* counted) {
  int* arr = new int[256];
  for(int i = 0; i < 128; i++) {
    arr[i + 128] = i;
    arr[i] = counted[i];
  }
  for(int i = 0; i < 128; i++) {
    for(int j = 0; j < i; j++) {
      if(arr[i] > arr[j]) {
        swap(arr[i], arr[j]);
        swap(arr[i + 128], arr[j + 128]);
      }
    }
  }
  return arr;
}

/*
  Implementing counter function to count occurence of each symbol in text
*/

int* counter(string text) {
  int* arr = new int[128];
  for(int i = 0; i < 128; i++) {
    arr[i] = 0;
  }
  for(int i = 0; i < text.length(); i++) {
    arr[text[i]]++;
  }
  return arr;
}

/*
  Implementing file_Read function to get tex from file
*/

string file_read(string name) {
  string text, line;
  ifstream myfile (name);
  if (myfile.is_open())
  {
    while(getline(myfile,line)) {
      text += line + '\n';
    }
    myfile.close();
  }
  return text;
}

/*
  Implementing main code to link every function before and get result of main task
*/

int main() {
  string text = file_read("text.txt");
  int* arr = uniqueSorter(counter(text));
  double size = text.length();
  for(int i = 0; i < 128; i++) {
    if(arr[i] == 0) {
      break;
    }
    cout << char(arr[i + 128]) << " - " << arr[i] << endl;
  }
}
