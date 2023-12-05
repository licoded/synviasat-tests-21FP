#include "automata.h"
#include "synthesis.h"

namespace automata
{
        void Automata::print_automata()
        {
            for (auto state_it = state_map_.begin(); state_it != state_map_.end(); ++state_it)
            {
                cout << "- " << "state: " << Syn_Frame::cast_to_af(state_it->first)->to_string() << endl;
                // cout << "- " << "state: " << ull(state_it->first) << endl;
                for (auto first_edge_it = state_it->second.begin(); first_edge_it != state_it->second.end(); ++first_edge_it)
                {
                    cout << "\t" << "- " << "first edge: " << first_edge_it->first->to_literal_set_string() << endl;
                    // cout << "\t" << "- " << "first edge: " << ull(first_edge_it->first) << endl;
                    for (auto second_edge_it = first_edge_it->second.begin(); second_edge_it != first_edge_it->second.end(); ++second_edge_it)
                    {
                        cout << "\t\t" << "- " << "second edge: " << second_edge_it->first->to_literal_set_string() << endl;
                        // cout << "\t\t" << "- " << "second edge: " << ull(second_edge_it->first) << endl;
                        cout << "\t\t\t" << "- " << "state: " << Syn_Frame::cast_to_af(second_edge_it->second)->to_string() << endl;
                        // cout << "\t\t\t" << "- " << "state: " << ull(second_edge_it->second) << endl;
                    }
                }
            }
        }
}
