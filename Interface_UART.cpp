/* 
 * File:   Interface_UART.cpp
 * Author: Joe Churchwell
 *
 * Created on June 23, 2015, 8:46 PM
 */

#include "Interface_UART.h"

int fd;

//Interface_UART::Interface_UART() {
//    
//}

Interface_UART::Interface_UART(const char* portname, int speed, int parity){
    
    //char *portname = "/dev/ttyUSB1";

    fd = open(portname, (O_RDWR | O_NOCTTY | O_SYNC));
    if (fd < 0){
            printf ("error %d opening %s: %s", errno, portname, strerror (errno));
            return;
    }
    
    SetupSerial(fd, 115200, 8, 1, 'N');

    //set_interface_attribs (fd, speed, parity);
    //set_blocking (fd, O_NONBLOCK); // set no blocking      
    
}

Interface_UART::Interface_UART(const Interface_UART& orig) {
}

Interface_UART::~Interface_UART() {
    
    /* Shutdown the file descriptor*/
    close(fd);
}

void Interface_UART::flush_buffer(){
    
    tcflush(fd, TCIOFLUSH);
    
}

s8 Interface_UART::read_data(u8* data_rtn, u8* byte_count){
    
    ssize_t bytes_read;
    
    u8 d0, d1, d2, d3, d4, d5, d6, d7;
    unsigned int mvalues;
    float result;
    
    bytes_read = read(fd, data_rtn, *byte_count); 
    
    d0 = *(data_rtn);
    d1 = *(data_rtn+1);
    d2 = *(data_rtn+2);
    d3 = *(data_rtn+3);
    d4 = *(data_rtn+4);
    d5 = *(data_rtn+5);
    d6 = *(data_rtn+6);
    d7 = *(data_rtn+7);
    
    mvalues = (d3 << 8) + d2;
    result = ((float)mvalues) / 16;
    
    return 0;        
    
}

s8 Interface_UART::write_data(u8* data_out, u8 byte_count){
    
    write(fd, data_out, byte_count); 
    
    return 0;
        
    
}

void Interface_UART::set_blocking(int fd, int should_block){
    
    struct termios tty;
    memset (&tty, 0, sizeof tty);
    if (tcgetattr (fd, &tty) != 0)
    {
            printf ("error %d from tggetattr", errno);
            return;
    }

    tty.c_cc[VMIN]  = should_block ? 1 : 0;
    tty.c_cc[VTIME] = 5;            // 0.5 seconds read timeout

    if (tcsetattr (fd, TCSANOW, &tty) != 0)
            printf ("error %d setting term attributes", errno); 
    
}

/*
	Setup the communication options
	Hopefully POSIX compliant
*/
int Interface_UART::SetupSerial(int fdes,int baud,int databits,int stopbits,int parity)
{
	int n;
	struct termios options; //,options2;

	/* Get the current options */
	if (tcgetattr(fdes,&options) < 0) {
		perror("SetupSerial 1");
		return(FALSE);
	}
	/*
   fprintf(stderr,"iflag - 0%o; oflag - 0%o; cflag - 0%o; lflag - 0%o\n",
      (unsigned int)options.c_iflag,
      (unsigned int)options.c_oflag,
      (unsigned int)options.c_cflag,
      (unsigned int)options.c_lflag);
	*/
	
	/* Set the baud rate */
	switch (baud) {
            case 1200:
               n =  cfsetispeed(&options,B1200);
               n += cfsetospeed(&options,B1200);
               break;
            case 2400:
               n =  cfsetispeed(&options,B2400);
               n += cfsetospeed(&options,B2400);
               break;
                 case 4800:
                         n =  cfsetispeed(&options,B4800);
                         n += cfsetospeed(&options,B4800);
                         break;
                 case 9600:
                         n =  cfsetispeed(&options,B9600);
                         n += cfsetospeed(&options,B9600);
               break;
            case 19200:
               n =  cfsetispeed(&options,B19200);
               n += cfsetospeed(&options,B19200);
               break;
            case 38400:
               n =  cfsetispeed(&options,B38400);
               n += cfsetospeed(&options,B38400);
               break;
            case 57600: // witilt
               n =  cfsetispeed(&options,B57600);
               n += cfsetospeed(&options,B57600);
               break;
            case 115200:
               n =  cfsetispeed(&options,B115200);
               n += cfsetospeed(&options,B115200);
               break;                
            default:
		fprintf(stderr,"Unsupported baud rate\n");
		return(FALSE);
	}
        
	if (n != 0) {
		perror("SetupSerial 2");
		return(FALSE);
	}

   // Set the data size 
   options.c_cflag &= ~CSIZE; // Character size mask
   switch (databits) {
   case 7:
      options.c_cflag |= CS7;
      break;
   case 8:
      options.c_cflag |= CS8;
      break;
   default:
      fprintf(stderr,"Unsupported data size\n");
      return(FALSE);
   }

	// Set parity
	switch (parity) {
	case 'n':
	case 'N':
		options.c_cflag &= ~PARENB; // Clear parity enable
		break;
	case 'o':
	case 'O':
		options.c_cflag |= PARENB; // Parity enable
		options.c_cflag |= PARODD; // Enable odd parity 
		break;
	case 'e':
	case 'E':
		options.c_cflag |= PARENB; // Parity enable
		options.c_cflag &= ~PARODD; // Turn off odd parity = even
		break;
	default:
		fprintf(stderr,"Unsupported parity\n");
		return(FALSE);
	}

	// Set stop bits 
	switch (stopbits) {
	case 1:
		options.c_cflag &= ~CSTOPB; // Not 2 stop bits = One stop bit
		break;
	case 2:
		options.c_cflag |= CSTOPB; // Two stop bits
		break;
	default:
		fprintf(stderr,"Unsupported stop bits\n");
		return(FALSE);
	}

   // Non blocking return immediately with data
   options.c_cc[VMIN] = 0;
   options.c_cc[VTIME] = 0;

   // Local flags
   options.c_lflag = 0;  // No local flags
   options.c_lflag &= ~ICANON; // Don't canonicalise
   options.c_lflag &= ~ECHO; // Don't echo
   options.c_lflag &= ~ECHOK; // Don't echo

   // Control flags
   options.c_cflag &= ~CRTSCTS; // Disable RTS/CTS
   options.c_cflag |= CLOCAL; // Ignore status lines
   options.c_cflag |= CREAD; // Enable receiver
   options.c_cflag |= HUPCL; // Drop DTR on close

   // oflag - output processing
   options.c_oflag &= ~OPOST; // No output processing
   options.c_oflag &= ~ONLCR; // Don't convert linefeeds

   // iflag - input processing
   options.c_iflag |= IGNPAR; // Ignore parity
   options.c_iflag &= ~ISTRIP; // Don't strip high order bit
   options.c_iflag |= IGNBRK; // Ignore break conditions
   options.c_iflag &= ~INLCR; // Don't Map NL to CR
   options.c_iflag &= ~ICRNL; // Don't Map CR to NL
   options.c_iflag |= (IXON | IXOFF | IXANY); // xon/xoff flow control
   
   // options.c_iflag &= ~(IGNBRK | BRKINT | PARMRK | ISTRIP | INLCR | IGNCR | ICRNL | IXON); 
    
    options.c_iflag &= ~(IGNBRK | BRKINT | PARMRK | ISTRIP | INLCR | IGNCR | ICRNL | IXON | IXOFF);
    
	/*
   fprintf(stderr,"iflag - 0%o; oflag - 0%o; cflag - 0%o; lflag - 0%o\n",
      (unsigned int)options.c_iflag,
      (unsigned int)options.c_oflag,
      (unsigned int)options.c_cflag,
      (unsigned int)options.c_lflag);
	*/

	// Update the options and do it NOW 
	if (tcsetattr(fdes,TCSANOW,&options) < 0) {
		perror("SetupSerial 3");
		return(FALSE);
	}

	/* Read the options and check they have "taken"
	if (tcgetattr(fdes,&options2) < 0) {
      perror("SetupSerial 4");
      return(FALSE);
   }
   fprintf(stderr,"iflag - 0%o; oflag - 0%o; cflag - 0%o; lflag - 0%o\n",
      (unsigned int)options.c_iflag,
      (unsigned int)options.c_oflag,
      (unsigned int)options.c_cflag,
      (unsigned int)options.c_lflag);
	if (memcmp((void *)&options,(void *)&options2,sizeof(options)) != 0) {
		perror("SetupSerial 5");
      return(FALSE);
	} */

   // Clear the line 
   tcflush(fdes,TCIFLUSH); 

	return(TRUE);
}


int Interface_UART::set_interface_attribs(int fd, int speed, int parity){
    
    struct termios tty;
    memset (&tty, 0, sizeof tty);
    if (tcgetattr (fd, &tty) != 0)
    {
            printf ("error %d from tcgetattr", errno);
            return -1;
    }

    cfsetospeed (&tty, speed);
    cfsetispeed (&tty, speed);

    tty.c_cflag = (tty.c_cflag & ~CSIZE) | CS8;     // 8-bit chars
    // disable IGNBRK for mismatched speed tests; otherwise receive break
    // as \000 chars
    tty.c_iflag &= ~IGNBRK;         // disable break processing
    
    tty.c_lflag = 0;                // no signaling chars, no echo,
                                    // no canonical processing
    tty.c_lflag &= ~(ICANON | ECHO | ECHOE | ISIG);
    
    
    
    tty.c_oflag = 0;                // no remapping, no delays
    tty.c_cc[VMIN]  = 0;            // read doesn't block
    tty.c_cc[VTIME] = 5;            // 0.5 seconds read timeout

    tty.c_iflag &= ~(IXON | IXOFF | IXANY); // shut off xon/xoff ctrl

    tty.c_cflag |= (CLOCAL | CREAD);// ignore modem controls,
                                    // enable reading
    tty.c_cflag &= ~(PARENB | PARODD);      // shut off parity
    tty.c_cflag |= parity;
    tty.c_cflag &= ~CSTOPB;
    tty.c_cflag &= ~CRTSCTS;

    if (tcsetattr (fd, TCSANOW, &tty) != 0)
    {
            printf ("error %d from tcsetattr", errno);
            return -1;
    }
    
    cfmakeraw(&tty);
    
    return 0;        
    
}