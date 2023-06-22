echo "Running tests..."
echo
# Tests cuboid with side1 = 10, side2 = 20 and height = 50
output=$(out/8.out  < tests/tests-input/input-p3-8-2.txt)
expected_output="Volumen cono (1)
Volumen ortoedro (2)
Salir (3)
Introduce el valor del lado 1 del ortoedro: Introduce el valor del lado 2 del ortoedro: Introduce el valor de la altura del ortoedro: Resultado: 10000.00
Volumen cono (1)
Volumen ortoedro (2)
Salir (3)"

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
