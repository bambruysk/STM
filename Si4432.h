/*!
 * \author no1wudi
 * \file Si4432.h
 */

#ifndef __Si4432_H_
#define __Si4432_H_

#include "Si4432_HW.h"

/*!
 * \addtogroup Si4432
 * @{
 */

/*!
 * \addtogroup Register
 * \brief Detailed register descriptions based on application note 440(AN440).
 * @{
 */


#define Si4432_Reg_Device_Type_Code 0x00



#define Si4432_Reg_Verson_Code 0x01



#define Si4432_Reg_Device_Status 0x02



#define Si4432_Reg_Interrupt_Status_1 0x03



#define Si4432_Reg_Interrupt_Status_2 0x04



#define Si4432_Reg_Interrupt_Enable_1 0x05



#define Si4432_Reg_Interrupt_Enable_2 0x06



#define Si4432_Reg_Operating_Mode_1 0x07



#define Si4432_Reg_Operating_Mode_2 0x08



#define Si4432_Reg_Crystal_Load_Capacitance 0x09



#define Si4432_Reg_MCU_Output_Clock 0x0A



#define Si4432_Reg_GPIO_Config_0 0x0B



#define Si4432_Reg_GPIO_Config_1 0x0C



#define Si4432_Reg_GPIO_Config_2 0x0D


#define Si4432_Reg_IO_Port_Config 0x0E


#define Si4432_Reg_ADC_Config 0x0F



#define Si4432_Reg_ADC_Amplifier_Offset 0x10



#define Si4432_Reg_ADC_Value 0x11



#define Si4432_Reg_Temperature_Sensor_Calibration 0x12



#define Si4432_Reg_Temperature_Value_Offset 0x13


#define Si4432_Reg_Wakeup_Timer_Period_1 0x14


#define Si4432_Reg_Wakeup_Timer_Period_2 0x15


#define Si4432_Reg_Wakeup_Timer_Period_3 0x16


#define Si4432_Reg_Wakeup_Timer_Value_1 0x17


#define Si4432_Reg_Wakeup_Timer_Value_2 0x18


#define Si4432_Reg_Low_Duty_Cycle_Mode_Duration 0x19


#define Si4432_Reg_Low_Batter_Detector_Threshold 0x1A


#define Si4432_Reg_Battery_Voltage_Level 0x1B


#define Si4432_Reg_IF_FIlter_Bandwidth 0x1C


#define Si4432_Reg_AFC_Loop_Gearshift_Override 0x1D


#define Si4432_Reg_AFC_Timing_Ctrl 0x1E


#define Si4432_Reg_Clock_Recovery_Gearshift_Override 0x1F


#define Si4432_Reg_Clock_Recovery_Oversamping_Rate 0x20


#define Si4432_Reg_Clock_Recovery_Offset_2 0x21


#define Si4432_Reg_Clock_Recovery_Offset_1 0x22


#define Si4432_Reg_Clock_Recovery_Offset_0 0x23


#define Si4432_Reg_Clock_Recovery_Timing_Loop_Gain_1 0x24


#define Si4432_Reg_Clock_Recovery_Timing_Loop_Gain_0 0x25


#define Si4432_Reg_Received_Signal_Strength_Indicator 0x26


#define Si4432_Reg_RSSI_Threshold_For_Clear_Channel_Indicator 0x27


#define Si4432_Reg_Antenna_Diversity_1 0x28


#define Si4432_Reg_Antenna_Diversity_2 0x29


#define Si4432_Reg_AFC_Limiter 0x2A


#define Si4432_Reg_ADC_Correction 0x2B


#define Si4432_Reg_OOK_Counter_Value_1 0x2C


#define Si4432_Reg_OOK_Counter_Value_2 0x2D


#define Si4432_Reg_Slicer_Peak_Holder 0x2E


#define Si4432_Reg_Data_Access_Ctrl 0x30


#define Si4432_Reg_EZMAC_Status 0x31


#define Si4432_Reg_Header_Ctrl_1 0x32


#define Si4432_Reg_Header_Ctrl_2 0x33


#define Si4432_Reg_Preamble_Lenth 0x34


#define Si4432_Reg_Preamble_Detection_Ctrl 0x35


#define Si4432_Reg_Synchronization_Word_3 0x36


#define Si4432_Reg_Synchronization_Word_2 0x37


#define Si4432_Reg_Synchronization_Word_1 0x38


#define Si4432_Reg_Synchronization_Word_0 0x39


#define Si4432_Reg_Transmit_Header_3 0x3A


#define Si4432_Reg_Transmit_Header_2 0x3B


#define Si4432_Reg_Transmit_Header_1 0x3C


#define Si4432_Reg_Transmit_Header_0 0x3D


#define Si4432_Reg_Packet_Length 0x3E


#define Si4432_Reg_Check_Header_3 0x3F


#define Si4432_Reg_Check_Header_2 0x40


#define Si4432_Reg_Check_Header_1 0x41


#define Si4432_Reg_Check_Header_0 0x42


#define Si4432_Reg_Header_Enable_3 0x43


#define Si4432_Reg_Header_Enable_2 0x44


#define Si4432_Reg_Header_Enable_1 0x45


#define Si4432_Reg_Header_Enable_0 0x46


#define Si4432_Reg_Received_Header_3 0x47


#define Si4432_Reg_Received_Header_2 0x48


#define Si4432_Reg_Received_Header_1 0x49


#define Si4432_Reg_Received_Header_0 0x4A


#define Si4432_Reg_Receive_Packet_Length 0x4B


#define Si4432_Reg_ADC8_Ctrl 0x4F


#define Si4432_Reg_Channel_Filter_Coefficient_Offset 0x60


#define Si4432_Reg_Crystal_And_Power_On_Reset_Ctrl 0x62


#define Si4432_Reg_AGC_Override_1 0x69


#define Si4432_Reg_TX_Power 0x6D


#define Si4432_Reg_Tx_Data_Rate_1 0x6E


#define Si4432_Reg_Tx_Data_Rate_0 0x6F


#define Si4432_Reg_Modulation_Mode_Ctrl_1 0x70


#define Si4432_Reg_Modulation_Mode_Ctrl_2 0x71


#define Si4432_Reg_Frequency_Deviation 0x72


#define Si4432_Reg_Frequency_Offset_1 0x73


#define Si4432_Reg_Frequency_Offset_2 0x74


#define Si4432_Reg_Frequency_Band_Select 0x75


#define Si4432_Reg_Nominal_Carrier_Frequency_H 0x76


#define Si4432_Reg_Nominal_Carrier_Frequency_L 0x77


#define Si4432_Reg_Frequency_Hopping_Channel_Select 0x79


#define Si4432_Reg_Frequency_Hopping_Step_Size 0x7A


#define Si4432_Reg_Tx_FIFO_Ctrl_1 0x7C


#define Si4432_Reg_Tx_FIFO_Ctrl_2 0x7D


#define Si4432_Reg_Rx_FIFO_Ctrl 0x7E


#define Si4432_Reg_FIFO_Access 0x7F
/*!
 * @}
 */

/*!
 * \addtogroup Command
 * @{
 */

#define Si4432_IT1_FIFO_Over_And_Under_Flow 0x80

#define Si4432_IT1_Tx_FIFO_Almost_Full 0x40

#define Si4432_IT1_Tx_FIFO_Almost_Empty 0x20

#define Si4432_IT1_Rx_FIFO_Almost_Full 0x10

#define Si4432_IT1_External_Interrupt 0x08

#define Si4432_IT1_Packet_Sent 0x04

#define Si4432_IT1_Valid_Packed_Recived 0x02

#define Si4432_IT1_CRC_Error 0x01

#define Si4432_IT1_Disable 0x00

#define Si4432_IT2_Sync_Word_Detected 0x80

#define Si4432_IT2_Valid_Preamble_Detected 0x40

#define Si4432_IT2_Invalid_Preamble_Detected 0x20

#define Si4432_IT2_RSSI 0x10

#define Si4432_IT2_Wakeup_Timer 0x08

#define Si4432_IT2_Low_Battery_Detected 0x04

#define Si4432_IT2_Chip_Ready 0x02

#define Si4432_IT2_POR 0x01

#define Si4432_IT2_Disable 0x00

#define Si4432_Mode1_Soft_Reset 0x80

#define Si4432_Mode1_Low_Battery_Detect 0x40

#define Si4432_Mode1_Wakeup_Timer 0x20

#define Si4432_Mode1_Crystal_32K 0x00

#define Si4432_Mode1_Crystal_RC 0x10

#define Si4432_Mode1_Tx_On 0x08

#define Si4432_Mode1_Rx_On 0x04

#define Si4432_Mode1_Tune 0x02

#define Si4432_Mode1_Ready 0x01

#define Si4432_Mode2_Rx_Multi_Packet 0x10

#define Si4432_Mode2_Auto_Transmission 0x08

#define Si4432_Mode2_Low_Duty_Cycle 0x04

#define Si4432_Mode2_Rx_FIFO_Reset 0x02

#define Si4432_Mode2_Tx_FIFO_Reset 0x01

#define Si4432_MCU_0_Cycles 0x00

#define Si4432_MCU_128_Cycles 0x10

#define Si4432_MCU_256_Cycles 0x20

#define Si4432_MCU_512_Cycles 0x30

#define Si4432_MCU_Enable_Low_Frequency_Clock 0x80

#define Si4432_MCU_Clock_30Mhz 0x00

#define Si4432_MCU_Clock_15Mhz 0x01

#define Si4432_MCU_Clock_10Mhz 0x02

#define Si4432_MCU_Clock_4Mhz 0x03

#define Si4432_MCU_Clock_3Mhz 0x04

#define Si4432_MCU_Clock_2Mhz 0x05

#define Si4432_MCU_Clock_1Mhz 0x06

#define Si4432_MCU_Clock_32khz 0x07

#define Si4432_MCU_Clear 0x00

#define Si4432_GPIO_Pullup 0x20

#define Si4432_GPIO_Power_On_Reset 0x00

#define Si4432_GPIO_Wakeup_Timer 0x01

#define Si4432_GPIO_Low_Battery_Detect 0x02

#define Si4432_GPIO_Digital_Input 0x03

#define Si4432_GPIO_EXIT_Falling 0x04

#define Si4432_GPIO_EXIR_Rising 0x05

#define Si4432_GPIO_EXIT_Chang 0x06

#define Si4432_GPIO_Analog_Input 0x07

#define Si4432_GPIO_R_Analog_Test_N_In 0x08

#define Si4432_GPIO_R_Analog_Test_P_In 0x09

#define Si4432_GPIO_Digital_Output 0x0A

#define Si4432_GPIO_R_Digital_Test 0x0B

#define Si4432_GPIO_R_Analog_Test_N_Out 0x0C

#define Si4432_GPIO_R_Analog_Test_P_Out 0x0D

#define Si4432_GPIO_Reference_Voltage 0x0E

#define Si4432_GPIO_Tx_Rx_Clock_Output 0x0F

#define Si4432_GPIO_Tx_Data_Input 0x10

#define Si4432_GPIO_External_Retransmission 0x11

#define Si4432_GPIO_Tx_State 0x12

#define Si4432_GPIO_Tx_FIFO_Almost_Full 0x13

#define Si4432_GPIO_Rx_Data_Out 0x14

#define Si4432_GPIO_Rx_State 0x15

#define Si4432_GPIO_Rx_FIFO_Almost_Full 0x16

#define Si4432_GPIO_Antenna1 0x17

#define Si4432_GPIO_Antenna2 0x18

#define Si4432_GPIO_Valid_Preamble_Detected 0x19

#define Si4432_GPIO_Invalid_Preamble_Detected 0x1A

#define Si4432_GPIO_Sync_Word_Detected 0x1B

#define Si4432_GPIO_Clear_Channel_Assessment 0x1C

#define Si4432_GPIO_VDD 0x1D

#define Si4432_GPIO_GND 0x1E

#define Si4432_GPIO_Clear 0x00



/*!
 * @}
 */


void Si4432_Interrupt1_Set(unsigned char Si4432_IT1);

void Si4432_Interrupt2_Set(unsigned char Si4432_IT2);

void Si4432_Mode1_Set(unsigned char Si4432_Mode1);

void Si4432_Mode2_Set(unsigned char Si4432_Mode2);

void Si4432_Load_Cap_Set(unsigned char Si4432_Crystal_Cap);

void Si4432_GPIO0_Set(unsigned char Si4432_GPIO);

void Si4432_GPIO1_Set(unsigned char Si4432_GPIO);

void Si4432_GPIO2_Set(unsigned char Si4432_GPIO);

void Si4432_Clear_IT_Flag();

void Si4432_Clear_FIFO();

void Si4432_Ready_Mode();

void Si4432_Rx_Mode();

void Si4432_Sent(int Byte_Length,int * Data);

void Si4432_Init();


/*!
 * @}
 */

#endif


//Typedef

typedef enum 
{
	Si4432_TransmitMode,
	Si4432_ReceiveMode,
	Si4432_StandbyMode,
	Si4432_TuneMode,
	Si4432_ReadyMode	

} Si4432_mode_t;







//Prototypes


void Si4432_Write_reg ( uint8_t addr, uint8_t data);
uint8_t Si4432_Read_reg ( uint8_t addr);
void Si4432_Init(void);
void Si4432_SendMsg( Si4432_message_t *Si4432_Msg);
uint8_t Si4432_ReadRxBuffer (uint8_t * RxBuffer_p );
void Si4432_SetMode (Si4432_mode_t mode);




