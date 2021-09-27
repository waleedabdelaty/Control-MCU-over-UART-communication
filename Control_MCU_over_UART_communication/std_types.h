/*
 * std_types.h
 *
 *  Created on: Sep 27, 2021
 *      Author: TOSHIBA PC
 */


#ifndef STD_TYPES_H_
#define STD_TYPES_H_

#include <stdint.h>

/* Boolean Data Type */
typedef unsigned char bool;

/* Boolean Values */
#ifndef FALSE
#define FALSE       (0u)
#endif

#ifndef TRUE
#define TRUE        (1u)
#endif

#define HIGH        (1u)
#define LOW         (0u)
#define NULL_PTR    ((void*)0)


#endif /* STD_TYPES_H_ */
