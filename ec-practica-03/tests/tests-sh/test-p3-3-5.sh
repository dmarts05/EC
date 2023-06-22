echo "Running tests..."
echo
# Tests -1 mark
output=$(out/3.out  < tests/tests-input/input-p3-2-5.txt)
expected_output="Escribe la nota numérica: Suspenso"

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
