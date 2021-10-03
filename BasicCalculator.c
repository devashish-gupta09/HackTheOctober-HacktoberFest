#include <stdio.h>
#include <string.h>

int main()
{

  float x;
  float y;
  char c[100];

  printf("Enter First No.:-");
  scanf("%f", &x);

  printf("Enter Second No.:-");
  scanf("%f", &y);

  printf("Enter Operation:-");

  scanf("%s", &c);

  float s = x + y;
  float d = x - y;
  float p = x * y;
  float q = x / y;

  // float r=fmod(x,y);

  if (strcmp(c, "sum") == 0)
  {

    printf("sum is :- %f", s);
  }
  else if (strcmp(c, "difference") == 0)
  {

    printf("difference is :- %f", d);
  }
  else if (strcmp(c, "product") == 0)
  {

    printf("product is :- %f", p);
  }
  else if (strcmp(c, "quotient") == 0)
  {

    printf("quotient is :- %f", q);
    // printf("Remainder is :- %f",r);
  }

  return 0;
}