#include<iostream>
#include<stack>
#include<cassert>
using namespace std;

class Solution {
	public:
		void push(int value) ;
		void pop( );
		int top( );
		int min( );
	private:
		stack<int> m_data;
		stack<int> m_min;
};

void Solution::push(int value) {
	m_data.push(value);
	if(m_min.size( )==0 || value < min( ))
		m_min.push(value);
	else
		m_min.push(min( ));

}

void Solution::pop( ) {
	assert(m_data.size( ) > 0 && m_min.size( ) > 0);
	m_data.pop( );
	m_min.pop( );
}

int Solution::top( ) {
	assert(m_data.size( ) > 0);
	return m_data.top( );
}

int Solution::min( ) {
	assert(m_min.size( )>0);
	return m_min.top( );
}


int main( ) {
	Solution s;
	s.push(3);
	cout<<s.min()<<endl;
	s.push(2);
	cout<<s.min()<<endl;
	s.pop();
	cout<<s.top()<<"    "<<s.min()<<endl;
	s.push(0);
	cout<<s.top( )<<"   "<<s.min( )<<endl;
	s.push(100);
	cout<<s.top( )<<"   "<<s.min( )<<endl;
	system("pause");
	return 0;
}