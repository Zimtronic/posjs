#ifndef ITRANSPORT_H
#define ITRANSPORT_H

   /**
    * @class ITransport
    * @brief Transport interface
    *
    *
    * @author tony
    * @date 17-10-2014
    */

class ITransport
{
public:
    /**
     * @brief Abre la interfaz de comunicacion. El metodo devuelve un codigo
     * de error.
     */
    virtual unsigned open() = 0;

    /**
     * @brief Cierra la interfaz de comunicacion. El metodo devuelve un codigo
     * de error.
     */
    virtual unsigned close() = 0;

    /**
     * @brief Tratan de leer bufferSize bytes de datos de la interfaz en
     * cuestion, el resultado se deposita en buffer. La lectura es sincronica,
     * se espera por el resultado el tiempo en milisegundos que se indique en
     * el parametro timeOut.
     */
    virtual unsigned read(unsigned char* buffer, unsigned &bufferSize,
                          unsigned timeOut) = 0;

    /**
     * @brief Tratan de escribir bufferSize bytes de datos en la interfaz en
     * cuestion. La escritura es sincronica, se espera por el resultado de la
     * operacion el tiempo en milisegundos que se indique en el parametro timeOut.
     * En bufferSize se deposita la cantidad de bytes que realmente fueron escritos.
     */
    virtual unsigned write(unsigned char* buffer, unsigned &bufferSize,
                           unsigned timeOut) = 0;
};

#endif // ITRANSPORT_H
