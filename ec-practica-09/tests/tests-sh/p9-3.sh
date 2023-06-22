echo "Running tests..."
echo

output=$(out/3.out alumnos.txt)
expected_output="El alumno con mejor nota media es: Alejandro García Bajo con una media de 8.75"

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
