echo "Running tests..."
echo

output=$(out/1.out  < tests/tests-input/input-p6-1.txt)
expected_output="Introduce cuántos enteros vas a almacenar: Introduce el entero 1: Introduce el entero 2: Introduce el entero 3: Introduce el entero 4: Introduce el entero 5: Máximo: 96
Número leído 1: 12
Número leído 2: 96
Número leído 3: 4
Número leído 4: 6
Número leído 5: 32"

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
