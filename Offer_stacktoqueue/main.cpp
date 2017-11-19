#include<iostream>
#include<stack>
using namespace std;

template<typename T>
class CQueue{
	public:
		CQueue( ){ }
		~CQueue( ) { }
		void push(const T& node);
		T pop( );
	private:
		stack<T> stack1;
		stack<T> stack2;
};

template<typename T>
void CQueue<T>::push(const T& node) {
	stack1.push(node);
}

template<typename T>
T CQueue<T>::pop( ) {
	if(stack2.empty( ) == true) {
		while(stack1.size( ) > 0) {
			T& temp = stack1.top( );
			stack1.pop( );
			stack2.push(temp);
		}
	}

	T& result  =  stack2.top( );
	stack2.pop( );
	return result;
}

int main( ) {
	CQueue<int> *Q = new CQueue<int>;
	Q->push(1);
	Q->push(2);
	Q->push(3);
	cout<<Q->pop( )<<" ";
	cout<<Q->pop( )<<" ";
	Q->push(4);
	cout<<Q->pop( )<<" ";
	Q->push(5);
	cout<<Q->pop( )<<" ";
	cout<<Q->pop( )<<" ";

	system("pause");
	return 0;
}