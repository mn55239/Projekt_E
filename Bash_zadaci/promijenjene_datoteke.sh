#!/bin/bash

# Provjeri je li argument (broj minuta) proslijeđen
if [ -z "$1" ]; then
    echo "Molim unesite broj minuta kao argument."
    exit 1
fi

# Broj minuta (argument)
minuta="$1"

# Definiraj ispravan direktorij
direktorij="/MacBook/Users/dinkonazor/Downloads/Bash_zadaci"

# Provjeri postoji li direktorij
if [ ! -d "$direktorij" ]; then
    echo "Direktorij $direktorij ne postoji. Molim provjerite put."
    exit 1
fi

# Pronađi sve datoteke promijenjene u zadnjih 'n' minuta i ispiši ih
echo "Datoteke promijenjene u zadnjih $minuta minuta u $direktorij:"
datoteke=$(find "$direktorij" -type f -mmin -"$minuta")

# Provjeri jesu li pronađene datoteke
if [ -z "$datoteke" ]; then
    echo "Nema datoteka promijenjenih u zadnjih $minuta minuta."
    exit 0
fi

# Ispis datoteka
echo "$datoteke"

# Komprimiraj te datoteke u 'backup.tgz'
find "$direktorij" -type f -mmin -"$minuta" -print0 | tar -czvf backup.tgz --null -T -

echo "Datoteke su komprimirane u backup.tgz"
