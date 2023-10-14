#include <iostream>
#include "List/List.hpp"
#include "Student/Student.hpp"


int main(){
  List <Student> p_lista;

  std::string alunos[] = {"Rafael", "Carlos", "Lucas"};
  int idades[] = {27, 32, 43};

  for (int i = 0; i<3 ; i++) {
    Student* new_student = (Student*) malloc(sizeof(Student));
    new (new_student) Student(alunos[i], idades[1]);
    int err = p_lista.push(new_student);
    if (err) {
      std::cout << "error" << "\n";
    }
  }

  Student* aluno = p_lista.get(1);
  std::cout << aluno->name << "::" << aluno->year << "\n";
  std::cout << "alo";

};
