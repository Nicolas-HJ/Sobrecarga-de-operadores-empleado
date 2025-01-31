#include<iostream>
#include<conio.h>
#include<stdio.h>
using namespace std;
class Empleado
{
private:
    int ClaveEmpleado;
    string Nombre;
    string Domicilio;
    float Sueldo;
    string JefeReporta;
public:
    Empleado(int, string, string, float, string);
    void imprime();
    void CambiaDomicilio(string);
    void CambiaReporta(string);
    void ActualSueldo(float);
    friend ostream& operator<<(ostream& os, const Empleado& p);
    friend istream& operator>>(istream& i,  Empleado& p);
    float operator+(const Empleado& p);
    float operator-(const Empleado& p);
    bool operator==(const Empleado& p) const;
    bool operator!=(const Empleado& p) const;
    bool operator<(const Empleado& e) const;
    bool operator>(const Empleado& e) const;
};


Empleado::Empleado(int _ClaveEmpleado, string _Nombre, string _Domicilio, float _Sueldo, string _JefeReporta)
{
    ClaveEmpleado=_ClaveEmpleado;
    Nombre=_Nombre;
    Domicilio=_Domicilio;
    Sueldo=_Sueldo;
    JefeReporta=_JefeReporta;
}
void Empleado::CambiaDomicilio(string nuevoDomicilio)
{
    Domicilio=nuevoDomicilio;
    cout<<"Cambio de domicilio exitoso"<<endl;
    getch();

}
void Empleado::CambiaReporta(string nuevo_jefe)
{
    JefeReporta=nuevo_jefe;
    cout<<"Cambio completo"<<endl;
    getch();
}
void Empleado::ActualSueldo(float sueldo)
{
    Sueldo=sueldo;
    cout<<"Cambio de sueldo exitoso"<<endl;
    getch();
}


ostream& operator<<(ostream& os, const Empleado& p) //Operador <<
{
    os << "Clave: " << p.ClaveEmpleado << endl;
    os << "Nombre: " << p.Nombre << endl;
    os << "Domicilio: " << p.Domicilio << endl;
    os << "Sueldo: " << p.Sueldo << endl;
    os << "Jefe Reporta: " << p.JefeReporta << endl;
    return os;
}
istream& operator>>(istream& i, Empleado& p)       //Operador >>
{
    cout<<"Introdusca el nuevo domicilio: ";
    i>>p.Domicilio;
    return i;

}
float Empleado::operator+(const Empleado& p)     //Operador + 
{
   return Sueldo + p.Sueldo;
}
float Empleado::operator-(const Empleado& p)     //Operador -
{
    return Sueldo - p.Sueldo;

}
bool Empleado::operator==(const Empleado& p) const //Operador ==
{
    return (ClaveEmpleado == p.ClaveEmpleado &&
            Nombre == p.Nombre &&
            Domicilio == p.Domicilio &&
            Sueldo == p.Sueldo &&
            JefeReporta == p.JefeReporta);
}
bool Empleado::operator!=(const Empleado& p) const //Operadro !=
{
    return (ClaveEmpleado != p.ClaveEmpleado &&
            Nombre != p.Nombre &&
            Domicilio != p.Domicilio &&
            Sueldo != p.Sueldo &&
            JefeReporta != p.JefeReporta);
}
bool Empleado::operator<(const Empleado& e) const {     //Operador <
    return Sueldo < e.Sueldo;
}
bool Empleado::operator>(const Empleado& e) const {     //Operador >
    return Sueldo > e.Sueldo;
}
enum Menu
{
    OPC_CAMBIARDOMICILIO =1,
    OPC_ACTUALSUELDO,
    OPC_IMPRIMIR,
    OPC_CAMBIOREPORTA,
    OPC_SALIR
};
int opc=0, clave=0;
int main()
{
    system("color 70");
    Empleado jefeplanta(1,"Nicolas", "San Mateo #246", 1300, "Junior");
    Empleado jefepersonal(2,"Angel", "San Antonio #316", 1250, "Jaime");

    cout<<jefepersonal+jefeplanta<<endl;
    cout<<jefepersonal-jefeplanta;

    getch();
    do
    {
        fflush(stdin);
        system("cls");
        cout<<"             Seleccione una opccion:"<<endl
        <<OPC_CAMBIARDOMICILIO<<")Cambiar domicilio"<<endl<<OPC_ACTUALSUELDO<<")Actualizar sueldo"<<endl
        <<OPC_IMPRIMIR<<")Imprimir datos"<<endl<<OPC_CAMBIOREPORTA<<")Cambio de jefe"<<endl
        <<OPC_SALIR<<")Salir"<<endl;
        cin>>opc;
        switch(opc)
        {
        case OPC_CAMBIARDOMICILIO:
        {
            string nuevo_domicilio;
            cout<<"Introduzca la clave del empleado: "<<endl;
            cin>>clave;
            cin.ignore();
            if(clave==01)
            {
                cout<<"Clave correcta"<<endl;
                cin>>jefeplanta;
            }
            else if(clave==02)
            {
                cout<<"Clave correcta"<<endl;
                cin>>jefepersonal;
            }
            else
            {
                cout<<"Clave incorrecta "<<endl;
                getch();
            }
            break;
        }
        case OPC_ACTUALSUELDO:
        {
            float nuevo_sueldo;
            cout<<"Introduzca la clave del empleado: "<<endl;
            cin>>clave;
            cin.ignore();
            if(clave==01)
            {
                cout<<"Clave correcta"<<endl<<"Introzuca el nuevo sueldo"<<endl;
                cin>>nuevo_sueldo;
                jefeplanta.ActualSueldo(nuevo_sueldo);
            }
            else if(clave==02)
            {
                cout<<"Clave correcta"<<endl<<"Introduzala nuevo sueldo"<<endl;
                cin>>nuevo_sueldo;
                jefepersonal.ActualSueldo(nuevo_sueldo);
            }
            else
            {
                cout<<"Clave incorrecta"<<endl;
                getch();
            }
            break;
        }
        case OPC_IMPRIMIR:
        {
              cout<<"Introduzca la clave del empleado:"<<endl;
              cin>>clave;
              cin.ignore();
              if(clave==01)
              {
                  cout<<jefeplanta;
                  getch();
              }
              else if(clave==02)
              {
                  cout<<jefepersonal;
                  getch();
              }
              else
              {
                cout<<"Clave incorrecta"<<endl;
                getch();
              }
              break;
        }
        case OPC_CAMBIOREPORTA:
            {
                string nuevo_jefe;
                cout<<"Introduzca la clave del empleado:"<<endl;
                cin>>clave;
                cin.ignore();
                if(clave==01)
                {
                    cout<<"Clave correcta"<<endl<<"Introduzca al nuevo jefe:"<<endl;
                    getline(cin, nuevo_jefe);
                    jefeplanta.CambiaReporta(nuevo_jefe);
                }
                else if(clave==02)
                {
                    cout<<"Clave correcta"<<endl<<"Introduzca al nuevo jefe:"<<endl;
                    getline(cin, nuevo_jefe);
                    jefepersonal.CambiaReporta(nuevo_jefe);
                }
                else
                {
                        cout<<"Clave incorrecta"<<endl;
                        getch();
                }
                break;
            }
        case OPC_SALIR:
            {
                cout<<"Buen Dia"<<endl;
                getch();
                break;
            }
        default:
            {
                cout<<"Opccion no valida"<<endl;
                getch();
            }

        }
    }while(opc!=OPC_SALIR);
    getch();
    return 0;
}
