#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>

class Brain
{
private :
    std::string ideas[100];
public :
    // constructor  && destructor 
    Brain();
    Brain(const std::string& idea);
    Brain(const Brain& other);
    Brain& operator=(const Brain& other);
    ~Brain();

    // SETTERS && GETTERS :
    void    setIdeas(int index, const std::string& idea);
    const std::string&    getIdeas(int index) const;

};

#endif
