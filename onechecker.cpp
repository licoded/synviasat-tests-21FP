/*
 * File:   onechecker.cpp
 * Author: Yongkang Li
 * Note: one-step move for LTLf synthesis
 * Created on November 23, 2023
 */

#include "onechecker.h"
#include <iostream>

using namespace std;

namespace aalta
{
	bool OneChecker::check (aalta_formula* f)
    {
		if (sat_once (f))
		{
			if (verbose_)
				cout << "sat once is true, return from here\n";
			return true;
		}
		else if (f->is_global ())
		{
			return false;
		}

        Transition* t = get_one_transition_from (f);
        if (t != NULL)
        {
            if (verbose_)
                cout << "getting transition:\n" << t->label ()->to_string() << " -> " << t->next ()->to_string () << endl;
            if (evidence_ != NULL)
                evidence_->push (t->label ());
            return true;
        }

        return false;
    }

	Transition* OneChecker::get_one_transition_from (aalta_formula* f)
	{
		bool ret = solver_->solve_by_assumption (f);
		if (ret)
		{
			Transition* res = solver_->get_transition ();
			return res;
		}
		return NULL;
	}
}