//#define _CRT_SECURE_NO_WARNINGS
//#include <string.h>
//#include "Dict.h"
//
//#define MAX_WORDS 10000
//
//// Слова 
//char words[MAX_WORDS][MAX_LEN_WORD + 1];
//// Количество слов в словаре
//int numWords = 0;
//
//
///* CREATE - создает словарь.
//Вызывается перед началом использования словаря. */
//void Create() {
//	numWords = 0;
//}
//
//
///* DESTROY - уничтожает словарь.
//Вызывается после окончания использования словаря. */
//void Destroy() {
//	numWords = 0;
//}
//
///* INSERT – добавляет элемент в множество.
//Множество – содержит только уникальные элементы.
//При повторном добавлении элемента в множество, множество не изменяется. */
//void Insert(char* word) {
//	if (!Member(word)) {
//		if (numWords < MAX_WORDS) {
//			strcpy(words[numWords], word);
//			numWords++;
//		}
//	}
//}
//
//
///* MEMBER – сообщает, является ли указанный элемент членом данного множества или нет.
//Если является - возврашает 1, иначе - возвращает 0 */
//int  Member(char* word) {
//	for (int i = 0; i < numWords; i++) {
//		if (strcmp(words[i], word) == 0) {
//			return 1;
//		}
//	}
//	return 0;
//}
//
