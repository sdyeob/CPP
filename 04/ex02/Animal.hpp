
# ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <iostream>

class Animal
{
	protected :
		std::string type;
	public :
		Animal();
		Animal(const std::string& type);
		Animal(const Animal& param);
		Animal& operator=(const Animal& param);
		virtual ~Animal();

		virtual void makeSound() const = 0; // 해당 함수 때문에, 해당 클래스는 추상 클래스가 돼서 인스턴스화가 불가능하지만,
			// 해당 클래스의 다른 함수들에서 이 함수를 간접 호출 하는 것은 가능함... 근데 왜 있는지 모르겠음.
		const std::string& getType() const;
};

# endif
