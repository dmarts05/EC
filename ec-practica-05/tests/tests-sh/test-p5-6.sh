echo "Running tests..."
echo

output=$(out/6.out)
expected_output="[4][7][8][6][4][6]
[7][3][10][2][3][8]
[1][10][4][7][1][7]

[12][20][22][15][8][21]"

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
