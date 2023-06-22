echo "Running tests..."
echo
# Tests output given two numbers, 1 and 10
output=$(out/9.out  < tests/tests-input/input-p3-9-1.txt)
expected_output="Introduce el primer numero: Introduce el segundo numero: 10, 8, 6, 4, 2"

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
