#!/bin/bash
inicio=10
incremento="$3"
ejecutable="$1"
salida="$2"
fin="$4"

echo "ejecutable: $ejecutable"
echo "salida: $salida"
echo "incremento: $incremento"
echo "fin: $fin"

i=$inicio

while [ $i -lt $fin ]
do
    echo "Ejecutando tam = $i"
    echo `./$ejecutable $i $i $i $i` >> $salida
    ((i+=incremento))
done
