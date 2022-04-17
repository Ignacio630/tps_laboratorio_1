/*
 * biblioteca.h
 *
 *  Created on: 13 abr. 2022
 *      Author: Ignacio javier Medici
 */

#ifndef BIBLIOTECA_H_
#define BIBLIOTECA_H_
#include <stdio_ext.h>
#include <stdlib.h>
#define BTC 4606954.55

/// @fn int PedirEntero(int )
/// @brief Esta funcion permite pedirle un entero al usuario
/// @return enteroIngresado
int PedirEntero(int);
/// @fn int ValidarEntero(int enteroIngresado, int minimo, char* mensajeError)
/// @brief Esta funcion permite validar los enteros que se ingresaron con la funcion PedirEntero
/// @param enteroIngresado = es el entero ingresado por el usuario
/// @param minimo = es lo minimo que se permite ingresar
/// @param mensajeError = este devuelve el mensaje de error por si falla en la validacion
/// @return resultadoEntero
int ValidarEntero(int, int, char*);
/// @fn float PedirFlotante()
/// @brief Esta funcion permite pedirle un flotante al usuario
/// @return flotanteIngresado
float PedirFlotante(float);
/// @fn float ValidarFlotante(float flotanteIngresado, int minimo, char* mensajeError)
/// @brief Esta funcion permite validar los flotantes que se ingresaron con la funcion PedirFlotante
/// @param flotanteIngresado = es el flotante ingresado por el usuario
/// @param minimo = es lo minimo que se permite ingresar
/// @param mensajeError = este devuelve el mensaje de error por si falla en la validacion
/// @return resultadoFlotante
float ValidarFlotante(float, int, char*);
/// @fn int SubMenu()
/// @brief Esta funcion crea y da acceso a un sub menu
/// @return opcion
int SubMenu();
/// @fn float DescuentoDebito(float precioIngresado, int descuento)
/// @brief Esta funcion permite calcular el descuento que se aplica cuando se paga con tarjeta de debito
/// @param precioIngresado = este es el precio ingresado por el usuario
/// @param descuento = este es el descuento que se aplica por la compra
/// @return precioDescuentoAplicado
float DescuentoDebito(float, int);
/// @fn float InteresCredito(float precioIngresado, int interesIngresado)
/// @brief Esta funcion permite calcular el interes que se aplica cuando se paga con tarjeta de credito
/// @param precioIngrsado = este es el precio que ingresa el usuario
/// @param interesIngresado = este es la tasa de interes que se aplica en la compra
/// @return precioInteresAplicado
float InteresCredito(float, int);
/// @fn float CalcularBTC(float precioIngresado, float precioEnBTC)
/// @brief Esta funcion permite calcular el precio en bitcoin de un monto ingresado en pesos argentinos
/// @param precioIngresado = este es el precio ingresado por el usuario
/// @param precioEnBTC = es la cotizacion del bitcoin en pesos argentinos
/// @return resultado del precio en BTC
float CalcularBTC(float, float);
/// @fn float CalcularPrecioUnitario(float precioIngresado, float kmIngresado, char* mensajeError)
/// @brief Esta funcion permite calcular el precio por km del vuelo ingresado
/// @param precioIngresado = este es el precio ingresado por el usuario
/// @param kmIngresado = esta es la cantidad de km que ingreso el usuario para el viaje
/// @param mensajeError = este es el mensaje que va a aparecer por si ocurre un error
/// @return resultado
float CalcularPrecioUnitario(float, float, char*);
/// @fn float DiferenciaPrecios(float precioAerolineas, float precioLatam)
/// @brief Esta funcion perminte calcular la diferencia de precio entre los vuelos de aerolineas y latam
/// @param precioAerolineas = este es el precio del vuelo ingresado por el usuario
/// @param precioLatam = este es el precio del vuelo ingresado por el usuario
/// @return resultado
float DiferenciaPrecios(float , float);
/// @fn void MostrarResultados(char* mensaje, float precioAerolineas, float debito, float credito, float bitcoin, float diferencia, float precioUnitario)
/// @brief Esta funcion permite mostrar los resultados ya calculados
/// @param mensaje = muestra un mensaje que ayuda a ver de que son los precios
/// @param precioAerolineas = muestra el precio de aerolineas o de latam
/// @param debito = muetra el precio final pagando con tarjeta de debito
/// @param credito = muestra el precio final pagando con tarjeta de credito
/// @param bitcoin = muestra el precio final pafando con bitcoin
/// @param diferencia = muestra la difenrencia de precio que hay entre aerolineas y latam
/// @param precioUnitario = muestra el precio a pagar por km de viaje
void MostrarResultados(char*, float, float, float, float, float, float);
/// @fn void MostrarCargaForzada(int kmIngresados, float precioAerolineas, float precioLatam)
/// @brief Esta funcion muestra los resultados con datos puestos por el programador para probrar su funcionamiento
/// @param kmIngresado = esta es la cantidad de km ingresados por el programador
/// @param precioAerolineas = este es el precio de aerolineas ingresado por el programado
/// @param precioLatam = este es el precio de latam ingresado por el programador
void MostrarCargaForzada(int , float , float);


#endif /* BIBLIOTECA_H_ */
