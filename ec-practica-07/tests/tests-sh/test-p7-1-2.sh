echo "Running tests..."
echo

output=$(out/1.out  < tests/tests-input/input-p7-1-2.txt)
expected_output="Introduce una cadena de caracteres: Longitud de la cadena: 15
Es distinta a la cadena compara
Las cadenas concatenadas son: cadena de textoanadida"

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
