#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;

struct Empleado {
	char codEmp[9 + 1];
	char nombYApe[50 + 1];
	int cantProdVend = 0;
};

struct Venta {
	char codEmp[9 + 1];
	int codProd;
	int fecha;
	float precioVenta;
};

struct detalleVenta {
	int codProd;
	int fecha;
};

struct NodoPilaProductosVendidos {
	NodoPilaProductosVendidos* sgte;
	detalleVenta info;
};

struct Reporte {
	char codEmp[9 + 1];
	char nombYApe[50 + 1];
	int totalProductosVendidos = 0;
	float totalRecaudado = 0;
	NodoPilaProductosVendidos* raizProdVendidos;
};

void crearEmpleados() {

	FILE* empleados = fopen("Empleados.dat","wb+");

	Empleado vecE[4] = {
		{ "EE", "Juan Gomez", 50 },
		{ "AA", "Pablo Perez", 100 },
		{ "ZZ", "Ariel Gimenez", 10 },
		{ "NN", "Roberto Diaz", 200 }
	};

	fwrite(vecE, sizeof(Empleado), 4, empleados);
	fclose(empleados);
}

void mostrarEmpleados() {
	FILE* empleados = fopen("Empleados.dat","rb+");

	cout << "Codigo Empleado, Nombre y Apellido, Cantidad de productos Vendidos" << endl;
	Empleado e;
	fread(&e, sizeof(Empleado), 1, empleados);

	while (!feof(empleados)) {
		cout << e.codEmp << ", " << e.nombYApe << ", " << e.cantProdVend << endl;
		fread(&e, sizeof(Empleado), 1, empleados);
	}

	cout << endl;
	fclose(empleados);
}

void crearVentas() {

	FILE* ventas = fopen("Ventas.dat","wb+");

	Venta vecV[11] = {
		{ "EE", 1, 20141001, 40.0 },
		{ "ZZ", 5, 20141001, 30.0 },
		{ "EE", 2, 20141002, 15.0 },
		{ "AA", 5, 20141002, 30.0 },
		{ "AA", 5, 20141002, 30.0 },
		{ "EE", 2, 20141002, 15.0 },
		{ "ZZ", 3, 20141004, 70.0 },
		{ "ZZ", 3, 20141010, 70.0 },
		{ "EE", 2, 20141011, 15.0 },
		{ "ZZ", 4, 20141015, 60.0 },
		{ "ZZ", 5, 20141015, 30.0 }
	};

	fwrite(vecV, sizeof(Venta), 11, ventas);
	fclose(ventas);
}

void mostrarVentas() {
	FILE* ventas = fopen("Ventas.dat","rb+");

	cout << "Codigo Empleado, Codigo Producto, Fecha, Precio de Venta" << endl;
	Venta v;
	fread(&v, sizeof(Venta), 1, ventas);

	while (!feof(ventas)) {
		cout << v.codEmp << ", " << v.codProd << ", " << v.fecha << ", " << v.precioVenta << endl;
		fread(&v, sizeof(Venta), 1, ventas);
	}

	cout << endl;
	fclose(ventas);
}

int buscar(Reporte arr[], int len, char* codEmp) {
	int pos = -1;
	int i = 0;
	while(pos == -1 && i <= len - 1) {
		if(strcmp(arr[i].codEmp, codEmp) == 0) {
			pos = i;
		}
		i++;
	}
	return pos;
}

void push (NodoPilaProductosVendidos*& raiz, detalleVenta info) {
	NodoPilaProductosVendidos* pnuevo = new NodoPilaProductosVendidos();
	pnuevo -> info = info;
	pnuevo -> sgte = raiz;
	raiz = pnuevo;
};

bool estaVacia(NodoPilaProductosVendidos*& raiz) {
	raiz == NULL;
}

detalleVenta pop(NodoPilaProductosVendidos*& raiz) {
	NodoPilaProductosVendidos* pAux = raiz;
	detalleVenta info = pAux -> info;
	raiz = pAux -> sgte;
	delete pAux;
	return info;
}

void liberar(NodoPilaProductosVendidos*& raiz){
	while (!estaVacia(raiz)) {
		pop(raiz);
	}
}

void resolucionTp() {
	// TODO completar aquí con la resolución del TP
	// funciones útiles para usar: strcmp y stcpy

	// 	El Reporte debe tener el siguiente orden:
	// -	Los empleados deben estar ordenados por total recaudado descendente
	// -	Los productos vendidos por cada empleado deben estar ordenados por fecha de venta descendente
	// Para resolver el ejercicio deberá utilizar un vector estático para guardar los empleados y pilas dinámicas en cada empleado del vector que contendrán los productos vendidos por cada uno de ellos.
		// EMPLEADOS

		Reporte vecReporte[50];

		FILE * EmpleadosDat = fopen("Empleados.dat", "rb+");
		
		Empleado regEmpleado;

		fread(&regEmpleado, sizeof(Empleado), 1, EmpleadosDat);

		int i = 0;
		int contador = 0;

		while(!feof(EmpleadosDat)) {

			vecReporte[i].totalProductosVendidos = regEmpleado.cantProdVend;
			strcpy(vecReporte[i].codEmp, regEmpleado.codEmp);
			strcpy(vecReporte[i].nombYApe, regEmpleado.nombYApe);

			i++;
			contador++;

			fread(&regEmpleado, sizeof(Empleado), 1, EmpleadosDat);
		}

		fclose(EmpleadosDat);

		// VENTAS

		FILE * VentasDat = fopen("Ventas.dat", "rb+");
		
		Venta regVentas;

		fread(&regVentas, sizeof(Venta), 1, VentasDat);

		detalleVenta infoVenta;

		while(!feof(VentasDat)) {

			int pos = buscar(vecReporte,50,regVentas.codEmp);

			infoVenta.codProd = regVentas.codProd;
			infoVenta.fecha = regVentas.fecha;

			strcpy(vecReporte[pos].codEmp, regVentas.codEmp);
			vecReporte[pos].totalRecaudado += regVentas.precioVenta;
			vecReporte[pos].totalProductosVendidos ++;

			push(vecReporte[pos].raizProdVendidos, infoVenta);

			fread(&regVentas, sizeof(Venta), 1, VentasDat);
		}

		fclose(VentasDat);

		// IMPRESION

		cout << "#################REPORTE#################" << endl;

		for(int i = 0; i <= contador - 1; i++) {

			cout << "Codigo de empleado: " << vecReporte[i].codEmp << endl;
			cout << "Nombre y apellido: " << vecReporte[i].nombYApe << endl;
			cout << "Total de productos vendidos: "<< vecReporte[i].totalProductosVendidos << endl;
			cout << "Total recaudado: $"<< vecReporte[i].totalRecaudado << ".00" << endl;
			cout << "Productos vendidos:"<< endl;
			cout << "________________________________" << endl;
			cout << "| Codigo Producto" << "|" << "Fecha" << "\t \t |" << endl;
			cout << "________________________________" << endl;
			NodoPilaProductosVendidos* pAux = vecReporte[i].raizProdVendidos;
			while(pAux != NULL) {
				cout << "| \t" << pAux->info.codProd << "\t |" << pAux->info.fecha << "\t |" << endl;
				cout << "________________________________" << endl;
				pAux = pAux->sgte;
			}
		}
		
		for(int i = 0; i <= contador - 1; i++) {
			liberar(vecReporte[i].raizProdVendidos);
		}
}

int main() {
	crearEmpleados();
	mostrarEmpleados();
	crearVentas();
	mostrarVentas();

	resolucionTp();

	return 0;
}