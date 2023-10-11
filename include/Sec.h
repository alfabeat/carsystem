#pragma once
# include<iostream>
#include < iomanip > 
#include "ErrorLogger.h"

double safeag(double ui_a, unsigned int ui_b) {
    std::string msg;
    unique_ptr< Logger> loggerformatted;
    loggerformatted = make_unique<ErrorLogger>();
    double udiff = ui_a * ui_b;
   // udiff = setprecision(3);
    if (udiff < ui_a) {
        msg = "Error multiplying";
        loggerformatted->log(msg);
       
    }
    else {

        return udiff;
    }
    /* ... */
}

int safeadd(unsigned int ui_a, unsigned int ui_b) {
    unsigned int usum;   
    std::string msg;
    unique_ptr< Logger> loggerformatted;
    loggerformatted = make_unique<ErrorLogger>();
    if (UINT_MAX - ui_a < ui_b) {
        /* Handle error */
        msg = "Error adding";
        loggerformatted->log(msg);
    }
    else {
        usum = ui_a + ui_b;
        return usum;
    }
    /* ... */
}


int safemin(unsigned int ui_a, unsigned int ui_b) {
    unsigned int udif;
    std::string msg;
    unique_ptr< Logger> loggerformatted;
    loggerformatted = make_unique<ErrorLogger>();
    if (ui_a < ui_b) {
        /* Handle error */
        msg = "Error subtracting";
        loggerformatted->log(msg);
    }
    else {
        udif = ui_a - ui_b;
        return udif;
    }
    /* ... */
}
