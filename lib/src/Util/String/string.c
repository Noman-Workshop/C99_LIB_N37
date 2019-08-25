/**
# Created By: Noman^Alien#0637 
# Created On: 4/9/2019; 9:44 AM
*/

#include <Util/String/string.h>

char *str_toggleCase(const char *str) {
	size_t i;
	size_t strLength = strlen(str);
	char *toggleStr = (char *) calloc(strLength, sizeof(char));
	for (i = 0; i < strLength; i++) {
		if (isalpha(str[i])) {
			if (str[i] >= 'a')
				toggleStr[i] = (char) (str[i] - 'a' + 'A');
			else
				toggleStr[i] = (char) (str[i] - 'A' + 'a');
		} else {
			toggleStr[i] = str[i];
		}
	}
	toggleStr[i] = '\0';
	
	return toggleStr;
}

char *str_trim(const char *str, const char *delimiter) {
	size_t len = strlen(str);
	int delimiterLen = (int) strlen(delimiter);
	
	// Searching at the beginning of the word
	size_t start = 0;
	size_t si;
	int j;
	for (si = 0; si < len; si++) {
		for (j = 0; j < delimiterLen; j++, si++) {
			if (str[si] != delimiter[j]) {
				goto endOfWord;
			}
		}
		
		start += delimiterLen;
		si--;
	}
	
	endOfWord:;
	
	// Searching at the end of the word
	size_t ei;
	for (ei = len - 1; ei > si; ei--) {
		for (j = delimiterLen - 1; j >= 0; j--, ei--) {
			if (str[ei] != delimiter[j]) {
				goto endSearch;
			}
		}
		
		len -= delimiterLen;
		ei++;
	}
	
	endSearch:;
	
	char *trimmedStr = calloc(len - start + 1, sizeof(char));
	snprintf(trimmedStr, len - start + 1, "%s", str + start);
//	strncpy(trimmedStr, str + start,len - start);
//	trimmedStr[len - start + 1] = '\0';
	return trimmedStr;
}

char **str_split(const char *str, const char *delimiter, ...) {
	str = str_trim(str, delimiter);
	
	size_t len = strlen(str);
	size_t delimiterLen = strlen(delimiter);
	bool match = true;
	
	// Determining Number of Split String
	size_t splitCount = 1;
	size_t i, j;
	size_t splitStrLen;
	
	for (i = 0, splitStrLen = 0; i < len; i++, splitStrLen++, match = true) {
		for (j = 0; j < delimiterLen; j++, i++, splitStrLen++) {
			if (str[i] != delimiter[j]) {
				match = false;
				break;
			}
		}
		
		if (j == delimiterLen && match) {
			// not counting the string with no length
			if (splitStrLen - delimiterLen != 0) splitCount++;
			i--;
			splitStrLen = -1;
		}
	}
	
	// todo: implementing max split count
	/*
	va_list args;
	va_start(args, delimiter);
	size_t maxSplitCount = strtoul(va_arg(args, char *), NULL, 10);
	if (maxSplitCount != 0 && maxSplitCount < splitCount) splitCount = maxSplitCount;
//	*/
	char **splitStrArr = calloc(splitCount + 1, sizeof(char *));
	splitStrArr[0] = intToStr(splitCount);
	
	delimiterLen = strlen(delimiter);
	size_t count;
	for (i = 0, splitStrLen = 0, count = 1; count <= splitCount; i++, splitStrLen++, match = true) {
		for (j = 0; j < delimiterLen; j++, i++, splitStrLen++) {
			if (str[i] != delimiter[j]) {
				match = false;
				break;
			}
		}
		
		if ((j == delimiterLen && match) || (i == len)) {
			if (i == len) {
				delimiterLen = 0;
			}
			
			if (splitStrLen - delimiterLen != 0) {
				splitStrArr[count] = calloc(splitStrLen - delimiterLen + 1, sizeof(char));
				snprintf(splitStrArr[count], splitStrLen - delimiterLen + 1, "%s", str + i - splitStrLen);
//				strncpy(splitStrArr[count], str + i - splitStrLen, splitStrLen - delimiterLen);
//				splitStrArr[count][splitStrLen] = '\0';
				count++;
			}
			splitStrLen = -1;
			i--;
		}
	}
	
	return splitStrArr;
	
}
