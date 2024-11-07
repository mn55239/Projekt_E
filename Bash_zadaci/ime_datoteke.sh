#!/bin/bash

# Dohvati ime trenutne datoteke
ime_datoteke=$(basename "$0")

# Ukloni ekstenziju .sh iz imena datoteke
ime_bez_ekstenzije="${ime_datoteke%.sh}"

# Obrni ime bez ekstenzije
ime_obrnuto=$(echo "$ime_bez_ekstenzije" | rev)

# Dodaj .txt ekstenziju na obrnuto ime
ime_obrnute_datoteke="${ime_obrnuto}.txt"

# Učitaj sadržaj trenutne datoteke i obrni redoslijed linija koristeći `awk`
awk '{
    linije[NR] = $0
}
END {
    for (i = NR; i > 0; i--) {
        print linije[i]
    }
}' "$ime_datoteke" > "$ime_obrnute_datoteke"

echo "Sadržaj je zapisan u datoteku: $ime_obrnute_datoteke"
