#include <iostream>
#include <conio.h>
#include <stdio.h>
#include <ctime>
using namespace std;


#include "Goods.h"


// forward declarations
void add_record(char *bin);
void view_file(char *bin);
void r_num(char *bin, int &rec_num);
void create_array(char *bin, Goods *arr);
void sort_array(Goods *arr, int rec_num);
void show_array(Goods *arr, int rec_num);
void array_to_file(char *bin, Goods *arr, int rec_num);
void select(char *bin);
int define_year();
void create_txt_file(char *bin, char *txt, int system_year);
void view_txt_file(char *txt);
void delete_records(char *bin, Goods *arr, int rec_num, int system_year);
void decrease_price(char *bin, int rec_num, Goods *arr);
void insert_record(char *bin, int rec_num, Goods *arr);

int main() {
	FILE *b = NULL, *t = NULL;
	char bin[] = "b-list.txt";
	char txt[] = "t-list.txt";
	int rec_num = 0;

	printf("_NAME___|_______CODE____|_______FIRM____|_______YEAR____|______PRICE____|____GUARANTEE__|\n");
	add_record(bin);
	printf("=========================================================================================\n");

	printf("\n\t\t\t\t   List of goods:\n_NAME___|_______CODE____|_______FIRM____|_______YEAR____|______PRICE____|____GUARANTEE__|\n");
	view_file(bin);
	printf("=========================================================================================\n\n");

	r_num(bin, rec_num);
	printf("\t\t\t      [ Number of records: %i ]\n", rec_num);
	printf("=========================================================================================\n\n");

	Goods *arr = new Goods[rec_num];
	create_array(bin, arr);

	sort_array(arr, rec_num);
	printf("\t\t\t   Sorted by decreasing price:\n_NAME___|_______CODE____|_______FIRM____|_______YEAR____|______PRICE____|____GUARANTEE__|\n");
	show_array(arr, rec_num);
	printf("=========================================================================================\n\n");

	array_to_file(bin, arr, rec_num);

	printf("\t\t\t   'Samsung' TV with guarantee:\n_NAME___|_______CODE____|_______FIRM____|_______YEAR____|______PRICE____|____GUARANTEE__|\n");
	select(bin);
	printf("=========================================================================================\n\n");

	int system_year = define_year();
	create_txt_file(bin, txt, system_year);

	printf("\tGoods produced more than 2 years ago with price more than 2000 grn.\n_NAME___|_______CODE____|_______FIRM____|_______YEAR____|______PRICE____|____GUARANTEE__|\n");
	view_txt_file(txt);
	printf("=========================================================================================\n\n");

	delete_records(bin, arr, rec_num, system_year);
	printf("\t\t     List after deleting goods produced 5 years ago\n_NAME___|_______CODE____|_______FIRM____|_______YEAR____|______PRICE____|____GUARANTEE__|\n");
	view_file(bin);
	printf("=========================================================================================\n\n");

	r_num(bin, rec_num);
	decrease_price(bin, rec_num, arr);
	printf("\t    After decreasing a price for goods produced by \"LG\" by 10%\n_NAME___|_______CODE____|_______FIRM____|_______YEAR____|______PRICE____|____GUARANTEE__|\n");
	view_file(bin);
	printf("=========================================================================================\n\n");

	insert_record(bin, rec_num, arr);
	printf("=========================================================================================\n\n");
	view_file(bin);


	delete[] arr;

	system("pause");
	return 0;
}

// add a record, parameter - pointer to binary file's name
void add_record(char *bin) {
	FILE *b;
	if ((b = fopen(bin, "ab")) == NULL) { cout << "Error! Cannot open a file!\n"; return; }

	// input data and write it to structure el
	Goods el;
	scanf("%s\t %i\t %s\t %i\t %f\t %s", el.name, &el.code, el.firm, &el.year, &el.price, el.grnt);
	// write data to binary file
	fwrite(&el, sizeof(Goods), 1, b);

	fclose(b);
}

// view records 
void view_file(char *bin) {
	FILE *b;
	if ((b = fopen(bin, "rb")) == NULL) { cout << "Error! Cannot open a file!\n"; return; }

	Goods el;
	while (fread(&el, sizeof(Goods), 1, b)) {
		printf("%s\t|\t%i\t|\t%s\t|\t%i\t|\t%6.2f\t|\t%s\t|\n", el.name, el.code, el.firm, el.year, el.price, el.grnt);
	}

	fclose(b);
}

void r_num(char *bin, int &rec_num) {
	FILE *b;
	if ((b = fopen(bin, "rb")) == NULL) { cout << "Error! Cannot open a file!\n"; return; }

	fseek(b, 0, 2);
	rec_num = ftell(b) / sizeof(Goods);

	fclose(b);
}

void create_array(char *bin, Goods *arr) {
	FILE *b;
	if ((b = fopen(bin, "rb")) == NULL) { cout << "Error! Cannot open a file!\n"; return; }

	int i = 0;
	while (fread(&arr[i], sizeof(Goods), 1, b)) i++;
	fclose(b);
}

void sort_array(Goods *arr, int rec_num) {
	Goods temp;
	bool f;

	do {
		f = 0;
		for (int i = 0; i < (rec_num - 1); i++)
			if (arr[i].price < arr[i + 1].price) {
				temp = arr[i];
				arr[i] = arr[i + 1];
				arr[i + 1] = temp;
				f = 1;
			}
	} while (f);
}

void show_array(Goods *arr, int rec_num) {
	for (int i = 0; i < rec_num; i++)
		printf("%s\t|\t%i\t|\t%s\t|\t%i\t|\t%6.2f\t|\t%s\t|\n", arr[i].name, arr[i].code, arr[i].firm, arr[i].year, arr[i].price, arr[i].grnt);
}

void array_to_file(char *bin, Goods *arr, int rec_num) {
	FILE *b;

	if ((b = fopen(bin, "wb")) == NULL) { cout << "Error! Cannot open a file!\n"; return; }

	for (int i = 0; i < rec_num; i++)
		fwrite(&arr[i], sizeof(Goods), 1, b);
	fclose(b);
}

void select(char *bin) {
	FILE *b;
	if ((b = fopen(bin, "rb")) == NULL) { cout << "Error! Cannot open a file!\n"; return; }

	Goods el;
	while (fread(&el, sizeof(Goods), 1, b))
		if (strcmp(el.name, "TV") == 0 && strcmp(el.firm, "Samsung") == 0 && strcmp(el.grnt, "yes") == 0)
			printf("%s\t|\t%i\t|\t%s\t|\t%i\t|\t%6.2f\t|\t%s\t|\n", el.name, el.code, el.firm, el.year, el.price, el.grnt);
	fclose(b);
}

int define_year() {
	char sys_year[5];
	time_t system_time;
	struct tm *time_info;	// structure for system time

	time(&system_time);		// write system time to the time_t type
	time_info = localtime(&system_time);	// write system time to the structure
	strftime(sys_year, 5, "%Y", time_info);	// write system year from structure
	int this_year = atoi(sys_year);		// convert string to integer

	return this_year;	// return system year
}

void create_txt_file(char *bin, char *txt, int system_year) {
	FILE *b, *t;
	if ((b = fopen(bin, "rb")) == NULL || (t = fopen(txt, "wt")) == NULL) { cout << "Error! Cannot open a file!\n"; return; }

	Goods el;
	while (fread(&el, sizeof(Goods), 1, b))
		if (system_year - el.year > 2 && el.price > 2000)
			fprintf(t, "%s\t %i\t %s\t %i\t %f\t %s\n", el.name, el.code, el.firm, el.year, el.price, el.grnt);
	fclose(b);
	fclose(t);
}

void view_txt_file(char *txt) {
	FILE *t;

	if ((t = fopen(txt, "rt")) == NULL) { cout << "Error! Cannot open a file\n"; return; }

	Goods el;
	while (!feof(t)) {
		fscanf(t, "%s\t %i\t %s\t %i\t %f\t %s\n", el.name, &el.code, el.firm, &el.year, &el.price, el.grnt);
		printf("%s\t|\t%i\t|\t%s\t|\t%i\t|\t%6.2f\t|\t%s\t|\n", el.name, el.code, el.firm, el.year, el.price, el.grnt);
	}
	fclose(t);
}

void delete_records(char *bin, Goods *arr, int rec_num, int system_year) {
	FILE *b;
	if ((b = fopen(bin, "rb")) == NULL) { cout << "Error! Cannot open a file!\n"; return; }

	int i = 0;
	while (fread(&arr[i], sizeof(Goods), 1, b)) i++;

	fclose(b);

	b = fopen(bin, "wb");
	for (int i = 0; i < rec_num; i++)
		if (system_year - arr[i].year != 5)
			fwrite(&arr[i], sizeof(Goods), 1, b);

	fclose(b);
}

void decrease_price(char *bin, int rec_num, Goods *arr) {
	FILE *b;
	if ((b = fopen(bin, "rb")) == NULL) { cout << "Error! Cannot open a file!\n"; return; }

	int i = 0;
	while (fread(&arr[i], sizeof(Goods), 1, b)) i++;

	fclose(b);

	b = fopen(bin, "wb");
	for (int i = 0; i < rec_num; i++) {
		if (strcmp(arr[i].firm, "LG") == 0)
			arr[i].price -= arr[i].price / 10;
		fwrite(&arr[i], sizeof(Goods), 1, b);
	}
	fclose(b);
}

void insert_record(char *bin, int rec_num, Goods *arr) {
	FILE *b;
	if ((b = fopen(bin, "rb")) == NULL) { cout << "Error! Cannot open a file!\n"; return; }

	int i = 0;
	while (fread(&arr[i], sizeof(Goods), 1, b)) i++;

	fclose(b);

	int str_num = 0;
	printf("Input a number (from 1 to %i) of string for inserting: ", rec_num);
	scanf("%i", &str_num);

	b = fopen(bin, "wb");

	for (i = 0; i < str_num - 1; i++)
		fwrite(&arr[i], sizeof(Goods), 1, b);

	Goods el;
	printf("_NAME___|_______CODE____|_______FIRM____|_______YEAR____|______PRICE____|____GUARANTEE__|\n");
	scanf("%s\t %i\t %s\t %i\t %f\t %s", el.name, &el.code, el.firm, &el.year, &el.price, el.grnt);
	fwrite(&el, sizeof(Goods), 1, b);

	for (i = str_num - 1; i < rec_num; i++)
		fwrite(&arr[i], sizeof(Goods), 1, b);

	fclose(b);
}