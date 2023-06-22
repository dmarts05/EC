echo "Running tests..."
echo

output=$(out/1.out)
expected_output="Elemento 1: 4
Elemento 2: 7
Elemento 3: 8
Elemento 4: 6
Elemento 5: 4
Elemento 6: 6
Elemento 7: 7
Elemento 8: 3
Elemento 9: 10
Elemento 10: 2
Resultado de la suma: 57"

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
