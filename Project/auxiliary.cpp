/**********************************************************/
/*                       AUXILIARY.CPP                    */
/**********************************************************/

#include "auxiliary.h"

double ** readfile() {
  cout << "Reading file data" << endl;
  double ** data;
  data = (double **) my_malloc((NOINPUTS + NOOUTPUTS) * sizeof(double *)); // rows
  for (int i = 0; i < (NOINPUTS + NOOUTPUTS); i++) {
    data[i] = (double *) my_malloc(TRAININGSIZE*sizeof(double)); // columns
  }

  string line;
  ifstream myfile ("C:/Users/Michael/Documents/ece720/Project/test/trainingdata.txt");
  if (myfile.is_open())
  {
      /* Inputs separated by columns (ie input 1 in data[0], 2 in data[1]) */
      for (int j = 0; j < TRAININGSIZE; j++) {
        for (int i = 0; i < (NOINPUTS + 1); i++) { // rows
          getline(myfile, line);
          data[i][j] = stod(line);
          // cout << "line: " << data[i][j] << endl;
          // cout << "Input [i][j] [" << i << "][" << j << "]" << endl;
        }
      }
      return data;
    myfile.close();
  }
  else cout << "Unable to open file";
  return 0;
}
