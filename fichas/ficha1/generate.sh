#!/bin/sh

for((i = 0 ; i <1000000; i++)) do 
  `./bin/ficha1 -i "Enzo $i" $i`
done
