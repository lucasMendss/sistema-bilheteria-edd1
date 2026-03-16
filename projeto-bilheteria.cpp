#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <locale.h>
using namespace std;

int main(int argc, char** argv)
{
	setlocale(LC_ALL, "");
	
	int i;
	
	bool **ocupacoes;
	ocupacoes = (bool**)malloc(40 * sizeof(bool*));
	
	for(i=0; i<40; ++i) // Percorre as linhas
	{
		ocupacoes[i] = (bool*)malloc(15 * sizeof(bool)); // Inicialização de cada coluna
	}
	
	//populando toda a matriz com false (todos os lugares livres)
	for(int fileira = 0; fileira < 40; fileira++){
		for(int poltrona = 0; poltrona < 15; poltrona++){
			ocupacoes[fileira][poltrona] = false;
		}
	}
	
	int qtdeReservas = 0;
	float valorTotal = 0;
	int opcao;
	while(opcao != 0){
		int fileiraEscolhida;
		int poltronaEscolhida;
		
		cout << setfill('-') << setw(65) << "" << endl;
		cout << "Escolha uma opção:" << endl;
		cout << "0: Finalizar" << endl;
		cout << "1: Reservar poltrona" << endl;
		cout << "2: Mostrar mapa de ocupação" << endl;
		cout << "3: Mostrar faturamento" << endl;
		cout << setfill('-') << setw(65) << "" << endl;
		cin >> opcao;
		switch(opcao){
			
			case 0:
				cout << setfill('-') << setw(65) << "" << endl;
				cout << "Programa finalizado." << endl;
				cout << setfill('-') << setw(65) << "" << endl;
				break;
			
			case 1:
				fileiraEscolhida = 0;
				poltronaEscolhida = 0;
				//solicitar fileira
				
				while(fileiraEscolhida < 1 || fileiraEscolhida > 15){
					cout << setfill('-') << setw(65) << "" << endl;
					cout << "Digite o nº da fileira(1 a 15): ";
					
					cin >> fileiraEscolhida;
					if(fileiraEscolhida < 1 || fileiraEscolhida > 15){
						cout << setfill('-') << setw(65) << "" << endl;
						cout << "Número inválido. Tente novamente" << endl;
						cout << setfill('-') << setw(65) << "" << endl;
					}	
				}
				//solicitar poltrona
				while(poltronaEscolhida < 1 || poltronaEscolhida > 40){
					cout << setfill('-') << setw(65) << "" << endl;
					cout << "Digite o nº da poltrona(1 a 40): ";
					
					cin >> poltronaEscolhida;
					if(poltronaEscolhida < 1 || poltronaEscolhida > 40){
						cout << setfill('-') << setw(65) << "" << endl;
						cout << "Número inválido. Tente novamente" << endl;
						cout << setfill('-') << setw(65) << "" << endl;
					}
				}
					// reservar lugar se estiver vazio
					if(!ocupacoes[poltronaEscolhida-1][fileiraEscolhida-1]){
						ocupacoes[poltronaEscolhida-1][fileiraEscolhida-1] = true;
						qtdeReservas++;
						
						cout << setfill('-') << setw(65) << "" << endl;
						cout << "f" << fileiraEscolhida << "-p" << poltronaEscolhida 
						<< " reservado com sucesso." << endl;
						cout << setfill('-') << setw(65) << "" << endl;
						
						if(fileiraEscolhida >= 1 && fileiraEscolhida <= 5){
							valorTotal += 50;
						}
						else if(fileiraEscolhida >= 6 && fileiraEscolhida <= 10){
							valorTotal += 30;
						}
						else{
							valorTotal += 15;
						}
					}
					// avisar caso estiver ocupado
					else{
						cout << setfill('-') << setw(65) << "" << endl;
						cout << "O lugar f" << fileiraEscolhida << "-p" << poltronaEscolhida 
						<< " está ocupado. Tente reservar outro." << endl;
						cout << setfill('-') << setw(65) << "" << endl;
					}
				break;
			case 2: 
				cout << setfill('-') << setw(65) << "" << endl;
				for(int poltrona = 0; poltrona < 40; poltrona++){
					if(poltrona == 0){
						cout << "  ";
						for(int i = 1; i < 16; i++){
							if(i < 10){
								cout << "| " << i;	
							}
							else{
								cout << "|" << i;
							} 
						}
						cout << "|" << endl;
					}
					cout << setfill(' ') << setw(2) << poltrona+1;
					for(int fileira = 0; fileira < 15; fileira++){
						   if(!ocupacoes[poltrona][fileira]){
								cout << "|" << "..";	   
						   }
						   else{
							   cout << "|" << "##";   
						   }	
					}
					cout << "|" << endl;
				}
				cout << setfill('-') << setw(65) << "" << endl;
				cout << "Legenda" << endl;
				cout << "- ## Lugar Ocupado " << endl;
				cout << "- .. Lugar livre " << endl;
				cout << setfill('-') << setw(65) << "" << endl;
				break;
			case 3:
				cout << setfill('-') << setw(65) << "" << endl;
				cout << left << setfill('.') << setw(35) << "Qtde. de lugares reservados: "  << qtdeReservas << endl;
				cout << fixed;
				cout << left << setfill('.') << setw(35) << "Valor da bilheteria: " << "R$" << setprecision(2) << valorTotal << endl;
				cout << setfill('-') << setw(65) << "" << endl;
				break;
			default:
				cout << setfill('-') << setw(65) << "" << endl;
				cout << "Opção inválida. Tente novamente." << endl;
				cout << setfill('-') << setw(65) << "" << endl;
				break;
		}
	} 
	return 0;
}
