#include <bits/stdc++.h>
#include <string>
using namespace std;

int main(){
    string curso;
    int fase;
    cout << "Digite o curso: ";
    cin >> curso;
    cout << "Qual sua fase: ";
    cin >> fase;
    if(curso=="CC"){
        if(fase==1){
            char val, valtgs='n', valagt='n';
            do{
                cout << "Tentar validação? s/n" << endl;
                cin >> val;
            }while(val!='s' && val!='n');
            if(val=='s'){
                do{
                    cout << "Vai validar AGT? s/n" << endl;
                    cin >> valagt;
                }while(valagt!='s' && valagt!='n');
                do{
                    cout << "Vai validar TGS? s/n" << endl;
                    cin >> valtgs;
                }while(valtgs!='s' && valtgs!='n');
            }
            cout << endl << "Matricula compulsoria em:" << endl << "Primeira fase-----Cred.teo.-----Cred.prat.-----" << endl;
            cout << "AGT0001              02             02" << endl;
            cout << "GAN0001              04" << endl;
            cout << "ICD0001              04" << endl;
            cout << "LMA0001              02             02" << endl;
            cout << "PEN0001              02             02" << endl;
            cout << "TGS0001              02             02" << endl;
            cout << "Total de creditos: 24" << endl << "Total de disciplinas: 6" << endl << "Pedidos de validacao:" << endl;
            if(valtgs=='s'){
            cout << "TGS" << endl;
            }
            if(valagt=='s'){
            cout << "AGT" << endl;
            }
        }else if(fase==2){
            char fzrali, fezgan, fzrcdi, valcdi, fzrecc, fzricd;
            int cred=0, disc=0;
            do{
                cout << "VAi fazer ALI? s/n" << endl;
                cin >> fzrali;
            }while(fzrali!='s' && fzrali!='n');
            do{
                cout << "Já fez GAN? s/n" << endl;
                cin >> fezgan;
            }while(fezgan!='s' && fezgan!='n');
            do{
                cout << "Vai fazer CDI? s/n" << endl;
                cin >> fzrcdi;
            }while(fzrcdi!='s' && fzrcdi!='n');
            do{
                cout << "Já fez ICD? s/n" << endl;
                cin >> fzricd;
            }while(fzricd!='s' && fzricd!='n');
            do{
                cout << "Vai validar CDI? s/n" << endl;
                cin >> valcdi;
            }while(valcdi!='s' && valcdi!='n');
            do{
                cout << "Vai fazer ECC? s/n" << endl;
                cin >> fzrecc;
            }while(fzrecc!='s' && fzrecc!='n');
            cout <<"SEgunda fase-----Cred.teo.-----Cred.prat.-----pre-requisitos-----" << endl;
            cout << "ALI0001             04                           GAN0001" << endl;
            cout << "CDI0001             04                           ICD0001" << endl;
            cout << "ECC0001             02            02" << endl;
            if(fezgan=='s'){
                if(fzrali=='s'){
                    cred+=4;
                    disc+=1;
                }
            }
            if(fzricd=='s'){
                if(fzrcdi=='s'){
                    disc+=1;
                    cred+=4;
                }
            }
            if(fzrecc=='s'){
                cred+=4;
                disc+=1;
            }
            if(disc==0){
                cout << "Sua matricula vai constar como trancada." << endl << "É preciso escolher ao menos uma disciplina." << endl;
                cout << "Total de creditos: 0" << endl << "Total de disciplinas: 0" << endl;
            }else{
                cout << "Total de creditos: " << cred << endl << "Total de disciplinas: " << disc << endl;
            }
        }else{
            cout << "Fase invalida" << endl;
        }
    }else{
        cout << "Curso invalido" << endl;
    }
}