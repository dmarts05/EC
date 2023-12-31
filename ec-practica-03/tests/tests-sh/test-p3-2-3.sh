echo "Running tests..."
echo
# Tests 7 mark
output=$(out/2.out  < tests/tests-input/input-p3-2-3.txt)
expected_output="Escribe la nota numérica: Notable"

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
