/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   BNO055.h
 * Author: jchurchwell
 *
 * Created on August 11, 2016, 9:02 AM
 */
#include "Interface.h"

#ifndef BNO055_H
#define BNO055_H

/****************************************************************/
/**\name	DATA TYPES INCLUDES		*/
/************************************************************/
/*!
* @brief The following definition uses for define the data types
*
* @note While porting the API please consider the following
* @note Please check the version of C standard
* @note Are you using Linux platform
*/

/*!
* @brief For the Linux platform support
* Please use the types.h for your data types definitions
*/
#ifdef	__KERNEL__

#include <linux/types.h>
/* singed integer type*/
typedef	int8_t s8;/**< used for signed 8bit */
typedef	int16_t s16;/**< used for signed 16bit */
typedef	int32_t s32;/**< used for signed 32bit */
typedef	int64_t s64;/**< used for signed 64bit */

typedef	u_int8_t u8;/**< used for unsigned 8bit */
typedef	u_int16_t u16;/**< used for unsigned 16bit */
typedef	u_int32_t u32;/**< used for unsigned 32bit */
typedef	u_int64_t u64;/**< used for unsigned 64bit */



#else /* ! __KERNEL__ */
/**********************************************************
* These definition uses for define the C
* standard version data types
***********************************************************/
# if !defined(__STDC_VERSION__)

/************************************************
 * compiler is C11 C standard
************************************************/
#if (__STDC_VERSION__ == 201112L)

/************************************************/
#include <stdint.h>
/************************************************/

/*unsigned integer types*/
typedef	uint8_t u8;/**< used for unsigned 8bit */
typedef	uint16_t u16;/**< used for unsigned 16bit */
typedef	uint32_t u32;/**< used for unsigned 32bit */
typedef	uint64_t u64;/**< used for unsigned 64bit */

/*signed integer types*/
typedef	int8_t s8;/**< used for signed 8bit */
typedef	int16_t s16;/**< used for signed 16bit */
typedef	int32_t s32;/**< used for signed 32bit */
typedef	int64_t s64;/**< used for signed 64bit */
/************************************************
 * compiler is C99 C standard
************************************************/

#elif (__STDC_VERSION__ == 199901L)

/* stdint.h is a C99 supported c library.
which is used to fixed the integer size*/
/************************************************/
#include <stdint.h>
/************************************************/

/*unsigned integer types*/
typedef	uint8_t u8;/**< used for unsigned 8bit */
typedef	uint16_t u16;/**< used for unsigned 16bit */
typedef	uint32_t u32;/**< used for unsigned 32bit */
typedef	uint64_t u64;/**< used for unsigned 64bit */

/*signed integer types*/
typedef int8_t s8;/**< used for signed 8bit */
typedef	int16_t s16;/**< used for signed 16bit */
typedef	int32_t s32;/**< used for signed 32bit */
typedef	int64_t s64;/**< used for signed 64bit */
/************************************************
 * compiler is C89 or other C standard
************************************************/

#else /*  !defined(__STDC_VERSION__) */
/*!
* @brief By default it is defined as 32 bit machine configuration
*	define your data types based on your
*	machine/compiler/controller configuration
*/
#define  MACHINE_32_BIT

/*! @brief
 *	If your machine support 16 bit
 *	define the MACHINE_16_BIT
 */
#ifdef MACHINE_16_BIT
#include <limits.h>
/*signed integer types*/
typedef	signed char  s8;/**< used for signed 8bit */
typedef	signed short int s16;/**< used for signed 16bit */
typedef	signed long int s32;/**< used for signed 32bit */

#if defined(LONG_MAX) && LONG_MAX == 0x7fffffffffffffffL
typedef long int s64;/**< used for signed 64bit */
typedef unsigned long int u64;/**< used for unsigned 64bit */
#elif defined(LLONG_MAX) && (LLONG_MAX == 0x7fffffffffffffffLL)
typedef long long int s64;/**< used for signed 64bit */
typedef unsigned long long int u64;/**< used for unsigned 64bit */
#else
#warning Either the correct data type for signed 64 bit integer \
could not be found, or 64 bit integers are not supported in your environment.
#warning If 64 bit integers are supported on your platform, \
please set s64 manually.
#endif

/*unsigned integer types*/
typedef	unsigned char u8;/**< used for unsigned 8bit */
typedef	unsigned short int u16;/**< used for unsigned 16bit */
typedef	unsigned long int u32;/**< used for unsigned 32bit */

/* If your machine support 32 bit
define the MACHINE_32_BIT*/
#elif defined MACHINE_32_BIT
/*signed integer types*/
typedef	signed char  s8;/**< used for signed 8bit */
typedef	signed short int s16;/**< used for signed 16bit */
typedef	signed int s32;/**< used for signed 32bit */
typedef	signed long long int s64;/**< used for signed 64bit */

/*unsigned integer types*/
typedef	unsigned char u8;/**< used for unsigned 8bit */
typedef	unsigned short int u16;/**< used for unsigned 16bit */
typedef	unsigned int u32;/**< used for unsigned 32bit */
typedef	unsigned long long int u64;/**< used for unsigned 64bit */

/* If your machine support 64 bit
define the MACHINE_64_BIT*/
#elif defined MACHINE_64_BIT
/*signed integer types*/
typedef	signed char  s8;/**< used for signed 8bit */
typedef	signed short int s16;/**< used for signed 16bit */
typedef	signed int s32;/**< used for signed 32bit */
typedef	signed long int s64;/**< used for signed 64bit */

/*unsigned integer types*/
typedef	unsigned char u8;/**< used for unsigned 8bit */
typedef	unsigned short int u16;/**< used for unsigned 16bit */
typedef	unsigned int u32;/**< used for unsigned 32bit */
typedef	unsigned long int u64;/**< used for unsigned 64bit */

#else
#warning The data types defined above which not supported \
define the data types manually
#endif
#endif

/*** This else will execute for the compilers
 *	which are not supported the C standards
 *	Like C89/C99/C11***/
#else
/*!
* @brief By default it is defined as 32 bit machine configuration
*	define your data types based on your
*	machine/compiler/controller configuration
*/
#define  MACHINE_32_BIT

/* If your machine support 16 bit
define the MACHINE_16_BIT*/
#ifdef MACHINE_16_BIT
#include <limits.h>
/*signed integer types*/
typedef	signed char  s8;/**< used for signed 8bit */
typedef	signed short int s16;/**< used for signed 16bit */
typedef	signed long int s32;/**< used for signed 32bit */

#if defined(LONG_MAX) && LONG_MAX == 0x7fffffffffffffffL
typedef long int s64;/**< used for signed 64bit */
typedef unsigned long int u64;/**< used for unsigned 64bit */
#elif defined(LLONG_MAX) && (LLONG_MAX == 0x7fffffffffffffffLL)
typedef long long int s64;/**< used for signed 64bit */
typedef unsigned long long int u64;/**< used for unsigned 64bit */
#else
#warning Either the correct data type for signed 64 bit integer \
could not be found, or 64 bit integers are not supported in your environment.
#warning If 64 bit integers are supported on your platform, \
please set s64 manually.
#endif

/*unsigned integer types*/
typedef	unsigned char u8;/**< used for unsigned 8bit */
typedef	unsigned short int u16;/**< used for unsigned 16bit */
typedef	unsigned long int u32;/**< used for unsigned 32bit */

/*! @brief If your machine support 32 bit
define the MACHINE_32_BIT*/
#elif defined MACHINE_32_BIT
/*signed integer types*/
typedef	signed char  s8;/**< used for signed 8bit */
typedef	signed short int s16;/**< used for signed 16bit */
typedef	signed int s32;/**< used for signed 32bit */
typedef	signed long long int s64;/**< used for signed 64bit */

/*unsigned integer types*/
typedef	unsigned char u8;/**< used for unsigned 8bit */
typedef	unsigned short int u16;/**< used for unsigned 16bit */
typedef	unsigned int u32;/**< used for unsigned 32bit */
typedef	unsigned long long int u64;/**< used for unsigned 64bit */

/* If your machine support 64 bit
define the MACHINE_64_BIT*/
#elif defined MACHINE_64_BIT
/*signed integer types*/
typedef	signed char  s8;/**< used for signed 8bit */
typedef	signed short int s16;/**< used for signed 16bit */
typedef	signed int s32;/**< used for signed 32bit */
typedef	signed long int s64;/**< used for signed 64bit */

/*unsigned integer types*/
typedef	unsigned char u8;/**< used for unsigned 8bit */
typedef	unsigned short int u16;/**< used for unsigned 16bit */
typedef	unsigned int u32;/**< used for unsigned 32bit */
typedef	unsigned long int u64;/**< used for unsigned 64bit */

#else
#warning The data types defined above which not supported \
define the data types manually
#endif
#endif
#endif

/***************************************************/
/**\name	CONSTANT DEFINITIONS                   */
/***************************************************/
#define         BNO055_ZERO_U8X           ((u8)0)
#define         BNO055_ONE_U8X           ((u8)1)
#define         BNO055_TWO_U8X			  ((u8)2)
#define         BNO055_FOUR_U8X           ((u8)4)
#define         BNO055_FIVE_U8X           ((u8)5)
#define         BNO055_SIX_U8X            ((u8)6)
#define         BNO055_SEVEN_U8X          ((u8)7)
#define         BNO055_ELEVEN_U8X         ((u8)11)
#define         BNO055_SIXTEEN_U8X        ((u8)16)
#define			BNO055_EIGHT_U8X		  ((u8)8)
#define			BNO055_TWENTY_U8X         ((u8)20)
#define			BNO055_EIGHTEEN_U8X       ((u8)18)


#define         BNO055_SHIFT_8_POSITION	   ((u8)8)


/*  BNO055 API error codes */
#define E_NULL_PTR                  ((s8)-127)
#define E_BNO055_OUT_OF_RANGE       ((s8)-2)
#define	SUCCESS						((u8)0)
#define	ERROR						((s8)-1)

/* Selection for bit enable and disable */
#define ENABLED		0x01
#define DISABLED	0x00

/* Page ID */
#define PAGE_ZERO		0X00
#define PAGE_ONE		0X01

/* Enable the temperature source */
#define	ACCEL_TEMP_EN	0x00
#define	GYRO_TEMP_EN	0x01
#define	MCU_TEMP_EN		0x03

/*Accel unit*/
#define ACCEL_UNIT_MSQ	0x00
#define ACCEL_UNIT_MG	0x01

/*Gyro unit*/
#define GYRO_UNIT_DPS	0x00
#define GYRO_UNIT_RPS	0x01

/* Euler unit*/
#define EULER_UNIT_DEG	0x00
#define EULER_UNIT_RAD	0x01

/*Temperature unit*/
#define TEMP_UNIT_CELSIUS		0x00
#define TEMP_UNIT_FAHRENHEIT	0x01

/*Accel division factor*/
#define	ACCEL_DIV_MSQ	100.0
#define	ACCEL_DIV_MG	1

/*Mag division factor*/
#define MAG_DIV_UT	16.0

/*Gyro division factor*/
#define GYRO_DIV_DPS		16.0
#define GYRO_DIV_RPS		900.0

/*Euler division factor*/
#define EULER_DIV_DEG		16.0
#define EULER_DIV_RAD		900.0

/*Linear accel division factor*/
#define	LINEAR_ACCEL_DIV_MSQ	100.0

/*Gravity accel division factor*/
#define	GRAVITY_DIV_MSQ	100.0

/* Temperature division factor*/
#define TEMP_DIV_FAHRENHEIT	0.5
#define TEMP_DIV_CELSIUS	1

#define	BNO055_SIX_HUNDRES_U8X	600



/* Operation mode settings*/
#define OPERATION_MODE_CONFIG			0X00
#define OPERATION_MODE_ACCONLY			0X01
#define OPERATION_MODE_MAGONLY			0X02
#define OPERATION_MODE_GYRONLY			0X03
#define OPERATION_MODE_ACCMAG			0X04
#define OPERATION_MODE_ACCGYRO			0X05
#define OPERATION_MODE_MAGGYRO			0X06
#define OPERATION_MODE_AMG			0X07
#define OPERATION_MODE_IMUPLUS			0X08
#define OPERATION_MODE_COMPASS			0X09
#define OPERATION_MODE_M4G			0X0A
#define OPERATION_MODE_NDOF_FMC_OFF		0X0B
#define OPERATION_MODE_NDOF		        0X0C

/* Power mode*/
#define POWER_MODE_NORMAL	0X00
#define POWER_MODE_LOWPOWER	0X01
#define POWER_MODE_SUSPEND	0X02

/* PAGE-1 definitions*/
/* Accel Range */

#define ACCEL_RANGE_2G		0X00
#define ACCEL_RANGE_4G		0X01
#define ACCEL_RANGE_8G		0X02
#define ACCEL_RANGE_16G		0X03

/* Accel Bandwidth*/
#define ACCEL_BW_7_81HZ		0x00
#define ACCEL_BW_15_63HZ	0x01
#define ACCEL_BW_31_25HZ	0x02
#define ACCEL_BW_62_5HZ		0X03
#define ACCEL_BW_125HZ		0X04
#define ACCEL_BW_250HZ		0X05
#define ACCEL_BW_500HZ		0X06
#define ACCEL_BW_1000HZ		0X07

/* Accel Power mode*/
#define ACCEL_NORMAL			0X00
#define ACCEL_SUSPEND			0X01
#define ACCEL_LOWPOWER_1		0X02
#define ACCEL_STANDBY			0X03
#define ACCEL_LOWPOWER_2		0X04
#define ACCEL_DEEPSUSPEND		0X05

/* Mag data output rate*/
#define MAG_DATA_OUTRATE_2HZ		0X00
#define MAG_DATA_OUTRATE_6HZ		0X01
#define MAG_DATA_OUTRATE_8HZ		0X02
#define MAG_DATA_OUTRATE_10HZ		0X03
#define MAG_DATA_OUTRATE_15HZ		0X04
#define MAG_DATA_OUTRATE_20HZ		0X05
#define MAG_DATA_OUTRATE_25HZ		0X06
#define MAG_DATA_OUTRATE_30HZ		0X07

/* Mag Operation mode*/
#define MAG_OPERATION_MODE_LOWPOWER				0X00
#define MAG_OPERATION_MODE_REGULAR				0X01
#define MAG_OPERATION_MODE_ENHANCED_REGULAR		0X02
#define MAG_OPERATION_MODE_HIGH_ACCURACY		0X03

/* Mag power mode*/
#define MAG_POWER_MODE_NORMAL					0X00
#define MAG_POWER_MODE_SLEEP					0X01
#define MAG_POWER_MODE_SUSPEND					0X02
#define MAG_POWER_MODE_FORCE_MODE				0X03

/* Gyro range*/
#define GYRO_RANGE_2000DPS		0x00
#define GYRO_RANGE_1000DPS		0x01
#define GYRO_RANGE_500DPS		0x02
#define GYRO_RANGE_250DPS		0x03
#define GYRO_RANGE_125DPS		0x04

/* Gyro Bandwidth*/
#define GYRO_BW_523HZ		0x00
#define GYRO_BW_230HZ		0x01
#define GYRO_BW_116HZ		0x02
#define GYRO_BW_47HZ		0x03
#define GYRO_BW_23HZ		0x04
#define GYRO_BW_12HZ		0x05
#define GYRO_BW_64HZ		0x06
#define GYRO_BW_32HZ		0x07

/* Gyro power mode*/
#define GYRO_POWER_MODE_NORMAL				0X00
#define GYRO_POWER_MODE_FASTPOWERUP			0X01
#define GYRO_POWER_MODE_DEEPSUSPEND			0X02
#define GYRO_POWER_MODE_SUSPEND				0X03
#define GYRO_POWER_MODE_ADVANCE_POWERSAVE	0X04

/* Accel Sleep Duration */
#define BNO055_ACCEL_SLEEP_DURN_0_5MS        0x05
/* sets sleep duration to 0.5 ms  */
#define BNO055_ACCEL_SLEEP_DURN_1MS          0x06
/* sets sleep duration to 1 ms */
#define BNO055_ACCEL_SLEEP_DURN_2MS          0x07
/* sets sleep duration to 2 ms */
#define BNO055_ACCEL_SLEEP_DURN_4MS          0x08
/* sets sleep duration to 4 ms */
#define BNO055_ACCEL_SLEEP_DURN_6MS          0x09
/* sets sleep duration to 6 ms*/
#define BNO055_ACCEL_SLEEP_DURN_10MS         0x0A
/* sets sleep duration to 10 ms */
#define BNO055_ACCEL_SLEEP_DURN_25MS         0x0B
 /* sets sleep duration to 25 ms */
#define BNO055_ACCEL_SLEEP_DURN_50MS         0x0C
 /* sets sleep duration to 50 ms */
#define BNO055_ACCEL_SLEEP_DURN_100MS        0x0D
 /* sets sleep duration to 100 ms */
#define BNO055_ACCEL_SLEEP_DURN_500MS        0x0E
 /* sets sleep duration to 500 ms */
#define BNO055_ACCEL_SLEEP_DURN_1S           0x0F
/* sets sleep duration to 1 s */

/* Gyro Auto sleep duration*/
#define BNO055_GYRO_No_AUTOSLPDUR		0x00
#define	BNO055_GYRO_4MS_AUTOSLPDUR		0x01
#define	BNO055_GYRO_5MS_AUTOSLPDUR		0x02
#define	BNO055_GYRO_8MS_AUTOSLPDUR		0x03
#define	BNO055_GYRO_10MS_AUTOSLPDUR		0x04
#define	BNO055_GYRO_15MS_AUTOSLPDUR		0x05
#define	BNO055_GYRO_20MS_AUTOSLPDUR		0x06
#define	BNO055_GYRO_40MS_AUTOSLPDUR		0x07

/* Accel Any/No motion axis selection*/
#define BNO055_ACCEL_ANY_MOTION_NO_MOTION_X_AXIS		0
#define BNO055_ACCEL_ANY_MOTION_NO_MOTION_Y_AXIS		1
#define BNO055_ACCEL_ANY_MOTION_NO_MOTION_Z_AXIS		2

/* Accel High g axis selection*/
#define BNO055_ACCEL_HIGH_G_X_AXIS		0
#define BNO055_ACCEL_HIGH_G_Y_AXIS		1
#define BNO055_ACCEL_HIGH_G_Z_AXIS		2

/* Gyro Any motion axis selection*/
#define BNO055_GYRO_ANY_MOTION_X_AXIS		0
#define BNO055_GYRO_ANY_MOTION_Y_AXIS		1
#define BNO055_GYRO_ANY_MOTION_Z_AXIS		2


/* Gyro High rate axis selection*/
#define BNO055_GYRO_HIGHRATE_X_AXIS		0
#define BNO055_GYRO_HIGHRATE_Y_AXIS		1
#define BNO055_GYRO_HIGHRATE_Z_AXIS		2

/* Axis remap values*/
#define REMAP_X_Y			0X21
#define REMAP_Y_Z			0X18
#define REMAP_Z_X			0X06
#define REMAP_X_Y_Z_TYPE0	0X12
#define REMAP_X_Y_Z_TYPE1	0X09
#define DEFAULT_AXIS		0X24

/* Axis remap sign */
#define	REMAP_AXIS_POSITIVE	0X00
#define	REMAP_AXIS_NEGATIVE	0X01

/* Gyro anymotion and high rate filter configuration */
#define	FILTERED	0x00
#define	UNFILTERED	0x01

/* mask definitions*/
#define BNO055_SIC_HEX_0_0_F_F_DATA		0x00FF
/****************************************************/
/**\name	ARRAY SIZE DEFINITIONS      */
/***************************************************/
#define ARRAY_SIZE_TWO		2
#define ARRAY_SIZE_THREE	3
#define ARRAY_SIZE_SIX		6
#define ARRAY_SIZE_FIVE		5
#define ARRAY_SIZE_EIGHT	8
#define ARRAY_SIZE_TWELVE	12
#define ARRAY_SIZE_FOURTEEN	14
#define ARRAY_SIZE_EIGHTEEN	18
#define ARRAY_SIZE_TWENTY_SIX	26

#define INDEX_ZERO		0
#define INDEX_ONE		1
#define INDEX_TWO		2
#define INDEX_THREE		3
#define INDEX_FOUR		4
#define INDEX_FIVE		5
#define INDEX_SIX		6
#define INDEX_SEVEN		7
#define INDEX_EIGHT		8
#define INDEX_NINE		9
#define INDEX_TEN		10
#define INDEX_ELEVEN	11
#define INDEX_TWELVE	12
#define INDEX_THIRTEEN	13
#define INDEX_FOURTEEN	14
#define INDEX_FIVETEEN	15
#define INDEX_SIXTEEN	16
#define INDEX_SEVENTEEN	17
#define INDEX_EIGHTEEN	18
#define INDEX_NINETEEN	19
#define INDEX_TWENTY	20
#define INDEX_TWENTY_ONE	21
#define INDEX_TWENTY_TWO	22
#define INDEX_TWENTY_THREE	23
#define INDEX_TWENTY_FIVE	25
/****************************************************/
/**\name	ARRAY PARAMETERS      */
/***************************************************/
#define LSB_ZERO	0
#define MSB_ONE		1
#define LSB_TWO		2
#define MSB_THREE	3
#define LSB_FOUR	4
#define MSB_FIVE	5
#define LSB_SIX		6
#define MSB_SEVEN	7
/*********************************************************/
/**\name PAGE0 DATA REGISTERS DEFINITION */
/*********************************************************/
/* Chip ID */
#define BNO055_CHIP_ID__POS             0
#define BNO055_CHIP_ID__MSK             0xFF
#define BNO055_CHIP_ID__LEN             8
#define BNO055_CHIP_ID__REG             BNO055_CHIP_ID_ADDR

/* Accel revision id*/
#define BNO055_ACCEL_REV_ID__POS             0
#define BNO055_ACCEL_REV_ID__MSK             0xFF
#define BNO055_ACCEL_REV_ID__LEN             8
#define BNO055_ACCEL_REV_ID__REG             BNO055_ACCEL_REV_ID_ADDR

/* Mag revision id*/
#define BNO055_MAG_REV_ID__POS             0
#define BNO055_MAG_REV_ID__MSK             0xFF
#define BNO055_MAG_REV_ID__LEN             8
#define BNO055_MAG_REV_ID__REG             BNO055_MAG_REV_ID_ADDR

/* Gyro revision id*/
#define BNO055_GYRO_REV_ID__POS             0
#define BNO055_GYRO_REV_ID__MSK             0xFF
#define BNO055_GYRO_REV_ID__LEN             8
#define BNO055_GYRO_REV_ID__REG             BNO055_GYRO_REV_ID_ADDR

/*Software revision id LSB*/
#define BNO055_SW_REV_ID_LSB__POS             0
#define BNO055_SW_REV_ID_LSB__MSK             0xFF
#define BNO055_SW_REV_ID_LSB__LEN             8
#define BNO055_SW_REV_ID_LSB__REG             BNO055_SW_REV_ID_LSB_ADDR

/*Software revision id MSB*/
#define BNO055_SW_REV_ID_MSB__POS             0
#define BNO055_SW_REV_ID_MSB__MSK             0xFF
#define BNO055_SW_REV_ID_MSB__LEN             8
#define BNO055_SW_REV_ID_MSB__REG             BNO055_SW_REV_ID_MSB_ADDR

/* BOOTLODER revision id*/
#define BNO055_BL_REV_ID__POS             0
#define BNO055_BL_REV_ID__MSK             0xFF
#define BNO055_BL_REV_ID__LEN             8
#define BNO055_BL_REV_ID__REG             BNO055_BL_REV_ID_ADDR

/*Page id*/
#define BNO055_PAGE_ID__POS             0
#define BNO055_PAGE_ID__MSK             0xFF
#define BNO055_PAGE_ID__LEN             8
#define BNO055_PAGE_ID__REG             BNO055_PAGE_ID_ADDR

/* Accel data X-LSB register*/
#define BNO055_ACCEL_DATA_X_LSB_VALUEX__POS             0
#define BNO055_ACCEL_DATA_X_LSB_VALUEX__MSK             0xFF
#define BNO055_ACCEL_DATA_X_LSB_VALUEX__LEN             8
#define BNO055_ACCEL_DATA_X_LSB_VALUEX__REG             \
BNO055_ACCEL_DATA_X_LSB_ADDR

/* Accel data X-MSB register*/
#define BNO055_ACCEL_DATA_X_MSB_VALUEX__POS             0
#define BNO055_ACCEL_DATA_X_MSB_VALUEX__MSK             0xFF
#define BNO055_ACCEL_DATA_X_MSB_VALUEX__LEN             8
#define BNO055_ACCEL_DATA_X_MSB_VALUEX__REG             \
BNO055_ACCEL_DATA_X_MSB_ADDR

/* Accel data Y-LSB register*/
#define BNO055_ACCEL_DATA_Y_LSB_VALUEY__POS             0
#define BNO055_ACCEL_DATA_Y_LSB_VALUEY__MSK             0xFF
#define BNO055_ACCEL_DATA_Y_LSB_VALUEY__LEN             8
#define BNO055_ACCEL_DATA_Y_LSB_VALUEY__REG             \
BNO055_ACCEL_DATA_Y_LSB_ADDR

/* Accel data Y-MSB register*/
#define BNO055_ACCEL_DATA_Y_MSB_VALUEY__POS             0
#define BNO055_ACCEL_DATA_Y_MSB_VALUEY__MSK             0xFF
#define BNO055_ACCEL_DATA_Y_MSB_VALUEY__LEN             8
#define BNO055_ACCEL_DATA_Y_MSB_VALUEY__REG             \
BNO055_ACCEL_DATA_Y_MSB_ADDR

/* Accel data Z-LSB register*/
#define BNO055_ACCEL_DATA_Z_LSB_VALUEZ__POS		0
#define BNO055_ACCEL_DATA_Z_LSB_VALUEZ__MSK		0xFF
#define BNO055_ACCEL_DATA_Z_LSB_VALUEZ__LEN		8
#define BNO055_ACCEL_DATA_Z_LSB_VALUEZ__REG     \
BNO055_ACCEL_DATA_Z_LSB_ADDR

/* Accel data Z-MSB register*/
#define BNO055_ACCEL_DATA_Z_MSB_VALUEZ__POS		0
#define BNO055_ACCEL_DATA_Z_MSB_VALUEZ__MSK		0xFF
#define BNO055_ACCEL_DATA_Z_MSB_VALUEZ__LEN		8
#define BNO055_ACCEL_DATA_Z_MSB_VALUEZ__REG     \
BNO055_ACCEL_DATA_Z_MSB_ADDR

/* Mag data X-LSB register*/
#define BNO055_MAG_DATA_X_LSB_VALUEX__POS             0
#define BNO055_MAG_DATA_X_LSB_VALUEX__MSK             0xFF
#define BNO055_MAG_DATA_X_LSB_VALUEX__LEN             8
#define BNO055_MAG_DATA_X_LSB_VALUEX__REG             \
BNO055_MAG_DATA_X_LSB_ADDR

/* Mag data X-MSB register*/
#define BNO055_MAG_DATA_X_MSB_VALUEX__POS             0
#define BNO055_MAG_DATA_X_MSB_VALUEX__MSK             0xFF
#define BNO055_MAG_DATA_X_MSB_VALUEX__LEN             8
#define BNO055_MAG_DATA_X_MSB_VALUEX__REG             BNO055_MAG_DATA_X_MSB_ADDR

/* Mag data Y-LSB register*/
#define BNO055_MAG_DATA_Y_LSB_VALUEY__POS             0
#define BNO055_MAG_DATA_Y_LSB_VALUEY__MSK             0xFF
#define BNO055_MAG_DATA_Y_LSB_VALUEY__LEN             8
#define BNO055_MAG_DATA_Y_LSB_VALUEY__REG             BNO055_MAG_DATA_Y_LSB_ADDR

/* Mag data Y-MSB register*/
#define BNO055_MAG_DATA_Y_MSB_VALUEY__POS             0
#define BNO055_MAG_DATA_Y_MSB_VALUEY__MSK             0xFF
#define BNO055_MAG_DATA_Y_MSB_VALUEY__LEN             8
#define BNO055_MAG_DATA_Y_MSB_VALUEY__REG             BNO055_MAG_DATA_Y_MSB_ADDR

/* Mag data Z-LSB register*/
#define BNO055_MAG_DATA_Z_LSB_VALUEZ__POS             0
#define BNO055_MAG_DATA_Z_LSB_VALUEZ__MSK             0xFF
#define BNO055_MAG_DATA_Z_LSB_VALUEZ__LEN             8
#define BNO055_MAG_DATA_Z_LSB_VALUEZ__REG             BNO055_MAG_DATA_Z_LSB_ADDR

/* Mag data Z-MSB register*/
#define BNO055_MAG_DATA_Z_MSB_VALUEZ__POS             0
#define BNO055_MAG_DATA_Z_MSB_VALUEZ__MSK             0xFF
#define BNO055_MAG_DATA_Z_MSB_VALUEZ__LEN             8
#define BNO055_MAG_DATA_Z_MSB_VALUEZ__REG             BNO055_MAG_DATA_Z_MSB_ADDR

/* Gyro data X-LSB register*/
#define BNO055_GYRO_DATA_X_LSB_VALUEX__POS	0
#define BNO055_GYRO_DATA_X_LSB_VALUEX__MSK	0xFF
#define BNO055_GYRO_DATA_X_LSB_VALUEX__LEN	8
#define BNO055_GYRO_DATA_X_LSB_VALUEX__REG	BNO055_GYRO_DATA_X_LSB_ADDR

/* Gyro data X-MSB register*/
#define BNO055_GYRO_DATA_X_MSB_VALUEX__POS	0
#define BNO055_GYRO_DATA_X_MSB_VALUEX__MSK	0xFF
#define BNO055_GYRO_DATA_X_MSB_VALUEX__LEN	8
#define BNO055_GYRO_DATA_X_MSB_VALUEX__REG	BNO055_GYRO_DATA_X_MSB_ADDR

/* Gyro data Y-LSB register*/
#define BNO055_GYRO_DATA_Y_LSB_VALUEY__POS	0
#define BNO055_GYRO_DATA_Y_LSB_VALUEY__MSK	0xFF
#define BNO055_GYRO_DATA_Y_LSB_VALUEY__LEN	8
#define BNO055_GYRO_DATA_Y_LSB_VALUEY__REG	BNO055_GYRO_DATA_Y_LSB_ADDR

/* Gyro data Y-MSB register*/
#define BNO055_GYRO_DATA_Y_MSB_VALUEY__POS	0
#define BNO055_GYRO_DATA_Y_MSB_VALUEY__MSK	0xFF
#define BNO055_GYRO_DATA_Y_MSB_VALUEY__LEN	8
#define BNO055_GYRO_DATA_Y_MSB_VALUEY__REG	BNO055_GYRO_DATA_Y_MSB_ADDR

/* Gyro data Z-LSB register*/
#define BNO055_GYRO_DATA_Z_LSB_VALUEZ__POS	0
#define BNO055_GYRO_DATA_Z_LSB_VALUEZ__MSK	0xFF
#define BNO055_GYRO_DATA_Z_LSB_VALUEZ__LEN	8
#define BNO055_GYRO_DATA_Z_LSB_VALUEZ__REG	BNO055_GYRO_DATA_Z_LSB_ADDR

/* Gyro data Z-MSB register*/
#define BNO055_GYRO_DATA_Z_MSB_VALUEZ__POS	0
#define BNO055_GYRO_DATA_Z_MSB_VALUEZ__MSK	0xFF
#define BNO055_GYRO_DATA_Z_MSB_VALUEZ__LEN	8
#define BNO055_GYRO_DATA_Z_MSB_VALUEZ__REG	BNO055_GYRO_DATA_Z_MSB_ADDR

/* Euler data HEADING-LSB register*/
#define BNO055_EULER_H_LSB_VALUEH__POS   0
#define BNO055_EULER_H_LSB_VALUEH__MSK   0xFF
#define BNO055_EULER_H_LSB_VALUEH__LEN   8
#define BNO055_EULER_H_LSB_VALUEH__REG  BNO055_EULER_H_LSB_ADDR

/* Euler data HEADING-MSB register*/
#define BNO055_EULER_H_MSB_VALUEH__POS  0
#define BNO055_EULER_H_MSB_VALUEH__MSK  0xFF
#define BNO055_EULER_H_MSB_VALUEH__LEN  8
#define BNO055_EULER_H_MSB_VALUEH__REG  BNO055_EULER_H_MSB_ADDR

/* Euler data ROLL-LSB register*/
#define BNO055_EULER_R_LSB_VALUER__POS  0
#define BNO055_EULER_R_LSB_VALUER__MSK  0xFF
#define BNO055_EULER_R_LSB_VALUER__LEN  8
#define BNO055_EULER_R_LSB_VALUER__REG  BNO055_EULER_R_LSB_ADDR

/* Euler data ROLL-MSB register*/
#define BNO055_EULER_R_MSB_VALUER__POS  0
#define BNO055_EULER_R_MSB_VALUER__MSK  0xFF
#define BNO055_EULER_R_MSB_VALUER__LEN  8
#define BNO055_EULER_R_MSB_VALUER__REG  BNO055_EULER_R_MSB_ADDR

/* Euler data PITCH-LSB register*/
#define BNO055_EULER_P_LSB_VALUEP__POS  0
#define BNO055_EULER_P_LSB_VALUEP__MSK  0xFF
#define BNO055_EULER_P_LSB_VALUEP__LEN  8
#define BNO055_EULER_P_LSB_VALUEP__REG  BNO055_EULER_P_LSB_ADDR

/* Euler data HEADING-MSB register*/
#define BNO055_EULER_P_MSB_VALUEP__POS  0
#define BNO055_EULER_P_MSB_VALUEP__MSK  0xFF
#define BNO055_EULER_P_MSB_VALUEP__LEN  8
#define BNO055_EULER_P_MSB_VALUEP__REG  BNO055_EULER_P_MSB_ADDR

/* Quaternion data W-LSB register*/
#define BNO055_QUATERNION_DATA_W_LSB_VALUEW__POS  0
#define BNO055_QUATERNION_DATA_W_LSB_VALUEW__MSK  0xFF
#define BNO055_QUATERNION_DATA_W_LSB_VALUEW__LEN  8
#define BNO055_QUATERNION_DATA_W_LSB_VALUEW__REG  \
BNO055_QUATERNION_DATA_W_LSB_ADDR

/* Quaternion data W-MSB register*/
#define BNO055_QUATERNION_DATA_W_MSB_VALUEW__POS  0
#define BNO055_QUATERNION_DATA_W_MSB_VALUEW__MSK  0xFF
#define BNO055_QUATERNION_DATA_W_MSB_VALUEW__LEN  8
#define BNO055_QUATERNION_DATA_W_MSB_VALUEW__REG  \
BNO055_QUATERNION_DATA_W_MSB_ADDR

/* Quaternion data X-LSB register*/
#define BNO055_QUATERNION_DATA_X_LSB_VALUEX__POS  0
#define BNO055_QUATERNION_DATA_X_LSB_VALUEX__MSK  0xFF
#define BNO055_QUATERNION_DATA_X_LSB_VALUEX__LEN  8
#define BNO055_QUATERNION_DATA_X_LSB_VALUEX__REG  \
BNO055_QUATERNION_DATA_X_LSB_ADDR

/* Quaternion data X-MSB register*/
#define BNO055_QUATERNION_DATA_X_MSB_VALUEX__POS  0
#define BNO055_QUATERNION_DATA_X_MSB_VALUEX__MSK  0xFF
#define BNO055_QUATERNION_DATA_X_MSB_VALUEX__LEN  8
#define BNO055_QUATERNION_DATA_X_MSB_VALUEX__REG \
BNO055_QUATERNION_DATA_X_MSB_ADDR

/* Quaternion data Y-LSB register*/
#define BNO055_QUATERNION_DATA_Y_LSB_VALUEY__POS  0
#define BNO055_QUATERNION_DATA_Y_LSB_VALUEY__MSK  0xFF
#define BNO055_QUATERNION_DATA_Y_LSB_VALUEY__LEN  8
#define BNO055_QUATERNION_DATA_Y_LSB_VALUEY__REG \
BNO055_QUATERNION_DATA_Y_LSB_ADDR

/* Quaternion data Y-MSB register*/
#define BNO055_QUATERNION_DATA_Y_MSB_VALUEY__POS  0
#define BNO055_QUATERNION_DATA_Y_MSB_VALUEY__MSK  0xFF
#define BNO055_QUATERNION_DATA_Y_MSB_VALUEY__LEN  8
#define BNO055_QUATERNION_DATA_Y_MSB_VALUEY__REG  \
NO055_QUATERNION_DATA_Y_MSB_ADDR

/* Quaternion data Z-LSB register*/
#define BNO055_QUATERNION_DATA_Z_LSB_VALUEZ__POS  0
#define BNO055_QUATERNION_DATA_Z_LSB_VALUEZ__MSK  0xFF
#define BNO055_QUATERNION_DATA_Z_LSB_VALUEZ__LEN  8
#define BNO055_QUATERNION_DATA_Z_LSB_VALUEZ__REG \
BNO055_QUATERNION_DATA_Z_LSB_ADDR

/* Quaternion data Z-MSB register*/
#define BNO055_QUATERNION_DATA_Z_MSB_VALUEZ__POS  0
#define BNO055_QUATERNION_DATA_Z_MSB_VALUEZ__MSK  0xFF
#define BNO055_QUATERNION_DATA_Z_MSB_VALUEZ__LEN  8
#define BNO055_QUATERNION_DATA_Z_MSB_VALUEZ__REG  \
BNO055_QUATERNION_DATA_Z_MSB_ADDR

/* Linear acceleration data X-LSB register*/
#define BNO055_LINEAR_ACCEL_DATA_X_LSB_VALUEX__POS  0
#define BNO055_LINEAR_ACCEL_DATA_X_LSB_VALUEX__MSK  0xFF
#define BNO055_LINEAR_ACCEL_DATA_X_LSB_VALUEX__LEN  8
#define BNO055_LINEAR_ACCEL_DATA_X_LSB_VALUEX__REG  \
BNO055_LINEAR_ACCEL_DATA_X_LSB_ADDR

/* Linear acceleration data X-MSB register*/
#define BNO055_LINEAR_ACCEL_DATA_X_MSB_VALUEX__POS  0
#define BNO055_LINEAR_ACCEL_DATA_X_MSB_VALUEX__MSK  0xFF
#define BNO055_LINEAR_ACCEL_DATA_X_MSB_VALUEX__LEN  8
#define BNO055_LINEAR_ACCEL_DATA_X_MSB_VALUEX__REG  \
BNO055_LINEAR_ACCEL_DATA_X_MSB_ADDR

/* Linear acceleration data Y-LSB register*/
#define BNO055_LINEAR_ACCEL_DATA_Y_LSB_VALUEY__POS  0
#define BNO055_LINEAR_ACCEL_DATA_Y_LSB_VALUEY__MSK  0xFF
#define BNO055_LINEAR_ACCEL_DATA_Y_LSB_VALUEY__LEN  8
#define BNO055_LINEAR_ACCEL_DATA_Y_LSB_VALUEY__REG  \
BNO055_LINEAR_ACCEL_DATA_Y_LSB_ADDR

/* Linear acceleration data Y-MSB register*/
#define BNO055_LINEAR_ACCEL_DATA_Y_MSB_VALUEY__POS  0
#define BNO055_LINEAR_ACCEL_DATA_Y_MSB_VALUEY__MSK  0xFF
#define BNO055_LINEAR_ACCEL_DATA_Y_MSB_VALUEY__LEN  8
#define BNO055_LINEAR_ACCEL_DATA_Y_MSB_VALUEY__REG  \
BNO055_LINEAR_ACCEL_DATA_Y_MSB_ADDR

/* Linear acceleration data Z-LSB register*/
#define BNO055_LINEAR_ACCEL_DATA_Z_LSB_VALUEZ__POS  0
#define BNO055_LINEAR_ACCEL_DATA_Z_LSB_VALUEZ__MSK  0xFF
#define BNO055_LINEAR_ACCEL_DATA_Z_LSB_VALUEZ__LEN  8
#define BNO055_LINEAR_ACCEL_DATA_Z_LSB_VALUEZ__REG \
BNO055_LINEAR_ACCEL_DATA_Z_LSB_ADDR

/* Linear acceleration data Z-MSB register*/
#define BNO055_LINEAR_ACCEL_DATA_Z_MSB_VALUEZ__POS  0
#define BNO055_LINEAR_ACCEL_DATA_Z_MSB_VALUEZ__MSK  0xFF
#define BNO055_LINEAR_ACCEL_DATA_Z_MSB_VALUEZ__LEN  8
#define BNO055_LINEAR_ACCEL_DATA_Z_MSB_VALUEZ__REG  \
BNO055_LINEAR_ACCEL_DATA_Z_MSB_ADDR

/* Gravity data X-LSB register*/
#define BNO055_GRAVITY_DATA_X_LSB_VALUEX__POS  0
#define BNO055_GRAVITY_DATA_X_LSB_VALUEX__MSK  0xFF
#define BNO055_GRAVITY_DATA_X_LSB_VALUEX__LEN  8
#define BNO055_GRAVITY_DATA_X_LSB_VALUEX__REG  \
BNO055_GRAVITY_DATA_X_LSB_ADDR

/* Gravity data X-MSB register*/
#define BNO055_GRAVITY_DATA_X_MSB_VALUEX__POS  0
#define BNO055_GRAVITY_DATA_X_MSB_VALUEX__MSK  0xFF
#define BNO055_GRAVITY_DATA_X_MSB_VALUEX__LEN  8
#define BNO055_GRAVITY_DATA_X_MSB_VALUEX__REG  \
BNO055_GRAVITY_DATA_X_MSB_ADDR

/* Gravity data Y-LSB register*/
#define BNO055_GRAVITY_DATA_Y_LSB_VALUEY__POS  0
#define BNO055_GRAVITY_DATA_Y_LSB_VALUEY__MSK  0xFF
#define BNO055_GRAVITY_DATA_Y_LSB_VALUEY__LEN  8
#define BNO055_GRAVITY_DATA_Y_LSB_VALUEY__REG  \
BNO055_GRAVITY_DATA_Y_LSB_ADDR

/* Gravity data Y-MSB register*/
#define BNO055_GRAVITY_DATA_Y_MSB_VALUEY__POS  0
#define BNO055_GRAVITY_DATA_Y_MSB_VALUEY__MSK  0xFF
#define BNO055_GRAVITY_DATA_Y_MSB_VALUEY__LEN  8
#define BNO055_GRAVITY_DATA_Y_MSB_VALUEY__REG  \
BNO055_GRAVITY_DATA_Y_MSB_ADDR

/* Gravity data Z-LSB register*/
#define BNO055_GRAVITY_DATA_Z_LSB_VALUEZ__POS  0
#define BNO055_GRAVITY_DATA_Z_LSB_VALUEZ__MSK  0xFF
#define BNO055_GRAVITY_DATA_Z_LSB_VALUEZ__LEN  8
#define BNO055_GRAVITY_DATA_Z_LSB_VALUEZ__REG  \
BNO055_GRAVITY_DATA_Z_LSB_ADDR

/* Gravity data Z-MSB register*/
#define BNO055_GRAVITY_DATA_Z_MSB_VALUEZ__POS  0
#define BNO055_GRAVITY_DATA_Z_MSB_VALUEZ__MSK  0xFF
#define BNO055_GRAVITY_DATA_Z_MSB_VALUEZ__LEN  8
#define BNO055_GRAVITY_DATA_Z_MSB_VALUEZ__REG  \
BNO055_GRAVITY_DATA_Z_MSB_ADDR

/* Temperature register*/
#define BNO055_TEMP__POS             0
#define BNO055_TEMP__MSK             0xFF
#define BNO055_TEMP__LEN             8
#define BNO055_TEMP__REG             BNO055_TEMP_ADDR

/*Mag_Calib status register*/
#define BNO055_MAG_CALIB_STAT__POS             0
#define BNO055_MAG_CALIB_STAT__MSK             0X03
#define BNO055_MAG_CALIB_STAT__LEN             2
#define BNO055_MAG_CALIB_STAT__REG             BNO055_CALIB_STAT_ADDR

/*Acc_Calib status register*/
#define BNO055_ACCEL_CALIB_STAT__POS             2
#define BNO055_ACCEL_CALIB_STAT__MSK             0X0C
#define BNO055_ACCEL_CALIB_STAT__LEN             2
#define BNO055_ACCEL_CALIB_STAT__REG             BNO055_CALIB_STAT_ADDR

/*Gyro_Calib status register*/
#define BNO055_GYRO_CALIB_STAT__POS             4
#define BNO055_GYRO_CALIB_STAT__MSK             0X30
#define BNO055_GYRO_CALIB_STAT__LEN             2
#define BNO055_GYRO_CALIB_STAT__REG             BNO055_CALIB_STAT_ADDR

/*Sys_Calib status register*/
#define BNO055_SYS_CALIB_STAT__POS             6
#define BNO055_SYS_CALIB_STAT__MSK             0XC0
#define BNO055_SYS_CALIB_STAT__LEN             2
#define BNO055_SYS_CALIB_STAT__REG             BNO055_CALIB_STAT_ADDR

/*ST_ACCEL register*/
#define BNO055_SELFTEST_ACCEL__POS             0
#define BNO055_SELFTEST_ACCEL__MSK             0X01
#define BNO055_SELFTEST_ACCEL__LEN             1
#define BNO055_SELFTEST_ACCEL__REG             BNO055_SELFTEST_RESULT_ADDR

/*ST_MAG register*/
#define BNO055_SELFTEST_MAG__POS             1
#define BNO055_SELFTEST_MAG__MSK             0X02
#define BNO055_SELFTEST_MAG__LEN             1
#define BNO055_SELFTEST_MAG__REG             BNO055_SELFTEST_RESULT_ADDR

/*ST_GYRO register*/
#define BNO055_SELFTEST_GYRO__POS             2
#define BNO055_SELFTEST_GYRO__MSK             0X04
#define BNO055_SELFTEST_GYRO__LEN             1
#define BNO055_SELFTEST_GYRO__REG             BNO055_SELFTEST_RESULT_ADDR

/*ST_MCU register*/
#define BNO055_SELFTEST_MCU__POS             3
#define BNO055_SELFTEST_MCU__MSK             0X08
#define BNO055_SELFTEST_MCU__LEN             1
#define BNO055_SELFTEST_MCU__REG             BNO055_SELFTEST_RESULT_ADDR

/*Interrupt status registers*/
#define BNO055_INTR_STAT_GYRO_ANY_MOTION__POS		2
#define BNO055_INTR_STAT_GYRO_ANY_MOTION__MSK		0X04
#define BNO055_INTR_STAT_GYRO_ANY_MOTION__LEN		1
#define BNO055_INTR_STAT_GYRO_ANY_MOTION__REG		BNO055_INTR_STAT_ADDR

#define BNO055_INTR_STAT_GYRO_HIGHRATE__POS		3
#define BNO055_INTR_STAT_GYRO_HIGHRATE__MSK		0X08
#define BNO055_INTR_STAT_GYRO_HIGHRATE__LEN		1
#define BNO055_INTR_STAT_GYRO_HIGHRATE__REG		BNO055_INTR_STAT_ADDR

#define BNO055_INTR_STAT_ACCEL_HIGH_G__POS		5
#define BNO055_INTR_STAT_ACCEL_HIGH_G__MSK		0X20
#define BNO055_INTR_STAT_ACCEL_HIGH_G__LEN		1
#define BNO055_INTR_STAT_ACCEL_HIGH_G__REG		BNO055_INTR_STAT_ADDR

#define BNO055_INTR_STAT_ACCEL_ANY_MOTION__POS		6
#define BNO055_INTR_STAT_ACCEL_ANY_MOTION__MSK		0X40
#define BNO055_INTR_STAT_ACCEL_ANY_MOTION__LEN		1
#define BNO055_INTR_STAT_ACCEL_ANY_MOTION__REG		BNO055_INTR_STAT_ADDR

#define BNO055_INTR_STAT_ACCEL_NO_MOTION__POS		7
#define BNO055_INTR_STAT_ACCEL_NO_MOTION__MSK		0X80
#define BNO055_INTR_STAT_ACCEL_NO_MOTION__LEN		1
#define BNO055_INTR_STAT_ACCEL_NO_MOTION__REG		BNO055_INTR_STAT_ADDR

/* system clock status register*/
#define BNO055_SYS_MAIN_CLK__POS		0
#define BNO055_SYS_MAIN_CLK__MSK		0X10
#define BNO055_SYS_MAIN_CLK__LEN		1
#define BNO055_SYS_MAIN_CLK__REG		BNO055_SYS_CLK_STAT_ADDR

/* System registers*/
#define BNO055_SYS_STAT_CODE__POS		0
#define BNO055_SYS_STAT_CODE__MSK		0XFF
#define BNO055_SYS_STAT_CODE__LEN		8
#define BNO055_SYS_STAT_CODE__REG		BNO055_SYS_STAT_ADDR

#define BNO055_SYS_ERROR_CODE__POS			0
#define BNO055_SYS_ERROR_CODE__MSK			0XFF
#define BNO055_SYS_ERROR_CODE__LEN			8
#define BNO055_SYS_ERROR_CODE__REG			BNO055_SYS_ERR_ADDR

/* Accel_Unit register*/
#define BNO055_ACCEL_UNIT__POS             0
#define BNO055_ACCEL_UNIT__MSK             0X01
#define BNO055_ACCEL_UNIT__LEN             1
#define BNO055_ACCEL_UNIT__REG             BNO055_UNIT_SEL_ADDR

/* Gyro_Unit register*/
#define BNO055_GYRO_UNIT__POS             1
#define BNO055_GYRO_UNIT__MSK             0X02
#define BNO055_GYRO_UNIT__LEN             1
#define BNO055_GYRO_UNIT__REG             BNO055_UNIT_SEL_ADDR

/* Euler_Unit register*/
#define BNO055_EULER_UNIT__POS             2
#define BNO055_EULER_UNIT__MSK             0X04
#define BNO055_EULER_UNIT__LEN             1
#define BNO055_EULER_UNIT__REG             BNO055_UNIT_SEL_ADDR

/* Tilt_Unit register*/
#define BNO055_TILT_UNIT__POS             3
#define BNO055_TILT_UNIT__MSK             0X08
#define BNO055_TILT_UNIT__LEN             1
#define BNO055_TILT_UNIT__REG             BNO055_UNIT_SEL_ADDR

/* Temperature_Unit register*/
#define BNO055_TEMP_UNIT__POS             4
#define BNO055_TEMP_UNIT__MSK             0X10
#define BNO055_TEMP_UNIT__LEN             1
#define BNO055_TEMP_UNIT__REG             BNO055_UNIT_SEL_ADDR

/* ORI android-windows register*/
#define BNO055_DATA_OUTPUT_FORMAT__POS             7
#define BNO055_DATA_OUTPUT_FORMAT__MSK             0X80
#define BNO055_DATA_OUTPUT_FORMAT__LEN             1
#define BNO055_DATA_OUTPUT_FORMAT__REG             BNO055_UNIT_SEL_ADDR
/*Operation Mode data register*/
#define BNO055_OPERATION_MODE__POS			0
#define BNO055_OPERATION_MODE__MSK			0X0F
#define BNO055_OPERATION_MODE__LEN			4
#define BNO055_OPERATION_MODE__REG			BNO055_OPR_MODE_ADDR
/* Power Mode register*/
#define BNO055_POWER_MODE__POS             0
#define BNO055_POWER_MODE__MSK             0X03
#define BNO055_POWER_MODE__LEN             2
#define BNO055_POWER_MODE__REG             BNO055_PWR_MODE_ADDR

/*Self Test register*/
#define BNO055_SELFTEST__POS			0
#define BNO055_SELFTEST__MSK			0X01
#define BNO055_SELFTEST__LEN			1
#define BNO055_SELFTEST__REG			BNO055_SYS_TRIGGER_ADDR

/* RST_SYS register*/
#define BNO055_SYS_RST__POS             5
#define BNO055_SYS_RST__MSK             0X20
#define BNO055_SYS_RST__LEN             1
#define BNO055_SYS_RST__REG             BNO055_SYS_TRIGGER_ADDR

/* RST_INT register*/
#define BNO055_INTR_RST__POS             6
#define BNO055_INTR_RST__MSK             0X40
#define BNO055_INTR_RST__LEN             1
#define BNO055_INTR_RST__REG             BNO055_SYS_TRIGGER_ADDR

/* CLK_SRC register*/
#define BNO055_CLK_SRC__POS             7
#define BNO055_CLK_SRC__MSK             0X80
#define BNO055_CLK_SRC__LEN             1
#define BNO055_CLK_SRC__REG             BNO055_SYS_TRIGGER_ADDR

/* Temp source register*/
#define BNO055_TEMP_SOURCE__POS		0
#define BNO055_TEMP_SOURCE__MSK		0X03
#define BNO055_TEMP_SOURCE__LEN		2
#define BNO055_TEMP_SOURCE__REG		BNO055_TEMP_SOURCE_ADDR

/* Axis remap value register*/
#define BNO055_REMAP_AXIS_VALUE__POS		0
#define BNO055_REMAP_AXIS_VALUE__MSK		0X3F
#define BNO055_REMAP_AXIS_VALUE__LEN		6
#define BNO055_REMAP_AXIS_VALUE__REG		BNO055_AXIS_MAP_CONFIG_ADDR

/* Axis sign value register*/
#define BNO055_REMAP_Z_SIGN__POS		0
#define BNO055_REMAP_Z_SIGN__MSK		0X01
#define BNO055_REMAP_Z_SIGN__LEN		1
#define BNO055_REMAP_Z_SIGN__REG		BNO055_AXIS_MAP_SIGN_ADDR

#define BNO055_REMAP_Y_SIGN__POS		1
#define BNO055_REMAP_Y_SIGN__MSK		0X02
#define BNO055_REMAP_Y_SIGN__LEN		1
#define BNO055_REMAP_Y_SIGN__REG		BNO055_AXIS_MAP_SIGN_ADDR

#define BNO055_REMAP_X_SIGN__POS		2
#define BNO055_REMAP_X_SIGN__MSK		0X04
#define BNO055_REMAP_X_SIGN__LEN		1
#define BNO055_REMAP_X_SIGN__REG		BNO055_AXIS_MAP_SIGN_ADDR

/* Soft Iron Calibration matrix register*/
#define BNO055_SIC_MATRIX_0_LSB__POS		0
#define BNO055_SIC_MATRIX_0_LSB__MSK		0XFF
#define BNO055_SIC_MATRIX_0_LSB__LEN		8
#define BNO055_SIC_MATRIX_0_LSB__REG		BNO055_SIC_MATRIX_0_LSB_ADDR

#define BNO055_SIC_MATRIX_0_MSB__POS		0
#define BNO055_SIC_MATRIX_0_MSB__MSK		0XFF
#define BNO055_SIC_MATRIX_0_MSB__LEN		8
#define BNO055_SIC_MATRIX_0_MSB__REG		BNO055_SIC_MATRIX_0_MSB_ADDR

#define BNO055_SIC_MATRIX_1_LSB__POS		0
#define BNO055_SIC_MATRIX_1_LSB__MSK		0XFF
#define BNO055_SIC_MATRIX_1_LSB__LEN		8
#define BNO055_SIC_MATRIX_1_LSB__REG		BNO055_SIC_MATRIX_1_LSB_ADDR

#define BNO055_SIC_MATRIX_1_MSB__POS		0
#define BNO055_SIC_MATRIX_1_MSB__MSK		0XFF
#define BNO055_SIC_MATRIX_1_MSB__LEN		8
#define BNO055_SIC_MATRIX_1_MSB__REG		BNO055_SIC_MATRIX_1_MSB_ADDR

#define BNO055_SIC_MATRIX_2_LSB__POS		0
#define BNO055_SIC_MATRIX_2_LSB__MSK		0XFF
#define BNO055_SIC_MATRIX_2_LSB__LEN		8
#define BNO055_SIC_MATRIX_2_LSB__REG		BNO055_SIC_MATRIX_2_LSB_ADDR

#define BNO055_SIC_MATRIX_2_MSB__POS		0
#define BNO055_SIC_MATRIX_2_MSB__MSK		0XFF
#define BNO055_SIC_MATRIX_2_MSB__LEN		8
#define BNO055_SIC_MATRIX_2_MSB__REG		BNO055_SIC_MATRIX_2_MSB_ADDR

#define BNO055_SIC_MATRIX_3_LSB__POS		0
#define BNO055_SIC_MATRIX_3_LSB__MSK		0XFF
#define BNO055_SIC_MATRIX_3_LSB__LEN		8
#define BNO055_SIC_MATRIX_3_LSB__REG		BNO055_SIC_MATRIX_3_LSB_ADDR

#define BNO055_SIC_MATRIX_3_MSB__POS		0
#define BNO055_SIC_MATRIX_3_MSB__MSK		0XFF
#define BNO055_SIC_MATRIX_3_MSB__LEN		8
#define BNO055_SIC_MATRIX_3_MSB__REG		BNO055_SIC_MATRIX_3_MSB_ADDR

#define BNO055_SIC_MATRIX_4_LSB__POS		0
#define BNO055_SIC_MATRIX_4_LSB__MSK		0XFF
#define BNO055_SIC_MATRIX_4_LSB__LEN		8
#define BNO055_SIC_MATRIX_4_LSB__REG		BNO055_SIC_MATRIX_4_LSB_ADDR

#define BNO055_SIC_MATRIX_4_MSB__POS		0
#define BNO055_SIC_MATRIX_4_MSB__MSK		0XFF
#define BNO055_SIC_MATRIX_4_MSB__LEN		8
#define BNO055_SIC_MATRIX_4_MSB__REG		BNO055_SIC_MATRIX_4_MSB_ADDR

#define BNO055_SIC_MATRIX_5_LSB__POS		0
#define BNO055_SIC_MATRIX_5_LSB__MSK		0XFF
#define BNO055_SIC_MATRIX_5_LSB__LEN		8
#define BNO055_SIC_MATRIX_5_LSB__REG		BNO055_SIC_MATRIX_5_LSB_ADDR

#define BNO055_SIC_MATRIX_5_MSB__POS		0
#define BNO055_SIC_MATRIX_5_MSB__MSK		0XFF
#define BNO055_SIC_MATRIX_5_MSB__LEN		8
#define BNO055_SIC_MATRIX_5_MSB__REG		BNO055_SIC_MATRIX_5_MSB_ADDR

#define BNO055_SIC_MATRIX_6_LSB__POS		0
#define BNO055_SIC_MATRIX_6_LSB__MSK		0XFF
#define BNO055_SIC_MATRIX_6_LSB__LEN		8
#define BNO055_SIC_MATRIX_6_LSB__REG		BNO055_SIC_MATRIX_6_LSB_ADDR

#define BNO055_SIC_MATRIX_6_MSB__POS		0
#define BNO055_SIC_MATRIX_6_MSB__MSK		0XFF
#define BNO055_SIC_MATRIX_6_MSB__LEN		8
#define BNO055_SIC_MATRIX_6_MSB__REG		BNO055_SIC_MATRIX_6_MSB_ADDR

#define BNO055_SIC_MATRIX_7_LSB__POS		0
#define BNO055_SIC_MATRIX_7_LSB__MSK		0XFF
#define BNO055_SIC_MATRIX_7_LSB__LEN		8
#define BNO055_SIC_MATRIX_7_LSB__REG		BNO055_SIC_MATRIX_7_LSB_ADDR

#define BNO055_SIC_MATRIX_7_MSB__POS		0
#define BNO055_SIC_MATRIX_7_MSB__MSK		0XFF
#define BNO055_SIC_MATRIX_7_MSB__LEN		8
#define BNO055_SIC_MATRIX_7_MSB__REG		BNO055_SIC_MATRIX_7_MSB_ADDR

#define BNO055_SIC_MATRIX_8_LSB__POS		0
#define BNO055_SIC_MATRIX_8_LSB__MSK		0XFF
#define BNO055_SIC_MATRIX_8_LSB__LEN		8
#define BNO055_SIC_MATRIX_8_LSB__REG		BNO055_SIC_MATRIX_8_LSB_ADDR

#define BNO055_SIC_MATRIX_8_MSB__POS		0
#define BNO055_SIC_MATRIX_8_MSB__MSK		0XFF
#define BNO055_SIC_MATRIX_8_MSB__LEN		8
#define BNO055_SIC_MATRIX_8_MSB__REG		BNO055_SIC_MATRIX_8_MSB_ADDR

/*Accel Offset registers*/
#define BNO055_ACCEL_OFFSET_X_LSB__POS		0
#define BNO055_ACCEL_OFFSET_X_LSB__MSK		0XFF
#define BNO055_ACCEL_OFFSET_X_LSB__LEN		8
#define BNO055_ACCEL_OFFSET_X_LSB__REG		ACCEL_OFFSET_X_LSB_ADDR

#define BNO055_ACCEL_OFFSET_X_MSB__POS		0
#define BNO055_ACCEL_OFFSET_X_MSB__MSK		0XFF
#define BNO055_ACCEL_OFFSET_X_MSB__LEN		8
#define BNO055_ACCEL_OFFSET_X_MSB__REG		ACCEL_OFFSET_X_MSB_ADDR

#define BNO055_ACCEL_OFFSET_Y_LSB__POS		0
#define BNO055_ACCEL_OFFSET_Y_LSB__MSK		0XFF
#define BNO055_ACCEL_OFFSET_Y_LSB__LEN		8
#define BNO055_ACCEL_OFFSET_Y_LSB__REG		ACCEL_OFFSET_Y_LSB_ADDR

#define BNO055_ACCEL_OFFSET_Y_MSB__POS		0
#define BNO055_ACCEL_OFFSET_Y_MSB__MSK		0XFF
#define BNO055_ACCEL_OFFSET_Y_MSB__LEN		8
#define BNO055_ACCEL_OFFSET_Y_MSB__REG		ACCEL_OFFSET_Y_MSB_ADDR

#define BNO055_ACCEL_OFFSET_Z_LSB__POS		0
#define BNO055_ACCEL_OFFSET_Z_LSB__MSK		0XFF
#define BNO055_ACCEL_OFFSET_Z_LSB__LEN		8
#define BNO055_ACCEL_OFFSET_Z_LSB__REG		ACCEL_OFFSET_Z_LSB_ADDR

#define BNO055_ACCEL_OFFSET_Z_MSB__POS		0
#define BNO055_ACCEL_OFFSET_Z_MSB__MSK		0XFF
#define BNO055_ACCEL_OFFSET_Z_MSB__LEN		8
#define BNO055_ACCEL_OFFSET_Z_MSB__REG		ACCEL_OFFSET_Z_MSB_ADDR

/*Mag Offset registers*/
#define BNO055_MAG_OFFSET_X_LSB__POS		0
#define BNO055_MAG_OFFSET_X_LSB__MSK		0XFF
#define BNO055_MAG_OFFSET_X_LSB__LEN		8
#define BNO055_MAG_OFFSET_X_LSB__REG		MAG_OFFSET_X_LSB_ADDR

#define BNO055_MAG_OFFSET_X_MSB__POS		0
#define BNO055_MAG_OFFSET_X_MSB__MSK		0XFF
#define BNO055_MAG_OFFSET_X_MSB__LEN		8
#define BNO055_MAG_OFFSET_X_MSB__REG		MAG_OFFSET_X_MSB_ADDR

#define BNO055_MAG_OFFSET_Y_LSB__POS		0
#define BNO055_MAG_OFFSET_Y_LSB__MSK		0XFF
#define BNO055_MAG_OFFSET_Y_LSB__LEN		8
#define BNO055_MAG_OFFSET_Y_LSB__REG		MAG_OFFSET_Y_LSB_ADDR

#define BNO055_MAG_OFFSET_Y_MSB__POS		0
#define BNO055_MAG_OFFSET_Y_MSB__MSK		0XFF
#define BNO055_MAG_OFFSET_Y_MSB__LEN		8
#define BNO055_MAG_OFFSET_Y_MSB__REG		MAG_OFFSET_Y_MSB_ADDR

#define BNO055_MAG_OFFSET_Z_LSB__POS		0
#define BNO055_MAG_OFFSET_Z_LSB__MSK		0XFF
#define BNO055_MAG_OFFSET_Z_LSB__LEN		8
#define BNO055_MAG_OFFSET_Z_LSB__REG		MAG_OFFSET_Z_LSB_ADDR

#define BNO055_MAG_OFFSET_Z_MSB__POS		0
#define BNO055_MAG_OFFSET_Z_MSB__MSK		0XFF
#define BNO055_MAG_OFFSET_Z_MSB__LEN		8
#define BNO055_MAG_OFFSET_Z_MSB__REG		MAG_OFFSET_Z_MSB_ADDR

/* Gyro Offset registers*/
#define BNO055_GYRO_OFFSET_X_LSB__POS		0
#define BNO055_GYRO_OFFSET_X_LSB__MSK		0XFF
#define BNO055_GYRO_OFFSET_X_LSB__LEN		8
#define BNO055_GYRO_OFFSET_X_LSB__REG		GYRO_OFFSET_X_LSB_ADDR

#define BNO055_GYRO_OFFSET_X_MSB__POS		0
#define BNO055_GYRO_OFFSET_X_MSB__MSK		0XFF
#define BNO055_GYRO_OFFSET_X_MSB__LEN		8
#define BNO055_GYRO_OFFSET_X_MSB__REG		GYRO_OFFSET_X_MSB_ADDR

#define BNO055_GYRO_OFFSET_Y_LSB__POS		0
#define BNO055_GYRO_OFFSET_Y_LSB__MSK		0XFF
#define BNO055_GYRO_OFFSET_Y_LSB__LEN		8
#define BNO055_GYRO_OFFSET_Y_LSB__REG		GYRO_OFFSET_Y_LSB_ADDR

#define BNO055_GYRO_OFFSET_Y_MSB__POS		0
#define BNO055_GYRO_OFFSET_Y_MSB__MSK		0XFF
#define BNO055_GYRO_OFFSET_Y_MSB__LEN		8
#define BNO055_GYRO_OFFSET_Y_MSB__REG		GYRO_OFFSET_Y_MSB_ADDR

#define BNO055_GYRO_OFFSET_Z_LSB__POS		0
#define BNO055_GYRO_OFFSET_Z_LSB__MSK		0XFF
#define BNO055_GYRO_OFFSET_Z_LSB__LEN		8
#define BNO055_GYRO_OFFSET_Z_LSB__REG		GYRO_OFFSET_Z_LSB_ADDR

#define BNO055_GYRO_OFFSET_Z_MSB__POS		0
#define BNO055_GYRO_OFFSET_Z_MSB__MSK		0XFF
#define BNO055_GYRO_OFFSET_Z_MSB__LEN		8
#define BNO055_GYRO_OFFSET_Z_MSB__REG		GYRO_OFFSET_Z_MSB_ADDR

/* Radius register definition*/
#define BNO055_ACCEL_RADIUS_LSB__POS		0
#define BNO055_ACCEL_RADIUS_LSB__MSK		0XFF
#define BNO055_ACCEL_RADIUS_LSB__LEN		8
#define BNO055_ACCEL_RADIUS_LSB__REG		ACCEL_RADIUS_LSB_ADDR

#define BNO055_ACCEL_RADIUS_MSB__POS		0
#define BNO055_ACCEL_RADIUS_MSB__MSK		0XFF
#define BNO055_ACCEL_RADIUS_MSB__LEN		8
#define BNO055_ACCEL_RADIUS_MSB__REG		ACCEL_RADIUS_MSB_ADDR

#define BNO055_MAG_RADIUS_LSB__POS		0
#define BNO055_MAG_RADIUS_LSB__MSK		0XFF
#define BNO055_MAG_RADIUS_LSB__LEN		8
#define BNO055_MAG_RADIUS_LSB__REG		MAG_RADIUS_LSB_ADDR

#define BNO055_MAG_RADIUS_MSB__POS		0
#define BNO055_MAG_RADIUS_MSB__MSK		0XFF
#define BNO055_MAG_RADIUS_MSB__LEN		8
#define BNO055_MAG_RADIUS_MSB__REG		MAG_RADIUS_MSB_ADDR

/* PAGE0 DATA REGISTERS DEFINITION END*/
/*************************************************/
/**\name PAGE1 DATA REGISTERS DEFINITION   */
/*************************************************/
/* Configuration registers*/
/* Accel range configuration register*/
#define BNO055_ACCEL_RANGE__POS		0
#define BNO055_ACCEL_RANGE__MSK		0X03
#define BNO055_ACCEL_RANGE__LEN		2
#define BNO055_ACCEL_RANGE__REG		ACCEL_CONFIG_ADDR

/* Accel bandwidth configuration register*/
#define BNO055_ACCEL_BW__POS			2
#define BNO055_ACCEL_BW__MSK			0X1C
#define BNO055_ACCEL_BW__LEN			3
#define BNO055_ACCEL_BW__REG			ACCEL_CONFIG_ADDR

/* Accel power mode configuration register*/
#define BNO055_ACCEL_POWER_MODE__POS		5
#define BNO055_ACCEL_POWER_MODE__MSK		0XE0
#define BNO055_ACCEL_POWER_MODE__LEN		3
#define BNO055_ACCEL_POWER_MODE__REG		ACCEL_CONFIG_ADDR

/* Mag data output rate configuration register*/
#define BNO055_MAG_DATA_OUTPUT_RATE__POS		0
#define BNO055_MAG_DATA_OUTPUT_RATE__MSK		0X07
#define BNO055_MAG_DATA_OUTPUT_RATE__LEN		3
#define BNO055_MAG_DATA_OUTPUT_RATE__REG		MAG_CONFIG_ADDR

/* Mag operation mode configuration register*/
#define BNO055_MAG_OPERATION_MODE__POS		3
#define BNO055_MAG_OPERATION_MODE__MSK		0X18
#define BNO055_MAG_OPERATION_MODE__LEN		2
#define BNO055_MAG_OPERATION_MODE__REG		MAG_CONFIG_ADDR

/* Mag power mode configuration register*/
#define BNO055_MAG_POWER_MODE__POS		5
#define BNO055_MAG_POWER_MODE__MSK		0X60
#define BNO055_MAG_POWER_MODE__LEN		2
#define BNO055_MAG_POWER_MODE__REG		MAG_CONFIG_ADDR

/* Gyro range configuration register*/
#define BNO055_GYRO_RANGE__POS		0
#define BNO055_GYRO_RANGE__MSK		0X07
#define BNO055_GYRO_RANGE__LEN		3
#define BNO055_GYRO_RANGE__REG		GYRO_CONFIG_ADDR

/* Gyro bandwidth configuration register*/
#define BNO055_GYRO_BW__POS		3
#define BNO055_GYRO_BW__MSK		0X38
#define BNO055_GYRO_BW__LEN		3
#define BNO055_GYRO_BW__REG		GYRO_CONFIG_ADDR

/* Gyro power mode configuration register*/
#define BNO055_GYRO_POWER_MODE__POS		0
#define BNO055_GYRO_POWER_MODE__MSK		0X07
#define BNO055_GYRO_POWER_MODE__LEN		3
#define BNO055_GYRO_POWER_MODE__REG		GYRO_MODE_CONFIG_ADDR

/* Sleep configuration registers*/
/* Accel sleep mode configuration register*/
#define BNO055_ACCEL_SLEEP_MODE__POS		0
#define BNO055_ACCEL_SLEEP_MODE__MSK		0X01
#define BNO055_ACCEL_SLEEP_MODE__LEN		1
#define BNO055_ACCEL_SLEEP_MODE__REG		ACCEL_SLEEP_CONFIG_ADDR

/* Accel sleep duration configuration register*/
#define BNO055_ACCEL_SLEEP_DURN__POS		1
#define BNO055_ACCEL_SLEEP_DURN__MSK		0X1E
#define BNO055_ACCEL_SLEEP_DURN__LEN		4
#define BNO055_ACCEL_SLEEP_DURN__REG		ACCEL_SLEEP_CONFIG_ADDR

/* Gyro sleep duration configuration register*/
#define BNO055_GYRO_SLEEP_DURN__POS		0
#define BNO055_GYRO_SLEEP_DURN__MSK		0X07
#define BNO055_GYRO_SLEEP_DURN__LEN		3
#define BNO055_GYRO_SLEEP_DURN__REG		GYRO_SLEEP_CONFIG_ADDR

/* Gyro auto sleep duration configuration register*/
#define BNO055_GYRO_AUTO_SLEEP_DURN__POS		3
#define BNO055_GYRO_AUTO_SLEEP_DURN__MSK		0X38
#define BNO055_GYRO_AUTO_SLEEP_DURN__LEN		3
#define BNO055_GYRO_AUTO_SLEEP_DURN__REG		GYRO_SLEEP_CONFIG_ADDR

/* Mag sleep mode configuration register*/
#define BNO055_MAG_SLEEP_MODE__POS		0
#define BNO055_MAG_SLEEP_MODE__MSK		0X01
#define BNO055_MAG_SLEEP_MODE__LEN		1
#define BNO055_MAG_SLEEP_MODE__REG		MAG_SLEEP_CONFIG_ADDR

/* Mag sleep duration configuration register*/
#define BNO055_MAG_SLEEP_DURN__POS		1
#define BNO055_MAG_SLEEP_DURN__MSK		0X1E
#define BNO055_MAG_SLEEP_DURN__LEN		4
#define BNO055_MAG_SLEEP_DURN__REG		MAG_SLEEP_CONFIG_ADDR

/* Interrupt registers*/
/* Gyro any motion interrupt msk register*/
#define BNO055_GYRO_ANY_MOTION_INTR_MASK__POS		2
#define BNO055_GYRO_ANY_MOTION_INTR_MASK__MSK		0X04
#define BNO055_GYRO_ANY_MOTION_INTR_MASK__LEN		1
#define BNO055_GYRO_ANY_MOTION_INTR_MASK__REG		INT_MASK_ADDR

/* Gyro high rate interrupt msk register*/
#define BNO055_GYRO_HIGHRATE_INTR_MASK__POS		3
#define BNO055_GYRO_HIGHRATE_INTR_MASK__MSK		0X08
#define BNO055_GYRO_HIGHRATE_INTR_MASK__LEN		1
#define BNO055_GYRO_HIGHRATE_INTR_MASK__REG		INT_MASK_ADDR

/* Accel high g interrupt msk register*/
#define BNO055_ACCEL_HIGH_G_INTR_MASK__POS		5
#define BNO055_ACCEL_HIGH_G_INTR_MASK__MSK		0X20
#define BNO055_ACCEL_HIGH_G_INTR_MASK__LEN		1
#define BNO055_ACCEL_HIGH_G_INTR_MASK__REG		INT_MASK_ADDR

/* Accel any motion interrupt msk register*/
#define BNO055_ACCEL_ANY_MOTION_INTR_MASK__POS		6
#define BNO055_ACCEL_ANY_MOTION_INTR_MASK__MSK		0X40
#define BNO055_ACCEL_ANY_MOTION_INTR_MASK__LEN		1
#define BNO055_ACCEL_ANY_MOTION_INTR_MASK__REG		INT_MASK_ADDR

/* Accel any motion interrupt msk register*/
#define BNO055_ACCEL_NO_MOTION_INTR_MASK__POS		7
#define BNO055_ACCEL_NO_MOTION_INTR_MASK__MSK		0X80
#define BNO055_ACCEL_NO_MOTION_INTR_MASK__LEN		1
#define BNO055_ACCEL_NO_MOTION_INTR_MASK__REG		INT_MASK_ADDR

/* Gyro any motion interrupt register*/
#define BNO055_GYRO_ANY_MOTION_INTR__POS		2
#define BNO055_GYRO_ANY_MOTION_INTR__MSK		0X04
#define BNO055_GYRO_ANY_MOTION_INTR__LEN		1
#define BNO055_GYRO_ANY_MOTION_INTR__REG		INT_ADDR

/* Gyro high rate interrupt register*/
#define BNO055_GYRO_HIGHRATE_INTR__POS		3
#define BNO055_GYRO_HIGHRATE_INTR__MSK		0X08
#define BNO055_GYRO_HIGHRATE_INTR__LEN		1
#define BNO055_GYRO_HIGHRATE_INTR__REG		INT_ADDR

/* Accel high g interrupt register*/
#define BNO055_ACCEL_HIGH_G_INTR__POS		5
#define BNO055_ACCEL_HIGH_G_INTR__MSK		0X20
#define BNO055_ACCEL_HIGH_G_INTR__LEN		1
#define BNO055_ACCEL_HIGH_G_INTR__REG		INT_ADDR

/* Accel any motion interrupt register*/
#define BNO055_ACCEL_ANY_MOTION_INTR__POS		6
#define BNO055_ACCEL_ANY_MOTION_INTR__MSK		0X40
#define BNO055_ACCEL_ANY_MOTION_INTR__LEN		1
#define BNO055_ACCEL_ANY_MOTION_INTR__REG		INT_ADDR

/*Accel any motion interrupt register*/
#define BNO055_ACCEL_NO_MOTION_INTR__POS		7
#define BNO055_ACCEL_NO_MOTION_INTR__MSK		0X80
#define BNO055_ACCEL_NO_MOTION_INTR__LEN		1
#define BNO055_ACCEL_NO_MOTION_INTR__REG		INT_ADDR

/*Accel any motion threshold setting*/
#define BNO055_ACCEL_ANY_MOTION_THRES__POS	0
#define BNO055_ACCEL_ANY_MOTION_THRES__MSK	0XFF
#define BNO055_ACCEL_ANY_MOTION_THRES__LEN	8
#define BNO055_ACCEL_ANY_MOTION_THRES__REG	ACCEL_ANY_MOTION_THRES_ADDR

/*Accel interrupt setting register*/
#define BNO055_ACCEL_ANY_MOTION_DURN_SET__POS		0
#define BNO055_ACCEL_ANY_MOTION_DURN_SET__MSK		0X03
#define BNO055_ACCEL_ANY_MOTION_DURN_SET__LEN		2
#define BNO055_ACCEL_ANY_MOTION_DURN_SET__REG		ACCEL_INTR_SETTINGS_ADDR

/* Accel AM/NM axis selection register*/
#define BNO055_ACCEL_ANY_MOTION_X_AXIS__POS		2
#define BNO055_ACCEL_ANY_MOTION_X_AXIS__MSK		0X04
#define BNO055_ACCEL_ANY_MOTION_X_AXIS__LEN		1
#define BNO055_ACCEL_ANY_MOTION_X_AXIS__REG		ACCEL_INTR_SETTINGS_ADDR

#define BNO055_ACCEL_ANY_MOTION_Y_AXIS__POS		3
#define BNO055_ACCEL_ANY_MOTION_Y_AXIS__MSK		0X08
#define BNO055_ACCEL_ANY_MOTION_Y_AXIS__LEN		1
#define BNO055_ACCEL_ANY_MOTION_Y_AXIS__REG		ACCEL_INTR_SETTINGS_ADDR

#define BNO055_ACCEL_ANY_MOTION_Z_AXIS__POS		4
#define BNO055_ACCEL_ANY_MOTION_Z_AXIS__MSK		0X10
#define BNO055_ACCEL_ANY_MOTION_Z_AXIS__LEN		1
#define BNO055_ACCEL_ANY_MOTION_Z_AXIS__REG		ACCEL_INTR_SETTINGS_ADDR

/* Accel high g axis selection register*/
#define BNO055_ACCEL_HIGH_G_X_AXIS__POS		5
#define BNO055_ACCEL_HIGH_G_X_AXIS__MSK		0X20
#define BNO055_ACCEL_HIGH_G_X_AXIS__LEN		1
#define BNO055_ACCEL_HIGH_G_X_AXIS__REG		ACCEL_INTR_SETTINGS_ADDR

#define BNO055_ACCEL_HIGH_G_Y_AXIS__POS		6
#define BNO055_ACCEL_HIGH_G_Y_AXIS__MSK		0X40
#define BNO055_ACCEL_HIGH_G_Y_AXIS__LEN		1
#define BNO055_ACCEL_HIGH_G_Y_AXIS__REG		ACCEL_INTR_SETTINGS_ADDR

#define BNO055_ACCEL_HIGH_G_Z_AXIS__POS		7
#define BNO055_ACCEL_HIGH_G_Z_AXIS__MSK		0X80
#define BNO055_ACCEL_HIGH_G_Z_AXIS__LEN		1
#define BNO055_ACCEL_HIGH_G_Z_AXIS__REG		ACCEL_INTR_SETTINGS_ADDR

/* Accel High g duration setting register*/
#define BNO055_ACCEL_HIGH_G_DURN__POS		0
#define BNO055_ACCEL_HIGH_G_DURN__MSK		0XFF
#define BNO055_ACCEL_HIGH_G_DURN__LEN		8
#define BNO055_ACCEL_HIGH_G_DURN__REG		ACCEL_HIGH_G_DURN_ADDR

/* Accel High g threshold setting register*/
#define BNO055_ACCEL_HIGH_G_THRES__POS		0
#define BNO055_ACCEL_HIGH_G_THRES__MSK		0XFF
#define BNO055_ACCEL_HIGH_G_THRES__LEN		8
#define BNO055_ACCEL_HIGH_G_THRES__REG		ACCEL_HIGH_G_THRES_ADDR

/* Accel no/slow motion threshold setting*/
#define BNO055_ACCEL_SLOW_NO_MOTION_THRES__POS		0
#define BNO055_ACCEL_SLOW_NO_MOTION_THRES__MSK		0XFF
#define BNO055_ACCEL_SLOW_NO_MOTION_THRES__LEN		8
#define BNO055_ACCEL_SLOW_NO_MOTION_THRES__REG		\
ACCEL_NO_MOTION_THRES_ADDR

/* Accel no/slow motion enable setting*/
#define BNO055_ACCEL_SLOW_NO_MOTION_ENABLE__POS		0
#define BNO055_ACCEL_SLOW_NO_MOTION_ENABLE__MSK		0X01
#define BNO055_ACCEL_SLOW_NO_MOTION_ENABLE__LEN		1
#define BNO055_ACCEL_SLOW_NO_MOTION_ENABLE__REG		ACCEL_NO_MOTION_SET_ADDR

/* Accel no/slow motion duration setting*/
#define BNO055_ACCEL_SLOW_NO_MOTION_DURN__POS		1
#define BNO055_ACCEL_SLOW_NO_MOTION_DURN__MSK		0X7E
#define BNO055_ACCEL_SLOW_NO_MOTION_DURN__LEN		6
#define BNO055_ACCEL_SLOW_NO_MOTION_DURN__REG		ACCEL_NO_MOTION_SET_ADDR

/*Gyro interrupt setting register*/
/*Gyro any motion axis setting*/
#define BNO055_GYRO_ANY_MOTION_X_AXIS__POS		0
#define BNO055_GYRO_ANY_MOTION_X_AXIS__MSK		0X01
#define BNO055_GYRO_ANY_MOTION_X_AXIS__LEN		1
#define BNO055_GYRO_ANY_MOTION_X_AXIS__REG		GYRO_INTR_SETING_ADDR

#define BNO055_GYRO_ANY_MOTION_Y_AXIS__POS		1
#define BNO055_GYRO_ANY_MOTION_Y_AXIS__MSK		0X02
#define BNO055_GYRO_ANY_MOTION_Y_AXIS__LEN		1
#define BNO055_GYRO_ANY_MOTION_Y_AXIS__REG		GYRO_INTR_SETING_ADDR

#define BNO055_GYRO_ANY_MOTION_Z_AXIS__POS		2
#define BNO055_GYRO_ANY_MOTION_Z_AXIS__MSK		0X04
#define BNO055_GYRO_ANY_MOTION_Z_AXIS__LEN		1
#define BNO055_GYRO_ANY_MOTION_Z_AXIS__REG		GYRO_INTR_SETING_ADDR

/*Gyro high rate axis setting*/
#define BNO055_GYRO_HIGHRATE_X_AXIS__POS		3
#define BNO055_GYRO_HIGHRATE_X_AXIS__MSK		0X08
#define BNO055_GYRO_HIGHRATE_X_AXIS__LEN		1
#define BNO055_GYRO_HIGHRATE_X_AXIS__REG		GYRO_INTR_SETING_ADDR

#define BNO055_GYRO_HIGHRATE_Y_AXIS__POS		4
#define BNO055_GYRO_HIGHRATE_Y_AXIS__MSK		0X10
#define BNO055_GYRO_HIGHRATE_Y_AXIS__LEN		1
#define BNO055_GYRO_HIGHRATE_Y_AXIS__REG		GYRO_INTR_SETING_ADDR

#define BNO055_GYRO_HIGHRATE_Z_AXIS__POS		5
#define BNO055_GYRO_HIGHRATE_Z_AXIS__MSK		0X20
#define BNO055_GYRO_HIGHRATE_Z_AXIS__LEN		1
#define BNO055_GYRO_HIGHRATE_Z_AXIS__REG		GYRO_INTR_SETING_ADDR

/* Gyro filter setting*/
#define BNO055_GYRO_ANY_MOTION_FILTER__POS		6
#define BNO055_GYRO_ANY_MOTION_FILTER__MSK		0X40
#define BNO055_GYRO_ANY_MOTION_FILTER__LEN		1
#define BNO055_GYRO_ANY_MOTION_FILTER__REG		GYRO_INTR_SETING_ADDR

#define BNO055_GYRO_HIGHRATE_FILTER__POS		7
#define BNO055_GYRO_HIGHRATE_FILTER__MSK		0X80
#define BNO055_GYRO_HIGHRATE_FILTER__LEN		1
#define BNO055_GYRO_HIGHRATE_FILTER__REG		GYRO_INTR_SETING_ADDR

/* Gyro high rate X axis settings*/
#define BNO055_GYRO_HIGHRATE_X_THRES__POS		0
#define BNO055_GYRO_HIGHRATE_X_THRES__MSK		0X1F
#define BNO055_GYRO_HIGHRATE_X_THRES__LEN		5
#define BNO055_GYRO_HIGHRATE_X_THRES__REG		GYRO_HIGHRATE_X_SET_ADDR

#define BNO055_GYRO_HIGHRATE_X_HYST__POS		5
#define BNO055_GYRO_HIGHRATE_X_HYST__MSK		0X60
#define BNO055_GYRO_HIGHRATE_X_HYST__LEN		2
#define BNO055_GYRO_HIGHRATE_X_HYST__REG		GYRO_HIGHRATE_X_SET_ADDR

#define BNO055_GYRO_HIGHRATE_X_DURN__POS		0
#define BNO055_GYRO_HIGHRATE_X_DURN__MSK		0XFF
#define BNO055_GYRO_HIGHRATE_X_DURN__LEN		8
#define BNO055_GYRO_HIGHRATE_X_DURN__REG		GYRO_DURN_X_ADDR

/* Gyro high rate Y axis settings*/
#define BNO055_GYRO_HIGHRATE_Y_THRES__POS		0
#define BNO055_GYRO_HIGHRATE_Y_THRES__MSK		0X1F
#define BNO055_GYRO_HIGHRATE_Y_THRES__LEN		5
#define BNO055_GYRO_HIGHRATE_Y_THRES__REG		GYRO_HIGHRATE_Y_SET_ADDR

#define BNO055_GYRO_HIGHRATE_Y_HYST__POS		5
#define BNO055_GYRO_HIGHRATE_Y_HYST__MSK		0X60
#define BNO055_GYRO_HIGHRATE_Y_HYST__LEN		2
#define BNO055_GYRO_HIGHRATE_Y_HYST__REG		GYRO_HIGHRATE_Y_SET_ADDR

#define BNO055_GYRO_HIGHRATE_Y_DURN__POS		0
#define BNO055_GYRO_HIGHRATE_Y_DURN__MSK		0XFF
#define BNO055_GYRO_HIGHRATE_Y_DURN__LEN		8
#define BNO055_GYRO_HIGHRATE_Y_DURN__REG		GYRO_DURN_Y_ADDR

/* Gyro high rate Z axis settings*/
#define BNO055_GYRO_HIGHRATE_Z_THRES__POS		0
#define BNO055_GYRO_HIGHRATE_Z_THRES__MSK		0X1F
#define BNO055_GYRO_HIGHRATE_Z_THRES__LEN		5
#define BNO055_GYRO_HIGHRATE_Z_THRES__REG		GYRO_HIGHRATE_Z_SET_ADDR

#define BNO055_GYRO_HIGHRATE_Z_HYST__POS		5
#define BNO055_GYRO_HIGHRATE_Z_HYST__MSK		0X60
#define BNO055_GYRO_HIGHRATE_Z_HYST__LEN		2
#define BNO055_GYRO_HIGHRATE_Z_HYST__REG		GYRO_HIGHRATE_Z_SET_ADDR

#define BNO055_GYRO_HIGHRATE_Z_DURN__POS		0
#define BNO055_GYRO_HIGHRATE_Z_DURN__MSK		0XFF
#define BNO055_GYRO_HIGHRATE_Z_DURN__LEN		8
#define BNO055_GYRO_HIGHRATE_Z_DURN__REG		GYRO_DURN_Z_ADDR

/*Gyro any motion threshold setting*/
#define BNO055_GYRO_ANY_MOTION_THRES__POS		0
#define BNO055_GYRO_ANY_MOTION_THRES__MSK		0X7F
#define BNO055_GYRO_ANY_MOTION_THRES__LEN		7
#define BNO055_GYRO_ANY_MOTION_THRES__REG		\
GYRO_ANY_MOTION_THRES_ADDR

/* Gyro any motion slope sample setting*/
#define BNO055_GYRO_SLOPE_SAMPLES__POS		0
#define BNO055_GYRO_SLOPE_SAMPLES__MSK		0X03
#define BNO055_GYRO_SLOPE_SAMPLES__LEN		2
#define BNO055_GYRO_SLOPE_SAMPLES__REG		GYRO_ANY_MOTION_SET_ADDR

/* Gyro awake duration setting*/
#define BNO055_GYRO_AWAKE_DURN__POS		2
#define BNO055_GYRO_AWAKE_DURN__MSK		0X0C
#define BNO055_GYRO_AWAKE_DURN__LEN		2
#define BNO055_GYRO_AWAKE_DURN__REG		GYRO_ANY_MOTION_SET_ADDR

/********************************************************/
/**\name	I2C ADDRESS DEFINITION FOR BNO055           */
/********************************************************/
/* bno055 I2C Address */
#define BNO055_I2C_ADDR1                0x28
#define BNO055_I2C_ADDR2                0x29

/***************************************************/
/**\name	REGISTER ADDRESS DEFINITION  */
/***************************************************/
/* Page id register definition*/
#define BNO055_PAGE_ID_ADDR				    0X07

/* PAGE0 REGISTER DEFINITION START*/
#define BNO055_CHIP_ID_ADDR                 0x00
#define BNO055_ACCEL_REV_ID_ADDR			0x01
#define BNO055_MAG_REV_ID_ADDR              0x02
#define BNO055_GYRO_REV_ID_ADDR             0x03
#define BNO055_SW_REV_ID_LSB_ADDR			0x04
#define BNO055_SW_REV_ID_MSB_ADDR			0x05
#define BNO055_BL_REV_ID_ADDR				0X06

/* Accel data register*/
#define BNO055_ACCEL_DATA_X_LSB_ADDR			0X08
#define BNO055_ACCEL_DATA_X_MSB_ADDR			0X09
#define BNO055_ACCEL_DATA_Y_LSB_ADDR			0X0A
#define BNO055_ACCEL_DATA_Y_MSB_ADDR			0X0B
#define BNO055_ACCEL_DATA_Z_LSB_ADDR			0X0C
#define BNO055_ACCEL_DATA_Z_MSB_ADDR			0X0D

/*Mag data register*/
#define BNO055_MAG_DATA_X_LSB_ADDR			0X0E
#define BNO055_MAG_DATA_X_MSB_ADDR			0X0F
#define BNO055_MAG_DATA_Y_LSB_ADDR			0X10
#define BNO055_MAG_DATA_Y_MSB_ADDR			0X11
#define BNO055_MAG_DATA_Z_LSB_ADDR			0X12
#define BNO055_MAG_DATA_Z_MSB_ADDR			0X13

/*Gyro data registers*/
#define BNO055_GYRO_DATA_X_LSB_ADDR			0X14
#define BNO055_GYRO_DATA_X_MSB_ADDR			0X15
#define BNO055_GYRO_DATA_Y_LSB_ADDR			0X16
#define BNO055_GYRO_DATA_Y_MSB_ADDR			0X17
#define BNO055_GYRO_DATA_Z_LSB_ADDR			0X18
#define BNO055_GYRO_DATA_Z_MSB_ADDR			0X19

/*Euler data registers*/
#define BNO055_EULER_H_LSB_ADDR			0X1A
#define BNO055_EULER_H_MSB_ADDR			0X1B

#define BNO055_EULER_R_LSB_ADDR			0X1C
#define BNO055_EULER_R_MSB_ADDR			0X1D

#define BNO055_EULER_P_LSB_ADDR			0X1E
#define BNO055_EULER_P_MSB_ADDR			0X1F

/*Quaternion data registers*/
#define BNO055_QUATERNION_DATA_W_LSB_ADDR	0X20
#define BNO055_QUATERNION_DATA_W_MSB_ADDR	0X21
#define BNO055_QUATERNION_DATA_X_LSB_ADDR	0X22
#define BNO055_QUATERNION_DATA_X_MSB_ADDR	0X23
#define BNO055_QUATERNION_DATA_Y_LSB_ADDR	0X24
#define BNO055_QUATERNION_DATA_Y_MSB_ADDR	0X25
#define BNO055_QUATERNION_DATA_Z_LSB_ADDR	0X26
#define BNO055_QUATERNION_DATA_Z_MSB_ADDR	0X27

/* Linear acceleration data registers*/
#define BNO055_LINEAR_ACCEL_DATA_X_LSB_ADDR			0X28
#define BNO055_LINEAR_ACCEL_DATA_X_MSB_ADDR			0X29
#define BNO055_LINEAR_ACCEL_DATA_Y_LSB_ADDR			0X2A
#define BNO055_LINEAR_ACCEL_DATA_Y_MSB_ADDR			0X2B
#define BNO055_LINEAR_ACCEL_DATA_Z_LSB_ADDR			0X2C
#define BNO055_LINEAR_ACCEL_DATA_Z_MSB_ADDR			0X2D

/*Gravity data registers*/
#define BNO055_GRAVITY_DATA_X_LSB_ADDR			0X2E
#define BNO055_GRAVITY_DATA_X_MSB_ADDR			0X2F
#define BNO055_GRAVITY_DATA_Y_LSB_ADDR			0X30
#define BNO055_GRAVITY_DATA_Y_MSB_ADDR			0X31
#define BNO055_GRAVITY_DATA_Z_LSB_ADDR			0X32
#define BNO055_GRAVITY_DATA_Z_MSB_ADDR			0X33

/* Temperature data register*/
#define BNO055_TEMP_ADDR					0X34

/* Status registers*/
#define BNO055_CALIB_STAT_ADDR				0X35
#define BNO055_SELFTEST_RESULT_ADDR			0X36
#define BNO055_INTR_STAT_ADDR				0X37
#define BNO055_SYS_CLK_STAT_ADDR			0X38
#define BNO055_SYS_STAT_ADDR				0X39
#define BNO055_SYS_ERR_ADDR					0X3A

/* Unit selection register*/
#define BNO055_UNIT_SEL_ADDR				0X3B
#define BNO055_DATA_SELECT_ADDR				0X3C

/* Mode registers*/
#define BNO055_OPR_MODE_ADDR				0X3D
#define BNO055_PWR_MODE_ADDR				0X3E

#define BNO055_SYS_TRIGGER_ADDR				0X3F
#define BNO055_TEMP_SOURCE_ADDR				0X40
/* Axis remap registers*/
#define BNO055_AXIS_MAP_CONFIG_ADDR			0X41
#define BNO055_AXIS_MAP_SIGN_ADDR			0X42

/* SIC registers*/
#define BNO055_SIC_MATRIX_0_LSB_ADDR		0X43
#define BNO055_SIC_MATRIX_0_MSB_ADDR		0X44
#define BNO055_SIC_MATRIX_1_LSB_ADDR		0X45
#define BNO055_SIC_MATRIX_1_MSB_ADDR		0X46
#define BNO055_SIC_MATRIX_2_LSB_ADDR		0X47
#define BNO055_SIC_MATRIX_2_MSB_ADDR		0X48
#define BNO055_SIC_MATRIX_3_LSB_ADDR		0X49
#define BNO055_SIC_MATRIX_3_MSB_ADDR		0X4A
#define BNO055_SIC_MATRIX_4_LSB_ADDR		0X4B
#define BNO055_SIC_MATRIX_4_MSB_ADDR		0X4C
#define BNO055_SIC_MATRIX_5_LSB_ADDR		0X4D
#define BNO055_SIC_MATRIX_5_MSB_ADDR		0X4E
#define BNO055_SIC_MATRIX_6_LSB_ADDR		0X4F
#define BNO055_SIC_MATRIX_6_MSB_ADDR		0X50
#define BNO055_SIC_MATRIX_7_LSB_ADDR		0X51
#define BNO055_SIC_MATRIX_7_MSB_ADDR		0X52
#define BNO055_SIC_MATRIX_8_LSB_ADDR		0X53
#define BNO055_SIC_MATRIX_8_MSB_ADDR		0X54

/* Accelerometer Offset registers*/
#define ACCEL_OFFSET_X_LSB_ADDR				0X55
#define ACCEL_OFFSET_X_MSB_ADDR				0X56
#define ACCEL_OFFSET_Y_LSB_ADDR				0X57
#define ACCEL_OFFSET_Y_MSB_ADDR				0X58
#define ACCEL_OFFSET_Z_LSB_ADDR				0X59
#define ACCEL_OFFSET_Z_MSB_ADDR				0X5A

/* Magnetometer Offset registers*/
#define MAG_OFFSET_X_LSB_ADDR				0X5B
#define MAG_OFFSET_X_MSB_ADDR				0X5C
#define MAG_OFFSET_Y_LSB_ADDR				0X5D
#define MAG_OFFSET_Y_MSB_ADDR				0X5E
#define MAG_OFFSET_Z_LSB_ADDR				0X5F
#define MAG_OFFSET_Z_MSB_ADDR				0X60

/* Gyroscope Offset registers*/
#define GYRO_OFFSET_X_LSB_ADDR				0X61
#define GYRO_OFFSET_X_MSB_ADDR				0X62
#define GYRO_OFFSET_Y_LSB_ADDR				0X63
#define GYRO_OFFSET_Y_MSB_ADDR				0X64
#define GYRO_OFFSET_Z_LSB_ADDR				0X65
#define GYRO_OFFSET_Z_MSB_ADDR				0X66

/* Radius registers*/
#define	ACCEL_RADIUS_LSB_ADDR				0X67
#define	ACCEL_RADIUS_MSB_ADDR				0X68
#define	MAG_RADIUS_LSB_ADDR					0X69
#define	MAG_RADIUS_MSB_ADDR					0X6A
/* PAGE0 REGISTERS DEFINITION END*/

/* PAGE1 REGISTERS DEFINITION START*/
/* Configuration registers*/
#define ACCEL_CONFIG_ADDR					0X08
#define MAG_CONFIG_ADDR						0X09
#define GYRO_CONFIG_ADDR					0X0A
#define GYRO_MODE_CONFIG_ADDR				0X0B
#define ACCEL_SLEEP_CONFIG_ADDR				0X0C
#define GYRO_SLEEP_CONFIG_ADDR				0X0D
#define MAG_SLEEP_CONFIG_ADDR				0x0E

/* Interrupt registers*/
#define INT_MASK_ADDR						0X0F
#define INT_ADDR							0X10
#define ACCEL_ANY_MOTION_THRES_ADDR			0X11
#define ACCEL_INTR_SETTINGS_ADDR				0X12
#define ACCEL_HIGH_G_DURN_ADDR				0X13
#define ACCEL_HIGH_G_THRES_ADDR				0X14
#define ACCEL_NO_MOTION_THRES_ADDR			0X15
#define ACCEL_NO_MOTION_SET_ADDR				0X16
#define GYRO_INTR_SETING_ADDR				0X17
#define GYRO_HIGHRATE_X_SET_ADDR			0X18
#define GYRO_DURN_X_ADDR						0X19
#define GYRO_HIGHRATE_Y_SET_ADDR			0X1A
#define GYRO_DURN_Y_ADDR						0X1B
#define GYRO_HIGHRATE_Z_SET_ADDR			0X1C
#define GYRO_DURN_Z_ADDR						0X1D
#define GYRO_ANY_MOTION_THRES_ADDR			0X1E
#define GYRO_ANY_MOTION_SET_ADDR				0X1F
/* PAGE1 REGISTERS DEFINITION END*/


#define BNO055_MDELAY_DATA_TYPE           u32

/*< This refers BNO055 return type as s8 */
#define BNO055_RETURN_FUNCTION_TYPE        s8

/* Compile switch definition for Float and double*/
#define BNO055_FLOAT_ENABLE
#define BNO055_DOUBLE_ENABLE

/**************************************************************/
/**\name	STRUCTURE DEFINITIONS                         */
/**************************************************************/
/*!
*	@brief bno055 struct
*/
struct bno055_t {
u8 chip_id;/**< chip_id of bno055 */
u16 sw_rev_id;/**< software revision id of bno055 */
u8 page_id;/**< page_id of bno055 */
u8 accel_rev_id;/**< accel revision id of bno055 */
u8 mag_rev_id;/**< mag revision id of bno055 */
u8 gyro_rev_id;/**< gyro revision id of bno055 */
u8 bl_rev_id;/**< boot loader revision id of bno055 */
u8 dev_addr;/**< i2c device address of bno055 */
void (*delay_msec)(BNO055_MDELAY_DATA_TYPE);/**< delay function pointer */
};
/*!
* @brief struct for accel data read from registers
*/
struct bno055_accel_t {
s16 x;/**< accel x data */
s16 y;/**< accel y data */
s16 z;/**< accel z data */
};
/*!
* @brief struct for Mag data read from registers
*/
struct bno055_mag_t {
s16 x;/**< mag x data */
s16 y;/**< mag y data */
s16 z;/**< mag z data */
};
/*!
* @brief struct for Gyro data read from registers
*/
struct bno055_gyro_t {
s16 x;/**< gyro x data */
s16 y;/**< gyro y data */
s16 z;/**< gyro z data */
};
/*!
* @brief struct for Euler data read from registers
*/
struct bno055_euler_t {
s16 h;/**< Euler h data */
s16 r;/**< Euler r data */
s16 p;/**< Euler p data */
};
/*!
* @brief struct for Quaternion data read from registers
*/
struct bno055_quaternion_t {
s16 w;/**< Quaternion w data */
s16 x;/**< Quaternion x data */
s16 y;/**< Quaternion y data */
s16 z;/**< Quaternion z data */
};
/*!
* @brief struct for Linear Accel data read from registers
*/
struct bno055_linear_accel_t {
s16 x; /**< Linear Accel x data */
s16 y; /**< Linear Accel y data */
s16 z; /**< Linear Accel z data */
};
/*!
* @brief struct for Gravity data read from registers
*/
struct bno055_gravity_t {
s16 x;/**< Gravity x data */
s16 y;/**< Gravity y data */
s16 z;/**< Gravity z data */
};
#ifdef	BNO055_DOUBLE_ENABLE
/*!
* @brief struct for Accel-output data of precision double
*/
struct bno055_accel_double_t {
double x;/**< Accel x double data */
double y;/**< Accel y double data */
double z;/**< Accel z double data */
};
/*!
* @brief struct for Mag-output data of precision double
*/
struct bno055_mag_double_t {
double x;/**< Mag x double data */
double y;/**< Mag y double data */
double z;/**< Mag z double data */
};
/*!
* @brief struct for Gyro-output data of precision double
*/
struct bno055_gyro_double_t {
double x;/**< Gyro x double data */
double y;/**< Gyro y double data */
double z;/**< Gyro z double data */
};
/*!
* @brief struct for Euler-output data of precision double
*/
struct bno055_euler_double_t {
double h;/**< Euler h double data */
double r;/**< Euler r double data */
double p;/**< Euler p double data */
};
/*!
* @brief struct for Linear Accel-output data of precision double
*/
struct bno055_linear_accel_double_t {
double x;/**< linear accel x double data */
double y;/**< linear accel y double data */
double z;/**< linear accel z double data */
};
/*!
* @brief struct for Gravity-output data of precision double
*/
struct bno055_gravity_double_t {
double x;/**< Gravity x double data */
double y;/**< Gravity y double data */
double z;/**< Gravity z double data */
};
#endif
#ifdef	BNO055_FLOAT_ENABLE
/*!
* @brief struct for Accel-output data of precision float
*/
struct bno055_accel_float_t {
float x;/**< accel x float data */
float y;/**< accel y float data */
float z;/**< accel z float data */
};
/*!
* @brief struct for Mag-output data of precision float
*/
struct bno055_mag_float_t {
float x;/**< Mag x float data */
float y;/**< Mag y float data */
float z;/**< Mag z float data */
};
/*!
* @brief struct for Gyro-output data of precision float
*/
struct bno055_gyro_float_t {
float x;/**< Gyro x float data */
float y;/**< Gyro y float data */
float z;/**< Gyro z float data */
};
/*!
* @brief struct for Euler-output data of precision float
*/
struct bno055_euler_float_t {
float h;/**< Euler h float data */
float r;/**< Euler r float data */
float p;/**< Euler p float data */
};
/*!
* @brief struct for Linear accel-output data of precision float
*/
struct bno055_linear_accel_float_t {
float x;/**< Linear accel x float data */
float y;/**< Linear accel y float data */
float z;/**< Linear accel z float data */
};
/*!
* @brief struct for Gravity-output data of precision float
*/
struct bno055_gravity_float_t {
float x;/**< Gravity x float data */
float y;/**< Gravity y float data */
float z;/**< Gravity z float data */
};
#endif
/*!
* @brief struct for Accel offset
*/
struct bno055_accel_offset_t {
s16 x;/**< Accel offset x data */
s16 y;/**< Accel offset y data */
s16 z;/**< Accel offset z data */
s16 r;/**< Accel radius r data */
};
/*!
* @brief struct for Gyro offset
*/
struct bno055_gyro_offset_t {
s16 x;/**< Gyro offset x data */
s16 y;/**< Gyro offset y data */
s16 z;/**< Gyro offset z data */
};
/*!
* @brief struct for Mag offset
*/
struct bno055_mag_offset_t {
s16 x;/**< Mag offset x data */
s16 y;/**< Mag offset y data */
s16 z;/**< Mag offset z data */
s16 r;/**< Mag radius x data */
};
/*!
* @brief struct for soft iron calibration matrix
*/
struct bno055_sic_matrix_t {
s16 sic_0;/**< soft iron calibration matrix 0 data */
s16 sic_1;/**< soft iron calibration matrix 1 data */
s16 sic_2;/**< soft iron calibration matrix 2 data */
s16 sic_3;/**< soft iron calibration matrix 3 data */
s16 sic_4;/**< soft iron calibration matrix 4 data */
s16 sic_5;/**< soft iron calibration matrix 5 data */
s16 sic_6;/**< soft iron calibration matrix 6 data */
s16 sic_7;/**< soft iron calibration matrix 7 data */
s16 sic_8;/**< soft iron calibration matrix 8 data */
};
/***************************************************/
/**\name	CONSTANT DEFINITIONS                   */
/***************************************************/
#define         BNO055_ZERO_U8X           ((u8)0)
#define         BNO055_ONE_U8X           ((u8)1)
#define         BNO055_TWO_U8X			  ((u8)2)
#define         BNO055_FOUR_U8X           ((u8)4)
#define         BNO055_FIVE_U8X           ((u8)5)
#define         BNO055_SIX_U8X            ((u8)6)
#define         BNO055_SEVEN_U8X          ((u8)7)
#define         BNO055_ELEVEN_U8X         ((u8)11)
#define         BNO055_SIXTEEN_U8X        ((u8)16)
#define			BNO055_EIGHT_U8X		  ((u8)8)
#define			BNO055_TWENTY_U8X         ((u8)20)
#define			BNO055_EIGHTEEN_U8X       ((u8)18)


#define         BNO055_SHIFT_8_POSITION	   ((u8)8)


/*  BNO055 API error codes */
#define E_NULL_PTR                  ((s8)-127)
#define E_BNO055_OUT_OF_RANGE       ((s8)-2)
#define	SUCCESS						((u8)0)
#define	ERROR						((s8)-1)

/* Selection for bit enable and disable */
#define ENABLED		0x01
#define DISABLED	0x00

/* Page ID */
#define PAGE_ZERO		0X00
#define PAGE_ONE		0X01

/* Enable the temperature source */
#define	ACCEL_TEMP_EN	0x00
#define	GYRO_TEMP_EN	0x01
#define	MCU_TEMP_EN		0x03

/*Accel unit*/
#define ACCEL_UNIT_MSQ	0x00
#define ACCEL_UNIT_MG	0x01

/*Gyro unit*/
#define GYRO_UNIT_DPS	0x00
#define GYRO_UNIT_RPS	0x01

/* Euler unit*/
#define EULER_UNIT_DEG	0x00
#define EULER_UNIT_RAD	0x01

/*Temperature unit*/
#define TEMP_UNIT_CELSIUS		0x00
#define TEMP_UNIT_FAHRENHEIT	0x01

/*Accel division factor*/
#define	ACCEL_DIV_MSQ	100.0
#define	ACCEL_DIV_MG	1

/*Mag division factor*/
#define MAG_DIV_UT	16.0

/*Gyro division factor*/
#define GYRO_DIV_DPS		16.0
#define GYRO_DIV_RPS		900.0

/*Euler division factor*/
#define EULER_DIV_DEG		16.0
#define EULER_DIV_RAD		900.0

/*Linear accel division factor*/
#define	LINEAR_ACCEL_DIV_MSQ	100.0

/*Gravity accel division factor*/
#define	GRAVITY_DIV_MSQ	100.0

/* Temperature division factor*/
#define TEMP_DIV_FAHRENHEIT	0.5
#define TEMP_DIV_CELSIUS	1

#define	BNO055_SIX_HUNDRES_U8X	600



/* Operation mode settings*/
#define OPERATION_MODE_CONFIG			0X00
#define OPERATION_MODE_ACCONLY			0X01
#define OPERATION_MODE_MAGONLY			0X02
#define OPERATION_MODE_GYRONLY			0X03
#define OPERATION_MODE_ACCMAG			0X04
#define OPERATION_MODE_ACCGYRO			0X05
#define OPERATION_MODE_MAGGYRO			0X06
#define OPERATION_MODE_AMG				0X07
#define OPERATION_MODE_IMUPLUS			0X08
#define OPERATION_MODE_COMPASS			0X09
#define OPERATION_MODE_M4G				0X0A
#define OPERATION_MODE_NDOF_FMC_OFF		0X0B
#define OPERATION_MODE_NDOF				0X0C

/* Power mode*/
#define POWER_MODE_NORMAL	0X00
#define POWER_MODE_LOWPOWER	0X01
#define POWER_MODE_SUSPEND	0X02

/* PAGE-1 definitions*/
/* Accel Range */

#define ACCEL_RANGE_2G		0X00
#define ACCEL_RANGE_4G		0X01
#define ACCEL_RANGE_8G		0X02
#define ACCEL_RANGE_16G		0X03

/* Accel Bandwidth*/
#define ACCEL_BW_7_81HZ		0x00
#define ACCEL_BW_15_63HZ	0x01
#define ACCEL_BW_31_25HZ	0x02
#define ACCEL_BW_62_5HZ		0X03
#define ACCEL_BW_125HZ		0X04
#define ACCEL_BW_250HZ		0X05
#define ACCEL_BW_500HZ		0X06
#define ACCEL_BW_1000HZ		0X07

/* Accel Power mode*/
#define ACCEL_NORMAL			0X00
#define ACCEL_SUSPEND			0X01
#define ACCEL_LOWPOWER_1		0X02
#define ACCEL_STANDBY			0X03
#define ACCEL_LOWPOWER_2		0X04
#define ACCEL_DEEPSUSPEND		0X05

/* Mag data output rate*/
#define MAG_DATA_OUTRATE_2HZ		0X00
#define MAG_DATA_OUTRATE_6HZ		0X01
#define MAG_DATA_OUTRATE_8HZ		0X02
#define MAG_DATA_OUTRATE_10HZ		0X03
#define MAG_DATA_OUTRATE_15HZ		0X04
#define MAG_DATA_OUTRATE_20HZ		0X05
#define MAG_DATA_OUTRATE_25HZ		0X06
#define MAG_DATA_OUTRATE_30HZ		0X07

/* Mag Operation mode*/
#define MAG_OPERATION_MODE_LOWPOWER				0X00
#define MAG_OPERATION_MODE_REGULAR				0X01
#define MAG_OPERATION_MODE_ENHANCED_REGULAR		0X02
#define MAG_OPERATION_MODE_HIGH_ACCURACY		0X03

/* Mag power mode*/
#define MAG_POWER_MODE_NORMAL					0X00
#define MAG_POWER_MODE_SLEEP					0X01
#define MAG_POWER_MODE_SUSPEND					0X02
#define MAG_POWER_MODE_FORCE_MODE				0X03

/* Gyro range*/
#define GYRO_RANGE_2000DPS		0x00
#define GYRO_RANGE_1000DPS		0x01
#define GYRO_RANGE_500DPS		0x02
#define GYRO_RANGE_250DPS		0x03
#define GYRO_RANGE_125DPS		0x04

/* Gyro Bandwidth*/
#define GYRO_BW_523HZ		0x00
#define GYRO_BW_230HZ		0x01
#define GYRO_BW_116HZ		0x02
#define GYRO_BW_47HZ		0x03
#define GYRO_BW_23HZ		0x04
#define GYRO_BW_12HZ		0x05
#define GYRO_BW_64HZ		0x06
#define GYRO_BW_32HZ		0x07

/* Gyro power mode*/
#define GYRO_POWER_MODE_NORMAL				0X00
#define GYRO_POWER_MODE_FASTPOWERUP			0X01
#define GYRO_POWER_MODE_DEEPSUSPEND			0X02
#define GYRO_POWER_MODE_SUSPEND				0X03
#define GYRO_POWER_MODE_ADVANCE_POWERSAVE	0X04

/* Accel Sleep Duration */
#define BNO055_ACCEL_SLEEP_DURN_0_5MS        0x05
/* sets sleep duration to 0.5 ms  */
#define BNO055_ACCEL_SLEEP_DURN_1MS          0x06
/* sets sleep duration to 1 ms */
#define BNO055_ACCEL_SLEEP_DURN_2MS          0x07
/* sets sleep duration to 2 ms */
#define BNO055_ACCEL_SLEEP_DURN_4MS          0x08
/* sets sleep duration to 4 ms */
#define BNO055_ACCEL_SLEEP_DURN_6MS          0x09
/* sets sleep duration to 6 ms*/
#define BNO055_ACCEL_SLEEP_DURN_10MS         0x0A
/* sets sleep duration to 10 ms */
#define BNO055_ACCEL_SLEEP_DURN_25MS         0x0B
 /* sets sleep duration to 25 ms */
#define BNO055_ACCEL_SLEEP_DURN_50MS         0x0C
 /* sets sleep duration to 50 ms */
#define BNO055_ACCEL_SLEEP_DURN_100MS        0x0D
 /* sets sleep duration to 100 ms */
#define BNO055_ACCEL_SLEEP_DURN_500MS        0x0E
 /* sets sleep duration to 500 ms */
#define BNO055_ACCEL_SLEEP_DURN_1S           0x0F
/* sets sleep duration to 1 s */

/* Gyro Auto sleep duration*/
#define BNO055_GYRO_No_AUTOSLPDUR		0x00
#define	BNO055_GYRO_4MS_AUTOSLPDUR		0x01
#define	BNO055_GYRO_5MS_AUTOSLPDUR		0x02
#define	BNO055_GYRO_8MS_AUTOSLPDUR		0x03
#define	BNO055_GYRO_10MS_AUTOSLPDUR		0x04
#define	BNO055_GYRO_15MS_AUTOSLPDUR		0x05
#define	BNO055_GYRO_20MS_AUTOSLPDUR		0x06
#define	BNO055_GYRO_40MS_AUTOSLPDUR		0x07

/* Accel Any/No motion axis selection*/
#define BNO055_ACCEL_ANY_MOTION_NO_MOTION_X_AXIS		0
#define BNO055_ACCEL_ANY_MOTION_NO_MOTION_Y_AXIS		1
#define BNO055_ACCEL_ANY_MOTION_NO_MOTION_Z_AXIS		2

/* Accel High g axis selection*/
#define BNO055_ACCEL_HIGH_G_X_AXIS		0
#define BNO055_ACCEL_HIGH_G_Y_AXIS		1
#define BNO055_ACCEL_HIGH_G_Z_AXIS		2

/* Gyro Any motion axis selection*/
#define BNO055_GYRO_ANY_MOTION_X_AXIS		0
#define BNO055_GYRO_ANY_MOTION_Y_AXIS		1
#define BNO055_GYRO_ANY_MOTION_Z_AXIS		2


/* Gyro High rate axis selection*/
#define BNO055_GYRO_HIGHRATE_X_AXIS		0
#define BNO055_GYRO_HIGHRATE_Y_AXIS		1
#define BNO055_GYRO_HIGHRATE_Z_AXIS		2

/* Axis remap values*/
#define REMAP_X_Y			0X21
#define REMAP_Y_Z			0X18
#define REMAP_Z_X			0X06
#define REMAP_X_Y_Z_TYPE0	0X12
#define REMAP_X_Y_Z_TYPE1	0X09
#define DEFAULT_AXIS		0X24

/* Axis remap sign */
#define	REMAP_AXIS_POSITIVE	0X00
#define	REMAP_AXIS_NEGATIVE	0X01

/* Gyro anymotion and high rate filter configuration */
#define	FILTERED	0x00
#define	UNFILTERED	0x01

/* mask definitions*/
#define BNO055_SIC_HEX_0_0_F_F_DATA		0x00FF
/****************************************************/
/**\name	ARRAY SIZE DEFINITIONS      */
/***************************************************/
#define ARRAY_SIZE_TWO		2
#define ARRAY_SIZE_THREE	3
#define ARRAY_SIZE_SIX		6
#define ARRAY_SIZE_FIVE		5
#define ARRAY_SIZE_EIGHT	8
#define ARRAY_SIZE_TWELVE	12
#define ARRAY_SIZE_FOURTEEN	14
#define ARRAY_SIZE_EIGHTEEN	18
#define ARRAY_SIZE_TWENTY_SIX	26

#define INDEX_ZERO		0
#define INDEX_ONE		1
#define INDEX_TWO		2
#define INDEX_THREE		3
#define INDEX_FOUR		4
#define INDEX_FIVE		5
#define INDEX_SIX		6
#define INDEX_SEVEN		7
#define INDEX_EIGHT		8
#define INDEX_NINE		9
#define INDEX_TEN		10
#define INDEX_ELEVEN	11
#define INDEX_TWELVE	12
#define INDEX_THIRTEEN	13
#define INDEX_FOURTEEN	14
#define INDEX_FIVETEEN	15
#define INDEX_SIXTEEN	16
#define INDEX_SEVENTEEN	17
#define INDEX_EIGHTEEN	18
#define INDEX_NINETEEN	19
#define INDEX_TWENTY	20
#define INDEX_TWENTY_ONE	21
#define INDEX_TWENTY_TWO	22
#define INDEX_TWENTY_THREE	23
#define INDEX_TWENTY_FIVE	25
/****************************************************/
/**\name	ARRAY PARAMETERS      */
/***************************************************/
#define LSB_ZERO	0
#define MSB_ONE		1
#define LSB_TWO		2
#define MSB_THREE	3
#define LSB_FOUR	4
#define MSB_FIVE	5
#define LSB_SIX		6
#define MSB_SEVEN	7
/*********************************************************/
/**\name PAGE0 DATA REGISTERS DEFINITION */
/*********************************************************/
/* Chip ID */
#define BNO055_CHIP_ID__POS             0
#define BNO055_CHIP_ID__MSK             0xFF
#define BNO055_CHIP_ID__LEN             8
#define BNO055_CHIP_ID__REG             BNO055_CHIP_ID_ADDR

/* Accel revision id*/
#define BNO055_ACCEL_REV_ID__POS             0
#define BNO055_ACCEL_REV_ID__MSK             0xFF
#define BNO055_ACCEL_REV_ID__LEN             8
#define BNO055_ACCEL_REV_ID__REG             BNO055_ACCEL_REV_ID_ADDR

/* Mag revision id*/
#define BNO055_MAG_REV_ID__POS             0
#define BNO055_MAG_REV_ID__MSK             0xFF
#define BNO055_MAG_REV_ID__LEN             8
#define BNO055_MAG_REV_ID__REG             BNO055_MAG_REV_ID_ADDR

/* Gyro revision id*/
#define BNO055_GYRO_REV_ID__POS             0
#define BNO055_GYRO_REV_ID__MSK             0xFF
#define BNO055_GYRO_REV_ID__LEN             8
#define BNO055_GYRO_REV_ID__REG             BNO055_GYRO_REV_ID_ADDR

/*Software revision id LSB*/
#define BNO055_SW_REV_ID_LSB__POS             0
#define BNO055_SW_REV_ID_LSB__MSK             0xFF
#define BNO055_SW_REV_ID_LSB__LEN             8
#define BNO055_SW_REV_ID_LSB__REG             BNO055_SW_REV_ID_LSB_ADDR

/*Software revision id MSB*/
#define BNO055_SW_REV_ID_MSB__POS             0
#define BNO055_SW_REV_ID_MSB__MSK             0xFF
#define BNO055_SW_REV_ID_MSB__LEN             8
#define BNO055_SW_REV_ID_MSB__REG             BNO055_SW_REV_ID_MSB_ADDR

/* BOOTLODER revision id*/
#define BNO055_BL_REV_ID__POS             0
#define BNO055_BL_REV_ID__MSK             0xFF
#define BNO055_BL_REV_ID__LEN             8
#define BNO055_BL_REV_ID__REG             BNO055_BL_REV_ID_ADDR

/*Page id*/
#define BNO055_PAGE_ID__POS             0
#define BNO055_PAGE_ID__MSK             0xFF
#define BNO055_PAGE_ID__LEN             8
#define BNO055_PAGE_ID__REG             BNO055_PAGE_ID_ADDR

/* Accel data X-LSB register*/
#define BNO055_ACCEL_DATA_X_LSB_VALUEX__POS             0
#define BNO055_ACCEL_DATA_X_LSB_VALUEX__MSK             0xFF
#define BNO055_ACCEL_DATA_X_LSB_VALUEX__LEN             8
#define BNO055_ACCEL_DATA_X_LSB_VALUEX__REG             \
BNO055_ACCEL_DATA_X_LSB_ADDR

/* Accel data X-MSB register*/
#define BNO055_ACCEL_DATA_X_MSB_VALUEX__POS             0
#define BNO055_ACCEL_DATA_X_MSB_VALUEX__MSK             0xFF
#define BNO055_ACCEL_DATA_X_MSB_VALUEX__LEN             8
#define BNO055_ACCEL_DATA_X_MSB_VALUEX__REG             \
BNO055_ACCEL_DATA_X_MSB_ADDR

/* Accel data Y-LSB register*/
#define BNO055_ACCEL_DATA_Y_LSB_VALUEY__POS             0
#define BNO055_ACCEL_DATA_Y_LSB_VALUEY__MSK             0xFF
#define BNO055_ACCEL_DATA_Y_LSB_VALUEY__LEN             8
#define BNO055_ACCEL_DATA_Y_LSB_VALUEY__REG             \
BNO055_ACCEL_DATA_Y_LSB_ADDR

/* Accel data Y-MSB register*/
#define BNO055_ACCEL_DATA_Y_MSB_VALUEY__POS             0
#define BNO055_ACCEL_DATA_Y_MSB_VALUEY__MSK             0xFF
#define BNO055_ACCEL_DATA_Y_MSB_VALUEY__LEN             8
#define BNO055_ACCEL_DATA_Y_MSB_VALUEY__REG             \
BNO055_ACCEL_DATA_Y_MSB_ADDR

/* Accel data Z-LSB register*/
#define BNO055_ACCEL_DATA_Z_LSB_VALUEZ__POS		0
#define BNO055_ACCEL_DATA_Z_LSB_VALUEZ__MSK		0xFF
#define BNO055_ACCEL_DATA_Z_LSB_VALUEZ__LEN		8
#define BNO055_ACCEL_DATA_Z_LSB_VALUEZ__REG     \
BNO055_ACCEL_DATA_Z_LSB_ADDR

/* Accel data Z-MSB register*/
#define BNO055_ACCEL_DATA_Z_MSB_VALUEZ__POS		0
#define BNO055_ACCEL_DATA_Z_MSB_VALUEZ__MSK		0xFF
#define BNO055_ACCEL_DATA_Z_MSB_VALUEZ__LEN		8
#define BNO055_ACCEL_DATA_Z_MSB_VALUEZ__REG     \
BNO055_ACCEL_DATA_Z_MSB_ADDR

/* Mag data X-LSB register*/
#define BNO055_MAG_DATA_X_LSB_VALUEX__POS             0
#define BNO055_MAG_DATA_X_LSB_VALUEX__MSK             0xFF
#define BNO055_MAG_DATA_X_LSB_VALUEX__LEN             8
#define BNO055_MAG_DATA_X_LSB_VALUEX__REG             \
BNO055_MAG_DATA_X_LSB_ADDR

/* Mag data X-MSB register*/
#define BNO055_MAG_DATA_X_MSB_VALUEX__POS             0
#define BNO055_MAG_DATA_X_MSB_VALUEX__MSK             0xFF
#define BNO055_MAG_DATA_X_MSB_VALUEX__LEN             8
#define BNO055_MAG_DATA_X_MSB_VALUEX__REG             BNO055_MAG_DATA_X_MSB_ADDR

/* Mag data Y-LSB register*/
#define BNO055_MAG_DATA_Y_LSB_VALUEY__POS             0
#define BNO055_MAG_DATA_Y_LSB_VALUEY__MSK             0xFF
#define BNO055_MAG_DATA_Y_LSB_VALUEY__LEN             8
#define BNO055_MAG_DATA_Y_LSB_VALUEY__REG             BNO055_MAG_DATA_Y_LSB_ADDR

/* Mag data Y-MSB register*/
#define BNO055_MAG_DATA_Y_MSB_VALUEY__POS             0
#define BNO055_MAG_DATA_Y_MSB_VALUEY__MSK             0xFF
#define BNO055_MAG_DATA_Y_MSB_VALUEY__LEN             8
#define BNO055_MAG_DATA_Y_MSB_VALUEY__REG             BNO055_MAG_DATA_Y_MSB_ADDR

/* Mag data Z-LSB register*/
#define BNO055_MAG_DATA_Z_LSB_VALUEZ__POS             0
#define BNO055_MAG_DATA_Z_LSB_VALUEZ__MSK             0xFF
#define BNO055_MAG_DATA_Z_LSB_VALUEZ__LEN             8
#define BNO055_MAG_DATA_Z_LSB_VALUEZ__REG             BNO055_MAG_DATA_Z_LSB_ADDR

/* Mag data Z-MSB register*/
#define BNO055_MAG_DATA_Z_MSB_VALUEZ__POS             0
#define BNO055_MAG_DATA_Z_MSB_VALUEZ__MSK             0xFF
#define BNO055_MAG_DATA_Z_MSB_VALUEZ__LEN             8
#define BNO055_MAG_DATA_Z_MSB_VALUEZ__REG             BNO055_MAG_DATA_Z_MSB_ADDR

/* Gyro data X-LSB register*/
#define BNO055_GYRO_DATA_X_LSB_VALUEX__POS	0
#define BNO055_GYRO_DATA_X_LSB_VALUEX__MSK	0xFF
#define BNO055_GYRO_DATA_X_LSB_VALUEX__LEN	8
#define BNO055_GYRO_DATA_X_LSB_VALUEX__REG	BNO055_GYRO_DATA_X_LSB_ADDR

/* Gyro data X-MSB register*/
#define BNO055_GYRO_DATA_X_MSB_VALUEX__POS	0
#define BNO055_GYRO_DATA_X_MSB_VALUEX__MSK	0xFF
#define BNO055_GYRO_DATA_X_MSB_VALUEX__LEN	8
#define BNO055_GYRO_DATA_X_MSB_VALUEX__REG	BNO055_GYRO_DATA_X_MSB_ADDR

/* Gyro data Y-LSB register*/
#define BNO055_GYRO_DATA_Y_LSB_VALUEY__POS	0
#define BNO055_GYRO_DATA_Y_LSB_VALUEY__MSK	0xFF
#define BNO055_GYRO_DATA_Y_LSB_VALUEY__LEN	8
#define BNO055_GYRO_DATA_Y_LSB_VALUEY__REG	BNO055_GYRO_DATA_Y_LSB_ADDR

/* Gyro data Y-MSB register*/
#define BNO055_GYRO_DATA_Y_MSB_VALUEY__POS	0
#define BNO055_GYRO_DATA_Y_MSB_VALUEY__MSK	0xFF
#define BNO055_GYRO_DATA_Y_MSB_VALUEY__LEN	8
#define BNO055_GYRO_DATA_Y_MSB_VALUEY__REG	BNO055_GYRO_DATA_Y_MSB_ADDR

/* Gyro data Z-LSB register*/
#define BNO055_GYRO_DATA_Z_LSB_VALUEZ__POS	0
#define BNO055_GYRO_DATA_Z_LSB_VALUEZ__MSK	0xFF
#define BNO055_GYRO_DATA_Z_LSB_VALUEZ__LEN	8
#define BNO055_GYRO_DATA_Z_LSB_VALUEZ__REG	BNO055_GYRO_DATA_Z_LSB_ADDR

/* Gyro data Z-MSB register*/
#define BNO055_GYRO_DATA_Z_MSB_VALUEZ__POS	0
#define BNO055_GYRO_DATA_Z_MSB_VALUEZ__MSK	0xFF
#define BNO055_GYRO_DATA_Z_MSB_VALUEZ__LEN	8
#define BNO055_GYRO_DATA_Z_MSB_VALUEZ__REG	BNO055_GYRO_DATA_Z_MSB_ADDR

/* Euler data HEADING-LSB register*/
#define BNO055_EULER_H_LSB_VALUEH__POS   0
#define BNO055_EULER_H_LSB_VALUEH__MSK   0xFF
#define BNO055_EULER_H_LSB_VALUEH__LEN   8
#define BNO055_EULER_H_LSB_VALUEH__REG  BNO055_EULER_H_LSB_ADDR

/* Euler data HEADING-MSB register*/
#define BNO055_EULER_H_MSB_VALUEH__POS  0
#define BNO055_EULER_H_MSB_VALUEH__MSK  0xFF
#define BNO055_EULER_H_MSB_VALUEH__LEN  8
#define BNO055_EULER_H_MSB_VALUEH__REG  BNO055_EULER_H_MSB_ADDR

/* Euler data ROLL-LSB register*/
#define BNO055_EULER_R_LSB_VALUER__POS  0
#define BNO055_EULER_R_LSB_VALUER__MSK  0xFF
#define BNO055_EULER_R_LSB_VALUER__LEN  8
#define BNO055_EULER_R_LSB_VALUER__REG  BNO055_EULER_R_LSB_ADDR

/* Euler data ROLL-MSB register*/
#define BNO055_EULER_R_MSB_VALUER__POS  0
#define BNO055_EULER_R_MSB_VALUER__MSK  0xFF
#define BNO055_EULER_R_MSB_VALUER__LEN  8
#define BNO055_EULER_R_MSB_VALUER__REG  BNO055_EULER_R_MSB_ADDR

/* Euler data PITCH-LSB register*/
#define BNO055_EULER_P_LSB_VALUEP__POS  0
#define BNO055_EULER_P_LSB_VALUEP__MSK  0xFF
#define BNO055_EULER_P_LSB_VALUEP__LEN  8
#define BNO055_EULER_P_LSB_VALUEP__REG  BNO055_EULER_P_LSB_ADDR

/* Euler data HEADING-MSB register*/
#define BNO055_EULER_P_MSB_VALUEP__POS  0
#define BNO055_EULER_P_MSB_VALUEP__MSK  0xFF
#define BNO055_EULER_P_MSB_VALUEP__LEN  8
#define BNO055_EULER_P_MSB_VALUEP__REG  BNO055_EULER_P_MSB_ADDR

/* Quaternion data W-LSB register*/
#define BNO055_QUATERNION_DATA_W_LSB_VALUEW__POS  0
#define BNO055_QUATERNION_DATA_W_LSB_VALUEW__MSK  0xFF
#define BNO055_QUATERNION_DATA_W_LSB_VALUEW__LEN  8
#define BNO055_QUATERNION_DATA_W_LSB_VALUEW__REG  \
BNO055_QUATERNION_DATA_W_LSB_ADDR

/* Quaternion data W-MSB register*/
#define BNO055_QUATERNION_DATA_W_MSB_VALUEW__POS  0
#define BNO055_QUATERNION_DATA_W_MSB_VALUEW__MSK  0xFF
#define BNO055_QUATERNION_DATA_W_MSB_VALUEW__LEN  8
#define BNO055_QUATERNION_DATA_W_MSB_VALUEW__REG  \
BNO055_QUATERNION_DATA_W_MSB_ADDR

/* Quaternion data X-LSB register*/
#define BNO055_QUATERNION_DATA_X_LSB_VALUEX__POS  0
#define BNO055_QUATERNION_DATA_X_LSB_VALUEX__MSK  0xFF
#define BNO055_QUATERNION_DATA_X_LSB_VALUEX__LEN  8
#define BNO055_QUATERNION_DATA_X_LSB_VALUEX__REG  \
BNO055_QUATERNION_DATA_X_LSB_ADDR

/* Quaternion data X-MSB register*/
#define BNO055_QUATERNION_DATA_X_MSB_VALUEX__POS  0
#define BNO055_QUATERNION_DATA_X_MSB_VALUEX__MSK  0xFF
#define BNO055_QUATERNION_DATA_X_MSB_VALUEX__LEN  8
#define BNO055_QUATERNION_DATA_X_MSB_VALUEX__REG \
BNO055_QUATERNION_DATA_X_MSB_ADDR

/* Quaternion data Y-LSB register*/
#define BNO055_QUATERNION_DATA_Y_LSB_VALUEY__POS  0
#define BNO055_QUATERNION_DATA_Y_LSB_VALUEY__MSK  0xFF
#define BNO055_QUATERNION_DATA_Y_LSB_VALUEY__LEN  8
#define BNO055_QUATERNION_DATA_Y_LSB_VALUEY__REG \
BNO055_QUATERNION_DATA_Y_LSB_ADDR

/* Quaternion data Y-MSB register*/
#define BNO055_QUATERNION_DATA_Y_MSB_VALUEY__POS  0
#define BNO055_QUATERNION_DATA_Y_MSB_VALUEY__MSK  0xFF
#define BNO055_QUATERNION_DATA_Y_MSB_VALUEY__LEN  8
#define BNO055_QUATERNION_DATA_Y_MSB_VALUEY__REG  \
NO055_QUATERNION_DATA_Y_MSB_ADDR

/* Quaternion data Z-LSB register*/
#define BNO055_QUATERNION_DATA_Z_LSB_VALUEZ__POS  0
#define BNO055_QUATERNION_DATA_Z_LSB_VALUEZ__MSK  0xFF
#define BNO055_QUATERNION_DATA_Z_LSB_VALUEZ__LEN  8
#define BNO055_QUATERNION_DATA_Z_LSB_VALUEZ__REG \
BNO055_QUATERNION_DATA_Z_LSB_ADDR

/* Quaternion data Z-MSB register*/
#define BNO055_QUATERNION_DATA_Z_MSB_VALUEZ__POS  0
#define BNO055_QUATERNION_DATA_Z_MSB_VALUEZ__MSK  0xFF
#define BNO055_QUATERNION_DATA_Z_MSB_VALUEZ__LEN  8
#define BNO055_QUATERNION_DATA_Z_MSB_VALUEZ__REG  \
BNO055_QUATERNION_DATA_Z_MSB_ADDR

/* Linear acceleration data X-LSB register*/
#define BNO055_LINEAR_ACCEL_DATA_X_LSB_VALUEX__POS  0
#define BNO055_LINEAR_ACCEL_DATA_X_LSB_VALUEX__MSK  0xFF
#define BNO055_LINEAR_ACCEL_DATA_X_LSB_VALUEX__LEN  8
#define BNO055_LINEAR_ACCEL_DATA_X_LSB_VALUEX__REG  \
BNO055_LINEAR_ACCEL_DATA_X_LSB_ADDR

/* Linear acceleration data X-MSB register*/
#define BNO055_LINEAR_ACCEL_DATA_X_MSB_VALUEX__POS  0
#define BNO055_LINEAR_ACCEL_DATA_X_MSB_VALUEX__MSK  0xFF
#define BNO055_LINEAR_ACCEL_DATA_X_MSB_VALUEX__LEN  8
#define BNO055_LINEAR_ACCEL_DATA_X_MSB_VALUEX__REG  \
BNO055_LINEAR_ACCEL_DATA_X_MSB_ADDR

/* Linear acceleration data Y-LSB register*/
#define BNO055_LINEAR_ACCEL_DATA_Y_LSB_VALUEY__POS  0
#define BNO055_LINEAR_ACCEL_DATA_Y_LSB_VALUEY__MSK  0xFF
#define BNO055_LINEAR_ACCEL_DATA_Y_LSB_VALUEY__LEN  8
#define BNO055_LINEAR_ACCEL_DATA_Y_LSB_VALUEY__REG  \
BNO055_LINEAR_ACCEL_DATA_Y_LSB_ADDR

/* Linear acceleration data Y-MSB register*/
#define BNO055_LINEAR_ACCEL_DATA_Y_MSB_VALUEY__POS  0
#define BNO055_LINEAR_ACCEL_DATA_Y_MSB_VALUEY__MSK  0xFF
#define BNO055_LINEAR_ACCEL_DATA_Y_MSB_VALUEY__LEN  8
#define BNO055_LINEAR_ACCEL_DATA_Y_MSB_VALUEY__REG  \
BNO055_LINEAR_ACCEL_DATA_Y_MSB_ADDR

/* Linear acceleration data Z-LSB register*/
#define BNO055_LINEAR_ACCEL_DATA_Z_LSB_VALUEZ__POS  0
#define BNO055_LINEAR_ACCEL_DATA_Z_LSB_VALUEZ__MSK  0xFF
#define BNO055_LINEAR_ACCEL_DATA_Z_LSB_VALUEZ__LEN  8
#define BNO055_LINEAR_ACCEL_DATA_Z_LSB_VALUEZ__REG \
BNO055_LINEAR_ACCEL_DATA_Z_LSB_ADDR

/* Linear acceleration data Z-MSB register*/
#define BNO055_LINEAR_ACCEL_DATA_Z_MSB_VALUEZ__POS  0
#define BNO055_LINEAR_ACCEL_DATA_Z_MSB_VALUEZ__MSK  0xFF
#define BNO055_LINEAR_ACCEL_DATA_Z_MSB_VALUEZ__LEN  8
#define BNO055_LINEAR_ACCEL_DATA_Z_MSB_VALUEZ__REG  \
BNO055_LINEAR_ACCEL_DATA_Z_MSB_ADDR

/* Gravity data X-LSB register*/
#define BNO055_GRAVITY_DATA_X_LSB_VALUEX__POS  0
#define BNO055_GRAVITY_DATA_X_LSB_VALUEX__MSK  0xFF
#define BNO055_GRAVITY_DATA_X_LSB_VALUEX__LEN  8
#define BNO055_GRAVITY_DATA_X_LSB_VALUEX__REG  \
BNO055_GRAVITY_DATA_X_LSB_ADDR

/* Gravity data X-MSB register*/
#define BNO055_GRAVITY_DATA_X_MSB_VALUEX__POS  0
#define BNO055_GRAVITY_DATA_X_MSB_VALUEX__MSK  0xFF
#define BNO055_GRAVITY_DATA_X_MSB_VALUEX__LEN  8
#define BNO055_GRAVITY_DATA_X_MSB_VALUEX__REG  \
BNO055_GRAVITY_DATA_X_MSB_ADDR

/* Gravity data Y-LSB register*/
#define BNO055_GRAVITY_DATA_Y_LSB_VALUEY__POS  0
#define BNO055_GRAVITY_DATA_Y_LSB_VALUEY__MSK  0xFF
#define BNO055_GRAVITY_DATA_Y_LSB_VALUEY__LEN  8
#define BNO055_GRAVITY_DATA_Y_LSB_VALUEY__REG  \
BNO055_GRAVITY_DATA_Y_LSB_ADDR

/* Gravity data Y-MSB register*/
#define BNO055_GRAVITY_DATA_Y_MSB_VALUEY__POS  0
#define BNO055_GRAVITY_DATA_Y_MSB_VALUEY__MSK  0xFF
#define BNO055_GRAVITY_DATA_Y_MSB_VALUEY__LEN  8
#define BNO055_GRAVITY_DATA_Y_MSB_VALUEY__REG  \
BNO055_GRAVITY_DATA_Y_MSB_ADDR

/* Gravity data Z-LSB register*/
#define BNO055_GRAVITY_DATA_Z_LSB_VALUEZ__POS  0
#define BNO055_GRAVITY_DATA_Z_LSB_VALUEZ__MSK  0xFF
#define BNO055_GRAVITY_DATA_Z_LSB_VALUEZ__LEN  8
#define BNO055_GRAVITY_DATA_Z_LSB_VALUEZ__REG  \
BNO055_GRAVITY_DATA_Z_LSB_ADDR

/* Gravity data Z-MSB register*/
#define BNO055_GRAVITY_DATA_Z_MSB_VALUEZ__POS  0
#define BNO055_GRAVITY_DATA_Z_MSB_VALUEZ__MSK  0xFF
#define BNO055_GRAVITY_DATA_Z_MSB_VALUEZ__LEN  8
#define BNO055_GRAVITY_DATA_Z_MSB_VALUEZ__REG  \
BNO055_GRAVITY_DATA_Z_MSB_ADDR

/* Temperature register*/
#define BNO055_TEMP__POS             0
#define BNO055_TEMP__MSK             0xFF
#define BNO055_TEMP__LEN             8
#define BNO055_TEMP__REG             BNO055_TEMP_ADDR

/*Mag_Calib status register*/
#define BNO055_MAG_CALIB_STAT__POS             0
#define BNO055_MAG_CALIB_STAT__MSK             0X03
#define BNO055_MAG_CALIB_STAT__LEN             2
#define BNO055_MAG_CALIB_STAT__REG             BNO055_CALIB_STAT_ADDR

/*Acc_Calib status register*/
#define BNO055_ACCEL_CALIB_STAT__POS             2
#define BNO055_ACCEL_CALIB_STAT__MSK             0X0C
#define BNO055_ACCEL_CALIB_STAT__LEN             2
#define BNO055_ACCEL_CALIB_STAT__REG             BNO055_CALIB_STAT_ADDR

/*Gyro_Calib status register*/
#define BNO055_GYRO_CALIB_STAT__POS             4
#define BNO055_GYRO_CALIB_STAT__MSK             0X30
#define BNO055_GYRO_CALIB_STAT__LEN             2
#define BNO055_GYRO_CALIB_STAT__REG             BNO055_CALIB_STAT_ADDR

/*Sys_Calib status register*/
#define BNO055_SYS_CALIB_STAT__POS             6
#define BNO055_SYS_CALIB_STAT__MSK             0XC0
#define BNO055_SYS_CALIB_STAT__LEN             2
#define BNO055_SYS_CALIB_STAT__REG             BNO055_CALIB_STAT_ADDR

/*ST_ACCEL register*/
#define BNO055_SELFTEST_ACCEL__POS             0
#define BNO055_SELFTEST_ACCEL__MSK             0X01
#define BNO055_SELFTEST_ACCEL__LEN             1
#define BNO055_SELFTEST_ACCEL__REG             BNO055_SELFTEST_RESULT_ADDR

/*ST_MAG register*/
#define BNO055_SELFTEST_MAG__POS             1
#define BNO055_SELFTEST_MAG__MSK             0X02
#define BNO055_SELFTEST_MAG__LEN             1
#define BNO055_SELFTEST_MAG__REG             BNO055_SELFTEST_RESULT_ADDR

/*ST_GYRO register*/
#define BNO055_SELFTEST_GYRO__POS             2
#define BNO055_SELFTEST_GYRO__MSK             0X04
#define BNO055_SELFTEST_GYRO__LEN             1
#define BNO055_SELFTEST_GYRO__REG             BNO055_SELFTEST_RESULT_ADDR

/*ST_MCU register*/
#define BNO055_SELFTEST_MCU__POS             3
#define BNO055_SELFTEST_MCU__MSK             0X08
#define BNO055_SELFTEST_MCU__LEN             1
#define BNO055_SELFTEST_MCU__REG             BNO055_SELFTEST_RESULT_ADDR

/*Interrupt status registers*/
#define BNO055_INTR_STAT_GYRO_ANY_MOTION__POS		2
#define BNO055_INTR_STAT_GYRO_ANY_MOTION__MSK		0X04
#define BNO055_INTR_STAT_GYRO_ANY_MOTION__LEN		1
#define BNO055_INTR_STAT_GYRO_ANY_MOTION__REG		BNO055_INTR_STAT_ADDR

#define BNO055_INTR_STAT_GYRO_HIGHRATE__POS		3
#define BNO055_INTR_STAT_GYRO_HIGHRATE__MSK		0X08
#define BNO055_INTR_STAT_GYRO_HIGHRATE__LEN		1
#define BNO055_INTR_STAT_GYRO_HIGHRATE__REG		BNO055_INTR_STAT_ADDR

#define BNO055_INTR_STAT_ACCEL_HIGH_G__POS		5
#define BNO055_INTR_STAT_ACCEL_HIGH_G__MSK		0X20
#define BNO055_INTR_STAT_ACCEL_HIGH_G__LEN		1
#define BNO055_INTR_STAT_ACCEL_HIGH_G__REG		BNO055_INTR_STAT_ADDR

#define BNO055_INTR_STAT_ACCEL_ANY_MOTION__POS		6
#define BNO055_INTR_STAT_ACCEL_ANY_MOTION__MSK		0X40
#define BNO055_INTR_STAT_ACCEL_ANY_MOTION__LEN		1
#define BNO055_INTR_STAT_ACCEL_ANY_MOTION__REG		BNO055_INTR_STAT_ADDR

#define BNO055_INTR_STAT_ACCEL_NO_MOTION__POS		7
#define BNO055_INTR_STAT_ACCEL_NO_MOTION__MSK		0X80
#define BNO055_INTR_STAT_ACCEL_NO_MOTION__LEN		1
#define BNO055_INTR_STAT_ACCEL_NO_MOTION__REG		BNO055_INTR_STAT_ADDR

/* system clock status register*/
#define BNO055_SYS_MAIN_CLK__POS		0
#define BNO055_SYS_MAIN_CLK__MSK		0X10
#define BNO055_SYS_MAIN_CLK__LEN		1
#define BNO055_SYS_MAIN_CLK__REG		BNO055_SYS_CLK_STAT_ADDR

/* System registers*/
#define BNO055_SYS_STAT_CODE__POS		0
#define BNO055_SYS_STAT_CODE__MSK		0XFF
#define BNO055_SYS_STAT_CODE__LEN		8
#define BNO055_SYS_STAT_CODE__REG		BNO055_SYS_STAT_ADDR

#define BNO055_SYS_ERROR_CODE__POS			0
#define BNO055_SYS_ERROR_CODE__MSK			0XFF
#define BNO055_SYS_ERROR_CODE__LEN			8
#define BNO055_SYS_ERROR_CODE__REG			BNO055_SYS_ERR_ADDR

/* Accel_Unit register*/
#define BNO055_ACCEL_UNIT__POS             0
#define BNO055_ACCEL_UNIT__MSK             0X01
#define BNO055_ACCEL_UNIT__LEN             1
#define BNO055_ACCEL_UNIT__REG             BNO055_UNIT_SEL_ADDR

/* Gyro_Unit register*/
#define BNO055_GYRO_UNIT__POS             1
#define BNO055_GYRO_UNIT__MSK             0X02
#define BNO055_GYRO_UNIT__LEN             1
#define BNO055_GYRO_UNIT__REG             BNO055_UNIT_SEL_ADDR

/* Euler_Unit register*/
#define BNO055_EULER_UNIT__POS             2
#define BNO055_EULER_UNIT__MSK             0X04
#define BNO055_EULER_UNIT__LEN             1
#define BNO055_EULER_UNIT__REG             BNO055_UNIT_SEL_ADDR

/* Tilt_Unit register*/
#define BNO055_TILT_UNIT__POS             3
#define BNO055_TILT_UNIT__MSK             0X08
#define BNO055_TILT_UNIT__LEN             1
#define BNO055_TILT_UNIT__REG             BNO055_UNIT_SEL_ADDR

/* Temperature_Unit register*/
#define BNO055_TEMP_UNIT__POS             4
#define BNO055_TEMP_UNIT__MSK             0X10
#define BNO055_TEMP_UNIT__LEN             1
#define BNO055_TEMP_UNIT__REG             BNO055_UNIT_SEL_ADDR

/* ORI android-windows register*/
#define BNO055_DATA_OUTPUT_FORMAT__POS             7
#define BNO055_DATA_OUTPUT_FORMAT__MSK             0X80
#define BNO055_DATA_OUTPUT_FORMAT__LEN             1
#define BNO055_DATA_OUTPUT_FORMAT__REG             BNO055_UNIT_SEL_ADDR
/*Operation Mode data register*/
#define BNO055_OPERATION_MODE__POS			0
#define BNO055_OPERATION_MODE__MSK			0X0F
#define BNO055_OPERATION_MODE__LEN			4
#define BNO055_OPERATION_MODE__REG			BNO055_OPR_MODE_ADDR
/* Power Mode register*/
#define BNO055_POWER_MODE__POS             0
#define BNO055_POWER_MODE__MSK             0X03
#define BNO055_POWER_MODE__LEN             2
#define BNO055_POWER_MODE__REG             BNO055_PWR_MODE_ADDR

/*Self Test register*/
#define BNO055_SELFTEST__POS			0
#define BNO055_SELFTEST__MSK			0X01
#define BNO055_SELFTEST__LEN			1
#define BNO055_SELFTEST__REG			BNO055_SYS_TRIGGER_ADDR

/* RST_SYS register*/
#define BNO055_SYS_RST__POS             5
#define BNO055_SYS_RST__MSK             0X20
#define BNO055_SYS_RST__LEN             1
#define BNO055_SYS_RST__REG             BNO055_SYS_TRIGGER_ADDR

/* RST_INT register*/
#define BNO055_INTR_RST__POS             6
#define BNO055_INTR_RST__MSK             0X40
#define BNO055_INTR_RST__LEN             1
#define BNO055_INTR_RST__REG             BNO055_SYS_TRIGGER_ADDR

/* CLK_SRC register*/
#define BNO055_CLK_SRC__POS             7
#define BNO055_CLK_SRC__MSK             0X80
#define BNO055_CLK_SRC__LEN             1
#define BNO055_CLK_SRC__REG             BNO055_SYS_TRIGGER_ADDR

/* Temp source register*/
#define BNO055_TEMP_SOURCE__POS		0
#define BNO055_TEMP_SOURCE__MSK		0X03
#define BNO055_TEMP_SOURCE__LEN		2
#define BNO055_TEMP_SOURCE__REG		BNO055_TEMP_SOURCE_ADDR

/* Axis remap value register*/
#define BNO055_REMAP_AXIS_VALUE__POS		0
#define BNO055_REMAP_AXIS_VALUE__MSK		0X3F
#define BNO055_REMAP_AXIS_VALUE__LEN		6
#define BNO055_REMAP_AXIS_VALUE__REG		BNO055_AXIS_MAP_CONFIG_ADDR

/* Axis sign value register*/
#define BNO055_REMAP_Z_SIGN__POS		0
#define BNO055_REMAP_Z_SIGN__MSK		0X01
#define BNO055_REMAP_Z_SIGN__LEN		1
#define BNO055_REMAP_Z_SIGN__REG		BNO055_AXIS_MAP_SIGN_ADDR

#define BNO055_REMAP_Y_SIGN__POS		1
#define BNO055_REMAP_Y_SIGN__MSK		0X02
#define BNO055_REMAP_Y_SIGN__LEN		1
#define BNO055_REMAP_Y_SIGN__REG		BNO055_AXIS_MAP_SIGN_ADDR

#define BNO055_REMAP_X_SIGN__POS		2
#define BNO055_REMAP_X_SIGN__MSK		0X04
#define BNO055_REMAP_X_SIGN__LEN		1
#define BNO055_REMAP_X_SIGN__REG		BNO055_AXIS_MAP_SIGN_ADDR

/* Soft Iron Calibration matrix register*/
#define BNO055_SIC_MATRIX_0_LSB__POS		0
#define BNO055_SIC_MATRIX_0_LSB__MSK		0XFF
#define BNO055_SIC_MATRIX_0_LSB__LEN		8
#define BNO055_SIC_MATRIX_0_LSB__REG		BNO055_SIC_MATRIX_0_LSB_ADDR

#define BNO055_SIC_MATRIX_0_MSB__POS		0
#define BNO055_SIC_MATRIX_0_MSB__MSK		0XFF
#define BNO055_SIC_MATRIX_0_MSB__LEN		8
#define BNO055_SIC_MATRIX_0_MSB__REG		BNO055_SIC_MATRIX_0_MSB_ADDR

#define BNO055_SIC_MATRIX_1_LSB__POS		0
#define BNO055_SIC_MATRIX_1_LSB__MSK		0XFF
#define BNO055_SIC_MATRIX_1_LSB__LEN		8
#define BNO055_SIC_MATRIX_1_LSB__REG		BNO055_SIC_MATRIX_1_LSB_ADDR

#define BNO055_SIC_MATRIX_1_MSB__POS		0
#define BNO055_SIC_MATRIX_1_MSB__MSK		0XFF
#define BNO055_SIC_MATRIX_1_MSB__LEN		8
#define BNO055_SIC_MATRIX_1_MSB__REG		BNO055_SIC_MATRIX_1_MSB_ADDR

#define BNO055_SIC_MATRIX_2_LSB__POS		0
#define BNO055_SIC_MATRIX_2_LSB__MSK		0XFF
#define BNO055_SIC_MATRIX_2_LSB__LEN		8
#define BNO055_SIC_MATRIX_2_LSB__REG		BNO055_SIC_MATRIX_2_LSB_ADDR

#define BNO055_SIC_MATRIX_2_MSB__POS		0
#define BNO055_SIC_MATRIX_2_MSB__MSK		0XFF
#define BNO055_SIC_MATRIX_2_MSB__LEN		8
#define BNO055_SIC_MATRIX_2_MSB__REG		BNO055_SIC_MATRIX_2_MSB_ADDR

#define BNO055_SIC_MATRIX_3_LSB__POS		0
#define BNO055_SIC_MATRIX_3_LSB__MSK		0XFF
#define BNO055_SIC_MATRIX_3_LSB__LEN		8
#define BNO055_SIC_MATRIX_3_LSB__REG		BNO055_SIC_MATRIX_3_LSB_ADDR

#define BNO055_SIC_MATRIX_3_MSB__POS		0
#define BNO055_SIC_MATRIX_3_MSB__MSK		0XFF
#define BNO055_SIC_MATRIX_3_MSB__LEN		8
#define BNO055_SIC_MATRIX_3_MSB__REG		BNO055_SIC_MATRIX_3_MSB_ADDR

#define BNO055_SIC_MATRIX_4_LSB__POS		0
#define BNO055_SIC_MATRIX_4_LSB__MSK		0XFF
#define BNO055_SIC_MATRIX_4_LSB__LEN		8
#define BNO055_SIC_MATRIX_4_LSB__REG		BNO055_SIC_MATRIX_4_LSB_ADDR

#define BNO055_SIC_MATRIX_4_MSB__POS		0
#define BNO055_SIC_MATRIX_4_MSB__MSK		0XFF
#define BNO055_SIC_MATRIX_4_MSB__LEN		8
#define BNO055_SIC_MATRIX_4_MSB__REG		BNO055_SIC_MATRIX_4_MSB_ADDR

#define BNO055_SIC_MATRIX_5_LSB__POS		0
#define BNO055_SIC_MATRIX_5_LSB__MSK		0XFF
#define BNO055_SIC_MATRIX_5_LSB__LEN		8
#define BNO055_SIC_MATRIX_5_LSB__REG		BNO055_SIC_MATRIX_5_LSB_ADDR

#define BNO055_SIC_MATRIX_5_MSB__POS		0
#define BNO055_SIC_MATRIX_5_MSB__MSK		0XFF
#define BNO055_SIC_MATRIX_5_MSB__LEN		8
#define BNO055_SIC_MATRIX_5_MSB__REG		BNO055_SIC_MATRIX_5_MSB_ADDR

#define BNO055_SIC_MATRIX_6_LSB__POS		0
#define BNO055_SIC_MATRIX_6_LSB__MSK		0XFF
#define BNO055_SIC_MATRIX_6_LSB__LEN		8
#define BNO055_SIC_MATRIX_6_LSB__REG		BNO055_SIC_MATRIX_6_LSB_ADDR

#define BNO055_SIC_MATRIX_6_MSB__POS		0
#define BNO055_SIC_MATRIX_6_MSB__MSK		0XFF
#define BNO055_SIC_MATRIX_6_MSB__LEN		8
#define BNO055_SIC_MATRIX_6_MSB__REG		BNO055_SIC_MATRIX_6_MSB_ADDR

#define BNO055_SIC_MATRIX_7_LSB__POS		0
#define BNO055_SIC_MATRIX_7_LSB__MSK		0XFF
#define BNO055_SIC_MATRIX_7_LSB__LEN		8
#define BNO055_SIC_MATRIX_7_LSB__REG		BNO055_SIC_MATRIX_7_LSB_ADDR

#define BNO055_SIC_MATRIX_7_MSB__POS		0
#define BNO055_SIC_MATRIX_7_MSB__MSK		0XFF
#define BNO055_SIC_MATRIX_7_MSB__LEN		8
#define BNO055_SIC_MATRIX_7_MSB__REG		BNO055_SIC_MATRIX_7_MSB_ADDR

#define BNO055_SIC_MATRIX_8_LSB__POS		0
#define BNO055_SIC_MATRIX_8_LSB__MSK		0XFF
#define BNO055_SIC_MATRIX_8_LSB__LEN		8
#define BNO055_SIC_MATRIX_8_LSB__REG		BNO055_SIC_MATRIX_8_LSB_ADDR

#define BNO055_SIC_MATRIX_8_MSB__POS		0
#define BNO055_SIC_MATRIX_8_MSB__MSK		0XFF
#define BNO055_SIC_MATRIX_8_MSB__LEN		8
#define BNO055_SIC_MATRIX_8_MSB__REG		BNO055_SIC_MATRIX_8_MSB_ADDR

/*Accel Offset registers*/
#define BNO055_ACCEL_OFFSET_X_LSB__POS		0
#define BNO055_ACCEL_OFFSET_X_LSB__MSK		0XFF
#define BNO055_ACCEL_OFFSET_X_LSB__LEN		8
#define BNO055_ACCEL_OFFSET_X_LSB__REG		ACCEL_OFFSET_X_LSB_ADDR

#define BNO055_ACCEL_OFFSET_X_MSB__POS		0
#define BNO055_ACCEL_OFFSET_X_MSB__MSK		0XFF
#define BNO055_ACCEL_OFFSET_X_MSB__LEN		8
#define BNO055_ACCEL_OFFSET_X_MSB__REG		ACCEL_OFFSET_X_MSB_ADDR

#define BNO055_ACCEL_OFFSET_Y_LSB__POS		0
#define BNO055_ACCEL_OFFSET_Y_LSB__MSK		0XFF
#define BNO055_ACCEL_OFFSET_Y_LSB__LEN		8
#define BNO055_ACCEL_OFFSET_Y_LSB__REG		ACCEL_OFFSET_Y_LSB_ADDR

#define BNO055_ACCEL_OFFSET_Y_MSB__POS		0
#define BNO055_ACCEL_OFFSET_Y_MSB__MSK		0XFF
#define BNO055_ACCEL_OFFSET_Y_MSB__LEN		8
#define BNO055_ACCEL_OFFSET_Y_MSB__REG		ACCEL_OFFSET_Y_MSB_ADDR

#define BNO055_ACCEL_OFFSET_Z_LSB__POS		0
#define BNO055_ACCEL_OFFSET_Z_LSB__MSK		0XFF
#define BNO055_ACCEL_OFFSET_Z_LSB__LEN		8
#define BNO055_ACCEL_OFFSET_Z_LSB__REG		ACCEL_OFFSET_Z_LSB_ADDR

#define BNO055_ACCEL_OFFSET_Z_MSB__POS		0
#define BNO055_ACCEL_OFFSET_Z_MSB__MSK		0XFF
#define BNO055_ACCEL_OFFSET_Z_MSB__LEN		8
#define BNO055_ACCEL_OFFSET_Z_MSB__REG		ACCEL_OFFSET_Z_MSB_ADDR

/*Mag Offset registers*/
#define BNO055_MAG_OFFSET_X_LSB__POS		0
#define BNO055_MAG_OFFSET_X_LSB__MSK		0XFF
#define BNO055_MAG_OFFSET_X_LSB__LEN		8
#define BNO055_MAG_OFFSET_X_LSB__REG		MAG_OFFSET_X_LSB_ADDR

#define BNO055_MAG_OFFSET_X_MSB__POS		0
#define BNO055_MAG_OFFSET_X_MSB__MSK		0XFF
#define BNO055_MAG_OFFSET_X_MSB__LEN		8
#define BNO055_MAG_OFFSET_X_MSB__REG		MAG_OFFSET_X_MSB_ADDR

#define BNO055_MAG_OFFSET_Y_LSB__POS		0
#define BNO055_MAG_OFFSET_Y_LSB__MSK		0XFF
#define BNO055_MAG_OFFSET_Y_LSB__LEN		8
#define BNO055_MAG_OFFSET_Y_LSB__REG		MAG_OFFSET_Y_LSB_ADDR

#define BNO055_MAG_OFFSET_Y_MSB__POS		0
#define BNO055_MAG_OFFSET_Y_MSB__MSK		0XFF
#define BNO055_MAG_OFFSET_Y_MSB__LEN		8
#define BNO055_MAG_OFFSET_Y_MSB__REG		MAG_OFFSET_Y_MSB_ADDR

#define BNO055_MAG_OFFSET_Z_LSB__POS		0
#define BNO055_MAG_OFFSET_Z_LSB__MSK		0XFF
#define BNO055_MAG_OFFSET_Z_LSB__LEN		8
#define BNO055_MAG_OFFSET_Z_LSB__REG		MAG_OFFSET_Z_LSB_ADDR

#define BNO055_MAG_OFFSET_Z_MSB__POS		0
#define BNO055_MAG_OFFSET_Z_MSB__MSK		0XFF
#define BNO055_MAG_OFFSET_Z_MSB__LEN		8
#define BNO055_MAG_OFFSET_Z_MSB__REG		MAG_OFFSET_Z_MSB_ADDR

/* Gyro Offset registers*/
#define BNO055_GYRO_OFFSET_X_LSB__POS		0
#define BNO055_GYRO_OFFSET_X_LSB__MSK		0XFF
#define BNO055_GYRO_OFFSET_X_LSB__LEN		8
#define BNO055_GYRO_OFFSET_X_LSB__REG		GYRO_OFFSET_X_LSB_ADDR

#define BNO055_GYRO_OFFSET_X_MSB__POS		0
#define BNO055_GYRO_OFFSET_X_MSB__MSK		0XFF
#define BNO055_GYRO_OFFSET_X_MSB__LEN		8
#define BNO055_GYRO_OFFSET_X_MSB__REG		GYRO_OFFSET_X_MSB_ADDR

#define BNO055_GYRO_OFFSET_Y_LSB__POS		0
#define BNO055_GYRO_OFFSET_Y_LSB__MSK		0XFF
#define BNO055_GYRO_OFFSET_Y_LSB__LEN		8
#define BNO055_GYRO_OFFSET_Y_LSB__REG		GYRO_OFFSET_Y_LSB_ADDR

#define BNO055_GYRO_OFFSET_Y_MSB__POS		0
#define BNO055_GYRO_OFFSET_Y_MSB__MSK		0XFF
#define BNO055_GYRO_OFFSET_Y_MSB__LEN		8
#define BNO055_GYRO_OFFSET_Y_MSB__REG		GYRO_OFFSET_Y_MSB_ADDR

#define BNO055_GYRO_OFFSET_Z_LSB__POS		0
#define BNO055_GYRO_OFFSET_Z_LSB__MSK		0XFF
#define BNO055_GYRO_OFFSET_Z_LSB__LEN		8
#define BNO055_GYRO_OFFSET_Z_LSB__REG		GYRO_OFFSET_Z_LSB_ADDR

#define BNO055_GYRO_OFFSET_Z_MSB__POS		0
#define BNO055_GYRO_OFFSET_Z_MSB__MSK		0XFF
#define BNO055_GYRO_OFFSET_Z_MSB__LEN		8
#define BNO055_GYRO_OFFSET_Z_MSB__REG		GYRO_OFFSET_Z_MSB_ADDR

/* Radius register definition*/
#define BNO055_ACCEL_RADIUS_LSB__POS		0
#define BNO055_ACCEL_RADIUS_LSB__MSK		0XFF
#define BNO055_ACCEL_RADIUS_LSB__LEN		8
#define BNO055_ACCEL_RADIUS_LSB__REG		ACCEL_RADIUS_LSB_ADDR

#define BNO055_ACCEL_RADIUS_MSB__POS		0
#define BNO055_ACCEL_RADIUS_MSB__MSK		0XFF
#define BNO055_ACCEL_RADIUS_MSB__LEN		8
#define BNO055_ACCEL_RADIUS_MSB__REG		ACCEL_RADIUS_MSB_ADDR

#define BNO055_MAG_RADIUS_LSB__POS		0
#define BNO055_MAG_RADIUS_LSB__MSK		0XFF
#define BNO055_MAG_RADIUS_LSB__LEN		8
#define BNO055_MAG_RADIUS_LSB__REG		MAG_RADIUS_LSB_ADDR

#define BNO055_MAG_RADIUS_MSB__POS		0
#define BNO055_MAG_RADIUS_MSB__MSK		0XFF
#define BNO055_MAG_RADIUS_MSB__LEN		8
#define BNO055_MAG_RADIUS_MSB__REG		MAG_RADIUS_MSB_ADDR

/* PAGE0 DATA REGISTERS DEFINITION END*/
/*************************************************/
/**\name PAGE1 DATA REGISTERS DEFINITION   */
/*************************************************/
/* Configuration registers*/
/* Accel range configuration register*/
#define BNO055_ACCEL_RANGE__POS		0
#define BNO055_ACCEL_RANGE__MSK		0X03
#define BNO055_ACCEL_RANGE__LEN		2
#define BNO055_ACCEL_RANGE__REG		ACCEL_CONFIG_ADDR

/* Accel bandwidth configuration register*/
#define BNO055_ACCEL_BW__POS			2
#define BNO055_ACCEL_BW__MSK			0X1C
#define BNO055_ACCEL_BW__LEN			3
#define BNO055_ACCEL_BW__REG			ACCEL_CONFIG_ADDR

/* Accel power mode configuration register*/
#define BNO055_ACCEL_POWER_MODE__POS		5
#define BNO055_ACCEL_POWER_MODE__MSK		0XE0
#define BNO055_ACCEL_POWER_MODE__LEN		3
#define BNO055_ACCEL_POWER_MODE__REG		ACCEL_CONFIG_ADDR

/* Mag data output rate configuration register*/
#define BNO055_MAG_DATA_OUTPUT_RATE__POS		0
#define BNO055_MAG_DATA_OUTPUT_RATE__MSK		0X07
#define BNO055_MAG_DATA_OUTPUT_RATE__LEN		3
#define BNO055_MAG_DATA_OUTPUT_RATE__REG		MAG_CONFIG_ADDR

/* Mag operation mode configuration register*/
#define BNO055_MAG_OPERATION_MODE__POS		3
#define BNO055_MAG_OPERATION_MODE__MSK		0X18
#define BNO055_MAG_OPERATION_MODE__LEN		2
#define BNO055_MAG_OPERATION_MODE__REG		MAG_CONFIG_ADDR

/* Mag power mode configuration register*/
#define BNO055_MAG_POWER_MODE__POS		5
#define BNO055_MAG_POWER_MODE__MSK		0X60
#define BNO055_MAG_POWER_MODE__LEN		2
#define BNO055_MAG_POWER_MODE__REG		MAG_CONFIG_ADDR

/* Gyro range configuration register*/
#define BNO055_GYRO_RANGE__POS		0
#define BNO055_GYRO_RANGE__MSK		0X07
#define BNO055_GYRO_RANGE__LEN		3
#define BNO055_GYRO_RANGE__REG		GYRO_CONFIG_ADDR

/* Gyro bandwidth configuration register*/
#define BNO055_GYRO_BW__POS		3
#define BNO055_GYRO_BW__MSK		0X38
#define BNO055_GYRO_BW__LEN		3
#define BNO055_GYRO_BW__REG		GYRO_CONFIG_ADDR

/* Gyro power mode configuration register*/
#define BNO055_GYRO_POWER_MODE__POS		0
#define BNO055_GYRO_POWER_MODE__MSK		0X07
#define BNO055_GYRO_POWER_MODE__LEN		3
#define BNO055_GYRO_POWER_MODE__REG		GYRO_MODE_CONFIG_ADDR

/* Sleep configuration registers*/
/* Accel sleep mode configuration register*/
#define BNO055_ACCEL_SLEEP_MODE__POS		0
#define BNO055_ACCEL_SLEEP_MODE__MSK		0X01
#define BNO055_ACCEL_SLEEP_MODE__LEN		1
#define BNO055_ACCEL_SLEEP_MODE__REG		ACCEL_SLEEP_CONFIG_ADDR

/* Accel sleep duration configuration register*/
#define BNO055_ACCEL_SLEEP_DURN__POS		1
#define BNO055_ACCEL_SLEEP_DURN__MSK		0X1E
#define BNO055_ACCEL_SLEEP_DURN__LEN		4
#define BNO055_ACCEL_SLEEP_DURN__REG		ACCEL_SLEEP_CONFIG_ADDR

/* Gyro sleep duration configuration register*/
#define BNO055_GYRO_SLEEP_DURN__POS		0
#define BNO055_GYRO_SLEEP_DURN__MSK		0X07
#define BNO055_GYRO_SLEEP_DURN__LEN		3
#define BNO055_GYRO_SLEEP_DURN__REG		GYRO_SLEEP_CONFIG_ADDR

/* Gyro auto sleep duration configuration register*/
#define BNO055_GYRO_AUTO_SLEEP_DURN__POS		3
#define BNO055_GYRO_AUTO_SLEEP_DURN__MSK		0X38
#define BNO055_GYRO_AUTO_SLEEP_DURN__LEN		3
#define BNO055_GYRO_AUTO_SLEEP_DURN__REG		GYRO_SLEEP_CONFIG_ADDR

/* Mag sleep mode configuration register*/
#define BNO055_MAG_SLEEP_MODE__POS		0
#define BNO055_MAG_SLEEP_MODE__MSK		0X01
#define BNO055_MAG_SLEEP_MODE__LEN		1
#define BNO055_MAG_SLEEP_MODE__REG		MAG_SLEEP_CONFIG_ADDR

/* Mag sleep duration configuration register*/
#define BNO055_MAG_SLEEP_DURN__POS		1
#define BNO055_MAG_SLEEP_DURN__MSK		0X1E
#define BNO055_MAG_SLEEP_DURN__LEN		4
#define BNO055_MAG_SLEEP_DURN__REG		MAG_SLEEP_CONFIG_ADDR

/* Interrupt registers*/
/* Gyro any motion interrupt msk register*/
#define BNO055_GYRO_ANY_MOTION_INTR_MASK__POS		2
#define BNO055_GYRO_ANY_MOTION_INTR_MASK__MSK		0X04
#define BNO055_GYRO_ANY_MOTION_INTR_MASK__LEN		1
#define BNO055_GYRO_ANY_MOTION_INTR_MASK__REG		INT_MASK_ADDR

/* Gyro high rate interrupt msk register*/
#define BNO055_GYRO_HIGHRATE_INTR_MASK__POS		3
#define BNO055_GYRO_HIGHRATE_INTR_MASK__MSK		0X08
#define BNO055_GYRO_HIGHRATE_INTR_MASK__LEN		1
#define BNO055_GYRO_HIGHRATE_INTR_MASK__REG		INT_MASK_ADDR

/* Accel high g interrupt msk register*/
#define BNO055_ACCEL_HIGH_G_INTR_MASK__POS		5
#define BNO055_ACCEL_HIGH_G_INTR_MASK__MSK		0X20
#define BNO055_ACCEL_HIGH_G_INTR_MASK__LEN		1
#define BNO055_ACCEL_HIGH_G_INTR_MASK__REG		INT_MASK_ADDR

/* Accel any motion interrupt msk register*/
#define BNO055_ACCEL_ANY_MOTION_INTR_MASK__POS		6
#define BNO055_ACCEL_ANY_MOTION_INTR_MASK__MSK		0X40
#define BNO055_ACCEL_ANY_MOTION_INTR_MASK__LEN		1
#define BNO055_ACCEL_ANY_MOTION_INTR_MASK__REG		INT_MASK_ADDR

/* Accel any motion interrupt msk register*/
#define BNO055_ACCEL_NO_MOTION_INTR_MASK__POS		7
#define BNO055_ACCEL_NO_MOTION_INTR_MASK__MSK		0X80
#define BNO055_ACCEL_NO_MOTION_INTR_MASK__LEN		1
#define BNO055_ACCEL_NO_MOTION_INTR_MASK__REG		INT_MASK_ADDR

/* Gyro any motion interrupt register*/
#define BNO055_GYRO_ANY_MOTION_INTR__POS		2
#define BNO055_GYRO_ANY_MOTION_INTR__MSK		0X04
#define BNO055_GYRO_ANY_MOTION_INTR__LEN		1
#define BNO055_GYRO_ANY_MOTION_INTR__REG		INT_ADDR

/* Gyro high rate interrupt register*/
#define BNO055_GYRO_HIGHRATE_INTR__POS		3
#define BNO055_GYRO_HIGHRATE_INTR__MSK		0X08
#define BNO055_GYRO_HIGHRATE_INTR__LEN		1
#define BNO055_GYRO_HIGHRATE_INTR__REG		INT_ADDR

/* Accel high g interrupt register*/
#define BNO055_ACCEL_HIGH_G_INTR__POS		5
#define BNO055_ACCEL_HIGH_G_INTR__MSK		0X20
#define BNO055_ACCEL_HIGH_G_INTR__LEN		1
#define BNO055_ACCEL_HIGH_G_INTR__REG		INT_ADDR

/* Accel any motion interrupt register*/
#define BNO055_ACCEL_ANY_MOTION_INTR__POS		6
#define BNO055_ACCEL_ANY_MOTION_INTR__MSK		0X40
#define BNO055_ACCEL_ANY_MOTION_INTR__LEN		1
#define BNO055_ACCEL_ANY_MOTION_INTR__REG		INT_ADDR

/*Accel any motion interrupt register*/
#define BNO055_ACCEL_NO_MOTION_INTR__POS		7
#define BNO055_ACCEL_NO_MOTION_INTR__MSK		0X80
#define BNO055_ACCEL_NO_MOTION_INTR__LEN		1
#define BNO055_ACCEL_NO_MOTION_INTR__REG		INT_ADDR

/*Accel any motion threshold setting*/
#define BNO055_ACCEL_ANY_MOTION_THRES__POS	0
#define BNO055_ACCEL_ANY_MOTION_THRES__MSK	0XFF
#define BNO055_ACCEL_ANY_MOTION_THRES__LEN	8
#define BNO055_ACCEL_ANY_MOTION_THRES__REG	ACCEL_ANY_MOTION_THRES_ADDR

/*Accel interrupt setting register*/
#define BNO055_ACCEL_ANY_MOTION_DURN_SET__POS		0
#define BNO055_ACCEL_ANY_MOTION_DURN_SET__MSK		0X03
#define BNO055_ACCEL_ANY_MOTION_DURN_SET__LEN		2
#define BNO055_ACCEL_ANY_MOTION_DURN_SET__REG		ACCEL_INTR_SETTINGS_ADDR

/* Accel AM/NM axis selection register*/
#define BNO055_ACCEL_ANY_MOTION_X_AXIS__POS		2
#define BNO055_ACCEL_ANY_MOTION_X_AXIS__MSK		0X04
#define BNO055_ACCEL_ANY_MOTION_X_AXIS__LEN		1
#define BNO055_ACCEL_ANY_MOTION_X_AXIS__REG		ACCEL_INTR_SETTINGS_ADDR

#define BNO055_ACCEL_ANY_MOTION_Y_AXIS__POS		3
#define BNO055_ACCEL_ANY_MOTION_Y_AXIS__MSK		0X08
#define BNO055_ACCEL_ANY_MOTION_Y_AXIS__LEN		1
#define BNO055_ACCEL_ANY_MOTION_Y_AXIS__REG		ACCEL_INTR_SETTINGS_ADDR

#define BNO055_ACCEL_ANY_MOTION_Z_AXIS__POS		4
#define BNO055_ACCEL_ANY_MOTION_Z_AXIS__MSK		0X10
#define BNO055_ACCEL_ANY_MOTION_Z_AXIS__LEN		1
#define BNO055_ACCEL_ANY_MOTION_Z_AXIS__REG		ACCEL_INTR_SETTINGS_ADDR

/* Accel high g axis selection register*/
#define BNO055_ACCEL_HIGH_G_X_AXIS__POS		5
#define BNO055_ACCEL_HIGH_G_X_AXIS__MSK		0X20
#define BNO055_ACCEL_HIGH_G_X_AXIS__LEN		1
#define BNO055_ACCEL_HIGH_G_X_AXIS__REG		ACCEL_INTR_SETTINGS_ADDR

#define BNO055_ACCEL_HIGH_G_Y_AXIS__POS		6
#define BNO055_ACCEL_HIGH_G_Y_AXIS__MSK		0X40
#define BNO055_ACCEL_HIGH_G_Y_AXIS__LEN		1
#define BNO055_ACCEL_HIGH_G_Y_AXIS__REG		ACCEL_INTR_SETTINGS_ADDR

#define BNO055_ACCEL_HIGH_G_Z_AXIS__POS		7
#define BNO055_ACCEL_HIGH_G_Z_AXIS__MSK		0X80
#define BNO055_ACCEL_HIGH_G_Z_AXIS__LEN		1
#define BNO055_ACCEL_HIGH_G_Z_AXIS__REG		ACCEL_INTR_SETTINGS_ADDR

/* Accel High g duration setting register*/
#define BNO055_ACCEL_HIGH_G_DURN__POS		0
#define BNO055_ACCEL_HIGH_G_DURN__MSK		0XFF
#define BNO055_ACCEL_HIGH_G_DURN__LEN		8
#define BNO055_ACCEL_HIGH_G_DURN__REG		ACCEL_HIGH_G_DURN_ADDR

/* Accel High g threshold setting register*/
#define BNO055_ACCEL_HIGH_G_THRES__POS		0
#define BNO055_ACCEL_HIGH_G_THRES__MSK		0XFF
#define BNO055_ACCEL_HIGH_G_THRES__LEN		8
#define BNO055_ACCEL_HIGH_G_THRES__REG		ACCEL_HIGH_G_THRES_ADDR

/* Accel no/slow motion threshold setting*/
#define BNO055_ACCEL_SLOW_NO_MOTION_THRES__POS		0
#define BNO055_ACCEL_SLOW_NO_MOTION_THRES__MSK		0XFF
#define BNO055_ACCEL_SLOW_NO_MOTION_THRES__LEN		8
#define BNO055_ACCEL_SLOW_NO_MOTION_THRES__REG		\
ACCEL_NO_MOTION_THRES_ADDR

/* Accel no/slow motion enable setting*/
#define BNO055_ACCEL_SLOW_NO_MOTION_ENABLE__POS		0
#define BNO055_ACCEL_SLOW_NO_MOTION_ENABLE__MSK		0X01
#define BNO055_ACCEL_SLOW_NO_MOTION_ENABLE__LEN		1
#define BNO055_ACCEL_SLOW_NO_MOTION_ENABLE__REG		ACCEL_NO_MOTION_SET_ADDR

/* Accel no/slow motion duration setting*/
#define BNO055_ACCEL_SLOW_NO_MOTION_DURN__POS		1
#define BNO055_ACCEL_SLOW_NO_MOTION_DURN__MSK		0X7E
#define BNO055_ACCEL_SLOW_NO_MOTION_DURN__LEN		6
#define BNO055_ACCEL_SLOW_NO_MOTION_DURN__REG		ACCEL_NO_MOTION_SET_ADDR

/*Gyro interrupt setting register*/
/*Gyro any motion axis setting*/
#define BNO055_GYRO_ANY_MOTION_X_AXIS__POS		0
#define BNO055_GYRO_ANY_MOTION_X_AXIS__MSK		0X01
#define BNO055_GYRO_ANY_MOTION_X_AXIS__LEN		1
#define BNO055_GYRO_ANY_MOTION_X_AXIS__REG		GYRO_INTR_SETING_ADDR

#define BNO055_GYRO_ANY_MOTION_Y_AXIS__POS		1
#define BNO055_GYRO_ANY_MOTION_Y_AXIS__MSK		0X02
#define BNO055_GYRO_ANY_MOTION_Y_AXIS__LEN		1
#define BNO055_GYRO_ANY_MOTION_Y_AXIS__REG		GYRO_INTR_SETING_ADDR

#define BNO055_GYRO_ANY_MOTION_Z_AXIS__POS		2
#define BNO055_GYRO_ANY_MOTION_Z_AXIS__MSK		0X04
#define BNO055_GYRO_ANY_MOTION_Z_AXIS__LEN		1
#define BNO055_GYRO_ANY_MOTION_Z_AXIS__REG		GYRO_INTR_SETING_ADDR

/*Gyro high rate axis setting*/
#define BNO055_GYRO_HIGHRATE_X_AXIS__POS		3
#define BNO055_GYRO_HIGHRATE_X_AXIS__MSK		0X08
#define BNO055_GYRO_HIGHRATE_X_AXIS__LEN		1
#define BNO055_GYRO_HIGHRATE_X_AXIS__REG		GYRO_INTR_SETING_ADDR

#define BNO055_GYRO_HIGHRATE_Y_AXIS__POS		4
#define BNO055_GYRO_HIGHRATE_Y_AXIS__MSK		0X10
#define BNO055_GYRO_HIGHRATE_Y_AXIS__LEN		1
#define BNO055_GYRO_HIGHRATE_Y_AXIS__REG		GYRO_INTR_SETING_ADDR

#define BNO055_GYRO_HIGHRATE_Z_AXIS__POS		5
#define BNO055_GYRO_HIGHRATE_Z_AXIS__MSK		0X20
#define BNO055_GYRO_HIGHRATE_Z_AXIS__LEN		1
#define BNO055_GYRO_HIGHRATE_Z_AXIS__REG		GYRO_INTR_SETING_ADDR

/* Gyro filter setting*/
#define BNO055_GYRO_ANY_MOTION_FILTER__POS		6
#define BNO055_GYRO_ANY_MOTION_FILTER__MSK		0X40
#define BNO055_GYRO_ANY_MOTION_FILTER__LEN		1
#define BNO055_GYRO_ANY_MOTION_FILTER__REG		GYRO_INTR_SETING_ADDR

#define BNO055_GYRO_HIGHRATE_FILTER__POS		7
#define BNO055_GYRO_HIGHRATE_FILTER__MSK		0X80
#define BNO055_GYRO_HIGHRATE_FILTER__LEN		1
#define BNO055_GYRO_HIGHRATE_FILTER__REG		GYRO_INTR_SETING_ADDR

/* Gyro high rate X axis settings*/
#define BNO055_GYRO_HIGHRATE_X_THRES__POS		0
#define BNO055_GYRO_HIGHRATE_X_THRES__MSK		0X1F
#define BNO055_GYRO_HIGHRATE_X_THRES__LEN		5
#define BNO055_GYRO_HIGHRATE_X_THRES__REG		GYRO_HIGHRATE_X_SET_ADDR

#define BNO055_GYRO_HIGHRATE_X_HYST__POS		5
#define BNO055_GYRO_HIGHRATE_X_HYST__MSK		0X60
#define BNO055_GYRO_HIGHRATE_X_HYST__LEN		2
#define BNO055_GYRO_HIGHRATE_X_HYST__REG		GYRO_HIGHRATE_X_SET_ADDR

#define BNO055_GYRO_HIGHRATE_X_DURN__POS		0
#define BNO055_GYRO_HIGHRATE_X_DURN__MSK		0XFF
#define BNO055_GYRO_HIGHRATE_X_DURN__LEN		8
#define BNO055_GYRO_HIGHRATE_X_DURN__REG		GYRO_DURN_X_ADDR

/* Gyro high rate Y axis settings*/
#define BNO055_GYRO_HIGHRATE_Y_THRES__POS		0
#define BNO055_GYRO_HIGHRATE_Y_THRES__MSK		0X1F
#define BNO055_GYRO_HIGHRATE_Y_THRES__LEN		5
#define BNO055_GYRO_HIGHRATE_Y_THRES__REG		GYRO_HIGHRATE_Y_SET_ADDR

#define BNO055_GYRO_HIGHRATE_Y_HYST__POS		5
#define BNO055_GYRO_HIGHRATE_Y_HYST__MSK		0X60
#define BNO055_GYRO_HIGHRATE_Y_HYST__LEN		2
#define BNO055_GYRO_HIGHRATE_Y_HYST__REG		GYRO_HIGHRATE_Y_SET_ADDR

#define BNO055_GYRO_HIGHRATE_Y_DURN__POS		0
#define BNO055_GYRO_HIGHRATE_Y_DURN__MSK		0XFF
#define BNO055_GYRO_HIGHRATE_Y_DURN__LEN		8
#define BNO055_GYRO_HIGHRATE_Y_DURN__REG		GYRO_DURN_Y_ADDR

/* Gyro high rate Z axis settings*/
#define BNO055_GYRO_HIGHRATE_Z_THRES__POS		0
#define BNO055_GYRO_HIGHRATE_Z_THRES__MSK		0X1F
#define BNO055_GYRO_HIGHRATE_Z_THRES__LEN		5
#define BNO055_GYRO_HIGHRATE_Z_THRES__REG		GYRO_HIGHRATE_Z_SET_ADDR

#define BNO055_GYRO_HIGHRATE_Z_HYST__POS		5
#define BNO055_GYRO_HIGHRATE_Z_HYST__MSK		0X60
#define BNO055_GYRO_HIGHRATE_Z_HYST__LEN		2
#define BNO055_GYRO_HIGHRATE_Z_HYST__REG		GYRO_HIGHRATE_Z_SET_ADDR

#define BNO055_GYRO_HIGHRATE_Z_DURN__POS		0
#define BNO055_GYRO_HIGHRATE_Z_DURN__MSK		0XFF
#define BNO055_GYRO_HIGHRATE_Z_DURN__LEN		8
#define BNO055_GYRO_HIGHRATE_Z_DURN__REG		GYRO_DURN_Z_ADDR

/*Gyro any motion threshold setting*/
#define BNO055_GYRO_ANY_MOTION_THRES__POS		0
#define BNO055_GYRO_ANY_MOTION_THRES__MSK		0X7F
#define BNO055_GYRO_ANY_MOTION_THRES__LEN		7
#define BNO055_GYRO_ANY_MOTION_THRES__REG		\
GYRO_ANY_MOTION_THRES_ADDR

/* Gyro any motion slope sample setting*/
#define BNO055_GYRO_SLOPE_SAMPLES__POS		0
#define BNO055_GYRO_SLOPE_SAMPLES__MSK		0X03
#define BNO055_GYRO_SLOPE_SAMPLES__LEN		2
#define BNO055_GYRO_SLOPE_SAMPLES__REG		GYRO_ANY_MOTION_SET_ADDR

/* Gyro awake duration setting*/
#define BNO055_GYRO_AWAKE_DURN__POS		2
#define BNO055_GYRO_AWAKE_DURN__MSK		0X0C
#define BNO055_GYRO_AWAKE_DURN__LEN		2
#define BNO055_GYRO_AWAKE_DURN__REG		GYRO_ANY_MOTION_SET_ADDR

/**\name GET AND SET BITSLICE FUNCTIONS    */
/*************************************************/
#define BNO055_GET_BITSLICE(regvar, bitname)\
((regvar & bitname##__MSK) >> bitname##__POS)


#define BNO055_SET_BITSLICE(regvar, bitname, val)\
((regvar & ~bitname##__MSK) | ((val<<bitname##__POS)&bitname##__MSK))

class BNO055 {
public:
    
        /*----------------------------------------------------------------------------*
     *  struct bno055_t parameters can be accessed by using BNO055
     *	BNO055_t having the following parameters
     *	Bus write function pointer: BNO055_WR_FUNC_PTR
     *	Bus read function pointer: BNO055_RD_FUNC_PTR
     *	Burst read function pointer: BNO055_BRD_FUNC_PTR
     *	Delay function pointer: delay_msec
     *	I2C address: dev_addr
     *	Chip id of the sensor: chip_id
    *---------------------------------------------------------------------------*/
    struct bno055_t bno055;
    
    /*	STRUCTURE DEFINITIONS	*/
    struct bno055_t *p_bno055;
    
    BNO055();
    BNO055(const char* portname);
    BNO055(const BNO055& orig);
    virtual ~BNO055();
    
    s8 BNO055_bus_write(u8 dev_addr, u8 reg_addr, u8 *reg_data, u8 cnt);
    s8 BNO055_bus_read(u8 dev_addr, u8 reg_addr, u8 *reg_data, u8 cnt);
    void BNO055_delay_msek(u32 msek);
    BNO055_RETURN_FUNCTION_TYPE bno055_init();
    BNO055_RETURN_FUNCTION_TYPE bno055_set_operation_mode(u8 v_operation_mode_u8);
    BNO055_RETURN_FUNCTION_TYPE bno055_get_operation_mode(u8 *v_operation_mode_u8);
    BNO055_RETURN_FUNCTION_TYPE bno055_write_register(u8 v_addr_u8, u8 *p_data_u8, u8 v_len_u8);
    BNO055_RETURN_FUNCTION_TYPE bno055_set_power_mode(u8 v_power_mode_u8);
    BNO055_RETURN_FUNCTION_TYPE bno055_write_page_id(u8 v_page_id_u8);
    BNO055_RETURN_FUNCTION_TYPE bno055_read_euler_hrp(struct bno055_euler_t *euler);
    BNO055_RETURN_FUNCTION_TYPE bno055_convert_double_euler_hpr_deg(struct bno055_euler_double_t *euler_hpr);
    BNO055_RETURN_FUNCTION_TYPE bno055_get_euler_unit(u8 *v_euler_unit_u8);
    BNO055_RETURN_FUNCTION_TYPE bno055_set_euler_unit(u8 v_euler_unit_u8);
    void bno055_read_new();
	double Heading();
	double Roll();
	double Pitch();


private:
    Interface *uart1;
	struct bno055_euler_t euler_hrp;
	struct bno055_euler_double_t d_euler_hrp;

};

#endif /* BNO055_H */

