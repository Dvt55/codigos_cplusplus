#include <iostream>
#include <string.h>

using namespace std;

typedef struct{

    int dia;
    int mes;
    int ano;
}Data;

typedef struct {
    char nome[100];
    float altura;
    Data nascimento;

}Pessoa;

void CriaData(Data &D){
   D.mes = 1 + (rand() % 12);
   D.ano = 1950 + (rand() % 49);
   D.dia = 1 + (rand() % 30);
}

void ImprimeTelaDeOpcoes(){

    cout << "1 -> ler e adicionar " << endl;
    cout << "----------------------" << endl;
    cout << "2 -> imprimir pessoas " << endl;
    cout << "----------------------" << endl;
    cout << "3 -> ler data e imprimir mais velhos " << endl;
    cout << "----------------------" << endl;

}
int EscolheOpcao(){
    int opcao;
    cout << "Qual opcao deseja? " << endl;
    cin >> opcao;
    return opcao;
}
void LePessoaDeTeclado(Pessoa * p, Data * dia){

    cout << "Informe o nome da pessoa: " << endl;
    cin >> p->nome;
    
    cout << "Informe a altura da pessoa: " << endl;
    cin >> p->altura;
    cout << "Data: " << endl;
    CriaData(*dia);
    cout << dia->mes << " / " << dia->ano << " / " << dia->dia << endl;
}
void AdicionaPessoa(Pessoa povo[10], Pessoa * p, int qtdPessoas, Data * dia){

        strcpy(povo[qtdPessoas].nome, p->nome);
        povo[qtdPessoas].altura = p->altura;
        povo[qtdPessoas].nascimento.mes = dia->mes;
        povo[qtdPessoas].nascimento.ano = dia->ano;
        povo[qtdPessoas].nascimento.dia = dia->dia;
        
    
    
}
void ImprimeTodasAsPessoas(Pessoa povo[10], int qtdPessoas){

    for(int i=1; i<=qtdPessoas; i++){
        cout << povo[i].nome << endl;
        cout << povo[i].altura << endl;
        cout << povo[i].nascimento.mes << " / " << povo[i].nascimento.ano << " / " << povo[i].nascimento.dia << endl;
    }
}
void LeDataDeTeclado(Pessoa povo[10], Data dia, int qtdPessoas){
    int day, mes, ano;

    cout << "Digite o mes: ";
    cin >> mes;
    cout << "Digite o ano: ";
    cin >> ano;
    cout << "Digite o dia: ";
    cin >> day;

    for(int i=1; i<=qtdPessoas; i++){
        if(povo[i].nascimento.ano < ano){
            cout << povo[i].nome << endl;
        }
        if(povo[i].nascimento.mes < mes){
            cout << povo[i].nome << endl;
        }
        if(povo[i].nascimento.dia < day){
            cout << povo[i].nome << endl;
        }

        
    }
}
int main(){

   {
    Pessoa povo[10];
    Pessoa p;
    Pessoa * pont;
    pont = &p;

    int opcao, qtdPessoas = 0 ;
    Data dia;
    Data * pont_data;
    pont_data = &dia;

    ImprimeTelaDeOpcoes();
    do
    {
      opcao = EscolheOpcao();
     if (opcao == 1)
     {
        
        LePessoaDeTeclado(pont, pont_data);
        qtdPessoas++;
        AdicionaPessoa(povo, pont, qtdPessoas, pont_data);
        
     }
     if (opcao == 2){
        ImprimeTodasAsPessoas(povo, qtdPessoas);
     }
     if (opcao == 3){
        LeDataDeTeclado(povo, dia, qtdPessoas);
     }
    } while (opcao != 4);
}
}