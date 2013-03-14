#include "../nfa.hpp"
#include "../State.hpp"
#include "../Alphabet.hpp"
#include "../fa_defs.hpp"

int main () {
	typedef char abc_type;
	typedef FA::StatePtr<abc_type> StatePtr;
	typedef FA::State<abc_type> State;
	typedef FA::Transfer<abc_type> Transfer;
	typedef FA::TransferPtr<abc_type> TransferPtr;
	typedef FA::NFA<abc_type> NFA;

	StatePtr a(new State());
	StatePtr b(new State());

	TransferPtr t(new Transfer(b));
	a->add(t);

	NFA nfa;
	nfa.insert(a);
	nfa.insert(b);
	nfa.setStart(a);
	nfa.next('a');
}

