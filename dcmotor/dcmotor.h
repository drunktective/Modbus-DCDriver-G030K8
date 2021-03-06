/*
 * dcmotor.h
 *
 *  Created on: Mar 16, 2022
 *      Author: User
 */

#ifndef DCMOTOR_H_
#define DCMOTOR_H_

#define HAL_TIM_MODULE_ENABLED

#include "stm32g0xx_hal.h"

// DC Motor Rotation Directions
#define DIR_CW    0
#define DIR_CCW   1

// DC Motor PWM Properties
// #define DC_MOTOR_PWM_RES  10
// #define DC_MOTOR_F_PWM    500

// The Number OF DC MOTORs To Be Used In The Project
#define DC_MOTOR_UNITS  1

typedef struct
{
	TIM_HandleTypeDef* TIM_Instance;
	uint32_t EN1_TIM_CH;
	uint32_t EN2_TIM_CH;
	TIM_HandleTypeDef* OC_Instance;
	uint32_t OC_TIM_CH;
	DMA_HandleTypeDef* DMA_Instance;
	uint32_t DMA_CC;
	uint32_t CC1_DEST;
	uint32_t CC2_DEST;
}DC_MOTOR_CfgType;

/*-----[ Prototypes For All Functions ]-----*/
void dcmotor_Init(uint8_t au8_MOTOR_Instance);
void dcmotor_Start(uint8_t au8_MOTOR_Instance);
void dcmotor_setDirection(uint8_t au8_MOTOR_Instance, uint8_t au8_DIR, uint32_t pwm_data);
void dcmotor_Stop(uint8_t au8_MOTOR_Instance);

#endif /* DCMOTOR_H_ */
