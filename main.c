/**
  ******************************************************************************
  * @file     Project/STM8L10x_StdPeriph_Templates/main.c
  * @author   MCD Application Team
  * @version V1.2.1
  * @date    30-September-2014
  * @brief    This file contains the firmware main function.
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

/* Includes ------------------------------------------------------------------*/
#include "stm8l10x.h"
#include "stm8l10x_spi.h"
#include "stm8l10x_awu.h"
#include "Si4432.h"

/** @addtogroup STM8L10x_StdPeriph_Templates
  * @{
  */

/* Private typedef -----------------------------------------------------------*/
//SEND_MESSAGE
    typedef  struct 
    {
       uint16_t ID_sender;
       uint16_t ID_receiver;
       uint8_t  data_length;
       uint8_t [32] data;  
        
    }Si4432_message_t;
//CONFIGURATION
    typedef struct 
    {
        uint16_t    DEV_ID;
        uint8_t    NUM_REPEATS;
        uint16_t    ANS_TIMEOUT;
        uint16_t    SEND_PERIOD;
        uint8_t     PREAMBLE_SIZE;
        uint8_t     SYNC_HEADER_SIZE;
        uint8_t     SYNC_WORD;
        uint8_t     CHANNEL;


    } Configuration_t;


/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/

//SPI_settings
SPI_FirstBit_Typedef            SPI_FirstBit            = SPI_FirstBit_MSB;
SPI_BaudRatePrescaler_TypeDef   SPI_BaudRatePrescaler   = SPI_BaudRatePrescaler_4;
SPI_Mode_TypeDef                SPI_Mode                = SPI_Mode_Master;
SPI_CPOL_TypeDef                SPI_CPOL                = SPI_CPOL_Low ;
SPI_CPHA_TypeDef                SPI_CPHA                = SPI_CPHA_1Edge;
SPI_DirectionMode_TypeDef       SPI_DirectionMode       = SPI_Direction_2Lines_FullDuplex;
SPI_NSS_TypeDef                 SPI_NSS                 = SPI_NSS_Soft ;    

//AWU_settings
AWU_Timebase_Typedef            AWU_Timebase            = AWU_Timebase_30s;


//EEPROM Congiguration
Configuration_t Configuration;
Configuration_t DefaultConfig = {

}


uint8_t [64] RxBuffer;
uint8_t *RxBuffer_p = &RxBuffer;

uint8_t *TxBuffer;

Si4432_message_t RxMessage,TxMessage;

/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/


void ReadConfigFromEEEPROM(Configuration_t *Configuration)
{
    uint16_t EEPROM_addr = 0x9800;
    uint8_t     databyte = 0;
    uint8_t     databyte_1  = 0;
    uint8_t     databyte_2 = 0;
    uint8_t     databyte_3 = 0;

    databyte = FLASH_ReadByte(EEPROM_addr);
    if (databyte == 0){
        LoadDefaultConfiguration (&Configuration);
        return;
    };

    databyte = FLASH_ReadByte(EEPROM_addr++);
    databyte_1 = FLASH_ReadByte(EEPROM_addr++);
    Configuration->DEV_ID = ((uint16_t) databyte_1<<8)|((uint16_t) databyte);

    databyte = FLASH_ReadByte(EEPROM_addr++);
    Configuration->NUM_REPEATS = databyte;

    databyte = FLASH_ReadByte(EEPROM_addr++);
    databyte_1 = FLASH_ReadByte(EEPROM_addr++);
    Configuration->ANS_TIMEOUT = ((uint16_t) databyte_1<<8)|((uint16_t) databyte);

    databyte = FLASH_ReadByte(EEPROM_addr++);
    databyte_1 = FLASH_ReadByte(EEPROM_addr++);
    Configuration->SEND_PERIOD = ((uint16_t) databyte_1<<8)|((uint16_t) databyte);

    databyte = FLASH_ReadByte(EEPROM_addr++);
    Configuration->PREAMBLE_SIZE = databyte;

    databyte = FLASH_ReadByte(EEPROM_addr++);
    Configuration->SYNC_HEADER_SIZE = databyte;
    
    databyte = FLASH_ReadByte(EEPROM_addr++);
    databyte_1 = FLASH_ReadByte(EEPROM_addr++);
    databyte_2 = FLASH_ReadByte(EEPROM_addr++);
    databyte_3 = FLASH_ReadByte(EEPROM_addr++);
    Configuration->SYNC_WORD =   ((uint32_t) databyte_3<<24)
                                |((uint32_t) databyte_2<<16)
                                |((uint32_t) databyte_1<<8)
                                |((uint32_t) databyte);


    databyte = FLASH_ReadByte(EEPROM_addr++);
    Configuration->CHANNEL = databyte;

}


void LoadDefaultConfiguration(Configuration_t * Configuration){
    Configuration->DEV_ID = 0xFFFF;
    Configuration->NUM_REPEATS = 0x03;
    Configuration->ANS_TIMEOUT = 100;
    Configuration->SEND_PERIOD = 50;
    Configuration->PREAMBLE_SIZE = 8;
    Configuration->SYNC_HEADER_SIZE = 0x44;
    Configuration->SYNC_WORD = 0x1F35; //13-bit Barker
    Configuration->CHANNEL = 0x01;

}

void WriteConfigurationToEEPROM(uint8_t * data){
    uint32_t EEPROM_addr = 0x9800;

    FLASH_Unlock(FLASH_MemType_Data);
    for (uint8_t i = 0; i < 64; ++i)
    {
        FLASH_ProgramByte(EEPROM_addr+i,*(data++));
    }

}



void main(void)
{
    uint8_t TxMsgCounter = 0;
    ReadConfigFromEEEPROM(Configuration);

    SPI_Init( SPI_FirstBit,
              SPI_BaudRatePrescaler,
              SPI_Mode, 
              SPI_CPOL,
              SPI_CPHA,
              SPI_DirectionMode,
              SPI_NSS);
  
    Si4432_Init();
    


    AWU_Init(AWU_Timebase);
    AWU_Cmd(ENABLE);



  
    /* Infinite loop */
    while (1)
    {
        if (awu_flag) 
        {

            //Prepare Message
            TxMessage.ID_sender = Configuration.DEV_ID;
            TxMessage.ID_receiver = 0;
            TxMessage.data_length = 1;
            TxMessage.data[0] = Si4432_GetVbat();
            

            Si4432_SetMode(Si4432_ReceiveMode);
            while(RF_is_freeair())
            {
                TxMsgCounter = Configuration.NUM_REPEATS;

                while (TxMsgCounter != 0 ){
                    Si4432_SetMode(Si4432_TransmitMode);
                    Si4432_SendMsg(TxMessage);
                    Si4432_SetMode(Si4432_ReceiveMode);
                    delay_ms(Configuration.ANS_TIMEOUT);
                    if (MessageReceived){
                        RF_ParseMsg();
                        if (RxMessage.ID_receiver == Configuration.DEV_ID){
                            if (RxMessage.data[0] == 0)
                            {
                                break;
                            }
                            else if (RxMessage.data[0] == 1)
                            {
                                continue;
                            }
                            else if (RxMessage.data[0] == 2)
                            {
                                WriteConfigurationToEEPROM(RxMessage.data);
                                ReadConfigFromEEEPROM(&Configuration);
                                break;
                            }
                        }
                            
                    } 
                    delay_ms(Configuration.ANS_TIMEOUT);
                    TxMsgCounter--;
                }

                Si4432_Standby();

            }    


        } 

    }

}

#ifdef  USE_FULL_ASSERT

/**
  * @brief  Reports the name of the source file and the source line number
  *   where the assert_param error has occurred.
  * @param file: pointer to the source file name
  * @param line: assert_param error line source number
  * @retval : None
  */
void assert_failed(uint8_t* file, uint32_t line)
{
    /* User can add his own implementation to report the file name and line number,
       ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */

    /* Infinite loop */
    while (1)
    {
    }
}
#endif

/**
  * @}
  */
  
/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/