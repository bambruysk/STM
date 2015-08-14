
#include "Si4432.h"

#include "stm8l10x.h"

//Запись регистра в Si4432
void Si4432_Write( uint8_t addr, uint8_t data)
{
    addr |= 0x80;

    SPI_NSSPinDown();
    SPI_SendData(addr);
    SPI_SendData(data);
    SPI_NSSPinUp();
}

//
uint8_t Si4432_Read ( uint8_t addr)
{
    addr &= 0x7F;
    uint8_t data;
    SPI_NSSPinDown();
    SPI_SendData(addr);
    data = SPI_ReceiveData(data);
    SPI_NSSPinUp();
    return data;
}



/*!
 * \author no1wudi
 * \file Si4432.c
 */

#include "Si4432.h"

/*!
 * \biref Set the interrupt 1 of the chip
 * \param Si4432_IT1 The IT status of the chip
 */

void Si4432_Interrupt1_Set(unsigned char Si4432_IT1) {
	Si4432_Write(Si4432_Reg_Interrupt_Enable_1, Si4432_IT1);
}

/*!
 * \biref Set the interrupt 2 of the chip
 * \param Si4432_IT2 The IT status of the chip
 */

void Si4432_Interrupt2_Set(unsigned char Si4432_IT2) {
	Si4432_Write(Si4432_Reg_Interrupt_Enable_2, Si4432_IT2);
}

/*!
 * \brief Set the work mode of the chip
 * \param Si4432_Mode1 The mode you selected
 */
void Si4432_Mode1_Set(unsigned char Si4432_Mode1) {
	Si4432_Write(Si4432_Reg_Operating_Mode_1, Si4432_Mode1);
}

/*!
 * \brief Set the work mode of the chip
 * \param Si4432_Mode2 The mode you selected
 */
void Si4432_Mode2_Set(unsigned char Si4432_Mode2) {
	Si4432_Write(Si4432_Reg_Operating_Mode_2, Si4432_Mode2);
}

/*!
 * \brief Set the crystal osclillator load capacitance
 * \param Si4432_Crystal_Cap The additional capacitance to coarse shift the frequency
 */

void Si4432_Load_Cap_Set(unsigned char Si4432_Crystal_Cap) {
	Si4432_Write(Si4432_Reg_Crystal_Load_Capacitance, Si4432_Crystal_Cap);
}

/*!
 *\brief Set the function of GPIO 0
 *\param Si4432_GPIO Settings.
 */

void Si4432_GPIO0_Set(unsigned char Si4432_GPIO) {
	Si4432_Write(Si4432_Reg_GPIO_Config_0, Si4432_GPIO);
}

/*!
 *\brief Set the function of GPIO 1
 *\param Si4432_GPIO Settings.
 */

void Si4432_GPIO1_Set(unsigned char Si4432_GPIO) {
	Si4432_Write(Si4432_Reg_GPIO_Config_1, Si4432_GPIO);
}

/*!
 *\brief Set the function of GPIO 2
 *\param Si4432_GPIO Settings.
 */

void Si4432_GPIO2_Set(unsigned char Si4432_GPIO) {
	Si4432_Write(Si4432_Reg_GPIO_Config_2, Si4432_GPIO);
}

/*!
 * \brief Clear the interrupt flag
 */

void Si4432_Clear_IT_Flag() {
	Si4432_Read(Si4432_Reg_Interrupt_Status_1);
	Si4432_Read(Si4432_Reg_Interrupt_Status_2);
}

/*!
 * \brief Clear the FIFO
 */
void Si4432_Clear_FIFO() {
	Si4432_Write(Si4432_Reg_Operating_Mode_2, 0x03);
	Si4432_Write(Si4432_Reg_Operating_Mode_2, 0x00);
}

/*!
 * \brief Enter the ready mode
 */

void Si4432_Ready_Mode() {
	Si4432_Clear_IT_Flag();
	Si4432_Interrupt1_Set(Si4432_IT1_Disable);
	Si4432_Mode1_Set(Si4432_Mode1_Ready);
}

/*!
 * \brief Enter the Rx mode
 */

void Si4432_Rx_Mode() {
	Si4432_Ready_Mode();
	Si4432_Delay(50);
	Si4432_Write(Si4432_Reg_IO_Port_Config, 0x02);
	Si4432_Clear_FIFO();
	Si4432_Mode1_Set(Si4432_Mode1_Rx_On | Si4432_Mode1_Ready);
	Si4432_Interrupt1_Set(Si4432_IT1_Valid_Packed_Recived);
	Si4432_Clear_IT_Flag();
}

/*!
 * \brief Enter the Tx mode
 */

void Si4432_Sent(uint8_t Byte_Length, uint8_t * Data) {
	Si4432_Ready_Mode();
	Si4432_Write(Si4432_Reg_IO_Port_Config, 0x01);
	Si4432_Delay(50);
	Si4432_Clear_FIFO();
	Si4432_Write(Si4432_Reg_Packet_Length,Byte_Length);
	for (uint8_t i = 0; i < Byte_Length; i++) {
		Si4432_Write(Si4432_Reg_FIFO_Access,*(Data + i));
	}
	Si4432_Interrupt1_Set(Si4432_IT1_Packet_Sent);
	Si4432_Clear_IT_Flag();
	Si4432_Mode1_Set(Si4432_Mode1_Tx_On | Si4432_Mode1_Ready);
}


/*!
 * \brief Init the chip,it will enter ready mode by default.
 */
void Si4432_Init(){
//	Si4432_SPI_Init();
	Si4432_Clear_IT_Flag();
	Si4432_Interrupt1_Set(Si4432_IT1_Disable);
	Si4432_Ready_Mode();
}




void Si4432_SendMsg( Si4432_message_t *Si4432_Msg)
{

}

uint8_t Si4432_ReadRxBuffer (uint8_t * RxBuffer_p )
{

}


void Si4432_SetMode (Si4432_mode_t mode)
{
}

uint8_t Si4432_GetVbat()
{
	return Si4432_Read(Si4432_Reg_Battery_Voltage_Level);
}


void Si4432_Standby()
{
	Si4432_Clear_IT_Flag();
	Si4432_Interrupt1_Set(Si4432_IT1_Disable);
	Si4432_Mode1_Set(Si4432_Mode1_Ready);
}



