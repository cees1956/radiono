// A1Main.h

#ifndef A1MAIN_H
#define A1MAIN_H

    // Optional USER Configurations             SIZE
    //==========================================================================================
    //#define USE_PCA9546                1  //  214b - Option to include PCA9546 support
    //#define USE_I2C_LCD                1  //  ???b - Option to include i2c LCD support
      #define USE_RF386                  1  //  272b - Option to include RF386 support
      #define USE_BANDPASS               1  //  104b - Option to include Band Pass Filter Output Pins
    //#define USE_BEACONS                1  // 1488b - Option to include Beacons, CW and QRSS support
      #define USE_EEPROM                 1  // 1454b - Option to include Load and Store to NonVolatile Memory (EEPROM) support
    //#define USE_AUTOSAVE_FACTORY_RESET 1  //    8b - Option to Automatically Save Factory Reset Values to NonVolatile Memory on Reset
      #define USE_MENUS                  1  // 4626b - Option to include Menu support
      #define USE_HAMBANDS               1  // 1552b - Option to include Ham Band and Ham Band Limits
      #define USE_TUNE2500_MODE          1  //   30b - Option to include Tune2500Hz Mode
      #define USE_EDITIF                 1  //  842b - Option to include EditIF function
    //#define USE_POT_KNOB               1  // 2304b - Option to include POT support
    //#define USE_ENCODER01              1  // 2220b - Option to include Simple Encoder01 support
    //#define USE_ENCODER02              1  // 2610b - Option to include FULL Two Digital Pin ISR Encoder02 support
      #define USE_ENCODER03              1  // 2604b - Option to include ISR Encoder03 support On Tuning Pin
    //#define USE_PARK_CURSOR            1  //   24b - Option to Park Cursor when Mode Changes and/or Timeout
      #define USE_HIDELEAST              1  //   84b - Option to Hide Least Digits to right of Cursor while Tuning
      #define USE_OPERATE_60M            1  //    6b - Will Include USE_HAMBANDS, Option to Operate and Support 60m Band Selection


    // Set up Units to make coding large Frequency Numbers easier
    #define Hz   (1UL)
    #define KHz  (1000 * Hz)
    #define MHz  (1000 * KHz)
    
    // Set up Units for Timers
    #define MSECs  (1UL) // Milli Seconds
    #define SECs  (1000 * MSECs) 
    #define MINs  (60   * SECs)
    #define HRs   (60   * MINs)
    #define DAYs  (24   * HRs)
    #define WKs   (7    * DAYs)

    enum Sideband { // Sidebands
        USB = 0,
        LSB,
        AutoSB
    };
 
    // Pin Numbers for analog inputs
    #define FN_PIN (A3)
    #define ANALOG_TUNING (A2)
    #define ANALOG_KEYER (A1)
    
    // Original Output Filter Control Lines
    #define BAND_HI_PIN (5)
    #define BAND_MD_PIN (6)
    #define BAND_LO_PIN (7)
    
    // For Rf386 PA Filter Selector
    #define PA_BAND_CLK (BAND_LO_PIN)
      
    // Set the following Conditional Compile Flags Above
    #ifdef USE_OPERATE_60M
      #define USE_HAMBANDS 1
    #endif
    
    #ifdef USE_PCA9546
      #include "PCA9546.h"
    #endif // USE_PCA9546
    
    #ifdef USE_HAMBANDS
      #include "HamBands.h"
    #endif // USE_HAMBANDS
    
    #ifdef USE_EEPROM
      #include "NonVol.h"
    #endif // USE_EEPROM
    
    #ifdef USE_RF386
      #include "Rf386.h"
    #endif // USE_RF386
    
    #ifdef USE_BEACONS
      #include "MorseCode.h"
      #include "Macro.h"
    #endif // USE_BEACONS
    
    #ifdef USE_POT_KNOB
      #include "PotKnob.h"
    #endif // USE_POT_KNOB
    
    #ifdef USE_MENUS
      #include "Menus.h"
    #endif // USE_MENUS
    
    #ifdef USE_ENCODER01
      #define USE_ENCODER 1
      #define ENC_A_PIN (ANALOG_TUNING)
      #define ENC_B_PIN (FN_PIN)
      #define ISR_DEBOUNCE_TIME_OUT (50 * MSECs)
      #include "Encoder01.h"
    #endif // USE_ENCODER01
     
    #ifdef USE_ENCODER02
      #define USE_ENCODER 2
      #define ENC_A_PIN (8)
      #define ENC_B_PIN (9)
      //#define ENC_A_PIN (6)
      //#define ENC_B_PIN (7)
      #include "Encoder02.h"
      #define ISR_DEBOUNCE_TIME_OUT (50 * MSECs)
    #endif // USE_ENCODER02
     
    #ifdef USE_ENCODER03
      #define USE_ENCODER 3
      #define ENC_A_PIN (16)
      #define ENC_B_PIN (FN_PIN)
      #include "Encoder03.h"
      #define ISR_DEBOUNCE_TIME_OUT (50 * MSECs)
    #endif // USE_ENCODER03
       
    #ifdef USE_EDITIF
      #include "EditIF.h"
    #endif // USE_EDITIF
    
    #ifdef USE_PCA9546
      #define PCA9546_I2C_ADDRESS 0x70
    #endif // USE_PCA9546
    
    #ifdef USE_TUNE2500_MODE
      #include "Tune2500.h"
    #endif // USE_TUNE2500_MODE



    #ifdef USE_PARK_CURSOR
       #define DEFAULT_BLINK_TIMEOUT (20 * SECs) // Set as desired
       #define DEFAULT_CURSOR_POSITION (0)       // Power Up Cursor Position, Park is Zero
    #else
       #define DEFAULT_BLINK_TIMEOUT (4 * HRs)   // Set to Zero for Never
       #define DEFAULT_CURSOR_POSITION (3)       // Power Up Cursor Position, Set as desired, Park is Zero
    #endif // USE_PARK_CURSOR
    
    #ifdef USE_HIDELEAST
       #define DEFAULT_BLINK_TIMEOUT (30 * MINs)
       #define DEFAULT_BLINK_RATIO (100)
       #define DEFAULT_BLINK_PERIOD (10 * SECs)
       #define DEFAULT_CURSOR_POSITION (3)       // Power Up Cursor Position, Set as desired, Park is Zero
    #endif // USE_HIDELEAST
    
    
    enum VFOs { // Available VFOs
        VFO_A = 0,
        VFO_B,
    };

    enum LCD_DisplayLines {
        FIRST_LINE = 0,
        STATUS_LINE,
        MENU_PROMPT_LINE,
        MENU_ITEM_LINE
    };

  
    #define DEBUG(x ...)  // Default to NO debug
    //#define DEBUG(x ...) debugUnique(x)    // UnComment for Debug
 

    // Externally Available Variables
    extern unsigned long frequency;
    extern unsigned long iFreqUSB;
    extern unsigned long iFreqLSB;
    
    extern unsigned long vfoA, vfoB;
    extern unsigned long cwTimeout;
    //extern boolean editIfMode;
    
    extern char b[], c[];  // General Buffers, used mostly for Formating message for LCD
    
    //extern byte menuActive;
    //extern byte menuPrev;
    extern byte refreshDisplay;
    extern unsigned long blinkTimeOut;
    extern int blinkPeriod;
    extern byte blinkRatio;
    extern unsigned long menuIdleTimeOut;

    /* tuning pot stuff */  
    //extern int tuningDir;
    extern int knobPosition;
    extern int freqUnStable;
    extern int knobPositionDelta;
    extern int cursorDigitPosition;
    extern int knobPositionPrevious;
    //extern int cursorCol, cursorRow, cursorMode;
    //extern char* const sideBandText[] PROGMEM;
    extern byte sideBandMode;
    
    extern boolean tuningLocked; //the tuning can be locked: wait until Freq Stable before unlocking it
    extern boolean dialCursorMode;
    extern boolean inTx, inPtt;
    extern boolean keyDown0;
    extern boolean isLSB;
    extern boolean vfoActive;
    
    /* modes */
    extern int ritVal;
    extern boolean ritOn;
    extern boolean AltTxVFO;
    //extern boolean isAltVFO;


    // Externally Available Functions
    extern void updateDisplay();   
    extern void cursorOff();
    extern void printLineXY(byte x, byte y, char const *c);
    extern void printLineCEL(int row, char const *c);
    extern void printLine(int row, char const *c);
    extern void startSidetone();
    extern void stopSidetone();
    extern void decodeSideband();
    extern void changeToTransmit();
    extern void changeToReceive();
    extern  int isKeyNowClosed();
    extern  int isPttPressed();
    extern void setFreq(unsigned long freq);
    
    // ERB - Buffers that Stores "const stings" to, and Reads from FLASH Memory via P()
    #define PBUFSIZE (66)
    extern char buf[PBUFSIZE];
    
    // ERB - Force format stings into FLASH Memory
    #define  P(x) strcpy_P(buf, PSTR(x))
    // PN can be used where Multiple small (1/2, 1/4, 1/8 size) Buffers are needed.
    #define P2(x) strcpy_P(buf + PBUFSIZE/2,   PSTR(x))
    #define P3(x) strcpy_P(buf + PBUFSIZE/8*5, PSTR(x))
    #define P4(x) strcpy_P(buf + PBUFSIZE/4*3, PSTR(x))
    #define P8(x) strcpy_P(buf + PBUFSIZE/8*7, PSTR(x))
    
    // Buffer Space Indexes
    // |-------|-------|-------|-------|-------|-------|-------|-------|
    // |-------------------------------|-------|-------|-------|-------|
    // P                               P       P       P       P
    //                                 2       3       4       8

#endif

// End
