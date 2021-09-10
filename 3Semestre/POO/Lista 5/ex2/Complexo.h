class Complexo{
	private:
		float real;
		float imaginario;
	public:
		float * soma(Complexo * c);
		float * subtracao(Complexo * c);
		float * multiplicacao(Complexo * c);
		float modulo();
		Complexo(float real, float imaginario);
};
