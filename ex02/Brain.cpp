#include "Brain.hpp"

Brain::Brain()
{
    for (int i = 0; i < 100; ++i)
    {
        ideas[i] = "";
    }
    std::cout << "Brain default costructor called" << std::endl;
}

Brain::Brain(const std::string& idea)
{
    for (int i = 0; i < 100; ++i)
    {
        this->ideas[i] = idea;
    }
    std::cout << "Brain Paramiterized costructor called" << std::endl;
}

Brain::Brain(const Brain& other)
{
    *this = other;
    std::cout << "Brain Copy costructor called" << std::endl;
}

Brain& Brain::operator=(const Brain& other)
{
    if (this != &other)
    {
        for (int i = 0; i < 100; ++i)
            this->ideas[i] = other.ideas[i];
    }
    return (*this);
}

Brain::~Brain()
{
    std::cout << "Brain destructor called" << std::endl;
}


void    Brain::setIdeas(int index, const std::string& idea)
{
    if (index >= 0 && index < 100)
        ideas[index] = idea;
}

const std::string&    Brain::getIdeas(int index) const
{
    static std::string  empty = "";

    if (index >= 0 && index < 100)
        return (ideas[index]);

    return (empty);
}
