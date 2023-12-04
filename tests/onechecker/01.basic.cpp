#include "onechecker.h"
#include "synthesis.h"
#include "formula/aalta_formula.h"
#include <iostream>
#include <sstream>

using namespace std;
using namespace aalta;

int main()
{
    string input_f; // = "a U b";
	getline(cin, input_f);

	string env_vars;
	getline(cin, env_vars);
	unordered_set<string> env_var;
    istringstream iss(env_vars);
    string token;

    while (std::getline(iss, token, ' ')) {
        env_var.insert(token);
    }

	// Printing the elements in the unordered_set
    // for (const auto& element : env_var) {
    //     std::cout << element << std::endl;
    // }

	// rewrite formula
	aalta_formula *af;
	// set tail id to be 1
	af = aalta_formula::TAIL();
	aalta_formula::TRUE();
	aalta_formula::FALSE();
	af = aalta_formula(input_f.c_str(), true).nnf();
	// af = af->remove_wnext();
	af = af->simplify();
	af = af->split_next();
	af = af->unique();

	PartitionAtoms(af, env_var);

    OneChecker checker(af, false, true);
    bool check_res = checker.check(af);
    auto XY_edge = checker.get_model_for_synthesis();
    cout
        << "X:" << "\t" << XY_edge.second->to_string()
        << endl
        << "Y:" << "\t" << XY_edge.first->to_string()
        << endl;

    return 0;
}