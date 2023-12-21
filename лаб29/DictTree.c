////
//// Реализация словаря на двоичном дереве поиска
//// 
//
//#define _CRT_SECURE_NO_WARNINGS
//#include <string.h>
//#include <stdlib.h>
//#include "Dict.h"
//
//
//// Узел дерева 
//struct NodeTree {
//	char* word;
//	struct NodeTree* left;
//	struct NodeTree* right;
//};
//
//// Корень дерева
//struct NodeTree* root = NULL;
//
//
//struct NodeTree* addElement(struct NodeTree* p, char* word)
//{
//	int cond;
//
//	if (p == NULL) {
//		p = (struct NodeTree*)malloc(sizeof(struct NodeTree));
//		p->word = (char*)calloc(strlen(word) + 1, sizeof(char));
//		strcpy(p->word, word);
//		p->left = p->right = NULL;
//	}
//	else if ((cond = strcmp(word, p->word)) == 0) {
//		// вставляемое слово совпадает
//		// с уже имеющимся  - ничего не делаем
//	}
//	else if (cond < 0) {
//		// вставляемое слово меньше 
//		// корня поддерева
//		p->left = addElement(p->left, word);
//	}
//	else {
//		// вставляемое слово больше 
//		// корня поддерева
//		p->right = addElement(p->right, word);
//	}
//	return p;
//}
//
//
//
//void clearTree(struct NodeTree* p)
//{
//	if (p != NULL) {
//		clearTree(p->left);
//		clearTree(p->right);
//		free(p->word);
//		free(p);
//	}
//}
//
//int containElement(struct NodeTree* p, char* word)
//{
//	int cond;
//	if (p == NULL) {
//		return 0;
//	}
//	else if ((cond = strcmp(word, p->word)) == 0) {
//		return 1;
//	}
//	else if (cond < 0) {
//		return containElement(p->left, word);
//	}
//	else {
//		return containElement(p->right, word);
//	}
//}
//
//
///* INSERT – добавляет элемент в множество.
//Множество – содержит только уникальные элементы.
//При повторном добавлении элемента в множество, множество не изменяется.*/
//void Insert(char* word) {
//	root = addElement(root, word);
//}
//
//
///* MEMBER – сообщает, является ли указанный элемент членом данного множества или нет.*/
//int  Member(char* word) {
//	return containElement(root, word);
//}
//
//
///* CREATE - создает словарь.
//Вызывается перед началом использования словаря. */
//void Create() {
//	root = NULL;
//}
//
//
///* DESTROY - уничтожает словарь.
//Вызывается после окончания использования словаря. */
//void Destroy() {
//	clearTree(root);
//	root = NULL;
//}
//
//
