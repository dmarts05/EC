echo "Running tests..."
echo

output=$(out/4.out)
expected_output="[3][12][14][7][4]
[4][15][6][4][10]
[5][6][3][7][15]
[4][12][13][13][14]
[10][11][6][6][6]"

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
