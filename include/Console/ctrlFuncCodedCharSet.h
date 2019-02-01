/*
 * ESC - ESCAPE

 * @ Parameters Required:
 * No Parameter Required

 * @ More Info:
 * ESC is used for code extension purposes. It causes the meanings
 * of a limited number of bit combinations following it in
 * the data stream to be changed.

 * The use of ESC is defined in Standard ECMA-35.
 *
 */
#define ESC "\x1b"

/*
 * CSI - CONTROL SEQUENCE INTRODUCER

 * @ Parameters Required:
 * No Parameter Required

 * @ More Info:
 * CSI is used as the first character of a control sequence, see 5.4.
 *
 */
#define CSI ESC "["

/*
 * ACK - ACKNOWLEDGE

 * @ Parameters Required: 
 * No Parameter Required

 * @ More Info:
 * ACK is transmitted by a receiver as an affirmative response to the sender.

 * The use of ACK is defined in ISO 1745.
 *
 */
#define ACK "\x06"

/*
 * APC - APPLICATION PROGRAM COMMAND

 * @ Parameters Required: 
 * No Parameter Required

 * @ More Info:
 * APC is used as the opening delimiter of a control string for application
 * program use. The command string following may consist of bit combinations
 * in the range 00/08 to 00/13 and 02/00 to 07/14. The control string is
 * closed by the terminating delimiter STRING TERMINATOR (ST). The interpretation
 * of the command string depends on the relevant application program.
 *
 */
#define APC ESC "_"

/*
 * BEL - BELL

 * @ Parameters Required: 
 * No Parameter Required

 * @ More Info:
 * BEL is used when there is a need to call for attention; it may
 * control alarm or attention devices.
 *
 */
#define BEL "\x07"

/*
 * BPH - BREAK PERMITTED HERE

 * @ Parameters Required: 
 * No Parameter Required

 * @ More Info:
 * BPH is used to indicate a point where a line break may occur
 * when text is formatted. BPH may occur between two graphic
 * characters, either or both of which may be SPACE.
 *
 */
#define BPH ESC "B"

/*
 * BS - BACKSPACE

 * @ Parameters Required: 
 * No Parameter Required

 * @ More Info:
 * BS causes the active data position to be moved one character
 * position in the data component in the direction opposite
 * to that of the implicit movement.

 * The direction of the implicit movement depends on the parameter
 * value of SELECT IMPLICIT MOVEMENT DIRECTION (SIMD).
 *
 */
#define BS "\x08"

/*
 * CAN - CANCEL

 * @ Parameters Required: 
 * No Parameter Required

 * @ More Info:
 * CAN is used to indicate that the data preceding it in the data
 * stream is in error. As a result, this data shall be
 * ignored. The specific meaning of this control function
 * shall be defined for each application and/or between
 * sender and recipient.
 *
 */
#define CAN "\x18"

/*
 * CBT - CURSOR BACKWARD TABULATION

 * @ Parameters Required: 
 * Pn

 * @ More Info:
 * CBT causes the active presentation position to be moved to the
 * character position corresponding to the n-th preceding
 * character tabulation stop in the presentation component,
 * according to the character path, where n equals the value of Pn.
 *
 */
#define CBT(Pn) CSI #Pn "Z"

/*
 * CBT - CURSOR BACKWARD TABULATION

 * @ Parameters Required: 
 * No Parameter Required

 * @ More Info:
 * CBT causes the active presentation position to be moved to the
 * character position corresponding to the n-th preceding
 * character tabulation stop in the presentation component,
 * according to the character path, where n equals the value of Pn.
 *
 */
#define _CBT_ CSI "Z"

/*
 * CCH - CANCEL CHARACTER

 * @ Parameters Required: 
 * No Parameter Required

 * @ More Info:
 * CCH is used to indicate that both the preceding graphic character
 * in the data stream, (represented by one or more bit
 * combinations) including SPACE, and the control function
 * CCH itself are to be ignored for further interpretation of
 * the data stream.

 * If the character preceding CCH in the data stream is a control
 * function (represented by one or more bit combinations),
 * the effect of CCH is not defined by this Standard.
 *
 */
#define CCH ESC "T"

/*
 * CHA - CURSOR CHARACTER ABSOLUTE

 * @ Parameters Required: 
 * Pn

 * @ More Info:
 * CHA causes the active presentation position to be moved to
 * character position n in the active line in the
 * presentation component, where n equals the value of Pn.
 *
 */
#define CHA(Pn) CSI #Pn "G"

/*
 * CHA - CURSOR CHARACTER ABSOLUTE

 * @ Parameters Required: 
 * No Parameter Required

 * @ More Info:
 * CHA causes the active presentation position to be moved to
 * character position n in the active line in the
 * presentation component, where n equals the value of Pn.
 *
 */
#define _CHA_ CSI "G"

/*
 * CHT - CURSOR FORWARD TABULATION

 * @ Parameters Required: 
 * Pn

 * @ More Info:
 * CHT causes the active presentation position to be moved to the
 * character position corresponding to the n-th following
 * character tabulation stop in the presentation component,
 * according to the character path, where n equals the value of Pn.
 *
 */
#define CHT(Pn) CSI #Pn "I"

/*
 * CHT - CURSOR FORWARD TABULATION

 * @ Parameters Required: 
 * No Parameter Required

 * @ More Info:
 * CHT causes the active presentation position to be moved to the
 * character position corresponding to the n-th following
 * character tabulation stop in the presentation component,
 * according to the character path, where n equals the value of Pn.
 *
 */
#define _CHT_ CSI "I"

/*
 * CMD - CODING METHOD DELIMITER

 * @ Parameters Required: 
 * Fs

 * @ More Info:
 * CMD is used as the delimiter of a string of data coded according
 * to Standard ECMA-35 and to switch to a general level of control.

 * The use of CMD is not mandatory if the higher level protocol
 * defines means of delimiting the string, for instance, by
 * specifying the length of the string.
 *
 */
#define CMD(Fs) ESC "d"

/*
 * CNL - CURSOR NEXT LINE

 * @ Parameters Required: 
 * Pn

 * @ More Info:
 * CNL causes the active presentation position to be moved to the
 * first character position of the n-th following line in the
 * presentation component, where n equals the value of Pn.
 *
 */
#define CNL(Pn) CSI #Pn "E"

/*
 * CNL - CURSOR NEXT LINE

 * @ Parameters Required: 
 * No Parameter Required

 * @ More Info:
 * CNL causes the active presentation position to be moved to the
 * first character position of the n-th following line in the
 * presentation component, where n equals the value of Pn.
 *
 */
#define _CNL_ CSI "E"

/*
 * CPL - CURSOR PRECEDING LINE

 * @ Parameters Required: 
 * Pn

 * @ More Info:
 * CPL causes the active presentation position to be moved to the
 * first character position of the n-th preceding line in the
 * presentation component, where n equals the value of Pn.
 *
 */
#define CPL(Pn) CSI #Pn "F"

/*
 * CPL - CURSOR PRECEDING LINE

 * @ Parameters Required: 
 * No Parameter Required

 * @ More Info:
 * CPL causes the active presentation position to be moved to the
 * first character position of the n-th preceding line in the
 * presentation component, where n equals the value of Pn.
 *
 */
#define _CPL_ CSI "F"

/*
 * CPR - ACTIVE POSITION REPORT

 * @ Parameters Required: 
 * Pn1, Pn2

 * @ More Info:
 * If the DEVICE COMPONENT SELECT MODE (DCSM) is set to PRESENTATION,
 * CPR is used to report the active presentation position of
 * the sending device as residing in the presentation
 * component at the n-th line position according to the line
 * progression and at the m-th character position according
 * to the character path, where n equals the value of Pn1 and
 * m equals the value of Pn2.

 * If the DEVICE COMPONENT SELECT MODE (DCSM) is set to DATA, CPR
 * is used to report the active data position of the sending device
 * as residing in the data component at the n-th line position according to
 * the line progression and at the m-th character position
 * according to the character progression, where n equals the
 * value of Pn1 and m equals the value of Pn2.

 * CPR may be solicited by a DEVICE STATUS REPORT (DSR) or be sent unsolicited.
 *
 */
#define CPR(Pn1, Pn2) CSI #Pn1 ";" #Pn2 "R"

/*
 * CPR - ACTIVE POSITION REPORT

 * @ Parameters Required: 
 * Pn1

 * @ More Info:
 * If the DEVICE COMPONENT SELECT MODE (DCSM) is set to PRESENTATION,
 * CPR is used to report the active presentation position of
 * the sending device as residing in the presentation
 * component at the n-th line position according to the line
 * progression and at the m-th character position according
 * to the character path, where n equals the value of Pn1 and
 * m equals the value of Pn2.

 * If the DEVICE COMPONENT SELECT MODE (DCSM) is set to DATA, CPR
 * is used to report the active data position of the sending device
 * as residing in the data component at the n-th line position according to
 * the line progression and at the m-th character position
 * according to the character progression, where n equals the
 * value of Pn1 and m equals the value of Pn2.

 * CPR may be solicited by a DEVICE STATUS REPORT (DSR) or be sent unsolicited.
 *
 */
#define _CPR(Pn1) CSI #Pn1 ";" "R"

/*
 * CPR - ACTIVE POSITION REPORT

 * @ Parameters Required: 
 * Pn2

 * @ More Info:
 * If the DEVICE COMPONENT SELECT MODE (DCSM) is set to PRESENTATION,
 * CPR is used to report the active presentation position of
 * the sending device as residing in the presentation
 * component at the n-th line position according to the line
 * progression and at the m-th character position according
 * to the character path, where n equals the value of Pn1 and
 * m equals the value of Pn2.

 * If the DEVICE COMPONENT SELECT MODE (DCSM) is set to DATA, CPR
 * is used to report the active data position of the sending device
 * as residing in the data component at the n-th line position according to
 * the line progression and at the m-th character position
 * according to the character progression, where n equals the
 * value of Pn1 and m equals the value of Pn2.

 * CPR may be solicited by a DEVICE STATUS REPORT (DSR) or be sent unsolicited.
 *
 */
#define __CPR(Pn2) CSI ";" #Pn2 "R"

/*
 * CPR - ACTIVE POSITION REPORT

 * @ Parameters Required: 
 * No Parameter Required

 * @ More Info:
 * If the DEVICE COMPONENT SELECT MODE (DCSM) is set to PRESENTATION,
 * CPR is used to report the active presentation position of
 * the sending device as residing in the presentation
 * component at the n-th line position according to the line
 * progression and at the m-th character position according
 * to the character path, where n equals the value of Pn1 and
 * m equals the value of Pn2.

 * If the DEVICE COMPONENT SELECT MODE (DCSM) is set to DATA, CPR
 * is used to report the active data position of the sending device
 * as residing in the data component at the n-th line position according to
 * the line progression and at the m-th character position
 * according to the character progression, where n equals the
 * value of Pn1 and m equals the value of Pn2.

 * CPR may be solicited by a DEVICE STATUS REPORT (DSR) or be sent unsolicited.
 *
 */
#define _CPR_ CSI ";" "R"

/*
 * CR - CARRIAGE RETURN

 * @ Parameters Required: 
 * No Parameter Required

 * @ More Info:
 * The effect of CR depends on the setting of the DEVICE COMPONENT
 * SELECT MODE (DCSM) and on the parameter value of SELECT
 * IMPLICIT MOVEMENT DIRECTION (SIMD).

 * If the DEVICE COMPONENT SELECT MODE (DCSM) is set to PRESENTATION and
 * with the parameter value of SIMD equal to 0, CR causes the
 * active presentation position to be moved to the line home
 * position of the same line in the presentation component.
 * The line home position is established by the parameter
 * value of SET LINE HOME (SLH).

 * With a parameter value of SIMD equal to 1, CR causes the active presentation
 * position to be moved to the line limit position of the
 * same line in the presentation component. The line limit
 * position is established by the parameter value of SET LINE
 * LIMIT (SLL).

 * If the DEVICE COMPONENT SELECT MODE (DCSM) is set to DATA and with
 * a parameter value of SIMD equal to 0, CR causes the active data position to
 * be moved to the line home position of the same line in the data component.
 * The line home position is established by the parameter value of SET LINE HOME (SLH).

 * With a parameter value of SIMD equal to 1, CR causes the active
 * data position to be moved to the line limit position of
 * the same line in the data component. The line limit
 * position is established by the parameter value of SET LINE LIMIT (SLL).
 *
 */
#define CR "\r"

/*
 * CTC - CURSOR TABULATION CONTROL

 * @ Parameters Required: 
 * Ps

 * @ More Info:
 * CTC causes one or more tabulation stops to be set or cleared
 * in the presentation component, depending on the parameter values:

 * 0 -> a character tabulation stop is set at the active presentation position
 * 1 -> a line tabulation stop is set at the active line
 * (the line that contains the active presentation position)
 * 2 -> the character tabulation stop at the active presentation position is cleared
 * 3 -> the line tabulation stop at the active line is cleared
 * 4 -> all character tabulation stops in the active line are cleared
 * 5 -> all character tabulation stops are cleared
 * 6 -> all line tabulation stops are cleared

 * In the case of parameter values 0, 2 or 4 the number of lines affected
 * depends on the setting of the TABULATION STOP MODE (TSM).
 *
 */
/*
 * CTC - CURSOR TABULATION CONTROL

 * @ Parameters Required: 
 * No Parameter Required

 * @ More Info:
 * CTC causes one or more tabulation stops to be set or cleared
 * in the presentation component, depending on the parameter values:

 * 0 -> a character tabulation stop is set at the active presentation position
 * 1 -> a line tabulation stop is set at the active line
 * (the line that contains the active presentation position)
 * 2 -> the character tabulation stop at the active presentation position is cleared
 * 3 -> the line tabulation stop at the active line is cleared
 * 4 -> all character tabulation stops in the active line are cleared
 * 5 -> all character tabulation stops are cleared
 * 6 -> all line tabulation stops are cleared

 * In the case of parameter values 0, 2 or 4 the number of lines affected
 * depends on the setting of the TABULATION STOP MODE (TSM).
 *
 */
#define _CTC_ CSI "W"

/*
 * CUB - CURSOR LEFT

 * @ Parameters Required: 
 * Pn

 * @ More Info:
 * CUB causes the active presentation position to be moved leftwards
 * in the presentation component by n character positions if
 * the character path is horizontal, or by n line positions
 * if the character path is vertical, where n equals the
 * value of Pn.
 *
 */
#define CUB(Pn) CSI #Pn "D"

/*
 * CUB - CURSOR LEFT

 * @ Parameters Required: 
 * No Parameter Required

 * @ More Info:
 * CUB causes the active presentation position to be moved leftwards
 * in the presentation component by n character positions if
 * the character path is horizontal, or by n line positions
 * if the character path is vertical, where n equals the
 * value of Pn.
 *
 */
#define _CUB_ CSI "D"

/*
 * CUD - CURSOR DOWN

 * @ Parameters Required: 
 * Pn

 * @ More Info:
 * CUD causes the active presentation position to be moved downwards
 * in the presentation component by n line positions if the
 * character path is horizontal, or by n character positions
 * if the character path is vertical, where n equals the
 * value of Pn.
 *
 */
#define CUD(Pn) CSI #Pn "B"

/*
 * CUD - CURSOR DOWN

 * @ Parameters Required: 
 * No Parameter Required

 * @ More Info:
 * CUD causes the active presentation position to be moved downwards
 * in the presentation component by n line positions if the
 * character path is horizontal, or by n character positions
 * if the character path is vertical, where n equals the
 * value of Pn.
 *
 */
#define _CUD_ CSI "B"

/*
 * CUF - CURSOR RIGHT

 * @ Parameters Required: 
 * Pn

 * @ More Info:
 * CUF causes the active presentation position to be moved
 * rightwards in the presentation component by n character
 * positions if the character path is horizontal, or by n
 * line positions if the character path is vertical, where n
 * equals the value of Pn.
 *
 */
#define CUF(Pn) CSI #Pn "C"

/*
 * CUF - CURSOR RIGHT

 * @ Parameters Required: 
 * No Parameter Required

 * @ More Info:
 * CUF causes the active presentation position to be moved
 * rightwards in the presentation component by n character
 * positions if the character path is horizontal, or by n
 * line positions if the character path is vertical, where n
 * equals the value of Pn.
 *
 */
#define _CUF_ CSI "C"

/*
 * CUP - CURSOR POSITION

 * @ Parameters Required: 
 * Pn1, Pn2

 * @ More Info:
 * CUP causes the active presentation position to be moved in the
 * presentation component to the n-th line position according
 * to the line progression and to the m-th character position
 * according to the character path, where n equals the value
 * of Pn1 and m equals the value of Pn2.
 *
 */
#define CUP(Pn1, Pn2) CSI #Pn1 ";" #Pn2 "H"

/*
 * CUP - CURSOR POSITION

 * @ Parameters Required: 
 * Pn1

 * @ More Info:
 * CUP causes the active presentation position to be moved in the
 * presentation component to the n-th line position according
 * to the line progression and to the m-th character position
 * according to the character path, where n equals the value
 * of Pn1 and m equals the value of Pn2.
 *
 */
#define _CUP(Pn1) CSI #Pn1 ";" "H"

/*
 * CUP - CURSOR POSITION

 * @ Parameters Required: 
 * Pn2

 * @ More Info:
 * CUP causes the active presentation position to be moved in the
 * presentation component to the n-th line position according
 * to the line progression and to the m-th character position
 * according to the character path, where n equals the value
 * of Pn1 and m equals the value of Pn2.
 *
 */
#define __CUP(Pn2) CSI ";" #Pn2 "H"

/*
 * CUP - CURSOR POSITION

 * @ Parameters Required: 
 * No Parameter Required

 * @ More Info:
 * CUP causes the active presentation position to be moved in the
 * presentation component to the n-th line position according
 * to the line progression and to the m-th character position
 * according to the character path, where n equals the value
 * of Pn1 and m equals the value of Pn2.
 *
 */
#define _CUP_ CSI ";" "H"

/*
 * CUU - CURSOR UP

 * @ Parameters Required: 
 * Pn

 * @ More Info:
 * CUU causes the active presentation position to be moved upwards
 * in the presentation component by n line positions if the
 * character path is horizontal, or by n character positions
 * if the character path is vertical, where n equals the
 * value of Pn.
 *
 */
#define CUU(Pn) CSI #Pn "A"

/*
 * CUU - CURSOR UP

 * @ Parameters Required: 
 * No Parameter Required

 * @ More Info:
 * CUU causes the active presentation position to be moved upwards
 * in the presentation component by n line positions if the
 * character path is horizontal, or by n character positions
 * if the character path is vertical, where n equals the
 * value of Pn.
 *
 */
#define _CUU_ CSI "A"

/*
 * CVT - CURSOR LINE TABULATION

 * @ Parameters Required: 
 * Pn

 * @ More Info:
 * CVT causes the active presentation position to be moved to the
 * corresponding character position of the line corresponding
 * to the n-th following line tabulation stop in the
 * presentation component, where n equals the value of Pn.
 *
 */
#define CVT(Pn) CSI #Pn "Y"

/*
 * CVT - CURSOR LINE TABULATION

 * @ Parameters Required: 
 * No Parameter Required

 * @ More Info:
 * CVT causes the active presentation position to be moved to the
 * corresponding character position of the line corresponding
 * to the n-th following line tabulation stop in the
 * presentation component, where n equals the value of Pn.
 *
 */
#define _CVT_ CSI "Y"

/*
 * DA - DEVICE ATTRIBUTES

 * @ Parameters Required: 
 * Ps

 * @ More Info:
 * With a parameter value not equal to 0, DA is used to identify
 * the device which sends the DA. The parameter value is a
 * device type identification code according to a register
 * which is to be established. If the parameter value is 0,
 * DA is used to request an identifying DA from a device.
 *
 */
#define DA(Ps) CSI #Ps "c"

/*
 * DA - DEVICE ATTRIBUTES

 * @ Parameters Required: 
 * No Parameter Required

 * @ More Info:
 * With a parameter value not equal to 0, DA is used to identify
 * the device which sends the DA. The parameter value is a
 * device type identification code according to a register
 * which is to be established. If the parameter value is 0,
 * DA is used to request an identifying DA from a device.
 *
 */
#define _DA_ CSI "c"

/*
 * DAQ - DEFINE AREA QUALIFICATION

 * @ Parameters Required: 
 * Ps

 * @ More Info:
 * DAQ is used to indicate that the active presentation position
 * in the presentation component is the first character
 * position of a qualified area. The last character position
 * of the qualified area is the character position in the
 * presentation component immediately preceding the first
 * character position of the following qualified area.

 * The parameter value designates the type of qualified area:
 * 0 -> unprotected and unguarded
 * 1 -> protected and guarded
 * 2 -> graphic character input
 * 3 -> numeric input
 * 4 -> alphabetic input
 * 5 -> input aligned on the last character position of the qualified area
 * 6 -> fill with ZEROs
 * 7 -> set a character tabulation stop at the active presentation position
 * (the first character position of the qualified area) to indicate the
 * beginning of a field
 * 8 -> protected and unguarded
 * 9 -> fill with SPACEs
 * 10 -> input aligned on the first character position of the qualified area
 * 11 -> the order of the character positions in the input field is reversed,
 * i.e. the last position in each line becomes the first and vice versa;
 * input begins at the new first position.

 * This control function operates independently of the setting
 * of the TABULATION STOP MODE (TSM). The character
 * tabulation stop set by parameter value 7 applies to the
 * active line only.

 * NOTE
 * The control functions for area definition (DAQ, EPA, ESA, SPA, SSA)
 * should not be used within an SRS string or an SDS string.
 *
 */
#define DAQ(Ps) CSI #Ps "o"

/*
 * DAQ - DEFINE AREA QUALIFICATION

 * @ Parameters Required: 
 * No Parameter Required

 * @ More Info:
 * DAQ is used to indicate that the active presentation position
 * in the presentation component is the first character
 * position of a qualified area. The last character position
 * of the qualified area is the character position in the
 * presentation component immediately preceding the first
 * character position of the following qualified area.

 * The parameter value designates the type of qualified area:
 * 0 -> unprotected and unguarded
 * 1 -> protected and guarded
 * 2 -> graphic character input
 * 3 -> numeric input
 * 4 -> alphabetic input
 * 5 -> input aligned on the last character position of the qualified area
 * 6 -> fill with ZEROs
 * 7 -> set a character tabulation stop at the active presentation position
 * (the first character position of the qualified area) to indicate the
 * beginning of a field
 * 8 -> protected and unguarded
 * 9 -> fill with SPACEs
 * 10 -> input aligned on the first character position of the qualified area
 * 11 -> the order of the character positions in the input field is reversed,
 * i.e. the last position in each line becomes the first and vice versa;
 * input begins at the new first position.

 * This control function operates independently of the setting
 * of the TABULATION STOP MODE (TSM). The character
 * tabulation stop set by parameter value 7 applies to the
 * active line only.

 * NOTE
 * The control functions for area definition (DAQ, EPA, ESA, SPA, SSA)
 * should not be used within an SRS string or an SDS string.
 *
 */
#define _DAQ_ CSI "o"

/*
 * DCH - DELETE CHARACTER

 * @ Parameters Required: 
 * Pn

 * @ More Info:
 * If the DEVICE COMPONENT SELECT MODE (DCSM) is set to PRESENTATION,
 * DCH causes the contents of the active presentation
 * position and, depending on the setting of the CHARACTER
 * EDITING MODE (HEM), the contents of the n-1 preceding or
 * following character positions to be removed from the
 * presentation component, where n equals the value of Pn.
 * The resulting gap is closed by shifting the contents of
 * the adjacent character positions towards the active
 * presentation position. At the other end of the shifted
 * part, n character positions are put into the erased state.

 * The extent of the shifted part is established by SELECT EDITING EXTENT (SEE).

 * The effect of DCH on the start or end of a selected area, the
 * start or end of a qualified area, or a tabulation stop in
 * the shifted part is not defined by this Standard.

 * If the DEVICE COMPONENT SELECT MODE (DCSM) is set to DATA, DCH
 * causes the contents of the active data position and,
 * depending on the setting of the CHARACTER EDITING MODE
 * (HEM), the contents of the n-1 preceding or following
 * character positions to be removed from the data component,
 * where n equals the value of Pn. The resulting gap is
 * closed by shifting the contents of the adjacent character
 * positions towards the active data position. At the other
 * end of the shifted part, n character positions are put into the erased state.
 *
 */
#define DCH(Pn) CSI #Pn "P"

/*
 * DCH - DELETE CHARACTER

 * @ Parameters Required: 
 * No Parameter Required

 * @ More Info:
 * If the DEVICE COMPONENT SELECT MODE (DCSM) is set to PRESENTATION,
 * DCH causes the contents of the active presentation
 * position and, depending on the setting of the CHARACTER
 * EDITING MODE (HEM), the contents of the n-1 preceding or
 * following character positions to be removed from the
 * presentation component, where n equals the value of Pn.
 * The resulting gap is closed by shifting the contents of
 * the adjacent character positions towards the active
 * presentation position. At the other end of the shifted
 * part, n character positions are put into the erased state.

 * The extent of the shifted part is established by SELECT EDITING EXTENT (SEE).

 * The effect of DCH on the start or end of a selected area, the
 * start or end of a qualified area, or a tabulation stop in
 * the shifted part is not defined by this Standard.

 * If the DEVICE COMPONENT SELECT MODE (DCSM) is set to DATA, DCH
 * causes the contents of the active data position and,
 * depending on the setting of the CHARACTER EDITING MODE
 * (HEM), the contents of the n-1 preceding or following
 * character positions to be removed from the data component,
 * where n equals the value of Pn. The resulting gap is
 * closed by shifting the contents of the adjacent character
 * positions towards the active data position. At the other
 * end of the shifted part, n character positions are put into the erased state.
 *
 */
#define _DCH_ CSI "P"

/*
 * DCS - DEVICE CONTROL STRING

 * @ Parameters Required: 
 * No Parameter Required

 * @ More Info:
 * to 07/14. The control string is closed by the terminating
 * delimiter STRING TERMINATOR (ST).

 * The command string represents either one or more commands for
 * the receiving device, or one or more status reports from
 * the sending device. The purpose and the format of the
 * command string are specified by the most recent occurrence
 * of IDENTIFY DEVICE CONTROL STRING (IDCS), if any, or
 * depend on the sending and/or the receiving device.
 *
 */
#define DCS ESC "P"

/*
 * DC1 - DEVICE CONTROL ONE

 * @ Parameters Required: 
 * No Parameter Required

 * @ More Info:
 * DC1 is primarily intended for turning on or starting an ancillary
 * device. If it is not required for this purpose, it may be
 * used to restore a device to the basic mode of operation
 * (see also DC2 and DC3), or any other device control
 * function not provided by other DCs.

 * NOTE
 * When used for data flow control, DC1 is sometimes called "X-ON".
 *
 */
#define DC1 "\x11"

/*
 * DC2 - DEVICE CONTROL TWO

 * @ Parameters Required: 
 * No Parameter Required

 * @ More Info:
 * DC2 is primarily intended for turning on or starting an ancillary
 * device. If it is not required for this purpose, it may be
 * used to set a device to a special mode of operation (in
 * which case DC1 is used to restore the device to the basic
 * mode), or for any other device control function not
 * provided by other DCs.
 *
 */
#define DC2 "\x12"

/*
 * DC3 - DEVICE CONTROL THREE

 * @ Parameters Required: 
 * No Parameter Required

 * @ More Info:
 * DC3 is primarily intended for turning off or stopping an
 * ancillary device. This function may be a secondary level
 * stop, for example wait, pause, stand-by or halt (in which
 * case DC1 is used to restore normal operation). If it is
 * not required for this purpose, it may be used for any
 * other device control function not provided by other DCs.

 * NOTE
 * When used for data flow control, DC3 is sometimes called "X-OFF".
 *
 */
#define DC3 "\x13"

/*
 * DC4 - DEVICE CONTROL FOUR

 * @ Parameters Required: 
 * No Parameter Required

 * @ More Info:
 * DC4 is primarily intended for turning off, stopping or
 * interrupting an ancillary device. If it is not required
 * for this purpose, it may be used for any other device
 * control function not provided by other DCs.
 *
 */
#define DC4 "\x14"

/*
 * DL - DELETE LINE

 * @ Parameters Required: 
 * Pn

 * @ More Info:
 * If the DEVICE COMPONENT SELECT MODE (DCSM) is set to PRESENTATION,
 * DL causes the contents of the active line (the line that
 * contains the active presentation position) and, depending
 * on the setting of the LINE EDITING MODE (VEM), the
 * contents of the n-1 preceding or following lines to be
 * removed from the presentation component, where n equals
 * the value of Pn. The resulting gap is closed by shifting
 * the contents of a number of adjacent lines towards the
 * active line. At the other end of the shifted part, n lines
 * are put into the erased state.

 * The active presentation position is moved to the line home position
 * in the active line. The line home position is established by the
 * parameter value of SET LINE HOME (SLH). If the TABULATION
 * STOP MODE (TSM) is set to SINGLE, character tabulation
 * stops are cleared in the lines that are put into the erased state.

 * The extent of the shifted part is established by SELECT EDITING EXTENT (SEE).

 * Any occurrences of the start or end of a selected area, the
 * start or end of a qualified area, or a tabulation stop in
 * the shifted part, are also shifted.

 * If the DEVICE COMPONENT SELECT MODE (DCSM) is set to DATA, DL
 * causes the contents of the active line (the line that
 * contains the active data position) and, depending on the
 * setting of the LINE EDITING MODE (VEM), the contents of
 * the n-1 preceding or following lines to be removed from
 * the data component, where n equals the value of Pn. The
 * resulting gap is closed by shifting the contents of a
 * number of adjacent lines towards the active line. At the
 * other end of the shifted part, n lines are put into the
 * erased state. The active data position is moved to the
 * line home position in the active line. The line home
 * position is established by the parameter value of SET LINE HOME (SLH).
 *
 */
#define DL(Pn) CSI #Pn "M"

/*
 * DL - DELETE LINE

 * @ Parameters Required: 
 * No Parameter Required

 * @ More Info:
 * If the DEVICE COMPONENT SELECT MODE (DCSM) is set to PRESENTATION,
 * DL causes the contents of the active line (the line that
 * contains the active presentation position) and, depending
 * on the setting of the LINE EDITING MODE (VEM), the
 * contents of the n-1 preceding or following lines to be
 * removed from the presentation component, where n equals
 * the value of Pn. The resulting gap is closed by shifting
 * the contents of a number of adjacent lines towards the
 * active line. At the other end of the shifted part, n lines
 * are put into the erased state.

 * The active presentation position is moved to the line home position
 * in the active line. The line home position is established by the
 * parameter value of SET LINE HOME (SLH). If the TABULATION
 * STOP MODE (TSM) is set to SINGLE, character tabulation
 * stops are cleared in the lines that are put into the erased state.

 * The extent of the shifted part is established by SELECT EDITING EXTENT (SEE).

 * Any occurrences of the start or end of a selected area, the
 * start or end of a qualified area, or a tabulation stop in
 * the shifted part, are also shifted.

 * If the DEVICE COMPONENT SELECT MODE (DCSM) is set to DATA, DL
 * causes the contents of the active line (the line that
 * contains the active data position) and, depending on the
 * setting of the LINE EDITING MODE (VEM), the contents of
 * the n-1 preceding or following lines to be removed from
 * the data component, where n equals the value of Pn. The
 * resulting gap is closed by shifting the contents of a
 * number of adjacent lines towards the active line. At the
 * other end of the shifted part, n lines are put into the
 * erased state. The active data position is moved to the
 * line home position in the active line. The line home
 * position is established by the parameter value of SET LINE HOME (SLH).
 *
 */
#define _DL_ CSI "M"

/*
 * DLE - DATA LINK ESCAPE

 * @ Parameters Required: 
 * No Parameter Required

 * @ More Info:
 * DLE is used exclusively to provide supplementary transmission control functions.

 * The use of DLE is defined in ISO 1745.
 *
 */
#define DLE "\x10"

/*
 * DMI - DISABLE MANUAL INPUT

 * @ Parameters Required: 
 * Fs

 * @ More Info:
 * DMI causes the manual input facilities of a device to be disabled.
 *
 */
#define DMI(Fs) ESC "`"

/*
 * DSR - DEVICE STATUS REPORT

 * @ Parameters Required: 
 * Ps

 * @ More Info:
 * DSR is used either to report the status of the sending device
 * or to request a status report from the receiving device,
 * depending on the parameter values:

 * 0 -> ready, no malfunction detected
 * 1 -> busy, another DSR must be requested later
 * 2 -> busy, another DSR will be sent later
 * 3 -> some malfunction detected, another DSR must be requested later
 * 4 -> some malfunction detected, another DSR will be sent later
 * 5 -> a DSR is requested
 * 6 -> a report of the active presentation position or of the active
 * data position in the form of ACTIVE POSITION REPORT (CPR) is requested

 * DSR with parameter value 0, 1, 2, 3 or 4 may be sent either
 * unsolicited or as a response to a request such as a DSR
 * with a parameter value 5 or MESSAGE WAITING (MW).
 *
 */
#define DSR(Ps) CSI #Ps "n"

/*
 * DSR - DEVICE STATUS REPORT

 * @ Parameters Required: 
 * No Parameter Required

 * @ More Info:
 * DSR is used either to report the status of the sending device
 * or to request a status report from the receiving device,
 * depending on the parameter values:

 * 0 -> ready, no malfunction detected
 * 1 -> busy, another DSR must be requested later
 * 2 -> busy, another DSR will be sent later
 * 3 -> some malfunction detected, another DSR must be requested later
 * 4 -> some malfunction detected, another DSR will be sent later
 * 5 -> a DSR is requested
 * 6 -> a report of the active presentation position or of the active
 * data position in the form of ACTIVE POSITION REPORT (CPR) is requested

 * DSR with parameter value 0, 1, 2, 3 or 4 may be sent either
 * unsolicited or as a response to a request such as a DSR
 * with a parameter value 5 or MESSAGE WAITING (MW).
 *
 */
#define _DSR_ CSI "n"

/*
 * DTA - DIMENSION TEXT AREA

 * @ Parameters Required: 
 * Pn1, Pn2

 * @ More Info:
 * DTA is used to establish the dimensions of the text area for subsequent pages.

 * The established dimensions remain in effect until the next
 * occurrence of DTA in the data stream.

 * Pn1 specifies the dimension in the direction perpendicular to the line orientation
 * Pn2 specifies the dimension in the direction parallel to the line orientation
 * The unit in which the parameter value is expressed is that established
 * by the parameter value of SELECT SIZE UNIT (SSU).
 *
 */
#define DTA(Pn1, Pn2) CSI #Pn1 ";" #Pn2 " " "T"

/*
 * EA - ERASE IN AREA

 * @ Parameters Required: 
 * Ps

 * @ More Info:
 * If the DEVICE COMPONENT SELECT MODE (DCSM) is set to PRESENTATION,
 * EA causes some or all character positions in the active
 * qualified area (the qualified area in the presentation
 * component which contains the active presentation position)
 * to be put into the erased state, depending on the parameter values:

 * 0 -> the active presentation position and the character positions
 * up to the end of the qualified area are put into the erased state
 * 1 -> the character positions from the beginning
 * of the qualified area up to and including the active
 * presentation position are put into the erased state
 * 2 -> all character positions of the qualified area are put into the erased state

 * If the DEVICE COMPONENT SELECT MODE (DCSM) is set to DATA, EA
 * causes some or all character positions in the active
 * qualified area (the qualified area in the data component
 * which contains the active data position) to be put into
 * the erased state, depending on the parameter values:

 * 0 -> the active data position and the character positions up to the
 * end of the qualified area are put into the erased state
 * 1 -> the character positions from the beginning of the qualified
 * area up to and including the active data position are put
 * into the erased state
 * 2 -> all character positions of the qualified area are put into the erased
 * state Whether the character positions of protected areas are put into the
 * erased state, or the character positions of unprotected
 * areas only, depends on the setting of the ERASURE MODE (ERM).
 *
 */
#define EA(Ps) CSI #Ps "O"

/*
 * EA - ERASE IN AREA

 * @ Parameters Required: 
 * No Parameter Required

 * @ More Info:
 * If the DEVICE COMPONENT SELECT MODE (DCSM) is set to PRESENTATION,
 * EA causes some or all character positions in the active
 * qualified area (the qualified area in the presentation
 * component which contains the active presentation position)
 * to be put into the erased state, depending on the parameter values:

 * 0 -> the active presentation position and the character positions
 * up to the end of the qualified area are put into the erased state
 * 1 -> the character positions from the beginning
 * of the qualified area up to and including the active
 * presentation position are put into the erased state
 * 2 -> all character positions of the qualified area are put into the erased state

 * If the DEVICE COMPONENT SELECT MODE (DCSM) is set to DATA, EA
 * causes some or all character positions in the active
 * qualified area (the qualified area in the data component
 * which contains the active data position) to be put into
 * the erased state, depending on the parameter values:

 * 0 -> the active data position and the character positions up to the
 * end of the qualified area are put into the erased state
 * 1 -> the character positions from the beginning of the qualified
 * area up to and including the active data position are put
 * into the erased state
 * 2 -> all character positions of the qualified area are put into the erased
 * state Whether the character positions of protected areas are put into the
 * erased state, or the character positions of unprotected
 * areas only, depends on the setting of the ERASURE MODE (ERM).
 *
 */
#define _EA_ CSI "O"

/*
 * ECH - ERASE CHARACTER

 * @ Parameters Required: 
 * Pn

 * @ More Info:
 * If the DEVICE COMPONENT SELECT MODE (DCSM) is set to PRESENTATION,
 * ECH causes the active presentation position and the n-1
 * following character positions in the presentation
 * component to be put into the erased state, where n equals
 * the value of Pn.

 * If the DEVICE COMPONENT SELECT MODE (DCSM) is set to DATA, ECH
 * causes the active data position and the n-1 following
 * character positions in the data component to be put into
 * the erased state, where n equals the value of Pn.

 * Whether the character positions of protected areas are put into
 * the erased state, or the character positions of
 * unprotected areas only, depends on the setting of the ERASURE MODE (ERM).
 *
 */
#define ECH(Pn) CSI #Pn "X"

/*
 * ECH - ERASE CHARACTER

 * @ Parameters Required: 
 * No Parameter Required

 * @ More Info:
 * If the DEVICE COMPONENT SELECT MODE (DCSM) is set to PRESENTATION,
 * ECH causes the active presentation position and the n-1
 * following character positions in the presentation
 * component to be put into the erased state, where n equals
 * the value of Pn.

 * If the DEVICE COMPONENT SELECT MODE (DCSM) is set to DATA, ECH
 * causes the active data position and the n-1 following
 * character positions in the data component to be put into
 * the erased state, where n equals the value of Pn.

 * Whether the character positions of protected areas are put into
 * the erased state, or the character positions of
 * unprotected areas only, depends on the setting of the ERASURE MODE (ERM).
 *
 */
#define _ECH_ CSI "X"

/*
 * ED - ERASE IN PAGE

 * @ Parameters Required: 
 * Ps

 * @ More Info:
 * If the DEVICE COMPONENT SELECT MODE (DCSM) is set to PRESENTATION,
 * ED causes some or all character positions of the active
 * page (the page which contains the active presentation
 * position in the presentation component) to be put into the
 * erased state, depending on the parameter values:

 * 0 -> the active presentation position and the character positions
 * up to the end of the page are put into the erased state
 * 1 -> the character positions from the beginning of the page up
 * to and including the active presentation position are put
 * into the erased state
 * 2 -> all character positions of the page are put into the erased state

 * If the DEVICE COMPONENT SELECT MODE (DCSM) is set to DATA, ED
 * causes some or all character positions of the active page
 * (the page which contains the active data position in the
 * data component) to be put into the erased state, depending
 * on the parameter values:
 * 0 -> the active data position and the character positions up to the end
 * of the page are put into the erased state
 * 1 -> the character positions from the beginning of the page up to and
 * including the active data position are put into the erased state
 * 2 -> all character positions of the page are put into the erased state

 * Whether the character positions of protected areas are put
 * into the erased state, or the character positions of
 * unprotected areas only, depends on the setting of the ERASURE MODE (ERM).
 *
 */
#define ED(Ps) CSI #Ps "J"

/*
 * ED - ERASE IN PAGE

 * @ Parameters Required: 
 * No Parameter Required

 * @ More Info:
 * If the DEVICE COMPONENT SELECT MODE (DCSM) is set to PRESENTATION,
 * ED causes some or all character positions of the active
 * page (the page which contains the active presentation
 * position in the presentation component) to be put into the
 * erased state, depending on the parameter values:

 * 0 -> the active presentation position and the character positions
 * up to the end of the page are put into the erased state
 * 1 -> the character positions from the beginning of the page up
 * to and including the active presentation position are put
 * into the erased state
 * 2 -> all character positions of the page are put into the erased state

 * If the DEVICE COMPONENT SELECT MODE (DCSM) is set to DATA, ED
 * causes some or all character positions of the active page
 * (the page which contains the active data position in the
 * data component) to be put into the erased state, depending
 * on the parameter values:
 * 0 -> the active data position and the character positions up to the end
 * of the page are put into the erased state
 * 1 -> the character positions from the beginning of the page up to and
 * including the active data position are put into the erased state
 * 2 -> all character positions of the page are put into the erased state

 * Whether the character positions of protected areas are put
 * into the erased state, or the character positions of
 * unprotected areas only, depends on the setting of the ERASURE MODE (ERM).
 *
 */
#define _ED_ CSI "J"

/*
 * EF - ERASE IN FIELD

 * @ Parameters Required: 
 * Ps

 * @ More Info:
 * If the DEVICE COMPONENT SELECT MODE (DCSM) is set to PRESENTATION,
 * EF causes some or all character positions of the active
 * field (the field which contains the active presentation
 * position in the presentation component) to be put into the
 * erased state, depending on the parameter values:

 * 0 -> the active presentation position and the character positions
 * up to the end of the field are put into the erased state
 * 1 -> the character positions from the beginning of the field up
 * to and including the active presentation position are put into the erased state
 * 2 -> all character positions of the field are put into the erased state

 * If the DEVICE COMPONENT SELECT MODE (DCSM) is set to DATA, EF
 * causes some or all character positions of the active field
 * (the field which contains the active data position in the
 * data component) to be put into the erased state, depending
 * on the parameter values:

 * 0 -> the active data position and the character positions up to the end
 * of the field are put into the erased state
 * 1 -> the character positions from the beginning of the field up to and
 * including the active data position are put into the erased state
 * 2 -> all character positions of the field are put into the erased state
 * Whether the character positions of protected areas are put
 * into the erased state, or the character positions of
 * unprotected areas only, depends on the setting of the ERASURE MODE (ERM).
 *
 */
#define EF(Ps) CSI #Ps "N"

/*
 * EF - ERASE IN FIELD

 * @ Parameters Required: 
 * No Parameter Required

 * @ More Info:
 * If the DEVICE COMPONENT SELECT MODE (DCSM) is set to PRESENTATION,
 * EF causes some or all character positions of the active
 * field (the field which contains the active presentation
 * position in the presentation component) to be put into the
 * erased state, depending on the parameter values:

 * 0 -> the active presentation position and the character positions
 * up to the end of the field are put into the erased state
 * 1 -> the character positions from the beginning of the field up
 * to and including the active presentation position are put into the erased state
 * 2 -> all character positions of the field are put into the erased state

 * If the DEVICE COMPONENT SELECT MODE (DCSM) is set to DATA, EF
 * causes some or all character positions of the active field
 * (the field which contains the active data position in the
 * data component) to be put into the erased state, depending
 * on the parameter values:

 * 0 -> the active data position and the character positions up to the end
 * of the field are put into the erased state
 * 1 -> the character positions from the beginning of the field up to and
 * including the active data position are put into the erased state
 * 2 -> all character positions of the field are put into the erased state
 * Whether the character positions of protected areas are put
 * into the erased state, or the character positions of
 * unprotected areas only, depends on the setting of the ERASURE MODE (ERM).
 *
 */
#define _EF_ CSI "N"

/*
 * EL - ERASE IN LINE

 * @ Parameters Required: 
 * Ps

 * @ More Info:
 * If the DEVICE COMPONENT SELECT MODE (DCSM) is set to PRESENTATION,
 * EL causes some or all character positions of the active
 * line (the line which contains the active presentation
 * position in the presentation component) to be put into the
 * erased state, depending on the parameter values:

 * 0 -> the active presentation position and the character positions
 * up to the end of the line are put into the erased state
 * 1 -> the character positions from the beginning of the line up to and
 * including the active presentation position are put into the erased state
 * 2 -> all character positions of the line are put into the erased state

 * If the DEVICE COMPONENT SELECT MODE (DCSM) is set to DATA, EL
 * causes some or all character positions of the active line
 * (the line which contains the active data position in the
 * data component) to be put into the erased state, depending
 * on the parameter values:

 * 0 -> the active data position and the character positions up to the end
 * of the line are put into the erased state
 * 1 -> the character positions from the beginning of the line up to and
 * including the active data position are put into the erased state
 * 2 -> all character positions of the line are put into the erased state

 * Whether the character positions of protected areas are put
 * into the erased state, or the character positions of
 * unprotected areas only, depends on the setting of the ERASURE MODE (ERM).
 *
 */
#define EL(Ps) CSI #Ps "K"

/*
 * EL - ERASE IN LINE

 * @ Parameters Required: 
 * No Parameter Required

 * @ More Info:
 * If the DEVICE COMPONENT SELECT MODE (DCSM) is set to PRESENTATION,
 * EL causes some or all character positions of the active
 * line (the line which contains the active presentation
 * position in the presentation component) to be put into the
 * erased state, depending on the parameter values:

 * 0 -> the active presentation position and the character positions
 * up to the end of the line are put into the erased state
 * 1 -> the character positions from the beginning of the line up to and
 * including the active presentation position are put into the erased state
 * 2 -> all character positions of the line are put into the erased state

 * If the DEVICE COMPONENT SELECT MODE (DCSM) is set to DATA, EL
 * causes some or all character positions of the active line
 * (the line which contains the active data position in the
 * data component) to be put into the erased state, depending
 * on the parameter values:

 * 0 -> the active data position and the character positions up to the end
 * of the line are put into the erased state
 * 1 -> the character positions from the beginning of the line up to and
 * including the active data position are put into the erased state
 * 2 -> all character positions of the line are put into the erased state

 * Whether the character positions of protected areas are put
 * into the erased state, or the character positions of
 * unprotected areas only, depends on the setting of the ERASURE MODE (ERM).
 *
 */
#define _EL_ CSI "K"

/*
 * EM - END OF MEDIUM

 * @ Parameters Required: 
 * No Parameter Required

 * @ More Info:
 * EM is used to identify the physical end of a medium, or the
 * end of the used portion of a medium, or the end of the
 * wanted portion of data recorded on a medium.
 *
 */
#define EM "\x19"

/*
 * EMI - ENABLE MANUAL INPUT

 * @ Parameters Required: 
 * Fs

 * @ More Info:
 * EMI is used to enable the manual input facilities of a device.
 *
 */
#define EMI(Fs) ESC "b"

/*
 * ENQ - ENQUIRY

 * @ Parameters Required: 
 * No Parameter Required

 * @ More Info:
 * ENQ is transmitted by a sender as a request for a response from a receiver.

 * The use of ENQ is defined in ISO 1745.
 *
 */
#define ENQ "\x05"

/*
 * EOT - END OF TRANSMISSION

 * @ Parameters Required: 
 * No Parameter Required

 * @ More Info:
 * EOT is used to indicate the conclusion of the transmission of
 * one or more texts.

 * The use of EOT is defined in ISO 1745.
 *
 */
#define EOT "\x04"

/*
 * EPA - END OF GUARDED AREA

 * @ Parameters Required: 
 * No Parameter Required

 * @ More Info:
 * EPA is used to indicate that the active presentation position
 * is the last of a string of character positions in the
 * presentation component, the contents of which are
 * protected against manual alteration, are guarded against
 * transmission or transfer, depending on the setting of the
 * GUARDED AREA TRANSFER MODE (GATM), and may be protected
 * against erasure, depending on the setting of the ERASURE
 * MODE (ERM). The beginning of this string is indicated by
 * START OF GUARDED AREA (SPA).

 * NOTE
 * The control functions for area definition (DAQ, EPA, ESA,
 * SPA, SSA) should not be used within an SRS string or an SDS string.
 *
 */
#define EPA ESC "W"

/*
 * ESA - END OF SELECTED AREA

 * @ Parameters Required: 
 * No Parameter Required

 * @ More Info:
 * ESA is used to indicate that the active presentation position
 * is the last of a string of character positions in the
 * presentation component, the contents of which are eligible
 * to be transmitted in the form of a data stream or
 * transferred to an auxiliary input/output device. The
 * beginning of this string is indicated by START OF SELECTED AREA (SSA).

 * NOTE
 * The control function for area definition (DAQ, EPA, ESA,
 * SPA, SSA) should not be used within an SRS string or an SDS string.
 *
 */
#define ESA ESC "G"

/*
 * ETB - END OF TRANSMISSION BLOCK

 * @ Parameters Required: 
 * No Parameter Required

 * @ More Info:
 * ETB is used to indicate the end of a block of data where the
 * data are divided into such blocks for transmission purposes.

 * The use of ETB is defined in ISO 1745.
 *
 */
#define ETB "\x17"

/*
 * ETX - END OF TEXT

 * @ Parameters Required: 
 * No Parameter Required

 * @ More Info:
 * ETX is used to indicate the end of a text.

 * The use of ETX is defined in ISO 1745.
 *
 */
#define ETX "\x03"

/*
 * FF - FORM FEED

 * @ Parameters Required: 
 * No Parameter Required

 * @ More Info:
 * FF causes the active presentation position to be moved to the
 * corresponding character position of the line at the page
 * home position of the next form or page in the presentation
 * component. The page home position is established by the
 * parameter value of SET PAGE HOME (SPH).
 *
 */
#define FF "\x0c"

/*
 * FNK - FUNCTION KEY

 * @ Parameters Required: 
 * Pn

 * @ More Info:
 * No parameter default value.

 * FNK is a control function in which the parameter value identifies
 * the function key which has been operated.
 *
 */
#define FNK(Pn) CSI #Pn " " "W"

/*
 * FNT - FONT SELECTION

 * @ Parameters Required: 
 * Ps1, Ps2

 * @ More Info:
 * FNT is used to identify the character font to be selected as
 * primary or alternative font by subsequent occurrences of
 * SELECT GRAPHIC RENDITION (SGR) in the data stream. Ps1 specifies the primary
 * or alternative font concerned:

 * 0 primary font
 * 1 first alternative font
 * 2 second alternative font
 * 3 third alternative font
 * 4 fourth alternative font
 * 5 fifth alternative font
 * 6 sixth alternative font
 * 7 seventh alternative font
 * 8 eighth alternative font
 * 9 ninth alternative font

 * Ps2 identifies the character font according to a register which
 * is to be established.
 *
 */
#define FNT(Ps1, Ps2) CSI #Ps1 ";" #Ps2 " " "D"

/*
 * FNT - FONT SELECTION

 * @ Parameters Required: 
 * Ps1

 * @ More Info:
 * FNT is used to identify the character font to be selected as
 * primary or alternative font by subsequent occurrences of
 * SELECT GRAPHIC RENDITION (SGR) in the data stream. Ps1 specifies the primary
 * or alternative font concerned:

 * 0 primary font
 * 1 first alternative font
 * 2 second alternative font
 * 3 third alternative font
 * 4 fourth alternative font
 * 5 fifth alternative font
 * 6 sixth alternative font
 * 7 seventh alternative font
 * 8 eighth alternative font
 * 9 ninth alternative font

 * Ps2 identifies the character font according to a register which
 * is to be established.
 *
 */
#define _FNT(Ps1) CSI #Ps1 ";" " " "D"

/*
 * FNT - FONT SELECTION

 * @ Parameters Required: 
 * Ps2

 * @ More Info:
 * FNT is used to identify the character font to be selected as
 * primary or alternative font by subsequent occurrences of
 * SELECT GRAPHIC RENDITION (SGR) in the data stream. Ps1 specifies the primary
 * or alternative font concerned:

 * 0 primary font
 * 1 first alternative font
 * 2 second alternative font
 * 3 third alternative font
 * 4 fourth alternative font
 * 5 fifth alternative font
 * 6 sixth alternative font
 * 7 seventh alternative font
 * 8 eighth alternative font
 * 9 ninth alternative font

 * Ps2 identifies the character font according to a register which
 * is to be established.
 *
 */
#define __FNT(Ps2) CSI ";" #Ps2 " " "D"

/*
 * FNT - FONT SELECTION

 * @ Parameters Required: 
 * No Parameter Required

 * @ More Info:
 * FNT is used to identify the character font to be selected as
 * primary or alternative font by subsequent occurrences of
 * SELECT GRAPHIC RENDITION (SGR) in the data stream. Ps1 specifies the primary
 * or alternative font concerned:

 * 0 primary font
 * 1 first alternative font
 * 2 second alternative font
 * 3 third alternative font
 * 4 fourth alternative font
 * 5 fifth alternative font
 * 6 sixth alternative font
 * 7 seventh alternative font
 * 8 eighth alternative font
 * 9 ninth alternative font

 * Ps2 identifies the character font according to a register which
 * is to be established.
 *
 */
#define _FNT_ CSI ";" " " "D"

/*
 * GCC - GRAPHIC CHARACTER COMBINATION

 * @ Parameters Required: 
 * Ps

 * @ More Info:
 * GCC is used to indicate that two or more graphic characters
 * are to be imaged as one single graphic symbol. GCC with a
 * parameter value of 0 indicates that the following two
 * graphic characters are to be imaged as one single graphic
 * symbol; GCC with a parameter value of 1 and GCC with a
 * parameter value of 2 indicate respectively the beginning
 * and the end of a string of graphic characters which are to
 * be imaged as one single graphic symbol.

 * NOTE
 * GCC does not explicitly specify the relative sizes or
 * placements of the component parts of a composite graphic
 * symbol. In the simplest case, two components may be
 * "half-width" and side-by-side. For example, in Japanese text a pair of
 * characters may be presented side-by-side, and occupy the space of a
 * normal-size Kanji character.
 *
 */
#define GCC(Ps) CSI #Ps " " "_"

/*
 * GCC - GRAPHIC CHARACTER COMBINATION

 * @ Parameters Required: 
 * No Parameter Required

 * @ More Info:
 * GCC is used to indicate that two or more graphic characters
 * are to be imaged as one single graphic symbol. GCC with a
 * parameter value of 0 indicates that the following two
 * graphic characters are to be imaged as one single graphic
 * symbol; GCC with a parameter value of 1 and GCC with a
 * parameter value of 2 indicate respectively the beginning
 * and the end of a string of graphic characters which are to
 * be imaged as one single graphic symbol.

 * NOTE
 * GCC does not explicitly specify the relative sizes or
 * placements of the component parts of a composite graphic
 * symbol. In the simplest case, two components may be
 * "half-width" and side-by-side. For example, in Japanese text a pair of
 * characters may be presented side-by-side, and occupy the space of a
 * normal-size Kanji character.
 *
 */
#define _GCC_ CSI " " "_"

/*
 * GSM - GRAPHIC SIZE MODIFICATION

 * @ Parameters Required: 
 * Pn1, Pn2

 * @ More Info:
 * GSM is used to modify for subsequent text the height and/or
 * the width of all primary and alternative fonts identified
 * by FONT SELECTION (FNT) and established by GRAPHIC SIZE
 * SELECTION (GSS). The established values remain in effect
 * until the next occurrence of GSM or GSS in the data steam.

 * Pn1 specifies the height as a percentage of the height established by GSS
 * Pn2 specifies the width as a percentage of the width established by GSS
 *
 */
#define GSM(Pn1, Pn2) CSI #Pn1 ";" #Pn2 " " "B"

/*
 * GSM - GRAPHIC SIZE MODIFICATION

 * @ Parameters Required: 
 * Pn1

 * @ More Info:
 * GSM is used to modify for subsequent text the height and/or
 * the width of all primary and alternative fonts identified
 * by FONT SELECTION (FNT) and established by GRAPHIC SIZE
 * SELECTION (GSS). The established values remain in effect
 * until the next occurrence of GSM or GSS in the data steam.

 * Pn1 specifies the height as a percentage of the height established by GSS
 * Pn2 specifies the width as a percentage of the width established by GSS
 *
 */
#define _GSM(Pn1) CSI #Pn1 ";" " " "B"

/*
 * GSM - GRAPHIC SIZE MODIFICATION

 * @ Parameters Required: 
 * Pn2

 * @ More Info:
 * GSM is used to modify for subsequent text the height and/or
 * the width of all primary and alternative fonts identified
 * by FONT SELECTION (FNT) and established by GRAPHIC SIZE
 * SELECTION (GSS). The established values remain in effect
 * until the next occurrence of GSM or GSS in the data steam.

 * Pn1 specifies the height as a percentage of the height established by GSS
 * Pn2 specifies the width as a percentage of the width established by GSS
 *
 */
#define __GSM(Pn2) CSI ";" #Pn2 " " "B"

/*
 * GSM - GRAPHIC SIZE MODIFICATION

 * @ Parameters Required: 
 * No Parameter Required

 * @ More Info:
 * GSM is used to modify for subsequent text the height and/or
 * the width of all primary and alternative fonts identified
 * by FONT SELECTION (FNT) and established by GRAPHIC SIZE
 * SELECTION (GSS). The established values remain in effect
 * until the next occurrence of GSM or GSS in the data steam.

 * Pn1 specifies the height as a percentage of the height established by GSS
 * Pn2 specifies the width as a percentage of the width established by GSS
 *
 */
#define _GSM_ CSI ";" " " "B"

/*
 * GSS - GRAPHIC SIZE SELECTION

 * @ Parameters Required: 
 * Pn

 * @ More Info:
 * No parameter default value.

 * GSS is used to establish for subsequent text the height and
 * the width of all primary and alternative fonts identified
 * by FONT SELECTION (FNT). The established values remain in
 * effect until the next occurrence of GSS in the data stream.

 * Pn specifies the height, the width is implicitly defined by
 * the height.

 * The unit in which the parameter value is expressed is that
 * established by the parameter value of SELECT SIZE UNIT (SSU).
 *
 */
#define GSS(Pn) CSI #Pn " " "C"

/*
 * HPA - CHARACTER POSITION ABSOLUTE

 * @ Parameters Required: 
 * Pn

 * @ More Info:
 * HPA causes the active data position to be moved to character
 * position n in the active line (the line in the data
 * component that contains the active data position), where n
 * equals the value of Pn.
 *
 */
#define HPA(Pn) CSI #Pn "`"

/*
 * HPA - CHARACTER POSITION ABSOLUTE

 * @ Parameters Required: 
 * No Parameter Required

 * @ More Info:
 * HPA causes the active data position to be moved to character
 * position n in the active line (the line in the data
 * component that contains the active data position), where n
 * equals the value of Pn.
 *
 */
#define _HPA_ CSI "`"

/*
 * HPB - CHARACTER POSITION BACKWARD

 * @ Parameters Required: 
 * Pn

 * @ More Info:
 * HPB causes the active data position to be moved by n character
 * positions in the data component in the direction opposite
 * to that of the character progression, where n equals the
 * value of Pn.
 *
 */
#define HPB(Pn) CSI #Pn "j"

/*
 * HPB - CHARACTER POSITION BACKWARD

 * @ Parameters Required: 
 * No Parameter Required

 * @ More Info:
 * HPB causes the active data position to be moved by n character
 * positions in the data component in the direction opposite
 * to that of the character progression, where n equals the
 * value of Pn.
 *
 */
#define _HPB_ CSI "j"

/*
 * HPR - CHARACTER POSITION FORWARD

 * @ Parameters Required: 
 * Pn

 * @ More Info:
 * HPR causes the active data position to be moved by n character
 * positions in the data component in the direction of the
 * character progression, where n equals the value of Pn.
 *
 */
#define HPR(Pn) CSI #Pn "a"

/*
 * HPR - CHARACTER POSITION FORWARD

 * @ Parameters Required: 
 * No Parameter Required

 * @ More Info:
 * HPR causes the active data position to be moved by n character
 * positions in the data component in the direction of the
 * character progression, where n equals the value of Pn.
 *
 */
#define _HPR_ CSI "a"

/*
 * HT - CHARACTER TABULATION

 * @ Parameters Required: 
 * No Parameter Required

 * @ More Info:
 * HT causes the active presentation position to be moved to the
 * following character tabulation stop in the presentation component.

 * In addition, if that following character tabulation stop has
 * been set by TABULATION ALIGN CENTRE (TAC), TABULATION
 * ALIGN LEADING EDGE (TALE), TABULATION ALIGN TRAILING EDGE
 * (TATE) or TABULATION CENTRED ON CHARACTER (TCC), HT
 * indicates the beginning of a string of text which is to be
 * positioned within a line according to the properties of
 * that tabulation stop. The end of the string is indicated
 * by the next occurrence of HT or CARRIAGE RETURN (CR) or
 * NEXT LINE (NEL) in the data stream.
 *
 */
#define HT "\t"

/*
 * HTJ - CHARACTER TABULATION WITH JUSTIFICATION

 * @ Parameters Required: 
 * No Parameter Required

 * @ More Info:
 * HTJ causes the contents of the active field (the field in the
 * presentation component that contains the active
 * presentation position) to be shifted forward so that it
 * ends at the character position preceding the following
 * character tabulation stop. The active presentation
 * position is moved to that following character tabulation
 * stop. The character positions which precede the beginning
 * of the shifted string are put into the erased state.
 *
 */
#define HTJ ESC "I"

/*
 * HTS - CHARACTER TABULATION SET

 * @ Parameters Required: 
 * No Parameter Required

 * @ More Info:
 * HTS causes a character tabulation stop to be set at the active
 * presentation position in the presentation component.

 * The number of lines affected depends on the setting of the
 * TABULATION STOP MODE (TSM).
 *
 */
#define HTS ESC "H"

/*
 * HVP - CHARACTER AND LINE POSITION

 * @ Parameters Required: 
 * Pn1, Pn2

 * @ More Info:
 * HVP causes the active data position to be moved in the data
 * component to the n-th line position according to the line
 * progression and to the m-th character position according
 * to the character progression, where n equals the value of
 * Pn1 and m equals the value of Pn2.
 *
 */
#define HVP(Pn1, Pn2) CSI #Pn1 ";" #Pn2 "f"

/*
 * HVP - CHARACTER AND LINE POSITION

 * @ Parameters Required: 
 * Pn1

 * @ More Info:
 * HVP causes the active data position to be moved in the data
 * component to the n-th line position according to the line
 * progression and to the m-th character position according
 * to the character progression, where n equals the value of
 * Pn1 and m equals the value of Pn2.
 *
 */
#define _HVP(Pn1) CSI #Pn1 ";" "f"

/*
 * HVP - CHARACTER AND LINE POSITION

 * @ Parameters Required: 
 * Pn2

 * @ More Info:
 * HVP causes the active data position to be moved in the data
 * component to the n-th line position according to the line
 * progression and to the m-th character position according
 * to the character progression, where n equals the value of
 * Pn1 and m equals the value of Pn2.
 *
 */
#define __HVP(Pn2) CSI ";" #Pn2 "f"

/*
 * HVP - CHARACTER AND LINE POSITION

 * @ Parameters Required: 
 * No Parameter Required

 * @ More Info:
 * HVP causes the active data position to be moved in the data
 * component to the n-th line position according to the line
 * progression and to the m-th character position according
 * to the character progression, where n equals the value of
 * Pn1 and m equals the value of Pn2.
 *
 */
#define _HVP_ CSI ";" "f"

/*
 * ICH - INSERT CHARACTER

 * @ Parameters Required: 
 * Pn

 * @ More Info:
 * If the DEVICE COMPONENT SELECT MODE (DCSM) is set to PRESENTATION,
 * ICH is used to prepare the insertion of n characters, by
 * putting into the erased state the active presentation
 * position and, depending on the setting of the CHARACTER
 * EDITING MODE (HEM), the n-1 preceding or following
 * character positions in the presentation component, where n
 * equals the value of Pn. The previous contents of the
 * active presentation position and an adjacent string of
 * character positions are shifted away from the active
 * presentation position. The contents of n character
 * positions at the other end of the shifted part are
 * removed. The active presentation position is moved to the
 * line home position in the active line. The line home
 * position is established by the parameter value of SET LINE HOME (SLH).

 * The extent of the shifted part is established by
 * SELECT EDITING EXTENT (SEE).

 * The effect of ICH on the start or end of a selected area, the
 * start or end of a qualified area, or a tabulation stop in
 * the shifted part, is not defined by this Standard.

 * If the DEVICE COMPONENT SELECT MODE (DCSM) is set to DATA, ICH
 * is used to prepare the insertion of n characters, by
 * putting into the erased state the active data position
 * and, depending on the setting of the CHARACTER EDITING
 * MODE (HEM), the n-1 preceding or following character
 * positions in the data component, where n equals the value
 * of Pn. The previous contents of the active data position
 * and an adjacent string of character positions are shifted
 * away from the active data position. The contents of n
 * character positions at the other end of the shifted part are
 * removed. The active data position is moved to the line home position
 * in the active line. The line home position is established by the
 * parameter value of SET LINE HOME (SLH).
 *
 */
#define ICH(Pn) CSI #Pn "@"

/*
 * ICH - INSERT CHARACTER

 * @ Parameters Required: 
 * No Parameter Required

 * @ More Info:
 * If the DEVICE COMPONENT SELECT MODE (DCSM) is set to PRESENTATION,
 * ICH is used to prepare the insertion of n characters, by
 * putting into the erased state the active presentation
 * position and, depending on the setting of the CHARACTER
 * EDITING MODE (HEM), the n-1 preceding or following
 * character positions in the presentation component, where n
 * equals the value of Pn. The previous contents of the
 * active presentation position and an adjacent string of
 * character positions are shifted away from the active
 * presentation position. The contents of n character
 * positions at the other end of the shifted part are
 * removed. The active presentation position is moved to the
 * line home position in the active line. The line home
 * position is established by the parameter value of SET LINE HOME (SLH).

 * The extent of the shifted part is established by
 * SELECT EDITING EXTENT (SEE).

 * The effect of ICH on the start or end of a selected area, the
 * start or end of a qualified area, or a tabulation stop in
 * the shifted part, is not defined by this Standard.

 * If the DEVICE COMPONENT SELECT MODE (DCSM) is set to DATA, ICH
 * is used to prepare the insertion of n characters, by
 * putting into the erased state the active data position
 * and, depending on the setting of the CHARACTER EDITING
 * MODE (HEM), the n-1 preceding or following character
 * positions in the data component, where n equals the value
 * of Pn. The previous contents of the active data position
 * and an adjacent string of character positions are shifted
 * away from the active data position. The contents of n
 * character positions at the other end of the shifted part are
 * removed. The active data position is moved to the line home position
 * in the active line. The line home position is established by the
 * parameter value of SET LINE HOME (SLH).
 *
 */
#define _ICH_ CSI "@"

/*
 * IDCS - IDENTIFY DEVICE CONTROL STRING

 * @ Parameters Required: 
 * Ps

 * @ More Info:
 * No parameter default value.

 * IDCS is used to specify the purpose and format of the command
 * string of subsequent DEVICE CONTROL STRINGs (DCS). The
 * specified purpose and format remain in effect until the
 * next occurrence of IDCS in the data stream.

 * The parameter values are:

 * 1 -> reserved for use with the DIAGNOSTIC state of the STATUS
 * REPORT TRANSFER MODE (SRTM).
 * 2 -> reserved for Dynamically Redefinable Character Sets (DRCS)
 * according to Standard ECMA-35.

 * The format and interpretation of the command string corresponding
 * to these parameter values are to be defined in appropriate standards.
 * If this control function is used to identify a private command
 * string, a private parameter value shall be used.
 *
 */
#define IDCS(Ps) CSI #Ps " " "O"

/*
 * IGS - IDENTIFY GRAPHIC SUBREPERTOIRE

 * @ Parameters Required: 
 * Ps

 * @ More Info:
 * No parameter default value. IGS is used to indicate that a
 * repertoire of the graphic characters of ISO/IEC 10367 is
 * used in the subsequent text.

 * The parameter value of IGS identifies a graphic character
 * repertoire registered in accordance with ISO/IEC 7350.
 *
 */
#define IGS(Ps) CSI #Ps " " "M"

/*
 * IL - INSERT LINE

 * @ Parameters Required: 
 * Pn

 * @ More Info:
 * If the DEVICE COMPONENT SELECT MODE (DCSM) is set to PRESENTATION,
 * IL is used to prepare the insertion of n lines, by putting
 * into the erased state in the presentation component the
 * active line (the line that contains the active
 * presentation position) and, depending on the setting of
 * the LINE EDITING MODE (VEM), the n-1 preceding or
 * following lines, where n equals the value of Pn. The
 * previous contents of the active line and of adjacent lines
 * are shifted away from the active line. The contents of n
 * lines at the other end of the shifted part are removed.
 * The active presentation position is moved to the line home
 * position in the active line. The line home position is
 * established by the parameter value of SET LINE HOME (SLH).

 * The extent of the shifted part is established by SELECT EDITING EXTENT (SEE).

 * Any occurrences of the start or end of a selected area, the
 * start or end of a qualified area, or a tabulation stop in
 * the shifted part, are also shifted.

 * If the TABULATION STOP MODE (TSM) is set to SINGLE, character
 * tabulation stops are cleared in the lines that are put into the erased state.

 * If the DEVICE COMPONENT SELECT MODE (DCSM) is set to DATA,
 * IL is used to prepare the insertion of n lines, by putting
 * into the erased state in the data component the active line
 * (the line that contains the active data position) and,
 * depending on the setting of the LINE EDITING MODE (VEM),
 * the n-1 preceding or following lines, where n equals the
 * value of Pn. The previous contents of the active line and of
 * adjacent lines are shifted away from the active line. The
 * contents of n lines at the other end of the shifted part are
 * removed. The active data position is moved to the line home
 * position in the active line. The line home position is established
 * by the parameter value of SET LINE HOME (SLH).
 *
 */
#define IL(Pn) CSI #Pn "L"

/*
 * IL - INSERT LINE

 * @ Parameters Required: 
 * No Parameter Required

 * @ More Info:
 * If the DEVICE COMPONENT SELECT MODE (DCSM) is set to PRESENTATION,
 * IL is used to prepare the insertion of n lines, by putting
 * into the erased state in the presentation component the
 * active line (the line that contains the active
 * presentation position) and, depending on the setting of
 * the LINE EDITING MODE (VEM), the n-1 preceding or
 * following lines, where n equals the value of Pn. The
 * previous contents of the active line and of adjacent lines
 * are shifted away from the active line. The contents of n
 * lines at the other end of the shifted part are removed.
 * The active presentation position is moved to the line home
 * position in the active line. The line home position is
 * established by the parameter value of SET LINE HOME (SLH).

 * The extent of the shifted part is established by SELECT EDITING EXTENT (SEE).

 * Any occurrences of the start or end of a selected area, the
 * start or end of a qualified area, or a tabulation stop in
 * the shifted part, are also shifted.

 * If the TABULATION STOP MODE (TSM) is set to SINGLE, character
 * tabulation stops are cleared in the lines that are put into the erased state.

 * If the DEVICE COMPONENT SELECT MODE (DCSM) is set to DATA,
 * IL is used to prepare the insertion of n lines, by putting
 * into the erased state in the data component the active line
 * (the line that contains the active data position) and,
 * depending on the setting of the LINE EDITING MODE (VEM),
 * the n-1 preceding or following lines, where n equals the
 * value of Pn. The previous contents of the active line and of
 * adjacent lines are shifted away from the active line. The
 * contents of n lines at the other end of the shifted part are
 * removed. The active data position is moved to the line home
 * position in the active line. The line home position is established
 * by the parameter value of SET LINE HOME (SLH).
 *
 */
#define _IL_ CSI "L"

/*
 * INT - INTERRUPT

 * @ Parameters Required: 
 * Fs

 * @ More Info:
 * INT is used to indicate to the receiving device that the current
 * process is to be interrupted and an agreed procedure is to
 * be initiated. This control function is applicable to
 * either direction of transmission.
 *
 */
#define INT(Fs) ESC "a"

/*
 * IS1 - INFORMATION SEPARATOR ONE (US - UNIT SEPARATOR)

 * @ Parameters Required:
 * No Parameter Required

 * @ More Info:
 * IS1 is used to separate and qualify data logically; its specific
 * meaning has to be defined for each application. If this
 * control function is used in hierarchical order, it may
 * delimit a data item called a unit, see 8.2.10.
 *
 */
#define IS1 "\x1f"

/*
 * IS2 - INFORMATION SEPARATOR TWO (RS - RECORD SEPARATOR)

 * @ Parameters Required:
 * No Parameter Required

 * @ More Info:
 * IS2 is used to separate and qualify data logically; its specific
 * meaning has to be defined for each application. If this
 * control function is used in hierarchical order, it may
 * delimit a data item called a record, see 8.2.10.
 *
 */
#define IS2 "\x1e"

/*
 * IS3 - INFORMATION SEPARATOR THREE (GS - GROUP SEPARATOR)

 * @ Parameters Required: 
 * No Parameter Required

 * @ More Info:
 * IS3 is used to separate and qualify data logically; its specific
 * meaning has to be defined for each application. If this
 * control function is used in hierarchical order, it may
 * delimit a data item called a group, see 8.2.10.
 *
 */
#define IS3 "\x1d"

/*
 * IS4 - INFORMATION SEPARATOR FOUR (FS - FILE SEPARATOR)

 * @ Parameters Required: 
 * No Parameter Required

 * @ More Info:
 * IS4 is used to separate and qualify data logically; its specific
 * meaning has to be defined for each application. If this
 * control function is used in hierarchical order, it may
 * delimit a data item called a file, see 8.2.10.
 *
 */
#define IS4 "\x1c"

/*
 * JFY - JUSTIFY

 * @ Parameters Required: 
 * Ps

 * @ More Info:
 * JFY is used to indicate the beginning of a string of graphic
 * characters in the presentation component that are to be
 * justified according to the layout specified by the
 * parameter values, see annex C:

 * 0 -> no justification, end of justification of preceding text
 * 1 -> word fill
 * 2 -> word space
 * 3 -> letter space
 * 4 -> hyphenation
 * 5 -> flush to line home position margin
 * 6 -> centre between line home position and line limit position margins
 * 7 -> flush to line limit position margin
 * 8 -> Italian hyphenation

 * The end of the string to be justified is indicated by the next
 * occurrence of JFY in the data stream.

 * The line home position is established by the parameter value
 * of SET LINE HOME (SLH). The line limit position is
 * established by the parameter value of SET LINE LIMIT (SLL).
 *
 */
#define JFY(Ps) CSI #Ps " " "F"

/*
 * JFY - JUSTIFY

 * @ Parameters Required: 
 * No Parameter Required

 * @ More Info:
 * JFY is used to indicate the beginning of a string of graphic
 * characters in the presentation component that are to be
 * justified according to the layout specified by the
 * parameter values, see annex C:

 * 0 -> no justification, end of justification of preceding text
 * 1 -> word fill
 * 2 -> word space
 * 3 -> letter space
 * 4 -> hyphenation
 * 5 -> flush to line home position margin
 * 6 -> centre between line home position and line limit position margins
 * 7 -> flush to line limit position margin
 * 8 -> Italian hyphenation

 * The end of the string to be justified is indicated by the next
 * occurrence of JFY in the data stream.

 * The line home position is established by the parameter value
 * of SET LINE HOME (SLH). The line limit position is
 * established by the parameter value of SET LINE LIMIT (SLL).
 *
 */
#define _JFY_ CSI " " "F"

/*
 * LF - LINE FEED

 * @ Parameters Required: 
 * No Parameter Required

 * @ More Info:
 * If the DEVICE COMPONENT SELECT MODE (DCSM) is set to PRESENTATION,
 * LF causes the active presentation position to be moved to
 * the corresponding character position of the following line
 * in the presentation component.

 * If the DEVICE COMPONENT SELECT MODE (DCSM) is set to DATA,
 * LF causes the active data position to be moved to the corresponding character
 * position of the following line in the data component.
 *
 */
#define LF "\n"

/*
 * LS0 - LOCKING-SHIFT ZERO

 * @ Parameters Required: 
 * No Parameter Required

 * @ More Info:
 * LS0 is used for code extension purposes. It causes the meanings
 * of the bit combinations following it in the data stream to be changed.

 * The use of LS0 is defined in Standard ECMA-35.

 * NOTE
 * LS0 is used in 8-bit environments only; in 7-bit environments
 * SHIFT-IN (SI) is used instead.
 *
 */
#define LS0 "\x0f"

/*
 * LS1 - LOCKING-SHIFT ONE

 * @ Parameters Required: 
 * No Parameter Required

 * @ More Info:
 * LS1 is used for code extension purposes. It causes the meanings
 * of the bit combinations following it in the data stream to be changed.

 * The use of LS1 is defined in Standard ECMA-35.

 * NOTE
 * LS1 is used in 8-bit environments only; in 7-bit environments
 * SHIFT-OUT (SO) is used instead.
 *
 */
#define LS1 "\x0e"

/*
 * LS1R - LOCKING-SHIFT ONE RIGHT

 * @ Parameters Required: 
 * Fs

 * @ More Info:
 * LS1R is used for code extension purposes. It causes the meanings
 * of the bit combinations following it in the data stream to be changed.

 * The use of LS1R is defined in Standard ECMA-35.
 *
 */
#define LS1R(Fs) ESC "~"

/*
 * LS2 - LOCKING-SHIFT TWO

 * @ Parameters Required: 
 * Fs

 * @ More Info:
 * LS2 is used for code extension purposes. It causes the meanings
 * of the bit combinations following it in the data stream to be changed.

 * The use of LS2 is defined in Standard ECMA-35.
 *
 */
#define LS2(Fs) ESC "n"

/*
 * LS2R - LOCKING-SHIFT TWO RIGHT

 * @ Parameters Required: 
 * Fs

 * @ More Info:
 * LS2R is used for code extension purposes. It causes the meanings
 * of the bit combinations following it in the data stream to be changed.

 * The use of LS2R is defined in Standard ECMA-35.
 *
 */
#define LS2R(Fs) ESC "}"

/*
 * LS3 - LOCKING-SHIFT THREE

 * @ Parameters Required: 
 * Fs

 * @ More Info:
 * LS3 is used for code extension purposes. It causes the meanings
 * of the bit combinations following it in the data stream to be changed.

 * The use of LS3 is defined in Standard ECMA-35.
 *
 */
#define LS3(Fs) ESC "o"

/*
 * LS3R - LOCKING-SHIFT THREE RIGHT

 * @ Parameters Required: 
 * Fs

 * @ More Info:
 * LS3R is used for code extension purposes. It causes the meanings
 * of the bit combinations following it in the data stream to be changed.

 * The use of LS3R is defined in Standard ECMA-35.
 *
 */
#define LS3R(Fs) ESC "|"

/*
 * MC - MEDIA COPY

 * @ Parameters Required: 
 * Ps

 * @ More Info:
 * MC is used either to initiate a transfer of data from or to
 * an auxiliary input/output device or to enable or disable
 * the relay of the received data stream to an auxiliary
 * input/output device, depending on the parameter value:

 * 0 -> initiate transfer to a primary auxiliary device
 * 1 -> initiate transfer from a primary auxiliary device
 * 2 -> initiate transfer to a secondary auxiliary device
 * 3 -> initiate transfer from a secondary auxiliary device
 * 4 -> stop relay to a primary auxiliary device
 * 5 -> start relay to a primary auxiliary device
 * 6 -> stop relay to a secondary auxiliary device
 * 7 -> start relay to a secondary auxiliary device

 * This control function may not be used to switch on or off an
 * auxiliary device.
 *
 */
#define MC(Ps) CSI #Ps "i"

/*
 * MC - MEDIA COPY

 * @ Parameters Required: 
 * No Parameter Required

 * @ More Info:
 * MC is used either to initiate a transfer of data from or to
 * an auxiliary input/output device or to enable or disable
 * the relay of the received data stream to an auxiliary
 * input/output device, depending on the parameter value:

 * 0 -> initiate transfer to a primary auxiliary device
 * 1 -> initiate transfer from a primary auxiliary device
 * 2 -> initiate transfer to a secondary auxiliary device
 * 3 -> initiate transfer from a secondary auxiliary device
 * 4 -> stop relay to a primary auxiliary device
 * 5 -> start relay to a primary auxiliary device
 * 6 -> stop relay to a secondary auxiliary device
 * 7 -> start relay to a secondary auxiliary device

 * This control function may not be used to switch on or off an
 * auxiliary device.
 *
 */
#define _MC_ CSI "i"

/*
 * MW - MESSAGE WAITING

 * @ Parameters Required: 
 * No Parameter Required

 * @ More Info:
 * MW is used to set a message waiting indicator in the receiving
 * device. An appropriate acknowledgement to the receipt of
 * MW may be given by using DEVICE STATUS REPORT (DSR).
 *
 */
#define MW ESC "U"

/*
 * NAK - NEGATIVE ACKNOWLEDGE

 * @ Parameters Required: 
 * No Parameter Required

 * @ More Info:
 * NAK is transmitted by a receiver as a negative response to the
 * sender.

 * The use of NAK is defined in ISO 1745.
 *
 */
#define NAK "\x15"

/*
 * NBH - NO BREAK HERE

 * @ Parameters Required: 
 * No Parameter Required

 * @ More Info:
 * NBH is used to indicate a point where a line break shall not
 * occur when text is formatted. NBH may occur between two
 * graphic characters either or both of which may be SPACE.
 *
 */
#define NBH ESC "C"

/*
 * NEL - NEXT LINE

 * @ Parameters Required: 
 * No Parameter Required

 * @ More Info:
 * The effect of NEL depends on the setting of the DEVICE COMPONENT
 * SELECT MODE (DCSM) and on the parameter value of SELECT
 * IMPLICIT MOVEMENT DIRECTION (SIMD).

 * If the DEVICE COMPONENT SELECT MODE (DCSM) is set to PRESENTATION and
 * with a parameter value of SIMD equal to 0, NEL causes the
 * active presentation position to be moved to the line home
 * position of the following line in the presentation
 * component. The line home position is established by the
 * parameter value of SET LINE HOME (SLH).

 * With a parameter value of SIMD equal to 1, NEL causes the active
 * presentation position to be moved to the line limit
 * position of the following line in the presentation
 * component. The line limit position is established by the parameter
 * value of SET LINE LIMIT (SLL).

 * If the DEVICE COMPONENT SELECT MODE (DCSM) is set to DATA and
 * with a parameter value of SIMD equal to 0, NEL causes the
 * active data position to be moved to the line home position
 * of the following line in the data component. The line home
 * position is established by the parameter value of SET LINE HOME (SLH).

 * With a parameter value of SIMD equal to 1, NEL causes the
 * active data position to be moved to the line limit
 * position of the following line in the data component. The
 * line limit position is established by the parameter value
 * of SET LINE LIMIT (SLL).
 *
 */
#define NEL ESC "E"

/*
 * NP - NEXT PAGE

 * @ Parameters Required: 
 * Pn

 * @ More Info:
 * NP causes the n-th following page in the presentation component
 * to be displayed, where n equals the value of Pn.

 * The effect of this control function on the active presentation
 * position is not defined by this Standard.
 *
 */
#define NP(Pn) CSI #Pn "U"

/*
 * NP - NEXT PAGE

 * @ Parameters Required: 
 * No Parameter Required

 * @ More Info:
 * NP causes the n-th following page in the presentation component
 * to be displayed, where n equals the value of Pn.

 * The effect of this control function on the active presentation
 * position is not defined by this Standard.
 *
 */
#define _NP_ CSI "U"

/*
 * NUL - NULL

 * @ Parameters Required: 
 * No Parameter Required

 * @ More Info:
 * NUL is used for media-fill or time-fill. NUL characters may
 * be inserted into, or removed from, a data stream without
 * affecting the information content of that stream, but such
 * action may affect the information layout and/or the
 * control of equipment.
 *
 */
#define NUL "\x00"

/*
 * OSC - OPERATING SYSTEM COMMAND

 * @ Parameters Required: 
 * No Parameter Required

 * @ More Info:
 * OSC is used as the opening delimiter of a control string for
 * operating system use. The command string following may consist
 * of a sequence of bit combinations in the range 00/08 to 00/13
 * and 02/00 to to 07/14. The control string is closed by the terminating
 * delimiter STRING TERMINATOR (ST). The interpretation of
 * the command string depends on the relevant operating system.
 *
 */
#define OSC ESC "]"

/*
 * PEC - PRESENTATION EXPAND OR CONTRACT

 * @ Parameters Required: 
 * Ps

 * @ More Info:
 * PEC is used to establish the spacing and the extent of the
 * graphic characters for subsequent text. The spacing is
 * specified in the line as multiples of the spacing
 * established by the most recent occurrence of SET CHARACTER
 * SPACING (SCS) or of SELECT CHARACTER SPACING (SHS) or of
 * SPACING INCREMENT (SPI) in the data stream. The extent of
 * the characters is implicitly established by these
 * control functions. The established spacing and the extent
 * remain in effect until the next occurrence of PEC, of SCS,
 * of SHS or of SPI in the data stream. The parameter values are:

 * 0 -> normal (as specified by SCS, SHS or SPI)
 * 1 -> expanded (multiplied by a factor not greater than 2)
 * 2 -> condensed (multiplied by a factor not less than 0,5)
 *
 */
#define PEC(Ps) CSI #Ps " " "Z"

/*
 * PEC - PRESENTATION EXPAND OR CONTRACT

 * @ Parameters Required: 
 * No Parameter Required

 * @ More Info:
 * PEC is used to establish the spacing and the extent of the
 * graphic characters for subsequent text. The spacing is
 * specified in the line as multiples of the spacing
 * established by the most recent occurrence of SET CHARACTER
 * SPACING (SCS) or of SELECT CHARACTER SPACING (SHS) or of
 * SPACING INCREMENT (SPI) in the data stream. The extent of
 * the characters is implicitly established by these
 * control functions. The established spacing and the extent
 * remain in effect until the next occurrence of PEC, of SCS,
 * of SHS or of SPI in the data stream. The parameter values are:

 * 0 -> normal (as specified by SCS, SHS or SPI)
 * 1 -> expanded (multiplied by a factor not greater than 2)
 * 2 -> condensed (multiplied by a factor not less than 0,5)
 *
 */
#define _PEC_ CSI " " "Z"

/*
 * PFS - PAGE FORMAT SELECTION

 * @ Parameters Required: 
 * Ps

 * @ More Info:
 * PFS is used to establish the available area for the imaging
 * of pages of text based on paper size. The pages are
 * introduced by the subsequent occurrence of FORM FEED (FF)
 * in the data stream.

 * The established image area remains in effect until the next
 * occurrence of PFS in the data stream. The parameter values
 * are (see also annex E):

 * 00 -> tall basic text communication format
 * 01 -> wide basic text communication format
 * 02 -> tall basic A4 format
 * 03 -> wide basic A4 format
 * 04 -> tall North American letter format
 * 05 -> wide North American letter format
 * 06 -> tall extended A4 format
 * 07 -> wide extended A4 format
 * 08 -> tall North American legal format
 * 09 -> wide North American legal format
 * 10 -> A4 short lines format
 * 11 -> A4 long lines format
 * 12 -> B5 short lines format
 * 13 -> B5 long lines format
 * 14 -> B4 short lines format
 * 15 -> B4 long lines format

 * The page home position is established by the parameter value
 * of SET PAGE HOME (SPH), the page limit position is
 * established by the parameter value of SET PAGE LIMIT (SPL).
 *
 */
#define PFS(Ps) CSI #Ps " " "J"

/*
 * PFS - PAGE FORMAT SELECTION

 * @ Parameters Required: 
 * No Parameter Required

 * @ More Info:
 * PFS is used to establish the available area for the imaging
 * of pages of text based on paper size. The pages are
 * introduced by the subsequent occurrence of FORM FEED (FF)
 * in the data stream.

 * The established image area remains in effect until the next
 * occurrence of PFS in the data stream. The parameter values
 * are (see also annex E):

 * 00 -> tall basic text communication format
 * 01 -> wide basic text communication format
 * 02 -> tall basic A4 format
 * 03 -> wide basic A4 format
 * 04 -> tall North American letter format
 * 05 -> wide North American letter format
 * 06 -> tall extended A4 format
 * 07 -> wide extended A4 format
 * 08 -> tall North American legal format
 * 09 -> wide North American legal format
 * 10 -> A4 short lines format
 * 11 -> A4 long lines format
 * 12 -> B5 short lines format
 * 13 -> B5 long lines format
 * 14 -> B4 short lines format
 * 15 -> B4 long lines format

 * The page home position is established by the parameter value
 * of SET PAGE HOME (SPH), the page limit position is
 * established by the parameter value of SET PAGE LIMIT (SPL).
 *
 */
#define _PFS_ CSI " " "J"

/*
 * PLD - PARTIAL LINE FORWARD

 * @ Parameters Required: 
 * No Parameter Required

 * @ More Info:
 * PLD causes the active presentation position to be moved in the
 * presentation component to the corresponding position of an
 * imaginary line with a partial offset in the direction of
 * the line progression. This offset should be sufficient
 * either to image following characters as subscripts until
 * the first following occurrence of PARTIAL LINE BACKWARD
 * (PLU) in the data stream, or, if preceding characters were
 * imaged as superscripts, to restore imaging of following
 * characters to the active line (the line that contains the
 * active presentation position).

 * Any interactions between PLD and format effectors other than
 * PLU are not defined by this Standard.
 *
 */
#define PLD ESC "K"

/*
 * PLU - PARTIAL LINE BACKWARD

 * @ Parameters Required: 
 * No Parameter Required

 * @ More Info:
 * PLU causes the active presentation position to be moved in the
 * presentation component to the corresponding position of an
 * imaginary line with a partial offset in the direction
 * opposite to that of the line progression. This offset
 * should be sufficient either to image following characters
 * as superscripts until the first following occurrence of
 * PARTIAL LINE FORWARD (PLD) in the data stream, or, if
 * preceding characters were imaged as subscripts, to restore
 * imaging of following characters to the active line
 * (the line that contains the active presentation position).

 * Any interactions between PLU and format effectors other than
 * PLD are not defined by this Standard.
 *
 */
#define PLU ESC "L"

/*
 * PM - PRIVACY MESSAGE

 * @ Parameters Required: 
 * No Parameter Required

 * @ More Info:
 * PM is used as the opening delimiter of a control string for
 * privacy message use. The command string following may consist
 * of a sequence of bit combinations in the range 00/08 to 00/13
 * and 02/00 to 07/14. The control string is closed by the terminating
 * delimiter STRING TERMINATOR (ST). The interpretation of
 * the command string depends on the relevant privacy discipline.
 *
 */
#define PM ESC "^"

/*
 * PP - PRECEDING PAGE

 * @ Parameters Required: 
 * Pn

 * @ More Info:
 * PP causes the n-th preceding page in the presentation component
 * to be displayed, where n equals the value of Pn. The
 * effect of this control function on the active presentation
 * position is not defined by this Standard.
 *
 */
#define PP(Pn) CSI #Pn "V"

/*
 * PP - PRECEDING PAGE

 * @ Parameters Required: 
 * No Parameter Required

 * @ More Info:
 * PP causes the n-th preceding page in the presentation component
 * to be displayed, where n equals the value of Pn. The
 * effect of this control function on the active presentation
 * position is not defined by this Standard.
 *
 */
#define _PP_ CSI "V"

/*
 * PPA - PAGE POSITION ABSOLUTE

 * @ Parameters Required: 
 * Pn

 * @ More Info:
 * PPA causes the active data position to be moved in the data
 * component to the corresponding character position on the
 * n-th page, where n equals the value of Pn.
 *
 */
#define PPA(Pn) CSI #Pn " " "P"

/*
 * PPA - PAGE POSITION ABSOLUTE

 * @ Parameters Required: 
 * No Parameter Required

 * @ More Info:
 * PPA causes the active data position to be moved in the data
 * component to the corresponding character position on the
 * n-th page, where n equals the value of Pn.
 *
 */
#define _PPA_ CSI " " "P"

/*
 * PPB - PAGE POSITION BACKWARD

 * @ Parameters Required: 
 * Pn

 * @ More Info:
 * PPB causes the active data position to be moved in the data
 * component to the corresponding character position on the
 * n-th preceding page, where n equals the value of Pn.
 *
 */
#define PPB(Pn) CSI #Pn " " "R"

/*
 * PPB - PAGE POSITION BACKWARD

 * @ Parameters Required: 
 * No Parameter Required

 * @ More Info:
 * PPB causes the active data position to be moved in the data
 * component to the corresponding character position on the
 * n-th preceding page, where n equals the value of Pn.
 *
 */
#define _PPB_ CSI " " "R"

/*
 * PPR - PAGE POSITION FORWARD

 * @ Parameters Required: 
 * Pn

 * @ More Info:
 * PPR causes the active data position to be moved in the data
 * component to the corresponding character position on the
 * n-th following page, where n equals the value of Pn.
 *
 */
#define PPR(Pn) CSI #Pn " " "Q"

/*
 * PPR - PAGE POSITION FORWARD

 * @ Parameters Required: 
 * No Parameter Required

 * @ More Info:
 * PPR causes the active data position to be moved in the data
 * component to the corresponding character position on the
 * n-th following page, where n equals the value of Pn.
 *
 */
#define _PPR_ CSI " " "Q"

/*
 * PTX - PARALLEL TEXTS

 * @ Parameters Required: 
 * Ps

 * @ More Info:
 * PTX is used to delimit strings of graphic characters that are
 * communicated one after another in the data stream but that
 * are intended to be presented in parallel with one another,
 * usually in adjacent lines.

 * The parameter values are:
 * 0 -> end of parallel texts
 * 1 -> beginning of a string of principal parallel text
 * 2 -> beginning of a string of supplementary parallel text
 * 3 -> beginning of a string of supplementary Japanese phonetic annotation
 * 4 -> beginning of a string of supplementary Chinese phonetic annotation
 * 5 -> end of a string of supplementary phonetic annotations

 * PTX with a parameter value of 1 indicates the beginning of the
 * string of principal text intended to be presented in
 * parallel with one or more strings of supplementary text.

 * PTX with a parameter value of 2, 3 or 4 indicates the beginning
 * of a string of supplementary text that is intended to be
 * presented in parallel with either a string of principal
 * text or the immediately preceding string of supplementary
 * text, if any; at the same time it indicates the end of the
 * preceding string of principal text or of the immediately
 * preceding string of supplementary text, if any. The end of
 * a string of supplementary text is indicated by a
 * subsequent occurrence of PTX with a parameter value other than 1.

 * PTX with a parameter value of 0 indicates the end of the strings
 * of text intended to be presented in parallel with one another.

 * NOTE
 * PTX does not explicitly specify the relative placement
 * of the strings of principal and supplementary parallel
 * texts, or the relative sizes of graphic characters in the
 * strings of parallel text. A string of supplementary text
 * is normally presented in a line adjacent to the line
 * containing the string of principal text, or adjacent to
 * the line containing the immediately preceding string of
 * supplementary text, if any. The first graphic character of
 * the string of principal text and the first graphic
 * character of a string of supplementary text are normally
 * presented in the same position of their respective lines.
 * However, a string of supplementary text longer (when
 * presented) than the associated string of principal text
 * may be centred on that string. In the case of long strings
 * of text, such as paragraphs in different languages, the
 * strings may be presented in successive lines in parallel
 * columns, with their beginnings aligned with one another
 * and the shorter of the paragraphs followed by an appropriate
 * amount of "white space".

 * Japanese phonetic annotation typically consists of a few
 * half-size or smaller Kana characters which indicate the
 * pronunciation or interpretation of one or more Kanji
 * characters and are presented above those Kanji characters
 * if the character path is horizontal, or to the right of
 * them if the character path is vertical.

 * Chinese phonetic annotation typically consists of a few Pinyin
 * characters which indicate the pronunciation of one or more
 * Hanzi characters and are presented above those Hanzi
 * characters. Alternatively, the Pinyin characters may be
 * presented in the same line as the Hanzi characters and
 * following the respective Hanzi characters. The Pinyin
 * characters will then be presented within enclosing pairs of parentheses.
 *
 */
#define PTX(Ps) CSI #Ps "\\"

/*
 * PTX - PARALLEL TEXTS

 * @ Parameters Required: 
 * No Parameter Required

 * @ More Info:
 * PTX is used to delimit strings of graphic characters that are
 * communicated one after another in the data stream but that
 * are intended to be presented in parallel with one another,
 * usually in adjacent lines.

 * The parameter values are:
 * 0 -> end of parallel texts
 * 1 -> beginning of a string of principal parallel text
 * 2 -> beginning of a string of supplementary parallel text
 * 3 -> beginning of a string of supplementary Japanese phonetic annotation
 * 4 -> beginning of a string of supplementary Chinese phonetic annotation
 * 5 -> end of a string of supplementary phonetic annotations

 * PTX with a parameter value of 1 indicates the beginning of the
 * string of principal text intended to be presented in
 * parallel with one or more strings of supplementary text.

 * PTX with a parameter value of 2, 3 or 4 indicates the beginning
 * of a string of supplementary text that is intended to be
 * presented in parallel with either a string of principal
 * text or the immediately preceding string of supplementary
 * text, if any; at the same time it indicates the end of the
 * preceding string of principal text or of the immediately
 * preceding string of supplementary text, if any. The end of
 * a string of supplementary text is indicated by a
 * subsequent occurrence of PTX with a parameter value other than 1.

 * PTX with a parameter value of 0 indicates the end of the strings
 * of text intended to be presented in parallel with one another.

 * NOTE
 * PTX does not explicitly specify the relative placement
 * of the strings of principal and supplementary parallel
 * texts, or the relative sizes of graphic characters in the
 * strings of parallel text. A string of supplementary text
 * is normally presented in a line adjacent to the line
 * containing the string of principal text, or adjacent to
 * the line containing the immediately preceding string of
 * supplementary text, if any. The first graphic character of
 * the string of principal text and the first graphic
 * character of a string of supplementary text are normally
 * presented in the same position of their respective lines.
 * However, a string of supplementary text longer (when
 * presented) than the associated string of principal text
 * may be centred on that string. In the case of long strings
 * of text, such as paragraphs in different languages, the
 * strings may be presented in successive lines in parallel
 * columns, with their beginnings aligned with one another
 * and the shorter of the paragraphs followed by an appropriate
 * amount of "white space".

 * Japanese phonetic annotation typically consists of a few
 * half-size or smaller Kana characters which indicate the
 * pronunciation or interpretation of one or more Kanji
 * characters and are presented above those Kanji characters
 * if the character path is horizontal, or to the right of
 * them if the character path is vertical.

 * Chinese phonetic annotation typically consists of a few Pinyin
 * characters which indicate the pronunciation of one or more
 * Hanzi characters and are presented above those Hanzi
 * characters. Alternatively, the Pinyin characters may be
 * presented in the same line as the Hanzi characters and
 * following the respective Hanzi characters. The Pinyin
 * characters will then be presented within enclosing pairs of parentheses.
 *
 */
#define _PTX_ CSI "\\"

/*
 * PU1 - PRIVATE USE ONE

 * @ Parameters Required: 
 * No Parameter Required

 * @ More Info:
 * PU1 is reserved for a function without standardized meaning
 * for private use as required, subject to the prior
 * agreement between the sender and the recipient of the data.
 *
 */
#define PU1 ESC "Q"

/*
 * PU2 - PRIVATE USE TWO

 * @ Parameters Required: 
 * No Parameter Required

 * @ More Info:
 * PU2 is reserved for a function without standardized meaning
 * for private use as required, subject to the prior
 * agreement between the sender and the recipient of the data.
 *
 */
#define PU2 ESC "R"

/*
 * QUAD - QUAD

 * @ Parameters Required: 
 * Ps

 * @ More Info:
 * QUAD is used to indicate the end of a string of graphic
 * characters that are to be positioned on a single line
 * according to the layout specified by the parameter values,
 * see annex C:

 * 0 -> flush to line home position margin
 * 1 -> flush to line home position margin and fill with leader
 * 2 -> centre between line home position and line limit position margins
 * 3 -> centre between line home position and line limit position
 * margins and fill with leader
 * 4 -> flush to line limit position margin
 * 5 -> flush to line limit position margin and fill with leader
 * 6 -> flush to both margins

 * The beginning of the string to be positioned is indicated by
 * the preceding occurrence in the data stream of either QUAD
 * or one of the following formator functions: FORM FEED
 * (FF), CHARACTER AND LINE POSITION (HVP), LINE FEED (LF),
 * NEXT LINE (NEL), PAGE POSITION ABSOLUTE (PPA), PAGE
 * POSITION BACKWARD (PPB), PAGE POSITION FORWARD (PPR),
 * REVERSE LINE FEED (RI), LINE POSITION ABSOLUTE (VPA), LINE
 * POSITION BACKWARD (VPB), LINE POSITION FORWARD (VPR), or LINE TABULATION (VT).

 * The line home position is established by the parameter value
 * of SET LINE HOME (SLH). The line limit position is
 * established by the parameter value of SET LINE LIMIT (SLL).
 *
 */
#define QUAD(Ps) CSI #Ps " " "H"

/*
 * QUAD - QUAD

 * @ Parameters Required: 
 * No Parameter Required

 * @ More Info:
 * QUAD is used to indicate the end of a string of graphic
 * characters that are to be positioned on a single line
 * according to the layout specified by the parameter values,
 * see annex C:

 * 0 -> flush to line home position margin
 * 1 -> flush to line home position margin and fill with leader
 * 2 -> centre between line home position and line limit position margins
 * 3 -> centre between line home position and line limit position
 * margins and fill with leader
 * 4 -> flush to line limit position margin
 * 5 -> flush to line limit position margin and fill with leader
 * 6 -> flush to both margins

 * The beginning of the string to be positioned is indicated by
 * the preceding occurrence in the data stream of either QUAD
 * or one of the following formator functions: FORM FEED
 * (FF), CHARACTER AND LINE POSITION (HVP), LINE FEED (LF),
 * NEXT LINE (NEL), PAGE POSITION ABSOLUTE (PPA), PAGE
 * POSITION BACKWARD (PPB), PAGE POSITION FORWARD (PPR),
 * REVERSE LINE FEED (RI), LINE POSITION ABSOLUTE (VPA), LINE
 * POSITION BACKWARD (VPB), LINE POSITION FORWARD (VPR), or LINE TABULATION (VT).

 * The line home position is established by the parameter value
 * of SET LINE HOME (SLH). The line limit position is
 * established by the parameter value of SET LINE LIMIT (SLL).
 *
 */
#define _QUAD_ CSI " " "H"

/*
 * REP - REPEAT

 * @ Parameters Required: 
 * Pn

 * @ More Info:
 * REP is used to indicate that the preceding character in the
 * data stream, if it is a graphic character (represented by
 * one or more bit combinations) including SPACE, is to be
 * repeated n times, where n equals the value of Pn. If the
 * character preceding REP is a control function or part of a
 * control function, the effect of REP is not defined by this Standard.
 *
 */
#define REP(Pn) CSI #Pn "b"

/*
 * REP - REPEAT

 * @ Parameters Required: 
 * No Parameter Required

 * @ More Info:
 * REP is used to indicate that the preceding character in the
 * data stream, if it is a graphic character (represented by
 * one or more bit combinations) including SPACE, is to be
 * repeated n times, where n equals the value of Pn. If the
 * character preceding REP is a control function or part of a
 * control function, the effect of REP is not defined by this Standard.
 *
 */
#define _REP_ CSI "b"

/*
 * RI - REVERSE LINE FEED

 * @ Parameters Required: 
 * No Parameter Required

 * @ More Info:
 * If the DEVICE COMPONENT SELECT MODE (DCSM) is set to PRESENTATION,
 * RI causes the active presentation position to be moved in
 * the presentation component to the corresponding character
 * position of the preceding line.

 * If the DEVICE COMPONENT SELECT MODE (DCSM) is set to DATA,
 * RI causes the active data position to be moved in the data
 * component to the corresponding character position of the preceding line.
 *
 */
#define RI ESC "M"

/*
 * RIS - RESET TO INITIAL STATE

 * @ Parameters Required: 
 * Fs

 * @ More Info:
 * RIS causes a device to be reset to its initial state, i.e. the
 * state it has after it is made operational. This may imply,
 * if applicable: clear tabulation stops, remove qualified
 * areas, reset graphic rendition, put all character
 * positions into the erased state, move the active
 * presentation position to the first position of the first
 * line in the presentation component, move the active data
 * position to the first character position of the first line
 * in the data component, set the modes into the reset state, etc.
 *
 */
#define RIS(Fs) ESC "c"

/*
 * RM - RESET MODE

 * @ Parameters Required: 
 * Ps

 * @ More Info:
 * No parameter default value.

 * RM causes the modes of the receiving device to be reset as
 * specified by the parameter values:
 * 01 -> GUARDED AREA TRANSFER MODE (GATM)
 * 02 -> KEYBOARD ACTION MODE (KAM)
 * 03 -> CONTROL REPRESENTATION MODE (CRM)
 * 04 -> INSERTION REPLACEMENT MODE (IRM)
 * 05 -> STATUS REPORT TRANSFER MODE (SRTM)
 * 06 -> ERASURE MODE (ERM)
 * 07 -> LINE EDITING MODE (VEM)
 * 08 -> BI-DIRECTIONAL SUPPORT MODE (BDSM) 9 DEVICE COMPONENT SELECT MODE (DCSM)
 * 10 -> CHARACTER EDITING MODE (HEM)
 * 11 -> POSITIONING UNIT MODE (PUM) (see F.4.1 in annex F)
 * 12 -> SEND/RECEIVE MODE (SRM)
 * 13 -> FORMAT EFFECTOR ACTION MODE (FEAM)
 * 14 -> FORMAT EFFECTOR TRANSFER MODE (FETM)
 * 15 -> MULTIPLE AREA TRANSFER MODE (MATM)
 * 16 -> TRANSFER TERMINATION MODE (TTM)
 * 17 -> SELECTED AREA TRANSFER MODE (SATM)
 * 18 -> TABULATION STOP MODE (TSM)
 * 19 -> (Shall not be used; see F.5.1 in annex F)
 * 20 -> (Shall not be used; see F.5.2 in annex F)
 * 21 -> GRAPHIC RENDITION COMBINATION MODE (GRCM)
 * 22 -> ZERO DEFAULT MODE (ZDM) (see F.4.2 in annex F)

 * NOTE Private modes may be implemented
 * using private parameters, see 5.4.1 and 7.4.
 *
 */
#define RM(Ps) CSI #Ps "l"

/*
 * SACS - SET ADDITIONAL CHARACTER SEPARATION

 * @ Parameters Required: 
 * Pn

 * @ More Info:
 * SACS is used to establish extra inter-character escapement for
 * subsequent text. The established extra escapement remains
 * in effect until the next occurrence of SACS or of SET
 * REDUCED CHARACTER SEPARATION (SRCS) in the data stream or
 * until it is reset to the default value by a subsequent
 * occurrence of CARRIAGE RETURN/LINE FEED (CR LF) or of NEXT
 * LINE (NEL) in the data stream, see annex C.

 * Pn specifies the number of units by which the inter-character
 * escapement is enlarged.

 * The unit in which the parameter value is expressed is that
 * established by the parameter value of SELECT SIZE UNIT (SSU).
 *
 */
#define SACS(Pn) CSI #Pn " " "\\"

/*
 * SACS - SET ADDITIONAL CHARACTER SEPARATION

 * @ Parameters Required: 
 * No Parameter Required

 * @ More Info:
 * SACS is used to establish extra inter-character escapement for
 * subsequent text. The established extra escapement remains
 * in effect until the next occurrence of SACS or of SET
 * REDUCED CHARACTER SEPARATION (SRCS) in the data stream or
 * until it is reset to the default value by a subsequent
 * occurrence of CARRIAGE RETURN/LINE FEED (CR LF) or of NEXT
 * LINE (NEL) in the data stream, see annex C.

 * Pn specifies the number of units by which the inter-character
 * escapement is enlarged.

 * The unit in which the parameter value is expressed is that
 * established by the parameter value of SELECT SIZE UNIT (SSU).
 *
 */
#define _SACS_ CSI " " "\\"

/*
 * SCI - SINGLE CHARACTER INTRODUCER

 * @ Parameters Required: 
 * No Parameter Required

 * @ More Info:
 * SCI and the bit combination following it are used to represent
 * a control function or a graphic character. The bit combination
 * following SCI must be from 00/08 to 00/13 or 02/00 to 07/14.
 * The use of SCI is reserved for future standardization.
 *
 */
#define SCI ESC "Z"

/*
 * SCO - SELECT CHARACTER ORIENTATION

 * @ Parameters Required: 
 * Ps

 * @ More Info:
 * SCO is used to establish the amount of rotation of the graphic
 * characters following in the data stream. The established
 * value remains in effect until the next occurrence of SCO
 * in the data stream.

 * The parameter values are:
 * 0 ->   0°
 * 1 ->  45°
 * 2 ->  90°
 * 3 -> 135°
 * 4 -> 180°
 * 5 -> 225°
 * 6 -> 270°
 * 7 -> 315°

 * Rotation is positive, i.e. counter-clockwise and applies to the
 * normal presentation of the graphic characters along the
 * character path. The centre of rotation of the affected
 * graphic characters is not defined by this Standard.
 *
 */
#define SCO(Ps) CSI #Ps " " "e"

/*
 * SCO - SELECT CHARACTER ORIENTATION

 * @ Parameters Required: 
 * No Parameter Required

 * @ More Info:
 * SCO is used to establish the amount of rotation of the graphic
 * characters following in the data stream. The established
 * value remains in effect until the next occurrence of SCO
 * in the data stream.

 * The parameter values are:
 * 0 ->   0°
 * 1 ->  45°
 * 2 ->  90°
 * 3 -> 135°
 * 4 -> 180°
 * 5 -> 225°
 * 6 -> 270°
 * 7 -> 315°

 * Rotation is positive, i.e. counter-clockwise and applies to the
 * normal presentation of the graphic characters along the
 * character path. The centre of rotation of the affected
 * graphic characters is not defined by this Standard.
 *
 */
#define _SCO_ CSI " " "e"

/*
 * SCP - SELECT CHARACTER PATH

 * @ Parameters Required: 
 * Ps1, Ps2

 * @ More Info:
 * No parameter default values.

 * SCP is used to select the character path, relative to
 * the line orientation, for the active line (the line that
 * contains the active presentation position) and subsequent
 * lines in the presentation component. It is also used to
 * update the content of the active line in the presentation
 * component and the content of the active line (the line that
 * contains the active data position) in the data component.
 * This takes effect immediately.

 * Ps1 specifies the character path:
 * 1 -> left-to-right (in the case of horizontal line
 * orientation), or top-to-bottom (in the case of vertical
 * line orientation)
 * 2 -> right-to-left (in the case of
 * horizontal line orientation), or bottom-to-top (in the
 * case of vertical line orientation)

 * Ps2 specifies the effect on the content of the presentation component and
 * the content of the data component:
 * 0 -> undefined
 * (implementation-dependent)

 * NOTE This may also permit the
 * effect to take place after the next occurrence of CR, NEL
 * or any control function which initiates an absolute movement
 * of the active presentation position or the active data position.

 * 1 -> the content of the active line in the presentation component
 * (the line that contains the active presentation position)
 * is updated to correspond to the content of the active line
 * in the data component (the line that contains the active
 * data position) according to the newly established
 * character path characteristics in the presentation
 * component; the active data position is moved to the first
 * character position in the active line in the data
 * component, the active presentation position in the
 * presentation component is updated accordingly
 * 2 -> the content of the active line in the data component (the line
 * that contains the active data position) is updated to
 * correspond to the content of the active line in the
 * presentation component (the line that contains the active
 * presentation position) according to the newly established
 * character path characteristics of the presentation
 * component; the active presentation position is moved to
 * the first character position in the active line in the
 * presentation component, the active data position in the data
 * component is updated accordingly.
 *
 */
#define SCP(Ps1, Ps2) CSI #Ps1 ";" #Ps2 " " "k"

/*
 * SCS - SET CHARACTER SPACING

 * @ Parameters Required: 
 * Pn

 * @ More Info:
 * No parameter default value.

 * SCS is used to establish the character spacing for subsequent
 * text. The established spacing remains in effect until the
 * next occurrence of SCS, or of SELECT CHARACTER SPACING
 * (SHS) or of SPACING INCREMENT (SPI) in the data stream,
 * see annex C.

 * Pn specifies the character spacing.

 * The unit in which the parameter value is expressed is that
 * established by the parameter value of SELECT SIZE UNIT (SSU).
 *
 */
#define SCS(Pn) CSI #Pn " " "g"

/*
 * SD - SCROLL DOWN

 * @ Parameters Required: 
 * Pn

 * @ More Info:
 * SD causes the data in the presentation component to be moved
 * by n line positions if the line orientation is horizontal,
 * or by n character positions if the line orientation is
 * vertical, such that the data appear to move down; where n
 * equals the value of Pn.

 * The active presentation position is not affected by this control
 * function.
 *
 */
#define SD(Pn) CSI #Pn "T"

/*
 * SD - SCROLL DOWN

 * @ Parameters Required: 
 * No Parameter Required

 * @ More Info:
 * SD causes the data in the presentation component to be moved
 * by n line positions if the line orientation is horizontal,
 * or by n character positions if the line orientation is
 * vertical, such that the data appear to move down; where n
 * equals the value of Pn.

 * The active presentation position is not affected by this control
 * function.
 *
 */
#define _SD_ CSI "T"

/*
 * SDS - START DIRECTED STRING

 * @ Parameters Required: 
 * Ps

 * @ More Info:
 * SDS is used to establish in the data component the beginning
 * and the end of a string of characters as well as the
 * direction of the string. This direction may be different
 * from that currently established. The indicated string
 * follows the preceding text. The established character
 * progression is not affected. The beginning of a directed
 * string is indicated by SDS with a parameter value not
 * equal to 0. A directed string may contain one or more
 * nested strings. These nested strings may be directed
 * strings the beginnings of which are indicated by SDS with
 * a parameter value not equal to 0, or reversed strings the
 * beginnings of which are indicated by START REVERSED STRING
 * (SRS) with a parameter value of 1. Every beginning of such
 * a string invokes the next deeper level of nesting. This
 * Standard does not define the location of the active data
 * position within any such nested string. The end of a
 * directed string is indicated by SDS with a parameter value
 * of 0. Every end of such a string re-establishes the next
 * higher level of nesting (the one in effect prior to the
 * string just ended). The direction is re-established to
 * that in effect prior to the string just ended. The active
 * data position is moved to the character position following the characters of the string just ended.

 * The parameter values are: 0 end of a directed string; re-establish
 * the previous direction 1 start of a directed string;
 * establish the direction left-to-right 2 start of a
 * directed string; establish the direction right-to-left
 * NOTE 1 The effect of receiving a CVT, HT, SCP, SPD or VT
 * control function within an SDS string is not defined by
 * this Standard. NOTE 2 The control functions for area
 * definition (DAQ, EPA, ESA, SPA, SSA) should not be used within an SDS string.
 *
 */
#define SDS(Ps) CSI #Ps "]"

/*
 * SDS - START DIRECTED STRING

 * @ Parameters Required: 
 * No Parameter Required

 * @ More Info:
 * SDS is used to establish in the data component the beginning
 * and the end of a string of characters as well as the
 * direction of the string. This direction may be different
 * from that currently established. The indicated string
 * follows the preceding text. The established character
 * progression is not affected. The beginning of a directed
 * string is indicated by SDS with a parameter value not
 * equal to 0. A directed string may contain one or more
 * nested strings. These nested strings may be directed
 * strings the beginnings of which are indicated by SDS with
 * a parameter value not equal to 0, or reversed strings the
 * beginnings of which are indicated by START REVERSED STRING
 * (SRS) with a parameter value of 1. Every beginning of such
 * a string invokes the next deeper level of nesting. This
 * Standard does not define the location of the active data
 * position within any such nested string. The end of a
 * directed string is indicated by SDS with a parameter value
 * of 0. Every end of such a string re-establishes the next
 * higher level of nesting (the one in effect prior to the
 * string just ended). The direction is re-established to
 * that in effect prior to the string just ended. The active
 * data position is moved to the character position following the characters of the string just ended.

 * The parameter values are: 0 end of a directed string; re-establish
 * the previous direction 1 start of a directed string;
 * establish the direction left-to-right 2 start of a
 * directed string; establish the direction right-to-left
 * NOTE 1 The effect of receiving a CVT, HT, SCP, SPD or VT
 * control function within an SDS string is not defined by
 * this Standard. NOTE 2 The control functions for area
 * definition (DAQ, EPA, ESA, SPA, SSA) should not be used within an SDS string.
 *
 */
#define _SDS_ CSI "]"

/*
 * SEE - SELECT EDITING EXTENT

 * @ Parameters Required: 
 * Ps

 * @ More Info:
 * SEE is used to establish the editing extent for subsequent
 * character or line insertion or deletion. The established
 * extent remains in effect until the next occurrence of SEE
 * in the data stream. The editing extent depends on the
 * parameter value:

 * 0 the shifted part is limited to the active page in the
 * presentation component 1 the shifted part is limited to
 * the active line in the presentation component

 * 2 the shifted part is limited to the active

 * field in the presentation component 3 the shifted part is
 * limited to the active qualified area

 * 4 the shifted part consists of the relevant part of the entire
 * presentation component.
 *
 */
#define SEE(Ps) CSI #Ps "Q"

/*
 * SEE - SELECT EDITING EXTENT

 * @ Parameters Required: 
 * No Parameter Required

 * @ More Info:
 * SEE is used to establish the editing extent for subsequent
 * character or line insertion or deletion. The established
 * extent remains in effect until the next occurrence of SEE
 * in the data stream. The editing extent depends on the
 * parameter value:

 * 0 the shifted part is limited to the active page in the
 * presentation component 1 the shifted part is limited to
 * the active line in the presentation component

 * 2 the shifted part is limited to the active

 * field in the presentation component 3 the shifted part is
 * limited to the active qualified area

 * 4 the shifted part consists of the relevant part of the entire
 * presentation component.
 *
 */
#define _SEE_ CSI "Q"

/*
 * SEF - SHEET EJECT AND FEED

 * @ Parameters Required: 
 * Ps1, Ps2

 * @ More Info:
 * SEF causes a sheet of paper to be ejected from a printing
 * device into a specified output stacker and another sheet
 * to be loaded into the printing device from a specified
 * paper bin. Parameter values of Ps1 are: 0 eject sheet, no
 * new sheet loaded 1 eject sheet and load another from bin 1

 * 2 eject sheet and load another from bin 2

 * .

 * .

 * .

 * n eject sheet and load another from bin n Parameter values of
 * Ps2 are: 0 eject sheet, no stacker specified 1 eject sheet
 * into stacker 1 2 eject sheet into stacker 2 . . .

 * n eject sheet into stacker n
 *
 */
#define SEF(Ps1, Ps2) CSI #Ps1 ";" #Ps2 " " "Y"

/*
 * SEF - SHEET EJECT AND FEED

 * @ Parameters Required: 
 * Ps1

 * @ More Info:
 * SEF causes a sheet of paper to be ejected from a printing
 * device into a specified output stacker and another sheet
 * to be loaded into the printing device from a specified
 * paper bin. Parameter values of Ps1 are: 0 eject sheet, no
 * new sheet loaded 1 eject sheet and load another from bin 1

 * 2 eject sheet and load another from bin 2

 * .

 * .

 * .

 * n eject sheet and load another from bin n Parameter values of
 * Ps2 are: 0 eject sheet, no stacker specified 1 eject sheet
 * into stacker 1 2 eject sheet into stacker 2 . . .

 * n eject sheet into stacker n
 *
 */
#define _SEF(Ps1) CSI #Ps1 ";" " " "Y"

/*
 * SEF - SHEET EJECT AND FEED

 * @ Parameters Required: 
 * Ps2

 * @ More Info:
 * SEF causes a sheet of paper to be ejected from a printing
 * device into a specified output stacker and another sheet
 * to be loaded into the printing device from a specified
 * paper bin. Parameter values of Ps1 are: 0 eject sheet, no
 * new sheet loaded 1 eject sheet and load another from bin 1

 * 2 eject sheet and load another from bin 2

 * .

 * .

 * .

 * n eject sheet and load another from bin n Parameter values of
 * Ps2 are: 0 eject sheet, no stacker specified 1 eject sheet
 * into stacker 1 2 eject sheet into stacker 2 . . .

 * n eject sheet into stacker n
 *
 */
#define __SEF(Ps2) CSI ";" #Ps2 " " "Y"

/*
 * SEF - SHEET EJECT AND FEED

 * @ Parameters Required: 
 * No Parameter Required

 * @ More Info:
 * SEF causes a sheet of paper to be ejected from a printing
 * device into a specified output stacker and another sheet
 * to be loaded into the printing device from a specified
 * paper bin. Parameter values of Ps1 are: 0 eject sheet, no
 * new sheet loaded 1 eject sheet and load another from bin 1

 * 2 eject sheet and load another from bin 2

 * .

 * .

 * .

 * n eject sheet and load another from bin n Parameter values of
 * Ps2 are: 0 eject sheet, no stacker specified 1 eject sheet
 * into stacker 1 2 eject sheet into stacker 2 . . .

 * n eject sheet into stacker n
 *
 */
#define _SEF_ CSI ";" " " "Y"

/*
 * SGR - SELECT GRAPHIC RENDITION

 * @ Parameters Required: 
 * Ps

 * @ More Info:
 * SGR is used to establish one or more graphic rendition aspects
 * for subsequent text. The established aspects remain in
 * effect until the next occurrence of SGR in the data
 * stream, depending on the setting of the GRAPHIC RENDITION
 * COMBINATION MODE (GRCM). Each graphic rendition aspect is
 * specified by a parameter value:

 * 0 default rendition (implementation-defined), cancels the
 * effect of any preceding occurrence of SGR in the data
 * stream regardless of the setting of the GRAPHIC RENDITION
 * COMBINATION MODE (GRCM) 1 bold or increased intensity 2
 * faint, decreased intensity or second colour 3 italicized 4
 * singly underlined 5 slowly blinking (less then 150 per
 * minute) 6 rapidly blinking (150 per minute or more) 7
 * negative image 8 concealed characters 9 crossed-out
 * (characters still legible but marked as to be deleted) 10
 * primary (default) font 11 first alternative font 12 second
 * alternative font 13 third alternative font 14 fourth
 * alternative font 15 fifth alternative font 16 sixth
 * alternative font 17 seventh alternative font 18 eighth
 * alternative font 19 ninth alternative font 20 Fraktur
 * (Gothic) 21 doubly underlined 22 normal colour or normal
 * intensity (neither bold nor faint) 23 not italicized, not
 * fraktur 24 not underlined (neither singly nor doubly) 25
 * steady (not blinking) 26 (reserved for proportional
 * spacing as specified in CCITT Recommendation T.61) 27 positive image 28 revealed characters

 * 29 not crossed out 30 black display 31 red display 32 green
 * display 33 yellow display 34 blue display 35 magenta
 * display 36 cyan display 37 white display 38 (reserved for
 * future standardization; intended for setting character
 * foreground colour as specified in ISO 8613-6 [CCITT
 * Recommendation T.416]) 39 default display colour
 * (implementation-defined) 40 black background 41 red
 * background 42 green background 43 yellow background 44
 * blue background 45 magenta background 46 cyan background
 * 47 white background 48 (reserved for future
 * standardization; intended for setting character background
 * colour as specified in ISO 8613-6 [CCITT Recommendation
 * T.416]) 49 default background colour
 * (implementation-defined) 50 (reserved for cancelling the
 * effect of the rendering aspect established by parameter
 * value 26) 51 framed 52 encircled 53 overlined 54 not
 * framed, not encircled 55 not overlined 56 (reserved for
 * future standardization) 57 (reserved for future
 * standardization) 58 (reserved for future standardization) 59 (reserved for future standardization) 60 ideogram underline or right side line

 * 61 ideogram double underline or double line on the right sid
 *e

 * 62 ideogram overline or left side line 63 ideogram double
 * overline or double line on the left side 64 ideogram
 * stress marking 65 cancels the effect of the rendition
 * aspects established by parameter values 60 to 64

 * NOTE The usable combinations of parameter values are determined
 * by the implementation.
 *
 */
#define SGR(Ps) CSI #Ps "m"

/*
 * SGR - SELECT GRAPHIC RENDITION

 * @ Parameters Required: 
 * No Parameter Required

 * @ More Info:
 * SGR is used to establish one or more graphic rendition aspects
 * for subsequent text. The established aspects remain in
 * effect until the next occurrence of SGR in the data
 * stream, depending on the setting of the GRAPHIC RENDITION
 * COMBINATION MODE (GRCM). Each graphic rendition aspect is
 * specified by a parameter value:

 * 0 default rendition (implementation-defined), cancels the
 * effect of any preceding occurrence of SGR in the data
 * stream regardless of the setting of the GRAPHIC RENDITION
 * COMBINATION MODE (GRCM) 1 bold or increased intensity 2
 * faint, decreased intensity or second colour 3 italicized 4
 * singly underlined 5 slowly blinking (less then 150 per
 * minute) 6 rapidly blinking (150 per minute or more) 7
 * negative image 8 concealed characters 9 crossed-out
 * (characters still legible but marked as to be deleted) 10
 * primary (default) font 11 first alternative font 12 second
 * alternative font 13 third alternative font 14 fourth
 * alternative font 15 fifth alternative font 16 sixth
 * alternative font 17 seventh alternative font 18 eighth
 * alternative font 19 ninth alternative font 20 Fraktur
 * (Gothic) 21 doubly underlined 22 normal colour or normal
 * intensity (neither bold nor faint) 23 not italicized, not
 * fraktur 24 not underlined (neither singly nor doubly) 25
 * steady (not blinking) 26 (reserved for proportional
 * spacing as specified in CCITT Recommendation T.61) 27 positive image 28 revealed characters

 * 29 not crossed out 30 black display 31 red display 32 green
 * display 33 yellow display 34 blue display 35 magenta
 * display 36 cyan display 37 white display 38 (reserved for
 * future standardization; intended for setting character
 * foreground colour as specified in ISO 8613-6 [CCITT
 * Recommendation T.416]) 39 default display colour
 * (implementation-defined) 40 black background 41 red
 * background 42 green background 43 yellow background 44
 * blue background 45 magenta background 46 cyan background
 * 47 white background 48 (reserved for future
 * standardization; intended for setting character background
 * colour as specified in ISO 8613-6 [CCITT Recommendation
 * T.416]) 49 default background colour
 * (implementation-defined) 50 (reserved for cancelling the
 * effect of the rendering aspect established by parameter
 * value 26) 51 framed 52 encircled 53 overlined 54 not
 * framed, not encircled 55 not overlined 56 (reserved for
 * future standardization) 57 (reserved for future
 * standardization) 58 (reserved for future standardization) 59 (reserved for future standardization) 60 ideogram underline or right side line

 * 61 ideogram double underline or double line on the right sid
 *e

 * 62 ideogram overline or left side line 63 ideogram double
 * overline or double line on the left side 64 ideogram
 * stress marking 65 cancels the effect of the rendition
 * aspects established by parameter values 60 to 64

 * NOTE The usable combinations of parameter values are determined
 * by the implementation.
 *
 */
#define _SGR_ CSI "m"

/*
 * SHS - SELECT CHARACTER SPACING

 * @ Parameters Required: 
 * Ps

 * @ More Info:
 * SHS is used to establish the character spacing for subsequent
 * text. The established spacing remains in effect until the
 * next occurrence of SHS or of SET CHARACTER SPACING (SCS)
 * or of SPACING INCREMENT (SPI) in the data stream. The
 * parameter values are

 * 0 10 characters per 25,4 mm

 * 1 12 characters per 25,4 mm

 * 2 15 characters per 25,4 mm

 * 3

 * 6 characters per 25,4 mm

 * 4

 * 3 characters per 25,4 mm

 * 5

 * 9 characters per 50,8 mm

 * 6

 * 4 characters per 25,4 mm
 *
 */
#define SHS(Ps) CSI #Ps " " "K"

/*
 * SHS - SELECT CHARACTER SPACING

 * @ Parameters Required: 
 * No Parameter Required

 * @ More Info:
 * SHS is used to establish the character spacing for subsequent
 * text. The established spacing remains in effect until the
 * next occurrence of SHS or of SET CHARACTER SPACING (SCS)
 * or of SPACING INCREMENT (SPI) in the data stream. The
 * parameter values are

 * 0 10 characters per 25,4 mm

 * 1 12 characters per 25,4 mm

 * 2 15 characters per 25,4 mm

 * 3

 * 6 characters per 25,4 mm

 * 4

 * 3 characters per 25,4 mm

 * 5

 * 9 characters per 50,8 mm

 * 6

 * 4 characters per 25,4 mm
 *
 */
#define _SHS_ CSI " " "K"

/*
 * SI - SHIFT-IN

 * @ Parameters Required: 
 * No Parameter Required

 * @ More Info:
 * SI is used for code extension purposes. It causes the meanings
 * of the bit combinations following it in the data stream to
 * be changed.

 * The use of SI is defined in Standard ECMA-35.

 * NOTE SI is used in 7-bit environments only; in 8-bit environments
 * LOCKING-SHIFT ZERO (LS0) is used instead.
 *
 */
#define SI "\x0f"

/*
 * SIMD - SELECT IMPLICIT MOVEMENT DIRECTION

 * @ Parameters Required: 
 * Ps

 * @ More Info:
 * SIMD is used to select the direction of implicit movement of
 * the data position relative to the character progression.
 * The direction selected remains in effect until the next
 * occurrence of SIMD. The parameter values are: 0 the
 * direction of implicit movement is the same as that of the
 * character progression 1 the direction of implicit movement
 * is opposite to that of the character progression.
 *
 */
#define SIMD(Ps) CSI #Ps "^"

/*
 * SIMD - SELECT IMPLICIT MOVEMENT DIRECTION

 * @ Parameters Required: 
 * No Parameter Required

 * @ More Info:
 * SIMD is used to select the direction of implicit movement of
 * the data position relative to the character progression.
 * The direction selected remains in effect until the next
 * occurrence of SIMD. The parameter values are: 0 the
 * direction of implicit movement is the same as that of the
 * character progression 1 the direction of implicit movement
 * is opposite to that of the character progression.
 *
 */
#define _SIMD_ CSI "^"

/*
 * SL - SCROLL LEFT

 * @ Parameters Required: 
 * Pn

 * @ More Info:
 * SL causes the data in the presentation component to be moved
 * by n character positions if the line orientation is
 * horizontal, or by n line positions if the line orientation
 * is vertical, such that the data appear to move to the
 * left; where n equals the value of Pn.

 * The active presentation position is not affected by this control
 * function.
 *
 */
#define SL(Pn) CSI #Pn " " "@"

/*
 * SL - SCROLL LEFT

 * @ Parameters Required: 
 * No Parameter Required

 * @ More Info:
 * SL causes the data in the presentation component to be moved
 * by n character positions if the line orientation is
 * horizontal, or by n line positions if the line orientation
 * is vertical, such that the data appear to move to the
 * left; where n equals the value of Pn.

 * The active presentation position is not affected by this control
 * function.
 *
 */
#define _SL_ CSI " " "@"

/*
 * SLH - SET LINE HOME

 * @ Parameters Required: 
 * Pn

 * @ More Info:
 * No parameter default value.

 * If the DEVICE COMPONENT SELECT MODE is set to PRESENTATION,
 * SLH is used to establish at character position n in the
 * active line (the line that contains the active
 * presentation position) and lines of subsequent text in the
 * presentation component the position to which the active
 * presentation position will be moved by subsequent
 * occurrences of CARRIAGE RETURN (CR), DELETE LINE (DL),
 * INSERT LINE (IL) or NEXT LINE (NEL) in the data stream;
 * where n equals the value of Pn. In the case of a device
 * without data component, it is also the position ahead of
 * which no implicit movement of the active presentation
 * position shall occur. If the DEVICE COMPONENT SELECT MODE
 * is set to DATA, SLH is used to establish at character
 * position n in the active line (the line that contains the
 * active data position) and lines of subsequent text in the
 * data component the position to which the active data
 * position will be moved by subsequent occurrences of
 * CARRIAGE RETURN (CR), DELETE LINE (DL), INSERT LINE (IL)
 * or NEXT LINE (NEL) in the data stream; where n equals the
 * value of Pn. It is also the position ahead of which no
 * implicit movement of the active data position shall occur.
 * The established position is called the line home position and remains in effect until the next occurrence of SLH in the data stream.
 *
 */
#define SLH(Pn) CSI #Pn " " "U"

/*
 * SLL - SET LINE LIMIT

 * @ Parameters Required: 
 * Pn

 * @ More Info:
 * No parameter default value.

 * If the DEVICE COMPONENT SELECT MODE is set to PRESENTATION,
 * SLL is used to establish at character position n in the
 * active line (the line that contains the active
 * presentation position) and lines of subsequent text in the
 * presentation component the position to which the active
 * presentation position will be moved by subsequent
 * occurrences of CARRIAGE RETURN (CR), or NEXT LINE (NEL) in
 * the data stream if the parameter value of SELECT IMPLICIT
 * MOVEMENT DIRECTION (SIMD) is equal to 1; where n equals
 * the value of Pn. In the case of a device without data
 * component, it is also the position beyond which no
 * implicit movement of the active presentation position
 * shall occur. If the DEVICE COMPONENT SELECT MODE is set to
 * DATA, SLL is used to establish at character position n in
 * the active line (the line that contains the active data
 * position) and lines of subsequent text in the data
 * component the position beyond which no implicit movement
 * of the active data position shall occur. It is also the
 * position in the data component to which the active data
 * position will be moved by subsequent occurrences of CR or
 * NEL in the data stream, if the parameter value of SELECT IMPLICIT MOVEMENT DIRECTION (SIMD) is equal to 1.

 * The established position is called the line limit position and
 * remains in effect until the next occurrence of SLL in the
 * data stream.
 *
 */
#define SLL(Pn) CSI #Pn " " "V"

/*
 * SLS - SET LINE SPACING

 * @ Parameters Required: 
 * Pn

 * @ More Info:
 * No parameter default value.

 * SLS is used to establish the line spacing for subsequent text.
 * The established spacing remains in effect until the next
 * occurrence of SLS or of SELECT LINE SPACING (SVS) or of
 * SPACING INCREMENT (SPI) in the data stream.

 * Pn specifies the line spacing.

 * The unit in which the parameter value is expressed is that
 * established by the parameter value of SELECT SIZE UNIT (SSU).
 *
 */
#define SLS(Pn) CSI #Pn " " "h"

/*
 * SM - SET MODE

 * @ Parameters Required: 
 * Ps

 * @ More Info:
 * No parameter default value.

 * SM causes the modes of the receiving device to be set as
 * specified by the parameter values:

 * 1 GUARDED AREA TRANSFER MODE (GATM)

 * 2 KEYBOARD ACTION MODE (KAM)

 * 3 CONTROL REPRESENTATION MODE (CRM)

 * 4 INSERTION REPLACEMENT MODE (IRM)

 * 5 STATUS REPORT TRANSFER MODE (SRTM)

 * 6 ERASURE MODE (ERM)

 * 7 LINE EDITING MODE (VEM)

 * 8 BI-DIRECTIONAL SUPPORT MODE (BDSM) 9 DEVICE COMPONENT SELECT
 * MODE (DCSM) 10 CHARACTER EDITING MODE (HEM)

 * 11 POSITIONING UNIT MODE (PUM) (see F.4.1 in annex F) 12
 * SEND/RECEIVE MODE (SRM)

 * 13 FORMAT EFFECTOR ACTION MODE (FEAM)

 * 14 FORMAT EFFECTOR TRANSFER MODE (FETM)

 * 15 MULTIPLE AREA TRANSFER MODE (MATM)

 * 16 TRANSFER TERMINATION MODE (TTM)

 * 17 SELECTED AREA TRANSFER MODE (SATM)

 * 18 TABULATION STOP MODE (TSM)

 * 19 (Shall not be used; see F.5.1 in annex F) 20 (Shall not be
 * used; see F.5.2 in annex F) 21 GRAPHIC RENDITION
 * COMBINATION (GRCM) 22 ZERO DEFAULT MODE (ZDM) (see F.4.2
 * in annex F) NOTE Private modes may be implemented using
 * private parameters, see 5.4.1 and 7.4.
 *
 */
#define SM(Ps) CSI #Ps "h"

/*
 * SO - SHIFT-OUT

 * @ Parameters Required: 
 * No Parameter Required

 * @ More Info:
 * SO is used for code extension purposes. It causes the meanings
 * of the bit combinations following it in the data stream to
 * be changed.

 * The use of SO is defined in Standard ECMA-35.

 * NOTE SO is used in 7-bit environments only; in 8-bit environments
 * LOCKING-SHIFT ONE (LS1) is used instead.
 *
 */
#define SO "\x0e"

/*
 * SOH - START OF HEADING

 * @ Parameters Required: 
 * No Parameter Required

 * @ More Info:
 * SOH is used to indicate the beginning of a heading.

 * The use of SOH is defined in ISO 1745.
 *
 */
#define SOH "\x01"

/*
 * SOS - START OF STRING

 * @ Parameters Required: 
 * No Parameter Required

 * @ More Info:
 * SOS is used as the opening delimiter of a control string. The
 * character string following may consist of any bit
 * combination, except those representing SOS or STRING
 * TERMINATOR (ST). The control string is closed by the
 * terminating delimiter STRING TERMINATOR (ST). The
 * interpretation of the character string depends on the application.
 *
 */
#define SOS ESC "X"

/*
 * SPA - START OF GUARDED AREA

 * @ Parameters Required: 
 * No Parameter Required

 * @ More Info:
 * SPA is used to indicate that the active presentation position
 * is the first of a string of character positions in the
 * presentation component, the contents of which are
 * protected against manual alteration, are guarded against
 * transmission or transfer, depending on the setting of the
 * GUARDED AREA TRANSFER MODE (GATM) and may be protected
 * against erasure, depending on the setting of the ERASURE
 * MODE (ERM). The end of this string is indicated by END OF GUARDED AREA (EPA).

 * NOTE The control functions for area definition (DAQ, EPA, ESA,
 * SPA, SSA) should not be used within an SRS string or an
 * SDS string.
 *
 */
#define SPA ESC "V"

/*
 * SPD - SELECT PRESENTATION DIRECTIONS

 * @ Parameters Required: 
 * Ps1, Ps2

 * @ More Info:
 * SPD is used to select the line orientation, the line progression,
 * and the character path in the presentation component. It
 * is also used to update the content of the presentation
 * component and the content of the data component. This
 * takes effect immediately. Ps1 specifies the line
 * orientation, the line progression and the character path: 0 line orientation:

 * horizontal

 * line progression: top-to-bottom

 * character path:

 * left-to-right 1 line orientation:

 * vertical

 * line progression: right-to-left

 * character path:

 * top-to-bottom 2 line orientation:

 * vertical

 * line progression: left-to-right

 * character path:

 * top-to-bottom 3 line orientation:

 * horizontal

 * line progression: top-to-bottom

 * character path:

 * right-to-left 4 line orientation:

 * vertical

 * line progression: left-to-right

 * character path:

 * bottom-to-top 5 line orientation:

 * horizontal

 * line progression: bottom-to-top

 * character path:

 * right-to-left

 * 6 line orientation:

 * horizontal

 * line progression: bottom-to-top

 * character path:

 * left-to-right 7 line orientation:

 * vertical

 * line progression: right-to-left

 * character path:

 * bottom-to-top Ps2 specifies the effect on the content of the
 * presentation component and the content of the data
 * component: 0 undefined (implementation-dependent) NOTE
 * This may also permit the effect to take place after the
 * next occurrence of CR, FF or any control function which
 * initiates an absolute movement of the active presentation
 * position or the active data position. 1 the content of the
 * presentation component is updated to correspond to the
 * content of the data component according to the newly
 * established characteristics of the presentation component;
 * the active data position is moved to the first character
 * position in the first line in the data component, the
 * active presentation position in the presentation component
 * is updated accordingly 2 the content of the data component
 * is updated to correspond to the content of the
 * presentation component according to the newly established
 * characteristics of the presentation component; the active
 * presentation position is moved to the first character
 * position in the first line in the presentation component, the active data position in the data component is updated accordingly.
 *
 */
#define SPD(Ps1, Ps2) CSI #Ps1 ";" #Ps2  " " "S"

/*
 * SPD - SELECT PRESENTATION DIRECTIONS

 * @ Parameters Required: 
 * Ps1

 * @ More Info:
 * SPD is used to select the line orientation, the line progression,
 * and the character path in the presentation component. It
 * is also used to update the content of the presentation
 * component and the content of the data component. This
 * takes effect immediately. Ps1 specifies the line
 * orientation, the line progression and the character path: 0 line orientation:

 * horizontal

 * line progression: top-to-bottom

 * character path:

 * left-to-right 1 line orientation:

 * vertical

 * line progression: right-to-left

 * character path:

 * top-to-bottom 2 line orientation:

 * vertical

 * line progression: left-to-right

 * character path:

 * top-to-bottom 3 line orientation:

 * horizontal

 * line progression: top-to-bottom

 * character path:

 * right-to-left 4 line orientation:

 * vertical

 * line progression: left-to-right

 * character path:

 * bottom-to-top 5 line orientation:

 * horizontal

 * line progression: bottom-to-top

 * character path:

 * right-to-left

 * 6 line orientation:

 * horizontal

 * line progression: bottom-to-top

 * character path:

 * left-to-right 7 line orientation:

 * vertical

 * line progression: right-to-left

 * character path:

 * bottom-to-top Ps2 specifies the effect on the content of the
 * presentation component and the content of the data
 * component: 0 undefined (implementation-dependent) NOTE
 * This may also permit the effect to take place after the
 * next occurrence of CR, FF or any control function which
 * initiates an absolute movement of the active presentation
 * position or the active data position. 1 the content of the
 * presentation component is updated to correspond to the
 * content of the data component according to the newly
 * established characteristics of the presentation component;
 * the active data position is moved to the first character
 * position in the first line in the data component, the
 * active presentation position in the presentation component
 * is updated accordingly 2 the content of the data component
 * is updated to correspond to the content of the
 * presentation component according to the newly established
 * characteristics of the presentation component; the active
 * presentation position is moved to the first character
 * position in the first line in the presentation component, the active data position in the data component is updated accordingly.
 *
 */
#define _SPD(Ps1) CSI #Ps1 ";" " " "S"

/*
 * SPD - SELECT PRESENTATION DIRECTIONS

 * @ Parameters Required: 
 * Ps2

 * @ More Info:
 * SPD is used to select the line orientation, the line progression,
 * and the character path in the presentation component. It
 * is also used to update the content of the presentation
 * component and the content of the data component. This
 * takes effect immediately. Ps1 specifies the line
 * orientation, the line progression and the character path: 0 line orientation:

 * horizontal

 * line progression: top-to-bottom

 * character path:

 * left-to-right 1 line orientation:

 * vertical

 * line progression: right-to-left

 * character path:

 * top-to-bottom 2 line orientation:

 * vertical

 * line progression: left-to-right

 * character path:

 * top-to-bottom 3 line orientation:

 * horizontal

 * line progression: top-to-bottom

 * character path:

 * right-to-left 4 line orientation:

 * vertical

 * line progression: left-to-right

 * character path:

 * bottom-to-top 5 line orientation:

 * horizontal

 * line progression: bottom-to-top

 * character path:

 * right-to-left

 * 6 line orientation:

 * horizontal

 * line progression: bottom-to-top

 * character path:

 * left-to-right 7 line orientation:

 * vertical

 * line progression: right-to-left

 * character path:

 * bottom-to-top Ps2 specifies the effect on the content of the
 * presentation component and the content of the data
 * component: 0 undefined (implementation-dependent) NOTE
 * This may also permit the effect to take place after the
 * next occurrence of CR, FF or any control function which
 * initiates an absolute movement of the active presentation
 * position or the active data position. 1 the content of the
 * presentation component is updated to correspond to the
 * content of the data component according to the newly
 * established characteristics of the presentation component;
 * the active data position is moved to the first character
 * position in the first line in the data component, the
 * active presentation position in the presentation component
 * is updated accordingly 2 the content of the data component
 * is updated to correspond to the content of the
 * presentation component according to the newly established
 * characteristics of the presentation component; the active
 * presentation position is moved to the first character
 * position in the first line in the presentation component, the active data position in the data component is updated accordingly.
 *
 */
#define __SPD(Ps2) CSI ";" #Ps2 " " "S"

/*
 * SPD - SELECT PRESENTATION DIRECTIONS

 * @ Parameters Required: 
 * No Parameter Required

 * @ More Info:
 * SPD is used to select the line orientation, the line progression,
 * and the character path in the presentation component. It
 * is also used to update the content of the presentation
 * component and the content of the data component. This
 * takes effect immediately. Ps1 specifies the line
 * orientation, the line progression and the character path: 0 line orientation:

 * horizontal

 * line progression: top-to-bottom

 * character path:

 * left-to-right 1 line orientation:

 * vertical

 * line progression: right-to-left

 * character path:

 * top-to-bottom 2 line orientation:

 * vertical

 * line progression: left-to-right

 * character path:

 * top-to-bottom 3 line orientation:

 * horizontal

 * line progression: top-to-bottom

 * character path:

 * right-to-left 4 line orientation:

 * vertical

 * line progression: left-to-right

 * character path:

 * bottom-to-top 5 line orientation:

 * horizontal

 * line progression: bottom-to-top

 * character path:

 * right-to-left

 * 6 line orientation:

 * horizontal

 * line progression: bottom-to-top

 * character path:

 * left-to-right 7 line orientation:

 * vertical

 * line progression: right-to-left

 * character path:

 * bottom-to-top Ps2 specifies the effect on the content of the
 * presentation component and the content of the data
 * component: 0 undefined (implementation-dependent) NOTE
 * This may also permit the effect to take place after the
 * next occurrence of CR, FF or any control function which
 * initiates an absolute movement of the active presentation
 * position or the active data position. 1 the content of the
 * presentation component is updated to correspond to the
 * content of the data component according to the newly
 * established characteristics of the presentation component;
 * the active data position is moved to the first character
 * position in the first line in the data component, the
 * active presentation position in the presentation component
 * is updated accordingly 2 the content of the data component
 * is updated to correspond to the content of the
 * presentation component according to the newly established
 * characteristics of the presentation component; the active
 * presentation position is moved to the first character
 * position in the first line in the presentation component, the active data position in the data component is updated accordingly.
 *
 */
#define _SPD_ CSI ";" " " "S"

/*
 * SPH - SET PAGE HOME

 * @ Parameters Required: 
 * Pn

 * @ More Info:
 * No parameter default value. If the DEVICE COMPONENT SELECT
 * MODE is set to PRESENTATION, SPH is used to establish at
 * line position n in the active page (the page that contains
 * the active presentation position) and subsequent pages in
 * the presentation component the position to which the
 * active presentation position will be moved by subsequent
 * occurrences of FORM FEED (FF) in the data stream; where n
 * equals the value of Pn. In the case of a device without
 * data component, it is also the position ahead of which no
 * implicit movement of the active presentation position
 * shall occur. If the DEVICE COMPONENT SELECT MODE is set to
 * DATA, SPH is used to establish at line position n in the
 * active page (the page that contains the active data
 * position) and subsequent pages in the data component the
 * position to which the active data position will be moved
 * by subsequent occurrences of FORM FEED (FF) in the data
 * stream; where n equals the value of Pn. It is also the
 * position ahead of which no implicit movement of the active
 * presentation position shall occur. The established
 * position is called the page home position and remains in effect until the next occurrence of SPH in the data stream.
 *
 */
#define SPH(Pn) CSI #Pn " " "i"

/*
 * SPI - SPACING INCREMENT

 * @ Parameters Required: 
 * Pn1, Pn2

 * @ More Info:
 * No parameter default values.

 * SPI is used to establish the line spacing and the character
 * spacing for subsequent text. The established line spacing
 * remains in effect until the next occurrence of SPI or of
 * SET LINE SPACING (SLS) or of SELECT LINE SPACING (SVS) in
 * the data stream. The established character spacing remains
 * in effect until the next occurrence of SET CHARACTER
 * SPACING (SCS) or of SELECT CHARACTER SPACING (SHS) in the
 * data stream, see annex C.

 * Pn1 specifies the line spacing

 * Pn2 specifies the character spacing

 * The unit in which the parameter values are expressed is that
 * established by the parameter value of SELECT SIZE UNIT (SSU)
 *
 * established by the parameter value of SELECT SIZE UNIT (SSU).
 *
 */
#define SPI(Pn1, Pn2) CSI #Pn1 ";" #Pn2 " " "G"

/*
 * SPL - SET PAGE LIMIT

 * @ Parameters Required: 
 * Pn

 * @ More Info:
 * No parameter default value. If the DEVICE COMPONENT SELECT
 * MODE is set to PRESENTATION, SPL is used to establish at
 * line position n in the active page (the page that contains
 * the active presentation position) and pages of subsequent
 * text in the presentation component the position beyond
 * which the active presentation position can normally not be
 * moved; where n equals the value of Pn. In the case of a
 * device without data component, it is also the position
 * beyond which no implicit movement of the active
 * presentation position shall occur. If the DEVICE COMPONENT
 * SELECT MODE is set to DATA, SPL is used to establish at
 * line position n in the active page (the page that contains
 * the active data position) and pages of subsequent text in
 * the data component the position beyond which no implicit
 * movement of the active data position shall occur.

 * The established position is called the page limit position and
 * remains in effect until the next occurrence of SPL in the
 * data stream.
 *
 */
#define SPL(Pn) CSI #Pn " " "j"

/*
 * SPQR - SELECT PRINT QUALITY AND RAPIDITY

 * @ Parameters Required: 
 * Ps

 * @ More Info:
 * SPQR is used to select the relative print quality and the print
 * speed for devices the output quality and speed of which
 * are inversely related. The selected values remain in
 * effect until the next occurrence of SPQR in the data
 * stream. The parameter values are

 * 0 highest available print quality, low print speed

 * 1 medium print quality, medium print speed

 * 2 draft print quality, highest available print speed
 *
 */
#define SPQR(Ps) CSI #Ps " " "X"

/*
 * SPQR - SELECT PRINT QUALITY AND RAPIDITY

 * @ Parameters Required: 
 * No Parameter Required

 * @ More Info:
 * SPQR is used to select the relative print quality and the print
 * speed for devices the output quality and speed of which
 * are inversely related. The selected values remain in
 * effect until the next occurrence of SPQR in the data
 * stream. The parameter values are

 * 0 highest available print quality, low print speed

 * 1 medium print quality, medium print speed

 * 2 draft print quality, highest available print speed
 *
 */
#define _SPQR_ CSI " " "X"

/*
 * SR - SCROLL RIGHT

 * @ Parameters Required: 
 * Pn

 * @ More Info:
 * SR causes the data in the presentation component to be moved
 * by n character positions if the line orientation is
 * horizontal, or by n line positions if the line orientation
 * is vertical, such that the data appear to move to the
 * right; where n equals the value of Pn.

 * The active presentation position is not affected by this control
 * function.
 *
 */
#define SR(Pn) CSI #Pn " " "A"

/*
 * SR - SCROLL RIGHT

 * @ Parameters Required: 
 * No Parameter Required

 * @ More Info:
 * SR causes the data in the presentation component to be moved
 * by n character positions if the line orientation is
 * horizontal, or by n line positions if the line orientation
 * is vertical, such that the data appear to move to the
 * right; where n equals the value of Pn.

 * The active presentation position is not affected by this control
 * function.
 *
 */
#define _SR_ CSI " " "A"

/*
 * SRCS - SET REDUCED CHARACTER SEPARATION

 * @ Parameters Required: 
 * Pn

 * @ More Info:
 * SRCS is used to establish reduced inter-character escapement
 * for subsequent text. The established reduced escapement
 * remains in effect until the next occurrence of SRCS or of
 * SET ADDITIONAL CHARACTER SEPARATION (SACS) in the data
 * stream or until it is reset to the default value by a
 * subsequent occurrence of CARRIAGE RETURN/LINE FEED (CR/LF)
 * or of NEXT LINE (NEL) in the data stream, see annex C.

 * Pn specifies the number of units by which the inter-character
 * escapement is reduced.

 * The unit in which the parameter values are expressed is that
 * established by the parameter value of SELECT SIZE UNIT (SSU)
 *
 * established by the parameter value of SELECT SIZE UNIT (SSU).
 *
 */
#define SRCS(Pn) CSI #Pn " " "f"

/*
 * SRCS - SET REDUCED CHARACTER SEPARATION

 * @ Parameters Required: 
 * No Parameter Required

 * @ More Info:
 * SRCS is used to establish reduced inter-character escapement
 * for subsequent text. The established reduced escapement
 * remains in effect until the next occurrence of SRCS or of
 * SET ADDITIONAL CHARACTER SEPARATION (SACS) in the data
 * stream or until it is reset to the default value by a
 * subsequent occurrence of CARRIAGE RETURN/LINE FEED (CR/LF)
 * or of NEXT LINE (NEL) in the data stream, see annex C.

 * Pn specifies the number of units by which the inter-character
 * escapement is reduced.

 * The unit in which the parameter values are expressed is that
 * established by the parameter value of SELECT SIZE UNIT (SSU)
 *
 * established by the parameter value of SELECT SIZE UNIT (SSU).
 *
 */
#define _SRCS_ CSI " " "f"

/*
 * SRS - START REVERSED STRING

 * @ Parameters Required: 
 * Ps

 * @ More Info:
 * SRS is used to establish in the data component the beginning
 * and the end of a string of characters as well as the
 * direction of the string. This direction is opposite to
 * that currently established. The indicated string follows
 * the preceding text. The established character progression
 * is not affected. The beginning of a reversed string is
 * indicated by SRS with a parameter value of 1. A reversed
 * string may contain one or more nested strings. These
 * nested strings may be reversed strings the beginnings of
 * which are indicated by SRS with a parameter value of 1, or
 * directed strings the beginnings of which are indicated by
 * START DIRECTED STRING (SDS) with a parameter value not
 * equal to 0. Every beginning of such a string invokes the
 * next deeper level of nesting. This Standard does not
 * define the location of the active data position within any
 * such nested string. The end of a reversed string is
 * indicated by SRS with a parameter value of 0. Every end of
 * such a string re-establishes the next higher level of
 * nesting (the one in effect prior to the string just
 * ended). The direction is re-established to that in effect
 * prior to the string just ended. The active data position
 * is moved to the character position following the
 * characters of the string just ended. The parameter values
 * are: 0 end of a reversed string; re-establish the previous
 * direction 1 beginning of a reversed string; reverse the
 * direction. NOTE 1 The effect of receiving a CVT, HT, SCP,
 * SPD or VT control function within an SRS string is not
 * defined by this Standard. NOTE 2 The control functions for area definition (DAQ, EPA, ESA, SPA, SSA) should not be used within an SRS string.
 *
 */
#define SRS(Ps) CSI #Ps "["

/*
 * SRS - START REVERSED STRING

 * @ Parameters Required: 
 * No Parameter Required

 * @ More Info:
 * SRS is used to establish in the data component the beginning
 * and the end of a string of characters as well as the
 * direction of the string. This direction is opposite to
 * that currently established. The indicated string follows
 * the preceding text. The established character progression
 * is not affected. The beginning of a reversed string is
 * indicated by SRS with a parameter value of 1. A reversed
 * string may contain one or more nested strings. These
 * nested strings may be reversed strings the beginnings of
 * which are indicated by SRS with a parameter value of 1, or
 * directed strings the beginnings of which are indicated by
 * START DIRECTED STRING (SDS) with a parameter value not
 * equal to 0. Every beginning of such a string invokes the
 * next deeper level of nesting. This Standard does not
 * define the location of the active data position within any
 * such nested string. The end of a reversed string is
 * indicated by SRS with a parameter value of 0. Every end of
 * such a string re-establishes the next higher level of
 * nesting (the one in effect prior to the string just
 * ended). The direction is re-established to that in effect
 * prior to the string just ended. The active data position
 * is moved to the character position following the
 * characters of the string just ended. The parameter values
 * are: 0 end of a reversed string; re-establish the previous
 * direction 1 beginning of a reversed string; reverse the
 * direction. NOTE 1 The effect of receiving a CVT, HT, SCP,
 * SPD or VT control function within an SRS string is not
 * defined by this Standard. NOTE 2 The control functions for area definition (DAQ, EPA, ESA, SPA, SSA) should not be used within an SRS string.
 *
 */
#define _SRS_ CSI "["

/*
 * SSA - START OF SELECTED AREA

 * @ Parameters Required: 
 * No Parameter Required

 * @ More Info:
 * SSA is used to indicate that the active presentation position
 * is the first of a string of character positions in the
 * presentation component, the contents of which are eligible
 * to be transmitted in the form of a data stream or
 * transferred to an auxiliary input/output device.

 * The end of this string is indicated by END OF SELECTED AREA
 * (ESA). The string of characters actually transmitted or
 * transferred depends on the setting of the GUARDED AREA
 * TRANSFER MODE (GATM) and on any guarded areas established
 * by DEFINE AREA QUALIFICATION (DAQ), or by START OF GUARDED
 * AREA (SPA) and END OF GUARDED AREA (EPA).

 * NOTE The control functions for area definition (DAQ, EPA, ESA,
 * SPA, SSA) should not be used within an SRS string or an
 * SDS string.
 *
 */
#define SSA ESC "F"

/*
 * SSU - SELECT SIZE UNIT

 * @ Parameters Required: 
 * Ps

 * @ More Info:
 * SSU is used to establish the unit in which the numeric parameters
 * of certain control functions are expressed. The
 * established unit remains in effect until the next
 * occurrence of SSU in the data stream.

 * The parameter values are

 * 0 CHARACTER

 * - The dimensions of this unit are device-dependent 1 MILLIMETR
 *E

 * 2 COMPUTER DECIPOINT - 0,035 28 mm (1/720 of 25,4 mm)

 * 3 DECIDIDOT - 0,037 59 mm (10/266 mm)

 * 4 MIL - 0,025 4 mm (1/1 000 of 25,4 mm)

 * 5 BASIC MEASURING UNIT (BMU) - 0,021 17 mm (1/1 200 of 25,4 mm
 *
 * mm)

 * 6 MICROMETRE - 0,001 mm

 * 7 PIXEL - The smallest increment that can be specified in a devic
 *
 * device

 * 8 DECIPOINT - 0,035 14 mm (35/996 mm)
 *
 */
#define SSU(Ps) CSI #Ps " " "I"

/*
 * SSU - SELECT SIZE UNIT

 * @ Parameters Required: 
 * No Parameter Required

 * @ More Info:
 * SSU is used to establish the unit in which the numeric parameters
 * of certain control functions are expressed. The
 * established unit remains in effect until the next
 * occurrence of SSU in the data stream.

 * The parameter values are

 * 0 CHARACTER

 * - The dimensions of this unit are device-dependent 1 MILLIMETR
 *E

 * 2 COMPUTER DECIPOINT - 0,035 28 mm (1/720 of 25,4 mm)

 * 3 DECIDIDOT - 0,037 59 mm (10/266 mm)

 * 4 MIL - 0,025 4 mm (1/1 000 of 25,4 mm)

 * 5 BASIC MEASURING UNIT (BMU) - 0,021 17 mm (1/1 200 of 25,4 mm
 *
 * mm)

 * 6 MICROMETRE - 0,001 mm

 * 7 PIXEL - The smallest increment that can be specified in a devic
 *
 * device

 * 8 DECIPOINT - 0,035 14 mm (35/996 mm)
 *
 */
#define _SSU_ CSI " " "I"

/*
 * SSW - SET SPACE WIDTH

 * @ Parameters Required: 
 * Pn

 * @ More Info:
 * No parameter default value.

 * SSW is used to establish for subsequent text the character
 * escapement associated with the character SPACE. The
 * established escapement remains in effect until the next
 * occurrence of SSW in the data stream or until it is reset
 * to the default value by a subsequent occurrence of
 * CARRIAGE RETURN/LINE FEED (CR/LF), CARRIAGE RETURN/FORM
 * FEED (CR/FF), or of NEXT LINE (NEL) in the data stream, see annex C.

 * Pn specifies the escapement.

 * The unit in which the parameter value is expressed is that
 * established by the parameter value of SELECT SIZE UNIT
 * (SSU). The default character escapement of SPACE is
 * specified by the most recent occurrence of SET CHARACTER
 * SPACING (SCS) or of SELECT CHARACTER SPACING (SHS) or of
 * SELECT SPACING INCREMENT (SPI) in the data stream if the
 * current font has constant spacing, or is specified by the
 * nominal width of the character SPACE in the current font
 * if that font has proportional spacing.
 *
 */
#define SSW(Pn) CSI #Pn " " "["

/*
 * SS2 - SINGLE-SHIFT TWO

 * @ Parameters Required: 
 * No Parameter Required

 * @ More Info:
 * SS2 is used for code extension purposes. It causes the meanings
 * of the bit combinations following it in the data stream to
 * be changed. The use of SS2 is defined in Standard
 * ECMA-35.
 *
 */
#define SS2 ESC "N"

/*
 * SS3 - SINGLE-SHIFT THREE

 * @ Parameters Required: 
 * No Parameter Required

 * @ More Info:
 * SS3 is used for code extension purposes. It causes the meanings
 * of the bit combinations following it in the data stream to
 * be changed. The use of SS3 is defined in Standard
 * ECMA-35.
 *
 */
#define SS3 ESC "O"

/*
 * ST - STRING TERMINATOR

 * @ Parameters Required: 
 * No Parameter Required

 * @ More Info:
 * ST is used as the closing delimiter of a control string opened
 * by APPLICATION PROGRAM COMMAND (APC), DEVICE CONTROL
 * STRING (DCS), OPERATING SYSTEM COMMAND (OSC), PRIVACY
 * MESSAGE (PM), or START OF STRING (SOS).
 *
 */
#define ST ESC "\\"

/*
 * STAB - SELECTIVE TABULATION

 * @ Parameters Required: 
 * Ps

 * @ More Info:
 * No parameter default value.

 * STAB causes subsequent text in the presentation component to
 * be aligned according to the position and the properties of
 * a tabulation stop which is selected from a list according
 * to the value of the parameter Ps.

 * The use of this control function and means of specifying a
 * list of tabulation stops to be referenced by the control
 * function are specified in other standards, for example ISO
 * 8613-6.
 *
 */
#define STAB(Ps) CSI #Ps " " "^"

/*
 * STS - SET TRANSMIT STATE

 * @ Parameters Required: 
 * No Parameter Required

 * @ More Info:
 * STS is used to establish the transmit state in the receiving
 * device. In this state the transmission of data from the
 * device is possible.

 * The actual initiation of transmission of data is performed by
 * a data communication or input/output interface control
 * procedure which is outside the scope of this Standard.

 * The transmit state is established either by STS appearing in
 * the received data stream or by the operation of an
 * appropriate key on a keyboard.
 *
 */
#define STS ESC "S"

/*
 * STX - START OF TEXT

 * @ Parameters Required: 
 * No Parameter Required

 * @ More Info:
 * STX is used to indicate the beginning of a text and the end
 * of a heading.

 * The use of STX is defined in ISO 1745.
 *
 */
#define STX "\x02"

/*
 * SU - SCROLL UP

 * @ Parameters Required: 
 * Pn

 * @ More Info:
 * SU causes the data in the presentation component to be moved
 * by n line positions if the line orientation is horizontal,
 * or by n character positions if the line orientation is
 * vertical, such that the data appear to move up; where n
 * equals the value of Pn.

 * The active presentation position is not affected by this control
 * function.
 *
 */
#define SU(Pn) CSI #Pn "S"

/*
 * SU - SCROLL UP

 * @ Parameters Required: 
 * No Parameter Required

 * @ More Info:
 * SU causes the data in the presentation component to be moved
 * by n line positions if the line orientation is horizontal,
 * or by n character positions if the line orientation is
 * vertical, such that the data appear to move up; where n
 * equals the value of Pn.

 * The active presentation position is not affected by this control
 * function.
 *
 */
#define _SU_ CSI "S"

/*
 * SUB - SUBSTITUTE

 * @ Parameters Required: 
 * No Parameter Required

 * @ More Info:
 * SUB is used in the place of a character that has been found
 * to be invalid or in error. SUB is intended to be
 * introduced by automatic means.
 *
 */
#define SUB "\x1a"

/*
 * SVS - SELECT LINE SPACING

 * @ Parameters Required: 
 * Ps

 * @ More Info:
 * SVS is used to establish the line spacing for subsequent text.
 * The established spacing remains in effect until the next
 * occurrence of SVS or of SET LINE SPACING (SLS) or of
 * SPACING INCREMENT (SPI) in the data stream. The parameter
 * values are:

 * 0 6 lines per 25,4 mm

 * 1 4 lines per 25,4 mm

 * 2 3 lines per 25,4 mm

 * 3 12 lines per 25,4 mm

 * 4 8 lines per 25,4 mm

 * 5 6 lines per 30,0 mm

 * 6 4 lines per 30,0 mm

 * 7 3 lines per 30,0 mm

 * 8 12 lines per 30,0 mm

 * 9 2 lines per 25,4 mm
 *
 */
#define SVS(Ps) CSI #Ps " " "L"

/*
 * SVS - SELECT LINE SPACING

 * @ Parameters Required: 
 * No Parameter Required

 * @ More Info:
 * SVS is used to establish the line spacing for subsequent text.
 * The established spacing remains in effect until the next
 * occurrence of SVS or of SET LINE SPACING (SLS) or of
 * SPACING INCREMENT (SPI) in the data stream. The parameter
 * values are:

 * 0 6 lines per 25,4 mm

 * 1 4 lines per 25,4 mm

 * 2 3 lines per 25,4 mm

 * 3 12 lines per 25,4 mm

 * 4 8 lines per 25,4 mm

 * 5 6 lines per 30,0 mm

 * 6 4 lines per 30,0 mm

 * 7 3 lines per 30,0 mm

 * 8 12 lines per 30,0 mm

 * 9 2 lines per 25,4 mm
 *
 */
#define _SVS_ CSI " " "L"

/*
 * SYN - SYNCHRONOUS IDLE

 * @ Parameters Required: 
 * No Parameter Required

 * @ More Info:
 * SYN is used by a synchronous transmission system in the absence
 * of any other character (idle condition) to provide a
 * signal from which synchronism may be achieved or retained
 * between data terminal equipment.

 * The use of SYN is defined in ISO 1745.
 *
 */
#define SYN "\x16"

/*
 * TAC - TABULATION ALIGNED CENTRED

 * @ Parameters Required: 
 * Pn

 * @ More Info:
 * No parameter default value.

 * TAC causes a character tabulation stop calling for centring
 * to be set at character position n in the active line (the
 * line that contains the active presentation position) and
 * lines of subsequent text in the presentation component,
 * where n equals the value of Pn. TAC causes the replacement
 * of any tabulation stop previously set at that character
 * position, but does not affect other tabulation stops.

 * A text string centred upon a tabulation stop set by TAC will
 * be positioned so that the (trailing edge of the) first
 * graphic character and the (leading edge of the) last
 * graphic character are at approximately equal distances
 * from the tabulation stop.
 *
 */
#define TAC(Pn) CSI #Pn " " "b"

/*
 * TALE - TABULATION ALIGNED LEADING EDGE

 * @ Parameters Required: 
 * Pn

 * @ More Info:
 * No parameter default value.

 * TALE causes a character tabulation stop calling for leading
 * edge alignment to be set at character position n in the
 * active line (the line that contains the active
 * presentation position) and lines of subsequent text in the
 * presentation component, where n equals the value of Pn.
 * TALE causes the replacement of any tabulation stop
 * previously set at that character position, but does not affect other tabulation stops.

 * A text string aligned with a tabulation stop set by TALE will
 * be positioned so that the (leading edge of the) last
 * graphic character of the string is placed at the tabulation stop.
 *
 */
#define TALE(Pn) CSI #Pn " " "a"

/*
 * TATE - TABULATION ALIGNED TRAILING EDGE

 * @ Parameters Required: 
 * Pn

 * @ More Info:
 * No parameter default value.

 * TATE causes a character tabulation stop calling for trailing
 * edge alignment to be set at character position n in the
 * active line (the line that contains the active
 * presentation position) and lines of subsequent text in the
 * presentation component, where n equals the value of Pn.
 * TATE causes the replacement of any tabulation stop
 * previously set at that character position, but does not affect other tabulation stops.

 * A text string aligned with a tabulation stop set by TATE will
 * be positioned so that the (trailing edge of the) first
 * graphic character of the string is placed at the
 * tabulation stop.
 *
 */
#define TATE(Pn) CSI #Pn " " "`"

/*
 * TBC - TABULATION CLEAR

 * @ Parameters Required: 
 * Ps

 * @ More Info:
 * TBC causes one or more tabulation stops in the presentation
 * component to be cleared, depending on the parameter value:

 * 0 the character tabulation stop at the active presentation
 * position is cleared

 * 1 the line tabulation stop at the active line is cleared

 * 2 all character tabulation stops in the active line are cleare
 *d

 * 3 all character tabulation stops are cleared

 * 4 all line tabulation stops are cleared

 * 5 all tabulation stops are cleared In the case of parameter
 * value 0 or 2 the number of lines affected depends on the
 * setting of the TABULATION STOP MODE (TSM)
 *
 */
#define TBC(Ps) CSI #Ps "g"

/*
 * TBC - TABULATION CLEAR

 * @ Parameters Required: 
 * No Parameter Required

 * @ More Info:
 * TBC causes one or more tabulation stops in the presentation
 * component to be cleared, depending on the parameter value:

 * 0 the character tabulation stop at the active presentation
 * position is cleared

 * 1 the line tabulation stop at the active line is cleared

 * 2 all character tabulation stops in the active line are cleare
 *d

 * 3 all character tabulation stops are cleared

 * 4 all line tabulation stops are cleared

 * 5 all tabulation stops are cleared In the case of parameter
 * value 0 or 2 the number of lines affected depends on the
 * setting of the TABULATION STOP MODE (TSM)
 *
 */
#define _TBC_ CSI "g"

/*
 * TCC - TABULATION CENTRED ON CHARACTER

 * @ Parameters Required: 
 * Pn1, Pn2

 * @ More Info:
 * TCC causes a character tabulation stop calling for alignment
 * of a target graphic character to be set at character
 * position n in the active line (the line that contains the
 * active presentation position) and lines of subsequent text
 * in the presentation component, where n equals the value of
 * Pn1, and the target character about which centring is to
 * be performed is specified by Pn2. TCC causes the
 * replacement of any tabulation stop previously set at that
 * character position, but does not affect other tabulation stops.

 * The positioning of a text string aligned with a tabulation
 * stop set by TCC will be determined by the first occurrence
 * in the string of the target graphic character; that
 * character will be centred upon the tabulation stop. If the
 * target character does not occur within the string, then
 * the trailing edge of the first character of the string
 * will be positioned at the tabulation stop.

 * The value of Pn2 indicates the code table position (binary
 * value) of the target character in the currently invoked
 * code. For a 7-bit code, the permissible range of values is
 * 32 to 127; for an 8-bit code, the permissible range of
 * values is 32 to 127 and 160 to 255.
 *
 */
#define TCC(Pn1, Pn2) CSI #Pn1 ";" #Pn2 " " "c"

/*
 * TCC - TABULATION CENTRED ON CHARACTER

 * @ Parameters Required: 
 * Pn1

 * @ More Info:
 * TCC causes a character tabulation stop calling for alignment
 * of a target graphic character to be set at character
 * position n in the active line (the line that contains the
 * active presentation position) and lines of subsequent text
 * in the presentation component, where n equals the value of
 * Pn1, and the target character about which centring is to
 * be performed is specified by Pn2. TCC causes the
 * replacement of any tabulation stop previously set at that
 * character position, but does not affect other tabulation stops.

 * The positioning of a text string aligned with a tabulation
 * stop set by TCC will be determined by the first occurrence
 * in the string of the target graphic character; that
 * character will be centred upon the tabulation stop. If the
 * target character does not occur within the string, then
 * the trailing edge of the first character of the string
 * will be positioned at the tabulation stop.

 * The value of Pn2 indicates the code table position (binary
 * value) of the target character in the currently invoked
 * code. For a 7-bit code, the permissible range of values is
 * 32 to 127; for an 8-bit code, the permissible range of
 * values is 32 to 127 and 160 to 255.
 *
 */
#define _TCC(Pn1) CSI #Pn1 ";" " " "c"

/*
 * TSR - TABULATION STOP REMOVE

 * @ Parameters Required: 
 * Pn

 * @ More Info:
 * No parameter default value.

 * TSR causes any character tabulation stop at character position
 * n in the active line (the line that contains the active
 * presentation position) and lines of subsequent text in the
 * presentation component to be cleared, but does not affect
 * other tabulation stops. n equals the value of Pn.
 *
 */
#define TSR(Pn) CSI #Pn " " "d"

/*
 * TSS - THIN SPACE SPECIFICATION

 * @ Parameters Required: 
 * Pn

 * @ More Info:
 * No parameter default value.

 * TSS is used to establish the width of a thin space for subsequent
 * text. The established width remains in effect until the
 * next occurrence of TSS in the data stream, see annex C.

 * Pn specifies the width of the thin space.

 * The unit in which the parameter value is expressed is that
 * established by the parameter value of SELECT SIZE UNIT (SSU).
 *
 */
#define TSS(Pn) CSI #Pn " " "E"

/*
 * VPA - LINE POSITION ABSOLUTE

 * @ Parameters Required: 
 * Pn

 * @ More Info:
 * VPA causes the active data position to be moved to line position
 * n in the data component in a direction parallel to the
 * line progression, where n equals the value of Pn.
 *
 */
#define VPA(Pn) CSI #Pn "d"

/*
 * VPA - LINE POSITION ABSOLUTE

 * @ Parameters Required: 
 * No Parameter Required

 * @ More Info:
 * VPA causes the active data position to be moved to line position
 * n in the data component in a direction parallel to the
 * line progression, where n equals the value of Pn.
 *
 */
#define _VPA_ CSI "d"

/*
 * VPB - LINE POSITION BACKWARD

 * @ Parameters Required: 
 * Pn

 * @ More Info:
 * VPB causes the active data position to be moved by n line
 * positions in the data component in a direction opposite to
 * that of the line progression, where n equals the value of Pn.
 *
 */
#define VPB(Pn) CSI #Pn "k"

/*
 * VPB - LINE POSITION BACKWARD

 * @ Parameters Required: 
 * No Parameter Required

 * @ More Info:
 * VPB causes the active data position to be moved by n line
 * positions in the data component in a direction opposite to
 * that of the line progression, where n equals the value of Pn.
 *
 */
#define _VPB_ CSI "k"

/*
 * VPR - LINE POSITION FORWARD

 * @ Parameters Required: 
 * Pn

 * @ More Info:
 * VPR causes the active data position to be moved by n line
 * positions in the data component in a direction parallel to
 * the line progression, where n equals the value of Pn.
 *
 */
#define VPR(Pn) CSI #Pn "e"

/*
 * VPR - LINE POSITION FORWARD

 * @ Parameters Required: 
 * No Parameter Required

 * @ More Info:
 * VPR causes the active data position to be moved by n line
 * positions in the data component in a direction parallel to
 * the line progression, where n equals the value of Pn.
 *
 */
#define _VPR_ CSI "e"

/*
 * VT - LINE TABULATION

 * @ Parameters Required: 
 * No Parameter Required

 * @ More Info:
 * VT causes the active presentation position to be moved in the
 * presentation component to the corresponding character
 * position on the line at which the following line
 * tabulation stop is set.
 *
 */
#define VT "\x0b"

/*
 * VTS - LINE TABULATION SET

 * @ Parameters Required: 
 * No Parameter Required

 * @ More Info:
 * VTS causes a line tabulation stop to be set at the active line
 * (the line that contains the active presentation position)
 *
 */
#define VTS ESC "J"

