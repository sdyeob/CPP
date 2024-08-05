
# ifndef DOG_HPP
# define DOG_HPP

#include "Animal.hpp"

class Dog : public Animal
{
	public :
		Dog();
		Dog(const Dog& param);
		Dog& operator=(const Dog& param);
		~Dog();

		void makeSound() const ; // 만약 가상함수를 오버라이딩 하지 않았다면, 그냥 기반 클래스의 함수를 사용함. -> 이때도 vfptr이 생성.
};

# endif
