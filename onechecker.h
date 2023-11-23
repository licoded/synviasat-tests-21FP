/*
 * File:   onechecker.h
 * Author: Yongkang Li
 * Note: one-step move for LTLf synthesis
 * Created on November 23, 2023
 */

#ifndef ONE_CHECKER_H
#define ONE_CHECKER_H

#include "formula/aalta_formula.h"
#include "solver.h"
#include "carsolver.h"
#include "evidence.h"

namespace aalta
{

    class OneChecker
    {
    public:
        OneChecker(){};
        OneChecker(aalta_formula *f, bool verbose = false, bool evidence = false)
            : to_check_(f), verbose_(verbose)
        {
            solver_ = new CARSolver(f, verbose);
            if (evidence)
                evidence_ = new Evidence();
            else
                evidence_ = NULL;
        }

        bool check (aalta_formula* f);
        bool sat_once (aalta_formula* f);   //check whether the formula can be satisfied in one step (the terminating condition of checking)
        Transition* get_one_transition_from (aalta_formula* f);
        void push_formula_to_explored (aalta_formula* f)
        {
            solver_->block_formula (f);
        }

    protected:
        // flags
        bool verbose_;      // default is false
        CARSolver *solver_; // SAT solver for computing next states
        aalta_formula *to_check_;
        Evidence *evidence_;
    };

}

#endif