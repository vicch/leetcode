int minDeletionSize(char ** array, int length) {
  if (length <= 1)
    return 0;

  int del, i, j;

  del = 0;
  
  // Loop through columns, take first char of the column
  for (j = 0; array[0][j] != '\0'; j++) {

    // Loop through rows, first row can be skipped because it's the base value
    for (i = 1; i < length; i++) {

      // If decreaing sequence is found, increment result value and continue to next column
      if (array[i][j] < array[i-1][j]) {
        del += 1;
        break;
      }
    }
  }

  return del;
}
