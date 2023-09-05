/*
** EPITECH PROJECT, 2022
** Untitled (Workspace)
** File description:
** KoalaHospital
*/

#include "KoalaHospital.hpp"
#include "cmath"

KoalaHospital::KoalaHospital()
{
    srand(time(NULL));
    Patient patient = Patient("Bob");
    Doctor doctor = Doctor("House");
    std::vector<symptoms_t> knownSymptoms = {COUGH, HEADACHE, STOMACHACHE, DEPRESSION};
    symptoms_t symp = doctor.diagnose(patient, knownSymptoms);
    Nurse nurse = Nurse("Josiane");
    nurse.giveDrug(symp, patient);
}

KoalaHospital::~KoalaHospital()
{
    
}