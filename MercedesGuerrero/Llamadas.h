
typedef struct{

    int id_llamada;
    char nombre_cliente[40];
    char email_cliente[60];
    long int dni_cliente;
    char producto[40];
    char observaciones[190];
    int isEmpty;

}eLlamada;

eLlamada* newLlamada();
eLlamada* newLlamadaParametrizada(int _id, char* _nombre, char* _email, long int _dni, char* _producto, char* _observaciones);

int set_id(eLlamada* unaLlamada, int valor);
int set_nombre(eLlamada* unaLlamada, char* _nombre);
int set_email(eLlamada* unaLlamada, char* _email);
int set_dni(eLlamada* unaLlamada, long int valor);
int set_producto(eLlamada* unaLlamada, char* _producto);
int set_isEmpty(eLlamada* unaLlamada, int valor);
int get_id(eLlamada* unaLlamada);
char* get_nombre(eLlamada* unaLlamada);
char* get_email(eLlamada* unaLlamada);
int get_dni(eLlamada* unaLlamada);
char* get_producto(eLlamada* unaLlamada);
char* get_observaciones(eLlamada* unaLlamada);
int get_isEmpty(eLlamada* unaLlamada);

int buscarLlamada(ArrayList* lista, int id);

void mostrar_unaLlamada(eLlamada* unaLlamada);
void mostrarLlamadas(ArrayList* lista);

int getInt(char* mensaje);
int getLong(char* mensaje);

int compararNombre_yDNI(void* x, void* y);
int filtrarPorID_Par(eLlamada* unaLlamada);

int compararID(void* x, void* y);

