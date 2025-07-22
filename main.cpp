#pragma once
#include "Window/window.h"
#include "iostream"
#include "vector"

void atividade1();
void atividade1()
{
	int age = 42;
	int* ptrAge = &age;

	std::cout << "O valor da variável age: " << age << "\n";
	std::cout << "O endereço de memória da variável: " << &age << "\n";
	std::cout << "valor armazenado no ponteiro: " << ptrAge << "\n";
	std::cout << "valor para o qual o ponteiro aponta: " << *ptrAge << "\n";
	std::cout << "valor da variável inteira usando o ponteiro" << "\n";
	
	*ptrAge = 99;
	
	std::cout << "novo valor da variável: " << age << "\n";

}

void dobrarValor(int* valuePtr) 
{
	*valuePtr *= 2;
}

void atividade3()
{
	int meuArray[5] = { 10, 20, 30, 40, 50 };
	int* ptr = &meuArray[0];
	std::cout << "variavel meu valor: " << *ptr << "\n";

	ptr = &meuArray[2];
	*ptr += 5;

	std::cout << "element array: " << *ptr << "\n";
}

void atividade4()
{
	int* ptrVazio = nullptr;

	if (ptrVazio == nullptr) {
		std::cout << "erro. your poniter is ptr" << "\n";
		int n = 100;
		ptrVazio = &n;
	}

	std::cout << "ptr: " << *ptrVazio << "\n";
}

//          x            x
int main(int argc, char* argv[])
{
	atividade1();
	WindowApplication::initWindow();


#if 0
	int meuValor = 5;
	std::cout << "variavel meu valor: " << meuValor << "\n";
	dobrarValor(&meuValor);
	std::cout << "variavel meu valor: " << meuValor << "\n";
#endif

	return 0;
}