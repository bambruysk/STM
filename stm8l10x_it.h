/**
  ******************************************************************************
  * @file     Project/STM8L10x_StdPeriph_Templates/stm8l10x_it.h
  * @author   MCD Application Team
  * @version  V1.2.1
  * @date     30-September-2014
  * @brief    This file contains the external declarations of the interrupt routines.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; COPYRIGHT 2014 STMicroelectronics</center></h2>
  *
  * Licensed under MCD-ST Liberty SW License Agreement V2, (the "License");
  * You may not use this file except in compliance with the License.
  * You may obtain a copy of the License at:
  *
  *        http://www.st.com/software_license_agreement_liberty_v2
  *
  * Unless required by applicable law or agreed to in writing, software 
  * distributed under the License is distributed on an "AS IS" BASIS, 
  * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
  * See the License for the specific language governing permissions and
  * limitations under the License.
  *
  ******************************************************************************
  */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __STM8L10x_IT_H
#define __STM8L10x_IT_H

/* Includes ------------------------------------------------------------------*/
#include "stm8l10x.h"

/* Exported types ------------------------------------------------------------*/
/* Exported constants --------------------------------------------------------*/
/* Exported macro ------------------------------------------------------------*/
/* Exported functions ------------------------------------------------------- */
#ifdef _COSMIC_
 void _stext(void); /* RESET startup routine */
 INTERRUPT void NonHandledInterrupt(void);
#endif /* _COSMIC_ */

#ifndef _RAISONANCE_
 INTERRUPT void NonHandledInterrupt(void);
 INTERRUPT void TRAP_IRQHandler(void); /* TRAP */
 INTERRUPT void FLASH_IRQHandler(void); /* FLASH EOP/PG_DIS */
 INTERRUPT void AWU_IRQHandler(void); /* AWU */
 INTERRUPT void EXTIB_IRQHandler(void); /* EXTI PORTB */
 INTERRUPT void EXTID_IRQHandler(void); /* EXTI PORTD */
 INTERRUPT void EXTI0_IRQHandler(void); /* EXTI PIN0 */
 INTERRUPT void EXTI1_IRQHandler(void); /* EXTI PIN1 */
 INTERRUPT void EXTI2_IRQHandler(void); /* EXTI PIN2 */
 INTERRUPT void EXTI3_IRQHandler(void); /* EXTI PIN3 */
 INTERRUPT void EXTI4_IRQHandler(void); /* EXTI PIN4 */
 INTERRUPT void EXTI5_IRQHandler(void); /* EXTI PIN5 */
 INTERRUPT void EXTI6_IRQHandler(void); /* EXTI PIN6 */
 INTERRUPT void EXTI7_IRQHandler(void); /* EXTI PIN7 */
 INTERRUPT void COMP_IRQHandler(void); /* COMP */
 INTERRUPT void TIM2_UPD_OVF_TRG_BRK_IRQHandler(void); /* TIM2 UPD/OVF/TRG/BRK */
 INTERRUPT void TIM2_CAP_IRQHandler(void); /* TIM2 CAP*/
 INTERRUPT void TIM3_UPD_OVF_TRG_BRK_IRQHandler(void); /* TIM3 UPD/OVF/TRG/BRK */
 INTERRUPT void TIM3_CAP_IRQHandler(void); /* TIM3 CAP*/
 INTERRUPT void TIM4_UPD_OVF_IRQHandler(void); /* TIM4 UPD/OVF */
 INTERRUPT void SPI_IRQHandler(void); /* SPI */
 INTERRUPT void USART_TX_IRQHandler(void); /* USART TX */
 INTERRUPT void USART_RX_IRQHandler(void); /* USART RX */
 INTERRUPT void I2C_IRQHandler(void); /* I2C */
#endif /* _COSMIC_ */

#endif /* __STM8L10x_IT_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/

