#include <iostream>
#include <string>
#include <thread>
#include <mutex>
#include <condition_variable>

using namespace std;

string inputString;
mutex inputMutex;
condition_variable inputCV;

void inputThread()
{
cout << "Enter a string: ";
getline(cin, inputString);


inputCV.notify_all();
}

void reverseThread()
{
unique_lock<mutex> lock(inputMutex);
inputCV.wait(lock);


string reversedString = "";
for(int i = inputString.length() - 1; i >= 0; i--)
{
    reversedString += inputString[i];
}

cout << "Reversed string: " << reversedString << endl;
}

void capitalThread()
{
unique_lock<mutex> lock(inputMutex);
inputCV.wait(lock);


string capitalizedString = "";
for(int i = 0; i < inputString.length(); i++)
{
    capitalizedString += toupper(inputString[i]);
}

cout << "Capitalized string: " << capitalizedString << endl;
}

void shiftThread()
{
unique_lock<mutex> lock(inputMutex);
inputCV.wait(lock);
string shiftedString = "";
for(int i = 0; i < inputString.length(); i++)
{
    char shiftedChar = inputString[i] + 2;
    shiftedString += shiftedChar;
}

cout << "Shifted string: " << shiftedString << endl;
}

int main()
{
thread input(inputThread);
thread reverse(reverseThread);
thread capital(capitalThread);
thread shift(shiftThread);


input.join();
reverse.join();
capital.join();
shift.join();

return 0;
}