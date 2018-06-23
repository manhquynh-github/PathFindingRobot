#include "Tree.h"
#include "Queue.h"
#include "Board.h"
#include "conio.h"
#include "AI.h"
#include <cstdlib>
#include <ctime>
#include "AIAstar.h"
using namespace std;
void main()
{
	int height, width, wall, ans, loop = 1, same = 0, distance;
	Board B, C;

	while (loop == 1)
	{
		if (same == 0)
		{
			cout << "Height: "; cin >> height;
			cout << "Width: "; cin >> width;

			if (width <= 1 || height <= 1)
			{
				cout << "Invalid map.";
				continue;
			}

			cout << "Walls: "; cin >> wall;
			cout << "Distance: "; cin >> distance;
			cout << "Draw board (1/0)? "; cin >> ans;
			B = Board(height, width, wall, distance);
		}
		else
		{
			B.Clear();
			B.Generate();
		}

		C = B;
		
		if (ans == 1) cout << B << endl << endl;

		AIAStar AA(B);
		clock_t start = clock();
		bool sch = AA.Search();
		clock_t end = clock();
		cout << "Elapsed time A*: " << (clock_t)(end - start) / (double)CLOCKS_PER_SEC << " s" << endl;
		if (ans == 1 && sch == true) cout << B << endl;

		AI A(C);
		start = clock();
		sch = A.Search();
		end = clock();
		cout << "Elapsed time BFS: " << (clock_t)(end - start) / (double)CLOCKS_PER_SEC << " s" << endl;
		if (ans == 1 && sch == true) cout << C << endl;

		cout << endl;	
		cout << "Continue (1/0)? "; cin >> loop;
		if (loop == 1)
		{
			cout << "Same (1/0)? "; cin >> same;
		}
	} while (loop == 1);
}