echo "Running tests..."
echo

output=$(out/3.out  < tests/tests-input/input-p6-3.txt)
expected_output="Introduce el número de filas: Introduce el número de columnas: [-9][-6][-1][9]
[-2][0][0][-1]
[5][0][-8][9]

[-9][-2][-8]"

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
