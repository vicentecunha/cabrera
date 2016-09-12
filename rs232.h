/*
***************************************************************************
*
* Author: Teunis van Beelen
*
* Copyright (C) 2005, 2006, 2007, 2008, 2009, 2010, 2011, 2012, 2013, 2014, 2015 Teunis van Beelen
*
* Email: teuniz@gmail.com
*
***************************************************************************
*
* This program is free software: you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation, either version 3 of the License, or
* (at your option) any later version.
*
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* GNU General Public License for more details.
*
* You should have received a copy of the GNU General Public License
* along with this program.  If not, see <http://www.gnu.org/licenses/>.
*
***************************************************************************
*/

/* Last revision: December 19, 2015 */

/* For more info and how to use this libray, visit: http://www.teuniz.net/RS-232/ */


#ifndef rs232_INCLUDED
#define rs232_INCLUDED

#ifdef __cplusplus
extern "C" {
#endif

#include <stdio.h>
#include <string.h>



#if defined(__linux__) || defined(__FreeBSD__)

#include <termios.h>
#include <sys/ioctl.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <limits.h>
#include <sys/file.h>

#else

#include <windows.h>

#endif

/*
 * Opens the comport, comportnumber starts with 0 (see the list of numbers).
 * Baudrate is expressed in baud per second i.e 115200 (see the list of possible baudrates).
 * Mode is a string in the form of "8N1", "7E2", etc.
 * 8N1 means eight databits, no parity, one stopbit. If in doubt, use 8N1 (see the list of possible modes).
 * Returns 1 in case of an error.
 */

int RS232_OpenComport(int comport_number, int baudrate, const char *mode);

/*
 * Gets characters from the serial port (if any). Buf is a pointer to a buffer
 * and size the size of the buffer in bytes.
 * Returns the amount of received characters into the buffer.
 * After succesfully opening the COM-port, connect this function to a timer.
 * The timer should have an interval of approx. 100 milliSeconds.
 * Do not forget to stop the timer before closing the COM-port.
 */

int RS232_PollComport(int comport_number, unsigned char *buf, int size);

/*
 * Sends a byte via the serial port. Returns 1 in case of an error.
 */

int RS232_SendByte(int comport_number, unsigned char byte);

/*
 * Sends multiple bytes via the serial port. Buf is a pointer to a buffer
 * and size the size of the buffer in bytes.
 * Returns -1 in case of an error, otherwise it returns the amount of bytes sent.
 * This function blocks (it returns after all the bytes have been processed).
 */

int RS232_SendBuf(int comport_number, unsigned char *buf, int size);

/*
 * Closes the serial port.
 */

void RS232_CloseComport(int comport_number);

/*
 * Sends a string via the serial port. String must be null-terminated.
 */

void RS232_cputs(int comport_number, const char *text);

/*
 * The following functions are normally not needed but can be used to set or check the status of the control-lines:
 */

int RS232_IsDCDEnabled(int comport_number);
int RS232_IsCTSEnabled(int comport_number);
int RS232_IsDSREnabled(int comport_number);
void RS232_enableDTR(int comport_number);
void RS232_disableDTR(int comport_number);
void RS232_enableRTS(int comport_number);
void RS232_disableRTS(int comport_number);
void RS232_flushRX(int comport_number);
void RS232_flushTX(int comport_number);
void RS232_flushRXTX(int comport_number);

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif


