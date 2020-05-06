#include <iostream>
#include <cmath>
using namespace std;

class Startup{
protected:
    string nama;
    string jenis[3] = {"Unicorn", "Decacorn", "Hectocorn"};
    double batasValuasi[3] = {1000000,10000000,100000000};
    double valuasi, invest, develop, income, pendapatanBersih;

public:
    void setNama(string n){
        nama = n;
    }
    void setValuasi(double v, bool *t){
        if(v<1000000) {
            cout<<"Invalid input...\nSilahkan input lagi...\n\n";
            *t = true;
        }
        else {
            valuasi = v;
            *t = false;
        }
    }
    void setIncome(double i){
        income = i;
    }
    void setPendapatanBersih(){
        pendapatanBersih = income + invest - develop;
    }
    bool isProfit(){
        return pendapatanBersih > 0;
    }
    int jenisStartup(){
        if(valuasi >= 1000000 && valuasi < 10000000) return 0;
        else if(valuasi >= 10000000 && valuasi < 100000000) return 1;
        else return 2;
    }
    void printPendapatanBersih(){
        setPendapatanBersih();
        cout.precision(1);
        cout<<"Income\t\t  : US$ "<<fixed<<income<<endl
            <<"Invest\t\t  : US$ "<<invest<<endl
            <<"\t\t    -------------------- +"<<endl
            <<"\t\t    US$ "<<income+invest<<endl
            <<"Develop\t\t  : US$ "<<develop<<endl
            <<"\t\t    -------------------- -"<<endl
            <<"Pendapatan Bersih : US$ "<<pendapatanBersih;
    }
    void printKeuntungan(){
        cout<<"\n\n=======================================================";
        cout<<"\n\nPrediksi\t  : ";
        if(isProfit()) cout<<"Dapat berkembang";
        else cout<<"Tidak dapat berkembang";
    }
    void printToNextLevel(){
        cout<<"\n\n=======================================================";
        double batas = batasValuasi[jenisStartup()+1] - valuasi;
        cout.precision(1);
        if(isProfit()){
            if(jenisStartup()==2) cout<<"\n\nStartup sudah berada di level tertinggi!!!\n";
            else {
                cout<<"\n\nWaktu yang dibutuhkan untuk mencapai level selanjutnya"<<endl
                    <<jenis[jenisStartup()]<<" -> "<<jenis[jenisStartup()+1]<<
                    " : "<<fixed<<batas/pendapatanBersih<<" tahun\n";
            }
        }
        else {
            cout<<"\n\nWaktu yang dibutuhkan untuk bangkrut : "
                <<fixed<<valuasi/abs(pendapatanBersih)<<" tahun\n";

        }
    }
};

class Unicorn : public Startup{
public:
    void setData(){
        invest = 0.5 * valuasi;
        develop = 0.8 * valuasi;
    }
};

class Decacorn : public Startup{
public:
    void setData(){
        invest = 0.6 * valuasi;
        develop = 0.8 * valuasi;
    }
};

class Hectocorn : public Startup{
public:
    void setData(){
        invest = 0.7 * valuasi;
        develop = 0.8 * valuasi;
    }
};

int main() {
    Startup s;

    Unicorn u;
    Decacorn d;
    Hectocorn h;

    string n;
    bool t = false;
    double v, i;

    menu:
    cout<<"Masukan data dari Startup..."<<endl;

    cout<<"Nama\t: ";
    getline(cin,n);

    input:
    cout<<"Valuasi\t: ";
    cin>>v;
    s.setValuasi(v,&t);
    if (t) goto input;

    cout<<"Income\t: ";
    cin>>i;

    switch (s.jenisStartup()){
        case 0: //Unicorn
            cout<<"\n======================= Unicorn =======================\n\n";
            u.setNama(n);
            u.setValuasi(v,&t);
            u.setIncome(i);
            u.setData();
            u.printPendapatanBersih();
            u.printKeuntungan();
            u.printToNextLevel();
            break;
        case 1:
            cout<<"\n======================= Decacorn =======================\n\n";
            d.setNama(n);
            d.setValuasi(v,&t);
            d.setIncome(i);
            d.setData();
            d.printPendapatanBersih();
            d.printKeuntungan();
            d.printToNextLevel();
            break;
        default:
            cout<<"\n======================= Hectocorn =======================\n\n";
            h.setNama(n);
            h.setValuasi(v,&t);
            h.setIncome(i);
            h.setData();
            h.printPendapatanBersih();
            h.printKeuntungan();
            h.printToNextLevel();
            break;
    }

    char choice;
    cout<<"\n=======================================================\n\n";
    cout<<"Apakah ingin memasukan data lagi? [y/n] : ";
    cin>>choice;
    cin.get();
    if(choice == 'y') {
        system("pause");
        system("cls");
        goto menu;
    }
    else cout<<"\nEXIT...\n";

    return 0;
}
