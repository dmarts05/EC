echo "Running tests..."
echo

output=$(out/1.out Hola 2 < tests/tests-input/cadenas-1.txt)
expected_output="Introduce otra cadena de caracteres: Longitud de la cadena introducida por teclado: 4
Las cadenas concatenadas son: HolaCadena añadida
La cadena (HolaCadena añadida) contiene a la cadena pasada como argumento (Hola).
La letra que ocupa la posición especificada es: o"

if [ $? -eq 0 ] ; then
  echo "Pass: Program exited zero"
else
  echo "Fail: Program did not exit zero"
  exit 1
fi

if [ "$output" == "$expected_output" ] ; then
  echo "Pass: Output is correct"
else
  echo "Expected '$expected_output' but got: $output"
  exit 1
fi

echo
echo "All tests passed."

exit 0
