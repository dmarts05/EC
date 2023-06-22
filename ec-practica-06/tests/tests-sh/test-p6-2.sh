echo "Running tests..."
echo

output=$(out/2.out  < tests/tests-input/input-p6-2.txt)
expected_output="Introduce el número de filas: Introduce el número de columnas: Mínimo: 3
[4][7][8][6]
[4][6][7][3]"

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
