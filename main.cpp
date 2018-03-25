#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <Progressao.h>
#include <Geometrica.h>
#include <Aritmetica.h>
#include <windows.h>
#include <conio.h>
#include <locale.h>

using namespace std;

void menuPaPg();
void menuPg();

int main()
{
    //menuPaPg();

    /*
    Dados a5 = 100 e r = 10, calcule o primeiro termo:
    a5=a1+(5–1).r
    100=a1+(5−1)⋅10
    100=a1+40
    100−40=a1
    a1=60
    */

    Aritmetica ar;
    ar.setSequence("100");
    cout << ar.getNthTerm(10, ar.getFirstTerm(), 5) << endl;

}

void menuPaPg(){
    int op;
    do{
        cout << "Seja bem-vindo a calculadora de Pa e Pg" << endl;
        cout << "0 - Sair" << endl;
        cout << "1 - Calcular Pa" << endl;
        cout << "2 - Calcular pg" << endl;
        cin >> op;
        switch(op){
            case 1: system("cls"); break;
            case 2: menuPg(); system("cls"); break;
        }
    }while(op != 0);
}

void menuPg(){
    int op;
    string entrada;
    Geometrica ge;
    int wantedPos, currentPos, qTerms, firstTermPos, lastTerm;
    do{
        system("cls");
        cout << "Seja bem-vindo a calculadora de PG" << endl;
        cout << "Digite os termos que voce possui como no exemplo abaixo: " << endl;
        cout << "2, 6, 18" << endl << endl;
        cin.ignore();
        getline(cin, entrada);
        system("cls");
        ge.setSequence(entrada);
        cout << "" << entrada << endl;
        cout << "O que deseja fazer?" << endl;
        cout << "1 - Descobrir um termo" << endl;
        cout << "2 - Somar todos os termos" << endl;
        cout << "3 - Obter o produto dos termos" << endl;
        cout << "4 - Descobrir a quantidade de termos" << endl;
        cin >> op;
        switch(op){
            case 1:
                cout << "Digite a posicao do termo que deseja encontrar, seguido da posicao do primeiro termo que voce possui" << endl;
                cin >> wantedPos;
                cin >> currentPos;
                cout << "Termo contido na posicao " << wantedPos << ": "<< ge.getNthTerm(wantedPos, currentPos) << endl;
                getch();
                system("cls");
                break;

            case 2:
                cout << "Digite a quantidade de termos, seguido da posicao do primeiro termo que voce possui: " << endl;
                cin >> qTerms >> firstTermPos;
                cout << ge.getCommonDifference() << endl;
                cout << "Resultado da soma: " << ge.getSum(qTerms, firstTermPos) << endl;
                getch();
                system("cls");
                break;

            case 3:
                cout << "Digite a quantidade de termos, seguido da posicao do primeiro termo que voce possui: " << endl;
                cin >> qTerms >> firstTermPos;
                cout << "Produto: " << ge.getProduct(qTerms, firstTermPos) << endl;
                getch();
                system("cls");
                break;

            case 4:
                cout << "Digite o ultimo termo, seguido da posicao do primeiro termo que voce possui: " << endl;
                cin >> lastTerm;
                cin >> firstTermPos;
                cout << "Quantidade de termos: " << ge.getQntTerms(lastTerm, firstTermPos) << endl;
                getch();
                system("cls");
                break;

        }
    }while(op != 0);
}

