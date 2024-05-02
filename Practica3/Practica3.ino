#define boton1 2
#define boton2 3
byte contador = 0;

struct expendedora {
  char nombres_del_producto[100];
  long precio_del_producto;
};

expendedora productos[4] = {
  {"cerecitas", 25},
  {"Elotitos", 25},
  {"tortillitas señorial", 25},
  {"tortix", 25}
};

void setup() {
  Serial.begin(9600);
  pinMode(boton1, INPUT);
  pinMode(boton2, INPUT);
}

void producto (int i) {
  Serial.println("Producto seleccionado:");
  Serial.print("Nombre: ");
  Serial.println(productos[i].nombres_del_producto);
  Serial.print("Cantidad: ");
  Serial.println(productos[i].precio_del_producto);
}

void loop() {
  if (digitalRead(boton1) == HIGH) {
    delay(100);  
    contador = (contador + 1) % 4;  

    if (contador == 0) {
      producto(0);
    } else if (contador == 1) {
      producto(1);
    } else if (contador == 2) {
      producto(2);
    } else if (contador == 3) {
      producto(3);
    }
  }

  if (digitalRead(boton2) == HIGH) {
    delay(100);  
    contador = (contador - 1 + 4) % 4;  

    if (contador == 0) {
      producto(0);
    } else if (contador == 1) {
      producto(1);
    } else if (contador == 2) {
      producto(2);
    } else if (contador == 3) {
      producto(3);
    }
  }
}

 