#include "Usuario.h"
using namespace std;
Usuario::Usuario(string nickname, string contrasena, string nombre, string email)
    : nickname(nickname), contrasena(contrasena), nombre(nombre), email(email) {}
string Usuario::getNombre(){
    return nombre;
}
string Usuario::getNickname(){
    return nombre;
}
Usuario::~Usuario() {}
