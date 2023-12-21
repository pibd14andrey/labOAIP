//#define _CRT_SECURE_NO_WARNINGS
//#include "Dict.h"
//#include <string.h>
//#include <stdio.h>
//
//
//#define MAX_WORDS 10000
//
//// —лова 
//char words[MAX_WORDS][MAX_LEN_WORD + 1];
////  оличество слов в словаре
//int numWords = 0;
//
///*
//CREATE - создает словарь.
//¬ызываетс€ перед началом использовани€ словар€.
//*/
//void Create() {
//	numWords = 0;
//}
//
//
///*
//DESTROY - уничтожает словарь.
//¬ызываетс€ после окончани€ использовани€ словар€.
//*/
//void Destroy() {
//	numWords = 0;
//}
//
//
//
///*
//INSERT Ц добавл€ет элемент в множество.
//ћножество Ц содержит только уникальные элементы.
//ѕри повторном добавлении элемента в множество, множество не измен€етс€.
//*/
//void Insert(char* word) {
//
//	if (numWords >= MAX_WORDS) {
//		return; // словарь переполнен!
//	}
//
//	// Ќачина€ с конца массива ищетс€ место куда нужно вставить слово
//	// ¬ставка делаетс€ в отсортированный массив
//	// ¬ставка делаетс€ так, чтобы после вставки массив был отсортирован
//	int i = numWords;
//	while ((i > 0) && (strcmp(word, words[i - 1]) < 0)) {
//		strcpy(words[i], words[i - 1]);
//		i--;
//	}
//	strcpy(words[i], word);
//	++numWords;
//}
//
//
//
///*
//MEMBER Ц сообщает, €вл€етс€ ли указанный элемент членом данного множества или нет.
//≈сли €вл€етс€ - возврашает 1, иначе - возвращает 0
//*/
//int  Member(char* word) {
//	// »спользуетс€ алгоритм бинарного поиска слова в отсортированном массиве
//	int left = 0;
//	int right = numWords - 1;
//
//	while (left <= right) {
//		int middle = (left + right) / 2;
//
//		int dif = strcmp(words[middle], word);
//		if (dif == 0) {
//			return 1;
//		}
//		if (dif < 0) {
//			left = middle + 1;
//		}
//		if (dif > 0) {
//			right = middle - 1;
//		}
//	}
//	return 0;
//}
