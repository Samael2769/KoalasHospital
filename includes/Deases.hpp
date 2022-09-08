/*
** EPITECH PROJECT, 2022
** Untitled (Workspace)
** File description:
** Deases
*/

#ifndef DEASES_HPP_
#define DEASES_HPP

#include <ctime>
#include <string>

//Type of Deases for the Patients
class Deases {
    public:
        Deases();
        ~Deases();
        enum Type {
            COLD,
            FLU,
            FEVER,
            BACTERIA,
            DISEASE
        };
        enum remede {
            DOLIPRANE,
            ANTIVIRAL,
            ANTIBIOTIC,
            DAFALGAN,
            VITAMINS
        };
        Type getType() { return type; }
    protected:
    private:
        Type type;
};

#endif /* !DEASES_HPP_ */
