#include <stdio.h>
#include <stdlib.h>


int _bsearch(int* a, int x, int l, int r){
	if (l + 1 == r){
		if (a[r] > x){
			return r;
		}
		else{
			return -1;
		}
	}
	else{
		int c = l + (r - l) / 2;
		if (a[c] == x){
			if (a[c + 1] > x){
				return c + 1;
			}
			else{
				return _bsearch(a, x, c, r);
			}
		}
		else{
			if (x > a[c]){
				return _bsearch(a, x, c, r);
			}
			else{
				return _bsearch(a, x, l, c);
			}
		}
	}
}

int main(){
	int *a;
	int x,n;
	//MANUAL INPUT
	/*scanf("%d", &x);
	scanf("%d", &n);
	a = (int *) malloc (n);
	int i = 0;
	for (i = 0; i < n; i ++){
        scanf("%d", &a[i]);
	}*/
	//MANUAL INPUT

	//EXAMPLE
	x = 3;
    n = 10;
    a = (int *) malloc (n * sizeof(int));
    a[0] = 1; a[1] = 2; a[2] = 3; a[4] = 3; a[5] = 3; a[6] = 7; a[7] = 8; a[8] = 9; a[9] = 10;
    //EXAMPLE


	int ans = _bsearch(a, x, 0, n);
	if (ans == -1){
		printf ("there is no answer");
	}
	else{
		printf ("%d", ans);
	}
	//system("pause");
	free(&a);

	return 0;
}
