//Fernando Martinez Macias
#include <iostream>
#include<string>

using namespace std;

int op;//opcion a elegir del
    float s;//para ingresar salario
    string n;//para ingresar nombre
    string a;//para ingresar apellido
    char g;//para ingresar genero

struct persona{//persona
    string name;//nombre
    string app;//apellido
    float salario;//salario
    char genero;//genero

    persona *next;//persona apuntando a siguiente
};

void push(persona *&,persona*&);//funcion agregar a la cola
void pop(persona *&,persona*&);//funcion eliminar
void show(persona *&);//funcion imprimir
bool q_empty(persona *);//funcion cola vacia
//void showiyf(persona *&,persona *&);


int main(){//aqui inicia el programa

persona *frente = NULL;//persona apuntando a frente es igual a vacio.
persona *fin = NULL;//persona apuntando a fin es igual a vacio.


    do{

        cout<<"Hola, bienvenido a esta Cola"<<endl;
        cout<<endl;
        cout<<"\n(1) ingresar a la cola \n(2) salir de la cola \n(3) mostrar cola \n(4) vaciar cola \n(5) mostrar frente y final de la cola \n ";
        cout<<"\n Elija opcion  ?: ",cin>>op;
        cout<<endl;
        system("CLS");
        switch (op){
            case 1:
                system("CLS");

                push(frente,fin);//funcion push para variables temporales
                cout<<endl;
                break;
            case 2:
                system("CLS");
                cout<<endl;
                cout<<"Eliminando ..... : ";
                cout<<endl;
                pop(frente,fin);
                cout<<endl;
                break;
            case 3:
                system("CLS");
                cout<<endl;
                cout<<"Imprimiendo..... : ";
                cout<<endl;
                show(frente);
                cout<<endl;
                break;
            case 4:
                system("CLS");
                cout<<endl;
                cout<<"Eliminando TODO ..... : ";
                cout<<endl;
                    while(frente != NULL){
                        pop(frente,fin);

                        if(frente != NULL){
                            cout<<n<< "  "<<a<<endl;
                        }
                        else{
                            cout<<endl;
                            cout<<n<< "  "<<a<<endl;
                            cout<<endl;
                        }

                    }
                break;
            case 5:
                cout<<endl;
                cout<<"Imprimiendo Frente...... : ";
                cout<<endl;//aqui estoy imprimiendo frente-> a datos de la primera persona
                cout<<frente->name<<endl;
                cout<<frente->app<<endl;
                cout<<frente->salario<<endl;
                cout<<frente->genero<<endl;
                cout<<endl;
                cout<<"Imprimiendo Fin..... : ";
                cout<<endl;//aqui estoy imprimiendo fin-> a datos de la ultima persona
                cout<<fin->name<<endl;
                cout<<fin->app<<endl;
                cout<<fin->salario<<endl;
                cout<<fin->genero<<endl;
                break;
        }
    }while(op!=6);
}


void push(persona *&frente, persona *&fin){
    persona *npersona =  new persona();

    cout<<"Ingrese nombre :  ";
        fflush(stdin);
        getline(cin, n);  //Esto es para que si mete dos palabras distitas no entre en un bucle infinito.

        cout<<"Ingresa Apellido:  ";
        fflush(stdin);
        getline(cin, a);

        cout<<"Ingrese Salario neto :  ",cin>>s;

        cout<<"Ingrese Genero (m=masculino / f=femenino) :  ",cin>>g;


    // n="luis fernando";
    // a="martinez macias";
    // s= "$ 4,958.00";
    // g= "M";
    npersona->name=n;
    npersona->app=a;
    npersona->salario=s;
    npersona->genero=g;

    npersona->next = NULL;

        if(q_empty(frente))
            frente=npersona;//aqui se asignan los valores al frente cuando esta vacio
        else
            fin->next = npersona;
            fin = npersona;
            cout<<endl;
            cout<<"Ahora el fin es  "<<n<<endl;

}

bool q_empty(persona *frente){
    if(frente == NULL)
        return true;
    else
        return false;
}

void pop(persona *&frente, persona *&fin){
    n = frente->name;
    a = frente->app;
    s = frente->salario;
    g = frente->genero;
    persona *aux = frente;

    if(frente == fin){
        frente = NULL;
        fin = NULL;
    }
    else{
        frente = frente->next;
    }
    delete aux;
}

void show(persona *&frente){
    persona *aux = frente;
            while(aux!=NULL){
            cout<<endl;
            cout<<"-> Nombre :"<<aux->name<<endl;
            cout<<"-> Apellido: "<<aux->app<<endl;
            cout<<"-> Salario : "<<aux->salario<<endl;
            cout<<"-> Genero (m=masculino / f=femenino) : "<<aux->genero<<endl;
            cout<<endl;
            cout<<endl;

            aux=aux->next;

        }
        if(aux=NULL){
        cout<<endl;
        cout<<"Nada que imprimir, Stack vacia\n";
        }
}
