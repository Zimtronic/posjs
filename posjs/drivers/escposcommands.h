//ifndef ESCPOSCOMMANDS_H
//define ESCPOSCOMMANDS_H

   /**
    *@brief ESC/POS protocol commands
    *
    *
    *@author tony
    *@date 18-10-2014
    */

#define FEEDCONTROLLENGTH  1
#define INITLENGTH  2
#define CASHDRAWERLENGTH  3
#define PAPERCUTLENGTH  3
#define TEXTFORMATLENGTH  3


/**
  * @brief Feed control sequences
  */
unsigned char CTL_LF[] = {0x0a}; /**< Print and line feed. */
unsigned char CTL_FF[] = {0x0c}; /**< Form feed. */
unsigned char CTL_CR[] = {0x0d}; /**< Carriage return. */
unsigned char CTL_HT[] = {0x09}; /**< Horizontal tab. */
unsigned char CTL_VT[] = {0x0b}; /**< Vertical tab. */


/**
  * @brief Printer hardware
  */
unsigned char HW_INIT[] = {0x1b, 0x40}; /**< Clear data in buffer and reset modes. */
unsigned char HW_SELECT[] = {0x1b, 0x3d, 0x01}; /**< Printer select. */
unsigned char HW_RESET[] = {0x1b, 0x3f, 0x0a, 0x00}; /**< Reset printer hardware. */

/**
  * @brief Cash Drawer
  */
unsigned char CD_KICK_2[] = {0x1b, 0x70, 0x00}; /**< Sends a pulse to pin 2 []. */
unsigned char CD_KICK_5[] = {0x1b,0x70,0x01}; /**< Sends a pulse to pin 5 []. */

/**
  * @brief Paper
  */
unsigned char PAPER_FULL_CUT[] = {0x1d, 0x56, 0x00}; /**< Full cut paper. */
unsigned char PAPER_PART_CUT[] = {0x1d, 0x56, 0x01}; /**< Partial cut paper. */

/**
  * @brief Text format
  */
unsigned char TXT_NORMAL[] = {0x1b, 0x21, 0x00}; /**< Normal text. */
unsigned char TXT_2HEIGHT[] = {0x1b, 0x21, 0x10}; /**< Double height text. */
unsigned char TXT_2WIDTH[] = {0x1b, 0x21, 0x20}; /**< Double width text. */
unsigned char TXT_DOUBLE[] = {0x1b, 0x21, 0x30}; /**< Double height & Width. */
unsigned char TXT_UNDERL_OFF[] = {0x1b, 0x2d, 0x00}; /**< Underline font OFF. */
unsigned char TXT_UNDERL_ON[] = {0x1b, 0x2d, 0x01}; /**< Underline font 1-dot ON. */
unsigned char TXT_UNDERL2_ON[] = {0x1b, 0x2d, 0x02}; /**< Underline font 2-dot ON. */
unsigned char TXT_BOLD_OFF[] = {0x1b, 0x45, 0x00}; /**< Bold font OFF. */
unsigned char TXT_BOLD_ON[] = {0x1b, 0x45, 0x01}; /**< Bold font ON. */
unsigned char TXT_FONT_A[] = {0x1b, 0x4d, 0x00}; /**< Font type A. */
unsigned char TXT_FONT_B[] = {0x1b, 0x4d, 0x01}; /**< Font type B. */
unsigned char TXT_ALIGN_LT[] = {0x1b, 0x61, 0x00}; /**< Left justification. */
unsigned char TXT_ALIGN_CT[] = {0x1b, 0x61, 0x01}; /**< Centering. */
unsigned char TXT_ALIGN_RT[] = {0x1b, 0x61, 0x02}; /**< Right justification. */
unsigned char TXT_COLOR_BLACK[] = {0x1b, 0x72, 0x00}; /**< Default Color. */
unsigned char TXT_COLOR_RED[] = {0x1b, 0x72, 0x01}; /**< Alternative Color ( Usually Red ). */


//endif // ESCPOSCOMMANDS_H
