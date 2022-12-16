#pragma once
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <iostream>
#include <fstream>
using namespace std;

struct Segment
{
	double p;
	double q;
};

class CUnion
{
private:
	Segment* s; int n;
public:
	CUnion(ifstream& f)
	{
		double d1, d2; int k = 1;
		int n = 0;
		this->s = new Segment[k];
		while (f >> d1 >> d2)
		{
			if (d1 > d2) { cout << "Incorrect data!" << endl; throw - 1; }
			if (n >= k)
			{
				resize(k);
				//cout << "k = " << k << endl;
			}
			s[n].p = d1; s[n].q = d2;
			n++;
			this->n = n;
		}
		this->n = n;
		//cout << "n = " << n << endl;
		for (int i = 0; i < n; i++)
		{
			cout << s[i].p << " " << s[i].q << endl;
		}
		cout << endl;
		//cout<<"Constructor"<<endl;
	}
	CUnion()
	{
		this->n = 0;
		this->s = nullptr;
	}
	CUnion(const CUnion& b)
	{
		n = b.n;
		s = new Segment[n];
		for (int i = 0; i < n; i++)
		{
			s[i].p = b.s[i].p;
			s[i].q = b.s[i].q;
		}
	}
	void CopyOnly(const CUnion& b)
	{
		memcpy(s = new Segment[n = b.n], b.s, b.n * sizeof(Segment));
	}
	CUnion& operator=(const CUnion& b)
	{
		if (this != &b)
		{
			Clean();
			CopyOnly(b);
		}

		return *this;
	}
	~CUnion() { Clean(); /*cout<<"Destructor"<<endl;*/ }
	void Clean() { delete[] s; s = nullptr; n = 0; }
	bool IsEmpty() { return n == 0; }
	int Size() { return n; }
	void qsort(Segment* a, int size);
	void resize(int& k);
	bool OK();
	void glue();
	
	void push_segment(Segment t);
	void collapse();
	void DelSegment(int k);
	int func(Segment x);

	void Print()
	{
		for (int i = 0; i < n; i++)
		{
			cout << s[i].p << " " << s[i].q << endl;
		}
		cout << endl << endl;
	}

};