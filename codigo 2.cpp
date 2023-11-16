
#include <iostream>

using namespace std;

    {
    int op;//opciones=(op)
    do
    {
//inicio Tarjeta:recarga, saldo.)
        cout<<"\tBienvenido a las Opciones de Tarjeta: ";
        cout<<"\n Seleccione una Función:";
        cout<<"\n1. Crear tarjeta.";
        cout<<"\n2. Recargar.";
        cout<<"\n3. Verificar saldo.";
        cout<<"\n4. Finalizar.";
        cin>>op;
                //Opciones:
                switch (op)
                {
//caso 1-----------------------------------------------------------------------------------------------------------------
                   case 1:
                   {//matriz
                    string cli; //cliente
                    int cnum; //cedula cliente
                    int ntar; //número-identificador de tarjeta
                    cout<<"\nIngresa el primer nombre del titular: ";
                    cin>>cli;
                    cout<<"\nIngrese el Identificador de la tarjeta (0-4 Digitos): ";
                    cin>>ntar;
                    cout<<"\nIngresa el número de cédula del cliente (Maximo 10 Digitos): ";
                    cin>>cnum;
                    cout<<"\nTarjeta creada.";
                   }break;
//caso 2-----------------------------------------------------------------------------------------------------------------
                    case 2:
                    {
                    int recar;
                    int resp;
                    cout<<"Ingrese identificador de tarjeta: ";
                    cin>>recar;
                    cout<<"¿se realizo el pago? ";
                    cout<<"1. Si. ";
                    cout<<"2. No. ";
                    cin>>recar;
                        if (resp==1){
                        cout<<"Tarjeta recargada.";
                        }
                        if (resp==2){
                            cout<<"Por favor realice el pago. ";
                        }
                    }
//caso 3-----------------------------------------------------------------------------------------------------------------
                    case 3:
                    {
                        
                    }
                };
    }while (op != 4); 
    cout<<"Proceso completado.";
}
}
