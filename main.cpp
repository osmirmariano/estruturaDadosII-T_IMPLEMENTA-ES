#include <iostream>
#include <cstdlib>
#include "Pessoa.cpp"

using namespace std;

int main(int argc, char const *argv[])
{
	string nome;
	int idade, opcao, fator;
	Pessoa *raiz, *people, *novo, *pai; /**atualiza*/
	raiz = NULL;
	pai = NULL;

	do{
		cout << "-----------------------------------------------------------------" << endl;
		cout << " MENU PRINCIPAL" << endl;
		cout << "-----------------------------------------------------------------" << endl;
		cout << " 1  - INSERIR ELEMENTOS" << "       | 9  - QUANTIDADES DE NÓS" << endl;
		cout << " 2  - LISTAR EM PRÉ-ORDEM" << "     | 10 - FATOR DE BALANCEAMENTO" << endl;
		cout << " 3  - LISTAR EM-ORDEM" << "         | 11 - REMOVER UM NÓ" << endl;
		cout << " 4  - LISTAR EM PÓS-ORDEM" << "     | 12 - BUBBLE SORT " << endl;
		cout << " 5  - PROFUNDIDADE DA ÁRVORE" << "  | 13 - SELECTION SORT " << endl;
		cout << " 6  - PROFUNDIDADE ESQUERDA" << "   | 14 - INSERTION SORT " << endl;
		cout << " 7  - PROFUNDIDADE DIREITA" << "    | 15 - SHELL SORT " << endl;
		cout << " 8  - SOMA DE TODAS AS IDADES" << " | 17 - QUICK SORT " << endl;
		cout << " 0  - SAIR" << endl;
		cout << "-----------------------------------------------------------------" << endl;
		cout << "OPÇÃO: ";
		cin >> opcao;

		Pessoa *o = new Pessoa();
		switch (opcao){
			case 1:
				cout << endl << "-----------------------------------------" << endl;
				cout << "\tINSERÇÃO DE ELEMENTOS" << endl;
				cout << " NOME: ";
				cin >> nome;
				cout << " IDADE: ";
				cin >> idade;
				cout << "-----------------------------------------" << endl << endl;

				novo =  new Pessoa(idade, nome, fator);
				if (raiz == NULL){
					raiz = novo;
					//raiz->atualizaFator(&raiz);
				}
				else{
					raiz->inserirNos(novo, &raiz);
					//raiz->atualizaFator(&raiz);
				}
				break;

			case 2:
				if(raiz == NULL)
					cout << "Raiz Vazia" << endl;
				else{
					cout << endl;
					cout << "-----------------------------------------" << endl;
					cout << "\tLISTA PRÉ-ORDEM" << endl;
					raiz->listaPreOrdem();
					cout << "-----------------------------------------" << endl << endl;
				}
				break;

			case 3:
				if(raiz == NULL)
					cout << "Raiz Vazia" << endl;
				else{
					cout << endl;
					cout << "-----------------------------------------" << endl;
					cout << "\tLISTA EM-ORDEM" << endl;
					raiz->listaEmOrdem();
					cout << "-----------------------------------------" << endl << endl;
				}
				break;
			case 4:
				if(raiz == NULL)
					cout << "Raiz Vazia" << endl;
				else{
					cout << endl;
					cout << "-----------------------------------------" << endl;
					cout << "\tLISTA PÓS-ORDEM" << endl;
					raiz->listaPosOrdem();
					cout << "-----------------------------------------" << endl << endl;
				}
				break;

			case 5:
				if (raiz == NULL)
					cout << "Raiz Vazia" << endl;
				else{
					cout << endl;
					cout << "-----------------------------------------" << endl;
					cout << "\tPROFUNDIDADE DA ÁRVORE" << endl;
					cout << "-----------------------------------------" << endl;
					cout << "PROFUNDIDADE: " << raiz->profundidadeNo() << endl;
				}
				break;

			case 6:
				if (raiz == NULL)
					cout << "Raiz Vazia" << endl;
				else{
					cout << endl;
					cout << "-----------------------------------------" << endl;
					cout << "\tPROFUNDIDADE ESQUERDA" << endl;
					cout << "-----------------------------------------" << endl;
					cout << "PROFUNDIDADE: " << raiz->profundidadeEsq() << endl;
				}
				break;

			case 7:
				if (raiz == NULL)
					cout << "Raiz Vazia" << endl;
				else{
					cout << endl;
					cout << "-----------------------------------------" << endl;
					cout << "\tPROFUNDIDADE DIREITA" << endl;
					cout << "-----------------------------------------" << endl;
					cout << "PROFUNDIDADE: " << raiz->profundidadeDir() << endl;
				}
				break;
			case 8:
				if (raiz == NULL)
					cout << "Raiz Vazia" << endl;
				else{
					cout << endl;
					cout << "-----------------------------------------" << endl;
					cout << "\tSOMA DE TODAS AS IDADES" << endl;
					cout << "-----------------------------------------" << endl;
					cout << "TOTAL: " << raiz->somarNos() << endl;
				}
				break;

			case 9:
				if (raiz == NULL)
					cout << "Raiz Vazia" << endl;
				else{
					cout << endl;
					cout << "-----------------------------------------" << endl;
					cout << "\tQUANTIDADES DE NÓS" << endl;
					cout << "-----------------------------------------" << endl;
					cout << "QUANTIDADE: " << raiz->quantidadeNos() << endl;
				}
				break;

			case 10:
				if (raiz == NULL)
					cout << "Raiz Vazia" << endl;
				else{
					cout << endl;
					cout << "-----------------------------------------" << endl;
					cout << "\tFATOR DE BALANCEAMENTO" << endl;
					cout << "-----------------------------------------" << endl;
					raiz->fatorBalanceamento(&raiz);
					raiz->listaPre();
				}
				break;

			case 11:
				if (raiz == NULL)
					cout << "Raiz Vazia" << endl;
				else{
					cout << endl;
					cout << "-----------------------------------------" << endl;
					cout << "\tEXCLUSÃO DE ELEMENTOS" << endl;
					cout << "-----------------------------------------" << endl;
					cout << " INFORME A IDADE QUE DESEJA EXCLUIR: ";
					cin >> idade;
					cout << "\tAntes" << endl;
					raiz->listaPreOrdem();
					cout << "-----------------------------------------" << endl;
					raiz->removerNo(&raiz, pai, idade);
					cout << "\tDepois" << endl;
					raiz->listaPreOrdem();
				}
				break;
			case 12:
			cout << endl << "-----------------------------------------" << endl;
	            cout << "\tBUBBLE SORT";
	            cout << endl << "-----------------------------------------" << endl;
				o->bubbleShort();
				cout <<"-----------------------------------------" << endl;
            	break;

            case 13:
				cout << endl << "-----------------------------------------" << endl;
	            cout << "\tSELECTION SORT";
	            cout << endl << "-----------------------------------------" << endl;
				o->selectionSort();
				cout <<"-----------------------------------------" << endl;
            	break;

            case 14:
				cout << endl << "-----------------------------------------" << endl;
	            cout << "\tINSERTION SORT";
	            cout << endl << "-----------------------------------------" << endl;
				o->insertionSort();
				cout <<"-----------------------------------------" << endl;
            	break;
            
            case 15:
				cout << endl << "-----------------------------------------" << endl;
	            cout << "\tSHELL SORT";
	            cout << endl << "-----------------------------------------" << endl;
				o->shellSort();
				cout <<"-----------------------------------------" << endl;
            	break;
			
			case 16:
				cout << endl << "-----------------------------------------" << endl;
	            cout << "\tMARGE SORT";
	            cout << endl << "-----------------------------------------" << endl;
				//o->margeSort();
				cout <<"-----------------------------------------" << endl;
            	break;

            case 17:
				cout << endl << "-----------------------------------------" << endl;
	            cout << "\tQUICK SORT";
	            cout << endl << "-----------------------------------------" << endl;
				//o->quickSort(0,MAX-1);
				cout <<"-----------------------------------------" << endl;
            	break;
				
			case 0:
				cout << "Programa encerrado com sucesso!" << endl << endl << endl;
				break;

			default:
				cout << "Opção Inválida!" << endl;
		};
	}while (opcao != 0);
};
