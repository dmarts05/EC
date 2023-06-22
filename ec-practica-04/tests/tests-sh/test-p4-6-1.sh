echo "Running tests..."
echo
# Tests 7 as input
output=$(out/6.out  < tests/tests-input/input-p4-6-1.txt)
expected_output="Introduce un numero: El resultado es: 5040"

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
