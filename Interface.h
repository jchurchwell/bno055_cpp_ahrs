/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Interface.h
 * Author: jchurchwell
 *
 * Created on August 11, 2016, 8:42 AM
 */
#include "Interface_UART.hpp"
#ifndef INTERFACE_H
#define INTERFACE_H

class Interface {
public:
    Interface();
    Interface(const char* portname);
    Interface(const Interface& orig);
    virtual ~Interface();
    
    void Read(unsigned char *data_rtn, unsigned char *byte_count);
    void Write(unsigned char *data_out, unsigned char byte_count);
    
private:
    Interface_UART *bno055UART;
};

#endif /* INTERFACE_H */

