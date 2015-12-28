#include "usart.h"

#define RX_TIMEOUT 1000000
#define TX_TIMEOUT 1000000


/** Wait for incoming data on USART (true on success) */
bool usart_wait_rx(uint32_t usart)
{
	for (uint32_t i = 0; i < RX_TIMEOUT; i++) {
		if (usart_rx_ready(usart)) return true;
	}
	return false;
}


/** Wait for outgoing data on USART (true on success) */
bool usart_wait_tx(uint32_t usart)
{
	for (uint32_t i = 0; i < TX_TIMEOUT; i++) {
		if (usart_tx_ready(usart)) return true;
	}
	return false;
}


/** Check if USART has received a byte */
bool usart_rx_ready(uint32_t usart)
{
	io32_t SR = P_REG(usart, USART_SR_offs);

	return (*SR & USART_SR_RXNE);
}


/** Check if USART has finished sending a byte */
bool usart_tx_ready(uint32_t usart)
{
	io32_t SR = P_REG(usart, USART_SR_offs);

	return (*SR & USART_SR_TXE);
}


/** Receive a char from USART. Does not check if ready. */
char usart_rx_char(uint32_t usart)
{
	io32_t DR = P_REG(usart, USART_DR_offs);

	return *DR & 0xFF;
}


/** Receive up to `len` chars from USART. */
uint32_t usart_rx_string(uint32_t usart, char *buffer, uint32_t len)
{
	uint32_t i;
	for (i = 0; i < len; i++) {
		if (!usart_wait_rx(usart)) break;
		buffer[i] = usart_rx_char(usart);
	}

	buffer[i] = 0;
	return i;
}


/** Transmit a character. First waits for TX buffer to empty. */
void usart_tx_char(uint32_t usart, uint8_t c)
{
	io32_t DR = P_REG(usart, USART_DR_offs);
	usart_wait_tx(usart);
	*DR = c;
}

/** Transmit a string until \0 */
void usart_tx_string(uint32_t usart, char *string)
{
	char c;
	while ((c = *string++) != 0) {
		usart_tx_char(usart, c);
	}
}

