#include <iostream>
#include "List/List.hpp"
#include "Student/Student.hpp"
#include "Node/Node.hpp"

void show_all(List <Student> *p_list);

int main(){
  List <Student> p_list;

  std::string alunos[] = {"Rafael", "Carlos", "Lucas", "Carla", "Julia", "Penelope"};
  int idades[] = {27, 32, 43, 12, 34, 54};

  //test FIFO
  std::cout << "Testing FIFO ..." << "\n";
  for (int i = 0; i<6 ; i++) {
    Student* new_student = (Student*) malloc(sizeof(Student));
    new (new_student) Student(alunos[i], idades[i]);
    p_list.push(new_student);
    show_all(&p_list);
  }

  for (int i = 0; i<6 ; i++) {
    p_list.shift();
    show_all(&p_list);
  }

  //test LIFO
  std::cout << "Testing LIFO ..." << "\n";
    for (int i = 0; i<6 ; i++) {
    Student* new_student = (Student*) malloc(sizeof(Student));
    new (new_student) Student(alunos[i], idades[i]);
    p_list.push(new_student);
    show_all(&p_list);
  }

  for (int i = 0; i<6 ; i++) {
    p_list.pop();
    show_all(&p_list);
  }

};


void show_all(List <Student> *p_list){
  int length = p_list->length();
  for(int i = 0; i < length; i++){
    Student *aluno = p_list->get(i);
    std::cout << "["<< aluno->name << "] ";
  }
  std::cout << "\n";
}
