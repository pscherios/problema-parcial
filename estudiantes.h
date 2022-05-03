#pragma once
#include "ConexionDB.h"
#include "est.h"
class conest :
    public Aest
{         
public:
    est() {

    }
    est(string car, string nom, string ape, string dir, string tel, string gen, string ema, string fn) : Aest(car,nom,ape,dir,tel,gen,ema,fn) {
    }

    void setCarnet(string car) { carnet = car; }
    void setNombres(string nom) { nombres = nom; }
    void setApellidos(string ape) { apellidos = ape; }
    void setDireccion(string dir) { direccion = dir; }
    void setTelefono(string tel) { telefono = tel; }
    void setGenero(string gen) { genero = gen; }
    void setEmail(string ema) { email = ema; }
    void setFechaNacimiento(string fn) { fecha_nacimiento = fn; }
 
    string getCarnet() { return carnet; }
    string getNombres() { return nombres; }
    string getApellidos() { return apellidos; }
    string getDireccion() { return direccion; }
    string getTelefono() { return telefono; }
    string getGenero() { return genero; }
    string getEmail() { return email; }
    string getFechaNacimiento() { return fecha_nacimiento; }

    void leer() {
        int q_estado;
        ConexionBD cn = ConexionBD();
        MYSQL_ROW fila;
        MYSQL_RES* resultado;
        cn.abrir_conexion();
        if (cn.getConectar()) {
            cout << "------------ Datos de los clientes ------------" << endl;
            string consulta = "select * from proveedores";
            const char* c = consulta.c_str();
            q_estado = mysql_query(cn.getConectar(), c);
            if (!q_estado) {
                resultado = mysql_store_result(cn.getConectar());
                while (fila = mysql_fetch_row(resultado)) {
                    cout << fila[0] << "," << fila[1] << "," << fila[2] << "," << fila[3] << "," << fila[4] << "," << fila[5] << "," << fila[6] << "," << fila[7] << endl;
                }

            }
            else {
                cout << " xxx Error al Consultar  xxx" << endl;
            }

        }
        else {
            cout << "Error al leer" << endl;
            system("pause");
        }
        cn.cerrar_conexion();

    }

    void crear() {
        int q_estado;
        ConexionBD cn = ConexionBD();
        cn.abrir_conexion();
        if (cn.getConectar()) {
            string insert = "INSERT INTO estudiantes(carnet,nombres,apellidos,direccion,telefono,genero,email,fecha_nacimiento)VALUES('" + carnet + "','" + nombres + "','" + apellidos + "','" + direccion + "','" + telefono + "','" + genero + "','" + email + "','" + fecha_nacimiento + "'); ";
            const char* i = insert.c_str();
            q_estado = mysql_query(cn.getConectar(), i);
            if (!q_estado) {
                cout << "Ingreso exitoso" << endl;
            }
            else {
                cout << "Error al ingresar" << endl;
            }

        }
        else {
            cout << "Error al leer" << endl;
            system("pause");
        }
        cn.cerrar_conexion();
    }

    void borrar() {
        int q_estado;
        ConexionBD cn = ConexionBD();
        cn.abrir_conexion();
        if (cn.getConectar()) {
            string insert = "DELETE FROM estudiantes WHERE carnet='" +  + "';";
            const char* i = insert.c_str();
            q_estado = mysql_query(cn.getConectar(), i);
            if (!q_estado) {
                cout << "Se elimino con exito" << endl;
            }
            else {
                cout << "Error al eliminar" << endl;
            }

        }
        else {
            cout << "Error al leer" << endl;
            system("pause");
        }
        cn.cerrar_conexion();

    }

    void actualizar() {
        int q_estado;
        ConexionBD cn = ConexionBD();
        cn.abrir_conexion();
        if (cn.getConectar()) {
            string insert = "UPDATE carnet\
                             SET carnet='" + carnet + "',nombres='" + nombres + "', apellidos = '" + apellidos + "', direccion = '" + direccion + "', telefono = '" + telefono + "', genero = '" + genero + "', email = '" + email + "', fecha_nacimiento = '" + fecha_nacimiento + "'\
            const char* i = insert.c_str();
            q_estado = mysql_query(cn.getConectar(), i);
            if (!q_estado) {
                cout << "Actualizacion exitosa" << endl;
                system("pause");
            }
            else {
                cout << "Error al Actualizar" << endl;
                system("pause");
            }

        }
        else {
            cout << "Error al leer" << endl;
            system("pause");
        }
        cn.cerrar_conexion();
        system("pause");

    }
};

