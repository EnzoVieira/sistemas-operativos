#!/bin/sh

for((i = 0 ; i <1000; i++)) do 
  echo `./bin/ficha1 -i "Enzo $i" $i`
done
