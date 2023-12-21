#define _CRT_SECURE_NO_WARNINGS
#include <string.h>
#include <time.h>
#include <stdio.h>
#include <Windows.h>


// Максимальная длина слова в словаре
#define MAX_LEN_WORD 80

int getNextDelim(FILE* fp, char token[]);
int getNextWord(FILE* fp, char token[]);



char filenameDict[] = "c:\\Temp\\Lection15_2023\\dict1.txt";
char filenameIn[] = "c:\\Temp\\Lection15_2023\\Alice.txt";
char filenameOut[] = "c:\\Temp\\Lection15_2023\\Alice_out.html";

//char filenameIn[] = "c:\\Temp\\Lection15_2023\\Tolkien2.txt";
//char filenameOut[] = "c:\\Temp\\Lection15_2023\\Tolkien2_out.html";

void main() {
	// сообщаем какие файлы обрабатываются
	printf("HTML file %s\nis created from text file %s\nwith highlighting words from %s\ndictionary\n\n\n",
		filenameOut, filenameIn, filenameDict);

	// t0 - сколько прошло времени от старта программы до момента входа в функцию main()
	long t0 = clock();
	printf("t0 = %.3f sec \n", t0 / (float)CLOCKS_PER_SEC);
	// t1 - сколько прошло времени от старта программы до окончания загрузки словаря
	int t1 = clock();
	printf("t1 = %.3f sec \n", t1 / (float)CLOCKS_PER_SEC);

	TextProcessing(filenameIn, filenameOut);

	// t2 - сколько прошло времени от старта программы до окончания конвертации текста
	long t2 = clock();
	printf("t2 = %.3f sec \n", t2 / (float)CLOCKS_PER_SEC);


	// t3 - сколько прошло времени от окончания конвертации текста до окончания уничтожения словаря 
	long t3 = clock();

	printf("t3 = %.3f sec \n", t3 / (float)CLOCKS_PER_SEC);

	printf("t1 - t0 = %.3f sec (Run time of dictionary loading)\n", (t1 - t0) / (float)CLOCKS_PER_SEC);
	printf("t2 - t1 = %.3f sec (Run time of HTML generating)\n", (t2 - t1) / (float)CLOCKS_PER_SEC);
	printf("t3 - t2 = %.3f sec (Run time of dictionary destroying )\n", (t2 - t1) / (float)CLOCKS_PER_SEC);
}

// Проверка, есть ли слово word в словаре, хранящемся в файле filenameDict
int Member(char* word) {
	// открыть файл
	FILE* fin = fopen(filenameDict, "rt");
	if (fin == NULL) {
		// если файл не смогли открыть - сообщаем об этом
		printf("File %s doesn't opened!\n", filenameDict);
		return 0;
	}

	char token[MAX_LEN_WORD + 1];


	// пока не конец файла
	while (!feof(fin)) {
		// пока есть разделитель - берем его
		while (getNextDelim(fin, token)) {
		}
		// если есть слово - берем его
		if (getNextWord(fin, token)) {
			if (strcmp(token, word) == 0) {
				// Слово в файле есть!
				fclose(fin);
				return 1;
			}
		}
	}
	// Закрываем файл с текстом
	fclose(fin);
	return 0;
}


int TextProcessing(char* filenameIn, char* filenameOut) {
	// открыть файл
	FILE* fin = fopen(filenameIn, "rt");
	if (fin == NULL) {
		// если файл не смогли открыть - сообщаем об этом
		printf("File %s doesn't opened!\n", filenameIn);
		return 0;
	}

	// открыть файл
	FILE* fout = fopen(filenameOut, "wt");
	if (fout == NULL) {
		// если файл не смогли открыть - сообщаем об этом
		printf("File %s doesn't opened!\n", filenameOut);

		fclose(fin);
		return 0;
	}

	// Выводим в выходной файл заголовок HTML документа
	fprintf(fout, "<!DOCTYPE html>");
	fprintf(fout, "<html>");
	fprintf(fout, "<head>");
	fprintf(fout, "<meta http - equiv = \"Content-Type\" content = \"text/html; charset=utf-8\" />");
	fprintf(fout, "<title>HTML Document</title>");
	fprintf(fout, "</head>");
	fprintf(fout, "<body>");



	char token[MAX_LEN_WORD + 1];

	// пока не конец файла
	while (!feof(fin)) {
		// пока есть разделитель - берем его
		while (getNextDelim(fin, token)) {
			// выводим разделитель 
			fprintf(fout, "%s", token);
			if (strcmp(token, "\n") == 0) {
				fprintf(fout, "<br>");
			}
		}
		// если есть слово - берем его
		if (getNextWord(fin, token)) {
			// Если слово есть в Словаре – то выделяем его
			if (Member(token)) {
				fprintf(fout, "<b>%s</b>", token);
			}
			else {
				fprintf(fout, "%s", token);
			}
		}
	}

	// выводит в HTML завершающие теги документа HTML
	fprintf(fout, "</body>");
	fprintf(fout, "</html>");
	// закрываем входной и выходной файла
	fclose(fin);
	fclose(fout);

	return 1;
}





// Возвращает 0 - если ch - не буква.
// Возвращает 1 - если ch - буква.
// Корректно работает для латинских букв (с кодами < 128)
// И для русских букв из кодировки ANSI
int isalpha_my(unsigned char ch) {

	if (isalpha(ch))
		return 1;

	// ANSI кодировка!!!
	if (ch >= 192 && ch <= 223)
		return 1;
	if (ch >= 224 && ch <= 255)
		return 1;

	return 0;
}




int isalpha_my(unsigned char ch);

// Возвращает 1 - если  из файла прочитан разделитель.
// В этом случае в token возвращается строка, содержащая 
// этот разделитель.
// Если в файле был не разделитель - возвращает 0.
// В этом случае состояние token неопределено.
int getNextDelim(FILE* fp, char token[])
{
	int ch = getc(fp);
	if (ch == EOF) {
		return 0;
	}
	if (isalpha_my((unsigned char)ch)) {
		ungetc(ch, fp);
		return 0;
	}
	token[0] = (unsigned char)ch;
	token[1] = '\0';
	return 1;
}


// Возвращает 1 - если  из файла прочитано слово.
// В этом случае в token возвращается строка, содержащая 
// это слово. Гарантируется что слово не более MAX_LEN_WORD символов.
// Если в файле не было буквы - возвращает 0.
// В этом случае token содержит пустую строку.
int getNextWord(FILE* fp, char token[])
{
	int i = 0;
	int ch;
	while (((ch = getc(fp)) != EOF) && (i < MAX_LEN_WORD)) {
		if (!isalpha_my((unsigned char)(ch))) {
			break;
		}
		token[i++] = ch;
	}
	ungetc(ch, fp);
	token[i] = '\0';
	if (i == 0)
		return 0;
	return 1;
}
