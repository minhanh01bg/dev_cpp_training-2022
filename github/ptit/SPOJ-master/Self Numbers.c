#include <stdio.h>
#include <string.h>
int main() {
   char v[1100000];
   int j1, j2, j3, j4, j5, j6, s, n=0;
   int s1, s2, s3, s4, s5;
   memset(v, 0, sizeof(v));
   for (j6=0; j6<10; j6++) {
      for (j5=0; j5<10; j5++) {
         s5 = j6 + j5;
         for (j4=0; j4<10; j4++) {
            s4 = s5 + j4;
            for (j3=0; j3<10; j3++) {
               s3 = s4 + j3;
               for (j2=0; j2<10; j2++) {
                  s2 = s3 + j2;
                  for (j1=0; j1<10; j1++) {
                     v[s2 + j1 + n++] = 1;
                  }
               }
            }
         }
      }
   }
   for (n=1; n<1000000; n++) {
      if (!v[n]) printf("%d\n", n);
   }
   return 0;
}
