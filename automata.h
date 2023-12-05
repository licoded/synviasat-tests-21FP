/**
 * File:   automata.h
 * Author: Yongkang Li
 *
 * Created on Nov 08, 2023, 21:35 PM
 */

#ifndef AUTOMATA_H
#define AUTOMATA_H

#include "aalta_formula.h"
#include "formula_in_bdd.h"
#include "synthesis.h"
#include <unordered_map>
using namespace std;

namespace automata
{
    typedef aalta::aalta_formula* Edge_af;
    typedef DdNode* State_af;
    typedef unsigned long long ull;

    /**
     * check UNKNOW: `==-1`
     * check WINNING: `==0`
     * check FAILURE: `==1`
     */
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

        Automata(bool sys_first = true) : sys_first_(sys_first) {}

        void print_automata()
        {
            for (auto state_it = state_map_.begin(); state_it != state_map_.end(); ++state_it)
            {
                cout << "- " << "state: " << Syn_Frame::cast_to_af(state_it->first)->to_string() << endl;
                for (auto first_edge_it = state_it->second.begin(); first_edge_it != state_it->second.end(); ++first_edge_it)
                {
                    cout << "\t" << "- " << "first edge: " << first_edge_it->first->to_literal_set_string() << endl;
                    for (auto second_edge_it = first_edge_it->second.begin(); second_edge_it != first_edge_it->second.end(); ++second_edge_it)
                    {
                        cout << "\t\t" << "- " << "second edge: " << second_edge_it->first->to_literal_set_string() << endl;
                        cout << "\t\t\t" << "- " << "state: " << Syn_Frame::cast_to_af(second_edge_it->second)->to_string() << endl;
                    }
                }
            }
        }
    };
}

#endif