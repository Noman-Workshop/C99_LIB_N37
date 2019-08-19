/**
# Created By: Noman^Alien#0637 
# Created On: 4/9/2019; 9:44 AM
*/

#ifndef UTIL_STRING_H
#define UTIL_STRING_H

#include <stdInclude.h>

/**
 *
 * @param str
 * @return
 */
char *str_toggleCase(const char *str);

/**
 * Removes the delimiter substring from the start and end of provided string
 * @param string 		the string to be trimmed
 * @param delimiter		substring to cut from the ends of string
 * @return				trimmed string
 */
char *str_trim(const char *string, const char *delimiter);

/**
 * Splits a String into desired no of tokens using Delimiter
 *
 * @param str 		Pointer to the String which will be split
 * @param delimiter The separator string
 * @param ... 		Maximum no of split instances
 * @return 			Pointer to the array of split string
 * 					along with total number of split strings.
 */
char **str_split(const char *str, const char *delimiter, ...);

#endif


