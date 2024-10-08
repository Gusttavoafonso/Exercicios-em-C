#include <iostream>

#define TAM_TURMA 10

class aluno {
	int matricula;
	double cra;
public:
	aluno(int m, double c):matricula(m), cra(c) {
		std::cout << "aluno()" << std::endl;
	}
	int get_matricula() { return matricula; }
	double get_cra() { return cra; }

	void print_info() {
		std::cout << "aluno(" << matricula;
		std::cout << ", " << cra << ")" << std::endl;
	}
};

class turma {
	int sala;
	int horario;
	aluno* alunos[TAM_TURMA];
	int qtd_alunos;
public:
	turma(int s, int h):sala(s), horario(h) {
		qtd_alunos = 0;
	}

	void add_aluno(aluno& a) {
		alunos[qtd_alunos] = &a;
		qtd_alunos++;
	}

	//INSEGURO!! VIOLA ENCAPSULAMENTO!!
	//aluno* get_alunos() { return alunos; }
	void print_info() {
		std::cout << "turma(" << sala << ")";
		std::cout << std::endl;
		for (int i = 0; i < qtd_alunos; i++) {
			alunos[i]->print_info();
		}
	}
};

int main(void) {
	aluno a1(1011, 9.5);
	aluno a2(1012, 9.0);
	aluno a3(1013, 8.5);

	turma t1(105, 10);
	turma t2(106, 8);

	t1.add_aluno(a1);
	t1.add_aluno(a2);

	t2.add_aluno(a1);
	t2.add_aluno(a3);

	t1.print_info();
	t2.print_info();


	return 0;
}
