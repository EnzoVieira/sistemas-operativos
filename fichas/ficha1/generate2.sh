#!/bin/bash

for ((i = 1; i <= $1; i++))
do
  IDADE = $(((RANDOM % 100) + 1))
  echo "./ficha1 -i Pessoas${i} $IDADE"

  ./ficha1 -i Pessoa${i} $IDADE
done
