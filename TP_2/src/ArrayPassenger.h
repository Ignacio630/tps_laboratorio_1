#ifndef GENERICO_C_
#define GENERICO_C_

//INCLUDES
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include "utn_funciones.h"
//DEFINES
#define TAM 5
#define TAM_F 5
#define LIBRE 0
#define OCUPADO 1
#define COMERCIAL 0
#define PREMIUN 1
#define EJECUTIVO 2
#define	ACTIVO 0
#define	DEMORADO 1
#define CANCELADO -1
//ESTRUCTURAS
struct{
	int id;
	char name[51];
	char lastName[51];
	float price;
	int typePassenger;
	char flycode[10];
	int statusFlight;
	int isEmpty;
}typedef Passenger;



//FUNCIONES ESTRUCTURAS
/** \brief To indicate that all position in the array are empty,
* this function put the flag (isEmpty) in TRUE in all
* position of the array
* \param list Passenger* Pointer to array of passenger
* \param len int Array length
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*/
int initPassengers(Passenger*, int );
/** \brief add in a existing list of passengers the values received as parameters
* in the first empty position
* \param list passenger*
* \param len int
* \param id int
* \param name[] char
* \param lastName[] char
* \param price float
* \param typePassenger int
* \param flycode[] char
* \return int Return (-1) if Error [Invalid length or NULL pointer or without
free space] - (0) if Ok*/
int addPassenger(Passenger* , int , int , char [], char [], float , int , char[], int);
/** \brief find a Passenger by Id en returns the index position in array.
* \param list Passenger*
* \param len int
* \param id int
* \return Return passenger index position or (-1) if [Invalid length or NULL pointer received or passenger not found]
*/
int findPassengerById(Passenger*, int,int);
/** \brief Remove a Passenger by Id (put isEmpty Flag in 1)
* \param list Passenger*
* \param len int
* \param id int
* \return int Return (-1) if Error [Invalid length or NULL pointer or if can't find a passenger] - (0) if Ok
*/
int removePassenger(Passenger*, int, int);
int modifyPassenger(Passenger*, int, int);
/** \brief Sort the elements in the array of passengers, the argument order indicate UP or DOWN order
* \param list Passenger*
* \param len int
* \param order int [1] indicate UP - [0] indicate DOWN
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*/
int sortPassengers(Passenger* list, int, int);
/// @brief print only one element of passengers array
/// @param list Passenger*
/// @return int return(-1) if Errir [NULL poinater] - (0) if ok
int printPassengers(Passenger* ,int);
/** \brief Sort the elements in the array of passengers, the argument order indicate UP or DOWN order
* \param list Passenger*
* \param len int
* \param order int [1] indicate UP - [0] indicate DOWN
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*/
int sortPassengersByCode(Passenger*, int, int);
/// @brief add 5 existing passengers with all the data need to inform
///
/// @param passenger Passenger*
/// @param list Passenger*
/// @param len int
void AltaForzada(Passenger* , Passenger*, int);


#endif /* GENERICO_C_ */
