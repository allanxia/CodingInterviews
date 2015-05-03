#include "util.h"

template<class T>
class MinStack
{
		public:
				//��ջ����
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
				//��ջ����
				void pop(){
					if(datas.size()!=0&&minStack.size()!=0)
					{
						datas.pop();
						minStack.pop();
					}

				}
				
				//��ȡ��Сֵ�ĺ���
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
	std::cout<<"����min������ջ"<<std::endl;
	std::cout<<s.min()<<std::endl;
	s.pop();
	std::cout<<s.min()<<std::endl;
	return 0;
}
