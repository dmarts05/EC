echo "Running tests..."
echo
# Tests 9 mark
output=$(out/1.out  < tests/tests-input/input-p4-1-4.txt)
expected_output="Escribe la nota numérica: Sobresaliente"

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
