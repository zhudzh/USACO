/*
	ID: zdzapple
	LANG: C++
	TASK: ratios
*/
include <stdio.h>

/* the goal ratio */
int goal[3];

/* the ratio of the feeds */
int ratios[3][3];

/* the best solution found so far */
int min;
int mloc[4]; /* amounts of ratio 1, 2, and 3, and the amount of ratio 4 prod */

/* the amount of each type of component in the feed */
int sum[3];

int main(int argc, char **argv)
 {
  FILE *fout, *fin;
  int lv, lv2, lv3; /* loop variables */
  int t, s; /* temporary variables */
  int gsum; /* the sum of the amounts of components in the goal mixture */

  if ((fin = fopen("ratios.in", "r")) == NULL)
   {
    perror ("fopen fin");
    exit(1);
   }
  if ((fout = fopen("ratios.out", "w")) == NULL)
   {
    perror ("fopen fout");
    exit(1);
   }

  /* read in data */
  fscanf (fin, "%d %d %d", &goal[0], &goal[1], &goal[2]);
  for (lv = 0; lv < 3; lv++)
    fscanf (fin, "%d %d %d", ratios[lv]+0, ratios[lv]+1, ratios[lv]+2);

  gsum = goal[0] + goal[1] + goal[2];

  min = 301; /* worst than possible = infinity */

  /* boundary case (this ensures gsum != 0) */
  if (gsum == 0)
   {
    fprintf (fout, "0 0 0 0\n");
    return 0;
   }

  for (lv = 0; lv < 100; lv++)
    for (lv2 = 0; lv2 < 100; lv2++)
     { /* for each amout of the first two types of mixtures */
      sum[0] = lv*ratios[0][0] + lv2*ratios[1][0];
      sum[1] = lv*ratios[0][1] + lv2*ratios[1][1];
      sum[2] = lv*ratios[0][2] + lv2*ratios[1][2];

      if (lv + lv2 > min) break;

      for (lv3 = 0; lv3 < 100; lv3++)
       {
        s = lv + lv2 + lv3;
	if (s >= min) break; /* worse than we've found already */

        /* calculate a guess at the multiples of the goal we've obtained */
	/* use gsum so we don't have to worry about divide by zero */
        t = (sum[0] + sum[1] + sum[2]) / gsum;
	if (t != 0 && sum[0] == t*goal[0] && 
	        sum[1] == t*goal[1] && sum[2] == t*goal[2])
	 { /* we've found a better solution! */
	  /* update min */
	  min = s;

	  /* store the solution */
	  mloc[0] = lv;
	  mloc[1] = lv2;
	  mloc[2] = lv3;
	  mloc[3] = t;
	 }

        /* add another 'bucket' of feed #2 */
        sum[0] += ratios[2][0];
        sum[1] += ratios[2][1];
        sum[2] += ratios[2][2];
       }
     }
  if (min == 301) fprintf (fout, "NONE\n"); /* no solution found */
  else fprintf (fout, "%d %d %d %d\n", mloc[0], mloc[1], mloc[2], mloc[3]);
  return 0;
 }
