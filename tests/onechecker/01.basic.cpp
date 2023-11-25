#include "onechecker.h"
#include "formula/aalta_formula.h"
#include <iostream>

using namespace std;
using namespace aalta;

int main()
{
    string input_f; // = "a U b";
	getline(cin, input_f);

	// rewrite formula
	aalta_formula *af;
	// set tail id to be 1
	af = aalta_formula::TAIL();
	aalta_formula::TRUE();
	aalta_formula::FALSE();
	af = aalta_formula(input_f.c_str(), true).nnf();
	af = af->remove_wnext();
	af = af->simplify();
	af = af->split_next();
	af = af->unique();

    OneChecker checker(af, false, true);
    bool check_res = checker.check(af);
    auto XY_edge = checker.get_model_for_synthesis();
    cout
        << "X:" << "\t" << XY_edge.first->to_string()
        << endl
        << "Y:" << "\t" << XY_edge.second->to_string()
        << endl;

    return 0;
}