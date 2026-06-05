/*
 * DIO_Program.c
 *
 *  Created on: Aug 10, 2025
 *      Author: areej
 */

//LIB includes
#include "STD_TYPES.h"
#include "BIT_MATH.h"


//MCAL includes
#include "DIO_Interface.h"
#include "DIO_Private.h"
#include "avr/io.h" /* To use the IO Ports Registers */


void DIO_u8SetPinDirection(u8 port_num, u8 pin_num, GPIO_PinDirectionType direction)
{
	/*
		 * Check if the input port number is greater than NUM_OF_PINS_PER_PORT value.
		 * Or if the input pin number is greater than NUM_OF_PINS_PER_PORT value.
		 * In this case the input is not valid port/pin number
		 */
		if((pin_num >= NUM_OF_PINS_PER_PORT) || (port_num >= NUM_OF_PORTS))
		{
			/* Do Nothing */
		}
		else
		{
			/* Setup the pin direction as required */
			switch(port_num)
			{
			case PORTA_ID:
				if(direction == PIN_OUTPUT)
				{
					SET_BIT(DDRA,pin_num);
				}
				else
				{
					CLR_BIT(DDRA,pin_num);
				}
				break;
			case PORTB_ID:
				if(direction == PIN_OUTPUT)
				{
					SET_BIT(DDRB,pin_num);
				}
				else
				{
					CLR_BIT(DDRB,pin_num);
				}
				break;
			case PORTC_ID:
				if(direction == PIN_OUTPUT)
				{
					SET_BIT(DDRC,pin_num);
				}
				else
				{
					CLR_BIT(DDRC,pin_num);
				}
				break;
			case PORTD_ID:
				if(direction == PIN_OUTPUT)
				{
					SET_BIT(DDRD,pin_num);
				}
				else
				{
					CLR_BIT(DDRD,pin_num);
				}
				break;
			}
		}
}


void DIO_u8SetPinValue(u8 port_num, u8 pin_num, u8 value)
{
	/*
	 * Check if the input port number is greater than NUM_OF_PINS_PER_PORT value.
	 * Or if the input pin number is greater than NUM_OF_PINS_PER_PORT value.
	 * In this case the input is not valid port/pin number
	 */
	if((pin_num >= NUM_OF_PINS_PER_PORT) || (port_num >= NUM_OF_PORTS))
	{
		/* Do Nothing */
	}
	else
	{
		/* Write the pin value as required */
		switch(port_num)
		{
		case PORTA_ID:
			if(value == HIGH)
			{
				SET_BIT(PORTA,pin_num);
			}
			else
			{
				CLR_BIT(PORTA,pin_num);
			}
			break;
		case PORTB_ID:
			if(value == HIGH)
			{
				SET_BIT(PORTB,pin_num);
			}
			else
			{
				CLR_BIT(PORTB,pin_num);
			}
			break;
		case PORTC_ID:
			if(value == HIGH)
			{
				SET_BIT(PORTC,pin_num);
			}
			else
			{
				CLR_BIT(PORTC,pin_num);
			}
			break;
		case PORTD_ID:
			if(value == HIGH)
			{
				SET_BIT(PORTD,pin_num);
			}
			else
			{
				CLR_BIT(PORTD,pin_num);
			}
			break;
		}
	}
}


u8 DIO_u8GetPinValue(u8 port_num, u8 pin_num)
{
	u8 pin_value = LOW;

	/*
	 * Check if the input port number is greater than NUM_OF_PINS_PER_PORT value.
	 * Or if the input pin number is greater than NUM_OF_PINS_PER_PORT value.
	 * In this case the input is not valid port/pin number
	 */
	if((pin_num >= NUM_OF_PINS_PER_PORT) || (port_num >= NUM_OF_PORTS))
	{
		/* Do Nothing */
	}
	else
	{
		/* Read the pin value as required */
		switch(port_num)
		{
		case PORTA_ID:
			if(BIT_IS_SET(PINA,pin_num))
			{
				pin_value = HIGH;
			}
			else
			{
				pin_value = LOW;
			}
			break;
		case PORTB_ID:
			if(BIT_IS_SET(PINB,pin_num))
			{
				pin_value = HIGH;
			}
			else
			{
				pin_value = LOW;
			}
			break;
		case PORTC_ID:
			if(BIT_IS_SET(PINC,pin_num))
			{
				pin_value = HIGH;
			}
			else
			{
				pin_value = LOW;
			}
			break;
		case PORTD_ID:
			if(BIT_IS_SET(PIND,pin_num))
			{
				pin_value = HIGH;
			}
			else
			{
				pin_value = LOW;
			}
			break;
		}
	}

	return pin_value;
}


void DIO_u8SetPortDirection(u8 port_num, GPIO_PortDirectionType direction)
{
	/*
	 * Check if the input number is greater than NUM_OF_PORTS value.
	 * In this case the input is not valid port number
	 */
	if(port_num >= NUM_OF_PORTS)
	{
		/* Do Nothing */
	}
	else
	{
		/* Setup the port direction as required */
		switch(port_num)
		{
		case PORTA_ID:
			DDRA = direction;
			break;
		case PORTB_ID:
			DDRB = direction;
			break;
		case PORTC_ID:
			DDRC = direction;
			break;
		case PORTD_ID:
			DDRD = direction;
			break;
		}
	}
}


void DIO_u8SetPortValue(u8 port_num, u8 value)
{
	/*
	 * Check if the input number is greater than NUM_OF_PORTS value.
	 * In this case the input is not valid port number
	 */
	if(port_num >= NUM_OF_PORTS)
	{
		/* Do Nothing */
	}
	else
	{
		/* Write the port value as required */
		switch(port_num)
		{
		case PORTA_ID:
			PORTA = value;
			break;
		case PORTB_ID:
			PORTB = value;
			break;
		case PORTC_ID:
			PORTC = value;
			break;
		case PORTD_ID:
			PORTD = value;
			break;
		}
	}
}

/*
 * Description :
 * Read and return the value of the required port.
 * If the input port number is not correct, The function will return ZERO value.
 */

u8 DIO_u8GetPortValue(u8 port_num)
{
	u8 value = LOW;

	/*
	 * Check if the input number is greater than NUM_OF_PORTS value.
	 * In this case the input is not valid port number
	 */
	if(port_num >= NUM_OF_PORTS)
	{
		/* Do Nothing */
	}
	else
	{
		/* Read the port value as required */
		switch(port_num)
		{
		case PORTA_ID:
			value = PINA;
			break;
		case PORTB_ID:
			value = PINB;
			break;
		case PORTC_ID:
			value = PINC;
			break;
		case PORTD_ID:
			value = PIND;
			break;
		}
	}

	return value;
}
