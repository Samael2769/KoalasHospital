/**
 * @ Author: Samael
 * @ Create Time: 2023-09-04 07:04:03
 * @ Modified by: Samael
 * @ Modified time: 2023-09-04 10:53:02
 * @ Description:
 */

#ifndef DEASES_HPP
#define DEASES_HPP

#include <iostream>
#include <string>
#include <vector>

typedef enum symptoms {
    FEVER,
    COUGH,
    HEADACHE,
    STOMACHACHE,
    LEG_PAIN,
    DEPRESSION,
    DIZZINESS,
    VOMITING,
    DIARRHEA,
    BURNING_EYES,
} symptoms_t;

class Deases {
    public:
        Deases(std::string const &name);
        ~Deases();
        std::string const &getName() const;
        void setName(std::string const &name);
    protected:
    private:
        std::string _name;
        std::vector<symptoms_t> _symptoms;
};

#endif /* !DEASES_HPP */