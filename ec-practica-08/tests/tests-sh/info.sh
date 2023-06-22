echo "Running tests..."
echo

output=$(out/2.out < tests/tests-input/info.txt)
expected_output="Introduce la inicial de un alumno: Pablo Llamazares García
Paula Martínez Sánchez

David González Pérez
Javier Sánchez Fernández
Nerea Álvarez Álvarez
Pablo Llamazares García
Paula Martínez Sánchez"

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
