echo "Running tests..."
echo

output=$(out/7.out)
expected_output="[4][2][3]
[1][4][1]
[2][3][5]

[2][3][3]
[1][5][4]
[2][1][2]

[16][25][26]
[8][24][21]
[17][26][28]"

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
