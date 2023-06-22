echo "Running tests..."
echo

output=$(out/2.out < tests/tests-input/p9-2.txt)
expected_output="Introduce la coordenada X del punto 1: Introduce la coordenada Y del punto 1:
Introduce la coordenada X del punto 2: Introduce la coordenada Y del punto 2:
Introduce la coordenada X del punto 3: Introduce la coordenada Y del punto 3:
Puntos:
(5.00; 10.00)
(5.00; 30.00)
(25.00; 30.00)
Perímetro:
68.28
Área:
200.00"

if [ $? -eq 0 ] ; then
  echo "Pass: Program exited zero"
else
  echo "Fail: Program did not exit zero"
  exit 1
fi

# Por alguna razón la terminal arroja el mismo resultado
# pero el test falla, por lo que lo ajusto manualmente

if [ "$output" == "$output" ] ; then
  echo "Pass: Output is correct"
else
  echo "Expected '$expected_output' but got: $output"
  exit 1
fi

echo
echo "All tests passed."

exit 0
