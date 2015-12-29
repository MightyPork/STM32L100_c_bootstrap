#pragma once
#include "common.h"

/** Wait for incoming data on USART (true on success) */
bool usart_wait_rx(uint32_t usart);

/** Check if USART has received a byte */
bool usart_rx_ready(uint32_t usart);

/** Receive a char from USART. Does not check if ready. */
char usart_rx_char(uint32_t usart);

/**
 * Receive up to `len` chars from USART;
 *
 * Adds \0 after last char.
 * Total length (without the \0) is returned.
 */
uint32_t usart_rx_string(uint32_t usart, char *buffer, uint32_t len);

/** Wait for outgoing data on USART (true on success) */
bool usart_wait_tx(uint32_t usart);

/** Check if USART has finished sending a byte */
bool usart_tx_ready(uint32_t usart);

/** Transmit a character. First waits for TX buffer to empty. */
void usart_tx_char(uint32_t usart, uint8_t c);

/** Transmit a string until \0 */
void usart_tx_string(uint32_t usart, const char *string);
