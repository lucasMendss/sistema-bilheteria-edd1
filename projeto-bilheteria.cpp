#include <iostream>
#include <locale.h>
using namespace std;

int main(int argc, char** argv)
{
	setlocale(LC_ALL, "");
	
	bool ocupacoes[15][40];
	//populando toda a matriz com false (todos os lugares livres)
	for(int fileira = 0; fileira < 15; fileira++){
		for(int poltrona = 0; poltrona < 40; poltrona++){
			ocupacoes[fileira][poltrona] = false;
			//cout << fileira+1 << "-" << poltrona+1 << ":" << ocupacoes[fileira][poltrona] << endl;
		}
	}
	
	int fileiraEscolhida;
	int poltronaEscolhida;
	int opcao;
	while(opcao != 0){
		
		cout << "Escolha uma opção:" << endl;
		cout << "0: Finalizar" << endl;
		cout << "1: Reservar poltrona" << endl;
		cout << "2: Mostrar mapa de ocupação" << endl;
		cout << "3: Mostrar faturamento" << endl;
		cin >> opcao;
		switch(opcao){
			case 0:
				cout << "Programa finalizado." << endl;
				break;
			case 1:
				fileiraEscolhida = 0;
				poltronaEscolhida = 0;
				//solicitar fileira
				while(fileiraEscolhida < 1 || fileiraEscolhida > 15){
					cout << "Digite o nº da fileira(1 a 15): " << endl;
					cin >> fileiraEscolhida;
					if(fileiraEscolhida < 1 || fileiraEscolhida > 15){
						cout << "Número inválido. Tente novamente" << endl;
					}	
				}
				//solicitar poltrona
				while(poltronaEscolhida < 1 || poltronaEscolhida > 40){
					cout << "Digite o nº da poltrona(1 a 40): " << endl;
					cin >> poltronaEscolhida;
					if(poltronaEscolhida < 1 || poltronaEscolhida > 40){
						cout << "Número inválido. Tente novamente" << endl;
					}
					if(!ocupacoes[fileiraEscolhida-1][poltronaEscolhida-1]){
						ocupacoes[fileiraEscolhida-1][poltronaEscolhida-1] = true;
						cout << "Reserva feita" << endl;
						
					}
					else{
						cout << "O lugar f" << fileiraEscolhida << "-p" << poltronaEscolhida 
						<< " está ocupado. Tente reservar outro." << endl;
					}
				}
				break;
			case 2:
				cout << "Escolheu " << opcao << endl;
				break;
			case 3:
				cout << "Escolheu " << opcao << endl;
				break;
			case 4:
				cout << "Escolheu " << opcao << endl;
				break;
			default:
				cout << "Opção inválida. Tente novamente." << endl;
				break;
		}
	} 
	return 0;
}