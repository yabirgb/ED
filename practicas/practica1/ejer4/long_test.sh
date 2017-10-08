#!/bin/bash
inicio=100
fin="$4"
incremento="$3"
ejecutable="$1"
salida="$2"

echo "ejecutable: $ejecutable"
echo "salida: $salida"
echo "incremento: $incremento"
echo "fin: $fin"

i=$inicio

while [[ $i -lt $fin ]]
do
    echo "Ejecutando tam = $i"
    echo `./$ejecutable $i $fin` >> $salida
    ((i+=incremento))
done
