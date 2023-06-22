echo "Running tests..."
echo

output=$(out/4.out triangulos.txt)
expected_output="Puntos del triángulo con mayor perímetro:
(0.00, 0.00, 0.00) (3.00, 0.00, 0.00) (10.00, 15.00, 0.00)
Puntos del triángulo con mayor área:
(0.00, 0.00, 0.00) (3.00, 0.00, 0.00) (10.00, 15.00, 0.00)"

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
