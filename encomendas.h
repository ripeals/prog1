#ifndef ENCOMENDAS_H_INCLUDED
#define ENCOMENDAS_H_INCLUDED

void menuEncomendas();
void inserirEncomendas (tipoEncomendas encomendas[], int *numEncomendas);
void listarEncomendas (tipoEncomendas encomendas[], int numEncomendas);
<<<<<<< HEAD
void apresentaDadosEncomendas(tipoEncomendas encomenda);
int procuraEncomendas (tipoEncomendas encomendas[], int numEncomendas, int numRegisto);
=======
void apresentaDadosEncomendas(tipoEncomendas encomendas);
int procuraEncomendas (tipoEncomendas encomendas [MAX_ENCOMENDAS], int numEncomendas, int numRegisto);
>>>>>>> 1a4992ea99f5279fc165993584fbef37eaa51030
void consultarEncomendas (tipoEncomendas encomendas [], int numEncomendas);
int eliminarEncomendas (tipoEncomendas encomendas [], int numEncomendas);
#endif // ENCOMENDAS_H_INCLUDED
