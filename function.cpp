#include "include.h"

int CUnion::func(Segment x)
{
	qsort(s, n);
	Print();
	do
	{
		glue();
	} while (OK() != true);
	for (int i = 0; i < n; i++)
	{
		if ((x.p >= s[i].p) && (x.q <= s[i].q)) { cout << "The line belongs to the union!" << endl<<endl; return 1; }
	}
	cout << "The line doesn't belong to the line!" << endl << endl;
	return 0;
}

void CUnion::resize(int &k)
{
	Segment* s1 = new Segment[n];
	for (int i = 0; i < n; i++)
	{
		s1[i] = s[i];
	}
	delete[] s;
	k = k + 1;
	s = new Segment[k];
	for (int i = 0; i < k - 1; i++)
	{
		s[i] = s1[i];
	}
	delete[] s1;
}

void CUnion::qsort(Segment* a, int size)
{
	int i = 0;
	int j = size - 1;

	double mid = a[size / 2].p;

	do
	{
		while (a[i].p < mid)
		{
			i++;
		}

		while (a[j].p > mid)
		{
			j--;
		}

		if (i <= j)
		{
			Segment tmp = a[i];
			a[i] = a[j];
			a[j] = tmp;
			i++;
			j--;
		}
	} while (i <= j);

	if (j > 0)
	{
		qsort(a, j + 1);
	}
	if (i < size)
	{
		qsort(&a[i], size - i);
	}
	//cout << "qsort" << endl;
}

bool CUnion::OK()
{
	for (int i = 0; i < n - 1; i++)
	{
		if (s[i].q > s[i + 1].p)
		{
			return false;
		}
	}
	//cout << "OK" << endl;
	return true;
}

void CUnion::glue ()
{
	for (int i = 0; i < n - 1; i++)
	{
		if ((s[i].q >= s[i + 1].p) && (s[i].q < s[i + 1].q))
		{
			s[i].q = s[i + 1].q;
			for (int j = i + 1; j < n - 1; j++)
			{
				s[j].p = s[j + 1].p;
				s[j].q = s[j + 1].q;
			}
			collapse();
			//n--;
		}
		else if (s[i].q >= s[i + 1].q)
		{
			for (int j = i + 1; j < n - 1; j++)
			{
				s[j].p = s[j + 1].p;
				s[j].q = s[j + 1].q;
			}
			collapse();
			//n--;
		}
	}
	//cout << "glue" << endl;
}

void CUnion::collapse()
{
	//cout << "col beg" << endl;
	//Print();
	CUnion V(*this);
	//cout << "V = " << endl;
	//V.Print();
	Clean();
	this->s = new Segment[this->n = V.n - 1];
	for (int i = 0; i < n; i++)
	{
		s[i] = V.s[i];
	}
	V.Clean();
	//cout << "col end" << endl;
}

void CUnion::push_segment(Segment t)
{
	if (t.p > t.q) { cout << "Incorrect line initialization!" << endl; return; }
	resize(n);
	s[n - 1].p = t.p;
	s[n - 1].q = t.q;
}

void CUnion::DelSegment(int k)
{
	if(IsEmpty()) { cout<<"Can't delete!"<<endl; return; }
	if( (k < 0) || (k > n) ) { cout<<"Can't delete!"<<endl; return; }
	for (int i = k; i < n - 1; i++)
	{
		s[i] = s[i + 1];
	}
	collapse();
}