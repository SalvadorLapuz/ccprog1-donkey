#include <stdio.h>

// Function that shows the user the position of the donkey and the owner.
int ShowDonkey(int nD1, int nD2, int nD3, int nD4, int nOW)
{
  if (!nD1)
  {
    printf("D1 | ~~~ |\n");
  }
  else
  {
    printf("   | ~~~ | D1\n");
  }

  if (!nD2)
  {
    printf("D2 | ~~~ |\n");
  }
  else
  {
    printf("   | ~~~ | D2\n");
  }
  if (!nD3)
  {
    printf("D3 | ~~~ |\n");
  }
  else
  {
    printf("   | ~~~ | D3\n");
  }
  if (!nD4)
  {
    printf("D4 | ~~~ |\n");
  }
  else
  {
    printf("   | ~~~ | D4\n");
  }

  if (!nOW)
  {
    printf("OW | ~~~ |\n");
  }
  else
  {
    printf("   | ~~~ | OW\n");
  }
}
// check if user entered a valid input or not (donkey and owner must always be in the same position)
int CheckInputVal(int nD1, int nD2, int nD3, int nD4, int nOW, int nPosition)
{
  switch (nPosition)
  {
  case 1:
    return nD1 == nOW;

  case 2:
    return nD2 == nOW;

  case 3:
    return nD3 == nOW;

  case 4:
    return nD4 == nOW;
  case 0:
    return 1;
  default:
    return 0;
  }
  return 0;
}
//  // Adds the Time Elapsed of the donkey with slowest time
void ElapsedTime(int nFirstD, int nSecondD, int *nElapsed, int *nSD1, int *nSD2, int *nSD3, int *nSD4)
{
  if (nFirstD > nSecondD)
  {
    switch (nFirstD)
    {
    case 1:
      *nElapsed += *nSD1;
      break;

    case 2:
      *nElapsed += *nSD2;
      break;

    case 3:
      *nElapsed += *nSD3;
      break;

    case 4:
      *nElapsed += *nSD4;
      break;
    }
  }
  else
  {
    switch (nSecondD)
    {
    case 1:
      *nElapsed += *nSD1;
      break;

    case 2:
      *nElapsed += *nSD2;
      break;

    case 3:
      *nElapsed += *nSD3;
      break;

    case 4:
      *nElapsed += *nSD4;
      break;
    }
  }
}
// Display the Result of the Game if >=14 print "You are too Slow! Do better next time"
void DisplayRes(int *nElapsed)
{
  if (*nElapsed >= 14)
    printf("You are too Slow! Do better next time");

  else
    printf("Quite Fast! You are Quick-witted");
}
// Increases the speed of the selected donkey by +1
int AdjustSpeed(int *nSD1, int *nSD2, int *nSD3, int *nSD4, int nFirstD, int nSecondD)
{
  switch (nFirstD)
  {
  case 1:
    *nSD1 += 1;
    break;

  case 2:
    *nSD2 += 1;
    break;

  case 3:
    *nSD3 += 1;
    break;

  case 4:
    *nSD4 += 1;
    break;
  }
  switch (nSecondD)
  {
  case 1:
    *nSD1 += 1;
    break;

  case 2:
    *nSD2 += 1;
    break;

  case 3:
    *nSD3 += 1;
    break;

  case 4:
    *nSD4 += 1;
    break;
  }
}
// Uses powerups to decrease the speed of the donkey by -2
int UsePowerups(char cSpeedup, int *nSD1, int *nSD2, int *nSD3, int *nSD4, int *nSpeedup, int nFirstD, int nSecondD)
{
  if (cSpeedup != 'y' && cSpeedup != 'Y' && cSpeedup != 'n' && cSpeedup != 'N')
  {
    printf("The input must be either Y or N\n");
  }

  if (cSpeedup != 'Y' && cSpeedup != 'y')
    return 1;

  if (*nSpeedup == 0)
  {
    printf("You have no more speedups!\n");
    return 0;
  }
// Set the default value higher than 2 so the function would not fail if one donkey is selected
  int nFirstSpeed = 1000;
  int nSecondSpeed = 1000;

  switch (nFirstD)
  {
  case 1:
    nFirstSpeed = *nSD1;
    break;
  case 2:
    nFirstSpeed = *nSD2;
    break;
  case 3:
    nFirstSpeed = *nSD3;
    break;
  case 4:
    nFirstSpeed = *nSD4;
    break;
  }
  switch (nSecondD)
  {
  case 1:
    nSecondSpeed = *nSD1;
    break;
  case 2:
    nSecondSpeed = *nSD2;
    break;
  case 3:
    nSecondSpeed = *nSD3;
    break;
  case 4:
    nSecondSpeed = *nSD4;
    break;
  }
  // If the speed is <2 it must not accept the input because we can't display negative speed
  if (nFirstSpeed < 2 || nSecondSpeed < 2)
  {
    printf("Oh no! You're attempting to time travel\n");
    return 0;
  }

  *nSpeedup -= 1;
  switch (nFirstD)
  {
  case 1:
    *nSD1 -= 2;
    break;
  case 2:
    *nSD2 -= 2;
    break;
  case 3:
    *nSD3 -= 2;
    break;
  case 4:
    *nSD4 -= 2;
    break;
  }
  switch (nSecondD)
  {
  case 1:
    *nSD1 -= 2;
    break;
  case 2:
    *nSD2 -= 2;
    break;
  case 3:
    *nSD3 -= 2;
    break;
  case 4:
    *nSD4 -= 2;
    break;
  }
  return 1;
}
// main function for the text-based game
int main()
{
  int nSpeed, nFirstD, nSecondD;
  int nD1 = 0, nSD1 = 1,
      nD2 = 0, nSD2 = 2,
      nD3 = 0, nSD3 = 4,
      nD4 = 0, nSD4 = 6,
      nSpeedup = 2, nElapsed = 0,
      nOW = 0;
  char cSpeedup;

  printf(" D1 | ~~~ |\n D2 | ~~~ |\n D3 | ~~~ |\n D4 | ~~~ |\n OW | ~~~ |\n");

  printf("Speedup: %d\n", nSpeedup);
  printf("Time Elapsed: %d\n", nElapsed);
  printf("Speed: D1=%d D2=%d D3=%d D4=%d\n", nSD1, nSD2, nSD3, nSD4);

  // Loop will end after all the donkeys are transferred on the other side
  while (!(nD1 && nD2 && nD3 && nD4))
  {
    int nCheckVal = 0;

    printf("Select First Donkey: ");
    scanf("%d", &nFirstD);
    printf("Select Second Donkey: ");
    scanf("%d", &nSecondD);
    printf("Use Speedup? [Y if Yes | N if No): ");
    scanf(" %c", &cSpeedup);

    // Condition that checks if the powerups is valid
    if (!UsePowerups(cSpeedup, &nSD1, &nSD2, &nSD3, &nSD4, &nSpeedup, nFirstD, nSecondD))
    {
      nCheckVal = 1;
    }

    // Condition that checks if the first input is valid
    if (!CheckInputVal(nD1, nD2, nD3, nD4, nOW, nFirstD))
    {
      printf("Invalid Selection!\n");
      nCheckVal = 1;
    }

    // Condition that checks if the second input is valid
    if (!CheckInputVal(nD1, nD2, nD3, nD4, nOW, nSecondD))
    {
      printf("Invalid Selection!\n");
      nCheckVal = 1;
    }

    // Condition where atleast one donkey must be chosen
    if (nFirstD == 0 && nSecondD == 0)
    {
      printf("Minumum of 1 donkey must be chosen!\n");
      nCheckVal = 1;
    }
    // Condition where one donkey cannot be repeated at the first and second input.
    if (nFirstD == nSecondD)
    {
      printf("One donkey cannot be repeated, please choose again.\n");
      nCheckVal = 1;
    }
    if (!nCheckVal)
    {
      // Condition wherein if user inputs 0 value no donkey position will change
      if (nFirstD != 0)
        switch (nFirstD)
        {
        case 1:
          nD1 = !nD1;
          break;

        case 2:
          nD2 = !nD2;
          break;

        case 3:
          nD3 = !nD3;
          break;

        case 4:
          nD4 = !nD4;
          break;
        }

      if (nSecondD != 0)
      {
        switch (nSecondD)
        {
        case 1:
          nD1 = !nD1;
          break;

        case 2:
          nD2 = !nD2;
          break;

        case 3:
          nD3 = !nD3;
          break;

        case 4:
          nD4 = !nD4;
          break;
        }
      }
      nOW = !nOW;
      ElapsedTime(nFirstD, nSecondD, &nElapsed, &nSD1, &nSD2, &nSD3, &nSD4);
      AdjustSpeed(&nSD1, &nSD2, &nSD3, &nSD4, nFirstD, nSecondD);
    }
    ShowDonkey(nD1, nD2, nD3, nD4, nOW);
    printf("Speedup: %d\n", nSpeedup);
    printf("Time Elapsed: %d\n", nElapsed);
    printf("Speed: D1=%d D2=%d D3=%d D4=%d\n", nSD1, nSD2, nSD3, nSD4);
  }
  DisplayRes(&nElapsed);
}

/******************************************************************************
This is to certify that this project is my own work, based on my personal
efforts in studying and applying the concepts learned. I haAve constructed
the functions and their respective algorithms and corresponding code by
myself. The program was run, tested, and debugged by my own efforts. I
further certify that I have not copied in part or whole or otherwise
plagiarized the work of other students and/or persons.
Mari Salvador S. Lapuz - 12138061 - S14B
******************************************************************************/
