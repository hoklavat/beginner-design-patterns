//16-Interpreter

#include <iostream>
#include <map>
using namespace std;

class Context{
private:
	map<string, bool> vars;
	
public:
	void set(const string& var, const bool value){
		vars.insert(pair<string, bool>(var, value));
	}
	
	bool get(const string& exp){
		return vars[exp];
	}
};

class AbstractExpression{
public:
	virtual ~AbstractExpression(){}
	
	virtual bool interpret(Context* const){
		return false;
	}
};

class TerminalExpression: public AbstractExpression{
private:
	string value;
	
public:
	TerminalExpression(const string& val): value(val){}	
	~TerminalExpression(){}
	
	bool interpret(Context* const context){
		return context->get(value);
	}
};

class NonterminalExpression: public AbstractExpression{
private:
	AbstractExpression *lop;
	AbstractExpression *rop;
	
public:
	NonterminalExpression(AbstractExpression *left, AbstractExpression *right): lop(left), rop(right){}
	
	~NonterminalExpression(){
		delete lop;
		delete rop;
	}
	
	bool interpret(Context *const context){
		return lop->interpret(context) && rop->interpret(context);
	}
};

int main(){
	AbstractExpression *A = new TerminalExpression("A");
	AbstractExpression *B = new TerminalExpression("B");
	AbstractExpression *exp = new NonterminalExpression(A, B);
	
	Context context;
	context.set("A", true);
	context.set("B", false);
	
	cout << context.get("A") << " AND " << context.get("B");
	cout << " = " << exp->interpret(&context) << endl;
	
	delete exp;
	return 0;
}