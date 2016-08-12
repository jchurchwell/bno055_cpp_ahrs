/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: jchurchwell
 *
 * Created on August 11, 2016, 8:42 AM
 */

#include <cstdlib>
#include "BNO055.h"
#include <unistd.h>
#include <stdio.h>

using namespace std;

const char *portname = "/dev/ttyS2";

BNO055 *bno055;

/*
 * 
 */
int main(int argc, char** argv) {
    
    bno055 = new BNO055(portname);

    /* structure used to read the euler hrp data */
    struct bno055_euler_t euler_hrp;
    
    /* structure used to read the euler hrp data output as as degree or radians */
    struct bno055_euler_double_t d_euler_hpr;  
    
    // Read the data forever
    while(1){
        bno055->bno055_read_euler_hrp(&euler_hrp);    
        bno055->bno055_convert_double_euler_hpr_deg(&d_euler_hpr);
        fflush(stdout);
        printf("%3.4f, %3.4f, %3.4f\r", d_euler_hpr.h, d_euler_hpr.p, d_euler_hpr.r);
    }

    return 0;
}

