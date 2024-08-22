
// 	Reporte* pop(NodoListaReporte*& raiz) {
// 	NodoListaReporte* pAux = raiz;
// 	Reporte info = pAux -> info; 
// 	raiz = pAux -> sgte; 
// 	delete pAux; 
// 	return info;
// }

// NodoListaReporte* insertaOrdenado(NodoListaReporte*& raiz, Reporte info) {
// 	NodoListaReporte* pAux = new NodoListaReporte(); 
// 	pAux -> info = info; 

// 	NodoListaReporte* pAct = raiz;
// 	NodoListaReporte* pAnt = NULL;

// 	while(pAct != NULL && pAct -> info.totalRecaudado > info.totalRecaudado) { 
// 		pAnt = pAct; 
// 		pAct = pAct -> sgte;
// 	}

// 	pAux -> sgte = pAct;

// 	if (pAnt == NULL) { 
// 		raiz = pAux;
// 	} else {
// 		pAnt -> sgte = pAux;
// 	}
// 	return pAux;
// }

// 	void ordenar(NodoListaReporte*& raiz) {
// 	NodoListaReporte* raizAux;
// 	raizAux = NULL

// 	while(raiz != NULL) {
// 		EmpleadoInfo info = pop(raiz); 
// 		insertaOrdenado(raizAux, info); 
// 	}

// 	raiz = raizAux;
// }

// 	

// 	FILE * archEmpleados = fopen("Empleados.dat", "rb+");

// 	Empleado regEmpleado;
// 	fread(&regEmpleado, sizeof(Empleado), 1, archEmpleados);

// 	NodoListaReporte* raiz = NULL;

// 	while(!feof(archEmpleados)) {
// 		NodoListaReporte* pAux = raiz;
// 		Reporte infoR;

// 		infoR.cantProdVend = regEmpleado.cantProdVend;
// 		strcpy(infoR.codEmp, regEmpleado.codEmp);
// 		strcpy(infoR.nombYApe, regEmpleado.nombYApe);

// 		push(raiz, infoR);

// 		fread(&regEmpleado, sizeof(Empleado), 1, archEmpleados);
// 	}

// 	ordenar(raiz);

// 	fclose(archEmpleados);

// 	FILE * archVentas = fopen("Ventas.dat", "rb+");

// 	Venta regVentas;
// 	fread(&regVentas, sizeof(Venta), 1, archVentas);

// 	while(!feof(archVentas)) {
// 		NodoPilaProductosVendidos* ptr = buscar(raiz, regVentas.codEmp);

// 		detalleVenta auxVenta; 

// 		strcpy(ptr -> info.codEmp, regVentas.codEmp);
// 		auxVenta.codProd = regVentas.codProd;
// 		auxVenta.fecha = regVentas.fecha;
// 		ptr -> info.precioVenta += regVentas.precioVenta;
		
// 		push(raiz -> info.raizProdVendidos, auxVenta);

// 		fread(&regVentas, sizeof(Venta), 1, archVentas);
// 	}

// 	fclose(archVentas);

// 	liberar(raiz);
}