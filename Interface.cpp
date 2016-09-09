/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "Interface_UART.hpp"
#include "Interface.h"

/* 
 * File:   Interface.cpp
 * Author: jchurchwell
 * 
 * Created on August 11, 2016, 8:42 AM
 */
//const char *portname = "/dev/ttyUSB1";


Interface::Interface() {
    
}

Interface::Interface(const char* portname) {
    
    bno055UART = new Interface_UART(portname,B115200,0);
    
}

Interface::Interface(const Interface& orig) {
    
    
}

Interface::~Interface() {
    bno055UART->~Interface_UART();
}

void Interface::Read(u8 *data_rtn, u8 *byte_count)
{    
    bno055UART->read_data(data_rtn, byte_count);    
}

void Interface::Write(u8 *data_out, u8 byte_count)
{   
    bno055UART->flush_buffer();
    bno055UART->write_data(data_out, byte_count);    
    //bno055UART->flush_buffer();
}

