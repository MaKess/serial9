/* ---------------------------------------------------------------------------
  serial9.h - support for 9 bit serial data using the physical UART

  See README and LICENCE for more information
 */

#ifndef SERIAL9_H
#define SERIAL9_H

enum serial9_state_e { SERIAL9_STATE_IDLE,
                       SERIAL9_STATE_ESCAPE,
                       SERIAL9_STATE_HIGH,
                       SERIAL9_STATE_CUSTOM_BAUD_1,
                       SERIAL9_STATE_CUSTOM_BAUD_2,
                       SERIAL9_STATE_CUSTOM_BAUD_3,
                       SERIAL9_STATE_CUSTOM_BAUD_4,
                     };

enum serial9_protocol_e : uint8_t {
  SERIAL9_ESCAPE = 0xff,
  SERIAL9_HIGH = 0x01, // The next byte is sent with BIT9 high
  SERIAL9_BAUD_CUSTOM = 0x02, // the next four bytes represent a custom baud rate
  SERIAL9_8BIT = 0x08, // Set the UART to 8 bit mode
  SERIAL9_9BIT = 0x09, // Set the UART to 9 bit mode (default)
  SERIAL9_BAUD_300 = 0x10,
  SERIAL9_BAUD_600 = 0x11,
  SERIAL9_BAUD_1200 = 0x12,
  SERIAL9_BAUD_2400 = 0x13,
  SERIAL9_BAUD_4800 = 0x14,
  SERIAL9_BAUD_9600 = 0x15,
  SERIAL9_BAUD_19200 = 0x16,
  SERIAL9_BAUD_38400 = 0x17,
  SERIAL9_BAUD_57600 = 0x18,
  SERIAL9_BAUD_115200 = 0x19,
};

class Serial9 // : public Stream
{
  private:
    bool _writing;
    uint32_t custom_baud;

    enum serial9_state_e tx_state;

  public:
    Serial9();
    ~Serial9();

    void begin(uint32_t baud);
    void end(void);
    void loop(void);
};

// This macro is used to provide code coverage for empty cases
// or conditional clauses - when we are compiling normally
// it evaluates to nothing 

#ifdef GCOV
  #define DO_NOTHING { int do_nothing = 0; }
#else
  #define DO_NOTHING
#endif 

#endif // SERIAL9_H
