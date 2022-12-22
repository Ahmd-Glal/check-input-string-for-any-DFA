/*
Written by Saeedy
Ahmd-Glal
*/

#include <iostream>
#include<iomanip>
#include<map>
#include<vector>
#include<algorithm>
using namespace std;

struct node
{
    char alpha1, alpha2;
    int when_alpha1_goto, when_alpha2_goto;
};

int trace(const string& str, const int& initial, const vector<node>& nodes)
{
    int beg = initial;
    for (int i = 0; i<int(str.size()); i++)
    {
        if (str[i] == nodes[beg].alpha1)
            beg = nodes[beg].when_alpha1_goto;
        else
            beg = nodes[beg].when_alpha2_goto;
    }
    return beg;
}

void transition_table(const char& alpha1, const char& alpha2, const int& node_count, vector<node>& nodes)
{
    cout << "-------\n";
    cout << '|' << setw(3) << alpha1 << ' ' << alpha2 << ' ' << setw(2) << " \n";
    for (int i = 0; i < node_count; i++)
    {

        int a, b;//to input the next node names
        bool che = 1;
        while (che)
        {
            cout << "------\n";
            cout << i << "| ";
            cin >> a >> b;
            if (a >= 0 && a < node_count && b >= 0 && b < node_count)
                che = 0;
            else
                cout << "enter values in this range[0," << node_count - 1 << "]\n";
        }
        nodes[i].alpha1 = alpha1;
        nodes[i].alpha2 = alpha2;
        nodes[i].when_alpha1_goto = a;
        nodes[i].when_alpha2_goto = b;
    }
    cout << "------\n";
    cout << "\n\nyour DFA is now initiated and can test languages\n";
}

int main()
{

    char alpha1, alpha2;//the two input characters in the DFA
    int node_count;//represent the number of nodes in DFA
    int final_count;//represent the number of final sates in DFA
    int initial_state;//represent the name of the initial state
    map<int, bool>accept;//store all the accept/final states

    cout << "please enter the number of nodes in your DFA: ";
    cin >> node_count;
    vector<node>nodes(node_count);//store all the nodes and its direction

    cout << "\nplease enter two input alphabetical characters to the DFA: ";
    cin >> alpha1 >> alpha2;

    cout << "\nyour nodes names is: ";
    for (int i = 0; i < node_count; i++)
    {
        cout << i << ' ';
    }

    cout << "\nwhat is the initial state in this DFA: ";
    cin >> initial_state;

    cout << "\nwhat is the number of final states in this DFA: ";
    cin >> final_count;
    cout << "\nknow what are the final states in this DFA:\n";
    for (int i = 0; i < final_count; i++)
    {
        int x;
        cin >> x;
        accept[x] = 1;
    }

    cout << "\nknow it is time for transition table for this DFA\n";
    cout << "please follow this procedure: i will show you the two input alphabetical characters\n";
    cout << "you entered and after that i will show you the name of every node in a single line and you will enter\n";
    cout << "for every node two numbers the first is the next node name that current node will go to it\n";
    cout << "if the input is the first character i showed before (same the second)\n";
    cout << '\n';

    transition_table(alpha1, alpha2, node_count, nodes);

    while (true)
    {
        string language;
        cin >> language;
        int number_of_occurrence_of_alpha1 = count(language.begin(), language.end(), alpha1);
        int number_of_occurrence_of_alpha2 = count(language.begin(), language.end(), alpha2);
        int result = trace(language, initial_state, nodes);
        if (accept[result] && number_of_occurrence_of_alpha1 + number_of_occurrence_of_alpha2 == int(language.size()))
            cout << "  :Accepted\n";
        else
            cout << "  :Rejected\n";
    }

}
