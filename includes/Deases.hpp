/**
 * @ Author: Samael
 * @ Create Time: 2023-09-04 07:04:03
 * @ Modified by: Samael
 * @ Modified time: 2023-09-04 07:05:55
 * @ Description:
 */

#ifndef DEASES_HPP
#define DEASES_HPP

#include <iostream>
#include <string>

class Deases {
    public:
        Deases(std::string const &name);
        ~Deases();
        std::string const &getName() const;
        void setName(std::string const &name);
    protected:
    private:
        std::string _name;
};

#endif /* !DEASES_HPP */