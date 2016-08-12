/* 
 * File:   Interface_UART.hpp
 * Author: Joe Churchwell
 *
 * Created on June 23, 2015, 8:46 PM
 */

#ifndef INTERFACE_UART_HPP
#define	INTERFACE_UART_HPP

#define TRUE 1
#define FALSE 0


#include <errno.h>
#include <termios.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>

typedef unsigned char u8;
typedef signed   char s8;

class Interface_UART {
    
    int SetupSerial(int fdes,int baud,int databits,int stopbits,int parity);
    
public:
    Interface_UART();
    Interface_UART(const Interface_UART& orig);
    Interface_UART(const char *portname, int speed, int parity);
    virtual ~Interface_UART();
    
    void flush_buffer(void);
    signed char read_data(u8 *data_rtn, u8 *byte_count);
    signed char write_data(u8 *data_out, u8 byte_count);        
    
private:
    
    void set_blocking (int fd, int should_block);
    int set_interface_attribs (int fd, int speed, int parity);

};


#endif	/* INTERFACE_UART_HPP */
