/**
# Created By: Noman^Alien#0637
# Created On: 6/12/2018; 6:47 AM
*/

#include <stdio.h>
#include <stdlib.h>

#ifndef UTIL_EXCEPTION_HANDLE
#define EXCEPTION_HANDLE "exceptionHandling.h"

#include EXCEPTION_HANDLE"exceptionHandling.h"


#endif
#ifndef UTIL_LINKED_LIST
#define UTIL_LINKED_LIST "linkedList.h"

#include UTIL_LINKED_LIST"linkedList.h""linkedList.h""linkedList.c"

#endif

#ifndef UTIL_CUSTOM_MATH_LIB
#define UTIL_CUSTOM_MATH_LIB "customMathLib.h"

#include UTIL_CUSTOM_MATH_LIB"customMathLib.h""customMathLib.h"

#endif

#define STR_INT int

#define TAB_SPACE_COUNT 4



/**
 * @brief coverts an English character to upper case form
 * @param c the character to be transformed
 * @return the upper case form
 *
 * @warning the character must be from English Language and defined in ASCII char table
 */
char toUpper(char c) {
    if (c >= 65 && c <= 90)
        // already in upper case
        return c;
    if (c >= 97 && c <= 122)
        return (char) (c - 32);
    else {
        warnError(UnSuppChar);
        return c;
    }
}

/**
 * @brief coverts an English character to lower case form
 * @param c the character to be transformed
 * @return the lower case form
 *
 * @warning the character must be from English Language and defined in ASCII char table
 */
char toLower(char c) {
    if (c >= 97 && c <= 122) {
        // already in lower case
        return c;
    }
    if (c >= 65 && c <= 90) {
        return (char) (c + 32);
    } else {
        warnError(UnSuppChar);
        return c;
    }
}

/**
 * @brief calculates the length of the string
 * @param str the string
 * @return string length
 */
size_t strLen(const char *str) {
    size_t i;
    for (i = 0; str[i] != '\0'; i++);
    return i;
}

/**
 * @brief converts the String into UpperCase
 * @param str the String
 * @related toUpper(char c);
 * @returns the string in uppercase
 */
char *toUpperCase(char *str) {
    int i;
    char *dest;
    for (i = 0; i < strLen(str); i++) {
        dest[i] = toUpper(str[i]);
    }
    dest[i] = '\0';

    return dest;
}

/**
 * @brief converts the String into lowerCase
 * @param str the String
 * @related toLower(char c);
 * @returns the string in lowerCase
 */
char *toLowerCase(char *str) {
    char *dest;
    int i;
    for (i = 0; i < strLen(str); i++) {
        dest[i] = toLower(str[i]);
    }

    dest[i] = '\0';
    return dest;
}

void printXChar(STR_INT len, char c) {
    for (int i = 0; i < len; i++) {
        printf("%c", c);
    }
}


void printAligned(const char *str, const STR_INT boundary, const char alignment) {
    if (boundary < strlen(str)) {
        printf("Boundary is less than string length\n");
        errorExit(BoundaryError);
    }

    if (alignment == 'r') {
        printXChar((STR_INT) (boundary - strlen(str)), ' ');
        printf("%s", str);
    } else if (alignment == 'l') {
        printf("%s", str);
        printXChar((STR_INT) (boundary - strlen(str)), ' ');
    } else {
        errorExit(UnSuppChar);
    }


}

STR_INT getMaxStrLenIndex(const char **strArr, const int len) {
    STR_INT maxLen = 0;
    for (STR_INT i = 0; i < len; i++) {
        size_t temp = strLen(strArr[i]);
        if (temp > maxLen) {
            maxLen = (int) temp;
        }
    }

    return maxLen;
}

lList *getIndex(const char *str, const char c) {
    lList *list = NULL;
    size_t len = strLen(str);
    for (int i = 0; i < len; i++) {
        if (str[i] == c) {
            list = ll_append(list, i);
        }
    }
    return list;
}

char *strCpyRange(const char *str, const int start, const int end) {
    int size = end - start + 1;
    char *copy = malloc(sizeof(char) * size);
    for (int i = start, ii = 0; ii < size - 1; i++, ii++) {
        copy[ii] = str[i];
    }
    copy[size - 1] = '\0';

    return copy;
}


char **charSplit(const char *str, const char c, int count) {
    lList *list = getIndex(str, c);
    // if the list is null then there is no match
    if (!list) {
        return NULL;
    }

    int nMatches = ll_getLen(list);
    if (count > nMatches || count < 0) {
        count = nMatches;
    }

    // allocating dynamic memory for the subString Array
    char **subStr = malloc(sizeof(char *) * (count + 1));

    int i = 0, lBound = 0, uBound = ll_getElem(list, i);

    do {
        subStr[i++] = strCpyRange(str, lBound, uBound);
    } while ((i != count) && ((lBound = uBound) | (uBound = ll_getElem(list, i)) | 1));

    subStr[i] = strCpyRange(str, uBound + 1, (const int) strLen(str));

    return subStr;

}

int charToInt(char c) {

    if (c > '0' || c < '9') {
        return c - '0';
    } else
        errorExit(UnIntChar);
}

STR_INT strToInt(const char *strInt) {
    size_t length;
    size_t i;
    int sign;
    length = strLen(strInt);
    if (strInt[0] == '-') {
        i = 1;
        sign = -1;
    } else {
        i = 0;
        sign = 1;
    }
    STR_INT result = 0;
    char c = strInt[i];
    for (; i < length; i++, c = strInt[i]) {
        result += charToInt(c) * powOf10((int) (length - i - 1));
    }

    return result * sign;

}

/**
 * @brief shows the count of some characters on
 * @param data an array of count of ASCII characters in order form 0 to 127
 * @returns The auto focus count shows the count of <br>
 * <i>i.  </i> <b>characters</b>
 * <i>ii. </i> <b>words</b>
 * <i>iii.</i> <b>line</b>
 * <i>iv. </i> <b>tabs</b>
 * <i>v.  </i> <b>digits</b>
 * <i>vi. </i> <b>special characters</b>
 * @see the data array can be found by calling -> <i>int *getStatistics(FILE *file); </i>
 *
 */
void getAutoFocusCount(int *data) {
    int nc, nw, nl, nt, nd, ns;
    nc = nd = 0;
    // counting Characters
    for (int i = 0; i < 128; i++) {
        nc += data[i];
    }
    printf("Total No of Characters: %d\n", nc);

    // Word Count todo word count should be improved
    nw = data[' '] + 1;     // toKnow there is a space between two words
    printf("Total No. of Words: %d\n", nw);

    // Digit count
    for (int i = 48; i < 58; i++) {
        nd += data[i];
    }
    printf("Digits appeared: %d times\n", nd);

    // tab count
    nt = data['\t']; // todo tab counting needs to be improved
    printf("Total Tab Count: %d\n", nt);

    // new line count
    nl = data['\n'];
    printf("Total No. of New Lines: %d\n", nl);

    // special Characters Count
    ns = data['!'] + data['@'] + data['#'] +
         data['$'] + data['%'] + data['^'] +
         data['&'] + data['*'] + data['('] +
         data[')'] + data['_'] + data['+'];
    printf("Special Character Count: %d\n", ns);
}

/**
 * @brief get the number of invisibles excluding spaces
 * @param str the string to be searched
 * @return the count of <b>tabs, new lines, backspaces</b>
 */
size_t getInvCount(char *str) {
    size_t count = 0;
    size_t len = strLen(str);
    for (int i = 0; i < len; i++) {
        if (str[i] == '\t' || str[i] == '\n' || str[i] == '\b') {
            count++;
        }
    }
    return count;
}

/**
 * @brief converts the string by replacing tabs, newline etc. by t, n etc.
 * @param orgStr organic String
 * @return the raw String which is "" supported
 */
char *toRaw(char *orgStr) {
    size_t size = strLen(orgStr) + getInvCount(orgStr) + 1;
    char *rawStr = malloc(size * sizeof(char));
    for (int i = 0, j = 0, c; (c = orgStr[i]) != '\0'; i++, j++) {
        switch ((char) c) {
            case '\t':
                rawStr[j++] = '\\';
                rawStr[j] = 't';
                break;

            case '\n':
                rawStr[j++] = '\\';
                rawStr[j] = 'n';
                break;

            case '\b':
                rawStr[j++] = '\\';
                rawStr[j] = 'b';
                break;

            default:
                rawStr[j] = (char) c;
                break;

        }
    }
    rawStr[size] = '\0';
//    printf("%s",returnStr);
    return rawStr;
}

// fixme
char *fixBlanks(char *orgStr) {
    size_t size = strLen(orgStr);
    // fixme problems in dynamic memory allocation
    char *fixedStr = (char *) malloc(size * sizeof(char));
    for (int i = 0, j = 0, c = orgStr[i]; i < size; i++, j++, c = orgStr[i]) {
        if (c != ' ') {
            fixedStr[j] = (char) c;
        } else {
            fixedStr[j] = (char) c;
            while (orgStr[i++] == ' ');
        }

    }
    printf("%s\n", fixedStr);
    return fixedStr;
}



//typedef struct dynamicString{
//    char *data;
//    struct dynamicString *pointing;
//
//    struct dynamicString * createDynStr(char c, struct dynamicString *pointer){
//        *data = c;
//        pointing = pointer;
//    }
//
//} DynStr;