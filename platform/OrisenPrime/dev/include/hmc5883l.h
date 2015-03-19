/*
 * hmc5883l.h
 *
 *  Created on: 6 Dec 2011
 *      Author: jkwon and mcphillips
 *
 *  Updated on: 01 Sept 2012 by Jagun Kwon (j.kwon@cs.ucl.ac.uk)
 *  Refactored to comply with Contiki sensor interface structure
 *  hmc5883l: 3-Axis Digital Compass
 */

#ifndef _HMC5883L_H_
#define _HMC5883L_H_

//#include <stdbool.h>

// Added by Jagun Kwon (j.kwon@cs.ucl.ac.uk)
extern const struct sensors_sensor hmc5883l_sensor;
// Sensor value types to be returned from value function
#define HMC5883L_LATCH_DATA	0	// This must be invoked first
#define HMC5883L_MAG_X_RAW	1
#define HMC5883L_MAG_Y_RAW	2
#define HMC5883L_MAG_Z_RAW	3

#define RAW_HMC5883L_DATA 0

#define HMC5883L_I2C_ADDR           ((0x3C)>>1)

#define HMC5883L_RA_CONFIG_A        0x00
#define HMC5883L_RA_CONFIG_B        0x01
#define HMC5883L_RA_MODE            0x02
#define HMC5883L_RA_DATAX_H         0x03
#define HMC5883L_RA_DATAX_L         0x04
#define HMC5883L_RA_DATAY_H         0x05
#define HMC5883L_RA_DATAY_L         0x06
#define HMC5883L_RA_DATAZ_H         0x07
#define HMC5883L_RA_DATAZ_L         0x08
#define HMC5883L_RA_STATUS          0x09
#define HMC5883L_RA_ID_A            0x0A
#define HMC5883L_RA_ID_B            0x0B
#define HMC5883L_RA_ID_C            0x0C

#define HMC5883L_AVERAGING_1        ((0x00)<<5)
#define HMC5883L_AVERAGING_2        ((0x01)<<5)
#define HMC5883L_AVERAGING_4        ((0x02)<<5)
#define HMC5883L_AVERAGING_8        ((0x03)<<5)

#define HMC5883L_RATE_0P75          ((0x00)<<2)
#define HMC5883L_RATE_1P5           ((0x01)<<2)
#define HMC5883L_RATE_3             ((0x02)<<2)
#define HMC5883L_RATE_7P5           ((0x03)<<2)
#define HMC5883L_RATE_15            ((0x04)<<2)
#define HMC5883L_RATE_30            ((0x05)<<2)
#define HMC5883L_RATE_75            ((0x06)<<2)

#define HMC5883L_BIAS_NORMAL        0x00
#define HMC5883L_BIAS_POSITIVE      0x01
#define HMC5883L_BIAS_NEGATIVE      0x02

#define HMC5883L_GAIN_1370          ((0x00)<<5)
#define HMC5883L_GAIN_1090          ((0x01)<<5)
#define HMC5883L_GAIN_820           ((0x02)<<5)
#define HMC5883L_GAIN_660           ((0x03)<<5)
#define HMC5883L_GAIN_440           ((0x04)<<5)
#define HMC5883L_GAIN_390           ((0x05)<<5)
#define HMC5883L_GAIN_330           ((0x06)<<5)
#define HMC5883L_GAIN_220           ((0x07)<<5)

#define HMC5883L_MODEREG_BIT        1
#define HMC5883L_MODEREG_LENGTH     2

#define HMC5883L_MODE_CONTINUOUS    0x00
#define HMC5883L_MODE_SINGLE        0x01
#define HMC5883L_MODE_IDLE          0x02

#define HMC5883L_STATUS_LOCK_BIT    1
#define HMC5883L_STATUS_READY_BIT   0

struct hmc5883l_data {
	int16_t mag_x ;
	int16_t mag_y ;
	int16_t mag_z ;
} ;

// typedef struct hmc5883l_data hmc5883l_d

void hmc5883l_init(void);
void hmc5883l_start(void);
void hmc5883l_stop(void);
void hmc5883l_get_data(uint8_t *buffer);
void hmc5883l_decode(struct hmc5883l_data *const mag_data , uint8_t *buffer);

#endif /* HMC5883L_H_ */
