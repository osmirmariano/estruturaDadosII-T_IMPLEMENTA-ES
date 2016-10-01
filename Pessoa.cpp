#include <iostream>
#define MAX 10
using namespace std;

class Pessoa{
	public:
		int idade, fator, vetor[MAX];
		string nome;
		Pessoa *filhoEsquerdo;
		Pessoa *filhoDireito;
		Pessoa *pai;
		
	public:
		Pessoa (){
			filhoEsquerdo =  NULL;
			filhoDireito = NULL;
			pai = NULL;

			vetor[0]=1;
			vetor[1]=5;
			vetor[2]=0;
			vetor[3]=20;
			vetor[4]=9;
			vetor[5]=10;
			vetor[6]=6;
			vetor[7]=8;
			vetor[8]=30;
			vetor[9]=4;
		};

		Pessoa(int idade, string nome, int fator){
			this->idade = idade;
			this->nome = nome;
			this->fator = fator;
			this->filhoEsquerdo = NULL;
			this->filhoDireito = NULL;
			pai = NULL;
		};

		~Pessoa(){
			cout << "Nome: " << this->nome << " Idade: " << this->idade << endl;
		};

		/*--------------------INÍCIO FUNÇÕES SETTERS E GETTERS----------------------*/
		string getNome(){
			return nome;
		};

		void setNome(string nome){
			this->nome = nome;
		};

		int getIdade(){
			return idade;
		};

		void setIdade(int idade){
			this->idade = idade;
		};

		int getFator(){
			return fator;
		};

		void setFator(int fator){
			this->fator = fator;
		}

		Pessoa *getFilhoEsquerdo(){
			return filhoEsquerdo;
		};

		void *setFilhoEsquerdo(Pessoa *fEsq){
			this->filhoEsquerdo = fEsq;
		};

		Pessoa *getFilhoDireito(){
			return filhoDireito;
		};

		void *setFilhoDireito(Pessoa *fDir){
			this->filhoDireito = fDir;
		};

		Pessoa *getPai(){
			return pai;
		};

		void *setPai(Pessoa *p){
			this->pai = p;
		};
		/*--------------------------------------------------------------------------*/

		/*---------------------INÍCIO INSERIR ELEMENTOS NA LISTA--------------------*/
		void inserirNos(Pessoa *novo, Pessoa **raiz){
			if (this->idade > novo->idade){
				if (this->filhoEsquerdo == NULL){
					this->filhoEsquerdo = novo;
					this->filhoEsquerdo->pai = NULL;
				}
				else
					this->filhoEsquerdo->inserirNos(novo, raiz);
			}
			else{
				if (this->filhoDireito == NULL){
					this->filhoDireito = novo;
					this->filhoDireito->pai = NULL;
				}
				else
					this->filhoDireito->inserirNos(novo, raiz);
			}
			(*raiz)->fatorBalanceamento(raiz);
			(*raiz)->checaBalanceamento(raiz);
		};
		/*--------------------------------------------------------------------------*/

		/*----------------INÍCIO LISTAGEM DOS ELEMENTOS PRÉ-ORDEM-------------------*/
		void listaPreOrdem(){
			cout << "-----------------------------------------" << endl;
			cout << "NOME: " << this->nome << " | IDADE: " << this->idade << endl;

			if(this->filhoEsquerdo != NULL)
				this->filhoEsquerdo->listaPreOrdem();
			if(this->filhoDireito != NULL)
				this->filhoDireito->listaPreOrdem();
		};
		/*--------------------------------------------------------------------------*/

		/*----------------INÍCIO LISTAGEM DOS ELEMENTOS EM-ORDEM--------------------*/
		void listaEmOrdem(){
			if (this->filhoEsquerdo != NULL)
				this->filhoEsquerdo->listaEmOrdem();
			cout << "-----------------------------------------" << endl;
			cout << "NOME: " << this->nome << " | IDADE: " << this->idade << endl;
			if (this->filhoDireito != NULL)
				this->filhoDireito->listaEmOrdem();
		};
		/*--------------------------------------------------------------------------*/

		/*----------------INÍCIO LISTAGEM DOS ELEMENTOS PÓS-ORDEM-------------------*/
		void listaPosOrdem(){
			if (this->filhoEsquerdo != NULL)
				this->filhoEsquerdo->listaPosOrdem();
			if (this->filhoDireito != NULL)
				this->filhoDireito->listaPosOrdem();
			cout << "-----------------------------------------" << endl;
			cout << "NOME: " << this->nome << " | IDADE: " << this->idade << endl;
		}
		/*--------------------------------------------------------------------------*/

		/*----------------------INÍCIO SOMA DAS IDADES DOS NÓS----------------------*/
		int somarNos(){
			int total = 0;
			if(this->filhoEsquerdo != NULL)
				total = this->filhoEsquerdo->somarNos();
			if (this->filhoDireito !=  NULL)
				total = total + this->filhoDireito->somarNos();
			return total + this->idade;
		};
		/*--------------------------------------------------------------------------*/

		/*--------------------------INÍCIO QUANTIDADES DE NÓS-----------------------*/
		int quantidadeNos(){
			int quantidade = 0;
			if(this->filhoEsquerdo != NULL)
				quantidade = this->filhoEsquerdo->quantidadeNos();
			if(this->filhoDireito != NULL)
				quantidade = quantidade + this->filhoDireito->quantidadeNos();
			return quantidade + 1;
		};
		/*--------------------------------------------------------------------------*/

		/*-------------------------INÍCIO PROFUNDIDADE ÁRVORE-----------------------*/
		int profundidadeNo(){
			int profEsquerdo = 0, profDireito = 0;
			if(this->filhoEsquerdo != NULL)
				profEsquerdo = this->filhoEsquerdo->profundidadeNo()+1;
			if(this->filhoDireito != NULL)
				profDireito = this->filhoDireito->profundidadeNo()+1;
			return (profEsquerdo > profDireito) ? profEsquerdo : profDireito;
		};
		/*--------------------------------------------------------------------------*/

//---------------------------------------------------AVL----------------------------------------

		/*----------------------INÍCIO LISTA DOS FATORES DE BALANCEAMENTO----------------------*/
		void listaPre(){
			cout << "-----------------------------------------" << endl;
			cout << "NOME: " << this->nome;
			cout << " | IDADE: " << this->idade;
			cout << " | FATOR: " << this->fator << endl;

			if(this->filhoEsquerdo != NULL)
				this->filhoEsquerdo->listaPre();
			if(this->filhoDireito != NULL)
				this->filhoDireito->listaPre();
		};
		/*--------------------------------------------------------------------------*/

		/*-----------------------INÍCIO PROFUNDIDADE ESQUERDO-----------------------*/
		int profundidadeEsq(){
			int profEsquerdo = 0;
			if(this->filhoEsquerdo != NULL)
				profEsquerdo = this->filhoEsquerdo->profundidadeNo()+1;
			return profEsquerdo;
		};
		/*--------------------------------------------------------------------------*/

		/*-----------------------INÍCIO PROFUNDIDADE DIREITO------------------------*/
		int profundidadeDir(){
			int profDireito = 0;
			if (this->filhoDireito != NULL)
				profDireito = this->filhoDireito->profundidadeNo()+1;
			return profDireito;
		};
		/*--------------------------------------------------------------------------*/

		/*----------------------INÍCIO FATOR DE BALANCEAMENTO-----------------------*/
		void fatorBalanceamento(Pessoa **raiz){
			if(this->filhoEsquerdo != NULL)
				this->filhoEsquerdo->fatorBalanceamento(raiz);
			if(this->filhoDireito != NULL)
				this->filhoDireito->fatorBalanceamento(raiz);
			this->fator = (this->profundidadeDir())-(this->profundidadeEsq());
		};
		/*--------------------------------------------------------------------------*/


		/*--------------------INÍCIO ROTAÇÃO À DIREITA SIMPLES----------------------*/
		void rotacaoSimplesDireita(Pessoa **raiz){
			(*raiz) = this->filhoEsquerdo;
			this->filhoEsquerdo = (*raiz)->filhoDireito;
			(*raiz)->filhoDireito = this;
		};
		/*---------------------------------------------------------------------------*/


		/*--------------------INÍCIO ROTAÇÃO À ESQUERDA SIMPLES----------------------*/
		void rotacaoSimplesEsquerda(Pessoa **raiz){
	        (*raiz) = this->filhoDireito;
			this->filhoDireito = (*raiz)->filhoEsquerdo;
			(*raiz)->filhoEsquerdo=this;
		};
		/*---------------------------------------------------------------------------*/


		/*--------------------INÍCIO ROTAÇÃO À DIREITA DUPLA-------------------------*/
		void rotacaoDuplaDireita(Pessoa **raiz){
			this->filhoEsquerdo->rotacaoSimplesEsquerda(&(this->filhoEsquerdo));
			this->rotacaoSimplesDireita(&(*raiz));
		};
		/*--------------------------------------------------------------------------*/


		/*--------------------INÍCIO ROTAÇÃO À ESQUERDA SIMPLES----------------------*/
		void rotacaoDuplaEsquerda(Pessoa **raiz){
			this->filhoDireito->rotacaoSimplesDireita(&(this->filhoDireito));
			this->rotacaoSimplesEsquerda(&(*raiz));
		};
		/*---------------------------------------------------------------------------*/
	
		/*----------------------INÍCIO CHECANDO O BALANCEAMENTO---------------------*/
		void checaBalanceamento(Pessoa **raiz){
			if(this->fator >=-1 && this->fator <= 1){//SE ESTIVER BALANCEADA VAI ANDANDO
				if(this->filhoEsquerdo != NULL)
					this->filhoEsquerdo->checaBalanceamento(raiz);
				if(this->filhoDireito != NULL)
					this->filhoDireito->checaBalanceamento(raiz);
			}	
			else{
				if(this->fator > 1 || this->fator < -1){
					if (this->fator > 1){
						if(this->filhoDireito->fator >= 0){//Rotação para esquerda - rotação simples
							cout << endl;
							cout << "ROTAÇÃO PARA ESQUERDA - SIMPLES" << endl;
							cout << "-----------------------------------------" << endl;
							cout << "\tELEMENTO DESBALANCEADO" << endl;
							this->rotacaoSimplesEsquerda(raiz);
							cout << "NOME: " << this->nome;
							cout << " | IDADE: " << this->idade;
							cout << " | FATOR: " << this->fator << endl;
						}
						else{//Rotação Dupla
							if(this->filhoDireito->fator < 0){
								cout << endl;
								cout << "ROTAÇÃO PARA ESQUERDA - DUPLA" << endl;
								cout << "-----------------------------------------" << endl;
								cout << "\tELEMENTO DESBALANCEADO" << endl;
								this->rotacaoDuplaEsquerda(raiz);
								cout << "NOME: " << this->nome;
								cout << " | IDADE: " << this->idade;
								cout << " | FATOR: " << this->fator << endl;
							}
						}
					}
					else{//Rotação para direita - rotação simples
						if(this->fator < -1){
							if(this->filhoEsquerdo->fator < 0){
								cout << endl;
								cout << "ROTAÇÃO PARA DIREITA - SIMPLES" << endl;
								cout << "-----------------------------------------" << endl;
								cout << "\tELEMENTO DESBALANCEADO" << endl;
								this->rotacaoSimplesDireita(raiz);
								cout << "NOME: " << this->nome;
								cout << " | IDADE: " << this->idade;
								cout << " | FATOR: " << this->fator << endl;
							}
							else{//Rotação dupla
								if(this->filhoEsquerdo->fator >= 0){
									cout << endl;
									cout << "ROTAÇÃO PARA DIREITA - DUPLA" << endl;
									cout << "-----------------------------------------" << endl;
									cout << "\tELEMENTO DESBALANCEADO" << endl;
									this->rotacaoDuplaDireita(raiz);
									cout << "NOME: " << this->nome;
									cout << " | IDADE: " << this->idade;
									cout << " | FATOR: " << this->fator << endl;
								}
							}
						}
					}
					(*raiz)->fatorBalanceamento(raiz);
				}
			}
		};
		/*--------------------------------------------------------------------------*/
		
		/*--------------------------INÍCIO REMOÇÃO DE NÓS---------------------------*/
		Pessoa *removerNo(Pessoa **raiz, Pessoa *pai, int idade){
			Pessoa *aux =  NULL; 
			Pessoa *armazena =  NULL;

			if (this->idade == idade){
				if (this == (*raiz)){
					if (this->filhoEsquerdo ==  NULL && this->filhoDireito == NULL)
						(*raiz) = NULL;
					else{
						if (this->filhoEsquerdo == NULL && this->filhoDireito != NULL)
							(*raiz) = this->filhoDireito;
						else{
							if (this->filhoEsquerdo != NULL && this->filhoDireito == NULL)
								(*raiz) = this->filhoEsquerdo;
							else{
								if (this->filhoEsquerdo != NULL && this->filhoDireito != NULL){
									aux = this->filhoEsquerdo;
									
									while (aux->filhoDireito != NULL){
										aux = aux->filhoDireito;
									}
									this->nome=aux->nome;
									this->idade=aux->idade;
									aux->removerNo(raiz, pai, aux->idade);
								}
							}
						}
					}
					delete this;
				}
				else{
					//NÓ FOLHA
					if (this->filhoEsquerdo == NULL && this->filhoDireito == NULL){
						if (this->pai->filhoEsquerdo == this){
							this->pai->filhoEsquerdo =  NULL;
						}
						else{
							this->pai->filhoDireito = NULL;
						}
						delete this;
					}
					else{
						//NÓ COM UM FILHO
						if (this->filhoEsquerdo != NULL && this->filhoDireito == NULL){
							if (this->pai->filhoEsquerdo == this)
								this->pai->filhoEsquerdo = this->filhoEsquerdo;
							else
								this->filhoEsquerdo->removerNo(raiz, pai, idade);
						}
						else{
							if (this->filhoDireito != NULL && this->filhoEsquerdo == NULL){
								if (this->pai->filhoDireito == this)
									this->pai->filhoDireito = this->filhoDireito;
								else
									this->filhoDireito->removerNo(raiz, pai, idade);
							}
							else{
								//NÓ COM DOIS FILHOS
								if (this->filhoEsquerdo != NULL && this->filhoDireito != NULL){
									aux = this->filhoDireito;
									while (aux->filhoEsquerdo != NULL){
										aux = aux->filhoEsquerdo;
									}
									if (this->pai->filhoEsquerdo == this)	
										this->pai->filhoEsquerdo = aux;
									else
										this->pai->filhoDireito =  aux;
									aux->pai->filhoEsquerdo = aux->filhoDireito;
									aux->pai = this->pai;
									aux->filhoEsquerdo = this->filhoDireito;
								}
							}
						}
						delete this;
					}
				}
				(*raiz)->fatorBalanceamento(raiz);
			}
			else{
				//PERCORRER A ÁRVORE EM BUSCA DO NÓ CORRETO
				if(this->filhoEsquerdo != NULL && this->idade > idade)
					this->filhoEsquerdo->removerNo(raiz, pai, idade);
				else{
					if (this->filhoDireito != NULL && this->idade < idade)
						this->filhoDireito->removerNo(raiz, pai, idade);
					else
						cout << "Valor informando não corresponde à nenhum elemento presente" << endl;
				}
			}
		};

		/*--------------------------------------------------------------------------*/

		/*--------------------------INÍCIO BUBBLE SORT------------------------------*/
		void bubbleShort(){
			for (int y = MAX; y > 0; y--){
				for (int x = 0; x < MAX; x++){
					if (vetor[x] > vetor[x+1]){
						int aux = vetor[x+1];
						vetor[x+1] = vetor[x];
						vetor[x] = aux;
					}
				}
			}
			printar();
		};
		/*--------------------------------------------------------------------------*/

		/*--------------------------INÍCIO SELECTION SORT---------------------------*/
		void selectionSort(){
			for (int x = 0; x < MAX; x++){
				int menor = vetor[x];
				for (int y = x+1; y < MAX; y++){
					if (vetor[y] < menor){
						int aux =  menor;
						menor = vetor[y];
						vetor[y] = aux;
					}
				}
				vetor[x]=menor;
			}
			printar();
		};
		/*--------------------------------------------------------------------------*/

		/*--------------------------INÍCIO INSERTION SORT---------------------------*/
		void insertionSort(){
		    for(int x = 0; x < MAX; x++){
		        int aux = vetor[x];
		        int y = x-1;
		        while(y >= 0 && vetor[y] > aux){
		            vetor[y+1] = vetor[y];
		            y--;
		        };
		        vetor[y+1] = aux;
		    }
			printar();
		};
		/*--------------------------------------------------------------------------*/

		/*----------------------------INÍCIO SHELL SORT-----------------------------*/
		void shellSort(){
			int k;
			if(MAX%2==0)
				k=MAX/2;
			else
				k=(MAX/2)+1;
			for(;k>0;k--){
				for(int i=0;i+k<MAX;i++){
					if(vetor[i]>vetor[i+k]){
						int aux = vetor[i];
						vetor[i]=vetor[i+k];
						vetor[i+k]=aux;
					}
				}
			}
			printar();
		};
		/*--------------------------------------------------------------------------*/

		/*----------------------------INÍCIO MARGE SORT-----------------------------*/

		/*--------------------------------------------------------------------------*/

		/*----------------------------INÍCIO QUICK SORT-----------------------------*/
		/*void quickSort(int inicio, int fim){
	       	int i, j, pivo, metade, aux;
	       	i = inicio;
	       	j = fim;

	       	metade = (int)((i+j)/2);
	      	pivo =  vetor[metade];
	       	do{
	          	while(vetor[i] < pivo)
	            	i = i+1;
	          	while(vetor[j] > pivo)
		            j = j-1;
		          	if(i <= j){
			            aux = vetor[i];
			            vetor[i] = vetor[j];
			            vetor[j] = aux;
			            i = i+1;
			            j = j-1;
		          	};
	       }while(j > i);

	       // 	if(inicio < j)
	       // 		quickSort(inicio,j);
	      	// if(i < fim)
	       // 		quickSort(i,fim);
		    printar();
	    };*/
		/*--------------------------------------------------------------------------*/

		/*--------------------------INÍCIO PRINTAR VETOR----------------------------*/
		void printar(){
			cout<<endl;
			for(int i=0;i<MAX;i++)
				cout<<vetor[i]<<endl;
		};
		/*--------------------------------------------------------------------------*/
};
		
		
	