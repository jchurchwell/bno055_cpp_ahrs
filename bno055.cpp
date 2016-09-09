/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   BNO055.cpp
 * Author: jchurchwell
 * 
 * Created on August 11, 2016, 9:02 AM
 */

#include "Interface.h"
#include "bno055.h"
#include <cstdlib>
#include <unistd.h>
#include <string>
#include <stdio.h>

BNO055::BNO055(const char* portname) {
    
    uart1 = new Interface(portname);
    
    /* variable used to set the power mode of the sensor*/
    u8 power_mode = BNO055_ZERO_U8X;    

    this->bno055_init();
    
    power_mode = POWER_MODE_NORMAL; /* set the power mode as NORMAL*/
    this->bno055_set_power_mode(power_mode);
    
    /* Wait for the interface to send all the data */
    this->BNO055_delay_msek(20);
        
    this->bno055_set_operation_mode(OPERATION_MODE_NDOF);

}

BNO055::BNO055(const BNO055& orig) {
}

BNO055::~BNO055() {
}

/*-------------------------------------------------------------------*
*
*	This is a sample code for read and write the data by using I2C
*	Use either I2C  based on your need
*	The device address defined in the bno055.h file
*
*-----------------------------------------------------------------------*/

/*	\Brief: The function is used as I2C bus write
 *	\Return : Status of the I2C write
 *	\param dev_addr : The device address of the sensor
 *	\param reg_addr : Address of the first register, will data is going to be written
 *	\param reg_data : It is a value hold in the array,
 *		will be used for write the value into the register
 *	\param cnt : The no of byte of data to be write
 */
s8 BNO055::BNO055_bus_write(u8 dev_addr, u8 reg_addr, u8 *reg_data, u8 cnt)
{
    s32 iError = BNO055_ZERO_U8X;
    u8 stringpos = BNO055_ZERO_U8X;

    // Declare an output array to pass to the read/write functions
    u8 output[128];

    // Setup an output array
    output[0] = 0xAA;
    output[1] = 0x00;
    output[2] = reg_addr;            
    output[3] = cnt;    
    
    for(stringpos = 0; stringpos < cnt; stringpos++){
        output[stringpos+4] = reg_data[stringpos];        
    }
    
    // Output a message with all the data
    uart1->Write(output, 4+cnt);  
    
    
    
    /* We could check to see the data that has come back here for an error 
     * but instead let's not delay and wait for the information to come in.
     * The read function calls the flush routine
    */

	return (s8)iError;
}

 /*	\Brief: The function is used as I2C bus read
 *	\Return : Status of the I2C read
 *	\param dev_addr : The device address of the sensor
 *	\param reg_addr : Address of the first register, will data is going to be read
 *	\param reg_data : This data read from the sensor, which is hold in an array
 *	\param cnt : The no of byte of data to be read
 */
s8 BNO055::BNO055_bus_read(u8 dev_addr, u8 reg_addr, u8 *reg_data, u8 cnt)
{
    s32 iError = BNO055_ZERO_U8X;
    u8 stringpos = BNO055_ZERO_U8X;
    u8 outputByteCount;
    // Declare an output array to pass to the read/write functions
    u8 output[128];
    
    // Setup an output array
    output[0] = 0xAA;
    output[1] = 0x01;
    output[2] = reg_addr;
    output[3] = cnt;
    
    // Clear out anything that is still in the buffer
    //uart1.flush_buffer();
    
    // Output a message with all the data
    uart1->Write(output, 4);
    
    // Wait for the interface to send all the data
    this->BNO055_delay_msek(20);
    
    outputByteCount = 2+cnt;
    uart1->Read(output, &outputByteCount);
    
    // Check the incoming bytes to determine success or failure
    if(output[0] != 0xBB){
        iError = ERROR;
    }else{
        
        // Get all the data bytes received
        for(stringpos = 2; stringpos < cnt+2; stringpos++){
             reg_data[stringpos-2] = output[stringpos];     
        }
        
        iError = SUCCESS;        
    }
        
    return (s8)iError;
}
/*	Brief : The delay routine
 *	\param : delay in ms
*/
void BNO055::BNO055_delay_msek(u32 msek)
{
    /*Here you can write your own delay routine*/    
    usleep((useconds_t)msek*1000);
}

/*!
 *	@brief
 *	This function is used for initialize
 *	bus read, bus write function pointers,device
 *	address,accel revision id, gyro revision id
 *	mag revision id, software revision id, boot loader
 *	revision id and page id
 *
 *	@param  bno055 - structure pointer
 *
 *
 *	@return results of bus communication function
 *	@retval 0 -> Success
 *	@retval 1 -> Error
 *
 *	@note While changing the parameter of the bno055_t
 *	consider the following point:
 *	Changing the reference value of the parameter
 *	will changes the local copy or local reference
 *	make sure your changes will not
 *	affect the reference value of the parameter
 *	(Better case don't change the reference value of the parameter)
 */
BNO055_RETURN_FUNCTION_TYPE BNO055::bno055_init()
{
    /* Variable used to return value of communication routine*/
    BNO055_RETURN_FUNCTION_TYPE com_rslt = ERROR;
    u8 v_data_u8 = BNO055_ZERO_U8X;
    u8 v_page_zero_u8 = PAGE_ZERO;
    
    /* Array holding the Software revision id */
    u8 a_SW_ID_u8[ARRAY_SIZE_TWO] = {BNO055_ZERO_U8X, BNO055_ZERO_U8X};
    
    /* stuct parameters are assign to bno055*/
    p_bno055 = &bno055;
    
    /* Write the default page as zero*/
    com_rslt = BNO055::BNO055_bus_write(p_bno055->dev_addr, 
                                        BNO055_PAGE_ID__REG, 
                                        &v_page_zero_u8, 
                                        BNO055_ONE_U8X);
    /* Read the chip id of the sensor from page
    zero 0x00 register*/
    com_rslt += BNO055::BNO055_bus_read(p_bno055->dev_addr,
                                        BNO055_CHIP_ID__REG, 
                                        &v_data_u8, 
                                        BNO055_ONE_U8X);
    p_bno055->chip_id = v_data_u8;
    
    /* Read the accel revision id from page
    zero 0x01 register*/
    com_rslt += BNO055::BNO055_bus_read(p_bno055->dev_addr,
                                        BNO055_ACCEL_REV_ID__REG, 
                                        &v_data_u8, 
                                        BNO055_ONE_U8X);
    p_bno055->accel_rev_id = v_data_u8;
    
    /* Read the mag revision id from page
    zero 0x02 register*/
    com_rslt += BNO055::BNO055_bus_read(p_bno055->dev_addr, 
                                        BNO055_MAG_REV_ID__REG, 
                                        &v_data_u8, 
                                        BNO055_ONE_U8X);
    p_bno055->mag_rev_id = v_data_u8;
    /* Read the gyro revision id from page
    zero 0x02 register*/
    com_rslt += BNO055::BNO055_bus_read(p_bno055->dev_addr,
                                        BNO055_GYRO_REV_ID__REG, 
                                        &v_data_u8, 
                                        BNO055_ONE_U8X);
    p_bno055->gyro_rev_id = v_data_u8;
    /* Read the boot loader revision from page
    zero 0x06 register*/
    com_rslt += BNO055::BNO055_bus_read(p_bno055->dev_addr,
                                        BNO055_BL_REV_ID__REG, 
                                        &v_data_u8, 
                                        BNO055_ONE_U8X);
    p_bno055->bl_rev_id = v_data_u8;
    /* Read the software revision id from page
    zero 0x04 and 0x05 register( 2 bytes of data)*/
    com_rslt += BNO055::BNO055_bus_read(p_bno055->dev_addr,
                                        BNO055_SW_REV_ID_LSB__REG, 
                                        a_SW_ID_u8, 
                                        BNO055_TWO_U8X);
    a_SW_ID_u8[INDEX_ZERO] = BNO055_GET_BITSLICE(a_SW_ID_u8[INDEX_ZERO], BNO055_SW_REV_ID_LSB);
    
    p_bno055->sw_rev_id = (u16)((((u32)((u8)a_SW_ID_u8[INDEX_ONE])) << BNO055_SHIFT_8_POSITION) | (a_SW_ID_u8[INDEX_ZERO]));
    
    /* Read the page id from the register 0x07*/
    com_rslt += BNO055::BNO055_bus_read(p_bno055->dev_addr, BNO055_PAGE_ID__REG, &v_data_u8, BNO055_ONE_U8X);
    
    p_bno055->page_id = v_data_u8;

    return com_rslt;
}


/*!	@brief This API used to write the operation mode
 *	from register from 0x3D bit 0 to 3
 *
 *	@param v_operation_mode_u8 : The value of operation mode
 *
 *  v_operation_mode_u8  |      result    | comments
 * ----------|----------------------------|----------------------------
 *  0x00     | OPERATION_MODE_CONFIG      | Configuration mode
 *  0x01     | OPERATION_MODE_ACCONLY     | Reads accel data alone
 *  0x02     | OPERATION_MODE_MAGONLY     | Reads mag data alone
 *  0x03     | OPERATION_MODE_GYRONLY     | Reads gyro data alone
 *  0x04     | OPERATION_MODE_ACCMAG      | Reads accel and mag data
 *  0x05     | OPERATION_MODE_ACCGYRO     | Reads accel and gyro data
 *  0x06     | OPERATION_MODE_MAGGYRO     | Reads accel and mag data
 *  0x07     | OPERATION_MODE_ANY_MOTION  | Reads accel mag and gyro data
 *  0x08     | OPERATION_MODE_IMUPLUS     | Inertial measurement unit
 *   -       |       -                    | Reads accel,gyro and fusion data
 *  0x09     | OPERATION_MODE_COMPASS     | Reads accel, mag data
 *   -       |       -                    | and fusion data
 *  0x0A     | OPERATION_MODE_M4G         | Reads accel, mag data
 *    -      |       -                    | and fusion data
 *  0x0B     | OPERATION_MODE_NDOF_FMC_OFF| Nine degrees of freedom with
 *   -       |       -                    | fast magnetic calibration
 *   -       |       -                    | Reads accel,mag, gyro
 *   -       |       -                    | and fusion data
 *  0x0C     | OPERATION_MODE_NDOF        | Nine degrees of freedom
 *   -       |       -                    | Reads accel,mag, gyro
 *   -       |       -                    | and fusion data
 *
 *	@return results of bus communication function
 *	@retval 0 -> Success
 *	@retval 1 -> Error
 *
 *	@note In the config mode, all sensor and fusion data
 *	becomes zero and it is mainly derived
 *	to configure the various settings of the BNO
 *
 */
BNO055_RETURN_FUNCTION_TYPE BNO055::bno055_set_operation_mode(u8 v_operation_mode_u8)
{
    BNO055_RETURN_FUNCTION_TYPE com_rslt = ERROR;
    u8 v_data_u8r = BNO055_ZERO_U8X;
    u8 v_prev_opmode_u8 = OPERATION_MODE_CONFIG;
    s8 v_stat_s8 = ERROR;
    
    /* Check the struct p_bno055 is empty */
    if (p_bno055 == BNO055_ZERO_U8X) 
    {
        return E_NULL_PTR;
    } else {
        /* The write operation effective only if the operation
        mode is in config mode, this part of code is checking the
        current operation mode and set the config mode */
        v_stat_s8 = BNO055::bno055_get_operation_mode(&v_prev_opmode_u8);
        
        if (v_stat_s8 == SUCCESS) {
            /* If the previous operation mode is config it is
            directly write the operation mode */
            if (v_prev_opmode_u8 == OPERATION_MODE_CONFIG) 
            {
                com_rslt = BNO055::BNO055_bus_read(p_bno055->dev_addr,
                                                    BNO055_OPERATION_MODE__REG,
                                                    &v_data_u8r, 
                                                    BNO055_ONE_U8X);
                if (com_rslt == SUCCESS) 
                {
                    v_data_u8r = BNO055_SET_BITSLICE(v_data_u8r, 
                                                    BNO055_OPERATION_MODE,                    
                                                    v_operation_mode_u8);
                    com_rslt +=
                            BNO055::BNO055_bus_write(p_bno055->dev_addr,
                                                     BNO055_OPERATION_MODE__REG,
                                                     &v_data_u8r, 
                                                     BNO055_ONE_U8X);
                    /* Config mode to other
                    operation mode switching
                    required delay of 600ms*/                    
                    this->BNO055_delay_msek(BNO055_SIX_HUNDRES_U8X);
                }
            } else {
                /* If the previous operation
                mode is not config it is
                write the config mode */
                com_rslt = BNO055::BNO055_bus_read(p_bno055->dev_addr,
                                                   BNO055_OPERATION_MODE__REG,
                                                   &v_data_u8r, 
                                                   BNO055_ONE_U8X);
                if (com_rslt == SUCCESS) 
                {
                    v_data_u8r = BNO055_SET_BITSLICE(v_data_u8r, 
                                                BNO055_OPERATION_MODE,
                                                OPERATION_MODE_CONFIG);
                    com_rslt += BNO055::bno055_write_register(BNO055_OPERATION_MODE__REG,
                                                     &v_data_u8r, 
                                                     BNO055_ONE_U8X);
                    /* other mode to config mode switching
                    required delay of 20ms*/
                    this->BNO055_delay_msek(BNO055_TWENTY_U8X);
                }
                /* Write the operation mode */
                if (v_operation_mode_u8 != OPERATION_MODE_CONFIG) 
                {
                    com_rslt =
                            BNO055::BNO055_bus_read(p_bno055->dev_addr,
                                                    BNO055_OPERATION_MODE__REG,
                                                    &v_data_u8r, 
                                                    BNO055_ONE_U8X);
                    if (com_rslt == SUCCESS) 
                    {
                        v_data_u8r = BNO055_SET_BITSLICE(v_data_u8r, BNO055_OPERATION_MODE, v_operation_mode_u8);
                        com_rslt +=
                                BNO055::BNO055_bus_write(p_bno055->dev_addr, 
                                                        BNO055_OPERATION_MODE__REG,
                                                        &v_data_u8r, 
                                                        BNO055_ONE_U8X);
                        /* Config mode to other
                        operation mode switching
                        required delay of 600ms*/
                        this->BNO055_delay_msek(BNO055_SIX_HUNDRES_U8X);

                    }
                }
            }
        } else {
        com_rslt = ERROR;
        }
    }
    return com_rslt;
}

/*!	@brief This API used to read the operation mode
 *	from register from 0x3D bit 0 to 3
 *
 *	@param v_operation_mode_u8 : The value of operation mode
 *
 * v_operation_mode_u8 |      result      | comments
 * ----------|----------------------------|----------------------------
 *  0x00     | OPERATION_MODE_CONFIG      | Configuration mode
 *  0x01     | OPERATION_MODE_ACCONLY     | Reads accel data alone
 *  0x02     | OPERATION_MODE_MAGONLY     | Reads mag data alone
 *  0x03     | OPERATION_MODE_GYRONLY     | Reads gyro data alone
 *  0x04     | OPERATION_MODE_ACCMAG      | Reads accel and mag data
 *  0x05     | OPERATION_MODE_ACCGYRO     | Reads accel and gyro data
 *  0x06     | OPERATION_MODE_MAGGYRO     | Reads accel and mag data
 *  0x07     | OPERATION_MODE_ANY_MOTION  | Reads accel mag and gyro data
 *  0x08     | OPERATION_MODE_IMUPLUS     | Inertial measurement unit
 *   -       |       -                    | Reads accel,gyro and fusion data
 *  0x09     | OPERATION_MODE_COMPASS     | Reads accel, mag data
 *   -       |       -                    | and fusion data
 *  0x0A     | OPERATION_MODE_M4G         | Reads accel, mag data
 *    -      |       -                    | and fusion data
 *  0x0B     | OPERATION_MODE_NDOF_FMC_OFF| Nine degrees of freedom with
 *   -       |       -                    | fast magnetic calibration
 *   -       |       -                    | Reads accel,mag, gyro
 *   -       |       -                    | and fusion data
 *  0x0C     | OPERATION_MODE_NDOF        | Nine degrees of freedom
 *   -       |       -                    | Reads accel,mag, gyro
 *   -       |       -                    | and fusion data
 *
 *	@return results of bus communication function
 *	@retval 0 -> Success
 *	@retval 1 -> Error
 *
 *	@note In the config mode, all sensor and fusion data
 *	becomes zero and it is mainly derived
 *	to configure the various settings of the BNO
 *
 */
BNO055_RETURN_FUNCTION_TYPE BNO055::bno055_get_operation_mode(u8 *v_operation_mode_u8)
{
	/* Variable used to return value of
	communication routine*/
	BNO055_RETURN_FUNCTION_TYPE com_rslt = ERROR;
	u8 v_data_u8r = BNO055_ZERO_U8X;
	s8 v_stat_s8 = ERROR;
	/* Check the struct p_bno055 is empty */
	if (p_bno055 == BNO055_ZERO_U8X) {
		return E_NULL_PTR;
	} else {
            /*condition check for page, operation mode is
            available in the page zero*/
            if (p_bno055->page_id != PAGE_ZERO)
                    /* Write the page zero*/
                    v_stat_s8 = BNO055::bno055_write_page_id(PAGE_ZERO);
            if ((v_stat_s8 == SUCCESS) || (p_bno055->page_id == PAGE_ZERO)) 
            {
                /* Read the value of operation mode*/
                com_rslt = BNO055::BNO055_bus_read(p_bno055->dev_addr,
                                                   BNO055_OPERATION_MODE__REG,
                                                   &v_data_u8r, 
                                                    BNO055_ONE_U8X);
                *v_operation_mode_u8 = 
                        BNO055_GET_BITSLICE(v_data_u8r, BNO055_OPERATION_MODE);
            } else {
                com_rslt = ERROR;
            }
	}
	return com_rslt;
}

/*!
 *	@brief
 *	This API gives data to the given register and
 *	the data is written in the corresponding register address
 *
 *  @param v_addr_u8 : Address of the register
 *	@param p_data_u8 : Data to be written to the register
 *	@param v_len_u8  : Length of the Data
 *
 *	@return results of bus communication function
 *	@retval 0 -> Success
 *	@retval 1 -> Error
 *
 *
*/
BNO055_RETURN_FUNCTION_TYPE BNO055::bno055_write_register(u8 v_addr_u8, u8 *p_data_u8, u8 v_len_u8)
{
    /* Variable used to return value of
    communication routine*/
    BNO055_RETURN_FUNCTION_TYPE com_rslt = ERROR;
    /* Check the struct p_bno055 is empty */
    if (p_bno055 == BNO055_ZERO_U8X) 
    {
        return E_NULL_PTR;
    } else {
        /* Write the values of respective given register */
        com_rslt = BNO055::BNO055_bus_write(p_bno055->dev_addr, 
                                            v_addr_u8, 
                                            p_data_u8, 
                                            v_len_u8);
    }
    return com_rslt;
}

/*!	@brief This API used to write the power mode
 *	from register from 0x3E bit 0 to 1
 *
 *	@param v_power_mode_u8 : The value of power mode
 *
 * v_power_mode_u8 |      result        | comments
 * ----------|---------------------|-------------------------------------
 *  0x00     | POWER_MODE_NORMAL   | In the NORMAL mode the register
 *    -      |       -             | map and the internal peripherals
 *    -      |       -             | of the MCU are always
 *    -      |       -             | operative in this mode
 *  0x01     | POWER_MODE_LOWPOWER | This is first level of power saving mode
 *  0x02     | POWER_MODE_SUSPEND  | In suspend mode the system is
 *   -       |      -              | paused and all the sensors and
 *   -       |      -              | the micro controller are
 *   -       |      -              | put into sleep mode.
 *
 *	@return results of bus communication function
 *	@retval 0 -> Success
 *	@retval 1 -> Error
 *
 *	@note For detailed about LOWPOWER mode
 *	refer data sheet 3.4.2
 *
 */
BNO055_RETURN_FUNCTION_TYPE BNO055::bno055_set_power_mode(u8 v_power_mode_u8)
{
    BNO055_RETURN_FUNCTION_TYPE com_rslt = ERROR;
    u8 v_data_u8r = BNO055_ZERO_U8X;
    u8 v_prev_opmode_u8 = OPERATION_MODE_CONFIG;
    s8 v_stat_s8 = ERROR;
    /* Check the struct p_bno055 is empty */
    if (p_bno055 == BNO055_ZERO_U8X) 
    {
	return E_NULL_PTR;
    } else {
        
        /* The write operation effective only if the operation
        mode is in config mode, this part of code is checking the
        current operation mode and set the config mode */
        v_stat_s8 = BNO055::bno055_get_operation_mode(&v_prev_opmode_u8);
        
        if (v_stat_s8 == SUCCESS) 
        {
            if (v_prev_opmode_u8 != OPERATION_MODE_CONFIG)
                v_stat_s8 += BNO055::bno055_set_operation_mode(OPERATION_MODE_CONFIG);
            if (v_stat_s8 == SUCCESS) 
            {
                /* Write the value of power mode */
                com_rslt = BNO055::BNO055_bus_read(p_bno055->dev_addr,
                                                   BNO055_POWER_MODE__REG,
                                                   &v_data_u8r, 
                                                   BNO055_ONE_U8X);
                if (com_rslt == SUCCESS) 
                {
                    v_data_u8r =
                    BNO055_SET_BITSLICE(v_data_u8r, BNO055_POWER_MODE, v_power_mode_u8);
                    com_rslt +=
                            BNO055::BNO055_bus_write(p_bno055->dev_addr, 
                                                     BNO055_POWER_MODE__REG,
                                                    &v_data_u8r, BNO055_ONE_U8X);
                }
            } else {
            com_rslt = ERROR;
            }
        } else {
        com_rslt = ERROR;
        }
    }
	if (v_prev_opmode_u8 != OPERATION_MODE_CONFIG)
		/* set the operation mode
		of previous operation mode*/
		com_rslt += BNO055::bno055_set_operation_mode
		(v_prev_opmode_u8);
	return com_rslt;
}

/*!
 *	@brief This API used to write
 *	the page id register 0x07
 *
 *	@param v_page_id_u8 : The value of page id
 *
 *	PAGE_ZERO -> 0x00
 *	PAGE_ONE  -> 0x01
 *
 *	@return results of bus communication function
 *	@retval 0 -> Success
 *	@retval 1 -> Error
 *
 *
 */
BNO055_RETURN_FUNCTION_TYPE BNO055::bno055_write_page_id(u8 v_page_id_u8)
{
	/* Variable used to return value of
	communication routine*/
	BNO055_RETURN_FUNCTION_TYPE com_rslt = ERROR;
	u8 v_data_u8r = BNO055_ZERO_U8X;
	/* Check the struct p_bno055 is empty */
	if (p_bno055 == BNO055_ZERO_U8X) {
                return E_NULL_PTR;
            } else {
                /* Read the current page*/
                com_rslt = BNO055::BNO055_bus_read(p_bno055->dev_addr,
                                                    BNO055_PAGE_ID__REG, 
                                                    &v_data_u8r, 
                                                    BNO055_ONE_U8X);
                /* Check condition for communication success*/
                if (com_rslt == SUCCESS) {
                    v_data_u8r = BNO055_SET_BITSLICE(v_data_u8r,
                                                    BNO055_PAGE_ID, 
                                                    v_page_id_u8);
                    /* Write the page id*/
                    com_rslt += BNO055::BNO055_bus_write(p_bno055->dev_addr,
                                                        BNO055_PAGE_ID__REG,
                                                        &v_data_u8r, 
                                                        BNO055_ONE_U8X);
                    if (com_rslt == SUCCESS)
                            p_bno055->page_id = v_page_id_u8;
                } else {
                    com_rslt = ERROR;
                }
            }
	return com_rslt;
}

/*!
 *	@brief This API reads Euler data hrp values
 *	from register 0x1A to 0x1F it is a six byte data
 *
 *
 *	@param euler : The Euler hrp data's
 *
 *	Parameter |    result
 *  --------- | -----------------
 *	 h        | The Euler h data
 *	 r        | The Euler r data
 *	 p        | The Euler p data
 *
 *
 *	@return results of bus communication function
 *	@retval 0 -> Success
 *	@retval 1 -> Error
 *
 */
BNO055_RETURN_FUNCTION_TYPE BNO055::bno055_read_euler_hrp(struct bno055_euler_t *euler)
{
	/* Variable used to return value of
	communication routine*/
	BNO055_RETURN_FUNCTION_TYPE com_rslt = ERROR;
	/* Array holding the Euler hrp value
	v_data_u8[INDEX_ZERO] - h->LSB
	v_data_u8[INDEX_ONE] - h->MSB
	v_data_u8[INDEX_TWO] - r->MSB
	v_data_u8[INDEX_THREE] - r->MSB
	v_data_u8[INDEX_FOUR] - p->MSB
	v_data_u8[INDEX_FIVE] - p->MSB
	*/
	u8 v_data_u8[ARRAY_SIZE_SIX] = {
	BNO055_ZERO_U8X, BNO055_ZERO_U8X,
	BNO055_ZERO_U8X, BNO055_ZERO_U8X,
	BNO055_ZERO_U8X, BNO055_ZERO_U8X};
	s8 v_stat_s8 = ERROR;
	/* Check the struct p_bno055 is empty */
	if (p_bno055 == BNO055_ZERO_U8X) {
		return E_NULL_PTR;
		} else {
		/*condition check for page, chip id is
		available in the page zero*/
		if (p_bno055->page_id != PAGE_ZERO)
			/* Write the page zero*/
			v_stat_s8 = BNO055::bno055_write_page_id(PAGE_ZERO);
		if ((v_stat_s8 == SUCCESS) ||
		(p_bno055->page_id == PAGE_ZERO)) {
			/* Read the six byte of Euler hrp data*/
			com_rslt = BNO055::BNO055_bus_read(p_bno055->dev_addr,BNO055_EULER_H_LSB_VALUEH__REG,v_data_u8, BNO055_SIX_U8X);
			/* Data h*/
			v_data_u8[INDEX_ZERO] =	BNO055_GET_BITSLICE(v_data_u8[INDEX_ZERO], BNO055_EULER_H_LSB_VALUEH);
			v_data_u8[INDEX_ONE] = BNO055_GET_BITSLICE(v_data_u8[INDEX_ONE], BNO055_EULER_H_MSB_VALUEH);
			euler->h = (s16)((v_data_u8[INDEX_ONE] << BNO055_SHIFT_8_POSITION) | (v_data_u8[INDEX_ZERO]));
			/* Data r*/
			v_data_u8[INDEX_TWO] = BNO055_GET_BITSLICE(v_data_u8[INDEX_TWO],BNO055_EULER_R_LSB_VALUER);
			v_data_u8[INDEX_THREE] = BNO055_GET_BITSLICE(v_data_u8[INDEX_THREE],BNO055_EULER_R_MSB_VALUER);
			euler->r = (s16)((((s32)((s8)v_data_u8[INDEX_THREE])) << BNO055_SHIFT_8_POSITION) | (v_data_u8[INDEX_TWO]));
			/* Data p*/
			v_data_u8[INDEX_FOUR] = BNO055_GET_BITSLICE(v_data_u8[INDEX_FOUR], BNO055_EULER_P_LSB_VALUEP);
			v_data_u8[INDEX_FIVE] = BNO055_GET_BITSLICE(v_data_u8[INDEX_FIVE], BNO055_EULER_P_MSB_VALUEP);
			euler->p = (s16)((((s32) ((s8)v_data_u8[INDEX_FIVE])) << BNO055_SHIFT_8_POSITION) | (v_data_u8[INDEX_FOUR]));
		} else {
		com_rslt = ERROR;
		}
	}
	return com_rslt;
}

/*!
 *	@brief This API is used to convert the Euler hpr raw data
 *	to degree output as double
 *
 *	@param euler_hpr : The degree data of Euler hpr
 *
 *	Parameter |    result
 *  --------- | -----------------
 *	 h        | degree data of Euler
 *	 r        | degree data of Euler
 *	 p        | degree data of Euler
 *
 *
 *	@return results of bus communication function
 *	@retval 0 -> Success
 *	@retval 1 -> Error
 *
 */

BNO055_RETURN_FUNCTION_TYPE BNO055::bno055_convert_double_euler_hpr_deg(struct bno055_euler_double_t *euler_hpr)
{
	/* Variable used to return value of
	communication routine*/
	BNO055_RETURN_FUNCTION_TYPE com_rslt = ERROR;
	struct bno055_euler_t reg_euler = {BNO055_ZERO_U8X,
	BNO055_ZERO_U8X, BNO055_ZERO_U8X};
	u8 v_euler_unit_u8 = BNO055_ZERO_U8X;
	/* Read the current Euler unit and set the
	unit as degree if the unit is in radians */
        
	com_rslt = this->bno055_get_euler_unit(&v_euler_unit_u8);
        
	if (v_euler_unit_u8 != EULER_UNIT_DEG)
		com_rslt += this->bno055_set_euler_unit(EULER_UNIT_DEG);
        
	if (com_rslt == SUCCESS) {
		/* Read Euler raw h data*/
		com_rslt += this->bno055_read_euler_hrp(&reg_euler);
		
                if (com_rslt == SUCCESS) {
			/* Convert raw Euler hrp to degree*/
			euler_hpr->h =
			(double)(reg_euler.h/EULER_DIV_DEG);
			euler_hpr->p =
			(double)(reg_euler.p/EULER_DIV_DEG);
			euler_hpr->r =
			(double)(reg_euler.r/EULER_DIV_DEG);
		} else {
		com_rslt = ERROR;
		}
	} else {
	com_rslt = ERROR;
	}
	return com_rslt;
}
/*!
 *	@brief This API used to read the Euler unit
 *	from register from 0x3B bit 2
 *
 *	@param v_euler_unit_u8 : The value of accel unit
 *
 *    v_euler_unit_u8 | result
 *   --------------   | -----------
 *      0x00          | EULER_UNIT_DEG
 *      0x01          | EULER_UNIT_RAD
 *
 *	@return results of bus communication function
 *	@retval 0 -> Success
 *	@retval 1 -> Error
 *
 *
 */
BNO055_RETURN_FUNCTION_TYPE BNO055::bno055_get_euler_unit(u8 *v_euler_unit_u8)
{
	/* Variable used to return value of
	communication routine*/
	BNO055_RETURN_FUNCTION_TYPE com_rslt = ERROR;
	u8 v_data_u8r = BNO055_ZERO_U8X;
	s8 v_stat_s8 = ERROR;
	/* Check the struct p_bno055 is empty */
	if (p_bno055 == BNO055_ZERO_U8X) {
		return E_NULL_PTR;
		} else {
		/*condition check for page, Euler unit is
		available in the page zero*/
		if (p_bno055->page_id != PAGE_ZERO)
			/* Write the page zero*/
			v_stat_s8 = BNO055::bno055_write_page_id(PAGE_ZERO);
		if ((v_stat_s8 == SUCCESS) ||
		(p_bno055->page_id == PAGE_ZERO)) {
			/* Read the Euler unit */
			com_rslt = BNO055::BNO055_bus_read
			(p_bno055->dev_addr,
			BNO055_EULER_UNIT__REG,
			&v_data_u8r, BNO055_ONE_U8X);
			*v_euler_unit_u8 =
			BNO055_GET_BITSLICE(v_data_u8r,
			BNO055_EULER_UNIT);
		} else {
		com_rslt = ERROR;
		}
	}
	return com_rslt;
}
/*!
 *	@brief This API used to write the Euler unit
 *	from register from 0x3B bit 2
 *
 *	@param v_euler_unit_u8 : The value of Euler unit
 *
 *    v_euler_unit_u8 | result
 *   --------------   | -----------
 *      0x00          | EULER_UNIT_DEG
 *      0x01          | EULER_UNIT_RAD
 *
 *	@return results of bus communication function
 *	@retval 0 -> Success
 *	@retval 1 -> Error
 *
 *
 */
BNO055_RETURN_FUNCTION_TYPE BNO055::bno055_set_euler_unit(u8 v_euler_unit_u8)
{
BNO055_RETURN_FUNCTION_TYPE com_rslt = ERROR;
u8 v_data_u8r = BNO055_ZERO_U8X;
u8 v_prev_opmode_u8 = OPERATION_MODE_CONFIG;
s8 v_stat_s8 = ERROR;
/* Check the struct p_bno055 is empty */
if (p_bno055 == BNO055_ZERO_U8X) {
	return E_NULL_PTR;
	} else {
		/* The write operation effective only if the operation
		mode is in config mode, this part of code is checking the
		current operation mode and set the config mode */
		v_stat_s8 = bno055_get_operation_mode(&v_prev_opmode_u8);
		if (v_stat_s8 == SUCCESS) {
			if (v_prev_opmode_u8 != OPERATION_MODE_CONFIG)
				v_stat_s8 += bno055_set_operation_mode
				(OPERATION_MODE_CONFIG);
			if (v_stat_s8 == SUCCESS) {
				/* Write the Euler unit*/
				com_rslt = BNO055::BNO055_bus_read
				(p_bno055->dev_addr,
				BNO055_EULER_UNIT__REG,
				&v_data_u8r, BNO055_ONE_U8X);
				if (com_rslt == SUCCESS) {
					v_data_u8r =
					BNO055_SET_BITSLICE(v_data_u8r,
					BNO055_EULER_UNIT, v_euler_unit_u8);
					com_rslt +=
                                        BNO055::BNO055_bus_write
					(p_bno055->dev_addr,
					BNO055_EULER_UNIT__REG,
					&v_data_u8r, BNO055_ONE_U8X);
				}
			} else {
			com_rslt = ERROR;
			}
		} else {
		com_rslt = ERROR;
		}
	}
	if (v_prev_opmode_u8 != OPERATION_MODE_CONFIG)
		/* set the operation mode
		of previous operation mode*/
		com_rslt += bno055_set_operation_mode
		(v_prev_opmode_u8);
	return com_rslt;
}
