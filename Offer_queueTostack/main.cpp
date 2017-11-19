#include<iostream>
#include<queue>
using namespace std;

template<typename T>
class CStack{
	public:
		CStack( ){ }
		~CStack( ) { }
		void push(const T& node);
		T pop( );
	private:
		queue<T> queue1;
		queue<T> queue2;
};

template<typename T>
void CStack<T>::push(const T& node) {
	if(queue2.empty( ) == true) {
		queue1.push(node);
	}
	else{
		queue2.push(node);
	}
}

template<typename T>
T CStack<T>::pop( ) {
	if(queue2.empty( ) == true) {
		while(queue1.size( ) > 1) {
			T& temp = queue1.front( );
			queue1.pop( );
			queue2.push(temp);
		}
		T& result = queue1.front( );
		queue1.pop( );
		return result;
	}
	else {
		while(queue2.size( ) > 1) {
			T& temp = queue2.front( );
			queue2.pop( );
			queue1.push(temp);
		}
		T& result = queue2.front( );
		queue2.pop( );
		return result;
	}
}

int main( ) {
	CStack<int> *Q = new CStack<int>;
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