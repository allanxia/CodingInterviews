#include "util.h"

template<class T>
class MinStack
{
		public:
				//入栈函数
				void push(const T &t){
					datas.push(t);

					if(minStack.size()==0)
							minStack.push(t);
					else if(t<minStack.top())
					{
						minStack.push(t);
					}	
					else
					{
						minStack.push(minStack.top());
					}	
			
				}
				//出栈函数
				void pop(){
					if(datas.size()!=0&&minStack.size()!=0)
					{
						datas.pop();
						minStack.pop();
					}

				}
				
				//获取最小值的函数
				const T& min(){
					return minStack.top();
				}

		private:
				std::stack<T> datas;
				std::stack<T> minStack;

};



int main(){
	MinStack<int> s;
	s.push(3);
	s.push(4);
	s.push(2);
	s.push(1);
	std::cout<<"包含min函数的栈"<<std::endl;
	std::cout<<s.min()<<std::endl;
	s.pop();
	std::cout<<s.min()<<std::endl;
	return 0;
}
