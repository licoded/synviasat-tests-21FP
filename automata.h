/**
 * File:   automata.h
 * Author: Yongkang Li
 *
 * Created on Nov 08, 2023, 21:35 PM
 */

#ifndef AUTOMATA_H
#define AUTOMATA_H

#include "formula/aalta_formula.h"
#include "formula_in_bdd.h"
#include <unordered_map>
using namespace std;

namespace automata
{
    typedef aalta::aalta_formula* Edge_af;
    typedef DdNode* State_af;

    enum STATE_STATUS
    {
        UNKNOWN = -1,
        WINNING,
        IS_FAILURE,
    };

    typedef std::unordered_map<Edge_af,State_af> Second_edge_map;
    typedef std::unordered_map<Edge_af,Second_edge_map> First_edge_map;
    typedef First_edge_map AutomataNode;
    typedef std::unordered_map<State_af,AutomataNode> State_map;

    class Automata
    {
    public:
        State_map state_map_;
        bool sys_first_;

        Automata(bool sys_first = true);

        AutomataNode* get_state(State_af state);

        void print_automata();
    };
}

#endif