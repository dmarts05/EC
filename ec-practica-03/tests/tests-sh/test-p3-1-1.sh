echo "Running tests..."
echo
# Tests entering a number that it's not 3
output=$(out/1.out  < tests/tests-input/input-p3-1-1.txt)
expected_output="Escribe un número: El número introducido no es el 3
Fin del algoritmo"

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
