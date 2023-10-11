#pragma once

#include <limits.h>
#include <inttypes.h>
#include <cstdlib>
#include <string>
#include <iostream>		// for system()
#include <iomanip>
#include <fstream> // for ifstream
#include <memory>

void addThem(uint16_t ui_a, uint16_t ui_b) {
    uint16_t ui_sum;
    try
    {
        if (UINT16_MAX - ui_a < ui_b) {
            throw exception;
        }
        else {
        ui_sum = ui_a + ui_b;
        }
    }
    catch (const exception)
    {

    }
    
    
    /* ... */
}

void addThem(int16_t si_a, int16_t si_b) {
    int16_t si_sum;
    if (((si_b > 0) && (si_a > (INT16_MAX - si_b))) ||
        ((si_b < 0) && (si_a < (INT16_MIN - si_b)))) {
        /* Handle error */
    }
    else {
        si_sum = si_a + si_b;
    }
    /* ... */
}

using namespace std;

void aFunction() {
    const char* tmpPtr = std::getenv("TMP");
    if (tmpPtr == NULL) {
        // error message here


    }
}



void filesr() {
    char buffer[20];
    try
    {
        ofstream myfile("test.txt"); // open a text file for reading
        // ifstream does not have exceptions by default. Let’s register 3 of them to the stream:
        myfile.exceptions(ofstream::eofbit | ofstream::failbit | ofstream::badbit);
        while (myfile)
        {

            cout << buffer << endl;
        }
        myfile.close();
    }
    catch (exception e)
    {
        // strstr: finds out if 2nd string is contained within 1st string.
        // Returns a pointer to occurrence of 2nd string in 1st string
        if (strstr(e.what(), "eofbit") != NULL)
        {
            cout << buffer << endl;
            cout << "END OF FILE REACHED" << endl;
        }
        else
        {
            cout << "There was an error: " << e.what() << endl;
        }
    }
}

int main()
{
    char buffer[20];
    try
    {
        ifstream myfile("test.txt"); // open a text file for reading
        // ifstream does not have exceptions by default. Let’s register 3 of them to the stream:
        myfile.exceptions(ifstream::eofbit | ifstream::failbit | ifstream::badbit);
        while (myfile)
        {
            myfile.getline(buffer, 20);
            cout << buffer << endl;
        }
        myfile.close();
    }
    catch (exception e)
    {
        // strstr: finds out if 2nd string is contained within 1st string.
        // Returns a pointer to occurrence of 2nd string in 1st string
        if (strstr(e.what(), "eofbit") != NULL)
        {
            cout << buffer << endl;
            cout << "END OF FILE REACHED" << endl;
        }
        else
        {
            cout << "There was an error: " << e.what() << endl;
        }
    }
    system("pause");
    return 0;
}