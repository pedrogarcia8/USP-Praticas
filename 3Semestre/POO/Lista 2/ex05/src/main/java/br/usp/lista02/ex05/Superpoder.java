package br.usp.lista02.ex05;

public class Superpoder {
    private int _categoria;
    private String _nome;
    private double _multiplicador;
    
    Superpoder(int pCategoria, String pNome, double pMultiplicador){
        _categoria = pCategoria;
        _nome = pNome;
        _multiplicador = pMultiplicador;
    }
    
    //retorna o número da categoria do superpoder
    public int getCategoria(){
        return _categoria;
    }
    
    //retorna o nome do superpoder
    public String getNome(){
        return _nome;
    }
    
    //configura o número da categoria do superpoder
    public void setCategoria(int pCategoria){
        _categoria = pCategoria;
    }
    
    //configura o nome do superpoder
    public void setNome(String pNome){
        _nome = pNome;
    }
    
    //configura o número do multiplicador do superpoder
    public void setMultiplicador(double pMultiplicador){
        _multiplicador = pMultiplicador;
    }
    
    //retorna o número do multiplicador do superpoder
    public double getMultiplicador(){
        return _multiplicador;
    }
}
