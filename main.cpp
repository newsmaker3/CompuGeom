#include "include.h"

int main()
{
	setlocale(LC_ALL, "rus");
	ifstream f("1.txt");
	CUnion U(f); Segment x; int k;
	int N = 0;
	do
	{
		cout << "Make your choice:" << endl;
		cout << "0. show given lines" << endl;
		cout << "1. Check if the line belongs to the union of given lines" << endl;
		cout << "2. Add line" << endl;
		cout << "3. Delete line" << endl;
		cout << endl << "4. Exit" << endl;
		cin >> N; cout << endl;
		if (N == 0)
		{
			U.Print();
			//cout << U << endl;
		}
		if (N == 1)
		{
			cout << "Enter the line" << endl;
			cin >> x.p >> x.q;
			U.func(x);
			U.Print();
			//cout << U;
		}
		if (N == 2)
		{
			cout << "Enter a new line" << endl;
			cin >> x.p >> x.q; cout << endl;
			U.push_segment(x);
			U.Print();
			//cout << U;
		}
		if (N == 3)
		{
			cout << "Choose the number of the line" << endl;
			cin >> k;
			U.DelSegment(k-1);
			U.Print();
			//cout << U;
		}
	} while (N != 4);

	f.close();

	return 0;
}