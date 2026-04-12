//
// Created by cesar on 12/4/2026.
//

#ifndef PROYECTO1_ERROR_H
#define PROYECTO1_ERROR_H
#include <exception>
#include <string>
using namespace std;

class Error : public exception {
private:
    string mensaje;
public:
    explicit Error(string const &mensaje);
    const char* what() const noexcept override;
};


#endif //PROYECTO1_ERROR_H