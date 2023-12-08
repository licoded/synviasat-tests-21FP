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
}
