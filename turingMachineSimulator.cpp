#include <bits/stdc++.h>
using namespace std;

class TuringMachine 
{
	public: 
	set<string> states;
	set<string> symbols;
	string blank_symbol; 
	set<string> input_symbols;
	string initial_state;
	set<string> accepting_states;

	// (state,symbol) -> (updated state, updated symbol, direction)
	map<pair<string,string>, tuple<string,string, int>> transitions;

	// internal variables
	int head;
	map<int, string> tape;
	string current_state;
	bool halted; 

	
	void initialize()
   	{
		set_states();
		set_symbols();
		set_blank_symbol();
		set_input_symbols();
		set_initial_states();
		set_accepting_states();
		set_transitions();
		head = 0;
		halted = false;
		current_state = initial_state;
	}

	void set_states() {
		int n;
		cin >> n;
		while(n--) {
			string s;
			cin >> s;
			states.insert(s);
		}
		//cout << "states" << endl;
		//for(auto i: states) cout << i << " " ;
		//cout << endl;
	}

	void set_symbols() {
		int n;
		cin >> n;
		while(n--) {
			string s;
			cin >> s;
			symbols.insert(s);
		}
		//cout << "symbols" << endl;
		//for(auto i : symbols) cout << i << " ";
		//cout << endl;
	}

	void set_blank_symbol() {
		cin >> blank_symbol;
		//cout << "Blank symbol = " << blank_symbol << endl;
	}
	
	void set_input_symbols() {
		int n;
		cin >> n;
		while(n--) {
			string s;
			cin >> s;
			input_symbols.insert(s);
		}
		//cout << "Input symbols " << endl;
		//for(auto i : input_symbols) 
		//	cout << i << " " << endl;
	}

	void set_initial_states() {
		cin >> initial_state;
		//cout << "Initial state =" << initial_state << endl;
	}

	void set_accepting_states() {
		int n;
		cin >> n;
		while(n--) {
			string s;
			cin >> s;
			accepting_states.insert(s);
		}
		//cout << "Accepting states" << endl;
		//for(auto i : accepting_states) {
		//	cout << i << " " << endl;
		//}
	}

	void set_transitions() {
		int n;
		cin >> n;
		while(n--) {
			string curr_state, next_state, curr_symbol, next_symbol;
			int direction;
			cin >> curr_state >> curr_symbol >> next_state >> next_symbol;
			cin >> direction;
			transitions[make_pair(curr_state,curr_symbol)] = make_tuple(next_state, next_symbol, direction);
		}
		//cout << "Transitions:" << endl;
		//for(auto i: transitions) {
		//	cout << i.first.first << " " << i.first.second << " " ;
		//	tuple<string,string,int> s = i.second;
		//	cout << get<0>(s) << " " << get<1>(s) << " " << get<2>(s) << endl;
		//}
	}


	void step() 
	{
		string curr = tape.find(head) == tape.end() ? blank_symbol : tape[head]; 
		pair<string,string> transition = make_pair(current_state, curr);
		//cout << transition.first << " " << transition.second << endl;
		if(transitions.find(transition) == transitions.end()) {
			// Unable to find next transition
			halted = true;
			return;
		}
		tuple<string, string, int> next_transition = transitions[transition];
		//tape[head] = next_transition.get(1);
		tape[head] = get<1>(next_transition);
		current_state = get<0>(next_transition);
		head += get<2>(next_transition);
		//current_state = next_transition.get(0);
		//head += next_transition.get(2);
	}

	bool accepted_input() 
	{
		if(!halted) {
			// still running 
			// error
			return false;
		}
		return accepting_states.find(current_state) != accepting_states.end(); 
	}

	void print(int window = 10) 
	{
		cout << "... ";
		for (int i = head - window; i < head + window; ++i) {
			if(tape.find(i) != tape.end()) 
				cout << tape[i] << " " ;
			else 
				cout << blank_symbol << " " ;
		}
		cout << " ... ";
		cout << "state = " << current_state << endl;
		for(int i = 0; i < 2*window + 4; ++i) cout << " ";
		cout << "^\n";
	}
	
	
};



int main()
{
	cout << "Turing Machine simulator\n";
	
	freopen("input.txt", "r", stdin);
	
	TuringMachine t;

	t.initialize();

	while(true) {
		if(t.halted) break;
		t.print();
		t.step();
	}

	return 0;
}
