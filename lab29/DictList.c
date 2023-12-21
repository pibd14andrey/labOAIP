////
//// Реализация словаря на односвязанном списке
//// 
//
//#define _CRT_SECURE_NO_WARNINGS
//#include <string.h>
//#include <stdlib.h>
//
//#include "Dict.h"
//
//// =========================================================================================
//// Реализация словаря!!!
//
//
//// элемент односвязанного списка
//struct Node {
//	char* word;
//	struct Node* next;
//};
//
//
//// Первый элемент списка
//struct Node* first = NULL;
//
//
///*
//INSERT – добавляет элемент в множество.
//Множество – содержит только уникальные элементы.
//При повторном добавлении элемента в множество, множество не изменяется.
//*/
//void Insert(char* word) {
//	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
//
//	newNode->next = first;
//	newNode->word = (char*)calloc(strlen(word) + 1,	sizeof(char));
//	strcpy(newNode->word, word);
//
//	first = newNode;
//}
//
//
///*
//MEMBER – сообщает, является ли указанный элемент членом данного множества или нет.
//*/
//int  Member(char* word) {
//	struct Node* ptr = first;
//	while (ptr != NULL) {
//		if (strcmp(ptr->word, word) == 0) {
//			return 1;
//		}
//		ptr = ptr->next;
//	}
//	return 0;
//}
//
//
///* CREATE - создает словарь.
//Вызывается перед началом использования словаря. */
//void Create() {
//	first = NULL;
//}
//
//
///* DESTROY - уничтожает словарь.
//Вызывается после окончания использования словаря. */
//void Destroy() {
//	while (first != NULL) {
//		struct Node* delNode = first;
//		first = first->next;
//
//		free(delNode->word);
//		free(delNode);
//	}
//}