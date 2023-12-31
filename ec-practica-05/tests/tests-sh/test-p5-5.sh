echo "Running tests..."
echo

output=$(out/5.out)
expected_output="[4][7][8][6][4][6]
[7][3][10][2][3][8]
[1][10][4][7][1][7]
[3][7][2][9][8][10]
[3][1][3][4][8][6]
[10][3][3][9][10][8]

Suma: 205"

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
