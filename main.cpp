#include <iostream>
#include <locale.h>
#include <windows.h>
#include <cstdlib>
#include <ctime>

template <typename T>
void three_max(T& a, T& b, T& c);

template <typename T>
T& findNeg(T* arr, const int length);

void fillArr(int* arr, const int length, int low, int hi);

template <typename T>
void showArr(T* arr, const int length);

template <typename T>
void resetFun(T* arr1, const int length1, T* arr2, const int length2);

int main() {
	setlocale(LC_ALL, "Russian");
	SetConsoleCP(1251); // установка кодовой страницы на ввод текста
	srand(time(NULL));

	std::cout << "Exercise 1.\n";
	/*
		Create a function that accepts three
	variables (not their addresses, namely variables).
	The function finds the maximum of them, and then
	changes the values of the remaining variables to the
	maximum value.
	Code example with function call:
	int A = 3, B = 5, C = 4;
	three_max(A, B, C);
	std::cout << A << ' ' << B << ' ' << C;
	// on screen 5 5 5
	
		Создайте функцию, которая принимает три 
	переменные (не их адреса, а именно переменные). 
	Функция находит максимальную из них, после чего 
	меняет значения остальных переменных на значение 
	максимальной.
	Пример кода с вызовом функции:
	int A = 3, B = 5, C = 4;
	three_max(A, B, C);
	std::cout << A << ' ' << B << ' ' << C;
	// на экране 5 5 5

	*/
	int A = 3, B = 5, C = 4;
	//std::cout << "Enter three numbers -> ";
	//std::cin >> A >> B >> C;
	three_max(A, B, C);
	std::cout << A << ' ' << B << ' ' << C << "\n\n\n";

	std::cout << "Exercise 2.\nProgram for finding negative element.\n";
	/*
		Create a function that takes an array and its
	length. The function returns a reference to the first
	negative element of the array. If
	there are no negative elements in the array, the function returns 
	a link to its first element.
	
		Создайте функцию, которая принимает массив и его 
	длину. Функция возвращает ссылку на первый 
	отрицательный элемент массива. Если отрицательных 
	элементов нет в массиве, то функция возвращает 
	ссылку на его первый элемент.
	*/
	const int length = 10;
	int arr[length];
	fillArr(arr, length, -1, 10);
	showArr(arr, length);
	//std::cout << findNeg(arr, length) << "\n\n\n";
	if (findNeg(arr, length) < 0)
		std::cout << "First negative element found -> " << findNeg(arr, length) << "\n\n\n";
	else
		std::cout << "Negative element not found in the array.\n\n\n";

	{
		std::cout << "Exercise 3.\n";
		/*
			Write a function that takes two arrays
		and their lengths. The function should reset all elements
		of the second array that occur in the first one. The
		syntax must be used in the function body
			pointers to iterate through the elements of both arrays.
			Example:
			Array 1:
		{ 3, 6, 4, 1, 4, 8, 2 }
		Array 2:
		{ 5, 3, 1, 5, 10, 8 }
		Array 2 after calling the function:
		{ 5, 0, 0, 5, 10, 0 }

			Напишите функцию, которая принимает два массива
		и их длины. Функция должна обнулить все элементы
		второго массива, которые встречаются в первом. В теле
		функции необходимо использовать синтаксис
		указателей для перебора элементов обоих массивов.
		Пример:
		Массив1:
		{ 3, 6, 4, 1, 4, 8, 2 }
		Массив2:
		{ 5, 3, 1, 5, 10, 8 }
		Массив 2 после вызова функции:
		{ 5, 0, 0, 5, 10, 0 }
		*/
		const int length1 = 10;
		int arr1[length];
		fillArr(arr1, length1, 1, 20);
		const int length2 = 8;
		int arr2[length2];
		fillArr(arr2, length2, 1, 10);
		std::cout << "Array 1:\n";
		showArr(arr1, length1);
		std::cout << "Array 2:\n";
		showArr(arr2, length2);
		resetFun(arr1, length1, arr2, length2);
		std::cout << "Array 2 after callint the function:\n";
		showArr(arr2, length2);
		std::cout << "\n\n\n";
	}
	return 0;
}

template <typename T>
void three_max(T& a, T& b, T& c) {
	if (a >= b) {
		if (a >= c) {
			b = a; c = a;
		}
		else if (c >= b) {
			b = c; a = c;
		}
	}
	else if (b >= a) {
		if (b >= c) {
			a = b; c = b;
		}
		else if (c >= b) {
			b = c; a = c;
		}
	}
}

template <typename T>
T& findNeg(T* arr, const int length) {
	for (size_t i = 0; i < length; i++){
		if (*(arr + i) < 0)
			return *(arr + i);
	}
	return *arr;
}

void fillArr(int* arr, const int length, int low, int hi) {
	for (size_t i = 0; i < length; i++){
		*(arr + i) = rand() % (hi - low) + low;
	}
}

template <typename T>
void showArr(T* arr, const int length) {
	std::cout << "[ ";
	bool first = true;
	for (size_t i = 0; i < length; i++){
		if (!first)
			std::cout << ", ";
		first = false;
		std::cout << *(arr + i) << ' ';
	}
	std::cout << " ]\n";
}

template <typename T>
void resetFun(T* arr1, const int length1, T* arr2, const int length2) {
	for (size_t i = 0; i < length2; i++){
		for (size_t j = 0; j < length1; j++) {
			if (*(arr1 + j) == *(arr2 + i))
				*(arr2 + i) = 0;
		}
	}
}


