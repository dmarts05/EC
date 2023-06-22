echo "Running tests..."
echo
# Tests wrong option
output=$(out/7.out  < tests/tests-input/input-p3-7-3.txt)
expected_output="Volumen cono (1)
Volumen ortoedro (2)
Opcion erronea"

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
