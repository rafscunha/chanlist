#include <iostream>
#include "List/List.hpp"
#include "Student/Student.hpp"
#include "Node/Node.hpp"

void show_all(List <Student> *p_list);

int main(){
  List <Student> p_list;

  std::string alunos[] = {"Rafael", "Andreia", "Carlos", "Reginaldo", "Zilma", "Zilma"};
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

  //test SORT
  std::cout << "Testing SORT ..." << "\n";

  for (int i = 0; i<6 ; i++) {
    Student* new_student = (Student*) malloc(sizeof(Student));
    new (new_student) Student(alunos[i], idades[i]);
    p_list.push(new_student);
  }
  show_all(&p_list);

  std::cout << "Order by name" << "\n";
  auto verify = [] (Student *first, Student *second) -> bool {
    return first->name > second->name; 
  };
  p_list.sort(verify);
  show_all(&p_list);

  std::cout << "Order by year" << "\n";
  auto verifyYear = [] (Student *first, Student *second) -> bool {
    return first->year > second->year; 
  };
  p_list.sort(verifyYear);
  show_all(&p_list);
  

};


void show_all(List <Student> *p_list){
  int length = p_list->length();
  for(int i = 0; i < length; i++){
    Student *aluno = p_list->get(i);
    std::cout << "["<< aluno->name << "] ";
  }
  std::cout << "\n";
}
