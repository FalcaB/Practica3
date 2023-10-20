#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void Cifrar();
void Descifrar();
void Metodo1C();
void Metodo2C();
void Metodo1D();
void Metodo2D();
void CifrarM1(char**, int, int);
void CifrarM2(char*, int);
void DescifrarM2(char*, int);
void BinTexto(const char*, char**, int);
pair<char**, int> obtenerGrupos(const char*, int);
void binArch(const char*, char**, int, int);
void TextoBin(const string &, const string &);

int main()
{
    int modo;

    do {
        // Mostrar el menu
        cout << "Menu:" << endl;
        cout << "0. Salir." << endl;
        cout << "1. Cifrar." << endl;
        cout << "2. Descifrar." << endl;
        cout << "Ingrese su opcion (0-2): ";
        cin >> modo;

        // Procesar modo seleccionada
        switch (modo) {
        case 0:
            cout << "Saliendo del programa." << endl;
            break;
        case 1:
            Cifrar();
            break;
        case 2:
            Descifrar();
            break;
        default:
            cout << "Opcion no valida. Por favor, elija una opcion valida." << endl;
            break;
        }
    } while (modo != 0);

    return 0;
}

void Cifrar()
{
    int metodo;

    do {
        // Mostrar el menu
        cout << "Menu:" << endl;
        cout << "0. Salir." << endl;
        cout << "1. Metodo 1." << endl;
        cout << "2. Metodo 2." << endl;
        cout << "Ingrese su opcion (0-2): ";
        cin >> metodo;

        // Procesar modo seleccionada
        switch (metodo) {
        case 0:
            cout << "Saliendo del programa." << endl;
            break;
        case 1:
            Metodo1C();
            break;
        case 2:
            Metodo2C();
            break;
        default:
            cout << "Opcion no valida. Por favor, elija una opcion valida." << endl;
            break;
        }
    } while (metodo != 0);

}

void Descifrar()
{
    int metodo;

    do {
        // Mostrar el menu
        cout << "Menu:" << endl;
        cout << "0. Salir." << endl;
        cout << "1. Metodo 1." << endl;
        cout << "2. Metodo 2." << endl;
        cout << "Ingrese su opcion (0-2): ";
        cin >> metodo;

        // Procesar modo seleccionada
        switch (metodo) {
        case 0:
            cout << "Saliendo del programa." << endl;
            break;
        case 1:
            Metodo1D();
            break;
        case 2:
            Metodo2D();
            break;
        default:
            cout << "Opcion no valida. Por favor, elija una opcion valida." << endl;
            break;
        }
    } while (metodo != 0);

}

void Metodo1C()
{
    string inArch, outArch;

    while (true) {
        cout << "Por favor, ingrese el nombre del archivo para lectura: ";
        cin >> inArch;

        ifstream archivo(inArch); // Abre el archivo para lectura

        if (!archivo) {
            cerr << "No se pudo abrir el archivo." << endl;
        } else {
            // El archivo se abrió con éxito, podemos salir del bucle
            archivo.close();
            break;
        }
    }

    while (true) {
        cout << "Por favor, ingrese el nombre del archivo para escritura: ";
        cin >> outArch;

        ofstream archivo(outArch); // Abre el archivo para escritura

        if (!archivo) {
            cerr << "No se pudo abrir el archivo." << endl;
        } else {
            // El archivo se abrió con éxito, podemos salir del bucle
            archivo.close();
            break;
        }
    }

    TextoBin(inArch, "output.txt");

    int semilla;
    cout << "Ingrese la Semilla de codificacion: ";
    cin >> semilla;

    pair<char**, int> resultado = obtenerGrupos("output.txt", semilla);
    char** grupos = resultado.first;
    int cantidadGrupos = resultado.second;

    if (grupos != nullptr) {
        // Aplicar la codificación según las reglas
        CifrarM1(grupos, cantidadGrupos, semilla);

        // Escribir los grupos codificados en un archivo
        binArch(outArch.c_str(), grupos, cantidadGrupos, semilla);

        // Liberar la memoria
        for (int i = 0; i < cantidadGrupos; i++) {
            delete[] grupos[i];
        }
        delete[] grupos;
        
        cout << "Texto convertido a binario y guardado en '" << outArch << "'." << endl;
    }
}

void Metodo2C()
{
    string inArch, outArch;

    while (true) {
        cout << "Por favor, ingrese el nombre del archivo para lectura: ";
        cin >> inArch;

        ifstream archivo(inArch); // Abre el archivo para lectura

        if (!archivo) {
            cerr << "No se pudo abrir el archivo." << endl;
        } else {
            // El archivo se abrió con éxito, podemos salir del bucle
            archivo.close();
            break;
        }
    }

    while (true) {
        cout << "Por favor, ingrese el nombre del archivo para escritura: ";
        cin >> outArch;

        ofstream archivo(outArch); // Abre el archivo para escritura

        if (!archivo) {
            cerr << "No se pudo abrir el archivo." << endl;
        } else {
            // El archivo se abrió con éxito, podemos salir del bucle
            archivo.close();
            break;
        }
    }

    TextoBin(inArch, "output.txt");

    int semilla;
    cout << "Ingrese la Semilla de codificacion: ";
    cin >> semilla;

    pair<char**, int> resultado = obtenerGrupos("output.txt", semilla);
    char** grupos = resultado.first;
    int cantidadGrupos = resultado.second;

    if (grupos != nullptr) {
        // Mover cada dígito de cada grupo una posición a la derecha
        for (int i = 0; i < cantidadGrupos; i++) {
            CifrarM2(grupos[i], semilla);
        }

        // Escribir los grupos en un archivo
        binArch(outArch.c_str(), grupos, cantidadGrupos, semilla);

        // Liberar la memoria
        for (int i = 0; i < cantidadGrupos; i++) {
            delete[] grupos[i];
        }
        delete[] grupos;
        
        cout << "Texto convertido a binario y guardado en '" << outArch << "'." << endl;
    }

}

void Metodo1D()
{
    string inArch, outArch;

    while (true) {
        cout << "Por favor, ingrese el nombre del archivo para lectura: ";
        cin >> inArch;

        ifstream archivo(inArch); // Abre el archivo para lectura

        if (!archivo) {
            cerr << "No se pudo abrir el archivo." << endl;
        } else {
            // El archivo se abrió con éxito, podemos salir del bucle
            archivo.close();
            break;
        }
    }

    while (true) {
        cout << "Por favor, ingrese el nombre del archivo para escritura: ";
        cin >> outArch;

        ofstream archivo(outArch); // Abre el archivo para lectura

        if (!archivo) {
            cerr << "No se pudo abrir el archivo." << endl;
        } else {
            // El archivo se abrió con éxito, podemos salir del bucle
            archivo.close();
            break;
        }
    }

    int semilla;
    cout << "Ingrese la Semilla de codificacion: ";
    cin >> semilla;

    pair<char**, int> resultado = obtenerGrupos(inArch.c_str(), semilla);
    char** grupos = resultado.first;
    int cantidadGrupos = resultado.second;

    if (grupos != nullptr) {
        // Aplicar la codificación según las reglas
        CifrarM1(grupos, cantidadGrupos, semilla);

        // Escribir los grupos decodificados en un archivo
        binArch("output.txt", grupos, cantidadGrupos, semilla);

        // Liberar la memoria
        for (int i = 0; i < cantidadGrupos; i++) {
            delete[] grupos[i];
        }
        delete[] grupos;
    }

    int s = 8;

    pair<char**, int> r = obtenerGrupos("output.txt", s);
    char** g = r.first;
    int cG = r.second;

    if (g != nullptr) {
        BinTexto(outArch.c_str(), g, cG);

        // Liberar la memoria
        for (int i = 0; i < cG; i++) {
            delete[] g[i];
        }
        delete[] g;
        
        cout << "Binario convertido a texto y guardado en '" << outArch << "'." << endl;
    }
}

void Metodo2D()
{
    string inArch, outArch;

    while (true) {
        cout << "Por favor, ingrese el nombre del archivo para lectura: ";
        cin >> inArch;

        ifstream archivo(inArch); // Abre el archivo para lectura

        if (!archivo) {
            cerr << "No se pudo abrir el archivo." << endl;
        } else {
            // El archivo se abrió con éxito, podemos salir del bucle
            archivo.close();
            break;
        }
    }

    while (true) {
        cout << "Por favor, ingrese el nombre del archivo para escritura: ";
        cin >> outArch;

        ofstream archivo(outArch); // Abre el archivo para escritura

        if (!archivo) {
            cerr << "No se pudo abrir el archivo." << endl;
        } else {
            // El archivo se abrió con éxito, podemos salir del bucle
            archivo.close();
            break;
        }
    }

    int semilla;
    cout << "Ingrese la Semilla de codificacion: ";
    cin >> semilla;

    pair<char**, int> resultado = obtenerGrupos(inArch.c_str(), semilla);
    char** grupos = resultado.first;
    int cantidadGrupos = resultado.second;

    if (grupos != nullptr) {
        // Mover cada dígito de cada grupo una posición a la izquierda
        for (int i = 0; i < cantidadGrupos; i++) {
            DescifrarM2(grupos[i], semilla);
        }

        binArch("output.txt", grupos, cantidadGrupos, semilla);

        // Liberar la memoria
        for (int i = 0; i < cantidadGrupos; i++) {
            delete[] grupos[i];
        }
        delete[] grupos;
    }

    int s = 8;

    pair<char**, int> r = obtenerGrupos("output.txt", s);
    char** g = r.first;
    int cG = r.second;

    if (g != nullptr) {
        BinTexto(outArch.c_str(), g, cG);

        // Liberar la memoria
        for (int i = 0; i < cG; i++) {
            delete[] g[i];
        }
        delete[] g;
        cout << "Binario convertido a texto y guardado en '" << outArch << "'." << endl;
    }
}

pair<char**, int> obtenerGrupos(const char* nombreArchivo, int semilla)
{
    ifstream archivo(nombreArchivo);
    if (!archivo.is_open()) {
        cerr << "Error al abrir el archivo." << endl;
        return pair<char**, int>(nullptr, 0);
    }

    char bit;
    int contador = 0;
    int cantidadGrupos = 0;
    int Actual = 0;
    int tamanoGrupo = 0;

    // Contar la cantidad de grupos
    while (archivo.get(bit)) {
        if (bit == '0' || bit == '1') {
            contador++;
            tamanoGrupo++;
            if (contador == semilla) {
                cantidadGrupos++;
                contador = 0;
            }
        }
    }

    // Si quedan bits sin formar un grupo completo, agregar un grupo adicional
    if (tamanoGrupo % semilla != 0) {
        cantidadGrupos++;
    }

    // Volver al inicio del archivo para leer los grupos
    archivo.clear();
    archivo.seekg(0, ios::beg);

    char** grupos = new char*[cantidadGrupos];
    for (int i = 0; i < cantidadGrupos; i++) {
        grupos[i] = new char[semilla];
    }

    contador = 0;

    // Leer los grupos y almacenarlos en el arreglo bidimensional
    while (archivo.get(bit)) {
        if (bit == '0' || bit == '1') {
            grupos[Actual][contador++] = bit;
            if (contador == semilla) {
                Actual++;
                contador = 0;
            }
        }
    }

    archivo.close();
    return pair<char**, int>(grupos, cantidadGrupos);
}

void CifrarM1(char** grupos, int cantidadGrupos, int semilla)
{
    // Crear un arreglo de grupos cifrados
    char** gruposCifrados = new char*[cantidadGrupos];

    for (int i = 0; i < cantidadGrupos; i++) {
        gruposCifrados[i] = new char[semilla];
    }

    // Iterar sobre los grupos originales y aplicar las reglas
    for (int i = 0; i < cantidadGrupos; i++) {
        // Primera iteración: Cambiar 1s por 0s y viceversa
        if (i == 0) {
            for (int j = 0; j < semilla; j++) {
                gruposCifrados[i][j] = (grupos[i][j] == '0') ? '1' : '0';
            }
        } else {
            // Contar la cantidad de 1s y 0s en el grupo anterior
            int unosAnterior = 0;
            int cerosAnterior = 0;

            for (int j = 0; j < semilla; j++) {
                if (grupos[i - 1][j] == '0') {
                    cerosAnterior++;
                } else {
                    unosAnterior++;
                }
            }

            // Aplicar las reglas basadas en la cantidad de 1s y 0s del grupo anterior
            if (unosAnterior == cerosAnterior) {
                // Igual cantidad de 1s y 0s, invertir cada bit del grupo
                for (int j = 0; j < semilla; j++) {
                    gruposCifrados[i][j] = (grupos[i][j] == '0') ? '1' : '0';
                }
            } else if (cerosAnterior > unosAnterior) {
                // Mayor cantidad de 0s, invertir cada 2 bits
                for (int j = 0; j < semilla; j++) {
                    if (j % 2 == 0) {
                        gruposCifrados[i][j] = (grupos[i][j] == '0') ? '1' : '0';
                    } else {
                        gruposCifrados[i][j] = grupos[i][j];
                    }
                }
            } else {
                // Mayor cantidad de 1s, invertir cada 3 bits
                for (int j = 0; j < semilla; j++) {
                    if (j % 3 == 0) {
                        gruposCifrados[i][j] = (grupos[i][j] == '0') ? '1' : '0';
                    } else {
                        gruposCifrados[i][j] = grupos[i][j];
                    }
                }
            }
        }
    }

    // Escribir los grupos cifrados en un archivo
    ofstream outArch("output.txt");
    if (!outArch.is_open()) {
        cerr << "Error al abrir el archivo de salida." << endl;
        for (int i = 0; i < cantidadGrupos; i++) {
            delete[] gruposCifrados[i];
        }
        delete[] gruposCifrados;
        return;
    }

    for (int i = 0; i < cantidadGrupos; i++) {
        for (int j = 0; j < semilla; j++) {
            outArch << gruposCifrados[i][j];
        }
    }

    // Liberar la memoria
    for (int i = 0; i < cantidadGrupos; i++) {
        delete[] gruposCifrados[i];
    }
    delete[] gruposCifrados;
}


void CifrarM2(char* grupo, int semilla)
{
    char temp = grupo[semilla - 1]; // Guardar el último dígito

    for (int i = semilla - 1; i > 0; i--) {
        grupo[i] = grupo[i - 1]; // Mover los dígitos a la derecha
    }

    grupo[0] = temp; // Colocar el último dígito en la primera posición
}

void DescifrarM2(char* grupo, int semilla)
{
    char temp = grupo[0]; // Guardar el primer dígito

    for (int i = 0; i < semilla - 1; i++) {
        grupo[i] = grupo[i + 1]; // Mover los dígitos a la izquierda
    }

    grupo[semilla - 1] = temp; // Colocar el primer dígito en la última posición
}

void binArch(const char* nombreArchivo, char** grupos, int cantidadGrupos, int semilla)
{
    ofstream outArch(nombreArchivo);
    if (!outArch.is_open()) {
        cerr << "Error al abrir el archivo de salida." << endl;
        return;
    }

    for (int i = 0; i < cantidadGrupos; i++) {
        for (int j = 0; j < semilla; j++) {
            outArch << grupos[i][j];
        }
    }

    outArch.close();
    
}

void TextoBin(const string &inArch, const string &outArch)
{
    // Abrir un archivo de entrada para leer el texto
    ifstream rFile(inArch);

    if (!rFile) {
        cerr << "No se pudo abrir el archivo de entrada." << endl;
        return;
    }

    // Leer el contenido del archivo en una cadena
    string texto;
    string linea;

    while (getline(rFile, linea)) {
        texto += linea;
        if (!rFile.eof()) {
            texto += '\n'; // Agregar un salto de línea al final de cada línea, excepto la última
        }

    }

    // Cerrar el archivo de entrada
    rFile.close();

    // Abrir un archivo de salida para escribir la representación binaria
    ofstream wFile(outArch);

    if (!wFile) {
        cerr << "No se pudo abrir el archivo de salida." << endl;
        return;
    }

    // Convertir la cadena de caracteres en su representación binaria y guardarla en el archivo de salida
    for (char c : texto) {
        for (int i = 7; i >= 0; i--) {
            wFile << ((c & (1 << i)) ? '1' : '0');
        }
    }

    // Cerrar el archivo de salida
    wFile.close();
}

void BinTexto(const char* nombreArchivo, char** grupos, int cantidadGrupos)
{
    ofstream outArch(nombreArchivo);
    if (!outArch.is_open()) {
        cerr << "Error al abrir el archivo de salida." << endl;
        return;
    }

    for (int i = 0; i < cantidadGrupos; i++) {
        char caracter = 0;

        // Convertir el grupo de 8 bits en un carácter ASCII
        for (int j = 0; j < 8; j++) {
            if (grupos[i][j] == '1') {
                caracter |= (1 << (7 - j));
            }
        }

        // Escribir el carácter en el archivo
        outArch.put(caracter);
    }

    outArch.close();
}
