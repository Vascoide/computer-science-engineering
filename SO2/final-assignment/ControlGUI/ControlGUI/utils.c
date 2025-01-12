#include "utils.h"

// Limpa uma string
TCHAR* resetString(TCHAR* str, unsigned int size) {
	unsigned int i;

	for (i = 0; i < size; i++) {
		str[i] = '\0';
	}

	return str;
}

// Conta e divide uma string
TCHAR** splitString(TCHAR* str, const TCHAR* delim, unsigned int* size) {
	TCHAR* nextToken = NULL, ** temp, ** returnArray = NULL;
	TCHAR* token = _tcstok_s(str, delim, &nextToken);

	if (str == NULL || _tcslen(str) == 0) {
		_ftprintf(stderr, TEXT("[ERRO] String vazia!"));
		return NULL;
	}

	*size = 0;

	while (token != NULL) {
		temp = realloc(returnArray, sizeof(TCHAR*) * (*size + 1));

		if (temp == NULL) {
			_ftprintf(stderr, TEXT("[ERRO] Imposs�vel alocar mem�ria para string!"));
			return NULL;
		}

		returnArray = temp;
		returnArray[(*size)++] = token;

		token = _tcstok_s(NULL, delim, &nextToken);
	}

	return returnArray;
}

// Verifica se a string � um n�mero inteiro
BOOL isStringANumber(TCHAR* str) {
	for (size_t i = 0; i < _tcslen(str); i++) {
		if (!_istdigit(str[i])) return FALSE;
	}

	return TRUE;
}

TCHAR* toUpperString(TCHAR* str) {
	for (unsigned int i = 0; i < _tcslen(str); i++) {
		str[i] = _totupper(str[i]);
	}

	return str;
}

BOOL stringHasSpaces(TCHAR* str) {
	for (size_t i = 0; i < _tcslen(str); i++) {
		if (str[i] == ' ') return TRUE;
	}

	return FALSE;
}