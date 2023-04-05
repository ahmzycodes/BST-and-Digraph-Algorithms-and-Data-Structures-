#include "Task.h"
#include <iostream>
using namespace std;

void main()
{
	cout << "************************************ Splay operation ***********************************\n";
	{
		BST t0;
		t0.Insert(15);
		t0.Insert(10);
		t0.Insert(16);
		t0.MoveToRoot(16);
		cout << "SimpleRR: ";
		t0.printTree();
		cout << endl;
		cout << "Expected: (((10)15)16)" << endl << endl;
	}
	{
		BST t0;
		t0.Insert(15);
		t0.Insert(16);
		t0.Insert(10);
		t0.MoveToRoot(10);
		cout << "SimpleLL: ";
		t0.printTree();
		cout << endl;
		cout << "Expected: (10(15(16)))" << endl << endl;
	}
	{
		BST t0;
		t0.Insert(16);
		t0.Insert(10);
		t0.Insert(15);
		t0.MoveToRoot(15);
		cout << "SimpleRL: ";
		t0.printTree();
		cout << endl;
		cout << "Expected: ((10)15(16))" << endl << endl;
	}
	{
		BST t0;
		t0.Insert(10);
		t0.Insert(16);
		t0.Insert(15);
		t0.MoveToRoot(15);
		cout << "SimpleLR: ";
		t0.printTree();
		cout << endl;
		cout << "Expected: ((10)15(16))" << endl << endl;
	}
	{
		BST t1;
		for (int i = 1; i < 16; i++)
			t1.Insert(i);
		t1.MoveToRoot(15);
		cout << "Test 1:   ";
		t1.printTree();
		cout << endl;
		cout << "Expected: ((1(2(3(4(5(6(7(8(9(10(11(12(13(14))))))))))))))15)" << endl << endl;
		t1.MoveToRoot(8);
		cout << "Test 1A:  ";
		t1.printTree();
		cout << endl;
		cout << "Expected: ((1(2(3(4(5(6(7)))))))8((9(10(11(12(13(14))))))15))" << endl << endl;
		cout << "Test 1B:  ";
		t1.MoveToRoot(1);
		t1.printTree();
		cout << endl;
		cout << "Expected: (1((2(3(4(5(6(7))))))8((9(10(11(12(13(14))))))15)))" << endl << endl;
	}
	{
		BST t2;
		for (int i = 1; i < 16; i++)
			t2.Insert(16 - i);
		cout << "Test 2:   ";
		t2.MoveToRoot(12);
		t2.printTree();
		cout << endl;
		cout << "Expected: ((((((((((((1)2)3)4)5)6)7)8)9)10)11)12(((13)14)15))" << endl << endl;
		cout << "Test 2A:  ";
		t2.MoveToRoot(3);
		t2.printTree();
		cout << endl;
		cout << "Expected: (((1)2)3(((((((((4)5)6)7)8)9)10)11)12(((13)14)15)))" << endl << endl;
		cout << "Test 2B:  ";
		t2.MoveToRoot(11);
		t2.printTree();
		cout << endl;
		cout << "Expected: ((((1)2)3(((((((4)5)6)7)8)9)10))11(12(((13)14)15)))" << endl << endl;
		cout << "Test 2C:  ";
		t2.MoveToRoot(8);
		t2.printTree();
		cout << endl;
		cout << "Expected: ((((1)2)3((((4)5)6)7))8(((9)10)11(12(((13)14)15))))" << endl << endl;
	}
	{
		srand(3);
		BST tr;
		cout << "Test 3:   ";
		for (int i = 1; i < 16; i++)
		{
			int v = 10 + rand() % 90;
			tr.Insert(v);
			if (i > 10)
				tr.MoveToRoot(v);
		}
		tr.printTree();
		cout << endl;
		cout << "Expected: (((((11)19((21(23(28)))34(47)))53(58))62((72)73))78(96(97)))" << endl << endl;
	}
	{
		srand(4);
		BST tr;
		cout << "Test 4:   ";
		for (int i = 1; i < 16; i++)
		{
			int v = 10 + rand() % 90;
			tr.Insert(v);
			if (i > 10)
				tr.MoveToRoot(v);
		}
		tr.printTree();
		cout << endl;
		cout << "Expected: ((27)32(((35)36)40(((45)51)52(61(((64(66))75)79(80(90)))))))" << endl << endl;
	}
	{
		srand(5);
		BST tr;
		cout << "Test 5:   ";
		for (int i = 1; i < 16; i++)
		{
			int v = 10 + rand() % 90;
			tr.Insert(v);
			if (i > 10)
				tr.MoveToRoot(v);
		}
		tr.printTree();
		cout << endl;
		cout << "Expected: ((((19)25)26(((30(32))40)43((64(69(70)))71)))76((83)84(87)))" << endl << endl;
	}
	{
		srand(6);
		BST tr;
		cout << "Test 6:   ";
		for (int i = 1; i < 16; i++)
		{
			int v = 10 + rand() % 90;
			tr.Insert(v);
			if (i > 10)
				tr.MoveToRoot(v);
		}
		tr.printTree();
		cout << endl;
		cout << "Expected: ((((23)25(26))34)38((((42)50(62(66)))68(69((79)86)))95))" << endl << endl;
	}


	cout << "******************************** HasCycle test ********************************" << endl;


	//Digraph g(10);
	//for (int i = 0; i <= 8; i++)
	//	g.AddEdge(i, i + 1);
	//g.AddEdge(9, 0);
	//g.AddEdge(2, 5);
	//g.AddEdge(7, 5);

	//g.DeleteEdge(5, 2);
	//g.DeleteEdge(5, 7);

	//cout << "g.HasCycle 0, 3, 5: " << g.HasCycle(0) << g.HasCycle(3) << g.HasCycle(5) << endl;
	//cout << "expected:           " << true << true << true << endl;

	//Digraph g3(g);
	//g3.DeleteEdge(2, 3);

	//cout << "g3.HasCycle 2, 3, 4: " << g3.HasCycle(2) << g3.HasCycle(3) << g3.HasCycle(4) << endl;
	//cout << "expected:            " << true << false << false << endl;

	//int n = 10000;
	//srand(13);
	//Digraph g4(n);
	//for (int i = n - 2; i >= 0; i--)
	//	g4.AddEdge(n - 1 - (rand() % (n - i - 1)), i);
	//g4.AddEdge(0, n - 1);

	//cout << "g4.HasCycle (n-1), 0, 13: " << g4.HasCycle(n - 1); cout << g4.HasCycle(0); cout << g4.HasCycle(13) << endl;
	//cout << "expected:                 " << true << true << false << endl;

	//for (int i = 1; i < n; i++)
	//	g4.DeleteEdge(i, 0);

	//cout << "g4.HasCycle 0: " << g4.HasCycle(0) << endl;
	//cout << "expected:      " << false << endl;

	system("pause");
}