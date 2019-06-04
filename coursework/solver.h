#pragma once
#include "head.h"


// Система линейных алгебраических уравнений
class SOLVER {

public:
	void initSLAE();
	void BiCG();


	void getVectX(vector1D &x) { x = b; };
	void generateVectX(int size);
	void writeXToFile(const char *fileName);
	void writeXToStream(std::ofstream& fout);
	void writeFToFile(const char *fileName);


	int getDimention() { return n; }
	void decomposionD();
	void decomposionLUsq();
	vector1D execDirectTraversal(const vector1D &_F);
	vector1D execReverseTraversal(const vector1D &_y);

	pair<int, double> LOS();
	pair<int, double> LOSfactD();
	pair<int, double> LOSfactLUsq();
	void clearAll();
	void setMaxiter(int new_maxiter) { maxiter = new_maxiter; }
	void setE(double new_E) { E = new_E; }

protected:
	vector1D q, q1, q2, q3;
	vector1D di, al, au, di_f, al_f, au_f;
	vector <int> ia, ja;
	int n, maxiter;
	double E, delta;
	vector1D x, r, z, p, b, b1, b2, b3, bTmp;


	vector1D multA(const vector1D&x);
	vector1D multD(const vector1D&x);
	double calcRelativeDiscrepancy();
	double calcNormE(const vector1D &x) { return sqrt(x*x); }


	vector1D xPrev, xPrevPrev;	// решение на k-1 итерации

	vector1D s;	// вспомогательный вектор
	double alpha, beta;


	void generateInitialGuess();
	vector1D multAOn(const vector1D &v);
	vector1D multAtOn(const vector1D &v);
	bool doStop(int i);
};