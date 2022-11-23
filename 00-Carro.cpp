#include <iostream> //entrada e saida de dados - fluxo de informacoes
#include <string>

using namespace std; //evita a duplicidade

class Carro{
	public:
		string modelo;
		string chassi;
		string cor;
		bool motor;
		bool volante;
		
	public:
		Carro (string modelo, string chassi, string cor){
			this -> cor = cor;
			this -> modelo = modelo;
			this -> chassi = chassi;
		}
		
		void setModelo(string m){
			modelo = m;	
		}
		
		void setChassi(string cha){
			chassi = cha;
		}
		
		void ligarCarro(){
			motor = true;
			cout << "Motor ligado!" <<endl;
		}
		
		void desligarCarro(){
			motor = false;
			cout <<"Motor desligado!" <<endl;
		}
		
		void curvarEsquerda(){
			if (motor == true){
				volante = true;
			}
			else{
				cout << "Motor nao esta ligado! " <<endl;
			}
		}
		
		void curvarDireita(){
			if (motor == true){
				volante = true;
			}
			else{
				cout <<"Motor nao esta ligado! " <<endl;
			}
		
		}
		};
		
int main(){
	Carro myHyunday ("HB20", "07412", "prata");
	cout << myHyunday.modelo << " " << myHyunday.chassi << " " << myHyunday.cor << endl;
	
	Carro meuToyota ("Corolla", "1234", "preto");
	meuToyota.ligarCarro();
	meuToyota.curvarEsquerda();
	
	return 0;
};