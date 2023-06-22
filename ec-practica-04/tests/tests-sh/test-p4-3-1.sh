echo "Running tests..."
echo
# Tests 3 as base and 7 as exponent
output=$(out/3.out  < tests/tests-input/input-p4-3-1.txt)
expected_output="Escribe un número (base): Escribe un número (exponente): La potencia es: 2187"

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
