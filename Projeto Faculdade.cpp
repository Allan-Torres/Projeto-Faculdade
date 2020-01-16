// BIBLIOTECAS
#include <iostream>
#include <ctype.h>
#include <fstream>
#include <string>
#include <locale>
#include <conio.h>
#include <windows.h>

using namespace std;

// VARIAVEIS GLOBAL
int tipo_bebida, numero_casa;
string resp_ingredientes, sabor_pizza, sabor_bebida, atendimento, realizar_pedido, ingredientes, bebida;
string nome, cpf, telefone, endereco; // VARIAVEL PARA DADOS DO CLIENTE
char p, b;
int tempo;

//pizza
string repeti_qtde;
int qtde_pizza;
char qtde_pizzas[10], a;
int l;

//bebida1
string repeti_qtde1;
int qtde_bebida;
char qtde_bebidas[10], m;
int g;

void pedido();
void menu();
float dinheiro;
float total;

fstream arquivo;

int main()
{
	string login = " ";
	string senha = " ";

	arquivo.open("pizzariadochefe.txt", ios::out);

	cout << "\n Para entrar no programa, digite o login e a senha corretamente.\n\n";

	while (login != "admin" || senha != "chefe")
	{
		cout << "\n\t\tLogin: ";
		cin >> login;
		cout << "\n\t\tSenha: ";
		cin >> senha;

		cout << " Carregando .";
		Sleep(1000);
		cout << ".";
		Sleep(1000);
		cout << ".";
		Sleep(1000);

		system("cls");
	}

	menu();

	arquivo.close();
}
void menu()
{
	string opcao_menu = " ";
	int opcao_menu2 = 77;

	arquivo.open("pizzariadochefe.txt", ios::out);

	// MENU
	while (opcao_menu != "1" && opcao_menu != "2" && opcao_menu != "3")
	{
		cout << "\t    PIZZARIA DO CHEFE\t";
		cout << "\n\tComa mais, pagando menos!\t\n\n";

		cout << "\n-----MENU-----";

		cout << "\n\n 1 - Cadastrar";
		cout << "\n 2 - Pedido";
		cout << "\n 3 - Feedback";

		cout << "\n\n OBS: Escolha apenas as opcoes citadas acima!!!";

		cout << "\n\n Digite uma opcao: ";
		cin >> opcao_menu;

		system("cls");  // APAGAR DADOS VIA TECLADO
	}

	opcao_menu2 = stoi(opcao_menu);

	switch (opcao_menu2)

	{

	case 1:

		cout << "\n-----TELA DE CADASTRO-----";

		cout << "\n\n Digite o nome: ";
		cin.ignore();
		getline(cin, nome);
		arquivo << nome << "\n";

		cout << "\n Informe o cpf: ";
		getline(cin, cpf);
		arquivo << cpf << "\n";

		cout << "\n Informe o telefone: ";
		getline(cin, telefone);
		arquivo << telefone << "\n";

		cout << "\n Informe o endereco: ";
		getline(cin, endereco);
		arquivo << endereco << "\n";

		do
		{
			cout << "\n Informe o numero da casa: ";
			cin >> numero_casa;
			arquivo << numero_casa << "\n";
			system("cls");
		} while (numero_casa <= 0);

		cout << "\n Cadastro Concluido!";

		do
		{
			cout << "\n\n Deseja continuar e realizar o pedido? (S/N): ";
			cin >> realizar_pedido;
			system("cls");
		} while (realizar_pedido != "s" && realizar_pedido != "S" && realizar_pedido != "N" && realizar_pedido != "n");

		if (realizar_pedido == "S" || realizar_pedido == "s")
		{
			pedido();
		}

		else if (realizar_pedido == "n" || realizar_pedido == "N")
		{
			cout << "\n Cadastro Finalizado com sucesso!\n\n";
			cout << "\n Salvando dados.";
			Sleep(500);
			cout << ".";
			Sleep(500);
			cout << ".\n\n";
			Sleep(500);
			menu();
		}

		break;


	case 2:

		pedido();
		break;

	case 3:
		cout << "\n-----FEEDBACK-----";
		cout << "\n\n\n Como foi o atendimento? ";
		cin >> atendimento;
		arquivo << atendimento << "\n";
		cout << "\n OBRIGADO POR NOS AJUDAR A SEMPRE MELHORAR.\n\n";

		cout << "\n\n Salvando dados.";
		Sleep(500);
		cout << ".";
		Sleep(500);
		cout << ".\n\n";
		Sleep(500);
		menu();
	}
	arquivo.close();
}


void pedido()
{
	arquivo.open("pizzariadochefe.txt", ios::out);

	// CARDAPIO DE PIZZAS

	cout << "\n-----TELA DE PEDIDO-----\n\n";

	cout << "++++++++++++++++++++++++++++++++++++++++++++++";
	cout << "\n++++++++++++++++++++++++++++++++++++++++++++++";

	cout << "\n CARDAPIO DE PIZZAS\t";
	cout << "\n\n CALABRESA....................R$ 15,00\t";
	cout << "\n Mussarela, calabresa e cebola.";
	cout << "\n\n FRANGO CATUPIRY..............R$ 15,00\t";
	cout << "\n Frango, mussarela e catupiry.";
	cout << "\n\n MARGUERITA...................R$ 15,00\t";
	cout << "\n Mussarela com molho de tomate, manjericao e parmesao.";
	cout << "\n\n PORTUGUESA...................R$ 15,00\t";
	cout << "\n Mussarela, milho, ervilha, ovo, calabresa, cebola, azeitona e palmito.";
	cout << "\n\n QUATRO QUEIJOS...............R$ 15,00\t";
	cout << "\n Mussarela, provolone, queijo prato, catupiry.\n";

	cout << "\n++++++++++++++++++++++++++++++++++++++++++++++";
	cout << "\n++++++++++++++++++++++++++++++++++++++++++++++";

	cout << "\n\n Qual seria a quantidade de pizzas?: ";
	do
	{
		do
		{
			a = _getch();
			if (isdigit(a) != 0)
			{
				qtde_pizzas[l] = a;
				l++;
				cout << a;
				repeti_qtde = "1";
			}
			else if (a == 8 && l)
			{
				qtde_pizzas[l] = '\0';
				l--;
				cout << ("\b \b");
			}
		} while (a != 13);
	} while (repeti_qtde == "");

	string qtde_pizza1(qtde_pizzas);

	qtde_pizza = stoi(qtde_pizza1);


	for (p = 1; p <= qtde_pizza; p++)
	{

		cout << "\n\n Escolha o sabor da pizza: ";
		cin >> sabor_pizza;
		arquivo << sabor_pizza << "\n";
		fflush(stdin);
	}


	do
	{
		cout << "\n Gostaria de acrescentar ou retirar algum ingrediente? (S/N): ";
		cin >> ingredientes;
		system("cls");
	} while (ingredientes != "s" && ingredientes != "S" && ingredientes != "N" && ingredientes != "n");

	if (ingredientes == "S" || ingredientes == "s")
	{
		cout << "\n Qual o ingrediente?: ";
		cin >> resp_ingredientes;
		arquivo << resp_ingredientes << "\n";


		do
		{
			cout << "\n Gostaria de alguma bebida para acompanhar? (S/N): ";
			cin >> bebida;
			system("cls");
		} while (bebida != "s" && bebida != "S" && bebida != "N" && bebida != "n");

		if (bebida == "S" || bebida == "s")
		{
			cout << "++++++++++++++++++++++++++++++++++++++++++++++";
			cout << "\n++++++++++++++++++++++++++++++++++++++++++++++";
			cout << "\n\n CARDAPIO DE BEBIDAS 2L\t";
			cout << "\n\nCOCA-COLA....................R$ 8,00";
			cout << "\n\n FANTA LARANJA................R$ 8,00";
			cout << "\n\n FANTA UVA....................R$ 8,00";     // CARDAPIO DE BEBIDAS 2 LITROS
			cout << "\n\n PEPSI........................R$ 8,00";
			cout << "\n\n GUARANA......................R$ 8,00\n";

			cout << "\n++++++++++++++++++++++++++++++++++++++++++++++";
			cout << "\n++++++++++++++++++++++++++++++++++++++++++++++";

			cout << "\n\n Qual seria a quantidade de bebidas?: ";
			do
			{
				do
				{
					m = _getch();
					if (isdigit(m) != 0)
					{
						qtde_bebidas[g] = m;
						g++;
						cout << m;
						repeti_qtde1 = "1";
					}
					else if (m == 8 && g)
					{
						qtde_bebidas[g] = '\0';
						g--;
						cout << ("\b \b");
					}
				} while (m != 13);
			} while (repeti_qtde1 == "");

			string qtde_bebida1(qtde_bebidas);

			qtde_bebida = stoi(qtde_bebida1);


			for (b = 1; b <= qtde_bebida; b++)
			{

				cout << "\n\n Escolha a bebida de sua preferencia: ";
				cin >> sabor_bebida;
				arquivo << sabor_bebida << "\n";
				fflush(stdin);
			}

			cout << "\n Pedido Finalizado!";
			cout << "\n Total: R$" << (qtde_pizza * 15) + (qtde_bebida * 8) << ",00\n\n";

			system("pause");
			cout << "\n\n Salvando dados.";
			Sleep(500);
			cout << ".";
			Sleep(500);
			cout << ".\n\n";
			Sleep(500);
			menu();
		}


		if (bebida == "N" || bebida == "n")
		{
			cout << " Pedido Finalizado!";
			cout << "\n Total: R$" << (qtde_pizza * 15) + (qtde_bebida * 8) << ",00\n\n";

			system("pause");
			cout << "\n\n Salvando dados.";
			Sleep(500);
			cout << ".";
			Sleep(500);
			cout << ".\n\n";
			Sleep(500);
			menu();
		}

	}


	if (ingredientes == "N" || ingredientes == "n")
	{
		do
		{
			cout << "\n Gostaria de alguma bebida para acompanhar? (S/N): ";
			cin >> bebida;
			system("cls");
		} while (bebida != "s" && bebida != "S" && bebida != "N" && bebida != "n");

		if (bebida == "S" || bebida == "s")
		{
			cout << "\n\t\tCARDAPIO DE BEBIDAS 2L\t";
			cout << "\n\n\tCOCA-COLA....................R$ 8,00\t";
			cout << "\n\n\tFANTA LARANJA................R$ 8,00\t";
			cout << "\n\n\tFANTA UVA....................R$ 8,00\t";     // CARDAPIO DE BEBIDAS 2 LITROS
			cout << "\n\n\tPEPSI........................R$ 8,00\t";
			cout << "\n\n\tGUARANA......................R$ 8,00\t";

			cout << "\n\n Qual seria a quantidade de bebidas?: ";
			do
			{
				do
				{
					m = _getch();
					if (isdigit(m) != 0)
					{
						qtde_bebidas[g] = m;
						g++;
						cout << m;
						repeti_qtde1 = "1";
					}
					else if (m == 8 && g)
					{
						qtde_bebidas[g] = '\0';
						g--;
						cout << ("\b \b");
					}
				} while (m != 13);
			} while (repeti_qtde1 == "");

			string qtde_bebida1(qtde_bebidas);

			qtde_bebida = stoi(qtde_bebida1);


			for (b = 1; b <= qtde_bebida; b++)
			{

				cout << "\n\n Escolha a bebida de sua preferencia: ";
				cin >> sabor_bebida;
				arquivo << sabor_bebida << "\n";
				fflush(stdin);
			}

			cout << "\n Pedido Finalizado!";
			cout << "\n Total: R$" << (qtde_pizza * 15) + (qtde_bebida * 8) << ",00\n\n";

			system("pause");
			cout << "\n\n Salvando dados.";
			Sleep(500);
			cout << ".";
			Sleep(500);
			cout << ".\n\n";
			Sleep(500);
			menu();
		}

		if (bebida == "N" || bebida == "n")
		{
			cout << "\n Pedido Finalizado!";
			cout << "\n Total: R$" << (qtde_pizza * 15) + (qtde_bebida * 8) << ",00\n\n";

			system("pause");
			cout << "\n\n Salvando dados.";
			Sleep(500);
			cout << ".";
			Sleep(500);
			cout << ".\n\n";
			Sleep(500);
			menu();

		}
	}
	arquivo.close();
}