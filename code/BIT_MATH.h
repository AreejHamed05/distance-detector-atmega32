/*
 * BIT_MATH.h
 *
 *  Created on: Aug 10, 2025
 *      Author: areej
 */

#ifndef BIT_MATH_H_
#define BIT_MATH_H_

#define SET_BIT(REG,BitNo)              REG |= (1<<BitNo)
#define CLR_BIT(REG,BitNo)              REG &= ~(1<<BitNo)
#define ASS_BIT(REG,BitNo,VAL)          (VAL==0)? CLR_BIT(REG,BitNo) : SET_BIT(REG,BitNo)
#define TOG_BIT(REG,BitNo)              REG ^= (1<<BitNo)
#define GET_BIT(REG,BitNo)              ((REG>>BitNo) & 0x01)

#define BIT_IS_SET(REG,BIT) ( REG & (1<<BIT) )



#endif /* BIT_MATH_H_ */
