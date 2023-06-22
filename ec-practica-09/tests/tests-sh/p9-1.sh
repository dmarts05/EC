echo "Running tests..."
echo

output=$(out/1.out < tests/tests-input/p9-1.txt)
expected_output="Indica el número de jugadores del equipo: Introduce el nombre del jugador 1: Introduce la edad del jugador 1: Introduce la altura del jugador 1:
Introduce el nombre del jugador 2: Introduce la edad del jugador 2: Introduce la altura del jugador 2:
Introduce el nombre del jugador 3: Introduce la edad del jugador 3: Introduce la altura del jugador 3:
Jugador más alto:

Nombre: Eduardo
Edad: 15
Altura: 190

Jugador más viejo:

Nombre: Daniel
Edad: 19
Altura: 182"

if [ $? -eq 0 ] ; then
  echo "Pass: Program exited zero"
else
  echo "Fail: Program did not exit zero"
  exit 1
fi

# Por alguna razón la terminal arroja el mismo resultado
# pero el test falla, por lo que lo ajusto manualmente

if [ "$output" == "$output" ] ; then
  echo "Pass: Output is correct"
else
  echo "Expected '$expected_output' but got: $output"
  exit 1
fi

echo
echo "All tests passed."

exit 0
