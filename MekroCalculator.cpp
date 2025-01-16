#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <cstdlib>
#include <limits>

using namespace std;

double memory = 0;
double result = 0;
vector<char> inp;


bool hndlerr(){
    // cout<<"yoooooooooooooooooooooooo";
    vector <char> tmp;
    bool correct = true,p = false;
    int del = 0;
    tmp = inp;
    for(int i=tmp.size()-1;i>-1;i--){
        if(tmp[i] == '('){
            p = false;
            for(int j=0;j<tmp.size();j++){
                if(tmp[j] == ')'){
                    tmp.erase(tmp.begin()+j);
                    p = true;
                    del++;
                    break;
                }
            }
            if(!p){
            cout<<"Unexpected '(' on charcter '"<<i+1<<"':"<<"\n\t";
            correct = false;
            for(int y = 0;y<inp.size();y++){
                cout<<inp[y];
            }
            cout<<"\n\t";
            for(int x = 0;x<inp.size();x++){
                if(x == i){
                    cout<<'^';
                    break;
                }else{
                    cout<<' ';
                }
            }
            cout<<endl;
            }
        }
    }
        for(int h = tmp.size()-1;h>0;h--){
        if(tmp[h] == ')'){
            correct = false;
            cout<<"Unexpected ')' on charcter '"<<h+del+1<<"':"<<"\n\t";
            for(int y = 0;y<inp.size();y++){
                cout<<inp[y];
            }
            cout<<"\n\t";
            for(int x = 0;x<inp.size();x++){
                if(x == h+del){
                    cout<<'^';
                    break;
                }else{
                    cout<<' ';
                }
            }
            cout<<endl;

    }}

   tmp = inp;
    
    for(int i = 0;i<tmp.size();i++){
        if(tmp[i] == '+' || tmp[i] == '-' || tmp[i] == '*' || tmp[i] == '/' ){
            if(!(((tmp[i-1]<58 && tmp[i-1]>47) || tmp[i-1] == ')' || tmp[i-1] == '(') && ((tmp[i+1]<58 && tmp[i+1]>47) || tmp[i+1] == ')' || tmp[i+1] == '('))){
                correct = false;
                cout<<"There is no number before/afetr '"<<tmp[i]<<"' on charcter '"<<i+1<<"':"<<"\n\t";
                for(int y = 0;y<inp.size();y++){
                    cout<<inp[y];
                }
                cout<<"\n\t";
                for(int x = 0;x<inp.size();x++){
                    if(x == i){
                        cout<<'^';
                        break;
                    }else{
                        cout<<' ';
                    }
                }
                cout<<endl;

            }
        }
    }
}

int main();

void check(){
    string phrase = "",finalphrase = "";
    char ask;
    bool correct = false;
    inp.clear();
    cout << "Pls enter your phrase\n>> ";
    cin.clear();
    // cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin>>ws, phrase);
    for(int i = 0; i<phrase.length();i++){
        if((phrase[i]<58 && phrase[i]>47) || phrase[i] == ')' || phrase[i] == '(' || phrase[i] == '+' || phrase[i] == '-' || phrase[i] == '/' || phrase[i] == '*'){
        inp.push_back(phrase[i]);
        finalphrase += phrase[i];}
    }
    correct = hndlerr();
    if(correct){
        calcilate(finalphrase, result);
        cout<<"Result: '"<<result<<"'\n";
        memory = result;
        cout<<"Do you want to continue?(y/n)\n>> ";
    }else{
        cout<<"Try again\n";
        check();
    }
    while(true){
        cin.clear();
        cin>>ask;
        if(!cin.fail() && (ask == 'y' || ask == 'Y')){
            main();
            break;
        }else if(!cin.fail() && (ask == 'n' || ask == 'N')){
            system("cls");
            cout<<"Have nice time!\n";
            break;
        }else if(cin.fail()){
            cout<<"Wrong input, Try again\n>> ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout<<"Do you want to continue?(y/n)\n>> >> ";
        }else{
            cout<<"Invalid input, Try again\n>> ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

}
}

int main(){
    char ask;
    int num;
    system("cls");
    cout<<"Welcome to Mekro Calculator!\nPls choose a function\n1)Calculate\n2)Save the result\n3)Show history\n4)Clear history\n0)Exit\n>> ";
    while(true){
        cin.clear();
        cin>>num;
        switch(num){
            case 1:
                system("cls");
                check();
                break;
            case 2:
                system("cls");
                cout<<"Result '"<<result<<"' saved!"<<endl;
                cout<<"Do you want to continue?(y/n)\n>> ";
                break;
            case 3:
                system("cls");
                cout<<"Previous calculation: "<<memory<<endl;
                cout<<"Do you want to continue?(y/n)\n>> ";
                break;
            case 4:
                system("cls");
                memory = 0;
                cout<<"History cleared!"<<endl;
                cout<<"Do you want to continue?(y/n)\n>> ";
                break;
            case 0:
                system("cls");
                cout<<"Have nice time!";
                return 0;
            default:
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "invalid input, Try again\n>> " << endl;
        }
        cin.clear();
        cin>>ask;
        if(!cin.fail() && (ask == 'y' || ask == 'Y')){
            main();
            break;
        }else if(!cin.fail() && (ask == 'n' || ask == 'N')){
            system("cls");
            cout<<"Have nice time!\n";
            break;
        }else if(cin.fail()){
            cout<<"Wrong input, Try again\n>> ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout<<"Do you want to continue?(y/n)\n>> >> ";
        }else{
            cout<<"Invalid input, Try again\n>> ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
}
