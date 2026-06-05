/*
 * DIO_Interface.h
 *
 *  Created on: Aug 10, 2025
 *      Author: areej
 */

#ifndef DIO_INTERFACE_H_
#define DIO_INTERFACE_H_



#define NUM_OF_PORTS           4
#define NUM_OF_PINS_PER_PORT   8


#define PORTA_ID               0
#define PORTB_ID               1
#define PORTC_ID               2
#define PORTD_ID               3

#define PIN0_ID                0
#define PIN1_ID                1
#define PIN2_ID                2
#define PIN3_ID                3
#define PIN4_ID                4
#define PIN5_ID                5
#define PIN6_ID                6
#define PIN7_ID                7




//Other macros
#define LOW        0
#define HIGH       1

#define INPUT      0
#define OUTPUT     1



/*******************************************************************************
 *                               Types Declaration                             *
 *******************************************************************************/

typedef enum
{
	PIN_INPUT,PIN_OUTPUT
}GPIO_PinDirectionType;

typedef enum
{
	PORT_INPUT,PORT_OUTPUT=0xFF
}GPIO_PortDirectionType;




// dealing with pins
void DIO_u8SetPinDirection(u8 port_num, u8 pin_num, GPIO_PinDirectionType direction);
void DIO_u8SetPinValue(u8 port_num, u8 pin_num, u8 value);
u8 DIO_u8GetPinValue(u8 port_num, u8 pin_num);

//dealing with ports
void DIO_u8SetPortDirection(u8 port_num, GPIO_PortDirectionType direction);
void DIO_u8SetPortValue(u8 port_num, u8 value);
u8 DIO_u8GetPortValue(u8 port_num);



#endif /* DIO_INTERFACE_H_ */
