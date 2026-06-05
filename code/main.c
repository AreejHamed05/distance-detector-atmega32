#include <avr/io.h> /* To use the SREG register */
#include <util/delay.h> /* To use the delay function */
#include "Ultrasonic.h"
#include "LCD_Interface.h"

int main(void) {
    LCD_init();
    SREG |= (1 << 7); // Enable interrupts
    Ultrasonic_init();

    // Static labels (never overwritten)
    LCD_displayStringRowColumn(0, 0, "Distance = "); // Line 1
    LCD_displayStringRowColumn(1, 14, "cm");         // "cm" on Line 2, positions 14-15

    while (1) {
        float distance = Ultrasonic_readDistance();

        // Display distance at Line 1, positions 11-13 (e.g., "25.3")
        LCD_moveCursor(0, 11);
        LCD_floatToString(distance); // Forces 1 decimal place

        _delay_ms(100); // Adjust refresh rate
    }
}
