echo "Running tests..."
echo
# Tests exit option
output=$(out/8.out  < tests/tests-input/input-p3-8-3.txt)
expected_output="Volumen cono (1)
Volumen ortoedro (2)
Salir (3)"

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
