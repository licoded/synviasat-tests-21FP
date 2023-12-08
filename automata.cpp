#include "automata.h"
#include "synthesis.h"

namespace automata
{
    Automata::Automata(bool sys_first)
        : sys_first_(sys_first) {}

    AutomataNode *Automata::get_state(State_af state)
    {
        auto state_it = state_map_.find(state);
        if (state_it == state_map_.end())
        {
            AutomataNode *automata_node = new AutomataNode();
            state_map_[state] = *automata_node; // this invoke copy ctor
            state_it = state_map_.find(state);  // so, can't just return `automata_node` here
        }
        return &(state_it->second);
    }

    void Automata::print_automata()
    {
        for (auto state_it = state_map_.begin(); state_it != state_map_.end(); ++state_it)
        {
            cout << "- "
                 << "state: " << Syn_Frame::cast_to_af(state_it->first)->to_string() << endl;
            for (auto first_edge_it = state_it->second.begin(); first_edge_it != state_it->second.end(); ++first_edge_it)
            {
                cout << "\t"
                     << "- "
                     << "first edge: " << first_edge_it->first->to_literal_set_string() << endl;
                for (auto second_edge_it = first_edge_it->second.begin(); second_edge_it != first_edge_it->second.end(); ++second_edge_it)
                {
                    cout << "\t\t"
                         << "- "
                         << "second edge: " << second_edge_it->first->to_literal_set_string() << endl;
                    cout << "\t\t\t"
                         << "- "
                         << "state: " << Syn_Frame::cast_to_af(second_edge_it->second)->to_string() << endl;
                }
            }
        }
    }
}
